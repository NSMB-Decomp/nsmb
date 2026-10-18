//! Generates MWCC-compatible NitroFS file ID constants from a Nintendo DS ROM.
//!
//! Usage: gen_file_ids --rom <A2DE.nds> --output <file_ids.hpp>
//!
//! Every file in the ROM's NitroFS gets an NSMB_FID_* macro, and every file
//! inside a mounted NARC archive gets an NSMB_ARC_FID_* macro. Macros are
//! intentional: MWCC ARM 1.2sp3 then sees only integer literals, preserving its
//! private-symbol numbering and exact output.

const std = @import("std");
const Allocator = std.mem.Allocator;

const cpp_keywords = [_][]const u8{
    "and",      "and_eq",   "asm",    "auto",    "bitand",       "bitor",       "bool",       "break",
    "case",     "catch",    "char",   "class",   "compl",        "const",       "const_cast", "continue",
    "default",  "delete",   "do",     "double",  "dynamic_cast", "else",        "enum",       "explicit",
    "export",   "extern",   "false",  "float",   "for",          "friend",      "goto",       "if",
    "inline",   "int",      "long",   "mutable", "namespace",    "new",         "not",        "not_eq",
    "operator", "or",       "or_eq",  "private", "protected",    "public",      "register",   "reinterpret_cast",
    "return",   "short",    "signed", "sizeof",  "static",       "static_cast", "struct",     "switch",
    "template", "this",     "throw",  "true",    "try",          "typedef",     "typeid",     "typename",
    "union",    "unsigned", "using",  "virtual", "void",         "volatile",    "wchar_t",    "while",
    "xor",      "xor_eq",
};

// A2DE's FS archive table at 0x0203A6C0 assigns each mounted archive a
// 0x100-file page starting at 0xC000. The two null entries are embedded
// archives that have no NitroFS NARC file to inspect.
const mounted_archive_order = [_]?[]const u8{
    "Dat_2D",         "Dat_Basement",   "Dat_Field",     "Dat_Fort",         "Dat_Ice",       "Dat_Init",
    "Dat_Pipe",       "Dat_enemy",      null,            "menu_title",       null,            "ARC0",
    "bomthrow",       "card",           "casino",        "flower_yoshi",     "hanasagase",    "jump",
    "luigi_model_mg", "mario_model_mg", "mg_common",     "mg_entry",         "mg_flower",     "mg_luigi",
    "mg_menu_common", "mg_teresa",      "mg_trampoline", "mgvs_common",      "p_heyho",       "pachinko",
    "pazzle_panel",   "snowball",       "snowwar",       "tranpu",           "vs_amida",      "vs_balloon_fight",
    "vs_escape",      "vs_flower",      "vs_mogura",     "vs_pachinko",      "vs_riversi",    "vs_snowball",
    "vs_step_on",     "vs_tamaire",     "vs_teresa",     "vs_wrecking_crew", "wrecking_crew",
};

fn mountedArchiveStart(name: []const u8) ?u32 {
    for (mounted_archive_order, 0..) |entry, slot| {
        if (entry) |n| {
            if (std.mem.eql(u8, n, name)) return 0xC000 + @as(u32, @intCast(slot)) * 0x100;
        }
    }
    return null;
}

const Entry = struct {
    id: u32,
    path: []const u8,

    fn lessThan(_: void, a: Entry, b: Entry) bool {
        if (a.id != b.id) return a.id < b.id;
        return std.mem.lessThan(u8, a.path, b.path);
    }
};

const Archive = struct {
    path: []const u8,
    files: []Entry,

    fn lessThan(_: void, a: Archive, b: Archive) bool {
        return std.mem.lessThan(u8, a.path, b.path);
    }
};

fn readU16(data: []const u8, offset: usize) !u16 {
    if (offset + 2 > data.len) return error.OutOfBounds;
    return std.mem.readInt(u16, data[offset..][0..2], .little);
}

fn readU32(data: []const u8, offset: usize) !u32 {
    if (offset + 4 > data.len) return error.OutOfBounds;
    return std.mem.readInt(u32, data[offset..][0..4], .little);
}

const Fnt = struct {
    first_file_id: u16,
    files: []Entry,
};

const FntWalker = struct {
    arena: Allocator,
    fnt: []const u8,
    directory_count: u16,
    fat_file_count: usize,
    visited: std.AutoHashMapUnmanaged(u16, void) = .empty,
    files: std.ArrayList(Entry) = .empty,

    fn walk(self: *FntWalker, directory_id: u16, parent: []const u8) !void {
        const directory_index = directory_id & 0x0FFF;
        if (directory_index >= self.directory_count) return error.InvalidDirectoryId;
        if ((try self.visited.getOrPut(self.arena, directory_id)).found_existing) return error.DirectoryCycle;

        const table_offset = @as(usize, directory_index) * 8;
        var offset: usize = try readU32(self.fnt, table_offset);
        var file_id: u32 = try readU16(self.fnt, table_offset + 4);
        if (offset >= self.fnt.len) return error.InvalidSubtable;

        while (true) {
            if (offset >= self.fnt.len) return error.UnterminatedSubtable;
            const type_and_length = self.fnt[offset];
            offset += 1;
            if (type_and_length == 0) break;

            const is_directory = (type_and_length & 0x80) != 0;
            const name_length = type_and_length & 0x7F;
            if (name_length == 0 or offset + name_length > self.fnt.len) return error.InvalidName;
            const name = self.fnt[offset .. offset + name_length];
            offset += name_length;

            const path = if (parent.len == 0)
                try self.arena.dupe(u8, name)
            else
                try std.fmt.allocPrint(self.arena, "{s}/{s}", .{ parent, name });

            if (is_directory) {
                const child_id = try readU16(self.fnt, offset);
                offset += 2;
                try self.walk(child_id, path);
            } else {
                if (file_id >= self.fat_file_count) return error.FileIdOutsideFat;
                try self.files.append(self.arena, .{ .id = file_id, .path = path });
                file_id += 1;
            }
        }
    }
};

fn parseFnt(arena: Allocator, fnt: []const u8, fat_file_count: usize) !Fnt {
    if (fnt.len < 8) return error.FntTooSmall;
    const root_subtable = try readU32(fnt, 0);
    const first_file_id = try readU16(fnt, 4);
    const directory_count = try readU16(fnt, 6);
    if (directory_count == 0 or @as(usize, directory_count) * 8 > fnt.len) return error.InvalidDirectoryCount;
    if (root_subtable >= fnt.len) return error.InvalidRootSubtable;

    var walker: FntWalker = .{
        .arena = arena,
        .fnt = fnt,
        .directory_count = directory_count,
        .fat_file_count = fat_file_count,
    };
    try walker.walk(0xF000, "");
    if (walker.files.items.len == 0) return error.NoFiles;
    std.mem.sort(Entry, walker.files.items, {}, Entry.lessThan);
    return .{ .first_file_id = first_file_id, .files = walker.files.items };
}

fn parseNarc(arena: Allocator, data: []const u8) ![]Entry {
    if (data.len < 0x10 or !std.mem.eql(u8, data[0..4], "NARC")) return error.InvalidNarcHeader;
    const header_size = try readU16(data, 0x0C);
    const block_count = try readU16(data, 0x0E);
    if (header_size < 0x10 or header_size > data.len) return error.InvalidNarcHeaderSize;

    var file_count: ?usize = null;
    var filename_table: ?[]const u8 = null;
    var offset: usize = header_size;
    for (0..block_count) |_| {
        if (offset + 8 > data.len) return error.NarcBlockOutOfBounds;
        const block_size = try readU32(data, offset + 4);
        if (block_size < 8 or offset + block_size > data.len) return error.InvalidNarcBlockSize;
        const magic = data[offset .. offset + 4];
        if (std.mem.eql(u8, magic, "BTAF")) {
            if (block_size < 12) return error.NarcFatTooSmall;
            file_count = try readU16(data, offset + 8);
        } else if (std.mem.eql(u8, magic, "BTNF")) {
            filename_table = data[offset + 8 .. offset + block_size];
        }
        offset += block_size;
    }

    const fnt = filename_table orelse return error.NarcMissingTables;
    const count = file_count orelse return error.NarcMissingTables;
    return (try parseFnt(arena, fnt, count)).files;
}

fn isKeyword(name: []const u8) bool {
    for (cpp_keywords) |keyword| {
        if (std.mem.eql(u8, keyword, name)) return true;
    }
    return false;
}

/// Path to a C identifier: '/' and every other non-identifier byte become '_',
/// with a "part_" prefix if the result would start with a digit or be a keyword.
fn pathIdentifier(arena: Allocator, path: []const u8) ![]const u8 {
    const result = try arena.dupe(u8, path);
    for (result) |*c| {
        if (!std.ascii.isAlphanumeric(c.*) and c.* != '_') c.* = '_';
    }
    if (result.len == 0 or std.ascii.isDigit(result[0]) or isKeyword(result)) {
        return std.fmt.allocPrint(arena, "part_{s}", .{result});
    }
    return result;
}

const HeaderWriter = struct {
    arena: Allocator,
    out: *std.Io.Writer,
    generated: std.StringHashMapUnmanaged([]const u8) = .empty,

    fn macro(self: *HeaderWriter, name: []const u8, value: u32, path: []const u8) !void {
        const entry = try self.generated.getOrPut(self.arena, name);
        if (entry.found_existing and !std.mem.eql(u8, entry.value_ptr.*, path)) {
            std.log.err("paths '{s}' and '{s}' generate the same macro '{s}'", .{ entry.value_ptr.*, path, name });
            return error.DuplicateMacro;
        }
        entry.value_ptr.* = path;
        try self.out.print("#define {s} 0x{X:0>4} // {s}\n", .{ name, value, path });
    }
};

pub fn main(init: std.process.Init) !void {
    const arena = init.arena.allocator();
    const io = init.io;
    const args = try init.minimal.args.toSlice(arena);

    var rom_path: ?[]const u8 = null;
    var output_path: ?[]const u8 = null;
    var i: usize = 1;
    while (i < args.len) : (i += 1) {
        if (std.mem.eql(u8, args[i], "--rom") and i + 1 < args.len) {
            i += 1;
            rom_path = args[i];
        } else if (std.mem.eql(u8, args[i], "--output") and i + 1 < args.len) {
            i += 1;
            output_path = args[i];
        } else {
            std.log.err("usage: gen_file_ids --rom <rom.nds> --output <file_ids.hpp>", .{});
            return error.InvalidArguments;
        }
    }
    const rom_file = rom_path orelse return error.MissingRom;
    const output_file = output_path orelse return error.MissingOutput;

    const cwd = std.Io.Dir.cwd();
    const rom = try cwd.readFileAlloc(io, rom_file, arena, .unlimited);
    if (rom.len < 0x50) return error.RomTooSmall;

    const fnt_offset = try readU32(rom, 0x40);
    const fnt_size = try readU32(rom, 0x44);
    const fat_offset = try readU32(rom, 0x48);
    const fat_size = try readU32(rom, 0x4C);
    if (@as(usize, fnt_offset) + fnt_size > rom.len) return error.FntOutsideRom;
    if (fat_size % 8 != 0 or @as(usize, fat_offset) + fat_size > rom.len) return error.InvalidFat;

    const fnt = try parseFnt(arena, rom[fnt_offset .. fnt_offset + fnt_size], fat_size / 8);

    var archives: std.ArrayList(Archive) = .empty;
    var archive_file_count: usize = 0;
    for (fnt.files) |file| {
        if (!std.ascii.endsWithIgnoreCase(file.path, ".narc")) continue;
        const start = try readU32(rom, fat_offset + file.id * 8);
        const end = try readU32(rom, fat_offset + file.id * 8 + 4);
        if (start > end or end > rom.len) return error.InvalidArchiveRange;
        const files = try parseNarc(arena, rom[start..end]);
        archive_file_count += files.len;
        try archives.append(arena, .{ .path = file.path, .files = files });
    }
    std.mem.sort(Archive, archives.items, {}, Archive.lessThan);

    var buffer: std.Io.Writer.Allocating = .init(arena);
    const out = &buffer.writer;
    try out.print(
        \\#pragma once
        \\
        \\// Generated by tools/gen_file_ids.zig. Do not edit.
        \\// Source ROM: {s}; NitroFS first file ID: {d}.
        \\// Macros are intentional: MWCC ARM 1.2sp3 then sees only integer
        \\// literals, preserving its private-symbol numbering and exact output.
        \\
        \\#define NSMB_FID(name) NSMB_FID_##name
        \\#define NSMB_ARC_FID(name) NSMB_ARC_FID_##name
        \\#define NSMB_VS_FID(fid, arcFid) \
        \\    ((NSMB_ARC_FID(arcFid) << 16) | NSMB_FID(fid))
        \\
        \\
    , .{ std.fs.path.basename(rom_file), fnt.first_file_id });

    var header: HeaderWriter = .{ .arena = arena, .out = out };
    for (fnt.files) |file| {
        const name = try std.fmt.allocPrint(arena, "NSMB_FID_{s}", .{try pathIdentifier(arena, file.path)});
        try header.macro(name, file.id - fnt.first_file_id, file.path);
    }

    try out.writeAll("\n");
    for (archives.items) |archive| {
        const base = archive.path[0 .. archive.path.len - ".narc".len];
        const archive_name = std.fs.path.basename(base);
        const archive_start = mountedArchiveStart(archive_name) orelse {
            std.log.err("'{s}' has no A2DE mounted archive range", .{archive.path});
            return error.UnknownArchive;
        };
        const count_name = try std.fmt.allocPrint(arena, "NSMB_ARC_FILE_COUNT_{s}", .{try pathIdentifier(arena, base)});
        try header.macro(count_name, @intCast(archive.files.len), archive.path);
        for (archive.files) |file| {
            const name = try std.fmt.allocPrint(arena, "NSMB_ARC_FID_{s}", .{try pathIdentifier(arena, file.path)});
            const path = try std.fmt.allocPrint(arena, "{s}:{s}", .{ archive.path, file.path });
            try header.macro(name, archive_start + file.id, path);
        }
    }

    if (std.fs.path.dirname(output_file)) |dir| try cwd.createDirPath(io, dir);
    try cwd.writeFile(io, .{ .sub_path = output_file, .data = buffer.written() });

    std.log.info("generated {s} with {d} ROM file IDs and {d} archive file IDs from {s} (offset {d})", .{
        output_file, fnt.files.len, archive_file_count, rom_file, fnt.first_file_id,
    });
}

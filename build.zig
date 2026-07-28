const std = @import("std");
const builtin = @import("builtin");

pub fn build(b: *std.Build) !void {
    b.resolveInstallPrefix(b.build_root.path orelse ".", .{});
    const release = b.option(Release, "Release", "") orelse Release.A2DE;

    // Define paths that are used in the build steps
    const rom_file = b.path(release.fileName());
    const extract_directory = b.path(b.pathJoin(&.{ "extracted", release.name(), "" }));
    const config_file = b.path(b.pathJoin(&.{ "config", release.name(), "arm9/config.yaml" }));

    // Step - extract
    const extract_cmd = b.addSystemCommand(&.{"dsd"});
    extract_cmd.addArgs(&.{ "rom", "extract" });
    extract_cmd.addArg("-o");
    extract_cmd.addFileArg(extract_directory);
    extract_cmd.addArg("-r");
    extract_cmd.addFileArg(rom_file);
    const extract_step = b.step("extract", "");
    extract_step.dependOn(&extract_cmd.step);

    // Step - delink
    const delink_cmd = b.addSystemCommand(&.{"dsd"});
    delink_cmd.addArgs(&.{ "delink", "-c" });
    delink_cmd.addFileArg(config_file);
    const delink_step = b.step("delink", "");
    delink_step.dependOn(&delink_cmd.step);

    // Step - objdiff
    const objdiff_cmd = b.addSystemCommand(&.{"dsd"});
    objdiff_cmd.addArgs(&.{ "objdiff", "-c" });
    objdiff_cmd.addFileArg(config_file);
    objdiff_cmd.addArgs(&.{ "-m", "zig" });
    objdiff_cmd.addArgs(&.{ "-M", "build", "-M", "single", "-M", release.commandName(), "-M", "--" });
    objdiff_cmd.addArgs(&.{ "-s", "-C", "mwcc_20_84", "-p", "201" });
    objdiff_cmd.addArgs(&.{ "-f", "-O4,p -interworking -proc=arm946e -w=off -gccinc -nolink -c -Cpp_exceptions off -lang=c++ -RTTI off -sym on" });
    var objdiff_step = b.step("objdiff", "");
    objdiff_step.dependOn(&objdiff_cmd.step);

    // Step - single
    var single_step = b.step("single", "");
    if (b.args) |args| {
        for (args) |destination| {
            const source = try getSourceByDest(b.graph.io, b.allocator, destination);
            const compile = BuildMWCC.create(b, b.path(source), release);
            const install = b.addInstallFileWithDir(compile.getOutput(), .prefix, destination);
            single_step.dependOn(&install.step);
        }
    }

    // Step - all
    var all_step = b.step("all", "");
    const objdiff = try readObjdiff(b.graph.io, b.allocator);
    for (objdiff.value.units) |unit| {
        const compile = BuildMWCC.create(b, b.path(unit.metadata.source_path orelse continue), release);
        const install = b.addInstallFileWithDir(compile.getOutput(), .prefix, unit.base_path);
        all_step.dependOn(&install.step);
    }

    // Step - report
    const report_cmd = b.addSystemCommand(&.{"objdiff-cli"});
    report_cmd.addArgs(&.{ "report", "generate", "-o", "build/report.json" });
    var report_step = b.step("report", "");
    report_step.dependOn(&report_cmd.step);

    b.default_step = all_step;
}

fn readObjdiff(io: std.Io, allocator: std.mem.Allocator) !std.json.Parsed(OBJDiff) {
    const contents = try std.Io.Dir.readFileAlloc(std.Io.Dir.cwd(), io, "objdiff.json", allocator, .unlimited);

    return try std.json.parseFromSlice(OBJDiff, allocator, contents, .{
        .ignore_unknown_fields = true,
    });
}

fn getSourceByDest(io: std.Io, allocator: std.mem.Allocator, destination: []const u8) ![]u8 {
    const result = try readObjdiff(io, allocator);
    defer result.deinit();

    for (result.value.units) |r| {
        if (std.mem.eql(u8, r.base_path, destination)) {
            if (r.metadata.source_path) |source| {
                return allocator.dupe(u8, source);
            }
        }
    }

    @panic("Could not find the source");
}

fn getSourceByScratch(io: std.Io, allocator: std.mem.Allocator, destination: []const u8) ![]u8 {
    const result = try readObjdiff(io, allocator);
    defer result.deinit();

    for (result.value.units) |r| {
        if (r.scratch) |scratch| {
            if (scratch.ctx_path) |ctx_path| {
                if (std.mem.eql(u8, ctx_path, destination)) {
                    if (r.metadata.source_path) |source| {
                        return allocator.dupe(u8, source);
                    }
                }
            }
        }
    }

    @panic("Could not find the scratch source");
}

//fn compileFile(io: std.Io, source_file: []const u8, destination_file: []const u8) !void {}

//fn generateContext(
//    io: std.Io,
//    source_file: []const u8,
//    destination_file: []const u8,
//) !void {
//    const i = std.mem.lastIndexOf(u8, destination_file, &[_]u8{'/'}) orelse 0;
//    std.Io.Dir.createDirPath(std.Io.Dir.cwd(), io, destination_file[0..i]) catch undefined;
//
//    const command = .{
//        "zig",
//        "c++",
//        source_file,
//        "-o",
//        destination_file,
//        "-E",
//        "-P",
//        "-undef",
//        "-I",
//        "lib/Nitro/",
//        "-D",
//        "__MWERKS__",
//        "-D",
//        release.macroName(),
//        //"-dD",
//    };
//
//    var child = try std.process.spawn(io, .{ .argv = &command });
//    const exit_code = try child.wait(io);
//    switch (exit_code) {
//        .exited => |id| {
//            if (id > 0) return error.BUILD_ERROR;
//        },
//        else => {},
//    }
//}

//fn taskSingle(self: *std.Build.Step, _: std.Build.Step.MakeOptions) !void {
//    const io = self.owner.graph.io;
//    const allocator = self.owner.allocator;
//    const args = self.owner.args orelse @panic("Missing argument?");
//    const destination_file = args[0];
//
//    if (std.mem.find(u8, destination_file, ".ctx")) |_| {
//        const source_file = try getSourceByScratch(io, allocator, destination_file);
//        generateContext(io, source_file, destination_file) catch @panic("");
//    } else {
//        const source_file = try getSourceByDest(io, allocator, destination_file);
//        compileFile(io, source_file, destination_file) catch @panic("");
//    }
//}
//
//fn taskAll(self: *std.Build.Step, _: std.Build.Step.MakeOptions) !void {
//    const io = self.owner.graph.io;
//    const allocator = self.owner.allocator;
//    const result = try readObjdiff(io, allocator);
//
//    for (result.value.units) |r| {
//        if (r.metadata.source_path) |source| {
//            std.log.info("Compiling {s}", .{source});
//            try compileFile(io, source, r.base_path);
//        }
//    }
//}

// Build Steps - modified from https://ziglang.org/documentation/0.16.0/std/#src/std/Build/Step/ObjCopy.zig
const BuildMWCC = struct {
    step: std.Build.Step,
    input_file: std.Build.LazyPath,
    output_file: std.Build.GeneratedFile,
    release: Release,

    pub fn create(owner: *std.Build, input_file: std.Build.LazyPath, release: Release) *@This() {
        const self = owner.allocator.create(@This()) catch @panic("OOM");
        self.* = .{
            .step = .init(.{
                .id = .custom,
                .name = "Compile Single",
                .owner = owner,
                .makeFn = make,
            }),
            .input_file = input_file,
            .output_file = std.Build.GeneratedFile{ .step = &self.step },
            .release = release,
        };
        input_file.addStepDependencies(&self.step);
        return self;
    }

    pub fn getOutput(this: *const @This()) std.Build.LazyPath {
        return .{ .generated = .{ .file = &this.output_file } };
    }

    pub fn make(step: *std.Build.Step, options: std.Build.Step.MakeOptions) !void {
        _ = options;
        const self: *@This() = @fieldParentPtr("step", step);
        const b = step.owner;
        const io = b.graph.io;

        var man = b.graph.cache.obtain();
        defer man.deinit();

        const full_src_path = self.input_file.getPath2(b, step);
        _ = try man.addFile(full_src_path, null);
        man.hash.add(self.release);

        // Check the cache and early return if it is hit.
        const cache_hit = try step.cacheHit(&man);

        const cache_path = "o" ++ std.fs.path.sep_str ++ man.hex_digest;
        const full_dest_path = try b.cache_root.join(b.allocator, &.{
            cache_path, std.fs.path.basename(full_src_path),
        });

        if (cache_hit) {
            self.output_file.path = full_dest_path;
            return;
        }

        b.cache_root.handle.createDirPath(io, cache_path) catch |err| {
            return step.fail("unable to make path {s}: {s}", .{ cache_path, @errorName(err) });
        };

        // Run the build command
        var argv = std.array_list.Managed([]const u8).init(b.allocator);
        if (builtin.target.os.tag != .windows) try argv.append("wine");
        try argv.appendSlice(&.{
            "./build/compiler/mwccarm/1.2/sp3/mwccarm.exe",
            full_src_path,
            "-o",
            full_dest_path,
            "-O4,p",
            "-interworking",
            "-proc=arm946e",
            "-lang=C++",
            "-Cpp_exceptions=off",
            "-w=off",
            "-gccinc",
            "-nolink",
            "-c",
            "-sym=on",
            "-RTTI=off",
            "-once",
            "-i",
            "lib/Nitro/",
            "-d",
            self.release.macroName(),
        });

        var child = try std.process.spawn(io, .{ .argv = argv.items });
        const exit_code = try child.wait(io);
        switch (exit_code) {
            .exited => |id| {
                if (id > 0) return error.BUILD_ERROR;
            },
            else => {},
        }

        // Add the C++ file's includes into cache check
        // https://ziglang.org/documentation/0.16.0/std/#src/std/Build/Step/Run.zig
        const dep_path = try b.cache_root.join(b.allocator, &.{ cache_path, "deps.d" });
        var dep_scan = try std.process.spawn(io, .{ .argv = &.{
            b.graph.zig_exe,
            "c++",
            full_src_path,
            "-MM",
            "-MV",
            "-MF",
            dep_path,
            "-I",
            "lib/Nitro/",
            "-D",
            "__MWERKS__",
            "-D",
            self.release.macroName(),
        } });
        switch (try dep_scan.wait(io)) {
            .exited => |code| if (code > 0) return step.fail("exited: {s}", .{full_src_path}),
            else => return step.fail("else: {s}", .{full_src_path}),
        }
        try man.addDepFilePost(b.cache_root.handle, b.pathJoin(&.{ cache_path, "deps.d" }));

        self.output_file.path = full_dest_path;
        try step.writeManifest(&man);
    }
};

// Data types
const Release = enum {
    A2DE,
    A2DJ,
    A85J,
    A85E,
    A2DP,
    A85P,
    A85J_1,
    A2DK,
    A2DC,
    Y7QJ,

    // Returns the enum name (e.g. A2DE)
    pub fn name(self: Release) []const u8 {
        return @tagName(self);
    }

    // Returns the enum name with .nds appended (e.g. A2DE.nds)
    pub fn fileName(self: Release) []const u8 {
        return switch (self) {
            inline else => |en| @tagName(en) ++ ".nds",
        };
    }

    // Returns the name with VER_ preanded (e.g. VER_A2DE)
    pub fn macroName(self: Release) []const u8 {
        return switch (self) {
            inline else => |en| "VER_" ++ @tagName(en),
        };
    }

    pub fn commandName(self: Release) []const u8 {
        return switch (self) {
            inline else => |en| "-DRelease=" ++ @tagName(en),
        };
    }

    pub fn compilerPath(self: Release) []const u8 {
        return switch (self) {
            .Y7QJ => "./build/compiler/mwccarm/2.0/sp2p4/mwccarm.exe", // TODO: Confirm the exact version this it should use.
            else => "./build/compiler/mwccarm/1.2/sp3/mwccarm.exe", // TODO: Confirm is sp3 or sp4
        };
    }
};

const OBJDiff = struct {
    units: []struct {
        base_path: []u8 = "",
        scratch: ?struct {
            ctx_path: ?[]u8 = null,
        } = .{},
        metadata: struct {
            source_path: ?[]u8 = null,
        },
    },
};

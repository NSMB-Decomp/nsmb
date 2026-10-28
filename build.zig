const std = @import("std");

pub fn build(b: *std.Build) !void {
    const release = b.option(Release, "Release", "") orelse Release.A2DE;

    // Steps - extract
    const dsd = addDsdCommands(b, release, null);
    const extract_step = b.step("extract", "");
    extract_step.dependOn(&dsd.extract.step);
    // Step - delink
    const delink_step = b.step("delink", "");
    delink_step.dependOn(&dsd.delink.step);
    // Step - objdiff
    const objdiff_step = b.step("objdiff", "");
    objdiff_step.dependOn(&dsd.objdiff.step);

    const config_inputs = try findConfigFiles(b, release);
    const objdiff_cmd = addDsdCommands(b, release, config_inputs).objdiff;

    // Step - all
    const all_step = b.step("all", "");
    if (try readObjdiff(b)) |objdiff| {
        for (objdiff.value.units) |unit| {
            const source = b.path(unit.metadata.source_path orelse continue);

            if (unit.base_path.len > 0) {
                const output = buildMWCC(b, source, release, &objdiff_cmd.step);
                const install = b.addInstallFileWithDir(output, .{ .custom = ".." }, unit.base_path);
                b.step(unit.base_path, "").dependOn(&install.step);
                all_step.dependOn(&install.step);
            }

            if (unit.scratch) |scratch| if (scratch.ctx_path) |ctx_path| {
                const output = buildCTX(b, source, release, &objdiff_cmd.step);
                const install = b.addInstallFileWithDir(output, .{ .custom = ".." }, ctx_path);
                b.step(ctx_path, "").dependOn(&install.step);
            };
        }
    }

    // Step - report
    const report_cmd = b.addSystemCommand(&.{"objdiff-cli"});
    report_cmd.addArgs(&.{ "report", "generate", "-o", "build/report.json" });
    report_cmd.step.dependOn(all_step);
    const report_step = b.step("report", "");
    report_step.dependOn(&report_cmd.step);

    b.default_step = all_step;
}

const DsdCommands = struct {
    extract: *std.Build.Step.Run,
    delink: *std.Build.Step.Run,
    objdiff: *std.Build.Step.Run,
};

fn addDsdCommands(b: *std.Build, release: Release, cached_inputs: ?[]const std.Build.LazyPath) DsdCommands {
    // Define paths that are used in the build steps
    const rom_file = b.path(release.romName());
    const extract_directory = b.pathJoin(&.{ "extracted", release.name(), "" });
    const config_file = b.path(b.pathJoin(&.{ "config", release.name(), "arm9/config.yaml" }));

    // Step - extract
    const extract_cmd = b.addSystemCommand(&.{"dsd"});
    extract_cmd.setCwd(b.path("."));
    extract_cmd.addArgs(&.{ "rom", "extract" });
    extract_cmd.addArgs(&.{ "-o", extract_directory });
    extract_cmd.addArg("-r");
    extract_cmd.addFileArg(rom_file);

    // Step - delink
    const delink_cmd = b.addSystemCommand(&.{"dsd"});
    delink_cmd.setCwd(b.path("."));
    delink_cmd.addArgs(&.{ "delink", "-c" });
    delink_cmd.addFileArg(config_file);
    delink_cmd.step.dependOn(&extract_cmd.step);

    // Step - objdiff
    const objdiff_cmd = b.addSystemCommand(&.{"dsd"});
    objdiff_cmd.setCwd(b.path("."));
    objdiff_cmd.addArgs(&.{ "objdiff", "-c" });
    objdiff_cmd.addFileArg(config_file);
    objdiff_cmd.addArgs(&.{ "-m", b.graph.zig_exe });
    objdiff_cmd.addArgs(&.{ "-M", "build", "-M", release.commandName() });
    objdiff_cmd.addArgs(&.{ "-s", "-C", "mwcc_20_84", "-p", "201" });
    objdiff_cmd.addArgs(&.{ "-f", "-O4,p -interworking -proc=arm946e -w=off -gccinc -nolink -c -Cpp_exceptions off -lang=c++ -RTTI off -sym on" });
    objdiff_cmd.step.dependOn(&delink_cmd.step);

    if (cached_inputs) |inputs| {
        for ([_]*std.Build.Step.Run{ extract_cmd, delink_cmd, objdiff_cmd }) |cmd| {
            _ = cmd.captureStdOut(.{});
            _ = cmd.captureStdErr(.{});
        }
        delink_cmd.addFileInput(rom_file);
        for (inputs) |input| {
            delink_cmd.addFileInput(input);
            objdiff_cmd.addFileInput(input);
        }
    }

    return .{ .extract = extract_cmd, .delink = delink_cmd, .objdiff = objdiff_cmd };
}

// Returns every file in config/<release>/. Configure reruns when a file is added or removed.
fn findConfigFiles(b: *std.Build, release: Release) ![]const std.Build.LazyPath {
    const io = b.graph.io;
    const config_directory = b.pathJoin(&.{ "config", release.name() });
    b.dependOnDirectoryMetadata(b.path(config_directory));

    var dir = try std.Io.Dir.openDir(std.Io.Dir.cwd(), io, config_directory, .{ .iterate = true });
    defer dir.close(io);
    var walker = try dir.walk(b.allocator);
    defer walker.deinit();

    var files: std.ArrayList(std.Build.LazyPath) = .empty;
    while (try walker.next(io)) |entry| {
        const path = b.path(b.pathJoin(&.{ config_directory, entry.path }));
        switch (entry.kind) {
            .file => try files.append(b.allocator, path),
            .directory => b.dependOnDirectoryMetadata(path),
            else => {},
        }
    }
    return files.items;
}

// Returns null when objdiff.json has not been generated yet. Configure reruns when it changes or appears.
fn readObjdiff(b: *std.Build) !?std.json.Parsed(OBJDiff) {
    const contents = std.Io.Dir.readFileAlloc(std.Io.Dir.cwd(), b.graph.io, "objdiff.json", b.allocator, .unlimited) catch |err| switch (err) {
        error.FileNotFound => {
            // Depending on a missing file fails configure, so watch the directory that will hold it
            b.dependOnDirectoryMetadata(b.path("."));
            return null;
        },
        else => return err,
    };
    b.dependOnFileContents(b.path("objdiff.json"));

    return try std.json.parseFromSlice(OBJDiff, b.allocator, contents, .{
        .ignore_unknown_fields = true,
    });
}

fn buildCTX(b: *std.Build, source: std.Build.LazyPath, release: Release, after: *std.Build.Step) std.Build.LazyPath {
    const run = b.addSystemCommand(&.{ b.graph.zig_exe, "c++" });
    run.setName(b.fmt("ctx {s}", .{source.getDisplayName()}));
    run.setCwd(b.path("."));
    run.addFileArg(source);
    run.addArg("-o");
    const output = run.addOutputFileArg(std.fs.path.basename(source.getDisplayName()));
    run.addArgs(&.{
        "-E",
        "-P",
        "-undef",
        "-I",
        "lib/nitro/include/",
        "-I",
        "lib/nitro/libs/c/include/",
        "-D",
        "__MWERKS__",
        "-D",
        release.macroName(),
        "-MD",
        "-MF",
    });
    _ = run.addDepFileOutputArg2("deps.d", .{});
    run.step.dependOn(after);
    return output;
}

// $0 = zig, $1 = source, $2 = dep file, $3 = release macro
const mwcc_script =
    \\"$0" c++ "$1" -MM -MF "$2" -I lib/nitro/include/ -I lib/nitro/libs/c/include/ -D __MWERKS__ -D "$3" && shift 3 && exec "$@"
;

fn buildMWCC(b: *std.Build, source: std.Build.LazyPath, release: Release, after: *std.Build.Step) std.Build.LazyPath {
    const run = b.addSystemCommand(&.{ "sh", "-c", mwcc_script, b.graph.zig_exe });
    run.setName(b.fmt("mwcc {s}", .{source.getDisplayName()}));
    run.setCwd(b.path("."));
    run.addFileArg(source);
    _ = run.addDepFileOutputArg2("deps.d", .{});
    run.addArg(release.macroName());

    // Run the build command
    if (b.graph.host.result.os.tag != .windows) run.addArg("wine");
    run.addArg(release.compilerPath());
    run.addFileArg(source);
    run.addArg("-o");
    const output = run.addOutputFileArg(b.fmt("{s}.o", .{std.fs.path.stem(source.getDisplayName())}));
    run.addArgs(&.{
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
        "lib/nitro/include/",
        "-i",
        "lib/nitro/libs/c/include/",
        "-d",
        release.macroName(),
    });
    run.step.dependOn(after);
    return output;
}

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
    pub fn romName(self: Release) []const u8 {
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
            else => "./build/compiler/mwccarm/1.2/sp3/mwccarm.exe", // Confirmed to be sp3, sp3 & sp4 seem to result in the same output. However sp4 was build after A2DE.
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

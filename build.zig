const std = @import("std");

pub fn build(b: *std.Build) void {
    const release = b.option(Release, "Release", "") orelse Release.A2DE;

    // Define paths that are used in the build steps
    const rom_file = b.path(release.fileName());
    const extract_directory = b.path(b.pathJoin(&.{ "extracted", release.name(), "" }));
    const config_file = b.path(b.pathJoin(&.{ "config", release.name(), "arm9/config.yaml" }));

    //std.log.info("{s}", .{rom_file});

    // step - extract
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
    // dsd objdiff -c config/$NSMB_RELEASE/arm9/config.yaml -m $PWD/build.sh
    objdiff_cmd.addArgs(&.{ "objdiff", "-c" });
    objdiff_cmd.addFileArg(config_file);
    objdiff_cmd.addArgs(&.{ "-m", "zig" });
    objdiff_cmd.addArgs(&.{ "-M", "build", "-M", "single", "-M", "--" });
    //objdiff_cmd.addArgs(&.{ "-s", "-C", "mwcc_20_84", "-p", "201" });
    //objdiff_cmd.addArgs(&.{ "-f", "-O4,p -interworking -proc=arm946e -w=off -gccinc -nolink -c -Cpp_exceptions off -lang=c++ -RTTI off -sym on" });

    var objdiff_step = b.step("objdiff", "");
    objdiff_step.dependOn(&objdiff_cmd.step);

    // Step - single
    var single_step = b.step("single", "");
    //single_step.dependOn(objdiff_step);
    single_step.makeFn = &taskSingle;
    config_file.addStepDependencies(single_step);

    // Step - all
    var all_step = b.step("all", "");
    all_step.dependOn(objdiff_step);
    all_step.makeFn = &taskAll;

    // Step - report
    const report_cmd = b.addSystemCommand(&.{"objdiff-cli"});
    report_cmd.addArgs(&.{ "report", "generate", "-o", "build/report.json" });

    var report_step = b.step("report", "");
    report_step.dependOn(&report_cmd.step);
}

fn read_objdiff() !std.json.Parsed(OBJDiff) {
    const cwd = std.fs.cwd();
    const objdiff = try cwd.openFile("objdiff.json", .{ .mode = .read_only });
    var buffer: [1024 * 64]u8 = undefined;
    const buffer_length = try objdiff.read(&buffer);
    const buffer_slice = buffer[0..buffer_length];

    return try std.json.parseFromSlice(OBJDiff, std.heap.smp_allocator, buffer_slice, .{
        .ignore_unknown_fields = true,
    });
}

fn getSourceByDest(destination: []const u8) ![]u8 {
    const result = try read_objdiff();
    defer result.deinit();

    for (result.value.units) |r| {
        if (std.mem.eql(u8, r.base_path, destination)) {
            if (r.metadata.source_path) |source| {
                return source;
            }
        }
    }

    @panic("Could not find something");
}

fn compileFile(source_file: []const u8, destination_file: []const u8) !void {
    const i = std.mem.lastIndexOf(u8, destination_file, &[_]u8{'/'}) orelse 0;
    std.fs.cwd().makePath(destination_file[0..i]) catch undefined;

    const command = .{
        "wine",
        "./build/compiler/mwccarm/1.2/sp3/mwccarm.exe",
        source_file,
        "-o",
        destination_file,
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
    };
    var child = std.process.Child.init(&command, std.heap.smp_allocator);
    const exit_code = try child.spawnAndWait();
    switch (exit_code) {
        .Exited => |id| {
            if (id > 0) return error.BUILD_ERROR;
        },
        else => {},
    }
}

fn taskSingle(self: *std.Build.Step, _: std.Build.Step.MakeOptions) !void {
    const args = self.owner.args orelse @panic("Missing argument?");
    const destination_file = args[0];
    const source_file = try getSourceByDest(destination_file);

    compileFile(source_file, destination_file) catch @panic("");
}

fn taskAll(_: *std.Build.Step, _: std.Build.Step.MakeOptions) !void {
    const result = try read_objdiff();

    for (result.value.units) |r| {
        if (r.metadata.source_path) |source| {
            std.log.info("Compiling {s}", .{source});
            try compileFile(source, r.base_path);
        }
    }
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

    // Returns the enum name with .nds appended (e.g. A2DE.nds)
    pub fn fileName(self: Release) []const u8 {
        return switch (self) {
            inline else => |en| @tagName(en) ++ ".nds",
        };
    }

    // Returns the enum name (e.g. A2DE)
    pub fn name(self: Release) []const u8 {
        return @tagName(self);
    }
};

const OBJDiff = struct {
    units: []struct {
        base_path: []u8 = "",
        metadata: struct {
            source_path: ?[]u8 = null,
        },
    },
};
const OBJDiff_Full = struct {
    min_version: []u8,
    custom_make: []u8,
    custom_args: [][]u8,
    target_dir: []u8,
    base_dir: []u8,
    build_base: bool,
    build_target: bool,
    watch_patterns: [][]u8,
    units: []struct {
        name: []u8,
        target_path: []u8,
        base_path: []u8 = "",
        metadata: struct {
            complete: bool,
            reverse_fn_order: bool,
            auto_generated: bool,
            source_path: ?[]u8 = null,
        },
    },
};

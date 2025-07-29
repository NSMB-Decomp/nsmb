const std = @import("std");

const Release = enum {
    A2DE,
};

pub fn build(b: *std.Build) void {
    const release_enum = b.option(Release, "Release", "") orelse Release.A2DE;

    const target_options = b.standardTargetOptions(.{});
    _ = target_options;

    const release = @tagName(release_enum);
    const rom_file = b.path("A2DE.nds");
    const extract_directory = b.path(b.pathJoin(&.{ "extracted", release }));
    const config_file = b.path(b.pathJoin(&.{ "config", release, "arm9/config.yaml" }));

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
    objdiff_cmd.addArgs(&.{ "-s", "-C", "mwcc_20_84" });
    objdiff_cmd.addArgs(&.{ "-f", "-O4,p -interworking -proc=arm946e -lang=C++ -Cpp_exceptions=off -w=off -gccinc -nolink -c -sym=on -RTTI=off" });

    var objdiff_step = b.step("objdiff", "");
    objdiff_step.dependOn(&objdiff_cmd.step);

    // Step - single
    var single_step = b.step("single", "");
    single_step.dependOn(objdiff_step);
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
// Read ObjDiff
const OBJDiff = struct {
    units: []struct {
        base_path: []u8 = "",
        metadata: struct {
            source_path: ?[]u8 = null,
        },
    },
};
fn read_objdiff() !std.json.Parsed(OBJDiff) {
    const cwd = std.fs.cwd();
    const objdiff = try cwd.openFile("objdiff.json", .{ .mode = .read_only });
    var buffer: [1024 * 64]u8 = undefined;
    const buffer_length = try objdiff.read(&buffer);
    const buffer_slice = buffer[0..buffer_length];

    return try std.json.parseFromSlice(OBJDiff, std.heap.page_allocator, buffer_slice, .{
        .ignore_unknown_fields = true,
    });
}
fn getSourceByDest(destination: []const u8) ![]u8 {
    const result = try read_objdiff();

    for (result.value.units) |r| {
        if (std.mem.eql(u8, r.base_path, destination)) {
            if (r.metadata.source_path) |source| {
                return source;
            }
        }
    }

    @panic("Could not find something");
}

// Signle
fn compileFile(source_file: []const u8, destination_file: []const u8) !void {
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
    };
    var child = std.process.Child.init(&command, std.heap.page_allocator);
    const b = try child.spawnAndWait();
    switch (b) {
        .Exited => |id| {
            if (id > 0) return error.BUILD_ERROR;
        },
        .Signal => |_| {},
        .Stopped => |_| {},
        .Unknown => |_| {},
    }
}
fn taskSingle(self: *std.Build.Step, _: std.Build.Step.MakeOptions) !void {
    const args = self.owner.args orelse @panic("Missing argument?");
    const destination_file = args[0];
    const source_file = try getSourceByDest(destination_file);

    compileFile(source_file, destination_file) catch {
        @panic("Failed to build");
    };
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

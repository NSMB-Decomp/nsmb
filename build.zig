const std = @import("std");

const Roms = enum {
    A2DE,
};

pub fn build(b: *std.Build) void {
    const release_enum = b.option(Roms, "Release", "") orelse Roms.A2DE;

    const target_options = b.standardTargetOptions(.{});

    const release = @tagName(release_enum);
    const rom_file = b.path("A2DE.nds");
    const extract_directory = b.path(b.pathJoin(&.{ "extracted", release }));
    const config_file = b.path(b.pathJoin(&.{ "config", release, "arm9/config.yaml" }));
    const mwcc_exe = b.path("./build/compiler/mwccarm/1.2/sp3/mwccarm.exe");

    // Extract Step
    const extract_cmd = b.addSystemCommand(&.{"dsd"});
    extract_cmd.addArgs(&.{ "rom", "extract" });
    extract_cmd.addArg("-o");
    extract_cmd.addFileArg(extract_directory);
    extract_cmd.addArg("-r");
    extract_cmd.addFileArg(rom_file);

    const extract_step = b.step("extract", "");
    extract_step.dependOn(&extract_cmd.step);

    // Delink Step
    const delink_cmd = b.addSystemCommand(&.{"dsd"});
    delink_cmd.addArgs(&.{ "delink", "-c" });
    delink_cmd.addFileArg(config_file);

    const delink_step = b.step("delink", "");
    delink_step.dependOn(&delink_cmd.step);

    // Objdiff step
    const objdiff_cmd = b.addSystemCommand(&.{"dsd"});
    // dsd objdiff -c config/$NSMB_RELEASE/arm9/config.yaml -m $PWD/build.sh
    objdiff_cmd.addArgs(&.{ "objdiff", "-c" });
    objdiff_cmd.addFileArg(config_file);
    objdiff_cmd.addArgs(&.{ "-m", "zig" });
    objdiff_cmd.addArgs(&.{ "-M", "build", "-M", "--", "-M", "single" });

    const objdiff_step = b.step("objdiff", "");
    objdiff_step.dependOn(&objdiff_cmd.step);

    // Single step
    const cmd: []const []const u8 = if (target_options.result.os.tag != .windows) &.{ "wine", mwcc_exe.getDisplayName() } else &.{mwcc_exe.getDisplayName()};
    const single_cmd = b.addSystemCommand(cmd);
    if (b.args) |args| {
        single_cmd.addArg("./src/Base.cpp");
        single_cmd.addArgs(&.{ "-o", args[0] });
        single_cmd.addArgs(&.{
            "-O4,p",
            "-interworking",
            "-proc=arm946e",
            "-lang=C++",
            "-Cpp_exceptions=off",
            "-w=off",
            "-gccinc",
            "-nolink",
            "-c",
            "-RTTI=off",
        });
    }

    const single_step = b.step("single", "");
    single_step.dependOn(&single_cmd.step);
}

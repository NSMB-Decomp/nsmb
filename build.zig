const std = @import("std");

const Roms = enum {
    A2DE,
};

pub fn build(b: *std.Build) void {
    const release_enum = b.option(Roms, "Release", "") orelse Roms.A2DE;

    const target_options = b.standardTargetOptions(.{});
    _ = target_options;

    const release = @tagName(release_enum);
    const rom_file = b.path("A2DE.nds");
    const extract_directory = b.path(b.pathJoin(&.{ "extracted", release }));
    const config_file = b.path(b.pathJoin(&.{ "config", release, "arm9/config.yaml" }));
    const mwcc_exe = b.path("./build/compiler/mwccarm/1.2/sp3/mwccarm.exe");
    _ = mwcc_exe;

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
    objdiff_cmd.addArgs(&.{ "-M", "build", "-M", "single", "-M", "--" });
    objdiff_cmd.addArgs(&.{ "-s", "-C", "mwcc_20_84" });
    objdiff_cmd.addArgs(&.{ "-f", "-O4,p -interworking -proc=arm946e -lang=C++ -Cpp_exceptions=off -w=off -gccinc -nolink -c -sym=on -RTTI=off" });

    var objdiff_step = b.step("objdiff", "");
    objdiff_step.dependOn(&objdiff_cmd.step);

    var roar = b.step("single", "");
    roar.makeFn = &myTask;
    config_file.addStepDependencies(roar);
}

const Struct = struct {
    units: []struct {
        target_path: []u8,
        metadata: struct {
            source_path: ?[]u8 = null,
        },
    },
};
fn getSourceByDest(destination: []const u8) ![]u8 {
    const cwd = std.fs.cwd();
    const objdiff = try cwd.openFile("objdiff.json", .{ .mode = .read_only });
    var buffer: [1024 * 64]u8 = undefined;
    const buffer_length = try objdiff.read(&buffer);
    const buffer_slice = buffer[0..buffer_length];

    const result = try std.json.parseFromSlice(Struct, std.heap.page_allocator, buffer_slice, .{
        .ignore_unknown_fields = true,
    });

    for (result.value.units) |r| {
        if (std.mem.eql(u8, r.target_path, destination)) {
            if (r.metadata.source_path) |source| {
                return source;
            }
        }
    }

    @panic("Could not find something");
}

fn myTask(self: *std.Build.Step, options: std.Build.Step.MakeOptions) anyerror!void {
    _ = options;
    //self.owner.user_input_options.get();
    const args = self.owner.args orelse @panic("Missing argument?");
    const destination_file = args[0];

    //const destination_file = "config/A2DE/arm9/../../../build/delinks/src/main.o";
    const source_file = try getSourceByDest(destination_file);
    std.log.info("{s}", .{source_file});
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
    _ = b;
}

// Old script
//#!/bin/bash
//
//input_file=$(echo "$1" | sed 's|/build/src|/src|; s|\.o$|.cpp|')
//# I believe the compiler nsmb used is either sp3 or sp4 or some unknown version.
//wine "$PWD/build/compiler/mwccarm/1.2/sp3/mwccarm.exe" \
//    $PWD/$input_file -o $PWD/$1 \
//    -O4,p -interworking -proc arm946e -lang=C++ -Cpp_exceptions off \
//    -w off -gccinc -nolink -c -RTTI off
//
//
//# -O4,p -enum int -proc arm946e -gccext,on -fp soft -lang c99
//# -Cpp_exceptions off -gccinc -interworking -gccdep -MD -g
//# -inline on -str reuse -lang=c -char signed -sym on
//#echo $output_path> a.txt
//
//#wine "/home/umbreon/nsmb/build/compiler/mwccarm/2.0/base/mwccarm.exe" -O4,p \
//#    -enum int -char signed -str noreuse -proc arm946e -gccext,on -fp soft -inline \
//#      noauto -lang=C++ -Cpp_exceptions off -RTTI off -interworking -w off \
//#      -sym on -gccinc -nolink -msgstyle gcc -D_NITRO -D_DEBUG -str reuse  \
//#      -MD -c ./src/Base.cpp

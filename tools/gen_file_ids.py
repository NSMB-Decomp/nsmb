#!/usr/bin/env python3
"""Generate MWCC-compatible NitroFS file ID constants from a Nintendo DS ROM."""

from __future__ import annotations

import argparse
import re
import struct
from pathlib import Path


CPP_KEYWORDS = {
    "and", "and_eq", "asm", "auto", "bitand", "bitor", "bool", "break",
    "case", "catch", "char", "class", "compl", "const", "const_cast",
    "continue", "default", "delete", "do", "double", "dynamic_cast", "else",
    "enum", "explicit", "export", "extern", "false", "float", "for", "friend",
    "goto", "if", "inline", "int", "long", "mutable", "namespace", "new",
    "not", "not_eq", "operator", "or", "or_eq", "private", "protected",
    "public", "register", "reinterpret_cast", "return", "short", "signed",
    "sizeof", "static", "static_cast", "struct", "switch", "template", "this",
    "throw", "true", "try", "typedef", "typeid", "typename", "union",
    "unsigned", "using", "virtual", "void", "volatile", "wchar_t", "while",
    "xor", "xor_eq",
}

# A2DE's FS archive table at 0x0203A6C0 assigns each mounted archive a
# 0x100-file page. The final entry is a sentinel, and the two None entries are
# embedded archives that do not have NitroFS NARC files to inspect here.
MOUNTED_ARCHIVE_ORDER = (
    "Dat_2D",
    "Dat_Basement",
    "Dat_Field",
    "Dat_Fort",
    "Dat_Ice",
    "Dat_Init",
    "Dat_Pipe",
    "Dat_enemy",
    None,
    "menu_title",
    None,
    "ARC0",
    "bomthrow",
    "card",
    "casino",
    "flower_yoshi",
    "hanasagase",
    "jump",
    "luigi_model_mg",
    "mario_model_mg",
    "mg_common",
    "mg_entry",
    "mg_flower",
    "mg_luigi",
    "mg_menu_common",
    "mg_teresa",
    "mg_trampoline",
    "mgvs_common",
    "p_heyho",
    "pachinko",
    "pazzle_panel",
    "snowball",
    "snowwar",
    "tranpu",
    "vs_amida",
    "vs_balloon_fight",
    "vs_escape",
    "vs_flower",
    "vs_mogura",
    "vs_pachinko",
    "vs_riversi",
    "vs_snowball",
    "vs_step_on",
    "vs_tamaire",
    "vs_teresa",
    "vs_wrecking_crew",
    "wrecking_crew",
)

MOUNTED_ARCHIVE_STARTS = {
    name: 0xC000 + slot * 0x100
    for slot, name in enumerate(MOUNTED_ARCHIVE_ORDER)
    if name is not None
}


def read_u16(data: bytes, offset: int) -> int:
    return struct.unpack_from("<H", data, offset)[0]


def read_u32(data: bytes, offset: int) -> int:
    return struct.unpack_from("<I", data, offset)[0]


def identifier(name: str, prefix: str) -> str:
    result = re.sub(r"[^A-Za-z0-9_]", "_", name)
    if not result or result[0].isdigit() or result in CPP_KEYWORDS:
        result = prefix + result
    return result


def parse_fnt(fnt: bytes, fat_file_count: int) -> tuple[int, list[tuple[int, str]]]:
    if len(fnt) < 8:
        raise ValueError("ROM filename table is too small")

    root_subtable = read_u32(fnt, 0)
    first_file_id = read_u16(fnt, 4)
    directory_count = read_u16(fnt, 6)
    if directory_count == 0 or directory_count * 8 > len(fnt):
        raise ValueError("ROM filename table has an invalid directory count")
    if root_subtable >= len(fnt):
        raise ValueError("ROM filename table has an invalid root subtable")

    files: list[tuple[int, str]] = []
    visited: set[int] = set()

    def walk(directory_id: int, parent: str) -> None:
        directory_index = directory_id & 0x0FFF
        if directory_index >= directory_count:
            raise ValueError(f"invalid directory ID 0x{directory_id:04X}")
        if directory_id in visited:
            raise ValueError(f"directory cycle at 0x{directory_id:04X}")
        visited.add(directory_id)

        table_offset = directory_index * 8
        subtable_offset = read_u32(fnt, table_offset)
        file_id = read_u16(fnt, table_offset + 4)
        if subtable_offset >= len(fnt):
            raise ValueError(f"invalid subtable for directory 0x{directory_id:04X}")

        offset = subtable_offset
        while True:
            if offset >= len(fnt):
                raise ValueError(f"unterminated subtable for directory 0x{directory_id:04X}")
            type_and_length = fnt[offset]
            offset += 1
            if type_and_length == 0:
                break

            is_directory = (type_and_length & 0x80) != 0
            name_length = type_and_length & 0x7F
            if name_length == 0 or offset + name_length > len(fnt):
                raise ValueError(f"invalid name in directory 0x{directory_id:04X}")
            name = fnt[offset:offset + name_length].decode("ascii")
            offset += name_length

            path = f"{parent}/{name}" if parent else name
            if is_directory:
                if offset + 2 > len(fnt):
                    raise ValueError(f"missing child ID for directory {path}")
                child_id = read_u16(fnt, offset)
                offset += 2
                walk(child_id, path)
            else:
                if file_id >= fat_file_count:
                    raise ValueError(f"file ID {file_id} for {path} is outside the FAT")
                files.append((file_id, path))
                file_id += 1

    walk(0xF000, "")
    if not files:
        raise ValueError("ROM filename table contains no files")
    return first_file_id, sorted(files)


def parse_narc(data: bytes) -> list[tuple[int, str]]:
    if len(data) < 0x10 or data[:4] != b"NARC":
        raise ValueError("file does not have a valid NARC header")

    header_size = read_u16(data, 0x0C)
    block_count = read_u16(data, 0x0E)
    if header_size < 0x10 or header_size > len(data):
        raise ValueError("NARC has an invalid header size")

    file_count: int | None = None
    filename_table: bytes | None = None
    offset = header_size
    for _ in range(block_count):
        if offset + 8 > len(data):
            raise ValueError("NARC block header lies outside the file")
        block_size = read_u32(data, offset + 4)
        if block_size < 8 or offset + block_size > len(data):
            raise ValueError("NARC has an invalid block size")
        magic = data[offset:offset + 4]
        if magic == b"BTAF":
            if block_size < 12:
                raise ValueError("NARC allocation table is too small")
            file_count = read_u16(data, offset + 8)
        elif magic == b"BTNF":
            filename_table = data[offset + 8:offset + block_size]
        offset += block_size

    if file_count is None or filename_table is None:
        raise ValueError("NARC is missing its allocation or filename table")
    _, files = parse_fnt(filename_table, file_count)
    return files


def read_rom_files(
    rom_path: Path,
) -> tuple[int, list[tuple[int, str]], list[tuple[str, list[tuple[int, str]]]]]:
    rom = rom_path.read_bytes()
    if len(rom) < 0x50:
        raise ValueError("ROM is too small to contain a Nintendo DS header")

    fnt_offset = read_u32(rom, 0x40)
    fnt_size = read_u32(rom, 0x44)
    fat_offset = read_u32(rom, 0x48)
    fat_size = read_u32(rom, 0x4C)
    if fnt_offset + fnt_size > len(rom):
        raise ValueError("ROM filename table lies outside the ROM")
    if fat_size % 8 != 0 or fat_offset + fat_size > len(rom):
        raise ValueError("ROM file allocation table is invalid")

    file_count = fat_size // 8
    first_file_id, files = parse_fnt(
        rom[fnt_offset:fnt_offset + fnt_size],
        file_count,
    )

    archives: list[tuple[str, list[tuple[int, str]]]] = []
    for file_id, path in files:
        if not path.lower().endswith(".narc"):
            continue
        file_start = read_u32(rom, fat_offset + file_id * 8)
        file_end = read_u32(rom, fat_offset + file_id * 8 + 4)
        if file_start > file_end or file_end > len(rom):
            raise ValueError(f"ROM allocation table range for {path} is invalid")
        archives.append((path, parse_narc(rom[file_start:file_end])))

    return first_file_id, files, archives


def path_identifier(path: str) -> str:
    return identifier(path.replace("/", "_"), "part_")


def render_header(
    rom_name: str,
    first_file_id: int,
    files: list[tuple[int, str]],
    archives: list[tuple[str, list[tuple[int, str]]]],
) -> str:
    lines = [
        "#pragma once",
        "",
        "// Generated by tools/gen_file_ids.py. Do not edit.",
        f"// Source ROM: {rom_name}; NitroFS first file ID: {first_file_id}.",
        "// Macros are intentional: MWCC ARM 1.2sp3 then sees only integer",
        "// literals, preserving its private-symbol numbering and exact output.",
        "",
        "#define NSMB_FID(name) NSMB_FID_##name",
        "#define NSMB_ARC_FID(name) NSMB_ARC_FID_##name",
        "#define NSMB_VS_FID(fid, arcFid) \\",
        "    ((NSMB_ARC_FID(arcFid) << 16) | NSMB_FID(fid))",
        "",
    ]

    generated: dict[str, str] = {}

    def add_macro(name: str, value: int, path: str) -> None:
        existing = generated.get(name)
        if existing is not None and existing != path:
            raise ValueError(
                f"paths {existing!r} and {path!r} generate "
                f"the same macro {name!r}"
            )
        generated[name] = path
        lines.append(f"#define {name} 0x{value:04X} // {path}")

    for file_id, path in files:
        add_macro(
            "NSMB_FID_" + path_identifier(path),
            file_id - first_file_id,
            path,
        )

    lines.append("")
    for archive_path, archive_files in sorted(archives):
        archive_base = str(Path(archive_path).with_suffix(""))
        archive_identifier = path_identifier(archive_base)
        archive_name = Path(archive_base).name
        archive_start = MOUNTED_ARCHIVE_STARTS.get(archive_name)
        if archive_start is None:
            raise ValueError(
                f"{archive_path!r} has no A2DE mounted archive range"
            )
        add_macro(
            "NSMB_ARC_FILE_COUNT_" + archive_identifier,
            len(archive_files),
            archive_path,
        )
        for file_id, path in archive_files:
            add_macro(
                "NSMB_ARC_FID_"
                + path_identifier(path),
                archive_start + file_id,
                f"{archive_path}:{path}",
            )

    lines.append("")
    return "\n".join(lines)


def main() -> None:
    parser = argparse.ArgumentParser(
        description="Generate MWCC-compatible NitroFS file ID constants",
    )
    parser.add_argument("--rom", required=True, type=Path)
    parser.add_argument("--output", required=True, type=Path)
    args = parser.parse_args()

    first_file_id, files, archives = read_rom_files(args.rom)
    header = render_header(
        args.rom.name,
        first_file_id,
        files,
        archives,
    )
    args.output.parent.mkdir(parents=True, exist_ok=True)
    args.output.write_text(header, encoding="ascii", newline="\n")
    print(
        f"Generated {args.output} with {len(files)} ROM file IDs and "
        f"{sum(len(files) for _, files in archives)} archive file IDs "
        f"from {args.rom} (offset {first_file_id})"
    )


if __name__ == "__main__":
    main()

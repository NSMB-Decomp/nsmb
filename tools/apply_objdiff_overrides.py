#!/usr/bin/env python3
"""Apply or remove tracked unit overrides in the generated objdiff configuration."""

from __future__ import annotations

import argparse
import json
import os
import tempfile
from pathlib import Path
from typing import Any


REPO_ROOT = Path(__file__).resolve().parents[1]
OBJDIFF_PATH = REPO_ROOT / "objdiff.json"
OVERRIDES_PATH = REPO_ROOT / "config" / "objdiff-unit-overrides.json"


def apply_overrides(
    objdiff: dict[str, Any], overrides_by_unit: dict[str, dict[str, Any]]
) -> None:
    units = {unit.get("name"): unit for unit in objdiff.get("units", [])}
    missing = sorted(set(overrides_by_unit) - units.keys())
    if missing:
        raise ValueError(f"objdiff units not found: {', '.join(missing)}")

    for unit_name, overrides in overrides_by_unit.items():
        unit = units[unit_name]
        for key in ("symbol_mappings", "options"):
            values = overrides.get(key, {})
            unit.setdefault(key, {}).update(values)


def remove_overrides(
    objdiff: dict[str, Any], overrides_by_unit: dict[str, dict[str, Any]]
) -> None:
    units = {unit.get("name"): unit for unit in objdiff.get("units", [])}
    missing = sorted(set(overrides_by_unit) - units.keys())
    if missing:
        raise ValueError(f"objdiff units not found: {', '.join(missing)}")

    for unit_name, overrides in overrides_by_unit.items():
        unit = units[unit_name]
        for key in ("symbol_mappings", "options"):
            current = unit.get(key)
            if not isinstance(current, dict):
                continue
            for name, value in overrides.get(key, {}).items():
                if current.get(name) == value:
                    current.pop(name)
            if not current:
                unit.pop(key)


def main() -> None:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument(
        "--remove",
        action="store_true",
        help="remove tracked overrides instead of applying them",
    )
    args = parser.parse_args()

    objdiff = json.loads(OBJDIFF_PATH.read_text())
    overrides = json.loads(OVERRIDES_PATH.read_text())
    if args.remove:
        remove_overrides(objdiff, overrides)
    else:
        apply_overrides(objdiff, overrides)

    handle, temporary_name = tempfile.mkstemp(
        dir=OBJDIFF_PATH.parent, prefix=".objdiff.", suffix=".json"
    )
    try:
        with os.fdopen(handle, "w") as temporary:
            json.dump(objdiff, temporary, indent=2)
            temporary.write("\n")
        os.replace(temporary_name, OBJDIFF_PATH)
    except BaseException:
        try:
            os.unlink(temporary_name)
        except FileNotFoundError:
            pass
        raise


if __name__ == "__main__":
    main()

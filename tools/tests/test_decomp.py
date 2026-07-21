import importlib.machinery
import importlib.util
import unittest
from pathlib import Path


HARNESS = Path(__file__).resolve().parents[1] / "decomp"
LOADER = importlib.machinery.SourceFileLoader("nsmb_decomp_harness", str(HARNESS))
SPEC = importlib.util.spec_from_loader(LOADER.name, LOADER)
decomp = importlib.util.module_from_spec(SPEC)
LOADER.exec_module(decomp)


class UnitResolutionTests(unittest.TestCase):
    def setUp(self):
        self.units = [
            {
                "name": "src/system/main",
                "base_path": "build/A2DE/src/system/main.o",
                "metadata": {"source_path": "src/system/main.cpp"},
            },
            {
                "name": "src/menu/main",
                "base_path": "build/A2DE/src/menu/main.o",
                "metadata": {"source_path": "src/menu/main.cpp"},
            },
        ]

    def test_resolves_source_path(self):
        self.assertEqual(
            decomp.resolve_unit(self.units, "src/system/main.cpp")["name"],
            "src/system/main",
        )

    def test_rejects_ambiguous_basename(self):
        with self.assertRaises(decomp.HarnessError) as context:
            decomp.resolve_unit(self.units, "main")
        self.assertEqual(len(context.exception.candidates), 2)


class ReportTests(unittest.TestCase):
    def test_summarizes_numeric_strings_and_candidates(self):
        report = {
            "version": 2,
            "measures": {
                "matched_code": "10",
                "total_code": "100",
                "matched_code_percent": 10.0,
                "matched_functions": 1,
                "total_functions": 3,
            },
            "units": [
                {
                    "name": "src/test",
                    "metadata": {"source_path": "src/test.cpp"},
                    "measures": {"total_code": "20", "matched_code_percent": 75.0},
                }
            ],
        }
        summary = decomp.summarize_report(report)
        self.assertEqual(summary["matched_code"], 10)
        self.assertEqual(summary["total_code"], 100)
        self.assertEqual(summary["candidates"][0]["name"], "src/test")


class GhidraSelectionTests(unittest.TestCase):
    def setUp(self):
        self.index = {
            "functions": [
                {
                    "program": "/arm9",
                    "name": "NitroMain",
                    "qualified_name": "NitroMain",
                    "entry": "02003000",
                },
                {
                    "program": "/overlay/ov001",
                    "name": "NitroMain",
                    "qualified_name": "Overlay::NitroMain",
                    "entry": "02003000",
                },
            ]
        }

    def test_program_resolves_duplicate_symbol(self):
        selected = decomp.select_ghidra_function(
            self.index, "NitroMain", program="/arm9"
        )
        self.assertEqual(selected["program"], "/arm9")

    def test_rejects_duplicate_address(self):
        with self.assertRaises(decomp.HarnessError):
            decomp.select_ghidra_function(self.index, "0x02003000")

    def test_maps_repository_symbol_to_ghidra_address(self):
        index = {
            "functions": [
                {
                    "program": "/NSMB.nds",
                    "name": "main",
                    "qualified_name": "main",
                    "entry": "02003000",
                }
            ]
        }
        selected = decomp.resolve_ghidra_function(index, "NitroMain")
        self.assertEqual(selected["qualified_name"], "main")

    def test_maps_overlay_symbol_to_ghidra_address_space(self):
        index = {
            "functions": [
                {
                    "program": "/NSMB.nds",
                    "name": "func_ov052_02153ab8",
                    "qualified_name": "func_ov052_02153ab8",
                    "entry": "arm9_ov052::02153ab8",
                },
                {
                    "program": "/NSMB.nds",
                    "name": "func_ov054_02153ab8",
                    "qualified_name": "func_ov054_02153ab8",
                    "entry": "arm9_ov054::02153ab8",
                },
            ]
        }
        selected = decomp.resolve_ghidra_function(
            index, "_ZN18MPLevelSelectScene19func_ov052_02153ab8Ev"
        )
        self.assertEqual(selected["entry"], "arm9_ov052::02153ab8")


class HeadlessCommandTests(unittest.TestCase):
    def test_command_is_read_only_and_targets_parent_folder(self):
        command = decomp.ghidra_headless_command(
            Path("/ghidra"),
            Path("/projects"),
            "NSMBDS-Local",
            script_name="DumpFunction.java",
            script_args=["/output", "02003000"],
            program_path="/overlays/ov001",
        )
        self.assertIn("NSMBDS-Local/overlays", command)
        self.assertIn("ov001", command)
        self.assertIn("-readOnly", command)
        self.assertIn("-noanalysis", command)


if __name__ == "__main__":
    unittest.main()

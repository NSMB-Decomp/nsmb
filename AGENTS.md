# NSMB Decompilation Agent Guide

## Purpose

This repository is a matching decompilation of *New Super Mario Bros.* for Nintendo DS. Work should increase evidence-backed objdiff progress while preserving the original program's behavior, layout, compiler output, and project conventions.

## Legal and Source Boundaries

- Never use NitroSDK implementations, SDK source, SDK binaries, leaked proprietary material, or code derived from them. The repository's clean-room declarations and existing public evidence are the only allowed implementation inputs.
- `/Users/ndymario/NSMB-DS-Modding/NSMB-DB-Latest` is explicitly forbidden input because it uses NitroSDK material. Do not open, copy, index, archive, search, quote, or derive code or types from that project.
- The approved Ghidra source is the authenticated shared `NSMBDS` project at `ghidra.gota7.com`, mirrored into the independent local `NSMBDS-Local` project. Use the shared server only for read-only snapshot export. Never run a mutating script, commit, checkout, rename, or analysis pass against the shared server.
- Do not commit ROMs, save files, extracted ROM data, compiler binaries, Ghidra projects or archives, credentials, generated objdiff configuration, reports, or anything under `build/`.

## Evidence-First Workflow

1. Run `tools/decomp doctor --json` before beginning a decompilation session.
2. Use `tools/decomp progress --json` to establish the current baseline.
3. Select one function and gather evidence from objdiff, the local Ghidra mirror, symbols, relocations, and neighboring code. Treat semantic names and decompiler output as hypotheses until corroborated.
4. Use `tools/decomp work UNIT SYMBOL --json` for the normal compile, diff, and read-only Ghidra context bundle.
5. Make the smallest source change that explains the observed binary. Avoid cleanup, architectural refactors, speculative abstractions, and unrelated formatting.
6. Re-run `tools/decomp diff UNIT SYMBOL --json`, then `tools/decomp progress --json`. A change is not complete until it builds and its effect on matching is measured.

## Build and Matching Rules

- Target the A2DE release unless the task explicitly says otherwise.
- Use the repository's MWCC ARM 1.2sp3 compiler and existing flags. Do not change compiler flags or the Zig build system merely to force a match.
- `objdiff.json`, `objdiff_report.json`, `extracted/`, and `build/` are generated state, not source files.
- Preserve data layout, declaration order, control flow, linkage, and symbol boundaries when binary evidence requires them.
- Do not mark a unit complete based only on a successful compile. Verify exact code and data results in the generated report.
- If evidence is ambiguous, report the competing interpretations and stop before inventing behavior.

## Ghidra Rules

- The default local project is `../NSMB-Ghidra-Local/NSMBDS-Local`. Override discovery only with `GHIDRA_HOME`, `NSMB_GHIDRA_PROJECT_DIR`, or `NSMB_GHIDRA_PROJECT_NAME`.
- Harness Ghidra operations must always include `-readOnly -noanalysis`.
- Generate an index with `tools/decomp ghidra index --json`; dump a function with `tools/decomp ghidra dump SYMBOL --json`.
- Never overwrite a private Ghidra workspace when refreshing. Restore or mirror newer shared snapshots under a new dated project name.

## Git Safety

- `origin` is the private `Ndymario/nsmb` mirror. `upstream` is the public `NSMB-Decomp/nsmb` repository.
- Never push to `upstream`. Push only to `origin` and only when the user asks.
- Preserve unrelated user changes. Do not use destructive Git commands to clean the worktree.

## Validation

- Harness tests: `python3 -m unittest discover -s tools/tests -v`
- Environment: `tools/decomp doctor --json`
- Full baseline: `tools/decomp baseline --json`
- Known smoke unit: `tools/decomp diff src/system/main NitroMain --json`
- Ghidra smoke test: index the local mirror and dump `NitroMain`; all four dump artifacts must be non-empty.

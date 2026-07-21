# NSMB Decompilation Agent Guide

## Purpose

This repository is a matching decompilation of *New Super Mario Bros.* for Nintendo DS. Work should increase evidence-backed objdiff progress while preserving the original program's behavior, layout, compiler output, and project conventions.

## Legal and Source Boundaries

- Never use NitroSDK implementations, SDK source, SDK binaries, leaked proprietary material, or code derived from them. The repository's clean-room declarations and existing public evidence are the only allowed implementation inputs.
- The approved Ghidra source is the authenticated shared `NSMBDS` project at `ghidra.gota7.com`, mirrored into the independent local `NSMBDS-Local` project. Use the shared server only for read-only snapshot export. Never run a mutating script, commit, checkout, rename, or analysis pass against the shared server.
- Do not commit ROMs, save files, extracted ROM data, compiler binaries, Ghidra projects or archives, credentials, generated objdiff configuration, reports, or anything under `build/`.

## Evidence-First Decompilation Loop

### 1. Establish a clean baseline

- Run `tools/decomp doctor --json` before beginning a decompilation session.
- Run `tools/decomp progress --json` and record the current exact/fuzzy code, data, and function totals.
- Inspect `git status --short`. Preserve unrelated work and identify any existing source changes before editing.

### 2. Resolve the target

- Identify one exact objdiff unit, symbol, program or overlay, and address. Do not start from a guessed semantic name.
- Confirm the declaration, owning class, function size, calling convention, and whether the function is inherited or overridden.
- Use the local Ghidra index, repository symbols, and objdiff metadata to resolve naming differences. If a Ghidra MCP is available, it may supplement this evidence, but `tools/decomp` remains the reproducible local path.
- If the name, address, unit, or program is ambiguous, report the candidates and resolve the ambiguity before editing.

### 3. Gather evidence

- Run `tools/decomp work UNIT SYMBOL --json` for the normal compile, objdiff, and read-only Ghidra context bundle.
- Inspect the generated `diff.json`, `decompile.c`, `listing.txt`, `function.json`, and `references.json` beneath `build/decomp/work/`.
- Inspect relevant callers, callees, neighboring functions, relocations, vtables, class layout, and existing repository conventions.
- Treat semantic names and Ghidra pseudocode as hypotheses. Corroborate them with instructions, references, layout, and compiler output.

### 4. Form one hypothesis

- Make the smallest source edit that explains the observed binary.
- Preserve ABI, signatures, data layout, declaration order, types, signedness, temporary lifetime, and control-flow shape where binary evidence requires them.
- Change one meaningful variable at a time. Avoid cleanup, architectural refactors, speculative abstractions, and unrelated formatting.
- Never transcribe or derive implementation material from NitroSDK or another forbidden source.

### 5. Run the tight feedback loop

- Run `tools/decomp diff UNIT SYMBOL --json` after each meaningful edit. This compiles the unit and emits the symbol-level objdiff result.
- Compare exact instructions and relocations, not only semantic behavior or a fuzzy percentage.
- Keep an edit only when it improves the match or provides concrete evidence about the remaining mismatch.
- When stuck, test evidence-backed differences such as expression shape, register pressure, branch structure, signedness, casts, constants, inlining, declaration order, and temporary lifetime. Do not batch speculative rewrites.

### 6. Validate completion

- Require the target function to reach 100% exact code and relocations. A successful compile or semantically equivalent function is not sufficient.
- Run `tools/decomp progress --json` and confirm global code, data, and function totals do not regress.
- Run `tools/decomp baseline --json` before handing off completed decompilation work.

### 7. Verify the authoritative completion report

- After every successful matching/validation cycle, and immediately before any completion claim, commit, or handoff, run `zig build report -DRelease=A2DE` after `tools/decomp baseline --json`. The required order is:

  ```sh
  tools/decomp baseline --json
  zig build report -DRelease=A2DE
  ```

- Treat `build/report.json` as the authoritative completion inventory. Inspect the target unit directly:

  ```sh
  jq '.units[] | select(.name == "UNIT") |
      {name, metadata, measures, sections}' build/report.json
  ```

- For an overlay claim, inspect its entire `delinks.txt` range and every corresponding `_dsd_gap@ovNNN_*` entry in `build/report.json`, including code, `.init`, `.rodata`, `.ctor`, `.data`, and `.bss`. Do not infer overlay completion from a few named source files or from the candidate list disappearing.
- Record the target scope's matched/total code bytes, data bytes, functions, and `metadata.complete` value before committing or handing off.
- Use these terms precisely:
  - **Function matched:** the symbol diff is 100% exact with matching relocations.
  - **Code matched:** all attributed code and functions match, but the unit may still contain unmatched data, relocations, literal pools, or other section content.
  - **Unit complete:** `build/report.json` reports `metadata.complete: true`, matched code/data/functions equal their totals, and objdiff shows no mismatch in any owned section or relocation.
  - **Overlay complete:** every unit in the overlay's `delinks.txt` is complete, aggregate code/data/function totals are exact, and no non-empty `_dsd_gap@ovNNN_*` unit remains.
- If the report does not support `unit complete` or `overlay complete`, use narrower language such as `matched function` or `matched scene code` in commit messages and handoffs.
- Review the final Git diff and remove unrelated changes. Generated evidence remains beneath `build/decomp/` and must not be committed.

## Build and Matching Rules

- Target the A2DE release unless the task explicitly says otherwise.
- Use the repository's MWCC ARM 1.2sp3 compiler and existing flags. Do not change compiler flags or the Zig build system merely to force a match.
- `objdiff.json`, `objdiff_report.json`, `extracted/`, and `build/` are generated state, not source files.
- `objdiff_report.json` is the harness progress summary. `build/report.json` is the canonical completion inventory. Neither report may be committed.
- `zig build report -DRelease=A2DE` only reports the current build/objdiff state; it does not compile the target or rebuild the project. Always run it after the full baseline, and never use it as the sole symbol-matching check.
- Preserve data layout, declaration order, control flow, linkage, and symbol boundaries when binary evidence requires them.
- Do not mark a unit complete based only on a successful compile. Verify exact code and data results in the generated report.
- If evidence is ambiguous, report the competing interpretations and stop before inventing behavior.

## Ghidra Rules

- The default local project is `../NSMB-Ghidra-Local/NSMBDS-Local`. Override discovery only with `GHIDRA_HOME`, `NSMB_GHIDRA_PROJECT_DIR`, or `NSMB_GHIDRA_PROJECT_NAME`.
- Harness Ghidra operations must always include `-readOnly -noanalysis`.
- Generate an index with `tools/decomp ghidra index --json`; dump a function with `tools/decomp ghidra dump SYMBOL --json`.
- Never overwrite a private Ghidra workspace when refreshing. Restore or mirror newer shared snapshots under a new dated project name.

## Git Safety

- `upstream` is the public `NSMB-Decomp/nsmb` repository.
- Never push to `upstream`.
- Preserve unrelated user changes. Do not use destructive Git commands to clean the worktree.
- Do not push without user approval.

## Validation

- Harness tests: `python3 -m unittest discover -s tools/tests -v`
- Environment: `tools/decomp doctor --json`
- Full baseline: `tools/decomp baseline --json`
- Authoritative completion report: `zig build report -DRelease=A2DE`, then inspect `build/report.json`
- Known smoke unit: `tools/decomp diff src/system/main NitroMain --json`
- Ghidra smoke test: index the local mirror and dump `NitroMain`; all four dump artifacts must be non-empty.

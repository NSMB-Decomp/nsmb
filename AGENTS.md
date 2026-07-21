# NSMB Decompilation Agent Guide

## Purpose

This repository is a matching decompilation of *New Super Mario Bros.* for Nintendo DS. Work should increase evidence-backed objdiff progress while preserving the original program's behavior, layout, compiler output, and project conventions.

The end goal is a true 100% match: exact code and data bytes, symbol boundaries, section layout, and relocation destinations. Semantic equivalence, identical referenced data, or a report rounded to 100% does not satisfy this goal when strict objdiff still shows a difference.

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

- Require the target function to reach 100% exact code and relocations under objdiff's strict `name_address` relocation comparison. A successful compile or semantically equivalent function is not sufficient.
- After compiling the target, generate a strict diff explicitly so unit options or report defaults cannot weaken the check:

  ```sh
  objdiff-cli diff -p . -u "UNIT" \
    -c function_reloc_diffs=name_address \
    -o build/decomp/strict-diff.json \
    --format json-pretty
  ```

- Inspect the target symbol and every owned section in `build/decomp/strict-diff.json`. The target symbol and all applicable section `match_percent` values must be exactly `100.0`, with no instruction, argument, relocation, data, insertion, or deletion mismatch.
- Never use `function_reloc_diffs=none` or `function_reloc_diffs=data_value` to justify a completion claim. Those modes may help diagnose whether a mismatch is relocation-only or points at equivalent data, but they intentionally accept differences that prevent a true binary match.
- Run `tools/decomp progress --json` and confirm global code, data, and function totals do not regress.
- Run `tools/decomp baseline --json` before handing off completed decompilation work.

### 7. Verify the completion inventory

- After every successful matching/validation cycle, and immediately before any completion claim, commit, or handoff, rebuild the baseline, generate the inventory, and run the strict diff. The required order is:

  ```sh
  tools/decomp baseline --json
  zig build report -DRelease=A2DE
  objdiff-cli diff -p . -u "UNIT" \
    -c function_reloc_diffs=name_address \
    -o build/decomp/strict-diff.json \
    --format json-pretty
  ```

- Treat `build/report.json` as the authoritative completion inventory, but never as standalone proof of an exact match. Objdiff's report generator disables function-relocation differences, so it can report 100% code/functions while strict objdiff still identifies incorrect relocation destinations. Inspect the target unit directly:

  ```sh
  jq '.units[] | select(.name == "UNIT") |
      {name, metadata, measures, sections}' build/report.json
  ```

- For an overlay claim, inspect its entire `delinks.txt` range and every corresponding `_dsd_gap@ovNNN_*` entry in `build/report.json`, including code, `.init`, `.rodata`, `.ctor`, `.data`, and `.bss`. Run the strict relocation-aware diff for every owned unit. Do not infer overlay completion from a few named source files, the candidate list disappearing, or report totals alone.
- Record the target scope's matched/total code bytes, data bytes, functions, `metadata.complete` value, and strict objdiff result before committing or handing off.
- Use these terms precisely:
  - **Function matched:** the strict `name_address` symbol diff is exactly 100%, including relocation names, destinations, types, and addends.
  - **Code matched:** instruction bytes may match, but the unit can still contain relocation, data, literal-pool, or other section differences. Do not call relocation-equivalent code a matched function.
  - **Unit complete:** `build/report.json` reports `metadata.complete: true`, matched code/data/functions equal their totals, and strict `name_address` objdiff is exactly 100% across every owned section and relocation.
  - **Overlay complete:** every unit in the overlay's `delinks.txt` satisfies the strict unit-complete definition, aggregate code/data/function totals are exact, and no non-empty `_dsd_gap@ovNNN_*` unit remains.
- If `build/report.json` says 100% but strict objdiff says less than 100%, the strict result wins. Report the precise remaining relocation or section mismatch and do not mark, commit, or describe the scope as complete.
- If the report does not support `unit complete` or `overlay complete`, use narrower language such as `matched function` or `matched scene code` in commit messages and handoffs.
- Review the final Git diff and remove unrelated changes. Generated evidence remains beneath `build/decomp/` and must not be committed.

## Build and Matching Rules

- Target the A2DE release unless the task explicitly says otherwise.
- Use the repository's MWCC ARM 1.2sp3 compiler and existing flags. Do not change compiler flags or the Zig build system merely to force a match.
- `objdiff.json`, `objdiff_report.json`, `extracted/`, and `build/` are generated state, not source files.
- `objdiff_report.json` is the harness progress summary. `build/report.json` is the canonical completion inventory, but its function totals do not account for strict function-relocation differences. Neither report may be committed.
- `zig build report -DRelease=A2DE` only reports the current build/objdiff state; it does not compile the target or rebuild the project. Always run it after the full baseline, and never use it as the sole symbol-matching check.
- Keep `function_reloc_diffs=name_address` for final verification. `none` and `data_value` are diagnostic modes only and must never be used to manufacture or support a 100% completion claim.
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
- Completion inventory: `zig build report -DRelease=A2DE`, then inspect `build/report.json`
- Strict completion proof: `objdiff-cli diff -p . -u "UNIT" -c function_reloc_diffs=name_address -o build/decomp/strict-diff.json --format json-pretty`
- Known smoke unit: `tools/decomp diff src/system/main NitroMain --json`
- Ghidra smoke test: index the local mirror and dump `NitroMain`; all four dump artifacts must be non-empty.

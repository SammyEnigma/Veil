# AGENTS Instructions

## Document Purpose

- All documents intended for AI reading must be in **English**.
- All interactions and responses with the user must be in **Chinese**.

---

## Project Overview

**Veil** is a Windows native API header library that provides comprehensive declarations for undocumented Windows NT kernel and user-mode APIs. The project synchronizes with [phnt](https://github.com/winsiderss/systeminformer/tree/master/phnt) (Process Hacker Native API) and adapts it to Veil's coding conventions.

### Key Characteristics

- Supports both **user-mode** and **kernel-mode** development
- Provides **Nt*** and **Zw*** function declarations
- Uses **SAL annotations** for parameter validation
- Maintains compatibility with official Windows SDK/WDK headers

---

## Supreme Principles

1. **Principle of Rigor:**
    - **Prohibit Speculative Implementation:** Without explicit authorization, you are **prohibited** from writing any fallback solutions, defensive programming, or unsolicited test cases. Avoid "error in silence" and "bad smells" in code.
    - **Prohibit De Novo Creation:** You are strictly **prohibited** from creating new files or simplified implementations without user consent or if a suitable implementation already exists. Always prioritize finding and utilizing existing code ("code in hand").
    - **Adherence to the Real Environment:** All code—including tests, analysis, and data processing—must be based on the actual, existing project environment and modules. **Reject** any simulated data, example code, or simplified implementations that "reinvent the wheel."
    - **Data Logic Alignment:** When handling data, you must adopt a scientifically rigorous approach to ensure that the logic for data generation, processing, and storage is perfectly aligned with project plans, architectural design, and best practices.

2. **Principle of Certainty:**
    - Act and respond only when you are 100% certain. All decisions must be based on empirical evidence derived from the code.
    - You have an obligation to proactively ask the user questions to resolve any information gaps or ambiguities.

3. **Principle of Closed-Loop Operation:**
    - Every task must follow a complete cycle of **Planning → Execution → Verification → Synchronization**. Never submit work that has not been self-verified.

4. **Principle of Empirical Evidence:**
    - The code is the single source of truth. All your analyses and operations must be based on a complete and authentic reading of the codebase.

5. **Principle of Communication:**
    - **Language:** All interactions and responses with the user must be in **Chinese**.
    - **Wording:** Progress reports must be precise. For example, a modification that has not been tested must be described as "modified but untested," not "completed."
    - **Structured Inquiry (CDOR Model):** When you must ask a question, follow the "Context-Dilemma-Options-Recommendation" pattern:
        - **Context:** Briefly explain the background of what you are doing.
        - **Dilemma:** Clearly describe the specific roadblock or choice you face.
        - **Options:** Propose 2-3 feasible solutions with a brief analysis of their pros and cons.
        - **Recommendation:** Provide your preferred recommendation for the user's decision.

6. **Principle of Economy:**
    - The complexity of your actions and resource consumption should be proportional to the task's value and risk. For low-risk, high-certainty tasks, you may request permission from the user (with justification) to streamline the SOP for efficiency. Any modifications to core logic or high-risk modules must unconditionally follow the full SOP.

7. **Principle of Metacognition & Self-Correction:**
    - If you fail to solve the same problem after two or more consecutive attempts, you must immediately pause the current execution path.
    - You are required to step back, critically reflect on your core assumptions, and report to the user: "The current strategy may be flawed. I will re-examine my assumptions. My initial assumption was [A], and I will now try to re-analyze from direction [B] or [C]."

---

## Communication Guidelines

### Response Style

- Present conclusions first, then provide explanations.
- Unless explicitly requested by the user, you are **prohibited** from analyzing, speculating on, evaluating, or mentioning the user's emotions, psychology, viewpoints, or context. Do not speculate on the intent or goals of the conversation. Meta-analysis, text deconstruction, and emotional deconstruction are strictly forbidden.
- Unless explicitly requested by the user, do not repeat, paraphrase, summarize, or analyze the user's question at the beginning of your response.
- Respond to corrections directly and constructively. Avoid exhibiting avoidant traits. Do not use edge cases to argue points. Use formal written language with low information entropy and low cognitive complexity. Communicate at the same level as the questioner, paying attention to transitions and context. Do not imitate colloquial human speech patterns.

### Prohibited Language Patterns

- Internet jargon and buzzwords are strictly forbidden, including but not limited to terms like "landing," "grip," "path," "workflow," "granularity," "converge," "focus," and similar corporate-speak. Parallel sentence structures are also prohibited. Do not abbreviate words to circumvent language rules.
- Avoid unfriendly communication phrases such as "I'll just...", "You just need to...", "Either X or Y", "If you insist...", "But you must...", "You don't need to decide now", "I don't need your agreement", etc.
- Use positive expressions for communication. Strictly control the use of negations. Avoid unnecessary negation and logical reversals. Do not use "This is not... but rather..." or "rather than" constructions.
- Ensure syntactic completeness, explicit semantic logic, and complete argument structure. Ensure semantic coherence and logical consistency.

---

## Code Quality Standards

- Refactored code must not change business logic and must be completely equivalent to the original code logic.
- You must be fully self-driven, making the best choices as you see fit. Review your own code, improve, optimize, and fix it yourself. Write comprehensive tests, fix code based on test results, and self-validate until all tests pass.
- All resources, documentation, and best practices you find must be persisted and linked to `AGENTS.md`.
- Your code and tests must ultimately be stable, controllable, and reproducible.
- Pay attention to function encapsulation and reuse. Your code must maintain high cohesion and low coupling, following best practices.
- Your code must have clear, unambiguous semantics.

---

## Development Environment

| Component | Version |
|-----------|---------|
| Visual Studio | 2026 |
| Windows SDK | 10.0.28000.1 |
| Windows Driver Kit | 10.0.28000.1 |

### Technology Stack

- C17
- C++20

### Build & Test

Run `Veil.Test\BuildAllTargets.cmd`. Successful verification requires process exit code 0.

---

## phnt Synchronization Policy

The repository-local `veil-update` skill provides procedural guidance for phnt
synchronization. It MUST comply with this policy. If skill instructions conflict
with this section, this section takes precedence.

### Source Selection and Audit

1. Read the old upstream commit from `VERSION_COMMIT`.
2. Resolve the requested target commit, or the upstream default branch HEAD when
   no target was requested, and pin it by full commit SHA.
3. Fetch both commits and verify that the old commit is an ancestor of the new
   commit. Stop when the ancestry check fails.
4. Generate both a name-status inventory and the full diff for
   `phnt/include/` between the two pinned commits.
5. Record an explicit disposition for every changed upstream file and every
   diff hunk: applied, already equivalent in Veil, retained for a documented
   compatibility reason, or intentionally ignored with a documented reason.
6. A new or unclassified header, symbol family, or version macro blocks
   updating `VERSION_COMMIT`. Absence from the skill's mapping table is not
   permission to skip a change.

### Semantic Reconciliation

- Reconcile additions, modifications, deletions, renames, and cross-file moves.
  Do not apply a blanket preserve-existing-content rule.
- Retain an upstream-removed declaration only when Veil requires it for a
  documented compatibility contract.
- Apply related changes as one Veil module or dependency unit. Upstream file
  order does not define Veil declaration order.
- Treat `ntmisc.h` as a multi-domain source. Classify its changed sections by
  symbol ownership and report every section separately; do not restrict review
  to Package APIs.

### API Family Conversion

- Native system calls use Veil's `__kernel_entry NTSYSCALLAPI` form.
- Add a native `Zw*` declaration only when the corresponding entry is present
  in upstream `ntzwapi.h` or an authoritative WDK declaration.
- Win32k `NtUser*` and `NtGdi*` declarations use the applicable `W32KAPI` form
  and do not receive synthesized `ZwUser*` or `ZwGdi*` declarations.
- Ordinary native exports retain the applicable `NTSYSAPI` or other Veil export
  form and do not receive an automatic Zw pair.
- Preserve upstream ABI, parameter types, SAL annotations, and declaration
  order unless an SDK or WDK compatibility adaptation is required and
  documented.

### Version Guard Conversion

- Enumerate every `PHNT_VERSION` and `PHNT_WINDOWS_*` token present in the new
  upstream commit and provide an explicit Veil conversion before applying the
  diff.
- Use `PHNT_WINDOWS_ANCIENT` rather than the obsolete
  `PHNT_WINDOWS_OLDEST`; map it to Veil's supported minimum,
  `NTDDI_WIN2K`.
- Map `PHNT_WINDOWS_11_25H2` to `NTDDI_WIN11_DT` and
  `PHNT_WINDOWS_11_26H1` to `NTDDI_WIN11_BR`.
- Do not map `PHNT_WINDOWS_11_27H2` or a later release until `Veil.h` contains
  an authoritative constant for that release.
- Treat `PHNT_WINDOWS_NEW` as a sentinel. Do not blindly convert it to the
  newest fixed `NTDDI_*` value.

### Validation and Finalization

1. Complete each coherent Veil module or dependency unit before an intermediate
   build. Cross-file moves must not be validated as isolated half-applied
   changes.
2. Run `Veil.Test\BuildAllTargets.cmd` after all changes. The final process exit
   code must be 0.
3. Do not run a global `taskkill /f /im MSBuild.exe` as a normal pre-build
   action. Terminate only a verified stale process that blocks this repository's
   build.
4. Update `VERSION_COMMIT` to the pinned new SHA only after final validation
   succeeds.
5. Remove only cache content created by the current synchronization. In the
   standard procedure this is `.cache/systeminformer`; remove `.cache` itself
   only when the current task created it and it is empty.
6. Report `ntmisc.h` changes by classified section.

---

## Code Conventions

### File Header Template

```cpp
/*
 * PROJECT:   Veil
 * FILE:      Veil.System.<Module>.h
 * PURPOSE:   This file is part of Veil.
 *
 * LICENSE:   MIT License
 *
 * DEVELOPER: MeeSong (meesong@outlook.com)
 */

#pragma once

// Warnings which disabled for compiling
#if _MSC_VER >= 1200
#pragma warning(push)
// nonstandard extension used : nameless struct/union
#pragma warning(disable:4201)
// nonstandard extension used : bit field types other than int
#pragma warning(disable:4214)
// 'struct_name' : structure was padded due to __declspec(align())
#pragma warning(disable:4324)
// 'enumeration': a forward declaration of an unscoped enumeration must have an
// underlying type (int assumed)
#pragma warning(disable:4471)
#endif

VEIL_BEGIN()

// Content here...

VEIL_END()

#if _MSC_VER >= 1200
#pragma warning(pop)
#endif
```

### Enumeration Definition

```cpp
/**
 * Brief description of the enumeration.
 * \sa https://learn.microsoft.com/...
 */
typedef enum _ENUM_NAME
{
    EnumValue1, // ASSOCIATED_STRUCTURE_1
    EnumValue2, // ASSOCIATED_STRUCTURE_2
    MaxEnumValue
} ENUM_NAME;
```

### Structure Definition

```cpp
/**
 * Brief description of the structure.
 * \sa https://learn.microsoft.com/...
 */
typedef struct _STRUCTURE_NAME
{
    TYPE Field1;
    TYPE Field2;
    _Field_size_bytes_(Length) TYPE VariableField[1];
} STRUCTURE_NAME, *PSTRUCTURE_NAME;
```

### Macro Definition with Documentation

```cpp
// rev (for reverse-engineered)
/**
 * \def MACRO_NAME
 * \brief Brief description.
 *
 * Detailed description of the macro's purpose and usage.
 */
#define MACRO_NAME value
```

### Kernel/User Mode Conditional Compilation

```cpp
#ifndef _KERNEL_MODE
// User-mode only definitions
#endif // !_KERNEL_MODE

#ifdef _KERNEL_MODE
// Kernel-mode only definitions
#endif // _KERNEL_MODE
```

---

## Verification Checklist

Before submitting a phnt synchronization, verify the following:

- [ ] Old and new upstream commits are pinned by full SHA and ancestry is verified.
- [ ] Every changed upstream file and diff hunk has an explicit disposition.
- [ ] No new header, symbol family, or version macro remains unclassified.
- [ ] Additions, modifications, deletions, renames, and cross-file moves are reconciled.
- [ ] All `PHNT_VERSION` and `PHNT_WINDOWS_*` uses have explicit Veil conversions.
- [ ] API annotations and export macros follow the applicable native, Win32k, or ordinary export family.
- [ ] Native Nt/Zw coverage is verified against `ntzwapi.h` or authoritative WDK declarations.
- [ ] Closing parentheses are aligned with no leading spaces before `);`.
- [ ] `Veil.Test\BuildAllTargets.cmd` exits with code 0.
- [ ] Definition order respects Veil dependencies.
- [ ] Every changed `ntmisc.h` section is classified and reported separately.
- [ ] `VERSION_COMMIT` contains the validated new upstream SHA.
- [ ] Only cache content created by the current synchronization is removed.

---

## Error Handling Guidelines

### Common Issues and Solutions

| Issue | Cause | Solution |
|-------|-------|----------|
| Undefined type | Missing dependency | Check definition order; add `#include` or move definition |
| Redefinition | Duplicate in SDK/WDK | Wrap with `#ifndef _KERNEL_MODE` or version check |
| Missing SAL annotation | phnt inconsistency | Add appropriate `_In_`, `_Out_`, `_Inout_` annotations |
| Macro conflict | Name collision | Use `VEIL_` prefix or conditional compilation |

### When Encountering Errors

1. **Identify** the exact error message and location.
2. **Trace** the dependency chain.
3. **Compare** with the original phnt definition.
4. **Apply** the minimal fix that maintains compatibility.
5. **Document** any non-obvious changes with comments.

---

## References

- [phnt Repository](https://github.com/winsiderss/systeminformer/tree/master/phnt)
- [Windows SDK Documentation](https://learn.microsoft.com/en-us/windows/win32/)
- [Windows Driver Kit Documentation](https://learn.microsoft.com/en-us/windows-hardware/drivers/)
- [SAL Annotations](https://learn.microsoft.com/en-us/cpp/code-quality/understanding-sal)
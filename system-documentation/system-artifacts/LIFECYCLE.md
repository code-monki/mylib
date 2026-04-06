# MyLib — lifecycle and phase gates

This document defines **mandatory phase sequencing** and **authority** for AI-assisted and human work on this repository. **Explicit human approval** is required to advance between phases. **No implicit advancement.**

---

## 1. Authority hierarchy (this repo)

Paths are relative to the **repository root**.

1. **`system-documentation/system-artifacts/LIFECYCLE.md`** (this file)  
2. **`system-documentation/system-artifacts/`** — `concept.md`, SRS, HLA, DD, test artifacts, RTM, packaging plan (as they exist)  
3. **`.cursor/rules/cursor-rules.mdc`** — Cursor behavior  
4. **Maintainer / project owner** decisions  

If guidance conflicts, defer **upward** in this list.

---

## 2. Mandatory lifecycle sequence

The project **SHALL** follow this order (no skipping or reordering without **explicit human authorization**):

1. Ideation  
2. Requirements (SRS)  
3. High-Level Architecture (HLA)  
4. Detailed Design (DD)  
5. Traceability consolidation (RTM alignment)  
6. Test planning and definition  
7. Implementation  
8. Packaging and orchestration  
9. Documentation alignment and closure  

---

## 3. Phase gates

Each phase requires **objectives**, **deliverables**, **exit criteria**, and **explicit human authorization** before the next phase.

---

## 4. Rollback

If scope, requirements, architecture, design boundaries, packaging, tests, or traceability change materially, roll back to the **earliest impacted phase**, update the RTM when it exists, and obtain **reauthorization**.

---

## 5. Current status

- **Ideation** closed **2026-04-05**; **Requirements** phase **in progress**.  
- **SRS:** [`srs.md`](srs.md "Srs") **draft** (v0.1); **not** approved for Architecture until **§16** gate satisfied.  
- See [`_process/project-primer.md`](_process/project-primer.md "Project Primer") **§12 — Gate Declaration** for the Ideation→Requirements authorization.

---

## 6. Agent / contributor behavior

- Identify the **current lifecycle phase** before substantive implementation work.  
- **Refuse** premature implementation (e.g. before approved DD and RTM readiness per project rules).  
- **Surface** violations; silence is not compliance.  
- **Requirement IDs**, **test mapping**, and **RTM** apply once the SRS and RTM exist.

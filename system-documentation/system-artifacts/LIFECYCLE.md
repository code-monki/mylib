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

## 5. Decision and discussion logging

Significant design decisions, framework/library choices, architecture choices, packaging choices, orchestration choices, risk-bearing deferrals, and changes to deterministic-probabilistic boundaries **SHALL** be recorded in [`_process/discussion-log.md`](_process/discussion-log.md "Discussion Log") using the decision-log structure defined by [`_templates/project/decision-log.md`](_templates/project/decision-log.md "Decision Log Template").

Routine implementation details do not require full decision-log entries unless they alter architecture, DD, tests, packaging, orchestration, NFR posture, risk posture, or traceability.

---

## 6. Current status

- **Ideation** closed **2026-04-05**. **Requirements** phase **complete** for baseline **SRS v0.9** (approved **2026-04-06**).  
- **SRS:** [`srs.md`](srs.md "Srs") **Approved** (**v0.9**); **High-Level Architecture** phase **authorized** **2026-04-06** (see SRS **§16**, **§Approval**, and primer **§13**).  
- **HLA:** [`hla.md`](hla.md "Hla") **Approved** (**v0.1.2**, **2026-04-25**); **Detailed Design** phase authorized.  
- **DD:** [`dd.md`](dd.md "Dd") **draft** (**v0.1**); component decomposition, interface contracts, data design, failure semantics, NFR derivation, and test intent **pending**.  
- **RTM:** [`rtm.md`](rtm.md "Rtm") **draft** (**v0.1**); **HLA Component ID** column populated from approved HLA; **DD**, test, packaging, and orchestration columns **TBD**.  
- **Next deliverable:** complete **DD** component decomposition and continue RTM alignment. **Implementation** remains blocked until **approved DD** and RTM readiness per project rules.  
- See [`_process/project-primer.md`](_process/project-primer.md "Project Primer") **§12** (Ideation→Requirements) and **§13** (Requirements→Architecture).

---

## 7. Agent / contributor behavior

- Identify the **current lifecycle phase** before substantive implementation work.  
- **Refuse** premature implementation (e.g. before approved DD and RTM readiness per project rules).  
- **Surface** violations; silence is not compliance.  
- **Requirement IDs**, **test mapping**, and **RTM** apply once the SRS and RTM exist.
- Record significant design/framework/library decisions in [`_process/discussion-log.md`](_process/discussion-log.md "Discussion Log") before relying on them in downstream artifacts.

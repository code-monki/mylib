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
- **DD:** [`dd.md`](dd.md "Dd") **Approved** (**v0.1**, **2026-04-28**); component **§4.x** decomposition; data/API contracts **§5.1.3**, **§5.2**, **§5.3.8**–**§5.3.19**.  
- **Test Plan:** [`test-plan.md`](test-plan.md "Test Plan") **Approved** (**v0.1**, **2026-04-28**).  
- **RTM:** [`rtm.md`](rtm.md "Rtm") **Approved** (**v0.1**, **2026-04-28**); requirement→HLA→DD **§4.x** rows populated; **§2.1** points to DD **§5** contracts; test **execution evidence** and release-hardening trace entries now populated through M7 baseline.  
- **Shell UI/UX:** [`shell-ui-ux-design.md`](shell-ui-ux-design.md "Shell UI/UX Design") (**Draft**) — iterative screen/flow/wireframe record for **HLA-SHELL**; mature per document gate before shell UI coding so implementation stays specification-driven.  
- **Implementation gate decision:** **Approved and cleared** by maintainer/project owner (**2026-04-29**). Implementation phase is authorized to begin under approved DD/Test Plan/RTM artifacts.  
- **Non-blocking cleanup carryover:** Manual Omnigraffle refresh/re-export of selected diagrams is accepted as post-gate cleanup and does not block implementation start.  
- **Implementation status:** Milestones **M1-M7** completed with build-integrated tests, complexity gate, performance harness, and rollback drill evidence captured.  
- **Next deliverable:** release-candidate closure artifacts (tag/checksum/manual acceptance) and documentation alignment closeout.  
- **Deferred cleanup:** Omnigraffle-based diagram refresh remains intentionally deferred to end-of-cycle cleanup and is non-blocking for release-candidate preparation.  
- See [`_process/project-primer.md`](_process/project-primer.md "Project Primer") **§12** (Ideation→Requirements) and **§13** (Requirements→Architecture).

---

## 7. Agent / contributor behavior

- Identify the **current lifecycle phase** before substantive implementation work.  
- **Refuse** premature implementation (e.g. before approved DD and RTM readiness per project rules).  
- **Surface** violations; silence is not compliance.  
- **Requirement IDs**, **test mapping**, and **RTM** apply once the SRS and RTM exist.
- Record significant design/framework/library decisions in [`_process/discussion-log.md`](_process/discussion-log.md "Discussion Log") before relying on them in downstream artifacts.

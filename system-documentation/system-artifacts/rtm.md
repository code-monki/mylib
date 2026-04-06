<!--
File: system-documentation/system-artifacts/rtm.md

Purpose:
  Requirements traceability matrix for MyLib (SRS → HLA → DD → tests → release).

Lifecycle authority:
  LIFECYCLE.md

This artifact is populated from SRS requirement IDs. Architectural and design
columns remain TBD until HLA and DD are drafted and approved.
-->

# Requirements Traceability Matrix (RTM)

**Project Name:** MyLib  
**Version:** 0.1  
**Date (YYYY-MM-DD):** 2026-04-06  
**Maintained By:** Charles McKnight (draft; maintainers may revise)  
**Status:** Draft  
**Requirement Version Reference:** SRS v0.9 **Approved** ([`srs.md`](srs.md "Srs"); header dated 2026-04-11; approved 2026-04-06)  
**Architecture Version Reference:** HLA v0.1.1 **Draft** ([`hla.md`](hla.md "Hla"))  
**Design Version Reference:** N/A (DD not yet drafted)  
**Test Plan Version Reference:** N/A (test plan not yet drafted)  

---

# 1. RTM Authority Declaration

Confirm:

- Requirements approved? **Yes** — SRS **v0.9**, **2026-04-06**  
- Architecture approved? **No** — **[`hla.md`](hla.md "Hla")** **v0.1** **draft** exists; **pending** human approval  
- Detailed Design approved? **No**  
- Test Plan aligned? **No**  
- Advancement to **High-Level Architecture** work authorized? **Yes** — **2026-04-06** (SRS **§16** / **§Approval**; **LIFECYCLE.md** §5)  
- Advancement to **Detailed Design** or **implementation** authorized? **No** — per **LIFECYCLE.md** until **HLA** (and later **DD**) are approved  

If any answer is “No” where a phase requires a “Yes,” traceability validation is incomplete for that phase. This matrix is a **scaffold**: every SRS requirement has a row; downstream IDs are filled as HLA, DD, and tests land.

---

# 2. Purpose

The RTM SHALL ensure:

- Every requirement maps to architecture  
- Every architectural element maps to requirements  
- Every design artifact maps to architecture  
- Every implementation artifact maps to design  
- Every test case maps to requirements  
- Packaging and orchestration artifacts map to release state  
- Deterministic–probabilistic boundaries are traceable  

Traceability SHALL be bidirectional and complete.

---

# 3. Core Traceability Matrix

| Req ID | Req Type | HLA Component ID | DD Artifact | Implementation Unit | Test Case ID | Packaging Ref | Orchestration Ref | Validation Status | Evidence Ref |
|--------|----------|------------------|-------------|---------------------|--------------|---------------|-------------------|-------------------|--------------|
| FR-001 | FR | HLA-DOMAIN | TBD | TBD | TBD | TBD | TBD | Planned | TBD |
| FR-002 | FR | HLA-DOMAIN | TBD | TBD | TBD | TBD | TBD | Planned | TBD |
| FR-003 | FR | HLA-DOMAIN | TBD | TBD | TBD | TBD | TBD | Planned | TBD |
| FR-004 | FR | HLA-INGEST, HLA-SECURITY | TBD | TBD | TBD | TBD | TBD | Planned | TBD |
| FR-005 | FR | HLA-INGEST | TBD | TBD | TBD | TBD | TBD | Planned | TBD |
| FR-006 | FR | HLA-SEARCH | TBD | TBD | TBD | TBD | TBD | Planned | TBD |
| FR-007 | FR | HLA-SEARCH | TBD | TBD | TBD | TBD | TBD | Planned | TBD |
| FR-008 | FR | HLA-DOMAIN, HLA-SHELL | TBD | TBD | TBD | TBD | TBD | Planned | TBD |
| FR-009 | FR | HLA-SEARCH | TBD | TBD | TBD | TBD | TBD | Planned | TBD |
| FR-010 | FR | HLA-INGEST | TBD | TBD | TBD | TBD | TBD | Planned | TBD |
| FR-011 | FR | HLA-STORAGE, HLA-SHELL | TBD | TBD | TBD | TBD | TBD | Planned | TBD |
| FR-012 | FR | HLA-STORAGE, HLA-DOMAIN | TBD | TBD | TBD | TBD | TBD | Planned | TBD |
| FR-013 | FR | HLA-SERVER-HOST, HLA-SECURITY, HLA-CLIENT-ACCESS | TBD | TBD | TBD | TBD | TBD | Planned | TBD |
| FR-014 | FR | HLA-SHELL, HLA-SERVER-HOST | TBD | TBD | TBD | TBD | TBD | Planned | TBD |
| FR-015 | FR | HLA-SERVER-HOST | TBD | TBD | TBD | TBD | TBD | Planned | TBD |
| FR-016 | FR | HLA-SECURITY, HLA-CLIENT-ACCESS | TBD | TBD | TBD | TBD | TBD | Planned | TBD |
| FR-017 | FR | HLA-SECURITY | TBD | TBD | TBD | TBD | TBD | Planned | TBD |
| FR-018 | FR | HLA-SECURITY | TBD | TBD | TBD | TBD | TBD | Planned | TBD |
| FR-019 | FR | HLA-SHELL, HLA-STORAGE | TBD | TBD | TBD | TBD | TBD | Planned | TBD |
| FR-020 | FR | HLA-SHELL | TBD | TBD | TBD | TBD | TBD | Planned | TBD |
| FR-021 | FR | HLA-SHELL | TBD | TBD | TBD | TBD | TBD | Planned | TBD |
| FR-022 | FR | HLA-SHELL | TBD | TBD | TBD | TBD | TBD | Planned | TBD |
| FR-023 | FR | HLA-OCR | TBD | TBD | TBD | TBD | TBD | Planned | TBD |
| FR-024 | FR | HLA-SHELL | TBD | TBD | TBD | TBD | TBD | Planned | TBD |
| FR-025 | FR | HLA-SHELL | TBD | TBD | TBD | TBD | TBD | Planned | TBD |
| FR-026 | FR | HLA-AUDIT | TBD | TBD | TBD | TBD | TBD | Planned | TBD |
| FR-027 | FR | HLA-SECURITY | TBD | TBD | TBD | TBD | TBD | Planned | TBD |
| FR-028 | FR | HLA-OBSLOG | TBD | TBD | TBD | TBD | TBD | Planned | TBD |
| FR-029 | FR | HLA-OBSLOG, HLA-SHELL | TBD | TBD | TBD | TBD | TBD | Planned | TBD |
| FR-030 | FR | HLA-RELEASE | TBD | TBD | TBD | TBD | TBD | Planned | TBD |
| FR-031 | FR | HLA-SHELL, HLA-SECURITY | TBD | TBD | TBD | TBD | TBD | Planned | TBD |
| FR-032 | FR | HLA-SECURITY | TBD | TBD | TBD | TBD | TBD | Planned | TBD |
| FR-033 | FR | HLA-SECURITY | TBD | TBD | TBD | TBD | TBD | Planned | TBD |
| FR-034 | FR | HLA-SECURITY | TBD | TBD | TBD | TBD | TBD | Planned | TBD |
| FR-035 | FR | HLA-SECURITY | TBD | TBD | TBD | TBD | TBD | Planned | TBD |
| FR-036 | FR | HLA-STORAGE | TBD | TBD | TBD | TBD | TBD | Planned | TBD |
| FR-037 | FR | HLA-SHELL, HLA-DOMAIN | TBD | TBD | TBD | TBD | TBD | Planned | TBD |
| FR-038 | FR | HLA-SEARCH | TBD | TBD | TBD | TBD | TBD | Planned | TBD |
| FR-039 | FR | HLA-SEARCH, HLA-SHELL | TBD | TBD | TBD | TBD | TBD | Planned | TBD |
| FR-040 | FR | HLA-DOMAIN | TBD | TBD | TBD | TBD | TBD | Planned | TBD |
| FR-041 | FR | HLA-DOMAIN | TBD | TBD | TBD | TBD | TBD | Planned | TBD |
| NFR-001 | NFR | HLA-SEARCH, HLA-DOMAIN, HLA-SERVER-HOST | TBD | TBD | TBD | TBD | TBD | Planned | TBD |
| NFR-002 | NFR | HLA-SECURITY, HLA-SERVER-HOST | TBD | TBD | TBD | TBD | TBD | Planned | TBD |
| NFR-003 | NFR | HLA-RELEASE, HLA-SHELL | TBD | TBD | TBD | TBD | TBD | Planned | TBD |
| NFR-004 | NFR | HLA-SHELL, HLA-SERVER-HOST | TBD | TBD | TBD | TBD | TBD | Planned | TBD |
| NFR-005 | NFR | HLA-SHELL, HLA-SERVER-HOST | TBD | TBD | TBD | TBD | TBD | Planned | TBD |
| NFR-006 | NFR | HLA-SHELL | TBD | TBD | TBD | TBD | TBD | Planned | TBD |
| NFR-007 | NFR | HLA-SHELL | TBD | TBD | TBD | TBD | TBD | Planned | TBD |
| NFR-008 | NFR | HLA-OBSLOG, HLA-AUDIT | TBD | TBD | TBD | TBD | TBD | Planned | TBD |
| NFR-009 | NFR | HLA-CLIENT-ACCESS, HLA-SERVER-HOST | TBD | TBD | TBD | TBD | TBD | Planned | TBD |

**SRS requirement titles (for maintenance):** see [§4 Functional requirements](srs.md#4-functional-requirements "4. Functional Requirements") and NFR sections in [`srs.md`](srs.md "Srs"). **HLA component definitions:** [`hla.md`](hla.md "Hla") **[§6](hla.md#6-major-components "6. Major Components")**.

---

## Field Definitions

**Req ID**  
FR-XXX or NFR-XXX identifier from SRS.

**Req Type**  
FR / NFR.

**HLA Component ID**  
Approved architectural component.

**DD Artifact**  
Design-level module, interface, or artifact identifier.

**Implementation Unit**  
Code module, package, service, or deployment unit.

**Test Case ID**  
Validation case identifier.

**Packaging Ref**  
Reference to packaging plan artifact or release identifier.

**Orchestration Ref**  
Reference to build or pipeline identifier.

**Validation Status**  
Planned / Implemented / Tested / Verified / Blocked.

**Evidence Ref**  
Reference to test report, validation artifact, or audit evidence.

---

# 4. Deterministic–Probabilistic Boundary Traceability (If Applicable)

OCR and derived text quality are bounded in SRS [§6](srs.md#6-deterministicprobabilistic-requirements "6. Deterministic–Probabilistic Requirements"). Initial mapping:

| Req ID | Boundary ID | Validation Harness | Containment Logic | Fallback Ref | Observability Ref | Drift Validation | Status |
|--------|-------------|--------------------|-------------------|--------------|-------------------|------------------|--------|
| FR-023 | HLA-BOUND-OCR | TBD | Ingest/reindex invokes **HLA-OCR**; no silent success (SRS §6) | FR-009 keywords | Log fields / error codes (DD) | Test Plan OCR tolerance | Planned |

Probabilistic behavior SHALL NOT exist outside RTM coverage.

Untracked boundaries are governance violations.

---

# 5. Non-Functional Traceability

Each NFR SHALL explicitly map to architectural mechanism, design enforcement, test validation, and packaging consideration. Rows below mirror §3 for NFR IDs; expand mechanisms when HLA exists.

| NFR ID | Architectural Mechanism | Design Artifact | Test Case | Packaging Impact | Status |
|--------|-------------------------|-----------------|-----------|------------------|--------|
| NFR-001 | Catalog/index partition; optional scaled API tier (**HLA** §8) | TBD | TBD | TBD | Planned |
| NFR-002 | Server-side authorization on sensitive paths (**HLA-SECURITY**) | TBD | TBD | TBD | Planned |
| NFR-003 | **HLA-RELEASE** + in-app notices | TBD | TBD | TBD | Planned |
| NFR-004 | Operator docs surfaces; server admin for log config (**HLA** §8) | TBD | TBD | TBD | Planned |
| NFR-005 | Shell + server honest policy alignment | TBD | TBD | TBD | Planned |
| NFR-006 | Themed shell WCAG AA (**HLA-SHELL**) | TBD | TBD | TBD | Planned |
| NFR-007 | Help / manuals via **HLA-SHELL** | TBD | TBD | TBD | Planned |
| NFR-008 | **HLA-AUDIT** vs **HLA-OBSLOG**; minimization (DD) | TBD | TBD | TBD | Planned |
| NFR-009 | TLS remote; loopback exception (**HLA-CLIENT-ACCESS**, **HLA-SERVER-HOST**) | TBD | TBD | TBD | Planned |

Assumed NFR compliance is prohibited.

---

# 6. Bidirectional Verification Rules

Traceability MUST support:

Forward tracing:  
Requirement → Architecture → Design → Implementation → Test → Packaging

Backward tracing:  
Test → Implementation → Design → Architecture → Requirement

If any chain breaks, advancement is prohibited.

---

# 7. Orphan Detection

The following SHALL block progression:

- Requirement without architectural mapping  
- Architectural component without requirement  
- Design artifact without architecture parent  
- Implementation unit without design reference  
- Test case without requirement reference  
- Packaging artifact without RTM linkage  
- Orchestration artifact without RTM linkage  

No orphan artifacts permitted.

---

# 8. Change Control and Lineage

When any of the following change:

- Requirement  
- Architecture  
- Design  
- Implementation  
- Test case  
- Packaging configuration  
- Orchestration pipeline  

The RTM SHALL be updated immediately.

Each update SHALL record:

- Date  
- Change summary  
- Impacted IDs  
- Phase rollback requirement (if any)  

Untracked change invalidates lifecycle integrity.

| Date (UTC) | Summary | Impacted IDs | Rollback |
|------------|---------|--------------|----------|
| 2026-04-03 | Initial RTM v0.1: full FR-001–FR-041 and NFR-001–NFR-009 rows; downstream TBD | All | N/A |
| 2026-04-06 | SRS v0.9 **Approved**; Architecture phase authorized; §1 authority rows updated | — | N/A |
| 2026-04-06 | **HLA** v0.1 **draft**; §3 HLA Component ID column populated; §4–§5 updated | FR-001–FR-041, NFR-001–NFR-009 | N/A |
| 2026-04-06 | **HLA** v0.1.1 — SRS `srs.md#…` cross-links for GitHub; metadata only | — | N/A |

---

# 9. Coverage Validation Checklist

Before phase advancement, confirm:

- 100% FR coverage to design  
- 100% NFR coverage to architecture  
- 100% implementation traceability  
- 100% requirement-to-test coverage  
- Deterministic–probabilistic boundaries mapped (if applicable)  
- Packaging traceability complete  
- Orchestration traceability complete  
- No orphan artifacts  

Failure blocks advancement.

---

# 10. Release-State Snapshot

Before release authorization:

- RTM Version incremented  
- Validation status updated to release state  
- Evidence references finalized  
- Packaging reference aligned to artifact  
- Orchestration reference aligned to build  
- Documentation version aligned  

Release without finalized RTM snapshot is prohibited.

---

# 11. Approval

Approved By: *— pending —*  
Role:  
Date:  
Version Incremented: No  

RTM validation required before:

- Implementation completion  
- Test phase closure  
- Packaging approval  
- Release authorization  

---

End of Requirements Traceability Matrix (draft)

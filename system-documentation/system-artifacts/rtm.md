<!--
File: system-documentation/system-artifacts/rtm.md

Purpose:
  Requirements traceability matrix for MyLib (SRS → HLA → DD → tests → release).

Lifecycle authority:
  LIFECYCLE.md

This artifact is populated from SRS requirement IDs. Architectural columns are
populated from approved HLA v0.1.2; design columns are mapped to DD v0.1
component sections (**§4.x**) and cross-cutting data/API contracts (**§5.1.3**, **§5.2**, **§5.3.8**–**§5.3.19**).
-->

# Requirements Traceability Matrix (RTM)

**Project Name:** MyLib  
**Version:** 0.1  
**Date (YYYY-MM-DD):** 2026-04-28  
**Maintained By:** Charles McKnight (maintainers may revise)  
**Status:** Approved  
**Requirement Version Reference:** SRS v0.9 **Approved** ([`srs.md`](srs.md "Srs"); header dated 2026-04-11; approved 2026-04-06)  
**Architecture Version Reference:** HLA v0.1.2 **Approved** ([`hla.md`](hla.md "Hla"); approved 2026-04-25)  
**Design Version Reference:** DD v0.1 **Approved** ([`dd.md`](dd.md "Dd"); approved 2026-04-28; data/API contracts **§5.1.3**, **§5.2**, **§5.3.8**–**§5.3.19**)  
**Test Plan Version Reference:** Test Plan v0.1 **Approved** ([`test-plan.md`](test-plan.md "Test Plan"); approved 2026-04-28)  

---

# 1. Authority

Confirm:

- Requirements approved? **Yes** — SRS **v0.9**, **2026-04-06**  
- Architecture approved? **Yes** — **[`hla.md`](hla.md "Hla")** **v0.1.2**, approved **2026-04-25**  
- Detailed Design approved? **Yes** — [`dd.md`](dd.md "Dd") v0.1 approved **2026-04-28** (component **§4.x**; contracts **§5.1.3** / **§5.2** / **§5.3.8**–**§5.3.19**)  
- Test Plan aligned? **Yes (Approved)** — [`test-plan.md`](test-plan.md "Test Plan") v0.1 approved **2026-04-28**  
- Advancement to **High-Level Architecture** work authorized? **Yes** — **2026-04-06** (SRS **§16** / **§Approval**; **LIFECYCLE.md** §5)  
- Advancement to **Detailed Design** authorized? **Yes** — HLA **v0.1.2** approved **2026-04-25**  
- Advancement to **implementation** authorized? **Yes** — maintainer/project-owner phase-gate approval recorded **2026-04-29**; Omnigraffle diagram refresh is non-blocking cleanup per **LIFECYCLE.md**  

If any answer is “No” where a phase requires a “Yes,” traceability validation is incomplete for that phase. This matrix is a **scaffold**: every SRS requirement has a row; downstream IDs are filled as HLA, DD, and tests land. **Per-row `DD` links** in §3.1 point to **component** design (**§4.x**). **HTTP/JSON, logical persistence, and service-interface contracts** are authoritative in **DD §5.1.3**, **§5.2**, and **§5.3.8**–**§5.3.19** (see **§2.1**).

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

## 2.1 DD §5 data and API contract layer (cross-cutting)

The §3.1 **DD** column lists **HLA-faithful component sections** (**DD §4.1**–**§4.12**). Cross-cutting **data design and v1 API contracts** (durable identity/RBAC model, message envelope, route index, wire JSON, C++ service shapes) are defined in **DD `§5.1.3`**, **`§5.2`**, **`§5.3.1`–`§5.3.6`**, **`§5.3.7`**, **`§5.3.8`–`§5.3.18`**, and **`§5.3.19`**. Test and implementation validation SHALL use those subsections as the **contract authority** for automated contract tests, per **Test Plan §2** and **§4.3**.

---

# 3. Core Traceability Matrix

> Core matrix converted to hybrid view for width-constrained reading.

### 3.1 Matrix

| Req | Type | HLA | DD | Status |
| :---: | :---: | :---: | :---: | :---: |
| <nobr>[FR-001](./srs.md#fr-001--catalog-records "FR-001")</nobr> | FR | <nobr>[HLA-DOMAIN](./hla.md#6-major-components "HLA-DOMAIN")</nobr> | <nobr>[DD §4.4](./dd.md#44-hla-domain "DD §4.4")</nobr> | <nobr>Planned</nobr> |
| <nobr>[FR-002](./srs.md#fr-002--metadata-fields "FR-002")</nobr> | FR | <nobr>[HLA-DOMAIN](./hla.md#6-major-components "HLA-DOMAIN")</nobr> | <nobr>[DD §4.4](./dd.md#44-hla-domain "DD §4.4")</nobr> | <nobr>Planned</nobr> |
| <nobr>[FR-003](./srs.md#fr-003--tags "FR-003")</nobr> | FR | <nobr>[HLA-DOMAIN](./hla.md#6-major-components "HLA-DOMAIN")</nobr> | <nobr>[DD §4.4](./dd.md#44-hla-domain "DD §4.4")</nobr> | <nobr>Planned</nobr> |
| <nobr>[FR-004](./srs.md#fr-004--deliberate-import "FR-004")</nobr> | FR | <nobr>[HLA-INGEST](./hla.md#6-major-components "HLA-INGEST")</nobr>, <nobr>[HLA-SHELL](./hla.md#6-major-components "HLA-SHELL")</nobr>, <nobr>[HLA-SECURITY](./hla.md#6-major-components "HLA-SECURITY")</nobr> | <nobr>[DD §4.1.2.1](./dd.md#dd-4121-metadata-enrichment "DD §4.1.2.1")</nobr>, <nobr>[DD §4.5](./dd.md#45-hla-ingest "DD §4.5")</nobr>, <nobr>[DD §4.8](./dd.md#48-hla-security "DD §4.8")</nobr> | <nobr>Planned</nobr> |
| <nobr>[FR-005](./srs.md#fr-005--supported-document-types-v1 "FR-005")</nobr> | FR | <nobr>[HLA-INGEST](./hla.md#6-major-components "HLA-INGEST")</nobr> | <nobr>[DD §4.5](./dd.md#45-hla-ingest "DD §4.5")</nobr> | <nobr>Planned</nobr> |
| <nobr>[FR-006](./srs.md#fr-006--full-text-indexing-when-permitted "FR-006")</nobr> | FR | <nobr>[HLA-SEARCH](./hla.md#6-major-components "HLA-SEARCH")</nobr> | <nobr>[DD §4.6](./dd.md#46-hla-search "DD §4.6")</nobr> | <nobr>Planned</nobr> |
| <nobr>[FR-007](./srs.md#fr-007--full-text-search "FR-007")</nobr> | FR | <nobr>[HLA-SEARCH](./hla.md#6-major-components "HLA-SEARCH")</nobr> | <nobr>[DD §4.6](./dd.md#46-hla-search "DD §4.6")</nobr> | <nobr>Planned</nobr> |
| <nobr>[FR-008](./srs.md#fr-008--tag-filtering "FR-008")</nobr> | FR | <nobr>[HLA-DOMAIN](./hla.md#6-major-components "HLA-DOMAIN")</nobr>, <nobr>[HLA-SHELL](./hla.md#6-major-components "HLA-SHELL")</nobr> | <nobr>[DD §4.1](./dd.md#41-hla-shell "DD §4.1")</nobr>, <nobr>[DD §4.4](./dd.md#44-hla-domain "DD §4.4")</nobr> | <nobr>Planned</nobr> |
| <nobr>[FR-009](./srs.md#fr-009--keywords-when-indexing-blocked "FR-009")</nobr> | FR | <nobr>[HLA-SEARCH](./hla.md#6-major-components "HLA-SEARCH")</nobr> | <nobr>[DD §4.6](./dd.md#46-hla-search "DD §4.6")</nobr> | <nobr>Planned</nobr> |
| <nobr>[FR-010](./srs.md#fr-010--duplicate-detection-digest "FR-010")</nobr> | FR | <nobr>[HLA-INGEST](./hla.md#6-major-components "HLA-INGEST")</nobr> | <nobr>[DD §4.5](./dd.md#45-hla-ingest "DD §4.5")</nobr> | <nobr>Planned</nobr> |
| <nobr>[FR-011](./srs.md#fr-011--missing-file-detection-and-relink "FR-011")</nobr> | FR | <nobr>[HLA-STORAGE](./hla.md#6-major-components "HLA-STORAGE")</nobr>, <nobr>[HLA-SHELL](./hla.md#6-major-components "HLA-SHELL")</nobr> | <nobr>[DD §4.1](./dd.md#41-hla-shell "DD §4.1")</nobr>, <nobr>[DD §4.7](./dd.md#47-hla-storage "DD §4.7")</nobr> | <nobr>Planned</nobr> |
| <nobr>[FR-012](./srs.md#fr-012--remove-from-catalog-vs-delete-on-disk "FR-012")</nobr> | FR | <nobr>[HLA-STORAGE](./hla.md#6-major-components "HLA-STORAGE")</nobr>, <nobr>[HLA-DOMAIN](./hla.md#6-major-components "HLA-DOMAIN")</nobr> | <nobr>[DD §4.4](./dd.md#44-hla-domain "DD §4.4")</nobr>, <nobr>[DD §4.7](./dd.md#47-hla-storage "DD §4.7")</nobr> | <nobr>Planned</nobr> |
| <nobr>[FR-013](./srs.md#fr-013--server-authority-for-security "FR-013")</nobr> | FR | <nobr>[HLA-SERVER-HOST](./hla.md#6-major-components "HLA-SERVER-HOST")</nobr>, <nobr>[HLA-SECURITY](./hla.md#6-major-components "HLA-SECURITY")</nobr>, <nobr>[HLA-CLIENT-ACCESS](./hla.md#6-major-components "HLA-CLIENT-ACCESS")</nobr> | <nobr>[DD §4.2](./dd.md#42-hla-client-access "DD §4.2")</nobr>, <nobr>[DD §4.3](./dd.md#43-hla-server-host "DD §4.3")</nobr>, <nobr>[DD §4.8](./dd.md#48-hla-security "DD §4.8")</nobr> | <nobr>Planned</nobr> |
| <nobr>[FR-014](./srs.md#fr-014--solo-co-located-deployment "FR-014")</nobr> | FR | <nobr>[HLA-SHELL](./hla.md#6-major-components "HLA-SHELL")</nobr>, <nobr>[HLA-SERVER-HOST](./hla.md#6-major-components "HLA-SERVER-HOST")</nobr> | <nobr>[DD §4.1](./dd.md#41-hla-shell "DD §4.1")</nobr>, <nobr>[DD §4.3](./dd.md#43-hla-server-host "DD §4.3")</nobr> | <nobr>Planned</nobr> |
| <nobr>[FR-015](./srs.md#fr-015--multi-user-server-deployment "FR-015")</nobr> | FR | <nobr>[HLA-SERVER-HOST](./hla.md#6-major-components "HLA-SERVER-HOST")</nobr> | <nobr>[DD §4.3](./dd.md#43-hla-server-host "DD §4.3")</nobr> | <nobr>Planned</nobr> |
| <nobr>[FR-016](./srs.md#fr-016--authentication-v1 "FR-016")</nobr> | FR | <nobr>[HLA-SECURITY](./hla.md#6-major-components "HLA-SECURITY")</nobr>, <nobr>[HLA-CLIENT-ACCESS](./hla.md#6-major-components "HLA-CLIENT-ACCESS")</nobr> | <nobr>[DD §4.2](./dd.md#42-hla-client-access "DD §4.2")</nobr>, <nobr>[DD §4.8](./dd.md#48-hla-security "DD §4.8")</nobr> | <nobr>Planned</nobr> |
| <nobr>[FR-017](./srs.md#fr-017--role-based-access-control "FR-017")</nobr> | FR | <nobr>[HLA-SECURITY](./hla.md#6-major-components "HLA-SECURITY")</nobr> | <nobr>[DD §4.8](./dd.md#48-hla-security "DD §4.8")</nobr> | <nobr>Planned</nobr> |
| <nobr>[FR-018](./srs.md#fr-018--tenant-boundary "FR-018")</nobr> | FR | <nobr>[HLA-SECURITY](./hla.md#6-major-components "HLA-SECURITY")</nobr> | <nobr>[DD §4.8](./dd.md#48-hla-security "DD §4.8")</nobr> | <nobr>Planned</nobr> |
| <nobr>[FR-019](./srs.md#fr-019--open-in-native-reader "FR-019")</nobr> | FR | <nobr>[HLA-SHELL](./hla.md#6-major-components "HLA-SHELL")</nobr>, <nobr>[HLA-STORAGE](./hla.md#6-major-components "HLA-STORAGE")</nobr> | <nobr>[DD §4.1](./dd.md#41-hla-shell "DD §4.1")</nobr>, <nobr>[DD §4.7](./dd.md#47-hla-storage "DD §4.7")</nobr> | <nobr>Planned</nobr> |
| <nobr>[FR-020](./srs.md#fr-020--settings-client-preferences "FR-020")</nobr> | FR | <nobr>[HLA-SHELL](./hla.md#6-major-components "HLA-SHELL")</nobr> | <nobr>[DD §4.1](./dd.md#41-hla-shell "DD §4.1")</nobr> | <nobr>Planned</nobr> |
| <nobr>[FR-021](./srs.md#fr-021--preferred-reader-per-document-type "FR-021")</nobr> | FR | <nobr>[HLA-SHELL](./hla.md#6-major-components "HLA-SHELL")</nobr> | <nobr>[DD §4.1](./dd.md#41-hla-shell "DD §4.1")</nobr> | <nobr>Planned</nobr> |
| <nobr>[FR-022](./srs.md#fr-022--application-theme "FR-022")</nobr> | FR | <nobr>[HLA-SHELL](./hla.md#6-major-components "HLA-SHELL")</nobr> | <nobr>[DD §4.1](./dd.md#41-hla-shell "DD §4.1")</nobr> | <nobr>Planned</nobr> |
| <nobr>[FR-023](./srs.md#fr-023--ocr-for-searchability "FR-023")</nobr> | FR | <nobr>[HLA-OCR](./hla.md#6-major-components "HLA-OCR")</nobr> | <nobr>[DD §4.9](./dd.md#49-hla-ocr--hla-bound-ocr "DD §4.9")</nobr> | <nobr>Planned</nobr> |
| <nobr>[FR-024](./srs.md#fr-024--shell-accessibility "FR-024")</nobr> | FR | <nobr>[HLA-SHELL](./hla.md#6-major-components "HLA-SHELL")</nobr> | <nobr>[DD §4.1](./dd.md#41-hla-shell "DD §4.1")</nobr> | <nobr>Planned</nobr> |
| <nobr>[FR-025](./srs.md#fr-025--english-ui-v1 "FR-025")</nobr> | FR | <nobr>[HLA-SHELL](./hla.md#6-major-components "HLA-SHELL")</nobr> | <nobr>[DD §4.1](./dd.md#41-hla-shell "DD §4.1")</nobr> | <nobr>Planned</nobr> |
| <nobr>[FR-026](./srs.md#fr-026--audit-logging "FR-026")</nobr> | FR | <nobr>[HLA-AUDIT](./hla.md#6-major-components "HLA-AUDIT")</nobr> | <nobr>[DD §4.10](./dd.md#410-hla-audit "DD §4.10")</nobr> | <nobr>Planned</nobr> |
| <nobr>[FR-027](./srs.md#fr-027--password-storage "FR-027")</nobr> | FR | <nobr>[HLA-SECURITY](./hla.md#6-major-components "HLA-SECURITY")</nobr> | <nobr>[DD §4.8](./dd.md#48-hla-security "DD §4.8")</nobr> | <nobr>Planned</nobr> |
| <nobr>[FR-028](./srs.md#fr-028--configurable-log-retention "FR-028")</nobr> | FR | <nobr>[HLA-OBSLOG](./hla.md#6-major-components "HLA-OBSLOG")</nobr> | <nobr>[DD §4.11](./dd.md#411-hla-obslog "DD §4.11")</nobr> | <nobr>Planned</nobr> |
| <nobr>[FR-029](./srs.md#fr-029--operational-and-diagnostic-logging-client-and-server "FR-029")</nobr> | FR | <nobr>[HLA-OBSLOG](./hla.md#6-major-components "HLA-OBSLOG")</nobr>, <nobr>[HLA-SHELL](./hla.md#6-major-components "HLA-SHELL")</nobr> | <nobr>[DD §4.1](./dd.md#41-hla-shell "DD §4.1")</nobr>, <nobr>[DD §4.11](./dd.md#411-hla-obslog "DD §4.11")</nobr> | <nobr>Planned</nobr> |
| <nobr>[FR-030](./srs.md#fr-030--release-information "FR-030")</nobr> | FR | <nobr>[HLA-RELEASE](./hla.md#6-major-components "HLA-RELEASE")</nobr> | <nobr>[DD §4.12](./dd.md#412-hla-release "DD §4.12")</nobr> | <nobr>Planned</nobr> |
| <nobr>[FR-031](./srs.md#fr-031--user-account-and-role-administration "FR-031")</nobr> | FR | <nobr>[HLA-SHELL](./hla.md#6-major-components "HLA-SHELL")</nobr>, <nobr>[HLA-SECURITY](./hla.md#6-major-components "HLA-SECURITY")</nobr> | <nobr>[DD §4.1](./dd.md#41-hla-shell "DD §4.1")</nobr>, <nobr>[DD §4.8](./dd.md#48-hla-security "DD §4.8")</nobr> | <nobr>Planned</nobr> |
| <nobr>[FR-032](./srs.md#fr-032--initial-administrator-bootstrap "FR-032")</nobr> | FR | <nobr>[HLA-SECURITY](./hla.md#6-major-components "HLA-SECURITY")</nobr> | <nobr>[DD §4.8](./dd.md#48-hla-security "DD §4.8")</nobr> | <nobr>Planned</nobr> |
| <nobr>[FR-033](./srs.md#fr-033--password-change-and-administrative-reset "FR-033")</nobr> | FR | <nobr>[HLA-SECURITY](./hla.md#6-major-components "HLA-SECURITY")</nobr> | <nobr>[DD §4.8](./dd.md#48-hla-security "DD §4.8")</nobr> | <nobr>Planned</nobr> |
| <nobr>[FR-034](./srs.md#fr-034--authentication-throttling "FR-034")</nobr> | FR | <nobr>[HLA-SECURITY](./hla.md#6-major-components "HLA-SECURITY")</nobr> | <nobr>[DD §4.8](./dd.md#48-hla-security "DD §4.8")</nobr> | <nobr>Planned</nobr> |
| <nobr>[FR-035](./srs.md#fr-035--session-management "FR-035")</nobr> | FR | <nobr>[HLA-SECURITY](./hla.md#6-major-components "HLA-SECURITY")</nobr> | <nobr>[DD §4.8](./dd.md#48-hla-security "DD §4.8")</nobr> | <nobr>Planned</nobr> |
| <nobr>[FR-036](./srs.md#fr-036--library-corpus-and-storage-model "FR-036")</nobr> | FR | <nobr>[HLA-STORAGE](./hla.md#6-major-components "HLA-STORAGE")</nobr> | <nobr>[DD §4.7](./dd.md#47-hla-storage "DD §4.7")</nobr> | <nobr>Planned</nobr> |
| <nobr>[FR-037](./srs.md#fr-037--catalog-browse-sort-and-pagination "FR-037")</nobr> | FR | <nobr>[HLA-SHELL](./hla.md#6-major-components "HLA-SHELL")</nobr>, <nobr>[HLA-DOMAIN](./hla.md#6-major-components "HLA-DOMAIN")</nobr> | <nobr>[DD §4.1](./dd.md#41-hla-shell "DD §4.1")</nobr>, <nobr>[DD §4.4](./dd.md#44-hla-domain "DD §4.4")</nobr> | <nobr>Planned</nobr> |
| <nobr>[FR-038](./srs.md#fr-038--search-query-semantics-and-results "FR-038")</nobr> | FR | <nobr>[HLA-SEARCH](./hla.md#6-major-components "HLA-SEARCH")</nobr> | <nobr>[DD §4.6](./dd.md#46-hla-search "DD §4.6")</nobr> | <nobr>Planned</nobr> |
| <nobr>[FR-039](./srs.md#fr-039--full-text-index-administration "FR-039")</nobr> | FR | <nobr>[HLA-SEARCH](./hla.md#6-major-components "HLA-SEARCH")</nobr>, <nobr>[HLA-SHELL](./hla.md#6-major-components "HLA-SHELL")</nobr> | <nobr>[DD §4.1](./dd.md#41-hla-shell "DD §4.1")</nobr>, <nobr>[DD §4.6](./dd.md#46-hla-search "DD §4.6")</nobr> | <nobr>Planned</nobr> |
| <nobr>[FR-040](./srs.md#fr-040--metadata-validation "FR-040")</nobr> | FR | <nobr>[HLA-DOMAIN](./hla.md#6-major-components "HLA-DOMAIN")</nobr> | <nobr>[DD §4.4](./dd.md#44-hla-domain "DD §4.4")</nobr> | <nobr>Planned</nobr> |
| <nobr>[FR-041](./srs.md#fr-041--concurrent-metadata-updates "FR-041")</nobr> | FR | <nobr>[HLA-DOMAIN](./hla.md#6-major-components "HLA-DOMAIN")</nobr> | <nobr>[DD §4.4](./dd.md#44-hla-domain "DD §4.4")</nobr> | <nobr>Planned</nobr> |
| <nobr>[NFR-001](./srs.md#nfr-001--corpus-scale-qualitative "NFR-001")</nobr> | NFR | <nobr>[HLA-SEARCH](./hla.md#6-major-components "HLA-SEARCH")</nobr>, <nobr>[HLA-DOMAIN](./hla.md#6-major-components "HLA-DOMAIN")</nobr>, <nobr>[HLA-SERVER-HOST](./hla.md#6-major-components "HLA-SERVER-HOST")</nobr> | <nobr>[DD §4.3](./dd.md#43-hla-server-host "DD §4.3")</nobr>, <nobr>[DD §4.4](./dd.md#44-hla-domain "DD §4.4")</nobr>, <nobr>[DD §4.6](./dd.md#46-hla-search "DD §4.6")</nobr> | <nobr>Planned</nobr> |
| <nobr>[NFR-002](./srs.md#nfr-002--server-side-enforcement "NFR-002")</nobr> | NFR | <nobr>[HLA-SECURITY](./hla.md#6-major-components "HLA-SECURITY")</nobr>, <nobr>[HLA-SERVER-HOST](./hla.md#6-major-components "HLA-SERVER-HOST")</nobr> | <nobr>[DD §4.3](./dd.md#43-hla-server-host "DD §4.3")</nobr>, <nobr>[DD §4.8](./dd.md#48-hla-security "DD §4.8")</nobr> | <nobr>Planned</nobr> |
| <nobr>[NFR-003](./srs.md#nfr-003--licensing-and-notices "NFR-003")</nobr> | NFR | <nobr>[HLA-RELEASE](./hla.md#6-major-components "HLA-RELEASE")</nobr>, <nobr>[HLA-SHELL](./hla.md#6-major-components "HLA-SHELL")</nobr> | <nobr>[DD §4.1](./dd.md#41-hla-shell "DD §4.1")</nobr>, <nobr>[DD §4.12](./dd.md#412-hla-release "DD §4.12")</nobr> | <nobr>Planned</nobr> |
| <nobr>[NFR-004](./srs.md#nfr-004--operator-documentation "NFR-004")</nobr> | NFR | <nobr>[HLA-SHELL](./hla.md#6-major-components "HLA-SHELL")</nobr>, <nobr>[HLA-SERVER-HOST](./hla.md#6-major-components "HLA-SERVER-HOST")</nobr> | <nobr>[DD §4.1](./dd.md#41-hla-shell "DD §4.1")</nobr>, <nobr>[DD §4.3](./dd.md#43-hla-server-host "DD §4.3")</nobr> | <nobr>Planned</nobr> |
| <nobr>[NFR-005](./srs.md#nfr-005--honest-policy-communication "NFR-005")</nobr> | NFR | <nobr>[HLA-SHELL](./hla.md#6-major-components "HLA-SHELL")</nobr>, <nobr>[HLA-SERVER-HOST](./hla.md#6-major-components "HLA-SERVER-HOST")</nobr> | <nobr>[DD §4.1](./dd.md#41-hla-shell "DD §4.1")</nobr>, <nobr>[DD §4.3](./dd.md#43-hla-server-host "DD §4.3")</nobr> | <nobr>Planned</nobr> |
| <nobr>[NFR-006](./srs.md#nfr-006--themed-shell-contrast "NFR-006")</nobr> | NFR | <nobr>[HLA-SHELL](./hla.md#6-major-components "HLA-SHELL")</nobr> | <nobr>[DD §4.1](./dd.md#41-hla-shell "DD §4.1")</nobr> | <nobr>Planned</nobr> |
| <nobr>[NFR-007](./srs.md#nfr-007--end-user-documentation-and-help "NFR-007")</nobr> | NFR | <nobr>[HLA-SHELL](./hla.md#6-major-components "HLA-SHELL")</nobr> | <nobr>[DD §4.1](./dd.md#41-hla-shell "DD §4.1")</nobr> | <nobr>Planned</nobr> |
| <nobr>[NFR-008](./srs.md#nfr-008--logging-privacy-and-jurisdictional-readiness "NFR-008")</nobr> | NFR | <nobr>[HLA-OBSLOG](./hla.md#6-major-components "HLA-OBSLOG")</nobr>, <nobr>[HLA-AUDIT](./hla.md#6-major-components "HLA-AUDIT")</nobr>, <nobr>[HLA-SERVER-HOST](./hla.md#6-major-components "HLA-SERVER-HOST")</nobr>, <nobr>[HLA-SECURITY](./hla.md#6-major-components "HLA-SECURITY")</nobr> | <nobr>[DD §4.3](./dd.md#43-hla-server-host "DD §4.3")</nobr>, <nobr>[DD §4.8](./dd.md#48-hla-security "DD §4.8")</nobr>, <nobr>[DD §4.10](./dd.md#410-hla-audit "DD §4.10")</nobr>, <nobr>[DD §4.11](./dd.md#411-hla-obslog "DD §4.11")</nobr> | <nobr>Planned</nobr> |
| <nobr>[NFR-009](./srs.md#nfr-009--transport-security-remote-access "NFR-009")</nobr> | NFR | <nobr>[HLA-CLIENT-ACCESS](./hla.md#6-major-components "HLA-CLIENT-ACCESS")</nobr>, <nobr>[HLA-SERVER-HOST](./hla.md#6-major-components "HLA-SERVER-HOST")</nobr> | <nobr>[DD §4.2](./dd.md#42-hla-client-access "DD §4.2")</nobr>, <nobr>[DD §4.3](./dd.md#43-hla-server-host "DD §4.3")</nobr> | <nobr>Planned</nobr> |

### 3.2 Requirements

Detailed traceability is provided as collapsible cards to improve readability in narrow panes.

<details>
  <summary><nobr>[FR-001](./srs.md#fr-001--catalog-records "FR-001")</nobr> — <nobr>Planned</nobr></summary>

<table>
  <tbody>
    <tr>
      <td align="left"><strong>Type</strong></td>
      <td align="left">FR</td>
      <td align="left"><strong>HLA ID(s)</strong></td>
      <td align="left"><nobr>[HLA-DOMAIN](./hla.md#6-major-components "HLA-DOMAIN")</nobr></td>
    </tr>
    <tr>
      <td align="left"><strong>DD Ref(s)</strong></td>
      <td align="left"><nobr>[DD §4.4](./dd.md#44-hla-domain "DD §4.4")</nobr></td>
      <td align="left"><strong>Validation Status</strong></td>
      <td align="left"><nobr>Planned</nobr></td>
    </tr>
    <tr>
      <td align="left"><strong>Implementation Unit</strong></td>
      <td align="left"><nobr>TBD</nobr></td>
      <td align="left"><strong>Test Case ID</strong></td>
      <td align="left"><nobr>TBD</nobr></td>
    </tr>
    <tr>
      <td align="left"><strong>Packaging Ref</strong></td>
      <td align="left"><nobr>TBD</nobr></td>
      <td align="left"><strong>Orchestration Ref</strong></td>
      <td align="left"><nobr>TBD</nobr></td>
    </tr>
    <tr>
      <td align="left"><strong>Evidence</strong></td>
      <td align="left" colspan="3">Initial domain decomposition in progress</td>
    </tr>
  </tbody>
</table>

</details>

<details>
  <summary><nobr>[FR-002](./srs.md#fr-002--metadata-fields "FR-002")</nobr> — <nobr>Planned</nobr></summary>

<table>
  <tbody>
    <tr>
      <td align="left"><strong>Type</strong></td>
      <td align="left">FR</td>
      <td align="left"><strong>HLA ID(s)</strong></td>
      <td align="left"><nobr>[HLA-DOMAIN](./hla.md#6-major-components "HLA-DOMAIN")</nobr></td>
    </tr>
    <tr>
      <td align="left"><strong>DD Ref(s)</strong></td>
      <td align="left"><nobr>[DD §4.4](./dd.md#44-hla-domain "DD §4.4")</nobr></td>
      <td align="left"><strong>Validation Status</strong></td>
      <td align="left"><nobr>Planned</nobr></td>
    </tr>
    <tr>
      <td align="left"><strong>Implementation Unit</strong></td>
      <td align="left"><nobr>TBD</nobr></td>
      <td align="left"><strong>Test Case ID</strong></td>
      <td align="left"><nobr>TBD</nobr></td>
    </tr>
    <tr>
      <td align="left"><strong>Packaging Ref</strong></td>
      <td align="left"><nobr>TBD</nobr></td>
      <td align="left"><strong>Orchestration Ref</strong></td>
      <td align="left"><nobr>TBD</nobr></td>
    </tr>
    <tr>
      <td align="left"><strong>Evidence</strong></td>
      <td align="left" colspan="3">Initial domain decomposition in progress</td>
    </tr>
  </tbody>
</table>

</details>

<details>
  <summary><nobr>[FR-003](./srs.md#fr-003--tags "FR-003")</nobr> — <nobr>Planned</nobr></summary>

<table>
  <tbody>
    <tr>
      <td align="left"><strong>Type</strong></td>
      <td align="left">FR</td>
      <td align="left"><strong>HLA ID(s)</strong></td>
      <td align="left"><nobr>[HLA-DOMAIN](./hla.md#6-major-components "HLA-DOMAIN")</nobr></td>
    </tr>
    <tr>
      <td align="left"><strong>DD Ref(s)</strong></td>
      <td align="left"><nobr>[DD §4.4](./dd.md#44-hla-domain "DD §4.4")</nobr></td>
      <td align="left"><strong>Validation Status</strong></td>
      <td align="left"><nobr>Planned</nobr></td>
    </tr>
    <tr>
      <td align="left"><strong>Implementation Unit</strong></td>
      <td align="left"><nobr>TBD</nobr></td>
      <td align="left"><strong>Test Case ID</strong></td>
      <td align="left"><nobr>TBD</nobr></td>
    </tr>
    <tr>
      <td align="left"><strong>Packaging Ref</strong></td>
      <td align="left"><nobr>TBD</nobr></td>
      <td align="left"><strong>Orchestration Ref</strong></td>
      <td align="left"><nobr>TBD</nobr></td>
    </tr>
    <tr>
      <td align="left"><strong>Evidence</strong></td>
      <td align="left" colspan="3">Initial domain decomposition in progress</td>
    </tr>
  </tbody>
</table>

</details>

<details>
  <summary><nobr>[FR-004](./srs.md#fr-004--deliberate-import "FR-004")</nobr> — <nobr>Planned</nobr></summary>

<table>
  <tbody>
    <tr>
      <td align="left"><strong>Type</strong></td>
      <td align="left">FR</td>
      <td align="left"><strong>HLA ID(s)</strong></td>
      <td align="left"><nobr>[HLA-INGEST](./hla.md#6-major-components "HLA-INGEST")</nobr>, <nobr>[HLA-SHELL](./hla.md#6-major-components "HLA-SHELL")</nobr>, <nobr>[HLA-SECURITY](./hla.md#6-major-components "HLA-SECURITY")</nobr></td>
    </tr>
    <tr>
      <td align="left"><strong>DD Ref(s)</strong></td>
      <td align="left"><nobr>[DD §4.1.2.1](./dd.md#dd-4121-metadata-enrichment "DD §4.1.2.1")</nobr>, <nobr>[DD §4.5](./dd.md#45-hla-ingest "DD §4.5")</nobr>, <nobr>[DD §4.8](./dd.md#48-hla-security "DD §4.8")</nobr></td>
      <td align="left"><strong>Validation Status</strong></td>
      <td align="left"><nobr>Planned</nobr></td>
    </tr>
    <tr>
      <td align="left"><strong>Implementation Unit</strong></td>
      <td align="left"><nobr>TBD</nobr></td>
      <td align="left"><strong>Test Case ID</strong></td>
      <td align="left"><nobr>TP-INGEST-001, TP-INGEST-004</nobr></td>
    </tr>
    <tr>
      <td align="left"><strong>Packaging Ref</strong></td>
      <td align="left"><nobr>TBD</nobr></td>
      <td align="left"><strong>Orchestration Ref</strong></td>
      <td align="left"><nobr>TBD</nobr></td>
    </tr>
    <tr>
      <td align="left"><strong>Evidence</strong></td>
      <td align="left" colspan="3">Ingest and security decomposition in progress; import dialog metadata assist per <nobr>[DD §4.1.2.1](./dd.md#dd-4121-metadata-enrichment "DD §4.1.2.1")</nobr> (see <nobr>[`shell-ui-ux-design.md`](shell-ui-ux-design.md "Shell UI/UX Design")</nobr> <strong>S-06</strong>)</td>
    </tr>
  </tbody>
</table>

</details>

<details>
  <summary><nobr>[FR-005](./srs.md#fr-005--supported-document-types-v1 "FR-005")</nobr> — <nobr>Planned</nobr></summary>

<table>
  <tbody>
    <tr>
      <td align="left"><strong>Type</strong></td>
      <td align="left">FR</td>
      <td align="left"><strong>HLA ID(s)</strong></td>
      <td align="left"><nobr>[HLA-INGEST](./hla.md#6-major-components "HLA-INGEST")</nobr></td>
    </tr>
    <tr>
      <td align="left"><strong>DD Ref(s)</strong></td>
      <td align="left"><nobr>[DD §4.5](./dd.md#45-hla-ingest "DD §4.5")</nobr></td>
      <td align="left"><strong>Validation Status</strong></td>
      <td align="left"><nobr>Planned</nobr></td>
    </tr>
    <tr>
      <td align="left"><strong>Implementation Unit</strong></td>
      <td align="left"><nobr>TBD</nobr></td>
      <td align="left"><strong>Test Case ID</strong></td>
      <td align="left"><nobr>TBD</nobr></td>
    </tr>
    <tr>
      <td align="left"><strong>Packaging Ref</strong></td>
      <td align="left"><nobr>TBD</nobr></td>
      <td align="left"><strong>Orchestration Ref</strong></td>
      <td align="left"><nobr>TBD</nobr></td>
    </tr>
    <tr>
      <td align="left"><strong>Evidence</strong></td>
      <td align="left" colspan="3">Initial ingest decomposition in progress</td>
    </tr>
  </tbody>
</table>

</details>

<details>
  <summary><nobr>[FR-006](./srs.md#fr-006--full-text-indexing-when-permitted "FR-006")</nobr> — <nobr>Planned</nobr></summary>

<table>
  <tbody>
    <tr>
      <td align="left"><strong>Type</strong></td>
      <td align="left">FR</td>
      <td align="left"><strong>HLA ID(s)</strong></td>
      <td align="left"><nobr>[HLA-SEARCH](./hla.md#6-major-components "HLA-SEARCH")</nobr></td>
    </tr>
    <tr>
      <td align="left"><strong>DD Ref(s)</strong></td>
      <td align="left"><nobr>[DD §4.6](./dd.md#46-hla-search "DD §4.6")</nobr></td>
      <td align="left"><strong>Validation Status</strong></td>
      <td align="left"><nobr>Planned</nobr></td>
    </tr>
    <tr>
      <td align="left"><strong>Implementation Unit</strong></td>
      <td align="left"><nobr>TBD</nobr></td>
      <td align="left"><strong>Test Case ID</strong></td>
      <td align="left"><nobr>TBD</nobr></td>
    </tr>
    <tr>
      <td align="left"><strong>Packaging Ref</strong></td>
      <td align="left"><nobr>TBD</nobr></td>
      <td align="left"><strong>Orchestration Ref</strong></td>
      <td align="left"><nobr>TBD</nobr></td>
    </tr>
    <tr>
      <td align="left"><strong>Evidence</strong></td>
      <td align="left" colspan="3">Initial search decomposition in progress</td>
    </tr>
  </tbody>
</table>

</details>

<details>
  <summary><nobr>[FR-007](./srs.md#fr-007--full-text-search "FR-007")</nobr> — <nobr>Planned</nobr></summary>

<table>
  <tbody>
    <tr>
      <td align="left"><strong>Type</strong></td>
      <td align="left">FR</td>
      <td align="left"><strong>HLA ID(s)</strong></td>
      <td align="left"><nobr>[HLA-SEARCH](./hla.md#6-major-components "HLA-SEARCH")</nobr></td>
    </tr>
    <tr>
      <td align="left"><strong>DD Ref(s)</strong></td>
      <td align="left"><nobr>[DD §4.6](./dd.md#46-hla-search "DD §4.6")</nobr></td>
      <td align="left"><strong>Validation Status</strong></td>
      <td align="left"><nobr>Planned</nobr></td>
    </tr>
    <tr>
      <td align="left"><strong>Implementation Unit</strong></td>
      <td align="left"><nobr>TBD</nobr></td>
      <td align="left"><strong>Test Case ID</strong></td>
      <td align="left"><nobr>TBD</nobr></td>
    </tr>
    <tr>
      <td align="left"><strong>Packaging Ref</strong></td>
      <td align="left"><nobr>TBD</nobr></td>
      <td align="left"><strong>Orchestration Ref</strong></td>
      <td align="left"><nobr>TBD</nobr></td>
    </tr>
    <tr>
      <td align="left"><strong>Evidence</strong></td>
      <td align="left" colspan="3">Initial search decomposition in progress</td>
    </tr>
  </tbody>
</table>

</details>

<details>
  <summary><nobr>[FR-008](./srs.md#fr-008--tag-filtering "FR-008")</nobr> — <nobr>Planned</nobr></summary>

<table>
  <tbody>
    <tr>
      <td align="left"><strong>Type</strong></td>
      <td align="left">FR</td>
      <td align="left"><strong>HLA ID(s)</strong></td>
      <td align="left"><nobr>[HLA-DOMAIN](./hla.md#6-major-components "HLA-DOMAIN")</nobr>, <nobr>[HLA-SHELL](./hla.md#6-major-components "HLA-SHELL")</nobr></td>
    </tr>
    <tr>
      <td align="left"><strong>DD Ref(s)</strong></td>
      <td align="left"><nobr>[DD §4.1](./dd.md#41-hla-shell "DD §4.1")</nobr>, <nobr>[DD §4.4](./dd.md#44-hla-domain "DD §4.4")</nobr></td>
      <td align="left"><strong>Validation Status</strong></td>
      <td align="left"><nobr>Planned</nobr></td>
    </tr>
    <tr>
      <td align="left"><strong>Implementation Unit</strong></td>
      <td align="left"><nobr>TBD</nobr></td>
      <td align="left"><strong>Test Case ID</strong></td>
      <td align="left"><nobr>TBD</nobr></td>
    </tr>
    <tr>
      <td align="left"><strong>Packaging Ref</strong></td>
      <td align="left"><nobr>TBD</nobr></td>
      <td align="left"><strong>Orchestration Ref</strong></td>
      <td align="left"><nobr>TBD</nobr></td>
    </tr>
    <tr>
      <td align="left"><strong>Evidence</strong></td>
      <td align="left" colspan="3">Shell and domain decomposition in progress</td>
    </tr>
  </tbody>
</table>

</details>

<details>
  <summary><nobr>[FR-009](./srs.md#fr-009--keywords-when-indexing-blocked "FR-009")</nobr> — <nobr>Planned</nobr></summary>

<table>
  <tbody>
    <tr>
      <td align="left"><strong>Type</strong></td>
      <td align="left">FR</td>
      <td align="left"><strong>HLA ID(s)</strong></td>
      <td align="left"><nobr>[HLA-SEARCH](./hla.md#6-major-components "HLA-SEARCH")</nobr></td>
    </tr>
    <tr>
      <td align="left"><strong>DD Ref(s)</strong></td>
      <td align="left"><nobr>[DD §4.6](./dd.md#46-hla-search "DD §4.6")</nobr></td>
      <td align="left"><strong>Validation Status</strong></td>
      <td align="left"><nobr>Planned</nobr></td>
    </tr>
    <tr>
      <td align="left"><strong>Implementation Unit</strong></td>
      <td align="left"><nobr>TBD</nobr></td>
      <td align="left"><strong>Test Case ID</strong></td>
      <td align="left"><nobr>TBD</nobr></td>
    </tr>
    <tr>
      <td align="left"><strong>Packaging Ref</strong></td>
      <td align="left"><nobr>TBD</nobr></td>
      <td align="left"><strong>Orchestration Ref</strong></td>
      <td align="left"><nobr>TBD</nobr></td>
    </tr>
    <tr>
      <td align="left"><strong>Evidence</strong></td>
      <td align="left" colspan="3">Initial search decomposition in progress</td>
    </tr>
  </tbody>
</table>

</details>

<details>
  <summary><nobr>[FR-010](./srs.md#fr-010--duplicate-detection-digest "FR-010")</nobr> — <nobr>Planned</nobr></summary>

<table>
  <tbody>
    <tr>
      <td align="left"><strong>Type</strong></td>
      <td align="left">FR</td>
      <td align="left"><strong>HLA ID(s)</strong></td>
      <td align="left"><nobr>[HLA-INGEST](./hla.md#6-major-components "HLA-INGEST")</nobr></td>
    </tr>
    <tr>
      <td align="left"><strong>DD Ref(s)</strong></td>
      <td align="left"><nobr>[DD §4.5](./dd.md#45-hla-ingest "DD §4.5")</nobr></td>
      <td align="left"><strong>Validation Status</strong></td>
      <td align="left"><nobr>Planned</nobr></td>
    </tr>
    <tr>
      <td align="left"><strong>Implementation Unit</strong></td>
      <td align="left"><nobr>TBD</nobr></td>
      <td align="left"><strong>Test Case ID</strong></td>
      <td align="left"><nobr>TBD</nobr></td>
    </tr>
    <tr>
      <td align="left"><strong>Packaging Ref</strong></td>
      <td align="left"><nobr>TBD</nobr></td>
      <td align="left"><strong>Orchestration Ref</strong></td>
      <td align="left"><nobr>TBD</nobr></td>
    </tr>
    <tr>
      <td align="left"><strong>Evidence</strong></td>
      <td align="left" colspan="3">Initial ingest decomposition in progress</td>
    </tr>
  </tbody>
</table>

</details>

<details>
  <summary><nobr>[FR-011](./srs.md#fr-011--missing-file-detection-and-relink "FR-011")</nobr> — <nobr>Planned</nobr></summary>

<table>
  <tbody>
    <tr>
      <td align="left"><strong>Type</strong></td>
      <td align="left">FR</td>
      <td align="left"><strong>HLA ID(s)</strong></td>
      <td align="left"><nobr>[HLA-STORAGE](./hla.md#6-major-components "HLA-STORAGE")</nobr>, <nobr>[HLA-SHELL](./hla.md#6-major-components "HLA-SHELL")</nobr></td>
    </tr>
    <tr>
      <td align="left"><strong>DD Ref(s)</strong></td>
      <td align="left"><nobr>[DD §4.1](./dd.md#41-hla-shell "DD §4.1")</nobr>, <nobr>[DD §4.7](./dd.md#47-hla-storage "DD §4.7")</nobr></td>
      <td align="left"><strong>Validation Status</strong></td>
      <td align="left"><nobr>Planned</nobr></td>
    </tr>
    <tr>
      <td align="left"><strong>Implementation Unit</strong></td>
      <td align="left"><nobr>TBD</nobr></td>
      <td align="left"><strong>Test Case ID</strong></td>
      <td align="left"><nobr>TBD</nobr></td>
    </tr>
    <tr>
      <td align="left"><strong>Packaging Ref</strong></td>
      <td align="left"><nobr>TBD</nobr></td>
      <td align="left"><strong>Orchestration Ref</strong></td>
      <td align="left"><nobr>TBD</nobr></td>
    </tr>
    <tr>
      <td align="left"><strong>Evidence</strong></td>
      <td align="left" colspan="3">Shell/storage decomposition in progress</td>
    </tr>
  </tbody>
</table>

</details>

<details>
  <summary><nobr>[FR-012](./srs.md#fr-012--remove-from-catalog-vs-delete-on-disk "FR-012")</nobr> — <nobr>Planned</nobr></summary>

<table>
  <tbody>
    <tr>
      <td align="left"><strong>Type</strong></td>
      <td align="left">FR</td>
      <td align="left"><strong>HLA ID(s)</strong></td>
      <td align="left"><nobr>[HLA-STORAGE](./hla.md#6-major-components "HLA-STORAGE")</nobr>, <nobr>[HLA-DOMAIN](./hla.md#6-major-components "HLA-DOMAIN")</nobr></td>
    </tr>
    <tr>
      <td align="left"><strong>DD Ref(s)</strong></td>
      <td align="left"><nobr>[DD §4.4](./dd.md#44-hla-domain "DD §4.4")</nobr>, <nobr>[DD §4.7](./dd.md#47-hla-storage "DD §4.7")</nobr></td>
      <td align="left"><strong>Validation Status</strong></td>
      <td align="left"><nobr>Planned</nobr></td>
    </tr>
    <tr>
      <td align="left"><strong>Implementation Unit</strong></td>
      <td align="left"><nobr>TBD</nobr></td>
      <td align="left"><strong>Test Case ID</strong></td>
      <td align="left"><nobr>TBD</nobr></td>
    </tr>
    <tr>
      <td align="left"><strong>Packaging Ref</strong></td>
      <td align="left"><nobr>TBD</nobr></td>
      <td align="left"><strong>Orchestration Ref</strong></td>
      <td align="left"><nobr>TBD</nobr></td>
    </tr>
    <tr>
      <td align="left"><strong>Evidence</strong></td>
      <td align="left" colspan="3">Domain/storage decomposition in progress</td>
    </tr>
  </tbody>
</table>

</details>

<details>
  <summary><nobr>[FR-013](./srs.md#fr-013--server-authority-for-security "FR-013")</nobr> — <nobr>Planned</nobr></summary>

<table>
  <tbody>
    <tr>
      <td align="left"><strong>Type</strong></td>
      <td align="left">FR</td>
      <td align="left"><strong>HLA ID(s)</strong></td>
      <td align="left"><nobr>[HLA-SERVER-HOST](./hla.md#6-major-components "HLA-SERVER-HOST")</nobr>, <nobr>[HLA-SECURITY](./hla.md#6-major-components "HLA-SECURITY")</nobr>, <nobr>[HLA-CLIENT-ACCESS](./hla.md#6-major-components "HLA-CLIENT-ACCESS")</nobr></td>
    </tr>
    <tr>
      <td align="left"><strong>DD Ref(s)</strong></td>
      <td align="left"><nobr>[DD §4.2](./dd.md#42-hla-client-access "DD §4.2")</nobr>, <nobr>[DD §4.3](./dd.md#43-hla-server-host "DD §4.3")</nobr>, <nobr>[DD §4.8](./dd.md#48-hla-security "DD §4.8")</nobr></td>
      <td align="left"><strong>Validation Status</strong></td>
      <td align="left"><nobr>Planned</nobr></td>
    </tr>
    <tr>
      <td align="left"><strong>Implementation Unit</strong></td>
      <td align="left"><nobr>TBD</nobr></td>
      <td align="left"><strong>Test Case ID</strong></td>
      <td align="left"><nobr>TBD</nobr></td>
    </tr>
    <tr>
      <td align="left"><strong>Packaging Ref</strong></td>
      <td align="left"><nobr>TBD</nobr></td>
      <td align="left"><strong>Orchestration Ref</strong></td>
      <td align="left"><nobr>TBD</nobr></td>
    </tr>
    <tr>
      <td align="left"><strong>Evidence</strong></td>
      <td align="left" colspan="3">Host/security/client-access decomposition in progress</td>
    </tr>
  </tbody>
</table>

</details>

<details>
  <summary><nobr>[FR-014](./srs.md#fr-014--solo-co-located-deployment "FR-014")</nobr> — <nobr>Planned</nobr></summary>

<table>
  <tbody>
    <tr>
      <td align="left"><strong>Type</strong></td>
      <td align="left">FR</td>
      <td align="left"><strong>HLA ID(s)</strong></td>
      <td align="left"><nobr>[HLA-SHELL](./hla.md#6-major-components "HLA-SHELL")</nobr>, <nobr>[HLA-SERVER-HOST](./hla.md#6-major-components "HLA-SERVER-HOST")</nobr></td>
    </tr>
    <tr>
      <td align="left"><strong>DD Ref(s)</strong></td>
      <td align="left"><nobr>[DD §4.1](./dd.md#41-hla-shell "DD §4.1")</nobr>, <nobr>[DD §4.3](./dd.md#43-hla-server-host "DD §4.3")</nobr></td>
      <td align="left"><strong>Validation Status</strong></td>
      <td align="left"><nobr>Planned</nobr></td>
    </tr>
    <tr>
      <td align="left"><strong>Implementation Unit</strong></td>
      <td align="left"><nobr>TBD</nobr></td>
      <td align="left"><strong>Test Case ID</strong></td>
      <td align="left"><nobr>TBD</nobr></td>
    </tr>
    <tr>
      <td align="left"><strong>Packaging Ref</strong></td>
      <td align="left"><nobr>TBD</nobr></td>
      <td align="left"><strong>Orchestration Ref</strong></td>
      <td align="left"><nobr>TBD</nobr></td>
    </tr>
    <tr>
      <td align="left"><strong>Evidence</strong></td>
      <td align="left" colspan="3">Shell/server-host decomposition in progress</td>
    </tr>
  </tbody>
</table>

</details>

<details>
  <summary><nobr>[FR-015](./srs.md#fr-015--multi-user-server-deployment "FR-015")</nobr> — <nobr>Planned</nobr></summary>

<table>
  <tbody>
    <tr>
      <td align="left"><strong>Type</strong></td>
      <td align="left">FR</td>
      <td align="left"><strong>HLA ID(s)</strong></td>
      <td align="left"><nobr>[HLA-SERVER-HOST](./hla.md#6-major-components "HLA-SERVER-HOST")</nobr></td>
    </tr>
    <tr>
      <td align="left"><strong>DD Ref(s)</strong></td>
      <td align="left"><nobr>[DD §4.3](./dd.md#43-hla-server-host "DD §4.3")</nobr></td>
      <td align="left"><strong>Validation Status</strong></td>
      <td align="left"><nobr>Planned</nobr></td>
    </tr>
    <tr>
      <td align="left"><strong>Implementation Unit</strong></td>
      <td align="left"><nobr>TBD</nobr></td>
      <td align="left"><strong>Test Case ID</strong></td>
      <td align="left"><nobr>TBD</nobr></td>
    </tr>
    <tr>
      <td align="left"><strong>Packaging Ref</strong></td>
      <td align="left"><nobr>TBD</nobr></td>
      <td align="left"><strong>Orchestration Ref</strong></td>
      <td align="left"><nobr>TBD</nobr></td>
    </tr>
    <tr>
      <td align="left"><strong>Evidence</strong></td>
      <td align="left" colspan="3">Initial server-host decomposition in progress</td>
    </tr>
  </tbody>
</table>

</details>

<details>
  <summary><nobr>[FR-016](./srs.md#fr-016--authentication-v1 "FR-016")</nobr> — <nobr>Planned</nobr></summary>

<table>
  <tbody>
    <tr>
      <td align="left"><strong>Type</strong></td>
      <td align="left">FR</td>
      <td align="left"><strong>HLA ID(s)</strong></td>
      <td align="left"><nobr>[HLA-SECURITY](./hla.md#6-major-components "HLA-SECURITY")</nobr>, <nobr>[HLA-CLIENT-ACCESS](./hla.md#6-major-components "HLA-CLIENT-ACCESS")</nobr></td>
    </tr>
    <tr>
      <td align="left"><strong>DD Ref(s)</strong></td>
      <td align="left"><nobr>[DD §4.2](./dd.md#42-hla-client-access "DD §4.2")</nobr>, <nobr>[DD §4.8](./dd.md#48-hla-security "DD §4.8")</nobr></td>
      <td align="left"><strong>Validation Status</strong></td>
      <td align="left"><nobr>Planned</nobr></td>
    </tr>
    <tr>
      <td align="left"><strong>Implementation Unit</strong></td>
      <td align="left"><nobr>TBD</nobr></td>
      <td align="left"><strong>Test Case ID</strong></td>
      <td align="left"><nobr>SEC-AUTH-001, SEC-AUTH-002, SEC-AUTH-003 (DD provisional)</nobr></td>
    </tr>
    <tr>
      <td align="left"><strong>Packaging Ref</strong></td>
      <td align="left"><nobr>TBD</nobr></td>
      <td align="left"><strong>Orchestration Ref</strong></td>
      <td align="left"><nobr>TBD</nobr></td>
    </tr>
    <tr>
      <td align="left"><strong>Evidence</strong></td>
      <td align="left" colspan="3">Security/client-access decomposition in progress; provisional test-ID mapping tracked in §10</td>
    </tr>
  </tbody>
</table>

</details>

<details>
  <summary><nobr>[FR-017](./srs.md#fr-017--role-based-access-control "FR-017")</nobr> — <nobr>Planned</nobr></summary>

<table>
  <tbody>
    <tr>
      <td align="left"><strong>Type</strong></td>
      <td align="left">FR</td>
      <td align="left"><strong>HLA ID(s)</strong></td>
      <td align="left"><nobr>[HLA-SECURITY](./hla.md#6-major-components "HLA-SECURITY")</nobr></td>
    </tr>
    <tr>
      <td align="left"><strong>DD Ref(s)</strong></td>
      <td align="left"><nobr>[DD §4.8](./dd.md#48-hla-security "DD §4.8")</nobr></td>
      <td align="left"><strong>Validation Status</strong></td>
      <td align="left"><nobr>Planned</nobr></td>
    </tr>
    <tr>
      <td align="left"><strong>Implementation Unit</strong></td>
      <td align="left"><nobr>TBD</nobr></td>
      <td align="left"><strong>Test Case ID</strong></td>
      <td align="left"><nobr>SEC-RBAC-001 (DD provisional)</nobr></td>
    </tr>
    <tr>
      <td align="left"><strong>Packaging Ref</strong></td>
      <td align="left"><nobr>TBD</nobr></td>
      <td align="left"><strong>Orchestration Ref</strong></td>
      <td align="left"><nobr>TBD</nobr></td>
    </tr>
    <tr>
      <td align="left"><strong>Evidence</strong></td>
      <td align="left" colspan="3">Initial security decomposition in progress; provisional test-ID mapping tracked in §10</td>
    </tr>
  </tbody>
</table>

</details>

<details>
  <summary><nobr>[FR-018](./srs.md#fr-018--tenant-boundary "FR-018")</nobr> — <nobr>Planned</nobr></summary>

<table>
  <tbody>
    <tr>
      <td align="left"><strong>Type</strong></td>
      <td align="left">FR</td>
      <td align="left"><strong>HLA ID(s)</strong></td>
      <td align="left"><nobr>[HLA-SECURITY](./hla.md#6-major-components "HLA-SECURITY")</nobr></td>
    </tr>
    <tr>
      <td align="left"><strong>DD Ref(s)</strong></td>
      <td align="left"><nobr>[DD §4.8](./dd.md#48-hla-security "DD §4.8")</nobr></td>
      <td align="left"><strong>Validation Status</strong></td>
      <td align="left"><nobr>Planned</nobr></td>
    </tr>
    <tr>
      <td align="left"><strong>Implementation Unit</strong></td>
      <td align="left"><nobr>TBD</nobr></td>
      <td align="left"><strong>Test Case ID</strong></td>
      <td align="left"><nobr>SEC-RBAC-001, SEC-STATE-001 (DD provisional)</nobr></td>
    </tr>
    <tr>
      <td align="left"><strong>Packaging Ref</strong></td>
      <td align="left"><nobr>TBD</nobr></td>
      <td align="left"><strong>Orchestration Ref</strong></td>
      <td align="left"><nobr>TBD</nobr></td>
    </tr>
    <tr>
      <td align="left"><strong>Evidence</strong></td>
      <td align="left" colspan="3">Initial security decomposition in progress; provisional test-ID mapping tracked in §10</td>
    </tr>
  </tbody>
</table>

</details>

<details>
  <summary><nobr>[FR-019](./srs.md#fr-019--open-in-native-reader "FR-019")</nobr> — <nobr>Planned</nobr></summary>

<table>
  <tbody>
    <tr>
      <td align="left"><strong>Type</strong></td>
      <td align="left">FR</td>
      <td align="left"><strong>HLA ID(s)</strong></td>
      <td align="left"><nobr>[HLA-SHELL](./hla.md#6-major-components "HLA-SHELL")</nobr>, <nobr>[HLA-STORAGE](./hla.md#6-major-components "HLA-STORAGE")</nobr></td>
    </tr>
    <tr>
      <td align="left"><strong>DD Ref(s)</strong></td>
      <td align="left"><nobr>[DD §4.1](./dd.md#41-hla-shell "DD §4.1")</nobr>, <nobr>[DD §4.7](./dd.md#47-hla-storage "DD §4.7")</nobr></td>
      <td align="left"><strong>Validation Status</strong></td>
      <td align="left"><nobr>Planned</nobr></td>
    </tr>
    <tr>
      <td align="left"><strong>Implementation Unit</strong></td>
      <td align="left"><nobr>TBD</nobr></td>
      <td align="left"><strong>Test Case ID</strong></td>
      <td align="left"><nobr>TBD</nobr></td>
    </tr>
    <tr>
      <td align="left"><strong>Packaging Ref</strong></td>
      <td align="left"><nobr>TBD</nobr></td>
      <td align="left"><strong>Orchestration Ref</strong></td>
      <td align="left"><nobr>TBD</nobr></td>
    </tr>
    <tr>
      <td align="left"><strong>Evidence</strong></td>
      <td align="left" colspan="3">Shell/storage decomposition in progress</td>
    </tr>
  </tbody>
</table>

</details>

<details>
  <summary><nobr>[FR-020](./srs.md#fr-020--settings-client-preferences "FR-020")</nobr> — <nobr>Planned</nobr></summary>

<table>
  <tbody>
    <tr>
      <td align="left"><strong>Type</strong></td>
      <td align="left">FR</td>
      <td align="left"><strong>HLA ID(s)</strong></td>
      <td align="left"><nobr>[HLA-SHELL](./hla.md#6-major-components "HLA-SHELL")</nobr></td>
    </tr>
    <tr>
      <td align="left"><strong>DD Ref(s)</strong></td>
      <td align="left"><nobr>[DD §4.1](./dd.md#41-hla-shell "DD §4.1")</nobr></td>
      <td align="left"><strong>Validation Status</strong></td>
      <td align="left"><nobr>Planned</nobr></td>
    </tr>
    <tr>
      <td align="left"><strong>Implementation Unit</strong></td>
      <td align="left"><nobr>TBD</nobr></td>
      <td align="left"><strong>Test Case ID</strong></td>
      <td align="left"><nobr>TBD</nobr></td>
    </tr>
    <tr>
      <td align="left"><strong>Packaging Ref</strong></td>
      <td align="left"><nobr>TBD</nobr></td>
      <td align="left"><strong>Orchestration Ref</strong></td>
      <td align="left"><nobr>TBD</nobr></td>
    </tr>
    <tr>
      <td align="left"><strong>Evidence</strong></td>
      <td align="left" colspan="3">Initial shell decomposition in progress</td>
    </tr>
  </tbody>
</table>

</details>

<details>
  <summary><nobr>[FR-021](./srs.md#fr-021--preferred-reader-per-document-type "FR-021")</nobr> — <nobr>Planned</nobr></summary>

<table>
  <tbody>
    <tr>
      <td align="left"><strong>Type</strong></td>
      <td align="left">FR</td>
      <td align="left"><strong>HLA ID(s)</strong></td>
      <td align="left"><nobr>[HLA-SHELL](./hla.md#6-major-components "HLA-SHELL")</nobr></td>
    </tr>
    <tr>
      <td align="left"><strong>DD Ref(s)</strong></td>
      <td align="left"><nobr>[DD §4.1](./dd.md#41-hla-shell "DD §4.1")</nobr></td>
      <td align="left"><strong>Validation Status</strong></td>
      <td align="left"><nobr>Planned</nobr></td>
    </tr>
    <tr>
      <td align="left"><strong>Implementation Unit</strong></td>
      <td align="left"><nobr>TBD</nobr></td>
      <td align="left"><strong>Test Case ID</strong></td>
      <td align="left"><nobr>TBD</nobr></td>
    </tr>
    <tr>
      <td align="left"><strong>Packaging Ref</strong></td>
      <td align="left"><nobr>TBD</nobr></td>
      <td align="left"><strong>Orchestration Ref</strong></td>
      <td align="left"><nobr>TBD</nobr></td>
    </tr>
    <tr>
      <td align="left"><strong>Evidence</strong></td>
      <td align="left" colspan="3">Initial shell decomposition in progress</td>
    </tr>
  </tbody>
</table>

</details>

<details>
  <summary><nobr>[FR-022](./srs.md#fr-022--application-theme "FR-022")</nobr> — <nobr>Planned</nobr></summary>

<table>
  <tbody>
    <tr>
      <td align="left"><strong>Type</strong></td>
      <td align="left">FR</td>
      <td align="left"><strong>HLA ID(s)</strong></td>
      <td align="left"><nobr>[HLA-SHELL](./hla.md#6-major-components "HLA-SHELL")</nobr></td>
    </tr>
    <tr>
      <td align="left"><strong>DD Ref(s)</strong></td>
      <td align="left"><nobr>[DD §4.1](./dd.md#41-hla-shell "DD §4.1")</nobr></td>
      <td align="left"><strong>Validation Status</strong></td>
      <td align="left"><nobr>Planned</nobr></td>
    </tr>
    <tr>
      <td align="left"><strong>Implementation Unit</strong></td>
      <td align="left"><nobr>TBD</nobr></td>
      <td align="left"><strong>Test Case ID</strong></td>
      <td align="left"><nobr>TBD</nobr></td>
    </tr>
    <tr>
      <td align="left"><strong>Packaging Ref</strong></td>
      <td align="left"><nobr>TBD</nobr></td>
      <td align="left"><strong>Orchestration Ref</strong></td>
      <td align="left"><nobr>TBD</nobr></td>
    </tr>
    <tr>
      <td align="left"><strong>Evidence</strong></td>
      <td align="left" colspan="3">Initial shell decomposition in progress</td>
    </tr>
  </tbody>
</table>

</details>

<details>
  <summary><nobr>[FR-023](./srs.md#fr-023--ocr-for-searchability "FR-023")</nobr> — <nobr>Planned</nobr></summary>

<table>
  <tbody>
    <tr>
      <td align="left"><strong>Type</strong></td>
      <td align="left">FR</td>
      <td align="left"><strong>HLA ID(s)</strong></td>
      <td align="left"><nobr>[HLA-OCR](./hla.md#6-major-components "HLA-OCR")</nobr></td>
    </tr>
    <tr>
      <td align="left"><strong>DD Ref(s)</strong></td>
      <td align="left"><nobr>[DD §4.9](./dd.md#49-hla-ocr--hla-bound-ocr "DD §4.9")</nobr></td>
      <td align="left"><strong>Validation Status</strong></td>
      <td align="left"><nobr>Planned</nobr></td>
    </tr>
    <tr>
      <td align="left"><strong>Implementation Unit</strong></td>
      <td align="left"><nobr>TBD</nobr></td>
      <td align="left"><strong>Test Case ID</strong></td>
      <td align="left"><nobr>TP-INGEST-003, TP-OCR-001, TP-OCR-003</nobr></td>
    </tr>
    <tr>
      <td align="left"><strong>Packaging Ref</strong></td>
      <td align="left"><nobr>TBD</nobr></td>
      <td align="left"><strong>Orchestration Ref</strong></td>
      <td align="left"><nobr>TBD</nobr></td>
    </tr>
    <tr>
      <td align="left"><strong>Evidence</strong></td>
      <td align="left" colspan="3">Initial OCR boundary decomposition in progress</td>
    </tr>
  </tbody>
</table>

</details>

<details>
  <summary><nobr>[FR-024](./srs.md#fr-024--shell-accessibility "FR-024")</nobr> — <nobr>Planned</nobr></summary>

<table>
  <tbody>
    <tr>
      <td align="left"><strong>Type</strong></td>
      <td align="left">FR</td>
      <td align="left"><strong>HLA ID(s)</strong></td>
      <td align="left"><nobr>[HLA-SHELL](./hla.md#6-major-components "HLA-SHELL")</nobr></td>
    </tr>
    <tr>
      <td align="left"><strong>DD Ref(s)</strong></td>
      <td align="left"><nobr>[DD §4.1](./dd.md#41-hla-shell "DD §4.1")</nobr></td>
      <td align="left"><strong>Validation Status</strong></td>
      <td align="left"><nobr>Planned</nobr></td>
    </tr>
    <tr>
      <td align="left"><strong>Implementation Unit</strong></td>
      <td align="left"><nobr>TBD</nobr></td>
      <td align="left"><strong>Test Case ID</strong></td>
      <td align="left"><nobr>TBD</nobr></td>
    </tr>
    <tr>
      <td align="left"><strong>Packaging Ref</strong></td>
      <td align="left"><nobr>TBD</nobr></td>
      <td align="left"><strong>Orchestration Ref</strong></td>
      <td align="left"><nobr>TBD</nobr></td>
    </tr>
    <tr>
      <td align="left"><strong>Evidence</strong></td>
      <td align="left" colspan="3">Initial shell decomposition in progress</td>
    </tr>
  </tbody>
</table>

</details>

<details>
  <summary><nobr>[FR-025](./srs.md#fr-025--english-ui-v1 "FR-025")</nobr> — <nobr>Planned</nobr></summary>

<table>
  <tbody>
    <tr>
      <td align="left"><strong>Type</strong></td>
      <td align="left">FR</td>
      <td align="left"><strong>HLA ID(s)</strong></td>
      <td align="left"><nobr>[HLA-SHELL](./hla.md#6-major-components "HLA-SHELL")</nobr></td>
    </tr>
    <tr>
      <td align="left"><strong>DD Ref(s)</strong></td>
      <td align="left"><nobr>[DD §4.1](./dd.md#41-hla-shell "DD §4.1")</nobr></td>
      <td align="left"><strong>Validation Status</strong></td>
      <td align="left"><nobr>Planned</nobr></td>
    </tr>
    <tr>
      <td align="left"><strong>Implementation Unit</strong></td>
      <td align="left"><nobr>TBD</nobr></td>
      <td align="left"><strong>Test Case ID</strong></td>
      <td align="left"><nobr>TBD</nobr></td>
    </tr>
    <tr>
      <td align="left"><strong>Packaging Ref</strong></td>
      <td align="left"><nobr>TBD</nobr></td>
      <td align="left"><strong>Orchestration Ref</strong></td>
      <td align="left"><nobr>TBD</nobr></td>
    </tr>
    <tr>
      <td align="left"><strong>Evidence</strong></td>
      <td align="left" colspan="3">Initial shell decomposition in progress</td>
    </tr>
  </tbody>
</table>

</details>

<details>
  <summary><nobr>[FR-026](./srs.md#fr-026--audit-logging "FR-026")</nobr> — <nobr>Planned</nobr></summary>

<table>
  <tbody>
    <tr>
      <td align="left"><strong>Type</strong></td>
      <td align="left">FR</td>
      <td align="left"><strong>HLA ID(s)</strong></td>
      <td align="left"><nobr>[HLA-AUDIT](./hla.md#6-major-components "HLA-AUDIT")</nobr></td>
    </tr>
    <tr>
      <td align="left"><strong>DD Ref(s)</strong></td>
      <td align="left"><nobr>[DD §4.10](./dd.md#410-hla-audit "DD §4.10")</nobr></td>
      <td align="left"><strong>Validation Status</strong></td>
      <td align="left"><nobr>Planned</nobr></td>
    </tr>
    <tr>
      <td align="left"><strong>Implementation Unit</strong></td>
      <td align="left"><nobr>TBD</nobr></td>
      <td align="left"><strong>Test Case ID</strong></td>
      <td align="left"><nobr>TBD</nobr></td>
    </tr>
    <tr>
      <td align="left"><strong>Packaging Ref</strong></td>
      <td align="left"><nobr>TBD</nobr></td>
      <td align="left"><strong>Orchestration Ref</strong></td>
      <td align="left"><nobr>TBD</nobr></td>
    </tr>
    <tr>
      <td align="left"><strong>Evidence</strong></td>
      <td align="left" colspan="3">Initial audit decomposition in progress</td>
    </tr>
  </tbody>
</table>

</details>

<details>
  <summary><nobr>[FR-027](./srs.md#fr-027--password-storage "FR-027")</nobr> — <nobr>Planned</nobr></summary>

<table>
  <tbody>
    <tr>
      <td align="left"><strong>Type</strong></td>
      <td align="left">FR</td>
      <td align="left"><strong>HLA ID(s)</strong></td>
      <td align="left"><nobr>[HLA-SECURITY](./hla.md#6-major-components "HLA-SECURITY")</nobr></td>
    </tr>
    <tr>
      <td align="left"><strong>DD Ref(s)</strong></td>
      <td align="left"><nobr>[DD §4.8](./dd.md#48-hla-security "DD §4.8")</nobr></td>
      <td align="left"><strong>Validation Status</strong></td>
      <td align="left"><nobr>Planned</nobr></td>
    </tr>
    <tr>
      <td align="left"><strong>Implementation Unit</strong></td>
      <td align="left"><nobr>TBD</nobr></td>
      <td align="left"><strong>Test Case ID</strong></td>
      <td align="left"><nobr>SEC-PASS-001, SEC-PASS-002 (DD provisional)</nobr></td>
    </tr>
    <tr>
      <td align="left"><strong>Packaging Ref</strong></td>
      <td align="left"><nobr>TBD</nobr></td>
      <td align="left"><strong>Orchestration Ref</strong></td>
      <td align="left"><nobr>TBD</nobr></td>
    </tr>
    <tr>
      <td align="left"><strong>Evidence</strong></td>
      <td align="left" colspan="3">Argon2id preferred baseline; concrete library TBD; provisional test-ID mapping tracked in §10</td>
    </tr>
  </tbody>
</table>

</details>

<details>
  <summary><nobr>[FR-028](./srs.md#fr-028--configurable-log-retention "FR-028")</nobr> — <nobr>Planned</nobr></summary>

<table>
  <tbody>
    <tr>
      <td align="left"><strong>Type</strong></td>
      <td align="left">FR</td>
      <td align="left"><strong>HLA ID(s)</strong></td>
      <td align="left"><nobr>[HLA-OBSLOG](./hla.md#6-major-components "HLA-OBSLOG")</nobr></td>
    </tr>
    <tr>
      <td align="left"><strong>DD Ref(s)</strong></td>
      <td align="left"><nobr>[DD §4.11](./dd.md#411-hla-obslog "DD §4.11")</nobr></td>
      <td align="left"><strong>Validation Status</strong></td>
      <td align="left"><nobr>Planned</nobr></td>
    </tr>
    <tr>
      <td align="left"><strong>Implementation Unit</strong></td>
      <td align="left"><nobr>TBD</nobr></td>
      <td align="left"><strong>Test Case ID</strong></td>
      <td align="left"><nobr>TBD</nobr></td>
    </tr>
    <tr>
      <td align="left"><strong>Packaging Ref</strong></td>
      <td align="left"><nobr>TBD</nobr></td>
      <td align="left"><strong>Orchestration Ref</strong></td>
      <td align="left"><nobr>TBD</nobr></td>
    </tr>
    <tr>
      <td align="left"><strong>Evidence</strong></td>
      <td align="left" colspan="3">Initial obslog decomposition in progress</td>
    </tr>
  </tbody>
</table>

</details>

<details>
  <summary><nobr>[FR-029](./srs.md#fr-029--operational-and-diagnostic-logging-client-and-server "FR-029")</nobr> — <nobr>Planned</nobr></summary>

<table>
  <tbody>
    <tr>
      <td align="left"><strong>Type</strong></td>
      <td align="left">FR</td>
      <td align="left"><strong>HLA ID(s)</strong></td>
      <td align="left"><nobr>[HLA-OBSLOG](./hla.md#6-major-components "HLA-OBSLOG")</nobr>, <nobr>[HLA-SHELL](./hla.md#6-major-components "HLA-SHELL")</nobr></td>
    </tr>
    <tr>
      <td align="left"><strong>DD Ref(s)</strong></td>
      <td align="left"><nobr>[DD §4.1](./dd.md#41-hla-shell "DD §4.1")</nobr>, <nobr>[DD §4.11](./dd.md#411-hla-obslog "DD §4.11")</nobr></td>
      <td align="left"><strong>Validation Status</strong></td>
      <td align="left"><nobr>Planned</nobr></td>
    </tr>
    <tr>
      <td align="left"><strong>Implementation Unit</strong></td>
      <td align="left"><nobr>TBD</nobr></td>
      <td align="left"><strong>Test Case ID</strong></td>
      <td align="left"><nobr>TP-OPS-002</nobr></td>
    </tr>
    <tr>
      <td align="left"><strong>Packaging Ref</strong></td>
      <td align="left"><nobr>TBD</nobr></td>
      <td align="left"><strong>Orchestration Ref</strong></td>
      <td align="left"><nobr>TBD</nobr></td>
    </tr>
    <tr>
      <td align="left"><strong>Evidence</strong></td>
      <td align="left" colspan="3">Shell/obslog decomposition in progress</td>
    </tr>
  </tbody>
</table>

</details>

<details>
  <summary><nobr>[FR-030](./srs.md#fr-030--release-information "FR-030")</nobr> — <nobr>Planned</nobr></summary>

<table>
  <tbody>
    <tr>
      <td align="left"><strong>Type</strong></td>
      <td align="left">FR</td>
      <td align="left"><strong>HLA ID(s)</strong></td>
      <td align="left"><nobr>[HLA-RELEASE](./hla.md#6-major-components "HLA-RELEASE")</nobr></td>
    </tr>
    <tr>
      <td align="left"><strong>DD Ref(s)</strong></td>
      <td align="left"><nobr>[DD §4.12](./dd.md#412-hla-release "DD §4.12")</nobr></td>
      <td align="left"><strong>Validation Status</strong></td>
      <td align="left"><nobr>Planned</nobr></td>
    </tr>
    <tr>
      <td align="left"><strong>Implementation Unit</strong></td>
      <td align="left"><nobr>TBD</nobr></td>
      <td align="left"><strong>Test Case ID</strong></td>
      <td align="left"><nobr>TBD</nobr></td>
    </tr>
    <tr>
      <td align="left"><strong>Packaging Ref</strong></td>
      <td align="left"><nobr>TBD</nobr></td>
      <td align="left"><strong>Orchestration Ref</strong></td>
      <td align="left"><nobr>TBD</nobr></td>
    </tr>
    <tr>
      <td align="left"><strong>Evidence</strong></td>
      <td align="left" colspan="3">Initial release decomposition in progress</td>
    </tr>
  </tbody>
</table>

</details>

<details>
  <summary><nobr>[FR-031](./srs.md#fr-031--user-account-and-role-administration "FR-031")</nobr> — <nobr>Planned</nobr></summary>

<table>
  <tbody>
    <tr>
      <td align="left"><strong>Type</strong></td>
      <td align="left">FR</td>
      <td align="left"><strong>HLA ID(s)</strong></td>
      <td align="left"><nobr>[HLA-SHELL](./hla.md#6-major-components "HLA-SHELL")</nobr>, <nobr>[HLA-SECURITY](./hla.md#6-major-components "HLA-SECURITY")</nobr></td>
    </tr>
    <tr>
      <td align="left"><strong>DD Ref(s)</strong></td>
      <td align="left"><nobr>[DD §4.1](./dd.md#41-hla-shell "DD §4.1")</nobr>, <nobr>[DD §4.8](./dd.md#48-hla-security "DD §4.8")</nobr></td>
      <td align="left"><strong>Validation Status</strong></td>
      <td align="left"><nobr>Planned</nobr></td>
    </tr>
    <tr>
      <td align="left"><strong>Implementation Unit</strong></td>
      <td align="left"><nobr>TBD</nobr></td>
      <td align="left"><strong>Test Case ID</strong></td>
      <td align="left"><nobr>SEC-ADMIN-001, SEC-RBAC-001 (DD provisional)</nobr></td>
    </tr>
    <tr>
      <td align="left"><strong>Packaging Ref</strong></td>
      <td align="left"><nobr>TBD</nobr></td>
      <td align="left"><strong>Orchestration Ref</strong></td>
      <td align="left"><nobr>TBD</nobr></td>
    </tr>
    <tr>
      <td align="left"><strong>Evidence</strong></td>
      <td align="left" colspan="3">Shell/security decomposition in progress; provisional test-ID mapping tracked in §10</td>
    </tr>
  </tbody>
</table>

</details>

<details>
  <summary><nobr>[FR-032](./srs.md#fr-032--initial-administrator-bootstrap "FR-032")</nobr> — <nobr>Planned</nobr></summary>

<table>
  <tbody>
    <tr>
      <td align="left"><strong>Type</strong></td>
      <td align="left">FR</td>
      <td align="left"><strong>HLA ID(s)</strong></td>
      <td align="left"><nobr>[HLA-SECURITY](./hla.md#6-major-components "HLA-SECURITY")</nobr></td>
    </tr>
    <tr>
      <td align="left"><strong>DD Ref(s)</strong></td>
      <td align="left"><nobr>[DD §4.8](./dd.md#48-hla-security "DD §4.8")</nobr></td>
      <td align="left"><strong>Validation Status</strong></td>
      <td align="left"><nobr>Planned</nobr></td>
    </tr>
    <tr>
      <td align="left"><strong>Implementation Unit</strong></td>
      <td align="left"><nobr>TBD</nobr></td>
      <td align="left"><strong>Test Case ID</strong></td>
      <td align="left"><nobr>SEC-BOOT-001 (DD provisional)</nobr></td>
    </tr>
    <tr>
      <td align="left"><strong>Packaging Ref</strong></td>
      <td align="left"><nobr>TBD</nobr></td>
      <td align="left"><strong>Orchestration Ref</strong></td>
      <td align="left"><nobr>TBD</nobr></td>
    </tr>
    <tr>
      <td align="left"><strong>Evidence</strong></td>
      <td align="left" colspan="3">Bootstrap policy baseline; provisional test-ID mapping tracked in §10</td>
    </tr>
  </tbody>
</table>

</details>

<details>
  <summary><nobr>[FR-033](./srs.md#fr-033--password-change-and-administrative-reset "FR-033")</nobr> — <nobr>Planned</nobr></summary>

<table>
  <tbody>
    <tr>
      <td align="left"><strong>Type</strong></td>
      <td align="left">FR</td>
      <td align="left"><strong>HLA ID(s)</strong></td>
      <td align="left"><nobr>[HLA-SECURITY](./hla.md#6-major-components "HLA-SECURITY")</nobr></td>
    </tr>
    <tr>
      <td align="left"><strong>DD Ref(s)</strong></td>
      <td align="left"><nobr>[DD §4.8](./dd.md#48-hla-security "DD §4.8")</nobr></td>
      <td align="left"><strong>Validation Status</strong></td>
      <td align="left"><nobr>Planned</nobr></td>
    </tr>
    <tr>
      <td align="left"><strong>Implementation Unit</strong></td>
      <td align="left"><nobr>TBD</nobr></td>
      <td align="left"><strong>Test Case ID</strong></td>
      <td align="left"><nobr>SEC-PASS-003 (DD provisional)</nobr></td>
    </tr>
    <tr>
      <td align="left"><strong>Packaging Ref</strong></td>
      <td align="left"><nobr>TBD</nobr></td>
      <td align="left"><strong>Orchestration Ref</strong></td>
      <td align="left"><nobr>TBD</nobr></td>
    </tr>
    <tr>
      <td align="left"><strong>Evidence</strong></td>
      <td align="left" colspan="3">Password change/reset baseline; provisional test-ID mapping tracked in §10</td>
    </tr>
  </tbody>
</table>

</details>

<details>
  <summary><nobr>[FR-034](./srs.md#fr-034--authentication-throttling "FR-034")</nobr> — <nobr>Planned</nobr></summary>

<table>
  <tbody>
    <tr>
      <td align="left"><strong>Type</strong></td>
      <td align="left">FR</td>
      <td align="left"><strong>HLA ID(s)</strong></td>
      <td align="left"><nobr>[HLA-SECURITY](./hla.md#6-major-components "HLA-SECURITY")</nobr></td>
    </tr>
    <tr>
      <td align="left"><strong>DD Ref(s)</strong></td>
      <td align="left"><nobr>[DD §4.8](./dd.md#48-hla-security "DD §4.8")</nobr></td>
      <td align="left"><strong>Validation Status</strong></td>
      <td align="left"><nobr>Planned</nobr></td>
    </tr>
    <tr>
      <td align="left"><strong>Implementation Unit</strong></td>
      <td align="left"><nobr>TBD</nobr></td>
      <td align="left"><strong>Test Case ID</strong></td>
      <td align="left"><nobr>SEC-THROTTLE-001 (DD provisional)</nobr></td>
    </tr>
    <tr>
      <td align="left"><strong>Packaging Ref</strong></td>
      <td align="left"><nobr>TBD</nobr></td>
      <td align="left"><strong>Orchestration Ref</strong></td>
      <td align="left"><nobr>TBD</nobr></td>
    </tr>
    <tr>
      <td align="left"><strong>Evidence</strong></td>
      <td align="left" colspan="3">Throttling baseline; provisional test-ID mapping tracked in §10</td>
    </tr>
  </tbody>
</table>

</details>

<details>
  <summary><nobr>[FR-035](./srs.md#fr-035--session-management "FR-035")</nobr> — <nobr>Planned</nobr></summary>

<table>
  <tbody>
    <tr>
      <td align="left"><strong>Type</strong></td>
      <td align="left">FR</td>
      <td align="left"><strong>HLA ID(s)</strong></td>
      <td align="left"><nobr>[HLA-SECURITY](./hla.md#6-major-components "HLA-SECURITY")</nobr></td>
    </tr>
    <tr>
      <td align="left"><strong>DD Ref(s)</strong></td>
      <td align="left"><nobr>[DD §4.8](./dd.md#48-hla-security "DD §4.8")</nobr></td>
      <td align="left"><strong>Validation Status</strong></td>
      <td align="left"><nobr>Planned</nobr></td>
    </tr>
    <tr>
      <td align="left"><strong>Implementation Unit</strong></td>
      <td align="left"><nobr>TBD</nobr></td>
      <td align="left"><strong>Test Case ID</strong></td>
      <td align="left"><nobr>SEC-REFRESH-001, SEC-REFRESH-002, SEC-JWKS-001, SEC-JWKS-002, SEC-JWKS-003, SEC-JWKS-004 (DD provisional)</nobr></td>
    </tr>
    <tr>
      <td align="left"><strong>Packaging Ref</strong></td>
      <td align="left"><nobr>TBD</nobr></td>
      <td align="left"><strong>Orchestration Ref</strong></td>
      <td align="left"><nobr>TBD</nobr></td>
    </tr>
    <tr>
      <td align="left"><strong>Evidence</strong></td>
      <td align="left" colspan="3">Session policy baseline; timeout numeric bounds still to finalize; provisional test-ID mapping tracked in §10</td>
    </tr>
  </tbody>
</table>

</details>

<details>
  <summary><nobr>[FR-036](./srs.md#fr-036--library-corpus-and-storage-model "FR-036")</nobr> — <nobr>Planned</nobr></summary>

<table>
  <tbody>
    <tr>
      <td align="left"><strong>Type</strong></td>
      <td align="left">FR</td>
      <td align="left"><strong>HLA ID(s)</strong></td>
      <td align="left"><nobr>[HLA-STORAGE](./hla.md#6-major-components "HLA-STORAGE")</nobr></td>
    </tr>
    <tr>
      <td align="left"><strong>DD Ref(s)</strong></td>
      <td align="left"><nobr>[DD §4.7](./dd.md#47-hla-storage "DD §4.7")</nobr></td>
      <td align="left"><strong>Validation Status</strong></td>
      <td align="left"><nobr>Planned</nobr></td>
    </tr>
    <tr>
      <td align="left"><strong>Implementation Unit</strong></td>
      <td align="left"><nobr>TBD</nobr></td>
      <td align="left"><strong>Test Case ID</strong></td>
      <td align="left"><nobr>TBD</nobr></td>
    </tr>
    <tr>
      <td align="left"><strong>Packaging Ref</strong></td>
      <td align="left"><nobr>TBD</nobr></td>
      <td align="left"><strong>Orchestration Ref</strong></td>
      <td align="left"><nobr>TBD</nobr></td>
    </tr>
    <tr>
      <td align="left"><strong>Evidence</strong></td>
      <td align="left" colspan="3">Initial storage decomposition in progress</td>
    </tr>
  </tbody>
</table>

</details>

<details>
  <summary><nobr>[FR-037](./srs.md#fr-037--catalog-browse-sort-and-pagination "FR-037")</nobr> — <nobr>Planned</nobr></summary>

<table>
  <tbody>
    <tr>
      <td align="left"><strong>Type</strong></td>
      <td align="left">FR</td>
      <td align="left"><strong>HLA ID(s)</strong></td>
      <td align="left"><nobr>[HLA-SHELL](./hla.md#6-major-components "HLA-SHELL")</nobr>, <nobr>[HLA-DOMAIN](./hla.md#6-major-components "HLA-DOMAIN")</nobr></td>
    </tr>
    <tr>
      <td align="left"><strong>DD Ref(s)</strong></td>
      <td align="left"><nobr>[DD §4.1](./dd.md#41-hla-shell "DD §4.1")</nobr>, <nobr>[DD §4.4](./dd.md#44-hla-domain "DD §4.4")</nobr></td>
      <td align="left"><strong>Validation Status</strong></td>
      <td align="left"><nobr>Planned</nobr></td>
    </tr>
    <tr>
      <td align="left"><strong>Implementation Unit</strong></td>
      <td align="left"><nobr>TBD</nobr></td>
      <td align="left"><strong>Test Case ID</strong></td>
      <td align="left"><nobr>TBD</nobr></td>
    </tr>
    <tr>
      <td align="left"><strong>Packaging Ref</strong></td>
      <td align="left"><nobr>TBD</nobr></td>
      <td align="left"><strong>Orchestration Ref</strong></td>
      <td align="left"><nobr>TBD</nobr></td>
    </tr>
    <tr>
      <td align="left"><strong>Evidence</strong></td>
      <td align="left" colspan="3">Shell/domain decomposition in progress</td>
    </tr>
  </tbody>
</table>

</details>

<details>
  <summary><nobr>[FR-038](./srs.md#fr-038--search-query-semantics-and-results "FR-038")</nobr> — <nobr>Planned</nobr></summary>

<table>
  <tbody>
    <tr>
      <td align="left"><strong>Type</strong></td>
      <td align="left">FR</td>
      <td align="left"><strong>HLA ID(s)</strong></td>
      <td align="left"><nobr>[HLA-SEARCH](./hla.md#6-major-components "HLA-SEARCH")</nobr></td>
    </tr>
    <tr>
      <td align="left"><strong>DD Ref(s)</strong></td>
      <td align="left"><nobr>[DD §4.6](./dd.md#46-hla-search "DD §4.6")</nobr></td>
      <td align="left"><strong>Validation Status</strong></td>
      <td align="left"><nobr>Planned</nobr></td>
    </tr>
    <tr>
      <td align="left"><strong>Implementation Unit</strong></td>
      <td align="left"><nobr>TBD</nobr></td>
      <td align="left"><strong>Test Case ID</strong></td>
      <td align="left"><nobr>TP-SEARCH-001</nobr></td>
    </tr>
    <tr>
      <td align="left"><strong>Packaging Ref</strong></td>
      <td align="left"><nobr>TBD</nobr></td>
      <td align="left"><strong>Orchestration Ref</strong></td>
      <td align="left"><nobr>TBD</nobr></td>
    </tr>
    <tr>
      <td align="left"><strong>Evidence</strong></td>
      <td align="left" colspan="3">Initial search decomposition in progress</td>
    </tr>
  </tbody>
</table>

</details>

<details>
  <summary><nobr>[FR-039](./srs.md#fr-039--full-text-index-administration "FR-039")</nobr> — <nobr>Planned</nobr></summary>

<table>
  <tbody>
    <tr>
      <td align="left"><strong>Type</strong></td>
      <td align="left">FR</td>
      <td align="left"><strong>HLA ID(s)</strong></td>
      <td align="left"><nobr>[HLA-SEARCH](./hla.md#6-major-components "HLA-SEARCH")</nobr>, <nobr>[HLA-SHELL](./hla.md#6-major-components "HLA-SHELL")</nobr></td>
    </tr>
    <tr>
      <td align="left"><strong>DD Ref(s)</strong></td>
      <td align="left"><nobr>[DD §4.1](./dd.md#41-hla-shell "DD §4.1")</nobr>, <nobr>[DD §4.6](./dd.md#46-hla-search "DD §4.6")</nobr></td>
      <td align="left"><strong>Validation Status</strong></td>
      <td align="left"><nobr>Planned</nobr></td>
    </tr>
    <tr>
      <td align="left"><strong>Implementation Unit</strong></td>
      <td align="left"><nobr>TBD</nobr></td>
      <td align="left"><strong>Test Case ID</strong></td>
      <td align="left"><nobr>TP-SEARCH-003, TP-OCR-002</nobr></td>
    </tr>
    <tr>
      <td align="left"><strong>Packaging Ref</strong></td>
      <td align="left"><nobr>TBD</nobr></td>
      <td align="left"><strong>Orchestration Ref</strong></td>
      <td align="left"><nobr>TBD</nobr></td>
    </tr>
    <tr>
      <td align="left"><strong>Evidence</strong></td>
      <td align="left" colspan="3">Shell/search decomposition in progress</td>
    </tr>
  </tbody>
</table>

</details>

<details>
  <summary><nobr>[FR-040](./srs.md#fr-040--metadata-validation "FR-040")</nobr> — <nobr>Planned</nobr></summary>

<table>
  <tbody>
    <tr>
      <td align="left"><strong>Type</strong></td>
      <td align="left">FR</td>
      <td align="left"><strong>HLA ID(s)</strong></td>
      <td align="left"><nobr>[HLA-DOMAIN](./hla.md#6-major-components "HLA-DOMAIN")</nobr></td>
    </tr>
    <tr>
      <td align="left"><strong>DD Ref(s)</strong></td>
      <td align="left"><nobr>[DD §4.4](./dd.md#44-hla-domain "DD §4.4")</nobr></td>
      <td align="left"><strong>Validation Status</strong></td>
      <td align="left"><nobr>Planned</nobr></td>
    </tr>
    <tr>
      <td align="left"><strong>Implementation Unit</strong></td>
      <td align="left"><nobr>TBD</nobr></td>
      <td align="left"><strong>Test Case ID</strong></td>
      <td align="left"><nobr>TBD</nobr></td>
    </tr>
    <tr>
      <td align="left"><strong>Packaging Ref</strong></td>
      <td align="left"><nobr>TBD</nobr></td>
      <td align="left"><strong>Orchestration Ref</strong></td>
      <td align="left"><nobr>TBD</nobr></td>
    </tr>
    <tr>
      <td align="left"><strong>Evidence</strong></td>
      <td align="left" colspan="3">Initial domain decomposition in progress</td>
    </tr>
  </tbody>
</table>

</details>

<details>
  <summary><nobr>[FR-041](./srs.md#fr-041--concurrent-metadata-updates "FR-041")</nobr> — <nobr>Planned</nobr></summary>

<table>
  <tbody>
    <tr>
      <td align="left"><strong>Type</strong></td>
      <td align="left">FR</td>
      <td align="left"><strong>HLA ID(s)</strong></td>
      <td align="left"><nobr>[HLA-DOMAIN](./hla.md#6-major-components "HLA-DOMAIN")</nobr></td>
    </tr>
    <tr>
      <td align="left"><strong>DD Ref(s)</strong></td>
      <td align="left"><nobr>[DD §4.4](./dd.md#44-hla-domain "DD §4.4")</nobr></td>
      <td align="left"><strong>Validation Status</strong></td>
      <td align="left"><nobr>Planned</nobr></td>
    </tr>
    <tr>
      <td align="left"><strong>Implementation Unit</strong></td>
      <td align="left"><nobr>TBD</nobr></td>
      <td align="left"><strong>Test Case ID</strong></td>
      <td align="left"><nobr>TP-CATALOG-003</nobr></td>
    </tr>
    <tr>
      <td align="left"><strong>Packaging Ref</strong></td>
      <td align="left"><nobr>TBD</nobr></td>
      <td align="left"><strong>Orchestration Ref</strong></td>
      <td align="left"><nobr>TBD</nobr></td>
    </tr>
    <tr>
      <td align="left"><strong>Evidence</strong></td>
      <td align="left" colspan="3">Initial domain decomposition in progress</td>
    </tr>
  </tbody>
</table>

</details>

<details>
  <summary><nobr>[NFR-001](./srs.md#nfr-001--corpus-scale-qualitative "NFR-001")</nobr> — <nobr>Planned</nobr></summary>

<table>
  <tbody>
    <tr>
      <td align="left"><strong>Type</strong></td>
      <td align="left">NFR</td>
      <td align="left"><strong>HLA ID(s)</strong></td>
      <td align="left"><nobr>[HLA-SEARCH](./hla.md#6-major-components "HLA-SEARCH")</nobr>, <nobr>[HLA-DOMAIN](./hla.md#6-major-components "HLA-DOMAIN")</nobr>, <nobr>[HLA-SERVER-HOST](./hla.md#6-major-components "HLA-SERVER-HOST")</nobr></td>
    </tr>
    <tr>
      <td align="left"><strong>DD Ref(s)</strong></td>
      <td align="left"><nobr>[DD §4.3](./dd.md#43-hla-server-host "DD §4.3")</nobr>, <nobr>[DD §4.4](./dd.md#44-hla-domain "DD §4.4")</nobr>, <nobr>[DD §4.6](./dd.md#46-hla-search "DD §4.6")</nobr></td>
      <td align="left"><strong>Validation Status</strong></td>
      <td align="left"><nobr>Planned</nobr></td>
    </tr>
    <tr>
      <td align="left"><strong>Implementation Unit</strong></td>
      <td align="left"><nobr>TBD</nobr></td>
      <td align="left"><strong>Test Case ID</strong></td>
      <td align="left"><nobr>TBD</nobr></td>
    </tr>
    <tr>
      <td align="left"><strong>Packaging Ref</strong></td>
      <td align="left"><nobr>TBD</nobr></td>
      <td align="left"><strong>Orchestration Ref</strong></td>
      <td align="left"><nobr>TBD</nobr></td>
    </tr>
    <tr>
      <td align="left"><strong>Evidence</strong></td>
      <td align="left" colspan="3">Server-host/domain/search decomposition in progress</td>
    </tr>
  </tbody>
</table>

</details>

<details>
  <summary><nobr>[NFR-002](./srs.md#nfr-002--server-side-enforcement "NFR-002")</nobr> — <nobr>Planned</nobr></summary>

<table>
  <tbody>
    <tr>
      <td align="left"><strong>Type</strong></td>
      <td align="left">NFR</td>
      <td align="left"><strong>HLA ID(s)</strong></td>
      <td align="left"><nobr>[HLA-SECURITY](./hla.md#6-major-components "HLA-SECURITY")</nobr>, <nobr>[HLA-SERVER-HOST](./hla.md#6-major-components "HLA-SERVER-HOST")</nobr></td>
    </tr>
    <tr>
      <td align="left"><strong>DD Ref(s)</strong></td>
      <td align="left"><nobr>[DD §4.3](./dd.md#43-hla-server-host "DD §4.3")</nobr>, <nobr>[DD §4.8](./dd.md#48-hla-security "DD §4.8")</nobr></td>
      <td align="left"><strong>Validation Status</strong></td>
      <td align="left"><nobr>Planned</nobr></td>
    </tr>
    <tr>
      <td align="left"><strong>Implementation Unit</strong></td>
      <td align="left"><nobr>TBD</nobr></td>
      <td align="left"><strong>Test Case ID</strong></td>
      <td align="left"><nobr>SEC-AUTH-003, SEC-RBAC-001 (DD provisional)</nobr></td>
    </tr>
    <tr>
      <td align="left"><strong>Packaging Ref</strong></td>
      <td align="left"><nobr>TBD</nobr></td>
      <td align="left"><strong>Orchestration Ref</strong></td>
      <td align="left"><nobr>TBD</nobr></td>
    </tr>
    <tr>
      <td align="left"><strong>Evidence</strong></td>
      <td align="left" colspan="3">Server-side security policy path in progress; provisional test-ID mapping tracked in §10</td>
    </tr>
  </tbody>
</table>

</details>

<details>
  <summary><nobr>[NFR-003](./srs.md#nfr-003--licensing-and-notices "NFR-003")</nobr> — <nobr>Planned</nobr></summary>

<table>
  <tbody>
    <tr>
      <td align="left"><strong>Type</strong></td>
      <td align="left">NFR</td>
      <td align="left"><strong>HLA ID(s)</strong></td>
      <td align="left"><nobr>[HLA-RELEASE](./hla.md#6-major-components "HLA-RELEASE")</nobr>, <nobr>[HLA-SHELL](./hla.md#6-major-components "HLA-SHELL")</nobr></td>
    </tr>
    <tr>
      <td align="left"><strong>DD Ref(s)</strong></td>
      <td align="left"><nobr>[DD §4.1](./dd.md#41-hla-shell "DD §4.1")</nobr>, <nobr>[DD §4.12](./dd.md#412-hla-release "DD §4.12")</nobr></td>
      <td align="left"><strong>Validation Status</strong></td>
      <td align="left"><nobr>Planned</nobr></td>
    </tr>
    <tr>
      <td align="left"><strong>Implementation Unit</strong></td>
      <td align="left"><nobr>TBD</nobr></td>
      <td align="left"><strong>Test Case ID</strong></td>
      <td align="left"><nobr>TBD</nobr></td>
    </tr>
    <tr>
      <td align="left"><strong>Packaging Ref</strong></td>
      <td align="left"><nobr>TBD</nobr></td>
      <td align="left"><strong>Orchestration Ref</strong></td>
      <td align="left"><nobr>TBD</nobr></td>
    </tr>
    <tr>
      <td align="left"><strong>Evidence</strong></td>
      <td align="left" colspan="3">Shell/release decomposition in progress</td>
    </tr>
  </tbody>
</table>

</details>

<details>
  <summary><nobr>[NFR-004](./srs.md#nfr-004--operator-documentation "NFR-004")</nobr> — <nobr>Planned</nobr></summary>

<table>
  <tbody>
    <tr>
      <td align="left"><strong>Type</strong></td>
      <td align="left">NFR</td>
      <td align="left"><strong>HLA ID(s)</strong></td>
      <td align="left"><nobr>[HLA-SHELL](./hla.md#6-major-components "HLA-SHELL")</nobr>, <nobr>[HLA-SERVER-HOST](./hla.md#6-major-components "HLA-SERVER-HOST")</nobr></td>
    </tr>
    <tr>
      <td align="left"><strong>DD Ref(s)</strong></td>
      <td align="left"><nobr>[DD §4.1](./dd.md#41-hla-shell "DD §4.1")</nobr>, <nobr>[DD §4.3](./dd.md#43-hla-server-host "DD §4.3")</nobr></td>
      <td align="left"><strong>Validation Status</strong></td>
      <td align="left"><nobr>Planned</nobr></td>
    </tr>
    <tr>
      <td align="left"><strong>Implementation Unit</strong></td>
      <td align="left"><nobr>TBD</nobr></td>
      <td align="left"><strong>Test Case ID</strong></td>
      <td align="left"><nobr>TP-PKG-001, TP-PKG-002</nobr></td>
    </tr>
    <tr>
      <td align="left"><strong>Packaging Ref</strong></td>
      <td align="left"><nobr>TBD</nobr></td>
      <td align="left"><strong>Orchestration Ref</strong></td>
      <td align="left"><nobr>TBD</nobr></td>
    </tr>
    <tr>
      <td align="left"><strong>Evidence</strong></td>
      <td align="left" colspan="3">Shell/server-host decomposition in progress</td>
    </tr>
  </tbody>
</table>

</details>

<details>
  <summary><nobr>[NFR-005](./srs.md#nfr-005--honest-policy-communication "NFR-005")</nobr> — <nobr>Planned</nobr></summary>

<table>
  <tbody>
    <tr>
      <td align="left"><strong>Type</strong></td>
      <td align="left">NFR</td>
      <td align="left"><strong>HLA ID(s)</strong></td>
      <td align="left"><nobr>[HLA-SHELL](./hla.md#6-major-components "HLA-SHELL")</nobr>, <nobr>[HLA-SERVER-HOST](./hla.md#6-major-components "HLA-SERVER-HOST")</nobr></td>
    </tr>
    <tr>
      <td align="left"><strong>DD Ref(s)</strong></td>
      <td align="left"><nobr>[DD §4.1](./dd.md#41-hla-shell "DD §4.1")</nobr>, <nobr>[DD §4.3](./dd.md#43-hla-server-host "DD §4.3")</nobr></td>
      <td align="left"><strong>Validation Status</strong></td>
      <td align="left"><nobr>Planned</nobr></td>
    </tr>
    <tr>
      <td align="left"><strong>Implementation Unit</strong></td>
      <td align="left"><nobr>TBD</nobr></td>
      <td align="left"><strong>Test Case ID</strong></td>
      <td align="left"><nobr>TBD</nobr></td>
    </tr>
    <tr>
      <td align="left"><strong>Packaging Ref</strong></td>
      <td align="left"><nobr>TBD</nobr></td>
      <td align="left"><strong>Orchestration Ref</strong></td>
      <td align="left"><nobr>TBD</nobr></td>
    </tr>
    <tr>
      <td align="left"><strong>Evidence</strong></td>
      <td align="left" colspan="3">Shell/server-host decomposition in progress</td>
    </tr>
  </tbody>
</table>

</details>

<details>
  <summary><nobr>[NFR-006](./srs.md#nfr-006--themed-shell-contrast "NFR-006")</nobr> — <nobr>Planned</nobr></summary>

<table>
  <tbody>
    <tr>
      <td align="left"><strong>Type</strong></td>
      <td align="left">NFR</td>
      <td align="left"><strong>HLA ID(s)</strong></td>
      <td align="left"><nobr>[HLA-SHELL](./hla.md#6-major-components "HLA-SHELL")</nobr></td>
    </tr>
    <tr>
      <td align="left"><strong>DD Ref(s)</strong></td>
      <td align="left"><nobr>[DD §4.1](./dd.md#41-hla-shell "DD §4.1")</nobr></td>
      <td align="left"><strong>Validation Status</strong></td>
      <td align="left"><nobr>Planned</nobr></td>
    </tr>
    <tr>
      <td align="left"><strong>Implementation Unit</strong></td>
      <td align="left"><nobr>TBD</nobr></td>
      <td align="left"><strong>Test Case ID</strong></td>
      <td align="left"><nobr>TBD</nobr></td>
    </tr>
    <tr>
      <td align="left"><strong>Packaging Ref</strong></td>
      <td align="left"><nobr>TBD</nobr></td>
      <td align="left"><strong>Orchestration Ref</strong></td>
      <td align="left"><nobr>TBD</nobr></td>
    </tr>
    <tr>
      <td align="left"><strong>Evidence</strong></td>
      <td align="left" colspan="3">Initial shell decomposition in progress</td>
    </tr>
  </tbody>
</table>

</details>

<details>
  <summary><nobr>[NFR-007](./srs.md#nfr-007--end-user-documentation-and-help "NFR-007")</nobr> — <nobr>Planned</nobr></summary>

<table>
  <tbody>
    <tr>
      <td align="left"><strong>Type</strong></td>
      <td align="left">NFR</td>
      <td align="left"><strong>HLA ID(s)</strong></td>
      <td align="left"><nobr>[HLA-SHELL](./hla.md#6-major-components "HLA-SHELL")</nobr></td>
    </tr>
    <tr>
      <td align="left"><strong>DD Ref(s)</strong></td>
      <td align="left"><nobr>[DD §4.1](./dd.md#41-hla-shell "DD §4.1")</nobr></td>
      <td align="left"><strong>Validation Status</strong></td>
      <td align="left"><nobr>Planned</nobr></td>
    </tr>
    <tr>
      <td align="left"><strong>Implementation Unit</strong></td>
      <td align="left"><nobr>TBD</nobr></td>
      <td align="left"><strong>Test Case ID</strong></td>
      <td align="left"><nobr>TP-NFR-003</nobr></td>
    </tr>
    <tr>
      <td align="left"><strong>Packaging Ref</strong></td>
      <td align="left"><nobr>TBD</nobr></td>
      <td align="left"><strong>Orchestration Ref</strong></td>
      <td align="left"><nobr>TBD</nobr></td>
    </tr>
    <tr>
      <td align="left"><strong>Evidence</strong></td>
      <td align="left" colspan="3">Initial shell decomposition in progress</td>
    </tr>
  </tbody>
</table>

</details>

<details>
  <summary><nobr>[NFR-008](./srs.md#nfr-008--logging-privacy-and-jurisdictional-readiness "NFR-008")</nobr> — <nobr>Planned</nobr></summary>

<table>
  <tbody>
    <tr>
      <td align="left"><strong>Type</strong></td>
      <td align="left">NFR</td>
      <td align="left"><strong>HLA ID(s)</strong></td>
      <td align="left"><nobr>[HLA-OBSLOG](./hla.md#6-major-components "HLA-OBSLOG")</nobr>, <nobr>[HLA-AUDIT](./hla.md#6-major-components "HLA-AUDIT")</nobr>, <nobr>[HLA-SERVER-HOST](./hla.md#6-major-components "HLA-SERVER-HOST")</nobr>, <nobr>[HLA-SECURITY](./hla.md#6-major-components "HLA-SECURITY")</nobr></td>
    </tr>
    <tr>
      <td align="left"><strong>DD Ref(s)</strong></td>
      <td align="left"><nobr>[DD §4.3](./dd.md#43-hla-server-host "DD §4.3")</nobr>, <nobr>[DD §4.8](./dd.md#48-hla-security "DD §4.8")</nobr>, <nobr>[DD §4.10](./dd.md#410-hla-audit "DD §4.10")</nobr>, <nobr>[DD §4.11](./dd.md#411-hla-obslog "DD §4.11")</nobr></td>
      <td align="left"><strong>Validation Status</strong></td>
      <td align="left"><nobr>Planned</nobr></td>
    </tr>
    <tr>
      <td align="left"><strong>Implementation Unit</strong></td>
      <td align="left"><nobr>TBD</nobr></td>
      <td align="left"><strong>Test Case ID</strong></td>
      <td align="left"><nobr>TP-OPS-002</nobr></td>
    </tr>
    <tr>
      <td align="left"><strong>Packaging Ref</strong></td>
      <td align="left"><nobr>TBD</nobr></td>
      <td align="left"><strong>Orchestration Ref</strong></td>
      <td align="left"><nobr>TBD</nobr></td>
    </tr>
    <tr>
      <td align="left"><strong>Evidence</strong></td>
      <td align="left" colspan="3">Security/audit/obslog/server-host decomposition in progress; mapped to approved Test Plan v0.1 case TP-OPS-002</td>
    </tr>
  </tbody>
</table>

</details>

<details>
  <summary><nobr>[NFR-009](./srs.md#nfr-009--transport-security-remote-access "NFR-009")</nobr> — <nobr>Planned</nobr></summary>

<table>
  <tbody>
    <tr>
      <td align="left"><strong>Type</strong></td>
      <td align="left">NFR</td>
      <td align="left"><strong>HLA ID(s)</strong></td>
      <td align="left"><nobr>[HLA-CLIENT-ACCESS](./hla.md#6-major-components "HLA-CLIENT-ACCESS")</nobr>, <nobr>[HLA-SERVER-HOST](./hla.md#6-major-components "HLA-SERVER-HOST")</nobr></td>
    </tr>
    <tr>
      <td align="left"><strong>DD Ref(s)</strong></td>
      <td align="left"><nobr>[DD §4.2](./dd.md#42-hla-client-access "DD §4.2")</nobr>, <nobr>[DD §4.3](./dd.md#43-hla-server-host "DD §4.3")</nobr></td>
      <td align="left"><strong>Validation Status</strong></td>
      <td align="left"><nobr>Planned</nobr></td>
    </tr>
    <tr>
      <td align="left"><strong>Implementation Unit</strong></td>
      <td align="left"><nobr>TBD</nobr></td>
      <td align="left"><strong>Test Case ID</strong></td>
      <td align="left"><nobr>TP-PKG-002</nobr></td>
    </tr>
    <tr>
      <td align="left"><strong>Packaging Ref</strong></td>
      <td align="left"><nobr>TBD</nobr></td>
      <td align="left"><strong>Orchestration Ref</strong></td>
      <td align="left"><nobr>TBD</nobr></td>
    </tr>
    <tr>
      <td align="left"><strong>Evidence</strong></td>
      <td align="left" colspan="3">Client-access/server-host decomposition in progress</td>
    </tr>
  </tbody>
</table>

</details>

**SRS requirement titles (for maintenance):** see [§4 Functional requirements](./srs.md#4-functional-requirements "4. Functional Requirements") and NFR sections in [`srs.md`](srs.md "Srs"). **HLA component definitions:** [`hla.md`](hla.md "Hla") **[§6](./hla.md#6-major-components "6. Major Components")**.

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

# 4. Boundary Traceability

OCR and derived text quality are bounded in SRS [§6](./srs.md#6-deterministicprobabilistic-requirements "6. Deterministic–Probabilistic Requirements"). Initial mapping (see HLA [§5](./hla.md#5-deterministicprobabilistic-boundary "5. Deterministic–Probabilistic Boundary") and [§6](./hla.md#6-major-components "6. Major Components")):

### 4.1 Boundary Items

<details>
  <summary><nobr>[FR-023](./srs.md#fr-023--ocr-for-searchability "FR-023")</nobr> — <nobr>Planned</nobr></summary>

<table>
  <tbody>
    <tr>
      <td align="left"><strong>Boundary</strong></td>
      <td align="left"><nobr>[HLA-BOUND-OCR](./hla.md#5-deterministicprobabilistic-boundary "HLA-BOUND-OCR")</nobr></td>
      <td align="left"><strong>Harness</strong></td>
      <td align="left"><nobr>TBD</nobr></td>
    </tr>
    <tr>
      <td align="left"><strong>Fallback</strong></td>
      <td align="left"><nobr>[FR-009](./srs.md#fr-009--keywords-when-indexing-blocked "FR-009")</nobr></td>
      <td align="left"><strong>Status</strong></td>
      <td align="left"><nobr>Planned</nobr></td>
    </tr>
    <tr>
      <td align="left"><strong>Containment</strong></td>
      <td align="left" colspan="3">Ingest/reindex invokes <strong>HLA-OCR</strong>; no silent success (SRS §6)</td>
    </tr>
    <tr>
      <td align="left"><strong>Observability</strong></td>
      <td align="left" colspan="3">Log fields / error codes (DD)</td>
    </tr>
    <tr>
      <td align="left"><strong>Drift Validation</strong></td>
      <td align="left" colspan="3">Test Plan OCR tolerance</td>
    </tr>
  </tbody>
</table>

</details>


Probabilistic behavior SHALL NOT exist outside RTM coverage.

Untracked boundaries are governance violations.

---

# 5. NFR Traceability

Each NFR SHALL explicitly map to architectural mechanism, design enforcement, test validation, and packaging consideration. Rows below mirror §3 for NFR IDs; expand mechanisms when HLA exists.

### 5.1 NFR Items

<details>
  <summary><nobr>[NFR-001](./srs.md#nfr-001--corpus-scale-qualitative "NFR-001")</nobr> — <nobr>Planned</nobr></summary>

<table>
  <tbody>
    <tr>
      <td align="left"><strong>DD Ref(s)</strong></td>
      <td align="left"><nobr>[DD §4.3](./dd.md#43-hla-server-host "DD §4.3")</nobr>, <nobr>[DD §4.4](./dd.md#44-hla-domain "DD §4.4")</nobr>, <nobr>[DD §4.6](./dd.md#46-hla-search "DD §4.6")</nobr></td>
      <td align="left"><strong>Status</strong></td>
      <td align="left"><nobr>Planned</nobr></td>
    </tr>
    <tr>
      <td align="left"><strong>Test</strong></td>
      <td align="left"><nobr>TP-PKG-001, TP-PKG-002</nobr></td>
      <td align="left"><strong>Pkg Impact</strong></td>
      <td align="left"><nobr>TBD</nobr></td>
    </tr>
    <tr>
      <td align="left"><strong>Arch Mechanism</strong></td>
      <td align="left" colspan="3">Catalog/index partition; optional scaled API tier (HLA [§8](./hla.md#8-non-functional-enforcement "8. Non-Functional Enforcement"))</td>
    </tr>
  </tbody>
</table>

</details>

<details>
  <summary><nobr>[NFR-002](./srs.md#nfr-002--server-side-enforcement "NFR-002")</nobr> — <nobr>Planned</nobr></summary>

<table>
  <tbody>
    <tr>
      <td align="left"><strong>DD Ref(s)</strong></td>
      <td align="left"><nobr>[DD §4.3](./dd.md#43-hla-server-host "DD §4.3")</nobr>, <nobr>[DD §4.8](./dd.md#48-hla-security "DD §4.8")</nobr></td>
      <td align="left"><strong>Status</strong></td>
      <td align="left"><nobr>Planned</nobr></td>
    </tr>
    <tr>
      <td align="left"><strong>Test</strong></td>
      <td align="left"><nobr>TBD</nobr></td>
      <td align="left"><strong>Pkg Impact</strong></td>
      <td align="left"><nobr>TBD</nobr></td>
    </tr>
    <tr>
      <td align="left"><strong>Arch Mechanism</strong></td>
      <td align="left" colspan="3">Server-side authorization on sensitive paths (**HLA-SECURITY**)</td>
    </tr>
  </tbody>
</table>

</details>

<details>
  <summary><nobr>[NFR-003](./srs.md#nfr-003--licensing-and-notices "NFR-003")</nobr> — <nobr>Planned</nobr></summary>

<table>
  <tbody>
    <tr>
      <td align="left"><strong>DD Ref(s)</strong></td>
      <td align="left"><nobr>[DD §4.1](./dd.md#41-hla-shell "DD §4.1")</nobr>, <nobr>[DD §4.12](./dd.md#412-hla-release "DD §4.12")</nobr></td>
      <td align="left"><strong>Status</strong></td>
      <td align="left"><nobr>Planned</nobr></td>
    </tr>
    <tr>
      <td align="left"><strong>Test</strong></td>
      <td align="left"><nobr>TBD</nobr></td>
      <td align="left"><strong>Pkg Impact</strong></td>
      <td align="left"><nobr>TBD</nobr></td>
    </tr>
    <tr>
      <td align="left"><strong>Arch Mechanism</strong></td>
      <td align="left" colspan="3">**HLA-RELEASE** + in-app notices</td>
    </tr>
  </tbody>
</table>

</details>

<details>
  <summary><nobr>[NFR-004](./srs.md#nfr-004--operator-documentation "NFR-004")</nobr> — <nobr>Planned</nobr></summary>

<table>
  <tbody>
    <tr>
      <td align="left"><strong>DD Ref(s)</strong></td>
      <td align="left"><nobr>[DD §4.1](./dd.md#41-hla-shell "DD §4.1")</nobr>, <nobr>[DD §4.3](./dd.md#43-hla-server-host "DD §4.3")</nobr>, <nobr>[DD §4.12](./dd.md#412-hla-release "DD §4.12")</nobr></td>
      <td align="left"><strong>Status</strong></td>
      <td align="left"><nobr>Planned</nobr></td>
    </tr>
    <tr>
      <td align="left"><strong>Test</strong></td>
      <td align="left"><nobr>TP-PKG-001, TP-PKG-002</nobr></td>
      <td align="left"><strong>Pkg Impact</strong></td>
      <td align="left"><nobr>TBD</nobr></td>
    </tr>
    <tr>
      <td align="left"><strong>Arch Mechanism</strong></td>
      <td align="left" colspan="3">Operator docs surfaces; server admin for log config (HLA [§8](./hla.md#8-non-functional-enforcement "8. Non-Functional Enforcement"))</td>
    </tr>
  </tbody>
</table>

</details>

<details>
  <summary><nobr>[NFR-005](./srs.md#nfr-005--honest-policy-communication "NFR-005")</nobr> — <nobr>Planned</nobr></summary>

<table>
  <tbody>
    <tr>
      <td align="left"><strong>DD Ref(s)</strong></td>
      <td align="left"><nobr>[DD §4.1](./dd.md#41-hla-shell "DD §4.1")</nobr>, <nobr>[DD §4.3](./dd.md#43-hla-server-host "DD §4.3")</nobr>, <nobr>[DD §4.6](./dd.md#46-hla-search "DD §4.6")</nobr>, <nobr>[DD §4.12](./dd.md#412-hla-release "DD §4.12")</nobr></td>
      <td align="left"><strong>Status</strong></td>
      <td align="left"><nobr>Planned</nobr></td>
    </tr>
    <tr>
      <td align="left"><strong>Test</strong></td>
      <td align="left"><nobr>TBD</nobr></td>
      <td align="left"><strong>Pkg Impact</strong></td>
      <td align="left"><nobr>TBD</nobr></td>
    </tr>
    <tr>
      <td align="left"><strong>Arch Mechanism</strong></td>
      <td align="left" colspan="3">Shell + server honest policy alignment</td>
    </tr>
  </tbody>
</table>

</details>

<details>
  <summary><nobr>[NFR-006](./srs.md#nfr-006--themed-shell-contrast "NFR-006")</nobr> — <nobr>Planned</nobr></summary>

<table>
  <tbody>
    <tr>
      <td align="left"><strong>DD Ref(s)</strong></td>
      <td align="left"><nobr>[DD §4.1](./dd.md#41-hla-shell "DD §4.1")</nobr></td>
      <td align="left"><strong>Status</strong></td>
      <td align="left"><nobr>Planned</nobr></td>
    </tr>
    <tr>
      <td align="left"><strong>Test</strong></td>
      <td align="left"><nobr>TBD</nobr></td>
      <td align="left"><strong>Pkg Impact</strong></td>
      <td align="left"><nobr>TBD</nobr></td>
    </tr>
    <tr>
      <td align="left"><strong>Arch Mechanism</strong></td>
      <td align="left" colspan="3">Themed shell WCAG AA (**HLA-SHELL**)</td>
    </tr>
  </tbody>
</table>

</details>

<details>
  <summary><nobr>[NFR-007](./srs.md#nfr-007--end-user-documentation-and-help "NFR-007")</nobr> — <nobr>Planned</nobr></summary>

<table>
  <tbody>
    <tr>
      <td align="left"><strong>DD Ref(s)</strong></td>
      <td align="left"><nobr>[DD §4.1](./dd.md#41-hla-shell "DD §4.1")</nobr></td>
      <td align="left"><strong>Status</strong></td>
      <td align="left"><nobr>Planned</nobr></td>
    </tr>
    <tr>
      <td align="left"><strong>Test</strong></td>
      <td align="left"><nobr>TP-NFR-003</nobr></td>
      <td align="left"><strong>Pkg Impact</strong></td>
      <td align="left"><nobr>TBD</nobr></td>
    </tr>
    <tr>
      <td align="left"><strong>Arch Mechanism</strong></td>
      <td align="left" colspan="3">Help / manuals via **HLA-SHELL**</td>
    </tr>
  </tbody>
</table>

</details>

<details>
  <summary><nobr>[NFR-008](./srs.md#nfr-008--logging-privacy-and-jurisdictional-readiness "NFR-008")</nobr> — <nobr>Planned</nobr></summary>

<table>
  <tbody>
    <tr>
      <td align="left"><strong>DD Ref(s)</strong></td>
      <td align="left"><nobr>[DD §4.3](./dd.md#43-hla-server-host "DD §4.3")</nobr>, <nobr>[DD §4.8](./dd.md#48-hla-security "DD §4.8")</nobr>, <nobr>[DD §4.10](./dd.md#410-hla-audit "DD §4.10")</nobr>, <nobr>[DD §4.11](./dd.md#411-hla-obslog "DD §4.11")</nobr></td>
      <td align="left"><strong>Status</strong></td>
      <td align="left"><nobr>Planned</nobr></td>
    </tr>
    <tr>
      <td align="left"><strong>Test</strong></td>
      <td align="left"><nobr>TP-OPS-002</nobr></td>
      <td align="left"><strong>Pkg Impact</strong></td>
      <td align="left"><nobr>TBD</nobr></td>
    </tr>
    <tr>
      <td align="left"><strong>Arch Mechanism</strong></td>
      <td align="left" colspan="3">**HLA-AUDIT** vs **HLA-OBSLOG**; server-host/security minimized event production; jurisdictional privacy posture</td>
    </tr>
  </tbody>
</table>

</details>

<details>
  <summary><nobr>[NFR-009](./srs.md#nfr-009--transport-security-remote-access "NFR-009")</nobr> — <nobr>Planned</nobr></summary>

<table>
  <tbody>
    <tr>
      <td align="left"><strong>DD Ref(s)</strong></td>
      <td align="left"><nobr>[DD §4.2](./dd.md#42-hla-client-access "DD §4.2")</nobr>, <nobr>[DD §4.3](./dd.md#43-hla-server-host "DD §4.3")</nobr></td>
      <td align="left"><strong>Status</strong></td>
      <td align="left"><nobr>Planned</nobr></td>
    </tr>
    <tr>
      <td align="left"><strong>Test</strong></td>
      <td align="left"><nobr>TP-PKG-002</nobr></td>
      <td align="left"><strong>Pkg Impact</strong></td>
      <td align="left"><nobr>TBD</nobr></td>
    </tr>
    <tr>
      <td align="left"><strong>Arch Mechanism</strong></td>
      <td align="left" colspan="3">TLS remote; loopback exception (**HLA-CLIENT-ACCESS**, **HLA-SERVER-HOST**)</td>
    </tr>
  </tbody>
</table>

</details>


Assumed NFR compliance is prohibited.

---

# 6. Bidirectional Rules

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

### 8.1 Change Entries

<details>
  <summary><nobr>2026-04-03</nobr> — N/A</summary>

<table>
  <tbody>
    <tr>
      <td align="left"><strong>Rollback</strong></td>
      <td align="left">N/A</td>
      <td align="left"><strong>Impacted IDs</strong></td>
      <td align="left">All</td>
    </tr>
    <tr>
      <td align="left"><strong>Summary</strong></td>
      <td align="left" colspan="3">Initial RTM v0.1: full FR-001–FR-041 and NFR-001–NFR-009 rows; downstream TBD</td>
    </tr>
  </tbody>
</table>

</details>

<details>
  <summary><nobr>2026-04-06</nobr> — N/A</summary>

<table>
  <tbody>
    <tr>
      <td align="left"><strong>Rollback</strong></td>
      <td align="left">N/A</td>
      <td align="left"><strong>Impacted IDs</strong></td>
      <td align="left">—</td>
    </tr>
    <tr>
      <td align="left"><strong>Summary</strong></td>
      <td align="left" colspan="3">SRS v0.9 <strong>Approved</strong>; Architecture phase authorized; §1 authority rows updated</td>
    </tr>
  </tbody>
</table>

</details>

<details>
  <summary><nobr>2026-04-06</nobr> — N/A</summary>

<table>
  <tbody>
    <tr>
      <td align="left"><strong>Rollback</strong></td>
      <td align="left">N/A</td>
      <td align="left"><strong>Impacted IDs</strong></td>
      <td align="left">FR-001–FR-041, NFR-001–NFR-009</td>
    </tr>
    <tr>
      <td align="left"><strong>Summary</strong></td>
      <td align="left" colspan="3">Historical <strong>HLA</strong> v0.1 <strong>draft</strong>; §3 HLA Component ID column populated; §4–§5 updated; superseded by current HLA v0.1.2</td>
    </tr>
  </tbody>
</table>

</details>

<details>
  <summary><nobr>2026-04-25</nobr> — N/A</summary>

<table>
  <tbody>
    <tr>
      <td align="left"><strong>Rollback</strong></td>
      <td align="left">N/A</td>
      <td align="left"><strong>Impacted IDs</strong></td>
      <td align="left">FR-028, FR-029, NFR-008</td>
    </tr>
    <tr>
      <td align="left"><strong>Summary</strong></td>
      <td align="left" colspan="3">DD server-host operational/diagnostic logging producer contract and privacy minimization constraints added</td>
    </tr>
  </tbody>
</table>

</details>

<details>
  <summary><nobr>2026-04-06</nobr> — N/A</summary>

<table>
  <tbody>
    <tr>
      <td align="left"><strong>Rollback</strong></td>
      <td align="left">N/A</td>
      <td align="left"><strong>Impacted IDs</strong></td>
      <td align="left">—</td>
    </tr>
    <tr>
      <td align="left"><strong>Summary</strong></td>
      <td align="left" colspan="3">Historical <strong>HLA</strong> v0.1.1 — SRS <code>srs.md#…</code> cross-links for GitHub; metadata only; superseded by current HLA v0.1.2</td>
    </tr>
  </tbody>
</table>

</details>

<details>
  <summary><nobr>2026-04-25</nobr> — N/A</summary>

<table>
  <tbody>
    <tr>
      <td align="left"><strong>Rollback</strong></td>
      <td align="left">N/A</td>
      <td align="left"><strong>Impacted IDs</strong></td>
      <td align="left">—</td>
    </tr>
    <tr>
      <td align="left"><strong>Summary</strong></td>
      <td align="left" colspan="3"><strong>HLA</strong> v0.1.2 — decision-log conformance reference and additional Mermaid diagrams; metadata only</td>
    </tr>
  </tbody>
</table>

</details>

<details>
  <summary><nobr>2026-04-25</nobr> — N/A</summary>

<table>
  <tbody>
    <tr>
      <td align="left"><strong>Rollback</strong></td>
      <td align="left">N/A</td>
      <td align="left"><strong>Impacted IDs</strong></td>
      <td align="left">All HLA-mapped FR/NFR rows</td>
    </tr>
    <tr>
      <td align="left"><strong>Summary</strong></td>
      <td align="left" colspan="3"><strong>HLA</strong> v0.1.2 <strong>Approved</strong>; Detailed Design phase authorized</td>
    </tr>
  </tbody>
</table>

</details>

<details>
  <summary><nobr>2026-04-25</nobr> — N/A</summary>

<table>
  <tbody>
    <tr>
      <td align="left"><strong>Rollback</strong></td>
      <td align="left">N/A</td>
      <td align="left"><strong>Impacted IDs</strong></td>
      <td align="left">—</td>
    </tr>
    <tr>
      <td align="left"><strong>Summary</strong></td>
      <td align="left" colspan="3"><strong>DD</strong> v0.1 draft scaffold created; DD columns remain TBD until component decomposition lands</td>
    </tr>
  </tbody>
</table>

</details>

<details>
  <summary><nobr>2026-04-25</nobr> — N/A</summary>

<table>
  <tbody>
    <tr>
      <td align="left"><strong>Rollback</strong></td>
      <td align="left">N/A</td>
      <td align="left"><strong>Impacted IDs</strong></td>
      <td align="left">FR-013-FR-015, NFR-001, NFR-002, NFR-004, NFR-005, NFR-009</td>
    </tr>
    <tr>
      <td align="left"><strong>Summary</strong></td>
      <td align="left" colspan="3">Began <strong>HLA-SERVER-HOST</strong> decomposition in DD §4.3; updated related DD Artifact references</td>
    </tr>
  </tbody>
</table>

</details>

<details>
  <summary><nobr>2026-04-25</nobr> — N/A</summary>

<table>
  <tbody>
    <tr>
      <td align="left"><strong>Rollback</strong></td>
      <td align="left">N/A</td>
      <td align="left"><strong>Impacted IDs</strong></td>
      <td align="left">FR-004, FR-013, FR-016-FR-018, FR-027, FR-031-FR-035, NFR-002, NFR-008</td>
    </tr>
    <tr>
      <td align="left"><strong>Summary</strong></td>
      <td align="left" colspan="3">Began <strong>HLA-SECURITY</strong> decomposition in DD §4.8; added auth/RBAC/tenant/session/password/throttle/bootstrap baseline</td>
    </tr>
  </tbody>
</table>

</details>

<details>
  <summary><nobr>2026-04-26</nobr> — N/A</summary>

<table>
  <tbody>
    <tr>
      <td align="left"><strong>Rollback</strong></td>
      <td align="left">N/A</td>
      <td align="left"><strong>Impacted IDs</strong></td>
      <td align="left">FR-001-FR-041, NFR-001-NFR-009</td>
    </tr>
    <tr>
      <td align="left"><strong>Summary</strong></td>
      <td align="left" colspan="3">DD component decomposition expanded to §4.1–§4.12 initial baselines; RTM DD Artifact mappings refreshed for all FR/NFR rows</td>
    </tr>
  </tbody>
</table>

</details>


---

# 9. Coverage Checklist

Before phase advancement, confirm:

- 100% FR coverage to design  
- 100% NFR coverage to architecture  
- 100% implementation traceability  
- 100% requirement-to-test coverage  
- Provisional DD test IDs (for example `SEC-*`) are remapped to canonical test-plan IDs (for example `TP-*`) with one-to-one trace notes before test phase closure  
- Deterministic–probabilistic boundaries mapped (if applicable)  
- Packaging traceability complete  
- Orchestration traceability complete  
- No orphan artifacts  

Failure blocks advancement.

---

# 10. Provisional-to-Canonical Test ID Mapping

Use this table to track one-to-one remapping from DD provisional IDs to canonical **`TP-*`** IDs in the approved [`test-plan.md`](test-plan.md "Test Plan") (seed catalog **§5.1**).

| DD Provisional ID | Canonical Test Plan ID | Mapping Status | Owner | Target Date | Notes |
| --- | --- | --- | --- | --- | --- |
| `SEC-AUTH-001` | `TP-AUTH-001` | `Mapped` | `Security Lead` | `2026-04-26` | Trace target: `FR-016` |
| `SEC-AUTH-002` | `TP-AUTH-002` | `Mapped` | `Security Lead` | `2026-04-26` | Trace target: `FR-016` |
| `SEC-AUTH-003` | `TP-AUTH-003` | `Mapped` | `Security Lead` | `2026-04-26` | Trace targets: `FR-016`, `NFR-002` |
| `SEC-JWKS-001` | `TP-AUTH-007` | `Mapped` | `Security Lead` | `2026-04-26` | Trace target: `FR-035` |
| `SEC-JWKS-002` | `TP-AUTH-008` | `Mapped` | `Security Lead` | `2026-04-26` | Trace target: `FR-035` |
| `SEC-JWKS-003` | `TP-AUTH-007` | `Mapped` | `Security Lead` | `2026-04-26` | Trace target: `FR-035` |
| `SEC-JWKS-004` | `TP-AUTH-008` | `Mapped` | `Security Lead` | `2026-04-26` | Trace target: `FR-035` |
| `SEC-REFRESH-001` | `TP-AUTH-005` | `Mapped` | `Security Lead` | `2026-04-26` | Trace target: `FR-035` |
| `SEC-REFRESH-002` | `TP-AUTH-005` | `Mapped` | `Security Lead` | `2026-04-26` | Trace target: `FR-035` |
| `SEC-PASS-001` | `TP-AUTH-002` | `Mapped` | `Security Lead` | `2026-04-26` | Trace target: `FR-027` |
| `SEC-PASS-002` | `TP-AUTH-006` | `Mapped` | `Security Lead` | `2026-04-26` | Trace target: `FR-027` |
| `SEC-PASS-003` | `TP-AUTH-006` | `Mapped` | `Security Lead` | `2026-04-26` | Trace target: `FR-033` |
| `SEC-STATE-001` | `TP-ADMIN-003` | `Mapped` | `Security Lead` | `2026-04-26` | Trace target: `FR-018` |
| `SEC-RBAC-001` | `TP-ADMIN-003` | `Mapped` | `Security Lead` | `2026-04-26` | Trace targets: `FR-017`, `FR-018`, `FR-031`, `NFR-002` |
| `SEC-ADMIN-001` | `TP-ADMIN-001` | `Mapped` | `Security Lead` | `2026-04-26` | Trace target: `FR-031` |
| `SEC-BOOT-001` | `TP-ADMIN-002` | `Mapped` | `Security Lead` | `2026-04-26` | Trace target: `FR-032` |
| `SEC-THROTTLE-001` | `TP-AUTH-004` | `Mapped` | `Security Lead` | `2026-04-26` | Trace target: `FR-034` |
| `SEC-LOG-001` | `TP-OPS-002` | `Mapped` | `QA Lead` | `2026-04-26` | Trace target: `NFR-008` |

Mapping status conventions:

- `Pending`: no canonical test-plan ID assigned yet
- `Mapped`: one-to-one mapping to a canonical test-plan ID is complete
- `Split`: one provisional ID maps to multiple canonical test-plan IDs
- `Retired`: provisional ID no longer maps to active test-plan scope; rationale captured in `Notes`

---

# 11. Release-State Snapshot

Before release authorization:

- RTM Version incremented  
- Validation status updated to release state  
- Evidence references finalized  
- Packaging reference aligned to artifact  
- Orchestration reference aligned to build  
- Documentation version aligned  

Release without finalized RTM snapshot is prohibited.

---

# 12. Approval

The RTM **document** is **Approved** as the traceability baseline; per-row **Validation Status** and **Evidence** cells advance with implementation and test execution.

Approved By: Charles McKnight  
Role: Maintainer  
Date (YYYY-MM-DD): 2026-04-28  
Version Incremented: No  

RTM validation required before:

- Implementation completion  
- Test phase closure  
- Packaging approval  
- Release authorization  

---

End of Requirements Traceability Matrix

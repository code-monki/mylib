# Discussion and Decision Log

**Project Name:** MyLib  
**Maintainer:** Charles McKnight  
**RTM Version Reference:** [`../rtm.md`](../rtm.md "Rtm") v0.1 approved  
**Lifecycle Authority:** [`../LIFECYCLE.md`](../LIFECYCLE.md "Lifecycle")  

Timestamped record of **discussions**, **decisions**, **technology choices**, framework/library choices, and explicit **deferrals**.  
**Newest entries first.** Append new blocks after updating the “Last updated” line below.

**Last updated:** 2026-04-29 (M1-M7 complete; release checklist/evidence + deferred diagram cleanup carryover) UTC  

**Not legal advice** where legal topics appear; see [`open-source-license.md`](open-source-license.md "Open Source License").

**Decision-log conformance:** New structural entries SHALL follow the active decision-log template in [`../_templates/project/decision-log.md`](../_templates/project/decision-log.md "Decision Log Template"). Significant decisions include architecture choices, design choices, framework/library selections, packaging choices, orchestration choices, risk-bearing deferrals, changes to deterministic-probabilistic boundaries, and changes to NFR posture. Routine implementation details do not require full decision entries unless they affect these areas.

**Archival note:** Older entries before this conformance rule may use summary format and may cite superseded FR numbers from SRS revisions prior to v0.6; the current [`../srs.md`](../srs.md "Srs") section headers are authoritative for IDs. When an older summary entry is reused as decision authority, normalize it to the template or create a superseding decision entry.

---

## 2026-04-29 — Release closeout artifacts and deferred diagram cleanup reaffirmed

**Summary:** Added release-candidate closeout artifacts for post-M7 readiness: [`../release-checklist.md`](../release-checklist.md "Release Checklist") and [`../release-evidence.md`](../release-evidence.md "Release Evidence"), plus rollback runbook/drill alignment through release metadata checks. Reaffirmed manual Omnigraffle diagram refresh as intentionally deferred end-of-cycle cleanup and non-blocking for release-candidate readiness.

**Documentation:** [`../README.md`](../README.md "Readme"), [`../LIFECYCLE.md`](../LIFECYCLE.md "Lifecycle"), [`../release-checklist.md`](../release-checklist.md "Release Checklist"), [`../release-evidence.md`](../release-evidence.md "Release Evidence"), [`discussion-log.md`](discussion-log.md "Discussion Log").

---

## 2026-04-28 — Shell UI/UX baseline: navigation, screens, flows, QML map

**Summary:** Expanded [`../shell-ui-ux-design.md`](../shell-ui-ux-design.md "Shell UI/UX Design") with v1 **sidebar + top search strip + content stack** IA, default **Library** landing, **Import** placement, full **S-01–S-12** purposes, detailed flows **§6.1–§6.6** (login, search→open, import/duplicate, metadata conflict, admin, rebuild), QML file naming sketch **§8**, theme/accessibility hooks **§9**, terminology **§10**, decisions/open items **§11**; adjusted **§1** gate to require wireframes for **S-01/S-03/S-05** (or **§11** waiver). **Status** line reflects **baseline text without pixels**.

**Documentation:** [`../shell-ui-ux-design.md`](../shell-ui-ux-design.md "Shell UI/UX Design"), [`discussion-log.md`](discussion-log.md "Discussion Log").

---

## 2026-04-28 — Seeded iterative Shell UI/UX design document (HLA-SHELL)

**Summary:** Added [`../shell-ui-ux-design.md`](../shell-ui-ux-design.md "Shell UI/UX Design") as a **living, non-template** UI/UX record (screen inventory S-xx, critical flows, wireframe log, open questions) subordinate to DD **§4.1**, with an explicit **implementation gate** before **HLA-SHELL** UI work. Linked from DD **§4.1**, [`../README.md`](../README.md "Readme"), and **LIFECYCLE.md** §6.

**Documentation:** [`../shell-ui-ux-design.md`](../shell-ui-ux-design.md "Shell UI/UX Design"), [`../dd.md`](../dd.md "Dd"), [`../LIFECYCLE.md`](../LIFECYCLE.md "Lifecycle"), [`discussion-log.md`](discussion-log.md "Discussion Log").

---

## 2026-04-28 — Full documentation set synchronized (approved DD/TP/RTM baseline)

**Summary:** Brought **LIFECYCLE.md** §6, **README.md**, **project-primer.md**, **SRS** §15–§16 + **Last revised**, **DD** (§4 intro, §8, §10 traceability, §13 gate, §4.8.10 ID mapping, approval date, global `TP-*` pointer), **RTM** §10 intro + §12 Approval + footer, and **HLA** (authority §1, DD/Test Plan header refs) into alignment with **Approved** **DD** / **Test Plan** / **RTM** v0.1 (2026-04-28). No SRS requirement narrative changed except traceability metadata.

**Documentation:** [`../LIFECYCLE.md`](../LIFECYCLE.md "Lifecycle"), [`../README.md`](../README.md "Readme"), [`../_process/project-primer.md`](../_process/project-primer.md "Project Primer"), [`../srs.md`](../srs.md "Srs"), [`../dd.md`](../dd.md "Dd"), [`../rtm.md`](../rtm.md "Rtm"), [`../hla.md`](../hla.md "Hla"), [`discussion-log.md`](discussion-log.md "Discussion Log").

---

## 2026-04-28 — Test Plan and RTM approved; DD §5 contract alignment

**Summary:** Set [`../test-plan.md`](../test-plan.md "Test Plan") to **Approved** (2026-04-28): **§2** now cites DD **`§5.1.3`**, **`§5.2`**, **`§5.3.8`–`§5.3.19`**; **§4.3**, **§8**, **§12**, **§14** clarification, **Approval** filled. Set [`../rtm.md`](../rtm.md "Rtm") to **Approved**, added **§2.1** DD §5 cross-cutting layer, refreshed authority block and version references. Synced [`../dd.md`](../dd.md "Dd") RTM reference; [`../srs.md`](../srs.md "Srs") / [`../hla.md`](../hla.md "Hla") headers updated only for RTM/DD/Test Plan version-reference consistency (no requirement text changes).

**Documentation:** [`../test-plan.md`](../test-plan.md "Test Plan"), [`../rtm.md`](../rtm.md "Rtm"), [`../dd.md`](../dd.md "Dd"), [`../srs.md`](../srs.md "Srs"), [`../hla.md`](../hla.md "Hla"), [`discussion-log.md`](discussion-log.md "Discussion Log").

---

## 2026-04-28 — DD §5.1.3 logical persistence schema for identity/RBAC/tenant

**Summary:** Documented that **§5.3.12** tables describe API/policy vocabulary, not SQL; added **§5.1.3** with logical tables `user_account`, `user_role`, `tenant`, `tenant_membership`, column baselines, PK rules, permission-resolution posture (code-expanded from stored roles per **§5.3.12**), and cross-links to session/JWT durability (**§4.8.5**). Updated **§5.3.12** intro and **§4.13** format-baseline row to reference **§5.1.3**.

**Documentation:** [`../dd.md`](../dd.md "Dd"), [`discussion-log.md`](discussion-log.md "Discussion Log").

---

## 2026-04-28 — DD §5.3 completed REST wire schemas (auth refresh/logout, search rebuild, OCR reprocess, ops/release/JWKS, duplicate decision, storage remove, bootstrap) and C++ §5.3.19

**Summary:** Finished parity between **§5.3** endpoint tables and concrete JSON: expanded **§5.3.8** with **`auth/refresh`** and **`auth/logout`**; added **§5.3.13**–**§5.3.18** for rebuild/reprocess, **`GET /ops/health`**, **`GET /release/metadata`**, **`GET /security/jwks`**, ingest **`duplicate-decision`**, **`POST /storage/remove`**, and **`auth/bootstrap/*`**; indexed **§5.3.1**/**§5.3.4**/**§5.3.5** for bootstrap, duplicate-decision, and remove routes; extended **§5.3.19** C++ with **`IAuthService`** bootstrap methods, **`IIngestService::submitDuplicateDecision`**, **`IStorageService::removeReference`**, and **`IOpsReleaseService`**. **§4.13** format baseline row points at **§5.3.8**–**§5.3.18** and **§5.3.19**.

**Documentation:** [`../dd.md`](../dd.md "Dd"), [`discussion-log.md`](discussion-log.md "Discussion Log").

---

## 2026-04-28 — DD §5.3 RBAC, tenant, admin JSON schemas and C++ admin/security interface

**Summary:** Closed the gap where RBAC was only narrative (**§4.8.6**) and admin routes lacked wire examples: added **§5.3.12** with role/permission IDs, default role-to-permission expansion, validated access-JWT claim shape, `GET /api/v1/auth/session` payload, `rejected_forbidden` authorization detail schema, and admin user **POST**/**PATCH**/**GET** JSON; indexed **§5.3.1** and **§5.3.6** with `GET /auth/session` and `GET /admin/users/{user_id}`; extended later §5.3 C++ baseline (`RequestContext` roles and **`IAdminSecurityService`**; subsequently consolidated under **§5.3.19**). **§4.13** format baseline row updated accordingly.

**Documentation:** [`../dd.md`](../dd.md "Dd"), [`discussion-log.md`](discussion-log.md "Discussion Log").

---

## 2026-04-28 — DD §5.3 catalog, ingest, storage concrete schemas and C++ interfaces

**Summary:** Extended [`../dd.md`](../dd.md "Dd") **§5.3** so catalog, ingest, and storage align with the same wire-level depth as auth/search/OCR: query-parameter table and JSON examples for catalog list/patch/delete, ingest import and job status, storage resolve/relink/open; extended the **§5.3** C++ interface baseline with `ICatalogService`, `IIngestService`, and `IStorageService` virtual interfaces alongside existing auth/search shapes.

**Documentation:** [`../dd.md`](../dd.md "Dd"), [`discussion-log.md`](discussion-log.md "Discussion Log").

---

## 2026-04-28 — Deepened DD with concrete API/protocol/interface specifications

**Summary:** Addressed DD depth gap by extending [`../dd.md`](../dd.md "Dd") **§5.3** with concrete implementation-facing interface detail: HTTP/S packet/header model, canonical response envelope packet schema, concrete JSON request/response payload examples for auth/search/OCR flows, and C++ service interface signature baselines for auth/search services. Updated DD-carried format decision wording to reflect that per-endpoint schema/detail is now defined at DD level, leaving only OpenAPI generation and final DTO class realization as implementation-phase refinements.

**Documentation:** [`../dd.md`](../dd.md "Dd"), [`discussion-log.md`](discussion-log.md "Discussion Log").

---

## 2026-04-28 — Normalized DD/TP header consistency metadata

**Summary:** Per review pass, normalized header metadata consistency in [`../dd.md`](../dd.md "Dd") and [`../test-plan.md`](../test-plan.md "Test Plan"): set DD header status to **Approved** with current date alignment, corrected DD approval footer wording from draft-baseline phrasing, and aligned Test Plan reference headers to explicitly mark SRS/HLA/DD authority documents as **Approved**.

**Documentation:** [`../dd.md`](../dd.md "Dd"), [`../test-plan.md`](../test-plan.md "Test Plan"), [`discussion-log.md`](discussion-log.md "Discussion Log").

---

## 2026-04-28 — Added Qt Quick bridge implementation guidance

**Summary:** Extended [`../dd.md`](../dd.md "Dd") **§4.1** with implementation guidance for the selected Qt Quick/QML stack: recommended `QObject` C++ bridge pattern, UI DTO mapping boundaries, intent-level signal/slot contracts, UI-thread isolation, normalized error/status mapping, and testability expectations that keep policy authority out of QML.

**Documentation:** [`../dd.md`](../dd.md "Dd"), [`discussion-log.md`](discussion-log.md "Discussion Log").

---

## 2026-04-28 — Refined UI stack to Qt Quick/QML with C++ bridge guardrails

**Summary:** Updated [`../dd.md`](../dd.md "Dd") **§4.1** to refine the UI stack decision from generic Qt to **Qt Quick/QML + C++ bridge**, added explicit guardrails that keep security/business authority outside QML, and extended shell testing/risk language to enforce boundary discipline. Updated [`../hla.md`](../hla.md "Hla") DD-carried UI stack row to record this as resolved in DD, and extended [`../test-plan.md`](../test-plan.md "Test Plan") with `TP-NFR-004` to validate QML presentation non-authority and preserved server/C++ security enforcement.

**Documentation:** [`../dd.md`](../dd.md "Dd"), [`../hla.md`](../hla.md "Hla"), [`../test-plan.md`](../test-plan.md "Test Plan"), [`discussion-log.md`](discussion-log.md "Discussion Log").

---

## 2026-04-26 — Completed OPS/NFR executable specs and TP quick-map appendix

**Summary:** Finalized the next executable-spec expansion in [`../test-plan.md`](../test-plan.md "Test Plan") by adding `OPS` and `NFR` suite specifications (preconditions, steps, expected outcomes, evidence requirements) and appended a compact `TP-*` to requirement quick-map appendix to accelerate review and traceability verification.

**Documentation:** [`../test-plan.md`](../test-plan.md "Test Plan"), [`discussion-log.md`](discussion-log.md "Discussion Log").

---

## 2026-04-26 — Expanded executable specs for SEARCH/INGEST/STORAGE/ADMIN

**Summary:** Extended [`../test-plan.md`](../test-plan.md "Test Plan") executable specification section to include `SEARCH`, `INGEST`, `STORAGE`, and `ADMIN` high-priority suites with concrete preconditions, step flows, expected outcomes, and evidence requirements, bringing the draft closer to review-ready execution planning.

**Documentation:** [`../test-plan.md`](../test-plan.md "Test Plan"), [`discussion-log.md`](discussion-log.md "Discussion Log").

---

## 2026-04-26 — Added executable AUTH/OCR/PKG test specifications

**Summary:** Expanded [`../test-plan.md`](../test-plan.md "Test Plan") with executable high-risk suite specifications in **§5.2** for `AUTH`, `OCR`, and `PKG` families, including preconditions, step sequences, expected outcomes, and required evidence artifacts for immediate test authoring and implementation-parallel validation work.

**Documentation:** [`../test-plan.md`](../test-plan.md "Test Plan"), [`discussion-log.md`](discussion-log.md "Discussion Log").

---

## 2026-04-26 — Seeded canonical TP IDs and mapped SEC provisional IDs

**Summary:** Expanded [`../test-plan.md`](../test-plan.md "Test Plan") with an initial canonical test case catalog (`TP-*`) spanning auth, catalog, search, ingest, OCR, storage, admin, ops, packaging, and NFR suites. Updated [`../rtm.md`](../rtm.md "Rtm") **§10 Provisional-to-Canonical Test ID Mapping** to map prior `SEC-*` provisional IDs to canonical `TP-*` IDs with `Mapped` status and target dates.

**Documentation:** [`../test-plan.md`](../test-plan.md "Test Plan"), [`../rtm.md`](../rtm.md "Rtm"), [`discussion-log.md`](discussion-log.md "Discussion Log").

---

## 2026-04-26 — Initiated Test Plan v0.1 draft and aligned RTM references

**Summary:** Created [`../test-plan.md`](../test-plan.md "Test Plan") as the initial Test Plan v0.1 draft using approved DD API/data/message contracts (`§5.2`/`§5.3`) and endpoint-family coverage expectations. Updated [`../rtm.md`](../rtm.md "Rtm") header/authority references to reflect DD approval and Test Plan draft initiation while preserving implementation gate restrictions until test execution evidence is complete.

**Documentation:** [`../test-plan.md`](../test-plan.md "Test Plan"), [`../rtm.md`](../rtm.md "Rtm"), [`discussion-log.md`](discussion-log.md "Discussion Log").

---

## 2026-04-26 — DD approved for implementation entry

**Summary:** Following maintainer review and confirmation of readiness, updated [`../dd.md`](../dd.md "Dd") **§13 Phase Gate Declaration** and **Approval** to record human approval, mark Detailed Design approved for implementation entry, and preserve explicit lifecycle follow-ons for Test Plan authoring and Packaging/Orchestration implementation details.

**Documentation:** [`../dd.md`](../dd.md "Dd"), [`discussion-log.md`](discussion-log.md "Discussion Log").

---

## 2026-04-26 — Closure pass: detailed API specs and phase-gate normalization

**Summary:** Extended [`../dd.md`](../dd.md "Dd") with a detailed v1 API specification sheet (**§5.3**) covering representative endpoint contracts (request/response minima and required error/status coverage) across auth, catalog, search, ingest/OCR, storage, admin/security, and ops/release families. Completed closure-pass normalization in **§10**, **§12**, and **§13** by converting remaining unresolved items into explicit lifecycle-deferred follow-ons, marking DD-level interface/NFR/deterministic-probabilistic coverage complete, and clarifying that only human approval plus later lifecycle artifacts remain before implementation authorization.

**Documentation:** [`../dd.md`](../dd.md "Dd"), [`discussion-log.md`](discussion-log.md "Discussion Log").

---

## 2026-04-26 — Added endpoint contract matrix for test-plan seeding

**Summary:** Extended [`../dd.md`](../dd.md "Dd") **§5.2** with an endpoint-family contract matrix baseline (`§5.2.5`) defining minimum request fields, response payload fields, and required status/error coverage across auth, catalog, search, ingest, OCR, storage, admin/security, and ops/release APIs. Added explicit test-plan seeding rules and updated **§8 Testing Alignment** to require matrix-based contract coverage.

**Documentation:** [`../dd.md`](../dd.md "Dd"), [`discussion-log.md`](discussion-log.md "Discussion Log").

---

## 2026-04-26 — Defined canonical API/data/message format baseline

**Summary:** Updated [`../dd.md`](../dd.md "Dd") with a new **§5.2** contract baseline for v1 data/message/API formats: canonical JSON serialization posture, schema evolution and unknown-field handling, common response envelope + error object, request-envelope guardrails (idempotency/pagination/version tokens), and route-family API version namespace map. Updated DD-carried decisions to include this cross-cutting format baseline and added testing-alignment language for schema/envelope/error-code/version compatibility contract tests.

**Documentation:** [`../dd.md`](../dd.md "Dd"), [`discussion-log.md`](discussion-log.md "Discussion Log").

---

## 2026-04-26 — Locked v1 platform package target families

**Summary:** Updated [`../dd.md`](../dd.md "Dd") **§9** to lock v1 platform packaging targets as `.dmg` (macOS), `.msi` (Windows), and `.deb`/`.rpm`/`AppImage` (Linux). Clarified that package-family targets are now part of DD contract scope while packaging toolchains, signing/notarization mechanics, service registration, update channels, and post-install automation remain packaging/orchestration implementation decisions.

**Documentation:** [`../dd.md`](../dd.md "Dd"), [`discussion-log.md`](discussion-log.md "Discussion Log").

---

## 2026-04-26 — Added OCR sidecar schema sketch and validation baseline

**Summary:** Extended [`../dd.md`](../dd.md "Dd") **§4.9** with a minimal v1 OCR/extracted-text sidecar schema sketch (required fields, lineage metadata, threshold-profile capture, and payload contract) plus import/export validation rules (schema compatibility checks, source fingerprint validation, stale-sidecar handling, and portability constraints). Serialization format choice remains deferred to packaging/orchestration, while field semantics are now fixed at DD level.

**Documentation:** [`../dd.md`](../dd.md "Dd"), [`discussion-log.md`](discussion-log.md "Discussion Log").

---

## 2026-04-26 — Added portable OCR/extracted-text sidecar baseline

**Summary:** Updated [`../dd.md`](../dd.md "Dd") **§4.9** to add a v1 baseline for persisted/exportable OCR/extracted-text sidecar artifacts so multi-site library replicas can carry derived text and provenance without mandatory immediate re-OCR. Added sidecar content/versioning/integrity/portability rules and reuse-vs-reprocess posture, and updated the DD-carried OCR decision row to include the sidecar baseline.

**Documentation:** [`../dd.md`](../dd.md "Dd"), [`discussion-log.md`](discussion-log.md "Discussion Log").

---

## 2026-04-26 — Closed OCR pipeline profile and retry/defer baseline question

**Summary:** Updated [`../dd.md`](../dd.md "Dd") **§4.9.8** with concrete v1 OCR/extraction processing profiles (`extract_only`, `ocr_quick`, `ocr_robust`), deterministic profile-selection rules, quality-class posture (`high`, `review_required`, `insufficient`), reproducibility/threshold-capture requirements, and bounded retry/defer escalation rules. Updated the DD-carried OCR decision row and removed the corresponding OCR profile question from **§12 Open Questions**.

**Documentation:** [`../dd.md`](../dd.md "Dd"), [`discussion-log.md`](discussion-log.md "Discussion Log").

---

## 2026-04-26 — Defined search transition protocol and deferred numeric thresholds

**Summary:** Updated [`../dd.md`](../dd.md "Dd") **§4.6.9** to formalize the search-engine transition decision protocol now (required metrics, workload-shape documentation, sustained-observation gate, and SLO-breach trigger) while explicitly deferring numeric thresholds/sample-size minimums until baseline telemetry is captured. Updated the DD-carried search-engine decision row accordingly and narrowed the **§12 Open Questions** item to threshold finalization only.

**Documentation:** [`../dd.md`](../dd.md "Dd"), [`discussion-log.md`](discussion-log.md "Discussion Log").

---

## 2026-04-26 — Closed remote certificate/trust runbook-depth question

**Summary:** Expanded [`../dd.md`](../dd.md "Dd") **§4.3** with a concrete remote certificate/trust runbook baseline covering allowed issuance paths (public CA/ACME, private CA, constrained self-signed), install/activation sequence, renewal and expiry warning thresholds, trust distribution requirements, minimum failure playbooks, and verification checklist. Updated the **§4.3.11** checklist runbook item to complete and removed the corresponding certificate/trust item from **§12 Open Questions**.

**Documentation:** [`../dd.md`](../dd.md "Dd"), [`discussion-log.md`](discussion-log.md "Discussion Log").

---

## 2026-04-26 — Locked Qt v1 shell stack with fallback handoff posture

**Summary:** Updated [`../dd.md`](../dd.md "Dd") to close the UI stack decision in favor of **Qt** for v1, recorded Electron+Vue as a revisit-only fallback path, added shell-policy language for deterministic server-mediated open handoff when in-app PDF search/highlight precision is insufficient, updated the corresponding DD-carried decision/risk wording, and removed the UI framework question from **§12 Open Questions**.

**Documentation:** [`../dd.md`](../dd.md "Dd"), [`discussion-log.md`](discussion-log.md "Discussion Log").

---

## 2026-04-26 — Refined HLA-RELEASE and aligned sections 5-9 consistency

**Summary:** Added a **§4.12.8 ready-for-approval checklist** for release metadata contracts, updated **§4.13 DD-Carried Decisions** to reflect resolved security pin/policy decisions and remaining narrow deferrals, and rewrote **§6 Failure Semantics** from a placeholder list into a cross-component closure rule that references defined §4.x contracts and explicit remaining escalation-policy obligations.

**Documentation:** [`../dd.md`](../dd.md "Dd"), [`discussion-log.md`](discussion-log.md "Discussion Log").

---

## 2026-04-26 — Closed logging sink/location/retention/redaction and field-partition questions

**Summary:** Expanded [`../dd.md`](../dd.md "Dd") **§4.11** with explicit v1 defaults for operational/diagnostic sink targets, locations, rotation/retention posture, and redaction/minimization rules, plus a concrete event-field partition matrix across operational, diagnostic, and audit records. Removed the two corresponding logging questions from **§12 Open Questions**.

**Documentation:** [`../dd.md`](../dd.md "Dd"), [`discussion-log.md`](discussion-log.md "Discussion Log").

---

## 2026-04-26 — Closed password/session defaults-bounds open question

**Summary:** Updated [`../dd.md`](../dd.md "Dd") **§4.8** with concrete v1 defaults and admin bounds for password policy, token/session lifetimes, refresh idle/chain controls, clock skew, concurrent-session cap/policy options, and authentication lockout threshold/duration bounds. Removed the corresponding password/session item from **§12 Open Questions**.

**Documentation:** [`../dd.md`](../dd.md "Dd"), [`discussion-log.md`](discussion-log.md "Discussion Log").

---

## 2026-04-26 — Added HLA-SERVER-HOST ready-for-approval checklist

**Summary:** Added [`../dd.md`](../dd.md "Dd") **§4.3.11** to explicitly mark completion status for server-host design topics and isolate residual carry-forward items (Argon2 binding package pin handoff to security/release manifests, operator runbook depth, and lifecycle-deferred canonical test IDs).

**Documentation:** [`../dd.md`](../dd.md "Dd"), [`discussion-log.md`](discussion-log.md "Discussion Log").

---

## 2026-04-26 — Added remaining HLA-SERVER-HOST completion details

**Summary:** Expanded [`../dd.md`](../dd.md "Dd") **§4.3** with concrete TLS bootstrap modes, remote transport floor, trusted-local-network clarification, certificate hot-reload vs restart-required behavior, session-refresh continuity note, explicit host stack version pins/proposals, and a new **§4.3.10 Host runtime guardrails** defaults table (size/timeout/concurrency/backpressure/shutdown bounds).

**Documentation:** [`../dd.md`](../dd.md "Dd"), [`discussion-log.md`](discussion-log.md "Discussion Log").

---

## 2026-04-26 — Closed JWT/OpenSSL pin+matrix open question

**Summary:** Updated [`../dd.md`](../dd.md "Dd") **§4.8.5** with a concrete v1 baseline for `jwt-cpp` and OpenSSL version pins, a supported JWS algorithm matrix (`Ed25519` default on, `ES256` default off, `HS256` disallowed for access tokens, `none` prohibited), and required cross-platform CI proof expectations. Removed the corresponding item from **§12 Open Questions** as resolved.

**Documentation:** [`../dd.md`](../dd.md "Dd"), [`discussion-log.md`](discussion-log.md "Discussion Log").

---

## 2026-04-26 — Clarified TLS posture: commercial multi-user vs family/home installs

**Summary:** Updated [`../dd.md`](../dd.md "Dd") transport/certificate guidance to state that client-validatable TLS is mandatory for commercial/organizational multi-user deployments, while allowing a documented low-friction local-trust profile for family/home multi-user scenarios on trusted local networks. Updated the related risk-mitigation row to keep self-signed-as-normal prohibited for commercial distributed use.

**Documentation:** [`../dd.md`](../dd.md "Dd"), [`discussion-log.md`](discussion-log.md "Discussion Log").

---

## 2026-04-26 — Closed dual-backend schema/migration open question

**Summary:** Expanded [`../dd.md`](../dd.md "Dd") **§5.1** with a concrete v1 dual-backend governance baseline for SQLite/PostgreSQL: canonical logical schema, migration ID parity, checksum/history validation, expand-contract rollout rules, repository contract ownership, and cross-backend CI conformance gates. Removed the corresponding item from **§12 Open Questions** as resolved.

**Documentation:** [`../dd.md`](../dd.md "Dd"), [`discussion-log.md`](discussion-log.md "Discussion Log").

---

## 2026-04-26 — Marked SQLite FTS transition question as partially resolved

**Summary:** Updated [`../dd.md`](../dd.md "Dd") **§12 Open Questions** to record the high-level trigger for moving beyond SQLite FTS: adoption is warranted when observed SQLite FTS performance no longer meets deployment needs/SLOs. Kept quantitative thresholds, workload shape definitions, and measurement protocol as unresolved details.

**Documentation:** [`../dd.md`](../dd.md "Dd"), [`discussion-log.md`](discussion-log.md "Discussion Log").

---

## 2026-04-26 — Marked password/session open question as partially resolved

**Summary:** Updated [`../dd.md`](../dd.md "Dd") **§12 Open Questions** wording to reflect that password/session policy already has defined baseline elements (symbol-set model, initial lockout defaults, and admin-configurable bounds) while keeping unresolved final defaults/bounds and concurrent-session eviction/denial behavior as active design questions.

**Documentation:** [`../dd.md`](../dd.md "Dd"), [`discussion-log.md`](discussion-log.md "Discussion Log").

---

## 2026-04-26 — Pruned resolved JWT policy wording from DD open questions

**Summary:** Reviewed [`../dd.md`](../dd.md "Dd") **§12 Open Questions** and removed already-resolved policy wording from the JWT/open-SSL question. The open item now focuses only on unresolved version pinning, supported algorithm matrix by platform, and CI proof requirements for the selected baseline.

**Documentation:** [`../dd.md`](../dd.md "Dd"), [`discussion-log.md`](discussion-log.md "Discussion Log").

---

## 2026-04-26 — Closed solo IPC open question: loopback HTTP/S baseline

**Summary:** Updated [`../dd.md`](../dd.md "Dd") to close the solo IPC decision in favor of **loopback `HTTP/S`** for v1. Revised **§4.3.4 Deployment Profiles** to standardize solo transport language, updated the related risk mitigation in **§11**, and removed the resolved IPC question from **§12 Open Questions**.

**Documentation:** [`../dd.md`](../dd.md "Dd"), [`discussion-log.md`](discussion-log.md "Discussion Log").

---

## 2026-04-26 — Set RTM mapping target-date milestone convention

**Summary:** Replaced per-row `Target Date` placeholders in [`../rtm.md`](../rtm.md "Rtm") **§10** with the shared milestone **“By test-plan draft approval”** to make schedule intent explicit before calendar dates are assigned.

**Documentation:** [`../rtm.md`](../rtm.md "Rtm"), [`discussion-log.md`](discussion-log.md "Discussion Log").

---

## 2026-04-26 — Normalized RTM mapping owners to explicit roles

**Summary:** Updated [`../rtm.md`](../rtm.md "Rtm") **§10** mapping `Owner` values from generic placeholders to role-based assignments (`Security Lead` for auth/JWKS/refresh/password/RBAC/admin/bootstrap/throttle mappings and `QA Lead` for log-redaction mapping), leaving dates open for scheduling.

**Documentation:** [`../rtm.md`](../rtm.md "Rtm"), [`discussion-log.md`](discussion-log.md "Discussion Log").

---

## 2026-04-26 — Added owner/target-date fields to RTM test-ID mapping table

**Summary:** Expanded [`../rtm.md`](../rtm.md "Rtm") **§10 Provisional-to-Canonical Test ID Mapping** with `Owner` and `Target Date` columns, seeded with explicit placeholders (`QA/Security TBD`, `TBD`) for each `SEC-*` row to make responsibility assignment and scheduling visible during test-plan onboarding.

**Documentation:** [`../rtm.md`](../rtm.md "Rtm"), [`discussion-log.md`](discussion-log.md "Discussion Log").

---

## 2026-04-26 — Linked security RTM evidence lines to §10 mapping table

**Summary:** Updated security-related evidence lines in [`../rtm.md`](../rtm.md "Rtm") requirement cards (`FR-016`-`FR-018`, `FR-027`, `FR-031`-`FR-035`, `NFR-002`, `NFR-008`) to point reviewers to **§10 Provisional-to-Canonical Test ID Mapping** so trace review and test-plan onboarding can jump directly to the active mapping registry.

**Documentation:** [`../rtm.md`](../rtm.md "Rtm"), [`discussion-log.md`](discussion-log.md "Discussion Log").

---

## 2026-04-26 — Added RTM mapping-status conventions for test-ID transitions

**Summary:** Added explicit mapping-status definitions in [`../rtm.md`](../rtm.md "Rtm") under the provisional-to-canonical test-ID table: `Pending`, `Mapped`, `Split`, and `Retired`, including when each status should be used during test-plan integration.

**Documentation:** [`../rtm.md`](../rtm.md "Rtm"), [`discussion-log.md`](discussion-log.md "Discussion Log").

---

## 2026-04-26 — Pre-populated RTM mapping notes with requirement trace targets

**Summary:** Updated the provisional-to-canonical mapping table in [`../rtm.md`](../rtm.md "Rtm") to include current requirement trace intent in the `Notes` column (for example `FR-016`, `FR-035`, `NFR-002`, `NFR-008`) so future `TP-*` assignment can preserve requirement coverage without re-deriving context.

**Documentation:** [`../rtm.md`](../rtm.md "Rtm"), [`discussion-log.md`](discussion-log.md "Discussion Log").

---

## 2026-04-26 — Seeded RTM provisional-to-canonical test-ID mapping table

**Summary:** Added a dedicated mapping section in [`../rtm.md`](../rtm.md "Rtm") with seeded rows for all current DD provisional security IDs (`SEC-*`) and placeholder canonical test-plan IDs (`TBD`) so test-plan onboarding can fill mappings directly without restructuring the RTM.

**Documentation:** [`../rtm.md`](../rtm.md "Rtm"), [`discussion-log.md`](discussion-log.md "Discussion Log").

---

## 2026-04-26 — Added RTM test-ID transition rule (`SEC-*` to canonical test-plan IDs)

**Summary:** Updated [`../rtm.md`](../rtm.md "Rtm") **§9 Coverage Checklist** to require explicit remapping of provisional DD test IDs (such as `SEC-*`) to canonical test-plan IDs (such as `TP-*`) with one-to-one trace notes before test phase closure.

**Documentation:** [`../rtm.md`](../rtm.md "Rtm"), [`discussion-log.md`](discussion-log.md "Discussion Log").

---

## 2026-04-26 — Added provisional security test mappings to RTM

**Summary:** Updated [`../rtm.md`](../rtm.md "Rtm") security-related requirement cards to reference the new DD-level `SEC-*` placeholders from [`../dd.md`](../dd.md "Dd") **§4.8.10**. Mapped `FR-016`, `FR-017`, `FR-018`, `FR-027`, `FR-031`-`FR-035`, `NFR-002`, and `NFR-008`, explicitly labeled as provisional until canonical test-plan IDs are published.

**Documentation:** [`../rtm.md`](../rtm.md "Rtm"), [`../dd.md`](../dd.md "Dd"), [`discussion-log.md`](discussion-log.md "Discussion Log").

---

## 2026-04-26 — Seeded DD-level security test IDs for auth/JWKS/refresh

**Summary:** Replaced the “test IDs TBD” placeholder in [`../dd.md`](../dd.md "Dd") **§4.8.10** with DD-level identifiers spanning authentication, JWKS cache/refresh behavior, signing-key rotation overlap, refresh replay handling, RBAC denials, throttling, and log redaction expectations. Marked these as placeholders that must map to canonical test-plan IDs during formal test-plan publication.

**Documentation:** [`../dd.md`](../dd.md "Dd"), [`discussion-log.md`](discussion-log.md "Discussion Log").

---

## 2026-04-26 — Added JWKS client cache/refresh defaults (v1 recommendation)

**Summary:** Extended [`../dd.md`](../dd.md "Dd") **§4.8.5** with a compact JWKS client behavior table covering startup fetch, cache lifetime fallback, unknown-`kid` refresh trigger, bounded backoff, stale-key fail-closed posture, and expected overlap with server rotation windows.

**Documentation:** [`../dd.md`](../dd.md "Dd"), [`discussion-log.md`](discussion-log.md "Discussion Log").

---

## 2026-04-26 — Suggested v1 JWKS delivery shape documented (non-binding)

**Summary:** Added a minimal recommendation in [`../dd.md`](../dd.md "Dd") **§4.8.5** to publish JWKS through a versioned security metadata surface (example path only), while explicitly preserving endpoint/path naming as deployment-configurable packaging detail rather than a fixed binary contract.

**Documentation:** [`../dd.md`](../dd.md "Dd"), [`discussion-log.md`](discussion-log.md "Discussion Log").

---

## 2026-04-26 — Ed25519 JWKS + rotation operator contract added to DD

**Summary:** Expanded [`../dd.md`](../dd.md "Dd") **§4.8.5** with an operator-facing contract for **Ed25519 signing keys**, **`kid` handling**, **JWKS publication expectations** for the dedicated client, and an explicit **overlap-based rotation** posture bounded by access-token TTL and clock skew. Added a related interface row for JWKS publication/consumption and extended security test intent for rotation and `kid` mismatch behavior.

**Documentation:** [`../dd.md`](../dd.md "Dd"), [`discussion-log.md`](discussion-log.md "Discussion Log").

---

## 2026-04-26 — Default JWT access-token algorithm: Ed25519 (EdDSA)

**Summary:** Confirmed the v1 default JWS algorithm for access tokens is **Ed25519 (EdDSA)** for the `jwt-cpp` + OpenSSL stack, because the only intended consumer is the dedicated client (**HLA-CLIENT-ACCESS**). `ES256` is treated as a non-default future compatibility option if a new interoperability requirement is approved. Updated [`../dd.md`](../dd.md "Dd") **§4.8.5** and refined the open question about the supported algorithm matrix accordingly.

**Documentation:** [`../dd.md`](../dd.md "Dd"), [`discussion-log.md`](discussion-log.md "Discussion Log").

---

## 2026-04-26 — Selected `jwt-cpp` for JWS/JWT (OpenSSL-integrated)

**Summary:** Recorded **jwt-cpp (Thalhammer)** as the implementation library for JWS encode/decode and signature operations for access JWTs, integrated with **OpenSSL** and JSON handling aligned with the existing **nlohmann/json** baseline. Updated [`../dd.md`](../dd.md "Dd") to remove the “pick a JWT library” open question and replace it with a version-pin/algorithm-matrix question appropriate for build reproducibility and operator documentation.

**Documentation:** [`../dd.md`](../dd.md "Dd"), [`discussion-log.md`](discussion-log.md "Discussion Log").

---

## 2026-04-26 — JWT access+refresh baseline, dual SQL backends, GitHub Actions CI of record

**Summary:** Updated [`../dd.md`](../dd.md "Dd") to adopt a v1 API authentication model based on **`Authorization: Bearer` access JWTs** and **rotating opaque refresh tokens** (no cookie session model), with explicit admin-configurable bounds, signing-key rotation posture, throttling, and failure semantics. Added a durable-store section describing **SQLite + PostgreSQL** backends with repository-level SQL (no ORM assumption) and JWT/refresh persistence requirements. Expanded packaging impact to record **GitHub Actions** as the default CI/build platform of record with cross-OS matrix expectations. Updated [`../srs.md`](../srs.md "Srs") **FR-035** notes to align session/token language with the DD decision. Added root [`../../CONTRIBUTING.md`](../../CONTRIBUTING.md "Contributing") describing CI-of-record and license posture.

**Documentation:** [`../dd.md`](../dd.md "Dd"), [`../srs.md`](../srs.md "Srs"), [`../../CONTRIBUTING.md`](../../CONTRIBUTING.md "Contributing"), [`discussion-log.md`](discussion-log.md "Discussion Log").

---

## 2026-04-26 — Project license: GPL-3.0-or-later (supersedes Apache-2.0)

**Summary:** Relicensed the project to **GPL-3.0-or-later** to align the repository license with the selected native-dependency plan (notably around bundled PDF/print and OCR stacks). Replaced the root `LICENSE` with the full GPLv3 text, updated `NOTICE` for GPL posture, and added `licenses/README.md` as the third-party notice policy stub. Updated [`../srs.md`](../srs.md "Srs") **NFR-003** and related license constraints, plus [`../hla.md`](../hla.md "Hla") and [`../concept.md`](../concept.md "Concept") references. Updated [`open-source-license.md`](open-source-license.md "Open Source License") to record the new decision and rationale.

**Documentation:** `LICENSE`, `NOTICE`, `licenses/README.md`, [`../srs.md`](../srs.md "Srs"), [`../hla.md`](../hla.md "Hla"), [`../concept.md`](../concept.md "Concept"), [`../dd.md`](../dd.md "Dd"), [`open-source-license.md`](open-source-license.md "Open Source License").

---

## 2026-04-26 — DD stack baselines selected for server/search/OCR

**Summary:** Recorded implementation-baseline decisions in [`../dd.md`](../dd.md "Dd"): server host stack baseline is C++ with Boost.Beast/Asio, OpenSSL, Argon2id, JWT capability, spdlog/fmt, nlohmann/json, and Catch2; durable-store posture is SQLite for solo deployments with PostgreSQL support for remote multi-user via backend-agnostic contracts. Search baseline is SQLite FTS with external multi-user engine path deferred (Meilisearch first candidate; OpenSearch/Tantivy-based options later). OCR/extraction baseline is Tesseract + Leptonica with OpenCV preprocessing and Poppler ingest extraction, while PDFium is positioned as viewer-side PDF UX candidate with explicit search-vs-viewer boundary language.

**Documentation:** [`../dd.md`](../dd.md "Dd"), [`discussion-log.md`](discussion-log.md "Discussion Log").

---

## 2026-04-26 — Markdown same-document anchor policy corrected

**Summary:** Updated documentation link policy to use bare fragment anchors for same-document navigation (for example, `#section-anchor`) and reserve explicit file+anchor links (for example, `./file.md#section-anchor`) for cross-document navigation. This correction addresses Cursor markdown behavior where same-file links expressed as `./current-file.md#anchor` may be interpreted as file navigation rather than in-document jump in some views.

**Documentation:** [`../dd.md`](../dd.md "Dd"), [`project-primer.md`](project-primer.md "Project Primer"), [`discussion-log.md`](discussion-log.md "Discussion Log").

---

## 2026-04-26 — RTM table readability/linking format updated

**Summary:** Updated [`../rtm.md`](../rtm.md "Rtm") table formatting for readability and navigation: requirement IDs now link to exact SRS anchors; HLA/DD references in matrix cells are linkified; header labels are abbreviated for width; table headers use centered alignment; and reference cells wrap only at comma separators via per-item non-wrapping segments.

**Documentation:** [`../rtm.md`](../rtm.md "Rtm").

---

## 2026-04-26 — DD status-taxonomy naming normalized

**Summary:** Performed a semantic consistency pass on [`../dd.md`](../dd.md "Dd") status contracts and normalized status token naming across prose and failure semantics to the canonical underscore forms (for example `rejected_validation`, `rejected_forbidden`, `rejected_authentication`, `failed_unavailable`, `completed_with_warnings`). Updated several contract bullets to reference explicit status classes instead of mixed generic wording.

**Documentation:** [`../dd.md`](../dd.md "Dd").

---

## 2026-04-26 — DD/RTM consistency sweep completed

**Summary:** Performed a cross-artifact consistency pass after the DD expansion. Updated [`../dd.md`](../dd.md "Dd") traceability/phase-gate wording to reflect that initial decomposition now exists for **§4.1–§4.12**. Updated [`../rtm.md`](../rtm.md "Rtm") to map DD Artifact references across all FR/NFR rows to the corresponding DD sections, refreshed RTM metadata wording, and added lineage entry for the mapping refresh. Updated [`../README.md`](../README.md "Readme") artifact status text to match current DD/RTM state.

**Documentation:** [`../dd.md`](../dd.md "Dd"), [`../rtm.md`](../rtm.md "Rtm"), [`../README.md`](../README.md "Readme").

---

## 2026-04-26 — OCR correction UI presence decided for v1

**Summary:** Established a DD baseline that OCR correction is not API-only: the product SHALL provide an in-app shell remediation surface for OCR artifact correction in v1. Scope is intentionally minimal for this pass (review/edit/submit corrected text + outcome visibility), with detailed UX composition deferred to a later DD UX-detail pass. Access scope baseline is uploader and administrator (or documented equivalent role), subject to server authorization policy.

**Documentation:** [`../dd.md`](../dd.md "Dd"), [`../rtm.md`](../rtm.md "Rtm").

---

## 2026-04-26 — DD HLA-SHELL baseline added

**Summary:** Added [`../dd.md`](../dd.md "Dd") **§4.1 HLA-SHELL** initial decomposition for client UI responsibilities, accessibility/theme/help obligations, server-mediated action routing through client-access, and explicit shell status-class contracts (including guarded `deferred` usage and degraded-state handling).

**Documentation:** [`../dd.md`](../dd.md "Dd"), [`../rtm.md`](../rtm.md "Rtm").

---

## 2026-04-26 — Installer detail deferral boundary recorded

**Summary:** Updated [`../dd.md`](../dd.md "Dd") **§9 Packaging and Orchestration Impact** to explicitly separate current DD responsibilities (installer-impacting runtime contracts/constraints) from deferred packaging-pass responsibilities (per-OS installer implementation mechanics). This preserves forward planning without prematurely committing installer tooling/workflow details.

**Documentation:** [`../dd.md`](../dd.md "Dd"), [`../rtm.md`](../rtm.md "Rtm").

---

## 2026-04-26 — DD HLA-RELEASE baseline added

**Summary:** Added [`../dd.md`](../dd.md "Dd") **§4.12 HLA-RELEASE** initial decomposition for runtime release identity, immutable manifest/descriptor handling, license/notice reference exposure, consistency validation across shell/server surfaces, and explicit status-class contracts including constrained `deferred` usage.

**Documentation:** [`../dd.md`](../dd.md "Dd"), [`../rtm.md`](../rtm.md "Rtm").

---

## 2026-04-26 — DD HLA-CLIENT-ACCESS baseline added

**Summary:** Added [`../dd.md`](../dd.md "Dd") **§4.2 HLA-CLIENT-ACCESS** initial decomposition covering API mediation, session/token handling boundaries, solo vs remote transport/trust posture, and explicit status-class contracts including `rejected_authentication` and guarded `deferred` usage rules.

**Documentation:** [`../dd.md`](../dd.md "Dd"), [`../rtm.md`](../rtm.md "Rtm").

---

## 2026-04-26 — DD HLA-SEARCH baseline added

**Summary:** Added [`../dd.md`](../dd.md "Dd") **§4.6 HLA-SEARCH** initial decomposition covering query semantics ownership, index lifecycle/rebuild administration, fallback behavior, and explicit status-class contracts for query/admin outcomes. The section follows the strengthened status taxonomy standard (including nonterminal `deferred` constraints) from first draft.

**Documentation:** [`../dd.md`](../dd.md "Dd"), [`../rtm.md`](../rtm.md "Rtm").

---

## 2026-04-29 — Implementation phase gate approved and cleared

**Summary:** Maintainer/project owner approved and cleared implementation start after review of current artifacts. Remaining manual Omnigraffle diagram rework is explicitly treated as non-blocking cleanup and does not prevent implementation from starting.

**Gate decision:** Implementation phase authorized effective 2026-04-29 under approved [`../srs.md`](../srs.md "Srs"), [`../hla.md`](../hla.md "Hla"), [`../dd.md`](../dd.md "Dd"), [`../test-plan.md`](../test-plan.md "Test Plan"), and [`../rtm.md`](../rtm.md "Rtm").

**Documentation:** [`../LIFECYCLE.md`](../LIFECYCLE.md "Lifecycle"), [`../rtm.md`](../rtm.md "Rtm"), [`../README.md`](../README.md "Readme").

---

## 2026-04-26 — Status-class contract rigor hardened across DD

**Summary:** Tightened DD component contracts to require explicit status-class taxonomy rather than implicit outcome wording. Added concrete status definitions for **HLA-DOMAIN**, **HLA-INGEST**, and **HLA-STORAGE** output contracts, including required response fields and explicit separation of nonterminal `deferred` from terminal `failed`. Updated the DD template so future sections include this rigor from first draft.

**Documentation:** [`../dd.md`](../dd.md "Dd"), [`../_templates/dd.md`](../_templates/dd.md "Dd Template").

---

## 2026-04-26 — Markdown anchor-link convention normalized (superseded)

**Summary:** (Superseded by the newer same-document anchor policy entry.) This earlier note normalized internal section links to explicit file+anchor form (for example, `./file.md#section-anchor`). Current policy now distinguishes same-document (`#anchor`) from cross-document (`./file.md#anchor`) usage based on observed Cursor navigation behavior.

**Documentation:** [`../../README.md`](../../README.md "MyLib documentation"), [`../srs.md`](../srs.md "Srs"), [`../hla.md`](../hla.md "Hla"), [`../dd.md`](../dd.md "Dd"), [`../rtm.md`](../rtm.md "Rtm").

---

## 2026-04-25 — DD HLA-SECURITY baseline started

**Summary:** Updated [`../dd.md`](../dd.md "Dd") **§4.8 HLA-SECURITY** with the initial detailed design for local authentication, RBAC, tenant policy, password storage, session management, throttling, bootstrap, account administration, failure semantics, NFR derivation, and test intent. Baseline design decisions: local username/password remains v1 scope; Argon2id is the preferred password hashing algorithm with persisted parameters and upgrade detection; sessions use opaque server-issued tokens rather than trusting self-contained client claims; security diagnostics are minimized and audit accountability remains separate.

**Technology:** No concrete library selected yet. Future security-library choices must be logged when the implementation stack is chosen; candidates must support Argon2id or a documented approved fallback, secure random token generation, safe verifier comparison, and parameter migration.

**Documentation:** [`../dd.md`](../dd.md "Dd"), [`../rtm.md`](../rtm.md "Rtm").

---

## 2026-04-25 — DD server-host logging/privacy concern recorded

**Summary:** Updated [`../dd.md`](../dd.md "Dd") **§4.3 HLA-SERVER-HOST** to add an explicit server-host operational and diagnostic logging producer contract. The design now requires lifecycle, listener, transport, dependency readiness, request-routing, and shutdown diagnostics while minimizing fields that could expose secrets or personal data. It separates operational diagnostics from **HLA-AUDIT**, keeps durable sinks/retention/redaction under **HLA-OBSLOG**, and records EU-style privacy concerns such as file paths, IP addresses, account names, tenant names, and document titles being potentially personal data.

**Documentation:** [`../dd.md`](../dd.md "Dd"), [`../rtm.md`](../rtm.md "Rtm").

---

## 2026-04-25 — DD remote TLS certificate/trust concern recorded

**Summary:** Updated [`../dd.md`](../dd.md "Dd") **§4.3 HLA-SERVER-HOST** to distinguish local-only certificate tolerance from distributed remote requirements. Local-only installs may use non-TLS local transport or self-signed HTTPS when appropriate; distributed remote deployments require a client-validatable trust chain through public CA or operator-managed private CA. v1 baseline assumes operators provide and renew certificates, with documentation for public CA / Let's Encrypt / ACME where applicable; built-in ACME automation remains optional future scope unless selected later in DD. DD must define certificate/trust-anchor configuration, client trust UX, rotation/replacement behavior, and remediation guidance without normalizing certificate-warning bypass.

**Documentation:** [`../dd.md`](../dd.md "Dd").

---

## 2026-04-25 — DD begins with HLA-SERVER-HOST

**Summary:** Began DD component decomposition with [`../dd.md`](../dd.md "Dd") **§4.3 HLA-SERVER-HOST** because the server host anchors process lifecycle, binding, routing, deployment profile, and the solo/remote trust posture. Added responsibilities, non-responsibilities, invariants, interface contracts, internal structure, deployment profiles, failure semantics, NFR derivation, and initial test intent. Updated [`../rtm.md`](../rtm.md "Rtm") DD Artifact references for FR-013-FR-015 and NFR-001, NFR-002, NFR-004, NFR-005, NFR-009.

**Documentation:** [`../dd.md`](../dd.md "Dd"), [`../rtm.md`](../rtm.md "Rtm").

---

## 2026-04-25 — DD v0.1 draft scaffold created

**Summary:** Created [`../dd.md`](../dd.md "Dd") **v0.1** as the active Detailed Design scaffold after HLA v0.1.2 approval. The scaffold preserves approved HLA boundaries, identifies all HLA components for decomposition, carries HLA §14 DD decisions into DD work, and keeps implementation blocked until DD approval and RTM readiness. Updated [`../README.md`](../README.md "Readme"), [`../LIFECYCLE.md`](../LIFECYCLE.md "Lifecycle"), [`../rtm.md`](../rtm.md "Rtm"), and [`../srs.md`](../srs.md "Srs").

**Documentation:** [`../dd.md`](../dd.md "Dd"), [`../rtm.md`](../rtm.md "Rtm"), [`../LIFECYCLE.md`](../LIFECYCLE.md "Lifecycle").

---

# Entry ID: DL-002

**Date (YYYY-MM-DD):** 2026-04-25  
**Lifecycle Phase:** Architecture / HLA approval gate  
**Author:** Charles McKnight directive, recorded by assistant  
**Status:** Approved  

---

## 1. Decision Summary

Approve [`../hla.md`](../hla.md "Hla") **v0.1.2** as the High-Level Architecture baseline and authorize advancement to **Detailed Design**. Implementation remains blocked until DD approval and RTM readiness.

---

## 2. Context

- **Requirement ID(s):** FR-001-FR-041, NFR-001-NFR-009.
- **Architectural Component ID(s):** HLA-SHELL, HLA-CLIENT-ACCESS, HLA-SERVER-HOST, HLA-DOMAIN, HLA-INGEST, HLA-SEARCH, HLA-STORAGE, HLA-SECURITY, HLA-OCR, HLA-AUDIT, HLA-OBSLOG, HLA-RELEASE, HLA-BOUND-OCR.
- **Design artifact references:** Future `dd.md`.
- **Non-functional drivers:** Server-side enforcement, transport security, logging/privacy, documentation honesty, accessibility, release identity, reproducibility posture.
- **Constraints influencing the decision:** SRS v0.9 is approved; HLA v0.1.2 has component boundaries, diagrams, DD-carried decisions, and RTM HLA mappings.
- **Risk factors identified:** DD-carried choices may still alter HLA boundaries if selected poorly; lifecycle rollback applies if that occurs.
- **Phase-gate context:** HLA approval closes the Architecture gate and authorizes DD.

---

## 3. Deterministic-Probabilistic Boundary Impact

No new boundary change. HLA approval confirms **HLA-BOUND-OCR** as the architectural boundary for OCR/extraction and requires DD to preserve containment, fallback, observability, and reproducibility expectations.

---

## 4. Alternatives Considered

- **Keep HLA in draft:** Rejected because review did not identify missing HLA-level boundaries or blockers.
- **Move DD-owned questions back into HLA blockers:** Rejected because Section 14 now correctly treats them as DD-carried decisions unless they alter HLA boundaries.

---

## 5. Decision Rationale

HLA v0.1.2 defines the required architecture baseline: client-server authority, major components, data ownership, probabilistic boundary, NFR mechanisms, deployment posture, traceability summary, and DD-carried decisions. The remaining unresolved work is appropriately detailed design, not HLA definition.

---

## 6. Impact Analysis

- **Requirements:** No SRS revision required.
- **Architecture:** HLA v0.1.2 status changes from Draft to Approved.
- **Detailed Design:** DD is now authorized.
- **Implementation units:** None authorized.
- **Test Case IDs:** N/A until test planning.
- **Packaging configuration:** Packaging choices remain future DD/packaging-plan work.
- **Orchestration pipeline:** Future orchestration artifacts TBD.
- **System documentation:** Update HLA approval block, lifecycle status, README, SRS HLA reference, concept lifecycle note, and RTM authority/lineage.
- **RTM update required:** Yes, authority and lineage metadata updated; DD/test/package columns remain TBD.

---

## 7. Traceability References

- **Requirement ID(s):** FR-001-FR-041, NFR-001-NFR-009 via [`../rtm.md`](../rtm.md "Rtm").
- **Architectural Component ID(s):** See [`../hla.md`](../hla.md "Hla") §6 and [`../rtm.md`](../rtm.md "Rtm") §3.
- **Detailed Design reference(s):** `dd.md` planned.
- **Test Case ID(s):** N/A.
- **Packaging reference:** `packaging-plan.md` planned.
- **Orchestration reference:** Future orchestration artifacts TBD.

---

## 8. Risk Assessment

- **Residual risks:** DD-carried decisions still require concrete choices and may trigger rollback if they change HLA boundaries.
- **Assumptions:** HLA review found no missing component, trust, data, deployment, or probabilistic boundaries.
- **Monitoring requirements:** DD review must check conformance to approved HLA and log framework/library decisions.
- **Revisit triggers:** DD proposes new architecture components, new trust boundaries, different dependency direction, or altered OCR/search/security ownership.
- **Compliance implications:** No legal compliance change.
- **Operational exposure:** None until implementation is authorized.

---

## 9. Versioning & Lineage

- **RTM version at time of decision:** v0.1 draft.
- **System documentation version:** HLA v0.1.2 approved.
- **Artifact version:** [`../hla.md`](../hla.md "Hla") v0.1.2.
- **Related prior entries:** DL-001; historical HLA v0.1 and v0.1.1 entries.

---

## 10. Phase Impact Declaration

- **Does this decision require rollback to prior phase?** No.
- **Does this decision require revalidation of tests?** No tests exist yet.
- **Does this decision require packaging revalidation?** No packaging plan exists yet.
- **Does this decision alter NFR posture?** No; it approves the documented NFR architecture posture.

---

# Entry ID: DL-001

**Date (YYYY-MM-DD):** 2026-04-25  
**Lifecycle Phase:** Architecture / HLA approval gate  
**Author:** Charles McKnight directive, recorded by assistant  
**Status:** Approved  

---

## 1. Decision Summary

The existing [`discussion-log.md`](discussion-log.md "Discussion Log") remains the canonical project decision/discussion log and SHALL conform to the decision-log template for all new structural decisions. HLA and DD artifacts SHALL include Mermaid diagrams where diagrams materially clarify data flows, component organization, architecture, trust boundaries, deployment topology, state transitions, or cross-component interactions.

---

## 2. Context

- **Requirement ID(s):** Cross-cutting governance; supports traceability for FR/NFR-driven design decisions.
- **Architectural Component ID(s):** Cross-cutting; applies to all HLA components when decisions affect them.
- **Design artifact references:** Future `dd.md`; current [`../hla.md`](../hla.md "Hla").
- **Non-functional drivers:** Audit readiness, maintainability, reproducibility, architectural integrity.
- **Constraints influencing the decision:** The project is past SRS approval and sits at the HLA approval gate; DD and implementation remain unauthorized.
- **Risk factors identified:** Framework/library choices may otherwise be made implicitly during DD or implementation without traceable rationale.
- **Phase-gate context:** This decision strengthens Architecture and DD gate evidence without advancing the lifecycle phase.

---

## 3. Deterministic-Probabilistic Boundary Impact

No boundary change. Future decisions affecting **HLA-BOUND-OCR** or other probabilistic behavior SHALL document validation, containment, fallback, observability, and reproducibility impact in this log.

---

## 4. Alternatives Considered

- **Create a separate project log:** Rejected to avoid two competing decision authorities.
- **Use only informal discussion summaries:** Rejected because framework/library and structural decisions need traceable rationale.
- **Put every decision only inside HLA/DD:** Rejected because cross-cutting decisions may span multiple artifacts and need chronological lineage.

---

## 5. Decision Rationale

Using the existing log preserves history while making future entries auditable. Requiring Mermaid diagrams in HLA/DD reduces ambiguity for architecture and design flows that are hard to validate from prose alone. The decision aligns with lifecycle controls by improving gate evidence without authorizing DD or implementation prematurely.

---

## 6. Impact Analysis

- **Requirements:** No SRS content change required.
- **Architecture:** HLA should include Mermaid diagrams where appropriate.
- **Detailed Design:** DD must record framework/library choices and include Mermaid diagrams where appropriate.
- **Implementation units:** None authorized.
- **Test Case IDs:** None yet; future DD/test decisions must map tests when applicable.
- **Packaging configuration:** Future packaging choices must be logged.
- **Orchestration pipeline:** Future orchestration choices must be logged.
- **System documentation:** Update lifecycle guidance, HLA/DD templates, artifact index, and HLA references.
- **RTM update required:** No direct RTM row change; downstream decisions may require RTM updates.

---

## 7. Traceability References

- **Requirement ID(s):** Cross-cutting governance; downstream entries must list specific IDs when applicable.
- **Architectural Component ID(s):** Cross-cutting; downstream entries must list specific HLA IDs when applicable.
- **Detailed Design reference(s):** `dd.md` planned.
- **Test Case ID(s):** N/A for this governance entry.
- **Packaging reference:** `packaging-plan.md` planned.
- **Orchestration reference:** Future orchestration artifacts TBD.
- **Documentation references:** [`../LIFECYCLE.md`](../LIFECYCLE.md "Lifecycle"), [`../hla.md`](../hla.md "Hla"), [`../_templates/hla.md`](../_templates/hla.md "Hla Template"), [`../_templates/dd.md`](../_templates/dd.md "Dd Template").

---

## 8. Risk Assessment

- **Residual risks:** Older entries remain summary-format until normalized.
- **Assumptions:** New decisions will be recorded before they become downstream design or implementation authority.
- **Monitoring requirements:** HLA/DD reviews must check for missing decision-log entries.
- **Revisit triggers:** Adoption of standalone ADR files, major framework selection, packaging strategy selection, or OCR/search engine selection.
- **Compliance implications:** Improves auditability; no legal compliance change.
- **Operational exposure:** None for this governance entry.

---

## 9. Versioning & Lineage

- **RTM version at time of decision:** v0.1 draft.
- **System documentation version:** Current Architecture phase artifacts.
- **Artifact version:** HLA draft moves to v0.1.2 for diagram/governance updates.
- **Related prior entries:** 2026-04-06 HLA v0.1 draft and 2026-04-06 HLA v0.1.1 SRS anchors; both are historical and superseded by current HLA v0.1.2.

---

## 10. Phase Impact Declaration

- **Does this decision require rollback to prior phase?** No.
- **Does this decision require revalidation of tests?** No tests exist yet.
- **Does this decision require packaging revalidation?** No packaging plan exists yet.
- **Does this decision alter NFR posture?** No; it improves documentation evidence for NFR-driven decisions.

---

## 2026-04-06 — Historical HLA v0.1.1: SRS anchors for rendered (GitHub) viewing

**Summary:** Historical **[`../hla.md`](../hla.md "Hla")** **v0.1.1** update, now superseded by current **HLA v0.1.2** — note on **relative** `srs.md#…` links matching **GitHub** heading IDs; converted **FR**/**NFR**/**§** references in drivers, components, data/NFR/failure/risk/open-questions tables, and gates to **`[text](./srs.md#slug "Title")`** (and **[`LIFECYCLE.md`](../LIFECYCLE.md "Lifecycle")** where useful). At that time, **SRS** header **HLA** reference and **README** artifact status were updated to **0.1.1**.

**Documentation:** [`../hla.md`](../hla.md "Hla"), [`../srs.md`](../srs.md "Srs").

---

## 2026-04-06 — Historical HLA v0.1 draft; RTM architectural mapping

**Summary:** Added historical **[`../hla.md`](../hla.md "Hla")** **v0.1** (**Draft**), now superseded by current **HLA v0.1.2**: client–server structural model, twelve components (**HLA-SHELL** through **HLA-RELEASE**), **HLA-BOUND-OCR**, context **mermaid** diagram, NFR structural notes, open questions for DD. Updated **[`../rtm.md`](../rtm.md "Rtm")** §3 **HLA Component ID** for all FR/NFR; §4 **FR-023** boundary row; §5 NFR mechanism column; lineage. **[`../LIFECYCLE.md`](../LIFECYCLE.md "Lifecycle")** §5 and **[`../README.md`](../README.md "Readme")**; **[`../concept.md`](../concept.md "Concept")** lifecycle blurb. HLA **§15** — human approval **pending** before DD.

**Documentation:** [`../hla.md`](../hla.md "Hla"), [`../rtm.md`](../rtm.md "Rtm").

---

## 2026-04-06 — SRS v0.9 approved; Requirements→Architecture gate

**Summary:** **Project owner** (sole stakeholder) **reviewed** and **approved** **[`../srs.md`](../srs.md "Srs")** **v0.9** **2026-04-06**. **§16** and **§Approval** updated; **NFR** measurement **deferred** to **Test Plan** / design (**accepted** for Architecture entry). **High-Level Architecture** phase **authorized**. **[`../LIFECYCLE.md`](../LIFECYCLE.md "Lifecycle")** **§5** and **[`project-primer.md`](project-primer.md "Project Primer")** **§13** record the gate; primer **v1.1**. **[`../rtm.md`](../rtm.md "Rtm")** **§1** — requirements **approved**; Architecture **work** authorized (HLA not yet approved). Fixed **SRS §1** link to primer **§12** (was incorrectly pointing at SRS §12). **[`../README.md`](../README.md "Readme")** artifact table updated.

**Documentation:** [`../srs.md`](../srs.md "Srs"), [`../LIFECYCLE.md`](../LIFECYCLE.md "Lifecycle"), [`../rtm.md`](../rtm.md "Rtm"), [`project-primer.md`](project-primer.md "Project Primer").

---

## 2026-04-03 — RTM v0.1 instantiated; LIFECYCLE aligned with SRS v0.9

**Summary:** Created **[`../rtm.md`](../rtm.md "Rtm")** **v0.1** (draft): core matrix rows for **FR-001–FR-041** and **NFR-001–NFR-009**; **HLA**, **DD**, **test**, **packaging**, and **orchestration** columns **TBD** until those artifacts exist. **§4** deterministic–probabilistic stub for **FR-023**. Updated **[`../LIFECYCLE.md`](../LIFECYCLE.md "Lifecycle")** **§5** to reference SRS **v0.9** and the RTM draft. **SRS** **§15–§16**: RTM reference in metadata and traceability; **§16** marks traceability scaffold **prepared**; human approval still **No**. **[`../README.md`](../README.md "Readme")** artifact index lists RTM. Minor **§16** fixes: **Partial** bolding, **FR-011** link title spelling.

**Documentation:** [`../rtm.md`](../rtm.md "Rtm"), [`../LIFECYCLE.md`](../LIFECYCLE.md "Lifecycle"), [`../srs.md`](../srs.md "Srs").

---

## 2026-04-03 — Markdown link convention and tooling

**Summary:** **Repository** documentation **SHALL** use inline links **`[text](url "Title")`** (paths and `#` fragments). **`system-documentation/_tools/add_link_titles.py`** adds missing quoted titles only when the target has **no** `"` (avoids corrupting titles that contain `)`). **`system-documentation/README.md`** documents the convention; **`.cursor/rules/cursor-rules.mdc`** instructs Cursor to preserve titles. **SRS** link repairs where an earlier naive pass had duplicated titles.

**Documentation:** [`../../README.md`](../../README.md "MyLib documentation"), [`../srs.md`](../srs.md "Srs").

---

## 2026-04-11 — SRS v0.9: FR-002/004/010/011/038; NFR-004/007; §15–§16 readability

**Summary:** **FR-002** — separate **publication date** (optional) and **acquisition date** (tracked, import semantics in DD). **FR-004** — import **administrator-only** (import-equivalent permission in DD); solo via bootstrap admin (FR-032); deps FR-017, FR-032. **FR-010** — **durable digest store** + **algorithm identifier**; migration in DD. **FR-011** — **solo** relink UX; **multi-user** default **notify administrators** for remediation, non-admin degraded per DD; FR-013 Notes tie server-side auth. **FR-038** — explicit **nested** query examples and acceptance fixtures. **NFR-004** / **NFR-007** updated. **§15–§16** bullets use **phrase-level** bolding (reduce per-word noise).

**Documentation:** [`../srs.md`](../srs.md "Srs").

---

## 2026-04-10 — SRS v0.8.1: §11 aligns with FR-041; FR-038 operator rules

**Summary:** **§11** **—** **removed** **generic** **last-write-wins** **/** **merge** **for** **metadata;** **same-record** **metadata** **concurrency** **now** **tracks** **FR-041** **(optimistic** **concurrency,** **refresh**/**retry,** **optional** **explicit** **overwrite** **per** **DD).** **FR-038** **item** **2** **—** **DD** **must** **define** **boolean** **keyword** **case** **and** **tokenization** **explicitly;** **Notes** **distinguish** **operator** **case** **from** **Latin** **matching** **case** **for** **terms.** **Version** **0.8.1.**

**Documentation:** [`../srs.md`](../srs.md "Srs").

---

## 2026-04-09 — SRS v0.8: MFA de-prioritized; passkeys as waiting-room candidate

**Summary:** **§2.2** **explicit** **out-of-scope:** **MFA** **not** **in** **v1,** **intentionally** **de-prioritized** **until** **clear** **need;** **if** **ever** **introduced,** **optional** **per** **deployment** **only** **(not** **listed** **in** **§13** **—** **avoid** **implying** **a** **backlog** **item).** **§13** **waiting** **room:** **passkeys** **/** **WebAuthn** **as** **candidate** **post-v1** **optional** **sign-in** **(HLA** **/** **DD).** **FR-016** **Notes,** **§12** **cross-references.**

**Documentation:** [`../srs.md`](../srs.md "Srs").

---

## 2026-04-08 — SRS v0.7: password policy, v1 boolean/phrase search, session vs capacity

**Summary:** **FR-033** **—** **v1** **password** **rules:** **minimum** **8** **characters;** **uppercase,** **lowercase,** **digit,** **and** **one** **symbol** **from** **a** **DD-enumerated** **set** **(temporary** **passwords** **meet** **rules** **or** **force** **change).** **FR-038** **—** **v1** **search** **requires** **`AND`/`OR`/`NOT`,** **double-quoted** **phrases,** **parentheses** **for** **grouping;** **DD** **carries** **normative** **grammar** **and** **precedence.** **FR-035** **+** **NFR-001** **—** **clarified** **per-user** **concurrent** **sessions** **(product** **policy** **in** **DD)** **vs.** **aggregate** **deployment** **capacity** **(hardware,** **network,** **multi-instance** **routing** **per** **HLA;** **stress** **scenarios** **optional** **in** **Test** **Plan).** **FR-027** **note** **cross-ref** **FR-033.** **NFR-004** **admin** **guide** **covers** **password** **policy.** **Risk** **row** **for** **search** **parsing.** **Version** **0.7,** **Last** **revised** **2026-04-08** **UTC.**

**Documentation:** [`../srs.md`](../srs.md "Srs").

---

## 2026-04-07 — SRS v0.6: sequential FR-001–041, governance + security + catalog gaps

**Summary:** **Renumbered** **functional** **requirements** **to** **FR-001–FR-030** **strict** **order** **(keywords** **FR-009,** **release** **FR-030).** **Added** **FR-031–FR-041:** **account**/**role** **admin,** **bootstrap,** **password** **change**/**admin** **reset,** **auth** **throttling,** **sessions,** **corpus** **storage** **model,** **catalog** **browse**/**pagination,** **search** **semantics** **(AND** **default),** **index** **rebuild,** **metadata** **validation,** **optimistic** **concurrency.** **Expanded** **FR-026** **audit** **(enable**/**disable,** **denied** **access** **default).** **NFR-001** **design-center** **100k;** **NFR-009** **TLS** **defaults.** **Header:** **Last** **revised** **2026-04-07** **UTC;** **§15–§16** **refresh.** **§8** **time** **sync** **assumption.**

**Open** **product** **choices** **embedded** **(revisit** **if** **needed):** **v1** **search** **default** **=** **AND** **of** **terms,** **case-insensitive** **Latin;** **concurrent** **sessions** **=** **policy** **choice** **in** **DD** **(cap** **vs** **unlimited);** **self-service** **email** **password** **recovery** **=** **deferred** **(§13).** **(Superseded** **for** **search**/**sessions**/**password** **by** **2026-04-08** **v0.7** **entry** **above.)**

**Documentation:** [`../srs.md`](../srs.md "Srs").

---

## 2026-04-06 — SRS v0.5: operational/diagnostic logs, Settings, compliance

**Summary:** **FR-030** — **client** **and** **server** **operational** **and** **diagnostic** **logs**, **independent** **enable**/**disable** **per** **category**, **Settings** **(FR-027)** **/** **server** **admin** **UI**, **platform-default** **paths**, **day-based** **rollover** **+** **FR-024** **maximum** **retention**. **NFR-008** **privacy**/**jurisdictional** **readiness**. **Definitions**, **NFR-004**/**007**, **§9–§12**, **FR-020**, **risks** **updated**.

**Documentation:** [`../srs.md`](../srs.md "Srs").

---

## 2026-04-06 — SRS v0.4: warm sepia / parchment default theme

**Summary:** **FR-029** now **requires** a **shipped** **warm sepia** theme (**parchment-style** **background** allowed). **NFR-006** **contrast** **applies** to **all** **shipped** themes **including** sepia—**no** **WCAG** **waivers** for **decorative** **backgrounds**.

**Documentation:** [`../srs.md`](../srs.md "Srs").

---

## 2026-04-06 — SRS v0.3: NFR-007 end-user docs and Help

**Summary:** Added **NFR-007** (user manual, quick-start, **Help** affordance to version-matched docs; packaging **TBD** HLA). **Searchable** help index and **context-sensitive** help in **waiting room**; **pre-built** help components allowed if license/a11y OK. **NFR-004** clarified vs end-user docs; **§2.2**, **FR-020**, **§14** updated.

**Documentation:** [`../srs.md`](../srs.md "Srs"); [`../../user-documentation/README.md`](../../user-documentation/README.md "Readme").

---

## 2026-04-06 (later) — SRS v0.2: Settings, reader preferences, theme

**Summary:** Extended [`../srs.md`](../srs.md "Srs") with **FR-027** (Settings facility, extensible), **FR-028** (preferred external reader per supported document type with platform-default fallback), **FR-029** (light/dark theme, **match system** where feasible). **NFR-006** ties shipped themes to **WCAG 2.1 AA** contrast for the shell. **FR-018** updated to honor reader preferences. **Waiting room:** third-party theme packs, preference sync across devices.

**Decisions**

- **None** beyond adopting draft requirement text pending review.

**Documentation:** [`../srs.md`](../srs.md "Srs").

---

## 2026-04-06 — SRS initial draft (`srs.md` v0.1)

**Summary:** Added **[`../srs.md`](../srs.md "Srs")** as **draft** SRS (**FR-001–FR-026**, **NFR-001–NFR-005**), derived from **`concept.md`** and **`project-primer.md`**. **Phase gate** in SRS **§16** records **not** ready for Architecture until **review**, **RTM**, and **human approval**. **PDF/DOCX** mandatory for v1; **EPUB** and several items remain **waiting room**.

**Decisions**

- **None finalized** — document is **draft** for review.

**Documentation:** [`../srs.md`](../srs.md "Srs"); [`../README.md`](../README.md "Readme") (artifact index).

---

## 2026-04-05 22:30 UTC — Documentation layout: `system-documentation/`

**Summary:** Reorganized documentation under **`system-documentation/`** with **`system-artifacts/`** (concept, lifecycle, future SRS/HLA/DD/tests/RTM) and **`user-documentation/`** (guides). Removed **`AI-Bootstrap/`** toolkit copy from this product repo. **`docs/`** reserved for optional **GitHub Pages** site later.

**Decisions**

- **Cursor rules** now reference **`system-documentation/system-artifacts/LIFECYCLE.md`** and artifacts under **`system-documentation/system-artifacts/`** (no `AI-Bootstrap/` paths).

**Documentation:** `system-documentation/README.md`; migrated `concept.md`, `_process/*`; new stubs in `user-documentation/`.

---

## 2026-04-05 21:45 UTC — Ideation gate: authorized to Requirements

**Summary:** Project owner **closed Ideation for this cycle** and **authorized** advancement to the **Requirements** phase, with explicit acceptance that **unknowns remain** and **rollback** remains possible per [`../LIFECYCLE.md`](../LIFECYCLE.md "Lifecycle").

**Decisions**

- **Gate:** `system-documentation/system-artifacts/_process/project-primer.md` **§12** completed (**Charles McKnight**, **2026-04-05**). **Primer version → 1.0**; **lifecycle phase** noted as **Requirements** (Ideation closed).
- **RTM scaffold** still **not** created—appropriate when **SRS / traceability** work begins.

**Documentation:** `system-documentation/system-artifacts/concept.md` (lifecycle note); `system-documentation/system-artifacts/_process/project-primer.md`; this log.

---

## 2026-04-05 21:30 UTC — SignPath for non-Apple release signing

**Summary:** Document **SignPath** as the **planned** path for **official** Windows/Linux (non-Apple) **signed release** binaries; clarify **source builds** may be **unsigned**; **Apple** remains a **separate** pipeline.

**Decisions**

- **OSS-appropriate:** Signing is for **published release artifacts** and user trust—not a requirement for **license** or **building from source**.
- **CI:** Integrate **SignPath** (or successor/equivalent) **as applicable** per platform; details **TBD** in release/HLA work.

**Documentation:** `system-documentation/system-artifacts/concept.md`, `system-documentation/system-artifacts/_process/project-primer.md` (v**0.5**).

---

## 2026-04-05 21:15 UTC — Apache-2.0, duplicate policy, backup/logs, dual installers

**Superseded (license only):** see `2026-04-26 — Project license: GPL-3.0-or-later` for the current repository license decision.

**Summary:** Locked **Apache License 2.0** (pending **IP counsel** final sign-off); clarified **SHA-256 duplicate** handling, **backup/logging** intent, and **two installer** lines.

**Decisions / artifacts**

- **License:** **Apache-2.0** chosen; added repository root **`LICENSE`** (verbatim text) and **`NOTICE`** (copyright + placeholder for dependency notices). **`system-documentation/system-artifacts/_process/open-source-license.md`** updated to **recorded decision**; **counsel review** still **pending**.
- **Duplicates:** same **content digest** → **warn** user; **explicit user choice** on how to proceed (**no** silent merge/skip by default).
- **Backup / logs:** **ideal** backup scope = **corpus + DB + index + config + logs**; **practical** scope **operator-dependent**; **log rotation/retention** = **admin-configurable** (mechanism **TBD** Requirements/HLA).
- **Installers:** expect **solo** (client + co-located server) vs **server/self-hosted multi-user** packaging (**HLA**/release detail).

**Documentation**

- `system-documentation/system-artifacts/concept.md`, `system-documentation/system-artifacts/_process/project-primer.md` (v**0.4**), `system-documentation/system-artifacts/_process/open-source-license.md`, `system-documentation/system-artifacts/_process/discussion-log.md`; **`LICENSE`**, **`NOTICE`**.

---

## 2026-04-05 21:05 UTC — Optional server autostart / always-on

**Summary:** Capture need for **user-configurable** startup so the **library server** can run **continuously** (login or boot) without requiring the **desktop client UI** first.

**Decisions / artifacts**

- **Likely in-scope:** optional **start server at OS user login** or **system startup** (exact options **TBD**), so solo or small-team deployments can keep the server **reachable** for local/remote clients.
- **Deferred to Requirements / HLA:** per-OS mechanisms (e.g. **LaunchAgent**, **systemd**, **Windows** service vs user startup), **which account** runs the server, and **security** implications.

**Documentation**

- `system-documentation/system-artifacts/concept.md` (corpus/ops); `system-documentation/system-artifacts/_process/project-primer.md` (v0.3).

---

## 2026-04-05 20:49 UTC — Client–server shape, DRM EPUB keywords, accessibility, ops

**Summary:** Captured follow-on Ideation decisions from working session: solo vs multi-user clarified as **one product shape** (server-authoritative security); format and network deferrals tightened.

**Decisions / artifacts**

- **Topology:** MyLib is **client–server**. **Authentication** (and RBAC enforcement for remote use) lives on the **server**; **desktop/solo** = server **co-located** on the same machine (e.g. loopback), not reliance on **UI-only** admin hiding.
- **Auth v1:** **Local accounts**; directory/SSO etc. deferred unless reprioritized.
- **DRM-protected EPUB:** no full-text index without lawful content access; **user-associated keyword lists** (**separate from tags**) for discoverability when indexing is blocked.
- **Duplicates:** **SHA-256** (or equivalent) **content digest** from the outset; merge/dedup policy details → Requirements.
- **Accessibility:** **WCAG 2.1 Level AA** target for **shell UI** where achievable.
- **Network:** **Minimize outbound** by default; **version / update notification** desired—**final mechanism** (privacy, opt-in, endpoints) → **Requirements / HLA**.
- **Hosting:** Maintainer **does not** plan to operate **SaaS**; **support via GitHub**; others may self-host/fork. **Exposing** the server (e.g. **open port**) = **operator** responsibility.
- **Formats (phasing intent):** **PDF and DOCX** likely before **full EPUB** depth; EPUB = ZIP/HTML indexing when no DRM.

**Technology**

- **Stack** (Electron vs Qt, etc.) still **undecided**; **client–server** accepted as **logical** architecture only.

**Documentation**

- Updated `system-documentation/system-artifacts/concept.md`, `system-documentation/system-artifacts/_process/project-primer.md` (version **0.2**).

---

## 2026-04-05 19:46 UTC — Discussion log format

**Summary:** Established this file as the running log for conversation outcomes.

**Decisions / artifacts**

- Maintain project narrative in `system-documentation/system-artifacts/concept.md` and structured Ideation in `system-documentation/system-artifacts/_process/project-primer.md`; use **this file** for **time-ordered** deltas from working sessions.
- License selection notes live in `system-documentation/system-artifacts/_process/open-source-license.md` (working preference: **Apache-2.0**, **MIT** fallback); root `LICENSE` still **TBD**.

**Technology**

- No new stack choices in this entry.

---

## 2026-04-05 (session) — License direction

**Summary:** Captured permissive-license comparison for counsel review later.

**Decisions**

- **Primary direction:** Apache License 2.0 (patent grant, NOTICE, permissive).
- **Fallback:** MIT if simplicity outweighs Apache’s structure.
- **Not** defaulting to GPL/AGPL unless copyleft becomes an explicit goal.

**Technology**

- N/A (legal/process).

**Reference:** `system-documentation/system-artifacts/_process/open-source-license.md` (committed as initial repo commit `fa69086`).

---

## 2026-04-03 (session) — Ideation artifacts and product boundaries

**Summary:** Folded extended Ideation into `system-documentation/system-artifacts/concept.md` and created `system-documentation/system-artifacts/_process/project-primer.md` (template-aligned). Aligned AI-Bootstrap paths and Cursor rules earlier in the same initiative.

**Product / scope decisions**

- **Desktop first** (Windows, macOS, Linux); **standalone web client deferred**; install acceptable for individuals, families, small teams—not SharePoint-class enterprise.
- **Native readers** preferred for **display/print**; MyLib does not own export/print; **open file** baseline; **pass search term to reader** optional/best-effort, not guaranteed across viewers.
- **Precise “jump to hit” in arbitrary external PDF readers** treated as **non-portable**; do not promise universal deep-linking.
- **Multi-user** with **RBAC**; single-user as degenerate case; **tenant boundary** = admin responsibility, app enforces.
- **Corpus:** user/admin-specified (local or remote); scale **10³–10⁵+** docs; personal driver ~**10k** pubs from diverse sources.
- **Document model:** each edition = **distinct document**; **missing file** → user **relink** via dialog (no silent relearn); **symlinks** unlikely v1; **delete from app** vs **delete file on disk** = separate with admin prompt.
- **Ingestion:** menu + file dialog first; **bulk import** likely later with **OCR/review** burden acknowledged; **tables/cursed PDFs** complicate extraction.
- **Metadata:** Dublin Core–ish + author, publisher, series; **free-form tags** initially; TTRPG **game system** as tag vs field **TBD**.
- **Bookmarks:** **reader-owned**, not MyLib.
- **Cartridge / package (working idea):** zip (or similar) with **PDF (unchanged)**, **metadata sidecar**, **index blob** + **versioned manifest** (checksums, provenance); **authoring tool** may correct **OCR for indexing only**—**not** “fix and republish” third-party PDFs; **index** should trend toward **proper inverted index** (positions/postings), not only unique word lists + stopword culling.
- **Deferred:** offline/sync, public API, scripting, numeric performance SLAs, i18n (English first).
- **Distribution:** GitHub Pages + Releases pattern; Apple **signing/notarization** (not App Store initially); other platforms e.g. SignPath-class; **updater** TBD (Sparkle vs stack-native).
- **Accessibility:** **hard requirement** for shell UI.
- **Legal posture (product intent, not advice):** tool for cataloging owned materials; no DRM removal; not distributing user-built cartridges as part of maintainer obligations; operators responsible for lawful use.

**Technology choices**

- **Desktop stack:** **not chosen** (e.g. Electron-class vs Qt-class called out as **alternatives only** in primer—no winner in Ideation).
- **Search index implementation:** not chosen; direction toward **manifest + structured index artifact** and **library-wide merge** on ingest.

**Open / carry to Requirements**

- Open-source **license** final pick and root `LICENSE`.
- **RTM scaffold** not created (per primer).
- **Gate to Requirements:** explicit human approval only (`system-documentation/system-artifacts/_process/project-primer.md` §12).

---

## How to append

Copy this template to the **top** of the log (below the header lines and the `---` after “Last updated”):

```markdown
## YYYY-MM-DD HH:MM UTC — Short title

**Summary:** One or two sentences.

**Decisions / artifacts**
- …

**Technology**
- … (or “None.”)

**Deferred / open**
- … (optional)

---
```

Then update **Last updated** to match the new entry’s timestamp.

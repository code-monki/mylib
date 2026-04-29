<!--
File: system-documentation/system-artifacts/test-plan.md

Purpose:
  Define enforceable validation governance and implementation-ready
  test-contract coverage for MyLib v1.
-->

# Test Plan

**Project Name:** MyLib  
**Version:** 0.1  
**Date (YYYY-MM-DD):** 2026-04-28  
**Author(s):** Charles McKnight  
**Status:** Approved  
**Requirement Version Reference:** SRS v0.9 **Approved** ([`srs.md`](srs.md "Srs"))  
**Architecture Version Reference:** HLA v0.1.2 **Approved** ([`hla.md`](hla.md "Hla"); approved 2026-04-25)  
**Detailed Design Version Reference:** DD v0.1 **Approved** ([`dd.md`](dd.md "Dd"); approved 2026-04-28; API/data contracts **§5.1.3**, **§5.2**, **§5.3.8**–**§5.3.19**)  
**RTM Version Reference:** RTM v0.1 **Approved** ([`rtm.md`](rtm.md "Rtm"); approved 2026-04-28)

---

# 1. Test Authority Declaration

Confirm:

- Requirements approved? **Yes**
- Architecture approved? **Yes**
- Detailed Design approved? **Yes**
- RTM initialized? **Yes**
- Advancement to Test Planning authorized? **Yes**

---

# 2. Test Scope

In scope:

- FR-001 through FR-041.
- NFR-001 through NFR-009.
- API/data/message contract validation from DD **`§5.1.3`** (logical identity, RBAC, and tenant membership persistence), **`§5.2`** (serialization and canonical envelope), and **`§5.3`** (route index **`§5.3.1`–`§5.3.6`**, transport **`§5.3.7`**, concrete JSON **`§5.3.8`–`§5.3.18`**, C++ interface baseline **`§5.3.19`**).
- Deterministic-probabilistic OCR containment and sidecar behavior from DD `§4.9`.
- Cross-platform packaging validation targets (`.dmg`, `.msi`, `.deb`, `.rpm`, `AppImage`) from DD `§9.2`.

Out of scope for this draft:

- Final per-endpoint OpenAPI artifact generation (implementation-phase deliverable).
- Production load thresholds for search transition gate (telemetry-dependent, DD `§4.6.9`).

---

# 3. Test Objectives

- Prove each approved requirement has at least one executable validation path.
- Prove all API families honor DD status/error contracts and security gating behavior.
- Prove OCR probabilistic behavior is contained, auditable, and recoverable.
- Prove packaging/build outputs are reproducible and traceable to release metadata.

Release-readiness posture:

- No unresolved high-severity defects.
- All critical FR/NFR tests pass.
- Traceability is complete in RTM with evidence links.

---

# 4. Test Strategy

## 4.1 Testing Levels

Applicable levels:

- Unit testing: component-local validation (domain/security/search/storage/ocr logic).
- Integration testing: server API + DB + OCR + search + auth + logging interactions.
- System testing: end-to-end user/admin workflows across deployment profiles.
- Regression testing: suite rerun on PR and release branches.
- Performance testing: search/query/rebuild latency and ingest-to-search freshness.
- Security testing: authn/authz/session/JWT/throttling/revocation/key rotation.
- Reliability/resilience testing: dependency outages, deferred/escalation paths.
- Packaging validation: install/upgrade/uninstall behavior per target package family.
- Orchestration/clean build validation: CI matrix reproducibility and artifact integrity.

UAT is deferred to pre-release acceptance and will reference this plan.

## 4.2 Deterministic-Probabilistic Validation (OCR)

- Acceptance boundary: OCR output is derived, not canonical truth.
- Variability tolerance: `high`/`review_required`/`insufficient` classes per DD `§4.9.8`.
- Rejection criteria: unbounded deferred state, invalid provenance, stale correction conflict, or silent quality downgrade.
- Containment tests: deterministic status mapping at OCR boundary and ingest/search handoff.
- Fallback tests: correction workflow, sidecar reuse/reprocess decisions, viewer handoff resilience.
- Observability tests: required correlation/provenance fields, redaction compliance.

## 4.3 Functional Validation

Functional suites are organized by API family and requirement clusters:

- `TP-AUTH-*`: `/api/v1/auth/*` and security policy.
- `TP-CATALOG-*`: `/api/v1/catalog/*` and domain mutation/read paths.
- `TP-SEARCH-*`: `/api/v1/search/*` query and rebuild behavior.
- `TP-INGEST-*`: `/api/v1/ingest/*` lifecycle and duplicate gating.
- `TP-OCR-*`: `/api/v1/ocr/*` OCR/correction/reprocess.
- `TP-STORAGE-*`: `/api/v1/storage/*` resolve/open/relink/remove.
- `TP-ADMIN-*`: `/api/v1/admin/*` and `/api/v1/security/*`.
- `TP-OPS-*`: `/api/v1/ops/*` and `/api/v1/release/*`.

Each family includes positive, validation-negative, auth-negative, and dependency-unavailable cases (DD `§5.2.5`). Contract assertions SHOULD cite the matching concrete schema subsection (for example RBAC/admin **`§5.3.12`**, bootstrap **`§5.3.18`**, duplicate-decision **`§5.3.16`**, **`GET /ops/health`** in **`§5.3.15`**) alongside component behavior in DD **`§4.x`**.

## 4.4 Non-Functional Validation

- NFR-001: scale posture (query/rebuild/index and ingest concurrency).
- NFR-002: server-side enforcement (no client trust bypass).
- NFR-003: release/legal metadata presence and consistency.
- NFR-004: operator-facing error/remediation and runbook observability.
- NFR-005: honest degraded/deferred/failure messaging.
- NFR-006/NFR-007: shell theme/accessibility/help discoverability.
- NFR-008: privacy-preserving logging/audit behavior.
- NFR-009: remote transport security and trust posture.

---

# 5. Traceability Enforcement

- Every test case ID SHALL map to one or more SRS requirement IDs in RTM.
- Every FR/NFR SHALL map to at least one test case.
- RTM updates are mandatory for:
  - Test Case ID
  - Validation status
  - Evidence reference (test run, report, or artifact URI/path)

Test case ID convention (v1):

- `TP-<FAMILY>-<NNN>` (example: `TP-SEARCH-014`).
- `FAMILY` in `{AUTH,CATALOG,SEARCH,INGEST,OCR,STORAGE,ADMIN,OPS,PKG,NFR}`.

## 5.1 Initial canonical test case catalog (v0.1 seed)

This seed catalog establishes canonical IDs for implementation and RTM mapping. Individual step-by-step procedures will be authored in the test-suite specifications.

| Test Case ID | Family | Primary requirement targets | Intent |
| ------------ | ------ | --------------------------- | ------ |
| `TP-AUTH-001` | AUTH | FR-016 | Invalid credentials are rejected without enumeration |
| `TP-AUTH-002` | AUTH | FR-016 | Successful login returns access + refresh session material |
| `TP-AUTH-003` | AUTH | FR-016, NFR-002 | Invalid/expired access token denied before protected dispatch |
| `TP-AUTH-004` | AUTH | FR-034 | Throttle/lockout triggers and clears per policy |
| `TP-AUTH-005` | AUTH | FR-035 | Refresh rotation and replay detection behavior |
| `TP-AUTH-006` | AUTH | FR-033 | Must-change-password and reset flow enforcement |
| `TP-AUTH-007` | AUTH | FR-035 | JWKS unknown `kid` refresh and fail-closed behavior |
| `TP-AUTH-008` | AUTH | FR-035 | Key-rotation overlap and stale-key expiry behavior |
| `TP-CATALOG-001` | CATALOG | FR-001, FR-002 | Record create/read contract baseline |
| `TP-CATALOG-002` | CATALOG | FR-003, FR-040 | Metadata/tag validation and rejection semantics |
| `TP-CATALOG-003` | CATALOG | FR-041 | Optimistic concurrency conflict behavior |
| `TP-CATALOG-004` | CATALOG | FR-037 | Browse/sort/pagination deterministic behavior |
| `TP-SEARCH-001` | SEARCH | FR-007, FR-038 | Query grammar (AND/OR/NOT/grouping/phrase) correctness |
| `TP-SEARCH-002` | SEARCH | FR-009 | Keyword fallback path signaling |
| `TP-SEARCH-003` | SEARCH | FR-039 | Rebuild authorization and lifecycle transitions |
| `TP-SEARCH-004` | SEARCH | FR-006 | Index unavailable/degraded behavior classification |
| `TP-INGEST-001` | INGEST | FR-004, FR-005 | Supported/unsupported import type gating |
| `TP-INGEST-002` | INGEST | FR-010 | Duplicate detection decision workflow |
| `TP-INGEST-003` | INGEST | FR-006, FR-023 | OCR-required ingest path and provenance capture |
| `TP-INGEST-004` | INGEST | FR-004 (Notes), DD §4.1.2.1 | Import metadata hints: user confirms; no auto-commit from lookups |
| `TP-OCR-001` | OCR | FR-023 | OCR profile selection and quality classification |
| `TP-OCR-002` | OCR | FR-023, FR-039 | Correction submit and reindex trigger behavior |
| `TP-OCR-003` | OCR | FR-023 | Sidecar import/reuse vs reprocess decision behavior |
| `TP-STORAGE-001` | STORAGE | FR-011 | Missing-file detection and remediation status behavior |
| `TP-STORAGE-002` | STORAGE | FR-012 | Remove-from-catalog vs delete-on-disk policy split |
| `TP-STORAGE-003` | STORAGE | FR-019, FR-021 | Mediated open-in-reader behavior and preference rules |
| `TP-ADMIN-001` | ADMIN | FR-031 | Account/role administration authorization matrix |
| `TP-ADMIN-002` | ADMIN | FR-032 | Bootstrap single-use and post-bootstrap lockout |
| `TP-ADMIN-003` | ADMIN | FR-017, FR-018 | RBAC + tenant-boundary denial matrix |
| `TP-OPS-001` | OPS | FR-030, NFR-003 | Release metadata identity/provenance/legal presence |
| `TP-OPS-002` | OPS | FR-026, NFR-008 | Audit event integrity and minimized log/privacy posture |
| `TP-PKG-001` | PKG | NFR-004 | Package install smoke validation for `.dmg`/`.msi`/`.deb`/`.rpm`/`AppImage` |
| `TP-PKG-002` | PKG | NFR-004, NFR-009 | Packaging trust/signing workflow verification posture |
| `TP-NFR-001` | NFR | NFR-001 | Scale-oriented performance baseline capture |
| `TP-NFR-002` | NFR | NFR-005 | Honest degraded/deferred/failure messaging verification |
| `TP-NFR-003` | NFR | NFR-006, NFR-007 | Theme contrast + help discoverability checks |
| `TP-NFR-004` | NFR | NFR-002 | Qt Quick/QML presentation remains non-authoritative; C++/server security boundary preserved |

## 5.2 Executable specification set (high-risk suites, v0.1)

The following specifications are implementation-ready skeletons for immediate test authoring.

### 5.2.1 AUTH suite executable specs

#### `TP-AUTH-001` — Invalid credentials are rejected without enumeration

- **Requirements:** FR-016
- **Preconditions:** test user exists; auth service healthy.
- **Steps:**
  1. Submit `/api/v1/auth/login` with valid username + wrong password.
  2. Submit `/api/v1/auth/login` with non-existent username + any password.
  3. Compare status class, error class, and user-visible message shape.
- **Expected outcomes:**
  - Both requests return authentication rejection semantics without identity disclosure.
  - No response reveals whether username exists.
  - Audit/ops events emitted with correlation IDs and minimized sensitive content.
- **Evidence:** API response captures, structured logs (redacted), audit event excerpt.

#### `TP-AUTH-005` — Refresh rotation and replay detection behavior

- **Requirements:** FR-035
- **Preconditions:** authenticated session with valid refresh token; replay protection enabled.
- **Steps:**
  1. Use refresh token once and capture rotated refresh material.
  2. Replay old refresh token.
  3. Attempt refresh with rotated token after replay event.
- **Expected outcomes:**
  - First refresh succeeds and rotates token family state per policy.
  - Replayed token is rejected with deterministic failure class.
  - Post-replay behavior follows configured policy (family revocation / deny further refresh).
- **Evidence:** token lifecycle trace, API responses, security audit events.

#### `TP-AUTH-007` — Unknown `kid` handling and fail-closed behavior

- **Requirements:** FR-035, NFR-002
- **Preconditions:** client verifier cache present; server keyset without target `kid`.
- **Steps:**
  1. Present access token signed with unknown `kid`.
  2. Force one JWKS refresh attempt.
  3. Retry verification after refresh.
- **Expected outcomes:**
  - Verification fails closed if `kid` remains unresolved.
  - Refresh attempt is bounded (no unbounded loop).
  - Protected route is not dispatched downstream.
- **Evidence:** verifier logs, JWKS fetch traces, protected-route rejection response.

### 5.2.2 OCR suite executable specs

#### `TP-OCR-001` — OCR profile selection and quality classification

- **Requirements:** FR-023
- **Preconditions:** fixtures for text-layer PDF, clean scan, and noisy scan.
- **Steps:**
  1. Ingest text-layer PDF and observe profile selection.
  2. Ingest clean scan and observe OCR profile.
  3. Ingest noisy/low-contrast scan and force retry/reprocess path.
- **Expected outcomes:**
  - `extract_only`, `ocr_quick`, and `ocr_robust` selection rules align with DD `§4.9.8`.
  - Output quality class recorded as `high`, `review_required`, or `insufficient`.
  - Provenance captures profile and threshold context.
- **Evidence:** ingest/OCR API results, provenance payloads, sidecar/projection metadata.

#### `TP-OCR-002` — Correction submission and reindex trigger

- **Requirements:** FR-023, FR-039
- **Preconditions:** OCR artifact exists with editable text; user has correction role.
- **Steps:**
  1. Submit correction against current artifact version.
  2. Verify new artifact version and lineage link.
  3. Confirm reindex job enqueue/execution state.
- **Expected outcomes:**
  - Correction accepted only with valid version token.
  - New immutable artifact version created with actor/timestamp attribution.
  - Reindex path runs and updates searchable projection (or returns explicit degraded/deferred status).
- **Evidence:** correction response, lineage metadata, search visibility check, index job logs.

#### `TP-OCR-003` — Sidecar import reuse vs reprocess decision

- **Requirements:** FR-023
- **Preconditions:** exportable sidecar with `source_fingerprint`; matching and mismatched source fixtures.
- **Steps:**
  1. Import sidecar with matching fingerprint.
  2. Import sidecar with mismatched fingerprint.
  3. Execute operator-selected reprocess on mismatched case.
- **Expected outcomes:**
  - Matching sidecar is accepted for index seeding where policy allows.
  - Mismatched sidecar is classified stale/incompatible (no silent acceptance).
  - Reprocess path creates new artifact/provenance consistent with current profile thresholds.
- **Evidence:** import responses, fingerprint validation records, reprocess output lineage.

### 5.2.3 PKG suite executable specs

#### `TP-PKG-001` — Multi-platform package install smoke validation

- **Requirements:** NFR-004
- **Preconditions:** release-candidate artifacts for `.dmg`, `.msi`, `.deb`, `.rpm`, `AppImage`.
- **Steps:**
  1. Install each package type in clean environment.
  2. Launch app/server process and run health/readiness check.
  3. Perform uninstall/cleanup and verify residue policy.
- **Expected outcomes:**
  - Install succeeds with documented prerequisites.
  - Runtime starts and serves baseline ops endpoints.
  - Uninstall behavior matches platform policy and does not leave unsafe config/secrets exposure.
- **Evidence:** install logs, startup/health outputs, uninstall reports per platform.

#### `TP-PKG-002` — Packaging trust/signing workflow verification

- **Requirements:** NFR-004, NFR-009
- **Preconditions:** signed artifacts where required by platform/release policy.
- **Steps:**
  1. Verify artifact signature/notarization metadata per platform.
  2. Attempt install/launch with trust verification enabled.
  3. Validate remote TLS defaults post-install for multi-user profile.
- **Expected outcomes:**
  - Artifact trust metadata validates successfully (or failure is explicit/blocking).
  - Platform trust warnings are not normalized as acceptable workflow.
  - Remote deployment profile enforces secure transport defaults after install.
- **Evidence:** signature verification outputs, installer trust checks, post-install transport config evidence.

### 5.2.4 SEARCH suite executable specs

#### `TP-SEARCH-001` — Query grammar and result contract validation

- **Requirements:** FR-007, FR-038
- **Preconditions:** indexed fixture corpus with known token/tag distribution.
- **Steps:**
  1. Execute representative AND/OR/NOT/phrase/grouping queries.
  2. Submit malformed grammar inputs.
  3. Execute query with tag filters and paging parameters.
- **Expected outcomes:**
  - Valid grammar returns deterministic inclusion/exclusion results.
  - Malformed grammar returns `rejected_validation` with actionable errors.
  - Response envelope includes required diagnostics and paging context.
- **Evidence:** request/response captures, query fixture expectation sheet, contract assertion logs.

#### `TP-SEARCH-003` — Rebuild control lifecycle and authorization

- **Requirements:** FR-039
- **Preconditions:** admin and non-admin test principals; index state baseline captured.
- **Steps:**
  1. Trigger rebuild as non-admin.
  2. Trigger rebuild as admin with valid mode.
  3. Poll rebuild status endpoint through terminal states.
- **Expected outcomes:**
  - Non-admin call is denied with authorization status.
  - Admin call enters documented lifecycle (`queued`/`running`/terminal).
  - Status endpoint returns deterministic progression and failure/deferred metadata when applicable.
- **Evidence:** authorization denial capture, rebuild operation trace, lifecycle status timeline.

### 5.2.5 INGEST suite executable specs

#### `TP-INGEST-001` — Supported/unsupported import type gating

- **Requirements:** FR-004, FR-005
- **Preconditions:** supported and unsupported document fixtures available.
- **Steps:**
  1. Submit ingest for supported type.
  2. Submit ingest for unsupported type.
  3. Retrieve ingest job state for each submission.
- **Expected outcomes:**
  - Supported type enters accepted/processing lifecycle.
  - Unsupported type is rejected with explicit classification (no ambiguous failure).
  - Ingest state model remains monotonic and auditable.
- **Evidence:** ingest API responses, job state records, validation error payloads.

#### `TP-INGEST-002` — Duplicate decision workflow enforcement

- **Requirements:** FR-010
- **Preconditions:** existing record with matching digest present.
- **Steps:**
  1. Submit duplicate candidate import.
  2. Confirm job enters `awaiting_decision`.
  3. Execute both approve/deny decision branches.
- **Expected outcomes:**
  - Duplicate candidate does not auto-commit without decision.
  - Decision outcomes produce deterministic final states.
  - Audit/ops traces include decision actor and correlation metadata.
- **Evidence:** duplicate detection event, decision API responses, resulting catalog state diff.

#### `TP-INGEST-003` — OCR-required ingest path and provenance capture

- **Requirements:** FR-006, FR-023
- **Preconditions:** fixture PDF requiring OCR for searchable text; OCR pipeline available per deployment baseline.
- **Steps:**
  1. Submit ingest for OCR-required fixture.
  2. Observe ingest stages through OCR completion or documented degradation.
  3. Retrieve provenance/capture records tied to derived text where exposed by API or ops logs.
- **Expected outcomes:**
  - Ingest completes or degrades with explicit classification (no silent OCR skip).
  - Derived-text provenance is traceable for audit or remediation workflows per DD.
- **Evidence:** ingest job timeline, OCR invocation outcome, searchability verification post-index.

#### `TP-INGEST-004` — Import metadata hints: no auto-commit

- **Requirements:** FR-004 (Notes), DD §4.1.2.1, shell import UX
- **Preconditions:** import dialog available; at least one external lookup provider enabled in test configuration (or disabled path covered in second run).
- **Steps:**
  1. Select a PDF; trigger optional metadata lookup if present.
  2. Observe candidate results prefilled or offered as suggestions.
  3. Change a field; confirm import only after explicit user submit.
  4. Repeat with lookup disabled or provider failure simulated.
- **Expected outcomes:**
  - Catalog record matches user-confirmed field values, not raw provider payload without confirmation.
  - With provider unavailable, import still completes using manual or embedded metadata path.
- **Evidence:** UI state capture, request payload to ingest API, resulting record metadata.

### 5.2.6 STORAGE suite executable specs

#### `TP-STORAGE-001` — Missing file detection and remediation signaling

- **Requirements:** FR-011
- **Preconditions:** catalog record referencing an intentionally unavailable/moved source file.
- **Steps:**
  1. Execute storage resolve/read-open path.
  2. Run health/remediation check for missing reference.
  3. Observe client-visible status and remediation hint.
- **Expected outcomes:**
  - Missing file is reported as explicit degraded/missing state.
  - No silent path substitution occurs.
  - Remediation guidance is available through documented status fields.
- **Evidence:** storage response captures, domain degraded-state marker, ops diagnostic event.

#### `TP-STORAGE-002` — Remove vs delete policy split

- **Requirements:** FR-012
- **Preconditions:** record linked to accessible source file; admin and non-admin principals.
- **Steps:**
  1. Execute remove-from-catalog intent.
  2. Execute delete-on-disk intent without elevated confirmation.
  3. Execute delete-on-disk with required confirmation and permission.
- **Expected outcomes:**
  - Remove leaves source bytes intact while catalog reference changes.
  - Unconfirmed/unauthorized delete is rejected.
  - Authorized confirmed delete executes with explicit outcome classification.
- **Evidence:** filesystem/corpus state checks, API responses, audit entries.

### 5.2.7 ADMIN suite executable specs

#### `TP-ADMIN-001` — Account/role administration authorization matrix

- **Requirements:** FR-031
- **Preconditions:** admin and non-admin principals in distinct tenant scopes.
- **Steps:**
  1. Attempt account/role mutation as non-admin.
  2. Perform same mutation as admin.
  3. Verify effective permissions on subsequent protected operations.
- **Expected outcomes:**
  - Non-admin mutation denied with `rejected_forbidden`.
  - Admin mutation succeeds with updated role/tenant state.
  - Authorization effects apply on next policy check as documented.
- **Evidence:** mutation responses, user-role state snapshot, policy-evaluation logs.

#### `TP-ADMIN-002` — Bootstrap single-use and post-bootstrap lockout

- **Requirements:** FR-032
- **Preconditions:** clean-install security store and bootstrap path enabled.
- **Steps:**
  1. Create first administrator via bootstrap path.
  2. Attempt to reuse bootstrap path.
  3. Verify normal auth/admin flows continue for created administrator.
- **Expected outcomes:**
  - Bootstrap succeeds exactly once.
  - Reuse attempt is rejected deterministically.
  - Bootstrap completion emits expected audit/ops signals.
- **Evidence:** bootstrap invocation logs, rejection response, audit/ops event captures.

### 5.2.8 OPS suite executable specs

#### `TP-OPS-001` — Release metadata identity/provenance/legal presence

- **Requirements:** FR-030, NFR-003
- **Preconditions:** build/release artifact with populated release metadata endpoint/source.
- **Steps:**
  1. Query `/api/v1/release/metadata`.
  2. Validate identity fields against build provenance references.
  3. Validate legal reference fields and offline availability requirements.
- **Expected outcomes:**
  - Metadata response includes canonical release identity and provenance fields.
  - Legal/notice references are present and coherent with release descriptor policy.
  - Mismatch/failure classes follow DD `§4.12.5` taxonomy.
- **Evidence:** release metadata response, build provenance record, legal-reference check report.

#### `TP-OPS-002` — Audit integrity and minimized log/privacy posture

- **Requirements:** FR-026, NFR-008
- **Preconditions:** audit and obslog sinks configured; security-relevant actions available.
- **Steps:**
  1. Execute security-relevant actions that must emit audit events.
  2. Inspect audit stream for required identity/action/outcome fields.
  3. Inspect operational logs for redaction/minimization compliance.
- **Expected outcomes:**
  - Audit events are append-only and include required envelope metadata.
  - Operational logs exclude disallowed sensitive payloads/secrets.
  - Correlation IDs enable join between audit and ops without leaking restricted content.
- **Evidence:** audit event samples, redacted operational log extracts, policy-compliance checklist.

### 5.2.9 NFR suite executable specs

#### `TP-NFR-001` — Scale-oriented performance baseline capture

- **Requirements:** NFR-001
- **Preconditions:** representative corpus and workload profile; controlled test environment.
- **Steps:**
  1. Execute baseline query mix under nominal load.
  2. Execute ingest + search overlap scenario.
  3. Capture rebuild duration and freshness-lag metrics.
- **Expected outcomes:**
  - P50/P95/P99 latency and freshness metrics captured per DD `§4.6.9` protocol.
  - No unclassified degraded/failure behavior under expected baseline load.
  - Measurement artifacts are reproducible and attributable to environment/version.
- **Evidence:** metrics report, workload profile manifest, environment/version snapshot.

#### `TP-NFR-002` — Honest degraded/deferred/failure messaging verification

- **Requirements:** NFR-005
- **Preconditions:** scenarios that trigger degraded, deferred, and failed outcomes.
- **Steps:**
  1. Trigger dependency-unavailable and degraded data-quality conditions.
  2. Trigger deferred operation with resume metadata requirements.
  3. Review API/UI message classes and next-action hints.
- **Expected outcomes:**
  - Status classes and message content remain policy-honest and non-misleading.
  - Deferred responses always include owner + resume condition.
  - No false success rendering for degraded/failed outcomes.
- **Evidence:** response payloads, UI/status captures, message taxonomy checklist.

#### `TP-NFR-003` — Theme contrast and help discoverability checks

- **Requirements:** NFR-006, NFR-007
- **Preconditions:** shell build with all shipped themes and help entry points enabled.
- **Steps:**
  1. Validate contrast/accessibility checks across light/dark/sepia themes.
  2. Verify help affordance discoverability in default navigation paths.
  3. Confirm help/about version alignment with running release identity.
- **Expected outcomes:**
  - Theme contrast meets documented accessibility baseline.
  - Help/manual surfaces are discoverable and version-matched.
  - Failures produce actionable validation records for remediation.
- **Evidence:** accessibility scan outputs, UI navigation captures, version-alignment checks.

#### `TP-NFR-004` — QML presentation boundary and security authority separation

- **Requirements:** NFR-002
- **Preconditions:** Qt Quick/QML shell build with C++ bridge instrumentation enabled.
- **Steps:**
  1. Exercise protected actions through normal UI paths and record bridge/API calls.
  2. Attempt UI-only manipulation/bypass scenarios (for example hidden-control invocation or altered client state) without valid server authorization.
  3. Verify resulting server-side authorization outcomes and client status rendering.
- **Expected outcomes:**
  - QML/Quick layer does not act as policy authority.
  - Protected operations still require server/C++ bridge authorization path.
  - UI manipulation without authorization cannot force protected action success.
- **Evidence:** bridge call traces, protected-route rejection responses, policy/audit correlation records.

## 5.3 TP-to-requirement quick map (review aid)

This appendix accelerates review by providing a condensed mapping from seeded canonical test IDs to primary requirement targets.

| Test Case ID | Primary requirement target(s) |
| ------------ | ----------------------------- |
| `TP-AUTH-001` | FR-016 |
| `TP-AUTH-002` | FR-016, FR-027 |
| `TP-AUTH-003` | FR-016, NFR-002 |
| `TP-AUTH-004` | FR-034 |
| `TP-AUTH-005` | FR-035 |
| `TP-AUTH-006` | FR-033, FR-027 |
| `TP-AUTH-007` | FR-035, NFR-002 |
| `TP-AUTH-008` | FR-035 |
| `TP-CATALOG-001` | FR-001, FR-002 |
| `TP-CATALOG-002` | FR-003, FR-040 |
| `TP-CATALOG-003` | FR-041 |
| `TP-CATALOG-004` | FR-037 |
| `TP-SEARCH-001` | FR-007, FR-038 |
| `TP-SEARCH-002` | FR-009 |
| `TP-SEARCH-003` | FR-039 |
| `TP-SEARCH-004` | FR-006 |
| `TP-INGEST-001` | FR-004, FR-005 |
| `TP-INGEST-002` | FR-010 |
| `TP-INGEST-003` | FR-006, FR-023 |
| `TP-INGEST-004` | FR-004 (Notes), DD §4.1.2.1 |
| `TP-OCR-001` | FR-023 |
| `TP-OCR-002` | FR-023, FR-039 |
| `TP-OCR-003` | FR-023 |
| `TP-STORAGE-001` | FR-011 |
| `TP-STORAGE-002` | FR-012 |
| `TP-STORAGE-003` | FR-019, FR-021 |
| `TP-ADMIN-001` | FR-031 |
| `TP-ADMIN-002` | FR-032 |
| `TP-ADMIN-003` | FR-017, FR-018 |
| `TP-OPS-001` | FR-030, NFR-003 |
| `TP-OPS-002` | FR-026, NFR-008 |
| `TP-PKG-001` | NFR-004 |
| `TP-PKG-002` | NFR-004, NFR-009 |
| `TP-NFR-001` | NFR-001 |
| `TP-NFR-002` | NFR-005 |
| `TP-NFR-003` | NFR-006, NFR-007 |
| `TP-NFR-004` | NFR-002 |

---

# 6. Test Environment

Baseline environments:

- CI matrix: Windows, macOS, Linux (GitHub Actions).
- DB backends: SQLite and PostgreSQL.
- Deployment profiles: solo loopback and remote multi-user TLS.
- OCR/search baseline tools: Tesseract/Leptonica/OpenCV/Poppler and SQLite FTS.
- Packaging-equivalent validation: `.dmg`, `.msi`, `.deb`, `.rpm`, `AppImage`.

All environment versions used in execution evidence SHALL be captured in run metadata.

---

# 7. Test Data Governance

- Use deterministic fixture corpus for core functional tests.
- Include cursed/low-quality PDFs and text-layer PDFs for OCR profile coverage.
- Include conflict/race fixtures for version-token and stale-edit cases.
- Include policy-sensitive security fixtures (lockout, token replay, revocation).
- Avoid personal data in test fixtures unless anonymized and approved.

---

# 8. Entry Criteria

Testing execution may begin when:

- DD remains approved (including DD **`§5`** contract depth referenced in **§2**).
- RTM includes DD references, **`§5`** cross-cutting contract pointers, and test-case placeholder structure.
- Initial test suites and fixtures are reviewed.
- CI environments and required dependencies are available.

---

# 9. Exit Criteria

Testing phase closes only when:

- All mandatory high-priority FR and critical NFR tests pass.
- No unresolved high-severity defects remain.
- OCR deterministic-probabilistic containment tests pass.
- Packaging and clean-build validations pass for all v1 target families.
- RTM is fully updated with evidence links.
- Human approval is granted.

---

# 10. Defect Governance

Severity classes:

- `S1 Critical`: security/data-loss/regulatory risk; release-blocking.
- `S2 High`: core requirement failure; release-blocking unless explicitly waived.
- `S3 Medium`: non-core functional degradation; fix or documented defer decision.
- `S4 Low`: cosmetic/non-blocking.

Critical defect protocol:

- root-cause analysis entry,
- regression test addition,
- RTM/evidence update,
- lifecycle rollback review if architectural/design assumptions are invalidated.

---

# 11. Automation and Orchestration Integration

- CI executes unit + integration + contract suites on every PR.
- Nightly/regression pipelines include heavier system/performance/OCR suites.
- Packaging validation and smoke-install tests run on release-candidate workflows.
- Failed mandatory gates block merge/release promotion.

---

# 12. Metrics and Reporting

Minimum reporting:

- Requirement coverage (% FR, % NFR with pass evidence).
- Test pass/fail/flaky rates per family.
- Defect density and severity trend.
- Mean time to detect and mean time to repair for blocking defects.
- API contract conformance rate (schema/envelope/status taxonomy against DD **`§5.2`**, **`§5.3.7`**, **`§5.3.8`–`§5.3.18`**).

---

# 13. Risk Assessment

High-risk concentration:

- Security/session/JWT/refresh/revocation flows.
- OCR quality and correction/reprocess integrity.
- Search rebuild and degraded-state honesty.
- Packaging/install trust/signing and cross-platform parity.
- Logging/audit privacy and jurisdictional constraints.

Risk-driven depth policy:

- Security, OCR containment, and packaging/install tests receive increased depth and mandatory regression coverage.

---

# 14. Phase Gate Declaration

Section **§14** tracks **test execution and evidence** completion. It is independent of **test plan document approval** (see **# Approval**).

Confirm readiness to proceed to Packaging & Orchestration:

- All mandatory tests executed? **No**  
- Validation evidence documented? **No**  
- Traceability updated? **No**  
- No orphan requirements? **No**  
- Deterministic-probabilistic containment validated? **No**  
- Human approval granted? **No**  

Current action: remain in Testing phase until execution evidence is complete.

---

# Approval

This Test Plan document is **Approved** as the validation governance baseline for MyLib v1; **§14** gate items remain **No** until mandatory test execution and evidence are complete.

Approved By: Charles McKnight  
Role: Maintainer  
Date: 2026-04-28  
Version Incremented: No

---

End of Test Plan

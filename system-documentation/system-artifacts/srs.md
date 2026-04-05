<!--
File: system-documentation/system-artifacts/srs.md

Purpose:
  Software Requirements Specification (SRS) for MyLib.

Lifecycle authority:
  LIFECYCLE.md

Requirements define intent.
They SHALL NOT encode architecture or implementation.
-->

# Software Requirements Specification (SRS)

Project Name: MyLib  
Version: 0.4  
Date (YYYY-MM-DD): 2026-04-06  
Author(s): Charles McKnight (draft; maintainers may revise)  
Status: Draft  
Project Primer Version Reference: 1.0 (`_process/project-primer.md`)  
RTM Scaffold Version: N/A (RTM not yet instantiated)  

---

# 1. Requirements Authority Declaration

Confirm:

- Ideation phase approved? **Yes** (2026-04-05; see `_process/project-primer.md` §12)  
- Project Primer stable? **Yes** (subject to lifecycle rollback if scope shifts materially)  
- Scope boundaries defined? **Yes** (see §2.2, §13)  
- Advancement to Requirements authorized? **Yes**  

---

# 2. Introduction

## 2.1 Purpose

This document specifies **software requirements** for **MyLib**, an **open-source** electronic document management system for **personal and small-team** corpora. It defines **what** the product must do, not **how** it is built. The intended audience is **product owners**, **architects**, **implementers**, **testers**, and **operators**.

## 2.2 Scope

**In scope (initial release target)**

- **Desktop client** applications on **Windows, macOS, and Linux** that connect to a **library server**.  
- **Server-side authentication** and **role-based access control** for documents and administrative functions.  
- **Solo deployment** where the server runs **co-located** on the same machine as the client (e.g. loopback), preserving server authority.  
- **Multi-user deployment** where the server is reachable over a network (exposure and hardening are **operator responsibilities**).  
- **Cataloging**, **metadata**, **free-form tags**, **full-text search** (where lawfully and technically feasible), **keyword-based discovery** when full-text indexing is not possible without circumventing protection measures, **duplicate detection** using a **content digest**, **missing-file detection and relink**, and **controlled removal** from the catalog vs **deletion on disk**.  
- **Opening documents in native reader applications** for display; MyLib does **not** replace those readers for rendering or printing.  
- **Shell UI accessibility** aligned with **WCAG 2.1 Level AA** as the conformance target (verification in test planning).  
- **English** user interface and documentation for the initial release.  
- **End-user documentation** (user manual, quick-start, in-app Help entry) per **NFR-007**.

**Explicitly out of scope (initial release)**

- **Standalone web client** (browser SPA) as a product surface.  
- **Offline replication / sync** between installations.  
- **Public HTTP API** and **end-user scripting** interfaces.  
- **Symbolic links** as first-class library paths (v1).  
- **Numeric performance SLAs** tied to specific hardware (deferred; see NFRs for qualitative scale).  
- **Features whose primary purpose is circumventing DRM** on copyrighted works.  
- **MyLib-provided** document **export**, **download**, or **print** flows (users may use capabilities of native readers where applicable).

**Ownership boundaries**

- **Operators** own **network exposure**, **backups**, **legal compliance**, and **tenant membership** configuration.  
- **The product** owns **enforcement of configured access policy** and **document library semantics** as specified herein.

---

# 3. System Overview

## 3.1 Problem Summary

Stakeholders managing **large, heterogeneous** electronic document collections (e.g. PDF, word-processing formats, EPUB-class content) suffer **fragmented discovery**, **weak cross-corpus search**, **unreliable jump from search hits to in-document context**, **inconsistent metadata**, and **limited governance** of who may access or alter content. At scale (**roughly 10³–10⁵+** documents), manual folder-based workflows **break down**. Impact falls on **researchers, archivists, small teams**, and **administrators** who must keep corpora **findable** and **access-controlled** without assuming **enterprise suite** budgets.

*(Problem framing only; see [`concept.md`](concept.md) and [`_process/project-primer.md`](_process/project-primer.md).)*

## 3.2 Definitions and Terminology

| Term                | Definition                                                                                                                                                                     |
| ------------------- | ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------ |
| **Catalog record**  | The logical library entry for a document **edition**, including metadata, tags, paths or storage references, and index state.                                                  |
| **Content digest**  | A cryptographic hash (e.g. **SHA-256**) computed over document **bytes** used to detect duplicates.                                                                            |
| **Full-text index** | Derived searchable text and index structures produced from document content where lawful and technically feasible.                                                             |
| **Keyword list**    | User-supplied search terms associated with a catalog record **separate from tags**, used when a **full-text index** cannot be built without circumventing protection measures. |
| **Library server**  | The component that **authoritatively** enforces authentication, authorization, and library operations.                                                                         |
| **Shell UI**        | MyLib’s own **application** user interface (not the native reader’s UI).                                                                                                       |
| **Native reader**   | An **external** application used to **display** or **print** a document file (e.g. OS-default PDF viewer).                                                                     |
| **Operator**        | A person who **deploys** and **configures** the system (may coincide with an **Administrator** user).                                                                          |
| **OCR pipeline**    | Processing that derives searchable text from **image-like** or scanned page content; output quality is **variable** by input.                                                  |
| **Tenant boundary** | The set of users and resources belonging to one **organization or household** as configured by an administrator.                                                               |

---

# 4. Functional Requirements

---

## FR-001 — Catalog records

**Description:** The system SHALL maintain a **catalog** of document records, each representing **one logical edition** (no merged edition chain required in v1).

**Acceptance criteria:** Given a successful import, a **durable** catalog record exists retrievable by identifier; given removal per FR-011, the record is **removed or archived** per documented behavior.

**Priority:** High  
**Dependencies:** —  
**Constraints:** —  
**Notes:** Edition/version lineage across files is **out of scope** for v1.

---

## FR-002 — Metadata fields

**Description:** The system SHALL support **metadata fields** including at least: **title**, **creator/author**, **language** (if known), **publisher**, **date** (publication or acquisition as applicable), **description/abstract**, and **series** (where applicable), aligned with **Dublin Core–inspired** practice.

**Acceptance criteria:** Each field can be **viewed and edited** (subject to RBAC) on a catalog record; values **persist** across sessions.

**Priority:** High  
**Dependencies:** FR-001  
**Constraints:** —  
**Notes:** Additional bibliographic fields may be added in later revisions without relaxing FR-002.

---

## FR-003 — Tags

**Description:** The system SHALL support **multiple free-form tags** per catalog record.

**Acceptance criteria:** A record can have **zero or more** tags; users can **add, remove, and filter** the catalog by tag (see FR-008).

**Priority:** High  
**Dependencies:** FR-001  
**Constraints:** —  
**Notes:** Controlled vocabularies deferred (waiting room).

---

## FR-004 — Deliberate import

**Description:** The system SHALL support **user-initiated import** of files via **explicit UI action** (e.g. menu and file selection dialog). **Silent** bulk directory ingestion **without user initiation** is **not** required in v1.

**Acceptance criteria:** User selects one or more files; system creates or updates catalog records per other FRs; user receives **clear completion or error** feedback.

**Priority:** High  
**Dependencies:** FR-001, FR-009  
**Constraints:** —  
**Notes:** Bulk import with **review queue** is **deferred** (waiting room).

---

## FR-005 — Supported document types (v1)

**Description:** The system SHALL support **import and cataloging** of at least **PDF** and **DOCX** (or equivalent Office Open XML word-processing) as **first-class** types for v1.

**Acceptance criteria:** PDF and DOCX files selected in FR-004 become catalog records with **actionable** metadata and tags per FR-002 and FR-003.

**Priority:** High  
**Dependencies:** FR-004  
**Constraints:** Lawful access to bytes required.  
**Notes:** **EPUB** and additional formats are **not** mandatory for v1 (waiting room).

---

## FR-006 — Full-text indexing (when permitted)

**Description:** Where **full textual content** is **lawfully available** to the server or client pipeline **without circumventing technical protection measures**, the system SHALL build and maintain a **full-text index** for **search** (FR-007).

**Acceptance criteria:** For an unprotected PDF/DOCX in v1, indexed text is **searchable**; index updates when catalog content or source file association changes per documented rules.

**Priority:** High  
**Dependencies:** FR-005, FR-007  
**Constraints:** No requirement to bypass DRM.  
**Notes:** **Table-heavy** and **poor-quality** PDFs may yield **imperfect** text (see §6, §14).

---

## FR-007 — Full-text search

**Description:** The system SHALL provide **search** over the **full-text index** (and **keyword lists** per FR-026 where applicable), returning **matching catalog records**.

**Acceptance criteria:** Given indexed content, a query returns **all records** matching documented query semantics; **zero results** is a valid outcome; **errors** (e.g. index unavailable) are **surfaced** to the user.

**Priority:** High  
**Dependencies:** FR-006  
**Constraints:** —  
**Notes:** “Jump to page/offset in native reader” behavior is **aspirational** and **format-dependent**; any such feature SHALL be **documented honestly** when specified in a later artifact.

---

## FR-008 — Tag filtering

**Description:** The system SHALL allow users to **filter** the catalog view by **one or more tags** (conjunctive or disjunctive semantics **SHALL be documented** and **consistent**).

**Acceptance criteria:** Applying a tag filter **narrows** the visible set; clearing filters **restores** full catalog (subject to RBAC).

**Priority:** Medium  
**Dependencies:** FR-003  
**Constraints:** —  
**Notes:** —

---

## FR-026 — Keywords when indexing blocked

**Description:** When **full-text indexing** is **not** performed because doing so would require **circumventing** technical protection measures on the file, the system SHALL allow an authorized user to associate a **keyword list** with the catalog record **separate from tags**, and SHALL include those keywords in **discovery** (e.g. search) per documented rules.

**Acceptance criteria:** For a record marked as **index-blocked** for this reason, user-added keywords **affect search results** as documented; tags and keywords **remain distinct** in the UI and data model.

**Priority:** High  
**Dependencies:** FR-001, FR-007  
**Constraints:** —  
**Notes:** Aligns with **lawful** handling of DRM-protected EPUB-class content when EPUB is added.

---

## FR-009 — Duplicate detection (digest)

**Description:** On import, the system SHALL compute a **content digest** (default: **SHA-256** of file bytes) and, when a **candidate duplicate** exists (same digest), **warn** the user and **require an explicit choice** before completing the import. **Silent** skip, merge, or replace **without user confirmation** is **prohibited** as default behavior.

**Acceptance criteria:** Duplicate-byte scenario produces **blocking confirmation** with at least **cancel** and **import as separate record** (additional options **MAY** be offered); **no silent** default resolution.

**Priority:** High  
**Dependencies:** FR-004  
**Constraints:** —  
**Notes:** Exact option set beyond minimum **TBD** in design; must satisfy **no silent** rule.

---

## FR-010 — Missing file detection and relink

**Description:** When the **underlying file** for a catalog record is **missing** (deleted, moved, or unreadable path), the system SHALL **detect** this state, **notify** the user, and offer a **controlled relink** path (e.g. file dialog) to associate a **new** path. The system SHALL **not** silently rebind to arbitrary files on disk.

**Acceptance criteria:** Simulated missing file yields **visible** notification and **successful relink** after user selects valid replacement; without relink, record shows **documented** degraded state.

**Priority:** High  
**Dependencies:** FR-001  
**Constraints:** —  
**Notes:** —

---

## FR-011 — Remove from catalog vs delete on disk

**Description:** Removing a document from the **library catalog** SHALL be **distinct** from **deleting** the underlying file bytes. When deletion on disk is offered, the system SHALL require **explicit administrator confirmation** (or equivalent **elevated** authorization).

**Acceptance criteria:** Default remove operation **does not** delete bytes without separate confirmed action; audit trail **if logging enabled** (FR-022).

**Priority:** High  
**Dependencies:** FR-001, FR-016  
**Constraints:** —  
**Notes:** —

---

## FR-012 — Server authority for security

**Description:** The system SHALL implement a **client–server** model in which **authentication** and **authorization** decisions for **remote-capable deployments** are **enforced by the library server**, not **only** by client UI concealment.

**Acceptance criteria:** In a configuration where the client connects to a **remote** server, **forbidden** operations are **rejected** by the server API even if the client is modified or bypassed (black-box test at API boundary).

**Priority:** High  
**Dependencies:** —  
**Constraints:** —  
**Notes:** Solo loopback remains subject to same **server-side** enforcement in process.

---

## FR-013 — Solo co-located deployment

**Description:** The system SHALL support **single-user** deployment where **client and server** run on the **same machine** and communicate via **loopback** (or equivalent local IPC documented in HLA).

**Acceptance criteria:** Documented **solo install** path results in working **catalog, search, and auth** without a separate physical host.

**Priority:** High  
**Dependencies:** FR-012  
**Constraints:** —  
**Notes:** —

---

## FR-014 — Multi-user server deployment

**Description:** The system SHALL support **multiple client instances** connecting to **one** library server shared by **multiple user accounts** subject to RBAC.

**Acceptance criteria:** Two distinct users with different permissions receive **different** allowed operations on the same corpus per configuration; **cross-tenant** access is **denied** when tenants are configured.

**Priority:** High  
**Dependencies:** FR-012, FR-015, FR-016  
**Constraints:** Network and TLS posture **TBD** in HLA; **operator** configures exposure.  
**Notes:** —

---

## FR-015 — Authentication (v1)

**Description:** The system SHALL authenticate users with **credentials validated by the server**. **v1** SHALL support **local user accounts** maintained by the product (username/password or documented equivalent).

**Acceptance criteria:** Invalid credentials **fail**; successful login **establishes** a server-recognized session or token per HLA; passwords **never** stored in cleartext (see FR-023).

**Priority:** High  
**Dependencies:** FR-012  
**Constraints:** Enterprise IdP / SSO **deferred** (waiting room).  
**Notes:** —

---

## FR-016 — Role-based access control

**Description:** The system SHALL enforce **RBAC** for **document access** (read, and **modify metadata/tags** where applicable) and **administrative** functions, **evaluated server-side**.

**Acceptance criteria:** Given a matrix of roles and permissions, **denied** actions **cannot** be completed via API; **UI** reflects denials **consistently** (but UI is not sole enforcement).

**Priority:** High  
**Dependencies:** FR-015  
**Constraints:** **Granularity** (per-collection vs per-document) **TBD** in design—must support **at least** **administrator** vs **non-administrator** **distinction**.  
**Notes:** **Tenant** membership **FR-017**.

---

## FR-017 — Tenant boundary

**Description:** The system SHALL allow an **administrator** to define **tenant boundaries** (which users belong to which tenant / organization context), and SHALL **enforce** that users **do not** access **other tenants’** resources.

**Acceptance criteria:** With two tenants configured, user A **cannot** retrieve or list documents belonging **only** to tenant B.

**Priority:** High  
**Dependencies:** FR-016  
**Constraints:** —  
**Notes:** For **single-tenant** installs, **one** default tenant **SHALL** suffice.

---

## FR-018 — Open in native reader

**Description:** The system SHALL provide a **documented** means to **open** the **underlying file** (or a **server-mediated** equivalent that preserves access policy) in the **OS-appropriate native reader** for the file type, for **supported** formats. When the user has set a **preferred reader** per FR-028, **open** SHALL honor that preference **where** the platform and security policy **allow** launching the designated application; otherwise **open** SHALL **fall back** to **documented** default behavior (e.g. **OS-registered default handler**).

**Acceptance criteria:** On each supported desktop OS, user can open from MyLib and **observe** the file in an external reader; if policy **denies** access, open **fails** with **clear** reason. With a **valid** preferred reader configured for that type, **open** uses that reader **unless** fallback is **documented** and **explained** (e.g. missing executable).

**Priority:** High  
**Dependencies:** FR-016, FR-028  
**Constraints:** **Hand-off of search term** to reader **deferred** / optional (waiting room).  
**Notes:** **Bytes may reach client** as part of open—**policy honesty** in operator docs (NFR). Reader choice is **client-side** preference (FR-027); **authorization** remains **server-side** (FR-012).

---

## FR-027 — Settings (client preferences)

**Description:** The **shell UI** SHALL provide a **Settings** (or equivalently named) area where an authenticated user can **view and change client-side preferences** that **do not** substitute for or **weaken** **server-enforced** access control (FR-012, FR-016). The Settings area SHALL include at minimum the capabilities in **FR-028** and **FR-029** and SHALL be **extensible** so that **additional** **client-side** or **documented system-level** options may be added in later releases **without** a new top-level navigation paradigm.

**Acceptance criteria:** User can open Settings from the shell, change a preference, **restart** the application (if required by HLA), and **observe** the change **persisted** on the **same client installation**; **forbidden** operations remain **blocked** by the server regardless of client UI state.

**Priority:** High  
**Dependencies:** FR-015  
**Constraints:** **Server-side** administrative options (e.g. log retention FR-024) **MAY** appear in Settings **only** for users with **appropriate** roles **and** **SHALL** remain **enforced** on the server.  
**Notes:** Exact layout (tabs vs sidebar) **TBD** DD. **Further** system-level knobs **TBD**; this FR establishes the **facility**.

---

## FR-028 — Preferred reader per document type

**Description:** For each **document type** the product **supports for open-in-reader** in v1 (at minimum those in FR-005: **PDF** and **DOCX**), Settings (FR-027) SHALL allow the user to specify a **preferred external application** used when invoking **FR-018**, **or** to select **use platform default** / **automatic** (exact labels **TBD** UX). The mechanism **SHALL** be **documented** (e.g. **path to executable**, **OS app picker**, or **registered handler id**) **per platform** in DD **without** mandating a specific OS API herein.

**Acceptance criteria:** For each v1 type, user can set **preferred**, **clear** the choice to **default**, and **open** (FR-018) reflects the choice **on a supported configuration**; invalid or missing targets produce **actionable** error **without** crashing the client.

**Priority:** High  
**Dependencies:** FR-005, FR-018, FR-027  
**Constraints:** Some environments **MAY** only support **default handler**; product **SHALL** document **limitations**.  
**Notes:** **EPUB** and future types **SHALL** gain the same **preference** row when those types become **supported**.

---

## FR-029 — Application theme

**Description:** Settings (FR-027) SHALL allow the user to select a **visual theme** for the **shell UI**, including at minimum these **shipped** defaults: **(a)** **light**, **(b)** **dark**, and **(c)** a **warm sepia** theme (e.g. **sepia-tinted** chrome and **parchment-like** **background** tones). Where the **desktop platform** exposes a **system** light/dark mode, the product **SHOULD** offer a **match system** option (or equivalent) **that maps** to **light** or **dark** **only** (sepia remains an **explicit** user choice unless **documented** otherwise in DD).

**Acceptance criteria:** User can switch among **light**, **dark**, and **warm sepia** and **observe** **shell** chrome and **documented** controls **update** accordingly; choice **persists** across restarts on the **same client** (FR-027). **All** **shipped** themes in **(a)–(c)** **SHALL** satisfy **contrast** for **shell** text and **essential** controls **per** NFR-006—**including** when **warm sepia** uses a **parchment-style** **background**, **foreground** (text, icons, borders) **SHALL** be **chosen** so **WCAG 2.1 Level AA** **contrast** **obligations** are **met** on **representative** surfaces.

**Priority:** Medium  
**Dependencies:** FR-027  
**Constraints:** **Native reader** appearance **out of scope**. **Decorative** parchment **texture** **MAY** be **subtle** **provided** **legibility** and **NFR-006** **still** **pass**.  
**Notes:** Custom **user-authored** themes or **third-party** theme packs **deferred** (waiting room).

---

## FR-019 — OCR for searchability

**Description:** For **image-only** or **scanned** PDFs (and similar) where **no** extractable text layer exists, the system SHALL support an **OCR** path to produce **indexable text**, subject to **user-visible** indication that text is **OCR-derived** and subject to **correction** workflow **as specified in Detailed Design**.

**Acceptance criteria:** Given a fixture image-only PDF, system **either** indexes after OCR **or** presents **explicit** user prompt/workflow; **silent** pretend-accuracy **prohibited**.

**Priority:** High  
**Dependencies:** FR-006  
**Constraints:** OCR engine **not** specified herein.  
**Notes:** Correction UX **TBD** in DD; ties to §6.

---

## FR-020 — Shell accessibility

**Description:** The **shell UI** SHALL meet **WCAG 2.1 Level AA** success criteria **where applicable** to the technology stack chosen in HLA (non-web shells map to **equivalent** documented checkpoints).

**Acceptance criteria:** Documented **accessibility test plan** executed; **critical** flows (login, search, open document, **Settings** per FR-027, **access Help / user documentation** per NFR-007) **pass** agreed checkpoints.

**Priority:** High  
**Dependencies:** —  
**Constraints:** **Native reader** accessibility **out of scope** (third-party).  
**Notes:** Exact audit method **in Test Plan**.

---

## FR-021 — English UI (v1)

**Description:** The **v1** product UI and **operator-facing** embedded help **SHALL** be available in **English**.

**Acceptance criteria:** No **mandatory** UI string is presented **only** in a non-English language for default install.

**Priority:** Medium  
**Dependencies:** —  
**Constraints:** —  
**Notes:** **i18n** deferred (waiting room).

---

## FR-022 — Audit logging

**Description:** The system SHALL emit **audit log events** for **security-relevant** actions including at minimum: **successful and failed authentication attempts**, **document access** (open/view) **as configured**, and **administrative configuration changes** **as enumerated in DD**.

**Acceptance criteria:** With logging enabled, configured actions produce **timestamped** records with **actor** and **resource identifier**; logs **respect** retention configuration (FR-024).

**Priority:** Medium  
**Dependencies:** FR-015, FR-016  
**Constraints:** **Privacy** and **retention** are **operator** policy (see §10, §12).  
**Notes:** Exact event catalog **TBD** in DD.

---

## FR-023 — Password storage

**Description:** The system SHALL store **password secrets** only using **strong one-way hashing** and **never** store **cleartext** passwords.

**Acceptance criteria:** Stored credential representation **matches** documented algorithm parameters; penetration of DB **does not** reveal cleartext passwords.

**Priority:** High  
**Dependencies:** FR-015  
**Constraints:** Algorithm choice **TBD** in DD (must be **industry-accepted**).  
**Notes:** —

---

## FR-024 — Configurable log retention

**Description:** The system SHALL provide **administrator-configurable** **log rotation and retention** parameters for **application/audit logs** it controls.

**Acceptance criteria:** Administrator can set **retention** and **rotation** per documented limits; behavior **documented** in admin guide.

**Priority:** Medium  
**Dependencies:** FR-022  
**Constraints:** —  
**Notes:** **Centralized log shipping** deferred unless required by HLA.

---

## FR-025 — Release information

**Description:** The system SHALL provide a **documented, user-visible** means to determine the **running software version** (e.g. About box).

**Acceptance criteria:** Version string **visible** without network access; **matches** packaged release identifier.

**Priority:** Medium  
**Dependencies:** —  
**Constraints:** —  
**Notes:** **Automatic update checks** and **outbound telemetry** **deferred** to HLA with **privacy-preserving** defaults (waiting room / NFR).

---

# 5. Non-Functional Requirements (NFRs)

---

## NFR-001 — Corpus scale (qualitative)

**Category:** Scalability  

**Description:** The system SHALL support **routine** catalog, browse, and search operations for libraries of **at least 10,000** catalog records **without** requiring **manual database surgery** for normal operation.

**Measurement criteria:** **Load test** with **10,000** representative records on a **reference environment** defined in the **Test Plan**; **no** unbounded memory growth on **steady-state** browse/search **as defined in Test Plan**.

**Constraints:** Does **not** fix **latency** milliseconds on all hardware.  
**Dependencies:** Test Plan, HLA.

---

## NFR-002 — Server-side enforcement

**Category:** Security  

**Description:** **All** authorization outcomes for **controlled operations** SHALL be **decided** and **enforceable** at the **server** boundary.

**Measurement criteria:** **Negative tests** at API level **per role matrix**; **no** single-client bypass for **remote** deployment.

**Constraints:** —  
**Dependencies:** FR-012, FR-016.

---

## NFR-003 — Licensing and notices

**Category:** Compliance / Maintainability  

**Description:** The distributed **source and binary** artifacts SHALL **include** **Apache-2.0** license text and **NOTICE** practice **consistent** with the repository root **as of release**, and SHALL **attribute** third-party components **as required** by their licenses.

**Measurement criteria:** **Release checklist** verifies **LICENSE** and **NOTICE** presence and **dependency** attribution completeness.

**Constraints:** **Legal review** recommended before broad distribution (assumption §8).  
**Dependencies:** —

---

## NFR-004 — Operator documentation

**Category:** Usability / Compliance  

**Description:** The project SHALL publish **operator documentation** describing **backup scope** (corpus, database, index, configuration, logs), **security boundaries**, and **privacy-relevant** data flows **at a conceptual level** sufficient for **informed deployment**.

**Measurement criteria:** **Reviewer** can answer: what to back up, what is logged, and where **secrets** live—using **only** shipped docs.

**Constraints:** Complements **NFR-007** (end-user / day-to-day documentation); **admin** vs **end-user** material **MAY** share a **Help** shell but **SHALL** remain **discernible** (e.g. separate sections or guides).  
**Dependencies:** `system-documentation/user-documentation/` (e.g. admin guide); stubs **to be** expanded for release.

---

## NFR-005 — Honest policy communication

**Category:** Compliance  

**Description:** Documentation SHALL **not claim** impossible security properties (e.g. **prevent all** exfiltration) and SHALL **state** that **opening** a document in a **native reader** may involve **local** handling of **bytes** subject to **OS** and **reader** behavior.

**Measurement criteria:** **Legal/technical review** checklist item **passes** for **deployment** guide sections on **access** and **readers**.

**Constraints:** —  
**Dependencies:** NFR-004.

---

## NFR-006 — Themed shell contrast

**Category:** Usability / Compliance  

**Description:** For **each** **shipped** **shell** theme in **FR-029**—**light**, **dark**, and **warm sepia** (including **parchment-style** **backgrounds** where used)—**shell UI** text and **essential** interactive controls **SHALL** meet **contrast** requirements **aligned** with **WCAG 2.1 Level AA** for **normal** and **large** text **as applicable** to the toolkit (verification method **in Test Plan**). **Non-text** contrast for **UI** components **SHALL** follow **the same conformance target** **where** **WCAG 2.1** **applies** to **non-text** content **per** agreed **test** mapping.

**Measurement criteria:** **Automated** and/or **manual** contrast checks on **agreed** **representative** screens (including **Settings** and **theme** **switching**) **pass** for **all** **shipped** themes **or** **defects** are **tracked** as **release blockers**.

**Constraints:** Does **not** guarantee **custom** OS **high-contrast** modes beyond **documented** behavior. **Parchment** or **textured** **backgrounds** **MUST NOT** **excuse** **sub-AA** **contrast** for **primary** reading and **control** **labels**.  
**Dependencies:** FR-020, FR-029.

---

## NFR-007 — End-user documentation and Help

**Category:** Usability / Maintainability  

**Description:** The product SHALL ship **end-user documentation** in **English** (FR-021), comprising at minimum: **(a)** a **User manual** describing **primary** **shell** workflows—including **catalog**, **search**, **metadata/tags**, **open in native reader** (and **reader** preferences per FR-028), **Settings** (FR-027), and **RBAC-visible** behavior (e.g. what **denied access** looks like)—and **(b)** a **Quick-start guide** sufficient for a **new** user to **install or connect** the client, **authenticate** if required, and **import** at least **one** document **successfully**. Source **MAY** be maintained under **`system-documentation/user-documentation/`** (or successor path) and **SHALL** be **packaged** or **published** with **releases** **per** HLA (e.g. **HTML**, **PDF**, **Markdown** bundle—**exact** formats **TBD**).

The **shell UI** SHALL provide a **user-discoverable** **Help** affordance (e.g. **Help** menu, **toolbar**, or **Settings** link—**TBD** DD) that **reaches** the **Quick-start** and **User manual** for the **running** **product version** (e.g. **opens** bundled content in an **embedded** viewer, **local** help window, or **system** browser—**not** mandated herein).

**Measurement criteria:** **Release checklist:** manual + quick-start **present**, **version** **aligned** with the **release**; **smoke test:** **novice** or **proxy** user completes **Quick-start** **without** **engineering** support **or** **gaps** are **recorded** and **tracked**; **Help** entry **reachable** from **default** logged-in shell within **documented** **click**/**key** budget.

**Constraints:** **Searchable** **full** in-app help **index**, **context-sensitive** (F1) help, and **very large** manual **browse/search** **UX** are **deferred** to **§13** unless **implemented** **early** via a **chosen** component. A **pre-built** help **component** or **viewer** **MAY** be used **provided** **licenses** are **compatible** with **Apache-2.0** distribution (or **clearly** **optional**), **security** posture is **acceptable**, and **accessibility** (FR-020) **obligations** are **met** for the **help** surface.

**Dependencies:** FR-021; FR-020; NFR-004 (operator docs **distinct** but **may** **cross-link**).

---

# 6. Deterministic–Probabilistic Requirements

**Applicability:** **OCR** and **layout extraction** behave **probabilistically** with respect to input quality. **No generative-AI** product features in v1.

**Expectations**

- **OCR and extraction outputs** MAY **differ** from **visually apparent** text; **error rate** is **input-dependent**.  
- The system SHALL **surface** when text used for search is **OCR-derived** or **otherwise unreliable** per FR-019 and DD.  
- Users SHALL have a **documented correction or override** path for **materially wrong** index text **before** relying on it for **compliance-critical** workflows (exact UX in DD).  
- **Search hit alignment** with **reader display** is **best-effort** and **SHALL NOT** be overstated in UI copy.  
- **Fallback:** If OCR **cannot** produce usable text, the record **SHALL** enter a **documented** state (e.g. **index failed**) **without** silent success.  
- **Observability:** OCR/index **failures** **SHALL** be **diagnosable** by **operators** per DD (log fields, error codes).  
- **Reproducibility:** **Same input file** through **same pipeline version** **SHOULD** yield **consistent** index text **within** documented **tolerance** (exact matching **not** guaranteed across OCR engine micro-versions—**document** behavior).

---

# 7. Constraints

- **Desktop OS:** Windows, macOS, Linux **only** for v1 **client**.  
- **License:** **Apache-2.0** for project code **as stated** in repository.  
- **No DRM circumvention** as a **product goal**.  
- **English-first** UI.  
- **Symbolic links:** **unsupported** in v1 for library paths.  
- **Network:** **Remote** access **requires** **operator** to supply **appropriate** transport security **per HLA** (requirement **to support** secure deployment, **not** specific cipher suites herein).  
- **Maintainer distribution:** **No** maintainer-operated **mandatory** SaaS; **self-host** or **solo** use.

---

# 8. Assumptions

- **Operators** have **lawful rights** to index and store documents they import.  
- **Users** accept **native readers** for **display** fidelity.  
- **Counsel review** will complete **before** **marketing** or **enterprise** claims.  
- **Reference hardware** for **Meaningful** performance characterization **will be** defined in **Test Plan**.  
- **Third-party** OCR/parser **licenses** remain **compatible** with **Apache-2.0** distribution **or** are **optional** plug-ins **clearly** separated ( **TBD** HLA).

---

# 9. Interfaces and External Dependencies

- **File system** paths or **administrator-configured** storage locations for **document bytes**.  
- **Operating system** services to **launch native readers** with **file** or **URI** targets.  
- **Human users** via **shell UI** and **native readers** (external).  
- **Client preference data** (reader choices, theme, and future Settings values) **SHALL** **persist** on the **client** **per** DD (local store, profile path, or equivalent); **synchronization** of preferences across machines **deferred** unless **specified** in HLA.  
- **Future:** optional **update metadata** endpoint **deferred**; **no** **public application API** in v1.  
- **No** specific **vendor** OCR, PDF, or UI framework **required** in this SRS.

---

# 10. Data Requirements

- **Catalog data** (metadata, tags, keywords, paths, tenant, permissions) **SHALL** be **durable** (survive restart).  
- **Full-text index** **SHALL** be **rebuildable** from **source documents** and **catalog** state **per documented** procedure (acceptable **downtime** **TBD** HLA).  
- **Passwords:** **hashed** only (FR-023).  
- **Audit logs:** **personal data** in some jurisdictions; **purpose limitation** and **retention** **operator-configured** (FR-024).  
- **Client preferences** (FR-027–FR-029): **SHALL NOT** be used to store **server secrets** or to **bypass** authorization; **backup** scope **MAY** include **client** preference stores **where** operators **document** **enterprise** restore practices (solo: typically **user-local**).  
- **Backups:** **ideal** includes **corpus + DB + index + config + logs**; **minimal** subset **documented** for operators (NFR-004).

---

# 11. Error Handling and Edge Conditions

- **Import** of **unreadable** or **unsupported** files **SHALL** **fail** with **actionable** messages.  
- **Partial index** failures **SHALL** **not** present **silent** success.  
- **Concurrent edits** to metadata **SHALL** follow **documented** conflict rules (**last-write-wins** or **merge**—**TBD** DD, **must be** **explicit**).  
- **Server unavailable:** client **SHALL** **degrade** **per documented** behavior (offline **editing** **not** required in v1).

---

# 12. Security and Compliance Requirements

- **Authentication** and **RBAC** per FR-015–FR-017.  
- **Client Settings** (FR-027) **SHALL NOT** allow **elevation** of privilege or **access** to **documents** **contrary** to **server** decisions; **UI** hiding alone **is** **insufficient** for **security** on **remote** deployments (FR-012).  
- **Transport security** for **remote** access **SHALL** be **supported** (details HLA).  
- **Audit** optional events per FR-022 with **privacy** awareness.  
- **Regulatory:** **Operators** responsible for **lawful processing**; product provides **controls** and **documentation**, **not legal advice**.  
- **Accessibility law** alignment **targeted** via FR-020; **jurisdiction-specific** claims **deferred** to **counsel**.

---

# 13. Waiting Room (Deferred Scope)

- **Standalone web SPA client**  
- **Offline sync / multi-site replication**  
- **Public HTTP API** and **scripting**  
- **Symbolic link** support  
- **Bulk import** with **automated review queue**  
- **EPUB** (and other formats beyond PDF/DOCX) as **mandatory** in v1  
- **Controlled vocabulary** tags  
- **“Game system”** and similar **domain fields** (structured vs tag)  
- **Hand-off of search string** to **native reader** (where technically feasible)  
- **Numeric latency SLAs** on **named** hardware SKUs  
- **Enterprise SSO / directory** integration  
- **i18n** beyond English  
- **Automatic update** / **phone-home** behavior (until **specified** with **opt-in** defaults in HLA)  
- **Server autostart** at login vs **system** boot—**configurable behavior** **required** by product goals but **exact** mechanism **deferred** to **HLA** (capture there as **non-SRS** detail)  
- **User-installable / third-party visual themes** and **theme marketplace**  
- **Sync of client preferences** across **multiple** installations or devices  
- **Searchable** in-app **help** (full-text **index** over the **manual**) when **document** size or **navigation** **pain** **warrants** it—**or** **adopt** a **component** that **provides** search **out of the box**  
- **Context-sensitive** help (**F1**, **“?”**, or **screen-linked** topics) **tied** to the **active** **shell** view

---

# 14. Risk Assessment

| Risk                                | Level        | Mitigation (requirements-level)     |
| ----------------------------------- | ------------ | ----------------------------------- |
| **Extraction/OCR inaccuracy**       | **High**     | §6, FR-019, FR-007 honest semantics |
| **User expects SharePoint parity**  | **Moderate** | §2.2 non-goals, operator docs       |
| **Remote access misconfiguration**  | **High**     | NFR-002, NFR-004, HLA hardening     |
| **Legal/DRM boundary**              | **Moderate** | FR-006, FR-026, §7                  |
| **Accessibility verification gaps** | **Moderate** | FR-020 + Test Plan                  |
| **Documentation / Help gaps**       | **Moderate** | NFR-007 checklist, Quick-start test |
| **Scope creep (web/API)**           | **Moderate** | §13 waiting room                    |
| **Reader preference misconfiguration** | **Low–Moderate** | FR-028 acceptance, clear fallback |

---

# 15. Traceability Readiness Declaration

- **FR** and **NFR** IDs **assigned** in this draft: **Yes**  
- **Acceptance criteria** present per item: **Yes** (subject to refinement)  
- **Architecture** embedded: **Avoided** (no stack mandates)  
- **RTM:** **Not yet** populated — **SHALL** be created **before** implementation phase per **LIFECYCLE.md**  
- **Waiting room** separated: **Yes**  
- **Probabilistic** bounds for OCR: **Yes** (§6)

---

# 16. Phase Gate Declaration

Confirm readiness to proceed to **High-Level Architecture**:

- Requirements stable? **No** — **initial draft**; **stakeholder review** pending  
- NFRs measurable? **Partial** — qualitative **NFR-001** pending **Test Plan** binding  
- Scope boundaries explicit? **Yes**  
- Traceability scaffold prepared? **No** — **RTM** next  
- Human approval granted? **No** — **required** after review of this draft  

**Action:** Remain in **Requirements** until **review**, **revision**, **RTM draft**, and **explicit approval** to **Architecture**.

---

# Approval

Approved By: *— pending —*  
Role:  
Date:  
Version Incremented:  

Advancement to High-Level Architecture requires explicit authorization per **LIFECYCLE.md**.

---

End of SRS (draft)

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
Version: 0.9  
Date (YYYY-MM-DD): 2026-04-11  
**Last revised (UTC):** 2026-04-11  
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
- **Operational** and **diagnostic** logging for **client** and **server**, **configurable** via **Settings** / **administration** surfaces, per **FR-029** and **NFR-008**.  
- **User and session administration** (account lifecycle, sessions, throttling), **corpus storage** model, **catalog browse**, **search semantics**, **index rebuild**, **metadata validation** and **concurrency**—**FR-031**–**FR-041**.

**Explicitly out of scope (initial release)**

- **Standalone web client** (browser SPA) as a product surface.  
- **Offline replication / sync** between installations.  
- **Public HTTP API** and **end-user scripting** interfaces.  
- **Symbolic links** as first-class library paths (v1).  
- **Numeric performance SLAs** tied to specific hardware (deferred; see NFRs for qualitative scale).  
- **Features whose primary purpose is circumventing DRM** on copyrighted works.  
- **MyLib-provided** document **export**, **download**, or **print** flows (users may use capabilities of native readers where applicable).  
- **Multi-factor authentication (MFA)**—e.g. **TOTP, SMS or app push OTP, hardware tokens** as a **second** **factor** **bound** **to** **login**—**is** **not** **in** **v1** **and** **is** **intentionally** **de-prioritized** **until** **a** **clear,** **stakeholder-driven** **need** **arises**; **if** **MFA** **is** **ever** **introduced,** **it** **SHALL** **remain** **optional** **per** **deployment** **(operators** **or** **users** **enable** **it** **where** **supported)** **and** **SHALL** **not** **be** **mandated** **for** **all** **installations** **without** **an** **explicit** **future** **scope** **revision.**

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
| **Audit log** | **Security- and compliance-oriented** records (who did what, when, on which resource) per **FR-026**—**distinct** from **operational**/**diagnostic** streams unless **implementation** **maps** **categories** **without** **blurring** **toggle** **semantics** **(DD)**. |
| **Operational log** | **Routine** **application** **and** **lifecycle** **events** **suitable** **for** **monitoring** **healthy** **operation** **(FR-029)**—**not** a **substitute** **for** **audit** **where** **audit** **is** **required**. |
| **Diagnostic log** | **Warnings**, **errors**, **and** **troubleshooting** **detail** **for** **support** **and** **fault** **analysis** **(FR-029)**. |

---

# 4. Functional Requirements

**Index (numerical):** FR-001–008 (catalog, metadata, import, types, index, search, tags, keywords) · FR-009–012 (duplicates, missing file, remove) · FR-013–019 (security, deployment, auth, RBAC, tenant, open reader) · FR-020–022 (Settings, reader prefs, theme) · FR-023–030 (OCR, a11y, English, audit, passwords, log retention, ops/diagnostic logs, release) · FR-031–041 (administration, sessions, storage, browse, search detail, index admin, metadata).

---

## FR-001 — Catalog records

**Description:** The system SHALL maintain a **catalog** of document records, each representing **one logical edition** (no merged edition chain required in v1).

**Acceptance criteria:** Given a successful import, a **durable** catalog record exists retrievable by identifier; given removal per FR-012, the record is **removed or archived** per documented behavior.

**Priority:** High  
**Dependencies:** —  
**Constraints:** —  
**Notes:** Edition/version lineage across files is **out of scope** for v1.

---

## FR-002 — Metadata fields

**Description:** The system SHALL support metadata fields including at least: **title**; **creator/author**; **language** (if known); **publisher**; **publication date** (when known—SHALL remain **optional** or **empty** when the source or operator does not supply it); **acquisition date** (when the record entered the library—SHALL be **tracked** with documented semantics, e.g. **system-set on first successful import** with optional **administrator correction** per DD); **description/abstract**; and **series** (where applicable), aligned with Dublin Core–inspired practice.

**Acceptance criteria:** Each field can be viewed and edited (subject to RBAC) on a catalog record; values persist across sessions. Publication date can be absent without blocking catalog completeness rules in FR-040 except where DD states otherwise; acquisition date behavior (auto vs editable) is verified per DD.

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

**Description:** The system SHALL support **administrator-initiated import** of files via explicit UI action (e.g. menu and file selection dialog). Only users holding an **administrator** role (or a documented **import-equivalent** permission evaluated server-side per FR-017) SHALL be allowed to perform import. **Solo deployment (FR-014):** the interactive user SHALL be the administrator established at bootstrap (FR-032) or otherwise hold that role so import remains available without a separate account. Silent bulk directory ingestion without explicit user initiation is not required in v1.

**Acceptance criteria:** An administrator completes import and receives clear completion or error feedback; a non-administrator receives denial at the server boundary (and consistent UI) when attempting import. Solo install path still satisfies import per FR-014 acceptance.

**Priority:** High  
**Dependencies:** FR-001, FR-010, FR-017, FR-032  
**Constraints:** —  
**Notes:** Bulk import with review queue is deferred (waiting room).

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
**Dependencies:** FR-005  
**Constraints:** No requirement to bypass DRM.  
**Notes:** **Table-heavy** and **poor-quality** PDFs may yield **imperfect** text (see §6, §14). **Search** consumption of the index is specified in **FR-007** (depends on this requirement).

---

## FR-007 — Full-text search

**Description:** The system SHALL provide **search** over the **full-text index** (and **keyword lists** per FR-009 where applicable), returning **matching catalog records**.

**Acceptance criteria:** Given indexed content, a query returns **all records** matching documented query semantics; **zero results** is a valid outcome; **errors** (e.g. index unavailable) are **surfaced** to the user.

**Priority:** High  
**Dependencies:** FR-006  
**Constraints:** —  
**Notes:** “Jump to page/offset in native reader” behavior is **aspirational** and **format-dependent**; any such feature SHALL be **documented honestly** when specified in a later artifact. **Query** **syntax** **and** **semantics** **(boolean,** **phrase,** **grouping)** **are** **specified** **in** **FR-038**.

---

## FR-008 — Tag filtering

**Description:** The system SHALL allow users to **filter** the catalog view by **one or more tags** (conjunctive or disjunctive semantics **SHALL be documented** and **consistent**).

**Acceptance criteria:** Applying a tag filter **narrows** the visible set; clearing filters **restores** full catalog (subject to RBAC).

**Priority:** Medium  
**Dependencies:** FR-003  
**Constraints:** —  
**Notes:** —

---

## FR-009 — Keywords when indexing blocked

**Description:** When **full-text indexing** is **not** performed because doing so would require **circumventing** technical protection measures on the file, the system SHALL allow an authorized user to associate a **keyword list** with the catalog record **separate from tags**, and SHALL include those keywords in **discovery** (e.g. search) per documented rules.

**Acceptance criteria:** For a record marked as **index-blocked** for this reason, user-added keywords **affect search results** as documented; tags and keywords **remain distinct** in the UI and data model.

**Priority:** High  
**Dependencies:** FR-001, FR-007  
**Constraints:** —  
**Notes:** Aligns with **lawful** handling of DRM-protected EPUB-class content when EPUB is added.

---

## FR-010 — Duplicate detection (digest)

**Description:** On import, the system SHALL compute a **content digest** (default: SHA-256 of file bytes) and, when a candidate duplicate exists (same digest value under the same algorithm), warn the actor and require an explicit choice before completing the import. Silent skip, merge, or replace without user confirmation is prohibited as default behavior. The system SHALL maintain a **durable store** of digest values **and** the **algorithm identifier** used for each stored digest (per catalog association documented in DD) so duplicate detection and integrity checks remain consistent across restarts; DD SHALL define retention, migration when the default algorithm changes, and whether multiple algorithms may coexist temporarily.

**Acceptance criteria:** Duplicate-byte scenario produces blocking confirmation with at least cancel and import as separate record (additional options MAY be offered); no silent default resolution. After restart, digest records persist and duplicate detection still recognizes prior imports per DD.

**Priority:** High  
**Dependencies:** FR-004  
**Constraints:** —  
**Notes:** Exact option set beyond minimum TBD in design; must satisfy no silent rule.

---

## FR-011 — Missing file detection and relink

**Description:** When the underlying file for a catalog record is missing (deleted, moved, or unreadable path), the system SHALL detect this state and SHALL NOT silently rebind to arbitrary files on disk.

**Solo deployment (FR-014):** The system SHALL notify the interactive user and SHALL offer a controlled relink path (e.g. file dialog) to associate a new path, subject to server enforcement (FR-013).

**Multi-user deployment (FR-015):** Default behavior SHALL notify users with **administrator** role (or a documented **corpus-maintenance** / equivalent role per FR-017) of the affected record(s) so they may remediate (relink, restore from backup, or remove per policy). Non-administrator users SHALL receive a documented degraded-access indication for affected records where applicable; whether they are offered relink is **policy in DD** (default: administrators drive remediation).

**Acceptance criteria:** **Solo:** Simulated missing file yields visible notification to the user and successful relink after valid replacement; without relink, documented degraded state. **Multi-user:** Simulated missing file yields administrator-visible notification (and audit per FR-026 where enabled); non-admin behavior matches DD; server API denies inconsistent relink or access per FR-013 and FR-017.

**Priority:** High  
**Dependencies:** FR-001, FR-017  
**Constraints:** —  
**Notes:** Notification channels (in-app only vs optional email—TBD DD/HLA) SHALL be documented for multi-user defaults.

---

## FR-012 — Remove from catalog vs delete on disk

**Description:** Removing a document from the **library catalog** SHALL be **distinct** from **deleting** the underlying file bytes. When deletion on disk is offered, the system SHALL require **explicit administrator confirmation** (or equivalent **elevated** authorization).

**Acceptance criteria:** Default remove operation **does not** delete bytes without separate confirmed action; audit trail **if logging enabled** (FR-026).

**Priority:** High  
**Dependencies:** FR-001, FR-017  
**Constraints:** —  
**Notes:** —

---

## FR-013 — Server authority for security

**Description:** The system SHALL implement a **client–server** model in which **authentication** and **authorization** decisions for **remote-capable deployments** are **enforced by the library server**, not **only** by client UI concealment.

**Acceptance criteria:** In a configuration where the client connects to a **remote** server, **forbidden** operations are **rejected** by the server API even if the client is modified or bypassed (black-box test at API boundary).

**Priority:** High  
**Dependencies:** —  
**Constraints:** —  
**Notes:** Solo loopback remains subject to same server-side enforcement in process. **Authorization** for import (FR-004) and for missing-file remediation UI (FR-011) SHALL be decided server-side per FR-017 so client modification cannot bypass policy.

---

## FR-014 — Solo co-located deployment

**Description:** The system SHALL support **single-user** deployment where **client and server** run on the **same machine** and communicate via **loopback** (or equivalent local IPC documented in HLA).

**Acceptance criteria:** Documented **solo install** path results in working **catalog, search, and auth** without a separate physical host.

**Priority:** High  
**Dependencies:** FR-013  
**Constraints:** —  
**Notes:** —

---

## FR-015 — Multi-user server deployment

**Description:** The system SHALL support **multiple client instances** connecting to **one** library server shared by **multiple user accounts** subject to RBAC.

**Acceptance criteria:** Two distinct users with different permissions receive **different** allowed operations on the same corpus per configuration; **cross-tenant** access is **denied** when tenants are configured.

**Priority:** High  
**Dependencies:** FR-013, FR-016, FR-017  
**Constraints:** Network and TLS posture **TBD** in HLA; **operator** configures exposure.  
**Notes:** —

---

## FR-016 — Authentication (v1)

**Description:** The system SHALL authenticate users with **credentials validated by the server**. **v1** SHALL support **local user accounts** maintained by the product (username/password or documented equivalent).

**Acceptance criteria:** Invalid credentials **fail**; successful login **establishes** a server-recognized session or token per HLA; passwords **never** stored in cleartext (see FR-027).

**Priority:** High  
**Dependencies:** FR-013  
**Constraints:** Enterprise IdP / SSO **deferred** (waiting room).  
**Notes:** **v1** **relies** **on** **server-validated** **username/password** **(or** **documented** **equivalent)** **per** **Description.** **MFA** **is** **out** **of** **scope** **(§2.2)** **unless** **explicitly** **reopened.** **Passkeys** **(FIDO2** **/** **WebAuthn-class** **credentials** **as** **an** **optional** **sign-in** **path)** **are** **a** **candidate** **post-v1** **enhancement** **(§13)** **when** **platform** **and** **privacy** **constraints** **are** **addressed** **in** **HLA** **/** **DD.**

---

## FR-017 — Role-based access control

**Description:** The system SHALL enforce **RBAC** for **document access** (read, and **modify metadata/tags** where applicable) and **administrative** functions, **evaluated server-side**.

**Acceptance criteria:** Given a matrix of roles and permissions, **denied** actions **cannot** be completed via API; **UI** reflects denials **consistently** (but UI is not sole enforcement).

**Priority:** High  
**Dependencies:** FR-016  
**Constraints:** **Granularity** (per-collection vs per-document) **TBD** in design—must support **at least** **administrator** vs **non-administrator** **distinction**.  
**Notes:** **Tenant** membership **FR-018**.

---

## FR-018 — Tenant boundary

**Description:** The system SHALL allow an **administrator** to define **tenant boundaries** (which users belong to which tenant / organization context), and SHALL **enforce** that users **do not** access **other tenants’** resources.

**Acceptance criteria:** With two tenants configured, user A **cannot** retrieve or list documents belonging **only** to tenant B.

**Priority:** High  
**Dependencies:** FR-017  
**Constraints:** —  
**Notes:** For **single-tenant** installs, **one** default tenant **SHALL** suffice.

---

## FR-019 — Open in native reader

**Description:** The system SHALL provide a **documented** means to **open** the **underlying file** (or a **server-mediated** equivalent that preserves access policy) in the **OS-appropriate native reader** for the file type, for **supported** formats. When the user has set a **preferred reader** per FR-021, **open** SHALL honor that preference **where** the platform and security policy **allow** launching the designated application; otherwise **open** SHALL **fall back** to **documented** default behavior (e.g. **OS-registered default handler**).

**Acceptance criteria:** On each supported desktop OS, user can open from MyLib and **observe** the file in an external reader; if policy **denies** access, open **fails** with **clear** reason. With a **valid** preferred reader configured for that type, **open** uses that reader **unless** fallback is **documented** and **explained** (e.g. missing executable).

**Priority:** High  
**Dependencies:** FR-017, FR-021  
**Constraints:** **Hand-off of search term** to reader **deferred** / optional (waiting room).  
**Notes:** **Bytes may reach client** as part of open—**policy honesty** in operator docs (NFR). Reader choice is **client-side** preference (FR-020); **authorization** remains **server-side** (FR-013).

---

## FR-020 — Settings (client preferences)

**Description:** The **shell UI** SHALL provide a **Settings** (or equivalently named) area where an authenticated user can **view and change client-side preferences** that **do not** substitute for or **weaken** **server-enforced** access control (FR-013, FR-017). The Settings area SHALL include at minimum the capabilities in **FR-021**, **FR-022**, and **client-side** **controls** **for** **operational** **and** **diagnostic** **logging** **(FR-029)** and SHALL be **extensible** so that **additional** **client-side** or **documented system-level** options may be added in later releases **without** a new top-level navigation paradigm.

**Acceptance criteria:** User can open Settings from the shell, change a preference, **restart** the application (if required by HLA), and **observe** the change **persisted** on the **same client installation**; **forbidden** operations remain **blocked** by the server regardless of client UI state.

**Priority:** High  
**Dependencies:** FR-016  
**Constraints:** **Server-side** administrative options (e.g. **audit** **retention** **FR-028**, **server** **logging** **FR-029**) **MAY** appear in Settings **only** for users with **appropriate** roles **and** **SHALL** remain **enforced** on the server.  
**Notes:** Exact layout (tabs vs sidebar) **TBD** DD. **Further** system-level knobs **TBD**; this FR establishes the **facility**. **Administrative** **functions** **(FR-031**–**FR-035,** **FR-039)** **MAY** **live** **in** **Settings,** **a** **separate** **admin** **shell,** **or** **documented** **CLI** **(HLA)** **but** **SHALL** **remain** **RBAC-gated**. **Server** **logging** **toggles** **and** **rotation** **when** **not** **exposed** **in** **the** **desktop** **shell** **SHALL** **appear** **in** **a** **documented** **server** **administration** **surface** **with** **equivalent** **capabilities** **(FR-029)**.

---

## FR-021 — Preferred reader per document type

**Description:** For each **document type** the product **supports for open-in-reader** in v1 (at minimum those in FR-005: **PDF** and **DOCX**), Settings (FR-020) SHALL allow the user to specify a **preferred external application** used when invoking **FR-019**, **or** to select **use platform default** / **automatic** (exact labels **TBD** UX). The mechanism **SHALL** be **documented** (e.g. **path to executable**, **OS app picker**, or **registered handler id**) **per platform** in DD **without** mandating a specific OS API herein.

**Acceptance criteria:** For each v1 type, user can set **preferred**, **clear** the choice to **default**, and **open** (FR-019) reflects the choice **on a supported configuration**; invalid or missing targets produce **actionable** error **without** crashing the client.

**Priority:** High  
**Dependencies:** FR-005, FR-019, FR-020  
**Constraints:** Some environments **MAY** only support **default handler**; product **SHALL** document **limitations**.  
**Notes:** **EPUB** and future types **SHALL** gain the same **preference** row when those types become **supported**.

---

## FR-022 — Application theme

**Description:** Settings (FR-020) SHALL allow the user to select a **visual theme** for the **shell UI**, including at minimum these **shipped** defaults: **(a)** **light**, **(b)** **dark**, and **(c)** a **warm sepia** theme (e.g. **sepia-tinted** chrome and **parchment-like** **background** tones). Where the **desktop platform** exposes a **system** light/dark mode, the product **SHOULD** offer a **match system** option (or equivalent) **that maps** to **light** or **dark** **only** (sepia remains an **explicit** user choice unless **documented** otherwise in DD).

**Acceptance criteria:** User can switch among **light**, **dark**, and **warm sepia** and **observe** **shell** chrome and **documented** controls **update** accordingly; choice **persists** across restarts on the **same client** (FR-020). **All** **shipped** themes in **(a)–(c)** **SHALL** satisfy **contrast** for **shell** text and **essential** controls **per** NFR-006—**including** when **warm sepia** uses a **parchment-style** **background**, **foreground** (text, icons, borders) **SHALL** be **chosen** so **WCAG 2.1 Level AA** **contrast** **obligations** are **met** on **representative** surfaces.

**Priority:** Medium  
**Dependencies:** FR-020  
**Constraints:** **Native reader** appearance **out of scope**. **Decorative** parchment **texture** **MAY** be **subtle** **provided** **legibility** and **NFR-006** **still** **pass**.  
**Notes:** Custom **user-authored** themes or **third-party** theme packs **deferred** (waiting room).

---

## FR-023 — OCR for searchability

**Description:** For **image-only** or **scanned** PDFs (and similar) where **no** extractable text layer exists, the system SHALL support an **OCR** path to produce **indexable text**, subject to **user-visible** indication that text is **OCR-derived** and subject to **correction** workflow **as specified in Detailed Design**.

**Acceptance criteria:** Given a fixture image-only PDF, system **either** indexes after OCR **or** presents **explicit** user prompt/workflow; **silent** pretend-accuracy **prohibited**.

**Priority:** High  
**Dependencies:** FR-006  
**Constraints:** OCR engine **not** specified herein.  
**Notes:** Correction UX **TBD** in DD; ties to §6.

---

## FR-024 — Shell accessibility

**Description:** The **shell UI** SHALL meet **WCAG 2.1 Level AA** success criteria **where applicable** to the technology stack chosen in HLA (non-web shells map to **equivalent** documented checkpoints).

**Acceptance criteria:** Documented **accessibility test plan** executed; **critical** flows (login, **catalog** **browse** **FR-037**, search, open document, **Settings** per FR-020 **(including** **logging** **FR-029)**, **access Help / user documentation** per NFR-007) **pass** agreed checkpoints.

**Priority:** High  
**Dependencies:** —  
**Constraints:** **Native reader** accessibility **out of scope** (third-party).  
**Notes:** Exact audit method **in Test Plan**.

---

## FR-025 — English UI (v1)

**Description:** The **v1** product UI and **operator-facing** embedded help **SHALL** be available in **English**.

**Acceptance criteria:** No **mandatory** UI string is presented **only** in a non-English language for default install.

**Priority:** Medium  
**Dependencies:** —  
**Constraints:** —  
**Notes:** **i18n** deferred (waiting room).

---

## FR-026 — Audit logging

**Description:** The system SHALL emit **audit log events** for **security-relevant** actions including at minimum: **successful and failed authentication attempts**; **document access** attempts **including** **denied** **access** **(default:** **SHALL** **be** **audited** **unless** **administrator** **explicitly** **disables** **denied-access** **logging** **per** **DD** **for** **a** **given** **deployment)**; **successful** **open/view** **where** **configured**; and **administrative** **and** **security-configuration** **changes** **as** **enumerated** **in** **DD** **(including** **audit** **policy** **changes** **themselves**)**.**

**Audit** **capture** **SHALL** **default** **to** **enabled** **for** **the** **minimum** **event** **set** **above.** **An** **administrator** **SHALL** **be** **able** **to** **disable** **audit** **logging** **globally** **or** **per** **event** **category** **as** **documented** **in** **DD**, **subject** **to** **RBAC** **(FR-031)**; **disabling** **SHALL** **require** **confirmation** **that** **surfaces** **compliance** **and** **forensics** **risk** **(exact** **UX** **DD)**. **Timestamps** **SHALL** **use** **the** **server** **clock** **(§8)**.

**Acceptance criteria:** With **audit** **enabled**, **configured** **actions** **produce** **timestamped** **records** **with** **actor** **and** **resource** **identifier** **per** **DD**; **logs** **respect** **retention** **(FR-028)**; **with** **audit** **disabled** **per** **policy**, **no** **new** **audit** **records** **for** **disabled** **categories** **are** **written** **except** **any** **mandatory** **bootstrap** **exceptions** **stated** **in** **DD**; **denied-access** **default** **behavior** **verified** **per** **DD**.

**Priority:** Medium  
**Dependencies:** FR-016, FR-017, FR-031  
**Constraints:** **Privacy** and **retention** are **operator** policy (see §10, §12, **NFR-008**).  
**Notes:** **Audit** **(FR-026)** **is** **separate** **from** **operational**/**diagnostic** **(FR-029)**; **multiplexed** **files** **allowed** **if** **categories** **remain** **discernible** **in** **DD**.

---

## FR-027 — Password storage

**Description:** The system SHALL store **password secrets** only using **strong one-way hashing** and **never** store **cleartext** passwords.

**Acceptance criteria:** Stored credential representation **matches** documented algorithm parameters; penetration of DB **does not** reveal cleartext passwords.

**Priority:** High  
**Dependencies:** FR-016  
**Constraints:** Algorithm choice **TBD** in DD (must be **industry-accepted**).  
**Notes:** **Human-chosen** **password** **composition** **rules** **(length** **and** **character** **classes)** **are** **in** **FR-033**; **storage** **here** **concerns** **hashing** **only**.

---

## FR-028 — Configurable log retention

**Description:** The system SHALL provide **administrator-configurable** **retention** and **rotation** **policy** for **all** **persistent** **log** **families** **the** **product** **controls**: **(a)** **audit** **logs** **(FR-026)** **and** **(b)** **operational** **and** **diagnostic** **logs** **(FR-029)**. **Enable**/**disable** **and** **day-based** **rollover** **for** **(b)** **are** **specified** **in** **FR-029**; **this** **requirement** **ensures** **operators** **can** **also** **configure** **maximum** **retention** **(e.g.** **deletion** **or** **archival** **of** **files** **older** **than** **N** **days)** **per** **log** **family** **where** **policy** **or** **jurisdiction** **requires**, **with** **documented** **defaults** **and** **bounds** **(DD)**.

**Acceptance criteria:** Administrator **(or** **documented** **operator** **role)** **can** **configure** **retention**/**rotation** **limits** **for** **audit** **separately** **from** **operational**/**diagnostic** **(or** **as** **documented** **if** **unified** **surface)**; **behavior** **documented** **in** **admin** **guide** **(NFR-004)**.

**Priority:** Medium  
**Dependencies:** FR-026  
**Constraints:** **Operational**/**diagnostic** **artifacts** **and** **their** **retention**/**rotation** **knobs** **are** **defined** **in** **FR-029**; **this** **requirement** **unifies** **policy** **across** **log** **families**. **Stricter** **of** **overlapping** **policies** **SHALL** **apply** **when** **multiple** **knobs** **touch** **the** **same** **files** **(documented)**.  
**Notes:** **Centralized log shipping** deferred unless required by HLA.

---

## FR-029 — Operational and diagnostic logging (client and server)

**Description:** The **desktop client** and the **library server** **each** SHALL emit **two** **logging** **categories** **distinct** **in** **purpose** **from** **audit** **events** **(FR-026)**—though **implementation** **MAY** **multiplex** **streams** **into** **files** **if** **categories** **remain** **individually** **controllable** **per** **below**:

1. **Operational** — **routine** **lifecycle** **and** **significant** **application** **events** **suitable** **for** **day-to-day** **monitoring** **(e.g.** **startup**/**shutdown**, **ready**, **coarse** **job**/**request** **boundaries** **as** **enumerated** **in** **DD**).  
2. **Diagnostic** — **warnings**, **errors**, **and** **troubleshooting** **detail** **for** **support** **(e.g.** **error** **codes**, **correlation** **identifiers**, **limited** **context** **as** **defined** **in** **DD**).

For **each** **category** **on** **each** **component** **(client** **vs** **server)**, **the** **product** **SHALL** **provide** **an** **independent** **enable**/**disable** **control** **exposed** **through** **Settings** **(FR-020)** **for** **client** **logs**, **and** **through** **the** **documented** **server** **administration** **interface** **(HLA**—**which** **MAY** **be** **the** **same** **shell** **app** **in** **solo** **deployments)** **for** **server** **logs**, **subject** **to** **RBAC** **(FR-017)**.

**Default** **log** **file** **locations** **SHALL** **follow** **platform-idiomatic** **practice** **for** **application** **and** **service** **logs** **on** **Windows**, **macOS**, **and** **Linux** **(e.g.** **per-user** **vs** **system** **service** **directories)** **per** **HLA** **without** **prescribing** **a** **single** **canonical** **path** **in** **this** **SRS**.

**Rotation:** **Operators** **SHALL** **be** **able** **to** **configure** **time-based** **rollover**, **including** **at** **minimum** **the** **number** **of** **days** **after** **which** **a** **log** **file** **rolls** **over** **to** **a** **new** **file** **(or** **equivalent** **documented** **semantics)**. **Optional** **size-based** **rotation** **MAY** **complement** **time-based** **rotation** **(DD)**. **Maximum** **retention** **(deletion** **or** **archival** **after** **N** **days)** **SHALL** **be** **configurable** **per** **FR-028** **and** **SHALL** **apply** **consistently** **to** **operational**/**diagnostic** **artifacts** **as** **documented**.

**Acceptance criteria:** With **operational** **enabled** **and** **diagnostic** **disabled** **on** **one** **component**, **new** **diagnostic-only** **content** **(per** **DD** **taxonomy)** **does** **not** **accumulate** **in** **persisted** **logs** **for** **that** **category** **(allow** **documented** **minimal** **bootstrap** **errors** **if** **unavoidable)**; **converse** **configuration** **holds**; **both** **disabled** **stops** **routine** **persistence** **for** **both** **categories** **except** **any** **immutable** **minimum** **stated** **in** **DD**; **day-based** **rollover** **behavior** **is** **observable** **per** **DD**; **default** **paths** **and** **PII**/**secrets** **posture** **documented** **(NFR-004,** **NFR-007,** **NFR-008)**.

**Priority:** High  
**Dependencies:** FR-017, FR-020, FR-026  
**Constraints:** **Secrets**, **session** **tokens**, **passwords**, **and** **full** **document** **payloads** **SHALL** **not** **appear** **in** **cleartext** **in** **operational**/**diagnostic** **logs** **(NFR-008)**. **Maximum** **retention** **and** **family-wide** **caps** **align** **with** **FR-028**.  
**Notes:** **Audit** **(FR-026)** **remains** **governed** **by** **its** **own** **enablement**/**retention** **where** **applicable**; **diagnostic** **verbosity** **levels** **(e.g.** **debug)** **MAY** **be** **a** **separate** **DD** **topic** **if** **needed** **without** **violating** **the** **two-category** **toggle** **model** **above**.

---

## FR-030 — Release information

**Description:** The system SHALL provide a **documented, user-visible** means to determine the **running software version** (e.g. About box).

**Acceptance criteria:** Version string **visible** without network access; **matches** packaged release identifier.

**Priority:** Medium  
**Dependencies:** —  
**Constraints:** —  
**Notes:** **Automatic update checks** and **outbound telemetry** **deferred** to HLA with **privacy-preserving** defaults (waiting room / NFR).

---

## FR-031 — User account and role administration

**Description:** **Administrators** SHALL be able to **create**, **disable** or **re-enable**, and **delete** **local** user accounts (**FR-016**), **assign** and **revoke** **roles** (**FR-017**), and **assign** users to **tenant** membership (**FR-018**) through a **documented** administration surface (Settings, dedicated admin UI, and/or **documented** CLI—**HLA**).

**Acceptance criteria:** Operations **enforce** RBAC and **tenant** rules (**cross-tenant** user assignment **denied**); **last** **remaining** **administrator** **cannot** be **removed** or **disabled** **without** **documented** **transfer** **or** **replacement** **flow** **(DD)**; **audit** **events** **emitted** **per** **FR-026** **where** **audit** **is** **enabled**.

**Priority:** High  
**Dependencies:** FR-016, FR-017, FR-018  
**Constraints:** —  
**Notes:** **Directory**/**SSO** **provisioning** **deferred** **(§13)**.

---

## FR-032 — Initial administrator bootstrap

**Description:** On **first** **install** **or** **empty** **database**, the product SHALL **not** expose **full** **multi-user** **operation** **until** **at** **least** **one** **administrator** **account** **exists**. This SHALL be achieved **either** **(a)** a **guided** **first-run** **flow** **that** **creates** **an** **administrator**, **or** **(b)** a **documented** **one-time** **bootstrap** **credential** **that** **forces** **password** **change** **on** **first** **login** **(DD)**.

**Acceptance criteria:** **Clean** **install** **test** **cannot** **perform** **privileged** **operations** **without** **completing** **bootstrap**; **bootstrap** **cannot** **be** **reused** **after** **successful** **completion** **per** **DD**.

**Priority:** High  
**Dependencies:** FR-016, FR-031  
**Constraints:** —  
**Notes:** —

---

## FR-033 — Password change and administrative reset

**Description:** **Authenticated** users SHALL be able to **change** their **own** **password** subject to **current-password** **verification** **or** **equivalent** **re-auth** **per** **DD**. **Administrators** SHALL be able to **reset** another user’s password (**temporary** **password** **or** **must-change** **flag** **on** **next** **login**—**DD**). **Self-service** **out-of-band** **recovery** **(e.g.** **email** **link)** **without** **administrator** **involvement** **is** **out** **of** **scope** **for** **v1** **unless** **reopened** **(§13)**.

**Any** **new** **password** **chosen** **by** **a** **user** **(self-service** **change** **or** **post-reset)** **SHALL** **meet** **all** **of** **the** **following** **v1** **rules:** **(a)** **minimum** **length** **eight** **characters;** **(b)** **at** **least** **one** **uppercase** **Latin** **letter** **(A–Z);** **(c)** **at** **least** **one** **lowercase** **Latin** **letter** **(a–z);** **(d)** **at** **least** **one** **decimal** **digit** **(0–9);** **(e)** **at** **least** **one** **symbol** **from** **a** **documented** **non-alphanumeric** **set** **(DD** **SHALL** **enumerate** **the** **default** **permitted** **symbols** **and** **any** **operator-configurable** **variants** **where** **allowed).**

**Acceptance criteria:** **Change** **and** **reset** **flows** **invalidate** **or** **preserve** **sessions** **per** **documented** **security** **policy** **(FR-035)**; **passwords** **violating** **the** **rules** **above** **are** **rejected** **with** **clear,** **actionable** **errors** **before** **persistence**; **compliant** **passwords** **are** **accepted** **and** **stored** **per** **FR-027**.

**Priority:** High  
**Dependencies:** FR-016, FR-027, FR-031  
**Constraints:** —  
**Notes:** **Self-service** **out-of-band** **recovery** **(e.g.** **email)** **remains** **in** **§13** **unless** **promoted** **to** **scope.** **System-generated** **temporary** **passwords** **SHALL** **either** **satisfy** **the** **same** **composition** **rules** **or** **be** **usable** **only** **until** **the** **user** **sets** **a** **compliant** **password** **on** **first** **login** **per** **DD.**

---

## FR-034 — Authentication throttling

**Description:** The **library** **server** SHALL **throttle** **or** **temporarily** **lock** **authentication** **after** a **configurable** **threshold** **of** **failed** **attempts** **per** **documented** **identity** **key** **(e.g.** **username** **+** **source** **IP** **or** **client** **instance**—**DD)**. **Defaults** **and** **maximum** **lockout** **duration** **SHALL** **be** **documented** **(NFR-004)**.

**Acceptance criteria:** **Simulated** **brute-force** **fixture** **triggers** **throttle** **or** **lockout** **per** **DD**; **successful** **login** **after** **lockout** **follows** **documented** **clearing** **rules**.

**Priority:** High  
**Dependencies:** FR-016  
**Constraints:** —  
**Notes:** **CAPTCHA** **and** **external** **WAF** **integration** **deferred** **unless** **HLA** **requires**.

---

## FR-035 — Session management

**Description:** **Server-validated** **sessions** **(or** **tokens)** **SHALL** **support** **administrator-configurable** **idle** **timeout** **and** **absolute** **maximum** **lifetime** **(documented** **defaults** **and** **bounds** **in** **DD)**. **Explicit** **user** **logout** **from** **the** **client** **SHALL** **invalidate** **the** **session** **on** **the** **server** **for** **remote-capable** **deployments** **(FR-013)**.

**Per-user** **concurrent** **sessions** **(the** **same** **identity** **with** **multiple** **active** **tokens** **or** **connections** **at** **once)** **SHALL** **follow** **documented** **product** **policy:** **either** **limited** **to** **N** **simultaneous** **sessions** **or** **unlimited** **with** **documented** **semantics** **(DD)**—**this** **is** **distinct** **from** **aggregate** **deployment** **capacity** **(below).**

**Aggregate** **concurrent** **authenticated** **sessions** **across** **all** **users** **depend** **on** **hardware,** **network,** **and** **deployment** **topology** **(e.g.** **one** **server** **process** **vs.** **multiple** **instances** **behind** **routing** **and** **load** **balancing** **per** **HLA)** **and** **are** **not** **assigned** **a** **single** **numeric** **maximum** **in** **this** **SRS.** **Where** **stakeholders** **require** **it,** **stress** **or** **load** **scenarios** **in** **the** **Test** **Plan** **(and** **operator** **guidance** **in** **NFR-004)** **SHALL** **characterize** **headroom** **for** **agreed** **reference** **configurations** **(see** **NFR-001).**

**Acceptance criteria:** **Idle** **timeout** **expires** **session** **in** **test** **harness**; **logout** **prevents** **reuse** **of** **old** **token**; **per-user** **concurrent** **policy** **verified** **per** **DD** **matrix**.

**Priority:** High  
**Dependencies:** FR-016  
**Constraints:** —  
**Notes:** **Token** **binding** **to** **device** **fingerprinting** **deferred.**

---

## FR-036 — Library corpus and storage model

**Description:** The **server** SHALL maintain the **authoritative** **association** **between** **each** **catalog** **record** **(FR-001)** **and** **stored** **document** **bytes** **(path,** **object** **reference,** **or** **equivalent** **per** **HLA)** **within** **operator-configurable** **library** **storage** **roots** **or** **policies** **documented** **in** **NFR-004**. **Client** **open-in-reader** **(FR-019)** **SHALL** **not** **circumvent** **server** **authorization** **when** **the** **server** **mediates** **file** **access**.

**Acceptance criteria:** **Changing** **storage** **root** **or** **relocating** **corpus** **follows** **documented** **migration** **or** **relink** **story** **(DD)**; **missing** **bytes** **surface** **per** **FR-011**.

**Priority:** High  
**Dependencies:** FR-001, FR-013, FR-019  
**Constraints:** **Object** **storage** **backends** **beyond** **filesystem** **deferred** **unless** **HLA** **adds**.  
**Notes:** —

---

## FR-037 — Catalog browse, sort, and pagination

**Description:** The **shell** SHALL provide a **browse** **view** **listing** **catalog** **records** **visible** **to** **the** **user** **under** **RBAC**, **with** **documented** **sort** **options** **(e.g.** **title,** **date** **added,** **date** **modified)** **and** **pagination** **or** **virtualized** **scrolling** **so** **large** **libraries** **remain** **usable** **(NFR-001** **alignment)**.

**Acceptance criteria:** **Sort** **order** **is** **stable** **per** **documented** **tie-break**; **pagination** **does** **not** **drop** **or** **duplicate** **rows** **across** **pages** **under** **steady** **catalog** **state**.

**Priority:** High  
**Dependencies:** FR-001, FR-017  
**Constraints:** —  
**Notes:** **Column** **customization** **deferred** **unless** **low** **cost**.

---

## FR-038 — Search query semantics and results

**Description:** Full-text search (FR-007) SHALL implement documented v1 query semantics including all of the following:

1. **Implicit conjunction:** Whitespace-separated bare terms (outside quotes and outside explicit operators) combine with logical AND by default.

2. **Boolean operators:** The query language SHALL support explicit AND, OR, and NOT. DD SHALL define spelling, whether those keywords are case-sensitive or accepted case-insensitively, and tokenization (including how they interact with quoted phrases and bare terms).

3. **Phrase search:** Double-quoted strings denote phrase units matched as contiguous text per index capabilities (documented limitations, e.g. stemming or word breaks).

4. **Grouping:** Parentheses `(` `)` group subexpressions so precedence is unambiguous for nested boolean and phrase combinations. The grammar SHALL support **nested groups** that mix phrases and operators in any documented order, including but not limited to representative forms such as:
   - `("Phrase A" AND "Phrase B") NOT ("Phrase C" OR "Phrase D")`
   - `(term1 AND term2) NOT (term3 AND term4)`  
   and other permutations that combine grouped **OR**/**AND**/**NOT** over phrases and bare terms. DD MAY impose documented limits (e.g. maximum expression depth or query length) provided behavior remains deterministic and user-visible when limits are exceeded.

5. **Grammar and precedence:** DD SHALL publish a normative grammar (e.g. BNF or equivalent) including operator precedence and associativity where parentheses are omitted, and SHALL define interaction between phrases, operators, and implicit AND.

Matching SHALL be case-insensitive for basic Latin (other scripts per DD). Records matched only via keyword lists (FR-009) SHALL participate in queries per documented rules consistent with the same grammar where applicable. Search results SHALL support documented sort and pagination consistent with FR-037 where applicable. Fielded or metadata-only query syntax beyond full-text and keywords is optional for v1 and SHALL be specified in DD if shipped.

**Acceptance criteria:** Golden query fixtures in the Test Plan validate implicit AND, explicit AND/OR/NOT, double-quoted phrases, parenthesized grouping with **at least two** nested structures, **including** one fixture structurally similar to `("Phrase A" AND "Phrase B") NOT ("Phrase C" OR "Phrase D")` and one similar to `(term1 AND term2) NOT (term3 AND term4)` (exact literals per Test Plan), case behavior for Latin text, and keyword-only hits (FR-009). Malformed queries (e.g. unbalanced parentheses, empty phrases) fail with user-visible, actionable feedback without server fault.

**Priority:** High  
**Dependencies:** FR-007, FR-009  
**Constraints:** —  
**Notes:** Relevance ranking algorithm TBD in DD (deterministic tie-break required for tests). Latin case behavior for search *terms* is distinct from boolean *keyword* case rules (items 2 and 5).

---

## FR-039 — Full-text index administration

**Description:** **Administrators** SHALL be able to **trigger** **full** **or** **scoped** **rebuild** **of** **the** **full-text** **index** **(FR-006)** **and** **to** **view** **index** **status** **(e.g.** **last** **successful** **build,** **in-progress** **job)** **per** **DD**. **Rebuild** **SHALL** **be** **safe** **to** **run** **while** **the** **system** **is** **online** **or** **SHALL** **document** **maintenance** **mode** **requirements** **(HLA)**.

**Acceptance criteria:** **After** **corrupted** **index** **fixture,** **rebuild** **restores** **search** **per** **FR-007**; **progress** **or** **completion** **is** **observable** **per** **DD**.

**Priority:** Medium  
**Dependencies:** FR-006, FR-031  
**Constraints:** —  
**Notes:** —

---

## FR-040 — Metadata validation

**Description:** **Editable** **metadata** **(FR-002)** **SHALL** **use** **Unicode** **(UTF-8)** **text** **with** **per-field** **maximum** **lengths** **and** **disallowed** **control-character** **policy** **documented** **in** **DD**. **A** **non-empty** **title** **(or** **documented** **primary** **label** **field)** **SHALL** **be** **required** **to** **mark** **a** **record** **catalog-complete** **except** **where** **import** **staging** **rules** **explicitly** **allow** **temporary** **incomplete** **records** **with** **persistent** **user-visible** **warning**.

**Acceptance criteria:** **Overlong** **or** **invalid** **input** **is** **rejected** **with** **actionable** **errors**; **required** **title** **rule** **verified** **per** **DD**.

**Priority:** Medium  
**Dependencies:** FR-002, FR-004  
**Constraints:** —  
**Notes:** —

---

## FR-041 — Concurrent metadata updates

**Description:** When **two** **sessions** **update** **the** **same** **catalog** **record**, the **server** SHALL **enforce** **optimistic** **concurrency** **using** **a** **version** **counter,** **ETag,** **or** **equivalent** **per** **DD**. **Stale** **updates** **SHALL** **fail** **with** **an** **error** **that** **allows** **the** **client** **to** **refresh** **and** **retry** **without** **silent** **overwrite**.

**Acceptance criteria:** **Concurrent** **edit** **test** **produces** **exactly** **one** **successful** **commit** **without** **lost** **updates** **unless** **user** **explicitly** **chooses** **overwrite** **per** **DD** **(if** **offered)**.

**Priority:** High  
**Dependencies:** FR-002, FR-017  
**Constraints:** —  
**Notes:** —

---

# 5. Non-Functional Requirements (NFRs)

---

## NFR-001 — Corpus scale (qualitative)

**Category:** Scalability  

**Description:** The system SHALL support **routine** catalog, browse (**FR-037**), and search (**FR-007**, **FR-038**) operations for libraries of **at least 10,000** catalog records **without** requiring **manual database surgery** for normal operation. **Architecture** **and** **index** **design** **SHALL** **treat** **corpora** **on** **the** **order** **of** **100,000** **documents** **as** **a** **design-center** **scale** **(concept** **alignment)** **even** **when** **formal** **release** **testing** **initially** **emphasizes** **the** **10,000-record** **verification** **gate** **below**.

**Deployments** **that** **require** **high** **aggregate** **concurrency** **MAY** **use** **multiple** **server** **instances** **behind** **network** **routing** **and** **load** **balancing** **(HLA);** **maximum** **sustainable** **authenticated** **session** **count** **and** **throughput** **depend** **on** **hardware,** **network,** **and** **topology** **and** **are** **not** **fixed** **by** **this** **SRS** **(see** **FR-035** **for** **per-user** **vs.** **aggregate** **distinction).**

**Measurement criteria:** **Load test** with **10,000** representative records on a **reference environment** defined in the **Test Plan**; **no** unbounded memory growth on **steady-state** browse/search **as defined in Test Plan**. **Optional** **stretch** **scenario** **(e.g.** **50k–100k** **synthetic** **records)** **MAY** **be** **defined** **in** **Test** **Plan** **as** **an** **engineering** **signal** **without** **being** **a** **v1** **release** **blocker** **unless** **promoted** **by** **stakeholders**. **Where** **stakeholders** **require** **capacity** **evidence,** **the** **Test** **Plan** **MAY** **add** **concurrent-session** **or** **multi-instance** **stress** **scenarios** **against** **agreed** **reference** **hardware** **profiles** **to** **identify** **when** **additional** **instances** **or** **capacity** **are** **warranted**—**without** **prescribing** **a** **universal** **numeric** **connection** **ceiling.**

**Constraints:** Does **not** fix **latency** milliseconds on all hardware.  
**Dependencies:** Test Plan, HLA, FR-035, FR-037, FR-038.

---

## NFR-002 — Server-side enforcement

**Category:** Security  

**Description:** **All** authorization outcomes for **controlled operations** SHALL be **decided** and **enforceable** at the **server** boundary.

**Measurement criteria:** **Negative tests** at API level **per role matrix**; **no** single-client bypass for **remote** deployment.

**Constraints:** —  
**Dependencies:** FR-013, FR-017, NFR-009 (remote **transport** **security** **posture**).

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

**Description:** The project SHALL publish **operator documentation** describing **backup scope** (corpus, database, index, configuration, logs), **security boundaries**, and **privacy-relevant** data flows **at a conceptual level** sufficient for **informed deployment**. The admin guide SHALL cover first-run bootstrap (FR-032), user and role administration (FR-031), **import authorization** (administrator-only default per FR-004), **content digest persistence and algorithm identifiers** (FR-010), **missing-file detection and administrator notification defaults** (FR-011), password composition policy as deployed (FR-033), session and lockout policy (FR-034, FR-035), TLS and certificate handling (NFR-009), library storage roots (FR-036), index rebuild (FR-039), and time synchronization expectations (§8). It **SHALL** **identify** **default** **locations** **(or** **discovery** **method)** **for** **audit** **(FR-026)**, **operational**, **and** **diagnostic** **logs** **(FR-029)** **on** **each** **supported** **platform**, **summarize** **what** **each** **log** **family** **may** **contain**, **and** **reference** **retention**/**rollover** **controls** **(FR-028,** **FR-029)** **and** **jurisdictional** **considerations** **(NFR-008)**.

**Measurement criteria:** **Reviewer** can answer: what to back up, what is logged, **where** **each** **log** **type** **resides**, **how** **to** **tune** **retention**/**rollover**, **and** where **secrets** live—using **only** shipped docs.

**Constraints:** Complements **NFR-007** (end-user / day-to-day documentation); **admin** vs **end-user** material **MAY** share a **Help** shell but **SHALL** remain **discernible** (e.g. separate sections or guides).  
**Dependencies:** `system-documentation/user-documentation/` (e.g. admin guide); stubs to be expanded for release; FR-004, FR-010, FR-011; FR-026–FR-029 (logging and retention); FR-031, FR-032, FR-034, FR-035, FR-036, FR-039; NFR-009 (TLS).

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

**Description:** For **each** **shipped** **shell** theme in **FR-022**—**light**, **dark**, and **warm sepia** (including **parchment-style** **backgrounds** where used)—**shell UI** text and **essential** interactive controls **SHALL** meet **contrast** requirements **aligned** with **WCAG 2.1 Level AA** for **normal** and **large** text **as applicable** to the toolkit (verification method **in Test Plan**). **Non-text** contrast for **UI** components **SHALL** follow **the same conformance target** **where** **WCAG 2.1** **applies** to **non-text** content **per** agreed **test** mapping.

**Measurement criteria:** **Automated** and/or **manual** contrast checks on **agreed** **representative** screens (including **Settings** and **theme** **switching**) **pass** for **all** **shipped** themes **or** **defects** are **tracked** as **release blockers**.

**Constraints:** Does **not** guarantee **custom** OS **high-contrast** modes beyond **documented** behavior. **Parchment** or **textured** **backgrounds** **MUST NOT** **excuse** **sub-AA** **contrast** for **primary** reading and **control** **labels**.  
**Dependencies:** FR-024, FR-022.

---

## NFR-007 — End-user documentation and Help

**Category:** Usability / Maintainability  

**Description:** The product SHALL ship end-user documentation in English (FR-025), comprising at minimum: **(a)** a User manual describing primary shell workflows—including catalog browse (FR-037); search semantics at user level (FR-007, FR-038); metadata and tags including **publication date** and **acquisition date** where shown (FR-002); validation and edit conflicts (FR-040, FR-041); **that document import is restricted to administrators** (or documented import permission) and how solo users satisfy that role (FR-004, FR-014, FR-032); missing-file or degraded-access behavior for the reader’s role (FR-011); open in native reader (FR-019) and reader preferences (FR-021); Settings (FR-020); password change (FR-033); logout and session behavior summary (FR-035); client operational/diagnostic logging controls and default log locations (FR-029); and RBAC-visible behavior (e.g. denied access and tenant visibility)—and **(b)** a Quick-start guide sufficient for a new user to install or connect the client, complete or skip bootstrap per role (FR-032), authenticate if required, and **as a user who may perform import** (administrator in typical solo or multi-user setups per FR-004), import at least one document successfully. Source MAY be maintained under `system-documentation/user-documentation/` (or successor path) and SHALL be packaged or published with releases per HLA (e.g. HTML, PDF, Markdown bundle—exact formats TBD).

The **shell UI** SHALL provide a **user-discoverable** **Help** affordance (e.g. **Help** menu, **toolbar**, or **Settings** link—**TBD** DD) that **reaches** the **Quick-start** and **User manual** for the **running** **product version** (e.g. **opens** bundled content in an **embedded** viewer, **local** help window, or **system** browser—**not** mandated herein).

**Measurement criteria:** **Release checklist:** manual + quick-start **present**, **version** **aligned** with the **release**; **smoke test:** **novice** or **proxy** user completes **Quick-start** **without** **engineering** support **or** **gaps** are **recorded** and **tracked**; **Help** entry **reachable** from **default** logged-in shell within **documented** **click**/**key** budget.

**Constraints:** **Searchable** **full** in-app help **index**, **context-sensitive** (F1) help, and **very large** manual **browse/search** **UX** are **deferred** to **§13** unless **implemented** **early** via a **chosen** component. A **pre-built** help **component** or **viewer** **MAY** be used **provided** **licenses** are **compatible** with **Apache-2.0** distribution (or **clearly** **optional**), **security** posture is **acceptable**, and **accessibility** (FR-024) **obligations** are **met** for the **help** surface.

**Dependencies:** FR-002, FR-004, FR-011, FR-025; FR-024; FR-029; FR-033, FR-035, FR-037, FR-038, FR-040, FR-041; NFR-004, NFR-008 (operator docs distinct but may cross-link).

---

## NFR-008 — Logging: privacy and jurisdictional readiness

**Category:** Compliance / Security  

**Description:** **Audit** **(FR-026)**, **operational**, **and** **diagnostic** **(FR-029)** **logging** **SHALL** **be** **designed** **assuming** **strict** **privacy**, **employment**, **health**, **or** **sector-specific** **rules** **may** **apply** **in** **some** **deployments**. **The** **product** **SHALL** **support** **data** **minimization** **in** **log** **content**, **purpose** **limitation** **and** **retention** **discipline** **documented** **for** **operators** **(NFR-004)**, **separation** **of** **audit** **from** **technical** **diagnostics** **where** **appropriate**, **and** **operator-configurable** **retention**, **rollover**, **and** **enablement** **(FR-028,** **FR-029)** **so** **that** **lawful** **basis**, **processor** **obligations**, **and** **internal** **policy** **can** **be** **honored** **without** **undocumented** **immutable** **log** **behavior**.

**Measurement criteria:** **Privacy**/**compliance** **review** **checklist** **passes**: **cleartext** **secrets**/**credentials**/**tokens**/**full** **document** **bodies** **absent** **from** **operational**/**diagnostic** **logs** **(FR-029)**; **documentation** **states** **what** **identifiers** **or** **paths** **may** **constitute** **personal** **data** **and** **recommended** **configurations** **for** **restrictive** **jurisdictions**; **tests** **verify** **disable** **stops** **new** **persistence** **per** **FR-029** **acceptance**.

**Constraints:** **Does** **not** **warrant** **compliance** **with** **any** **specific** **statute**; **operators** **and** **controllers** **remain** **accountable** **for** **legal** **interpretation**.  
**Dependencies:** FR-026, FR-028, FR-029, NFR-004.

---

## NFR-009 — Transport security (remote access)

**Category:** Security  

**Description:** For **client-to-server** **communication** **over** **non-loopback** **networks**, **the** **product** **SHALL** **use** **TLS** **(or** **equivalent** **documented** **secure** **channel)** **with** **a** **default** **minimum** **protocol** **version** **and** **cipher** **policy** **aligned** **with** **current** **industry** **practice** **at** **release** **(e.g.** **TLS** **1.2** **minimum** **unless** **a** **later** **floor** **is** **mandated** **by** **platform** **policy**—**exact** **parameters** **in** **DD)**. **Operators** **SHALL** **be** **able** **to** **configure** **server** **certificates** **and** **trust** **anchors** **per** **NFR-004**. **Loopback** **solo** **deployments** **MAY** **use** **non-TLS** **IPC** **only** **if** **documented** **as** **not** **exposing** **the** **API** **beyond** **localhost**.

**Measurement criteria:** **Security** **test** **checklist** **confirms** **no** **cleartext** **password** **or** **session** **token** **on** **the** **wire** **for** **remote** **profiles**; **outdated** **protocols** **disabled** **by** **default** **per** **DD**.

**Constraints:** **Certificate** **pinning** **and** **mTLS** **deferred** **unless** **required** **by** **HLA**.  
**Dependencies:** FR-013, FR-014, NFR-004.

---

# 6. Deterministic–Probabilistic Requirements

**Applicability:** **OCR** and **layout extraction** behave **probabilistically** with respect to input quality. **No generative-AI** product features in v1.

**Expectations**

- **OCR and extraction outputs** MAY **differ** from **visually apparent** text; **error rate** is **input-dependent**.  
- The system SHALL **surface** when text used for search is **OCR-derived** or **otherwise unreliable** per FR-023 and DD.  
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
- **Network:** **Remote** access **SHALL** meet **NFR-009**; **operators** **supply** **certificates** **and** **trust** **policy** **per** **NFR-004**.  
- **Maintainer distribution:** **No** maintainer-operated **mandatory** SaaS; **self-host** or **solo** use.

---

# 8. Assumptions

- **Operators** have **lawful rights** to index and store documents they import.  
- **Users** accept **native readers** for **display** fidelity.  
- **Counsel review** will complete **before** **marketing** or **enterprise** claims.  
- **Reference hardware** for **Meaningful** performance characterization **will be** defined in **Test Plan**.  
- **Third-party** OCR/parser **licenses** remain **compatible** with **Apache-2.0** distribution **or** are **optional** plug-ins **clearly** separated ( **TBD** HLA).  
- **Trustworthy** **timestamps** **for** **audit** **and** **logs** **depend** **on** **accurate** **server** **(and** **where** **applicable** **client)** **system** **time**; **operators** **SHALL** **maintain** **time** **sync** **(e.g.** **NTP)** **per** **NFR-004** **guidance**—**the** **product** **does** **not** **replace** **an** **authoritative** **time** **source**.

---

# 9. Interfaces and External Dependencies

- **File system** paths or **administrator-configured** storage locations for **document bytes**.  
- **Operating system** services to **launch native readers** with **file** or **URI** targets.  
- **Human users** via **shell UI** and **native readers** (external).  
- **Client preference data** (reader choices, theme, **logging** **toggles**/**rotation** **values**, and future Settings) **SHALL** **persist** on the **client** **per** DD (local store, profile path, or equivalent); **synchronization** of preferences across machines **deferred** unless **specified** in HLA.  
- **Operational** **and** **diagnostic** **log** **files** **(FR-029)** **SHALL** **reside** **at** **platform-appropriate** **paths** **per** **HLA**; **server** **log** **paths** **SHALL** **follow** **service**/**daemon** **conventions** **per** **OS**.  
- **Future:** optional **update metadata** endpoint **deferred**; **no** **public application API** in v1.  
- **No** specific **vendor** OCR, PDF, or UI framework **required** in this SRS.

---

# 10. Data Requirements

- **Catalog data** (metadata, tags, keywords, paths, tenant, permissions) **SHALL** be **durable** (survive restart).  
- **Full-text index** **SHALL** be **rebuildable** from **source documents** and **catalog** state **per documented** procedure (acceptable **downtime** **TBD** HLA).  
- **Passwords:** **hashed** only (FR-027).  
- **Audit logs:** **personal data** in some jurisdictions; **purpose limitation** and **retention** **operator-configured** (FR-028, **NFR-008**).  
- **Operational** **and** **diagnostic** **logs** **(FR-029):** **MAY** **contain** **identifiers**, **paths**, **or** **other** **personal** **data**; **minimization** **and** **retention** **SHALL** **align** **with** **NFR-008** **and** **operator** **policy**.  
- **Client preferences** (FR-020–FR-022, **FR-029**, **and** **other** **client-held** **settings**): **SHALL NOT** be used to store **server secrets** or to **bypass** authorization; **backup** scope **MAY** include **client** preference stores **where** operators **document** **enterprise** restore practices (solo: typically **user-local**). **Server-side** **administration** **data** **(FR-031**–**FR-035,** **FR-039)** **SHALL** **be** **durable** **and** **included** **in** **operator** **backup** **guidance** **(NFR-004)**.  
- **Backups:** **ideal** includes **corpus + DB + index + config + logs**; **minimal** subset **documented** for operators (NFR-004).

---

# 11. Error Handling and Edge Conditions

- **Import** of **unreadable** or **unsupported** files **SHALL** **fail** with **actionable** messages.  
- **Partial index** failures **SHALL** **not** present **silent** success.  
- **Concurrent** **edits** **to** **the** **same** **catalog** **record’s** **metadata** **SHALL** **follow** **FR-041** **(optimistic** **concurrency):** **stale** **updates** **fail** **without** **silent** **overwrite;** **the** **client** **SHALL** **support** **refresh** **and** **retry** **per** **DD;** **an** **optional** **explicit** **user** **overwrite** **after** **conflict** **MAY** **be** **offered** **per** **DD** **(if** **offered,** **SHALL** **be** **documented** **and** **tested).**  
- **Server unavailable:** client **SHALL** **degrade** **per documented** behavior (offline **editing** **not** required in v1).

---

# 12. Security and Compliance Requirements

- **Authentication** and **RBAC** per FR-016–FR-018.  
- **Multi-factor authentication (MFA)** **is** **not** **required** **in** **v1** **and** **is** **out** **of** **scope** **unless** **reopened** **(§2.2);** **any** **future** **MFA** **SHALL** **be** **optional** **per** **deployment.** **Passkey** **/** **WebAuthn** **sign-in** **is** **deferred** **as** **a** **candidate** **capability** **(§13).**  
- **Client Settings** (FR-020) **SHALL NOT** allow **elevation** of privilege or **access** to **documents** **contrary** to **server** decisions; **UI** hiding alone **is** **insufficient** for **security** on **remote** deployments (FR-013).  
- **Transport security** for **remote** access **SHALL** satisfy **NFR-009**; **loopback** **solo** **profiles** **per** **documented** **HLA** **exception**.  
- **Audit** optional events per FR-026 with **privacy** awareness.  
- **Operational**/**diagnostic** **logs** **(FR-029):** **Where** **viewing** **or** **export** **is** **exposed** **in** **UI**, **access** **SHALL** **respect** **RBAC** **(FR-017)**. **Log** **content** **SHALL** **satisfy** **NFR-008** (**no** **cleartext** **secrets**, **session** **tokens**, **passwords**, **or** **full** **document** **payloads** **in** **operational**/**diagnostic** **streams**).  
- **Regulatory:** **Operators** **remain** **responsible** **for** **lawful** **processing**; **the** **product** **provides** **controls** **and** **documentation** **(including** **NFR-008)** **but** **not** **legal** **advice** **or** **jurisdiction-specific** **certification**.  
- **Accessibility law** alignment **targeted** via FR-024; **jurisdiction-specific** claims **deferred** to **counsel**.

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
- **Self-service** **password** **recovery** **(e.g.** **email** **magic** **link)** **without** **administrator** **involvement**  
- **Passkeys** **/** **WebAuthn** **(platform** **or** **roaming** **authenticators)** **as** **an** **optional** **sign-in** **method** **alongside** **or** **instead** **of** **password** **where** **client** **and** **server** **design** **permit**—**candidate** **post-v1** **feature** **(requirements** **and** **UX** **TBD** **HLA** **/** **DD;** **privacy** **and** **account** **recovery** **story** **must** **be** **explicit)**

---

# 14. Risk Assessment

| Risk                                   | Level            | Mitigation (requirements-level)     |
| -------------------------------------- | ---------------- | ----------------------------------- |
| **Extraction/OCR inaccuracy**          | **High**         | §6, FR-023, FR-007 honest semantics |
| **Search query parsing / user expectation** | **Moderate**  | FR-038 normative grammar, golden fixtures, NFR-007 |
| **Non-administrator expects to import** | **Low–Moderate** | FR-004, NFR-007, RBAC messaging   |
| **User expects SharePoint parity**     | **Moderate**     | §2.2 non-goals, operator docs       |
| **Remote access misconfiguration**     | **High**         | NFR-002, NFR-004, NFR-009, HLA     |
| **Credential / session abuse**         | **High**         | FR-034, FR-035, NFR-009, FR-033     |
| **Concurrent-edit data loss**          | **Moderate**     | FR-041                              |
| **Legal/DRM boundary**                 | **Moderate**     | FR-006, FR-009, §7                  |
| **Accessibility verification gaps**    | **Moderate**     | FR-024 + Test Plan                  |
| **Documentation / Help gaps**          | **Moderate**     | NFR-007 checklist, Quick-start test |
| **Scope creep (web/API)**              | **Moderate**     | §13 waiting room                    |
| **Reader preference misconfiguration** | **Low–Moderate** | FR-021 acceptance, clear fallback   |
| **Logging / retention compliance**       | **Moderate**     | FR-029, FR-028, NFR-004, NFR-008    |

---

# 15. Traceability Readiness Declaration

- **FR-001–FR-041** and **NFR-001–NFR-009** assigned in this revision: **Yes**
- **Acceptance criteria** present per item: **Yes** (subject to refinement)
- **Architecture** embedded: **Avoided** (no stack mandates)
- **RTM:** Not yet populated — SHALL be created before implementation phase per **LIFECYCLE.md**
- **Waiting room** separated: **Yes**
- **Probabilistic** bounds for OCR: **Yes** (§6)
- **FR numerical order matches document headers (§4 index): Yes as of Last revised**

---

# 16. Phase Gate Declaration

Confirm readiness to proceed to **High-Level Architecture**:

- **Requirements stable?** **Partial** — revision **0.9** (2026-04-11) updates **FR-002** (publication/acquisition dates), **FR-004** (admin-only import), **FR-010** (digest persistence), **FR-011** (solo vs multi-user missing file), **FR-013** Notes, **FR-038** (nested query examples); stakeholder pass still recommended before Architecture
- **NFRs measurable?** **Partial** — **NFR-001** gates on Test Plan; **NFR-009** on security checklist
- **Scope boundaries explicit?** **Yes**
- **Traceability scaffold prepared?** **No** — RTM next
- **Human approval granted?** **No** — required after final SRS review and RTM draft

**Action:** Remain in **Requirements** until RTM draft, any targeted SRS tweaks, and recorded human approval to Architecture per **LIFECYCLE.md**.

---

# Approval

Approved By: *— pending —*  
Role:  
Date:  
Version Incremented:  

Advancement to High-Level Architecture requires explicit authorization per **LIFECYCLE.md**.

---

End of SRS (draft)

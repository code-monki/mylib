<!--
File: system-documentation/system-artifacts/_process/project-primer.md

Purpose:
  Ideation-phase Project Primer (historical record) aligned with repository lifecycle.

Lifecycle authority:
  ../LIFECYCLE.md

Related artifact:
  ../concept.md (expanded concept narrative)

This primer defines intent. It does not authorize architecture or implementation.
-->

# Project Primer

Project Name: MyLib  
Initiation Date (YYYY-MM-DD): 2026-04-03  
Author(s): Charles McKnight  
Lifecycle Phase: Implementation preparation (DD v0.1, Test Plan v0.1, RTM v0.1 approved 2026-04-28; see [`../LIFECYCLE.md`](../LIFECYCLE.md "Lifecycle") §6)  
Version: 1.3  
RTM Scaffold Created? Yes ([`../rtm.md`](../rtm.md "Rtm") v0.1 **Approved**; HLA + DD §4.x mapped; DD §5 contracts per RTM §2.1; execution/package columns lifecycle-gated)  

---

# 1. Problem Statement

- **The problem being addressed**  
  People who manage **large, heterogeneous** electronic document collections (PDF, word-processing formats, EPUB, etc.) face **fragmented workflows**: finding content requires **opening many files** in different applications; **search across the corpus** is painful; **jumping from a search hit** to the right place inside a document is **unreliable**, especially for PDF and layout-heavy files; **categorization** drifts; **complex layouts and tables** break naive text extraction; **scanned or low-quality PDFs** may need **OCR**, which introduces **errors** that require **human correction**. At scale (on the order of **thousands to hundreds of thousands** of documents), these issues compound.

- **Why it matters**  
  Time lost to search and manual opening, **inconsistent metadata**, and **weak access governance** reduce productivity for **researchers, archivists, and small teams**. Personal motivation includes corpora on the order of **~10,000** publications from **diverse sources**, where **normalization and findability** are the bottleneck.

- **Who is impacted**  
  **Individual researchers**, **archivists**, **small to medium teams**, and **administrators** who deploy and operate a shared library. **Large enterprises** with enterprise DMS budgets are **not** the primary focus.

- **The cost of inaction**  
  Continued reliance on **ad hoc folders**, **multiple readers**, and **no unified access policy** means **persistent search/navigation friction**, **metadata chaos**, and **higher risk** of inappropriate access or accidental loss when files move or are deleted outside any library tool.

This section describes the **problem only**.

---

# 2. Desired Outcomes


- **Observable success conditions**  
  Users can **discover** documents via **search and filters** (including **tags**); where **full-text index** is impossible (e.g. **DRM-protected EPUB** without circumvention), **user-associated keywords** (separate from tags) support **discovery**; **metadata** (Dublin Core–inspired and bibliographic fields) is **usable** for organization; **access** aligns with **RBAC** enforced **server-side**; **duplicate imports** detected via **content digest** (e.g. SHA-256) **warn** the user, who **chooses** the next action (**no silent** resolution); **missing files** are **detected** and **relinked** deliberately; **removal from the application** is **separate** from **deletion on disk**, with **admin confirmation**. **Shell UI** targets **WCAG 2.1 Level AA** where achievable.

- **Measurable impact (if known)**  
  Not yet specified with numeric SLAs; **scale** is understood as **10³–10⁵+** documents. **Performance targets** are **deferred** pending requirements and hardware diversity.

- **Conceptual acceptance criteria**  
  **Search and navigation** are **as accurate as extraction/OCR quality allows**, with **honest** handling of **bad PDFs and tables**. **IP protection** is addressed through **admin-configurable** controls (who may access; constraints on modify/save/copy **as enforced by the product**), without claiming **impossibility** of determined misuse (e.g. screenshots). **Display and printing** are **not** required to be implemented inside MyLib if **native readers** provide them.

Outcomes describe **results**, not system structure.

---

# 3. Stakeholders

- **Primary stakeholders**  
  Individual researchers; archivists; small to medium teams.

- **Secondary stakeholders**  
  Contributors to an **open-source** project; future packagers or integrators.

- **Decision makers**  
  Project maintainer(s); **deployment administrators** for each installation.

- **Operational owners**  
  **Administrators** responsible for **tenant boundaries**, **backups**, **availability**, and **legal compliance** in their environment.

- **Compliance stakeholders (if applicable)**  
  Operators subject to **privacy** rules where **accounts and audit logs** constitute **personal data**; **no dedicated legal role** in-project—**counsel** when exposure grows (e.g. EU, enterprise).

---

# 4. Context and Environment

- **Business context**  
  **Non-commercial open-source** intent; **not** competing directly with **SharePoint-class** enterprise stacks for v1. **License:** **GPL-3.0-or-later** (root `LICENSE`); **counsel sign-off** pending before treating publication as final.

- **Existing systems**  
  Documents originate from **many sources** and formats; users already rely on **OS file storage** and **native/desktop readers**.

- **Integration boundaries**  
  **Native applications** for **viewing and printing**; potential **OS APIs** for open-with and (aspirationally) **hand-off of search** to readers. **No web SPA** in initial scope.

- **Organizational constraints**  
  **Small teams** and **individuals**; **desktop install** is acceptable.

- **Regulatory considerations (if applicable)**  
  **Copyright and DRM:** product should **not** center on **circumventing** technical protection measures. **Privacy:** **minimal** account data; **audit logs** may be sensitive; **operator responsibility** for lawful processing. **Disclaimer and license** to be **lawyer-reviewed** when public.

- **Operational environment**  
  **User-specified storage** (local or **remote server** for multi-user). **Network exposure** (e.g. opening a **port** for remote clients) is the **operator’s** choice and responsibility. **Maintainer** does not anticipate operating a **hosted SaaS**; **community support** via **GitHub**; **others** may self-host or fork. **Offline/sync deferred.** **Distribution** envisioned via **GitHub Pages** (presence) and **GitHub Releases** (binaries); **dual installer** lines anticipated—**solo** (client + co-located server) vs **server/self-hosted multi-user** (details in HLA/release). **macOS signing/notarization** via **Apple Developer Program** (not App Store initially). **Official** Windows/Linux (non-Apple) release binaries: **SignPath** (or equivalent) **as applicable**, via **CI**—**separate** from Apple; **source builds** may remain **unsigned**.

---

# 5. Constraints

- **Technical constraints**  
  **Desktop:** Windows, macOS, Linux. **English** UI/docs first; **i18n** later. **Web client, public API, scripting** deferred. **Symbolic links** unlikely in v1. **Numeric performance SLAs** deferred.

- **Resource constraints**  
  **Open-source** maintenance; **signing/notarization** (Apple + **SignPath** or similar for non-Apple **release** artifacts) and **release** pipelines are **real costs** but **not** treated as blockers.

- **Timeline constraints**  
  None fixed in this primer.

- **Infrastructure limitations**  
  **Backup/restore** and **bulk storage** largely **administrator-owned** initially. **Ideal backup** includes **corpus**, **database**, **index state**, **config**, and **logs**; **practical** scope depends on **operator storage**. **Log rotation/retention** on an **administrator-configured** schedule (**Requirements/HLA**).

- **Governance requirements**  
  **RBAC**; **separation of admin vs everyday user** recommended; **tenant boundary** defined by **admin**, **enforced** by app.

- **Compliance requirements**  
  **Accessibility** for **shell UI** is a **hard requirement**, targeting **WCAG 2.1 Level AA** where achievable. **Privacy-sensitive** logging and retention to be **documented** for operators.

---

# 6. Risks and Unknowns

| Risk / unknown                                                                                          | Level                                  |
| ------------------------------------------------------------------------------------------------------- | -------------------------------------- |
| **Search/navigation accuracy** limited by **extraction, OCR, tables, cursed PDFs**                      | **High**                               |
| **IP / access control** expectations vs **technical reality** (e.g. remote open implies local handling) | **Moderate**                           |
| **Maintenance burden** for admins and users (indexing, corrections, updates)                            | **Moderate**                           |
| **Hand-off to native reader** with **search term**—**inconsistent** across readers/OS                   | **Moderate**                           |
| **Bulk import** vs **manual correction** workload                                                       | **Moderate**                           |
| **Legal/disclaimer** wording and **license** choice                                                     | **Low–Moderate** (until wide exposure) |
| **Open source license** (copyleft vs permissive) affecting **adoption**                                 | **Low–Moderate**                       |
| **OCR / extraction** producing **wrong text** without visible **review** path                           | **High** (if unmitigated in design)    |

**Probabilistic integration (AI):** **Generative AI** not in scope for v1. **OCR** and layout extraction behave **unreliably** on some inputs; treat as **validation-heavy**, not **trust blindly**.

Unclassified risks indicate incomplete ideation—above table should be revisited before Requirements.

---

# 7. Preliminary Non-Functional Considerations

At a conceptual level:

- **Performance sensitivity**  
  **High** for **interactive search** at large corpus sizes; **exact targets** deferred.

- **Scalability expectations**  
  **Tens to hundreds of thousands** of documents; possibly more.

- **Security implications**  
  **Client–server topology:** **authentication** and **RBAC** decisions are **enforced by a server**; **solo desktop** deployments run the server **co-located** on the same machine (e.g. loopback)—not **security-by-hiding** admin UI in the client alone for **remote** use. **v1** leans toward **local accounts** (enterprise directory/SSO deferred unless reprioritized). **Outbound traffic** should be **minimal by default**; **notifying users of new versions** is **desired**—exact design **deferred** to **Requirements / HLA**. **Audit logging**, **encryption** as appropriate; **hashed passwords**, **minimal PII**.

- **Reliability posture**  
  **Explicit handling** of **missing files**; **no silent** path drift for moved files.

- **Auditability expectations**  
  **Access logging** may be required for **governance**; design for **purpose limitation** and **retention** policy.

- **Reproducibility requirements**  
  **Build and release** should be **documented**; **clean** install from **signed** artifacts where applicable.

- **Maintainability concerns**  
  **Dependency** on **third-party readers** and **format parsers/OCR**; **table-heavy** documents increase **engineering** and **QA** load.

These inform **Requirements**; they do **not** select architecture.

---

# 8. Deterministic–Probabilistic Awareness (If Applicable)

- **Nature of uncertain behavior**  
  **OCR** and **text extraction** from complex PDFs and **tables** produce **imperfect** text; outcomes depend on **document quality** and **pipeline**.

- **Areas of uncertainty**  
  Correct **character** and **reading order**; **table** structure vs **linearized** search index.

- **Potential containment challenges**  
  Search hits may **not align** with **reader display**; users need **clear** indication when **index text** is **untrusted** or **pending correction**.

- **Validation concerns**  
  **Manual correction** and **review queues** (especially if **bulk import** is added).

- **Governance risks**  
  Overstating **“accurate search”** without **qualifying** extraction limits; **audit logs** and **privacy**.

**No generative-AI** product features assumed in v1; if added later, **boundary and validation** rules would follow lifecycle governance.

---

# 9. Alternative Solution Directions

Describe at least two **conceptual** directions (**no selection** in Ideation):

**Conceptual Option A — Desktop shell with embedded web technology**  
A single cross-platform **desktop** app using an **embedded browser engine** for the **shell UI**, with **native** bridges for **file system** and **open-in-reader**. **Pros:** one UI stack, large ecosystem. **Cons:** runtime weight, security discipline for **node/native** boundaries, updater story may be **stack-specific** (e.g. Electron-style).

**Conceptual Option B — Native toolkit (e.g. Qt-class)**  
**Pros:** **native** UX and integration, potentially **lighter** deployment, strong **OS** integration. **Cons:** different skill set, **cross-platform** polish is **effort**, optional **Qt WebEngine** reintroduces **Chromium** if web tech is used for UI.

**Trade-offs**  
Signing, notarization, and **Sparkle vs stack updater** interact with **A vs B** but **do not** alone **decide** the split.

**Open questions**  
Which stack best satisfies **accessibility**, **long-term maintenance**, and **secure** **remote + local** deployment for **multi-user** without a **web SPA**, given a **client–server** product shape (solo = **co-located server**)?

---

# 10. Preliminary Scope Boundaries

- **Likely in-scope (initial)**  
  **Desktop** library **client** and **server** (same installer/deployment may bundle both for solo use); **optional** **start server at OS login or boot** (or equivalent “always-on server” mode) so the library stays **reachable** without manually launching the client—**configurable** by user/admin; **import** (menu + file dialog); **metadata** (Dublin Core–ish + bibliographic fields); **free-form tags**; **user keywords** for items without buildable full-text index (e.g. **DRM EPUB**); **full-text search**; **content-digest duplicate detection** (e.g. SHA-256); **OCR** where needed for searchability; **server-side** **RBAC**; **missing-file** detection and **relink**; **deletion** flow with **admin** choice on **disk**; **accessibility** of shell (**WCAG 2.1 AA** target); **open-source** distribution with **AS-IS** terms (draft).

- **Clearly out-of-scope (initial)**  
  **Standalone web client**; **offline/sync**; **public API** and **scripting**; **MyLib-provided** export/print (readers may still provide); **symbolic links** (v1); **numeric performance SLA**; **Mac App Store** (initially).

- **Areas requiring further validation**  
  **Bulk import** with **review queue**; **game system** (e.g. TTRPG) as **tag vs field**; **updater** and **version-notification** mechanism with **minimal outbound** policy; **exact** reader integration for **search hand-off**; **format phasing** (likely **PDF/DOCX** before **EPUB**); **server autostart** (login vs boot, **service** vs user session, per-OS install hooks and **security**); **dual-installer** packaging details; **duplicate-digest** follow-on actions in UI.

- **Explicit exclusions**  
  **DRM circumvention** features; **enterprise SharePoint** replacement positioning.

---

# 11. Lifecycle Readiness Assessment

Before advancing to **Requirements**, confirm:

| Criterion                              | Status                                                             |
| -------------------------------------- | ------------------------------------------------------------------ |
| Problem is clearly articulated         | Yes                                                                |
| Outcomes are defined                   | Yes (qualitative; metrics deferred)                                |
| Constraints are documented             | Yes                                                                |
| Risks are surfaced and classified      | Yes                                                                |
| Alternative approaches explored        | Yes (two desktop directions)                                       |
| No architectural commitments made      | **Client–server topology** and **server-side auth** accepted; **implementation stack** (e.g. **Electron vs Qt**) **not** chosen |
| No implementation assumptions embedded | Avoided; **specific libraries** not mandated                       |
| RTM scaffold prepared                  | **No** — create when entering **Requirements / traceability** work |

If any condition is unmet, **remain in Ideation**.

**Advancement requires explicit human authorization.**

---

# 12. Gate Declaration

Approved to Proceed to Requirements Phase:

**Name:** Charles McKnight  
**Role:** Project owner / author  
**Date (YYYY-MM-DD):** 2026-04-05  
**Signature (if applicable):** *Recorded in repository (electronic authorization).*  

**Note:** Ideation is closed **for now** on a **best-efforts** basis. Material discoveries later may require **rollback or rework** per [`../LIFECYCLE.md`](../LIFECYCLE.md "Lifecycle") (scope, requirements, or architecture changes).

Version incremented upon approval (**primer 1.0**).

---

# 13. Requirements completion and Architecture authorization

**SRS** [`../srs.md`](../srs.md "Srs") **v0.9** reviewed and **Approved** by the **sole stakeholder**; **NFR** measurement binding deferred to **Test Plan** / design artifacts (**accepted** for Architecture entry **2026-04-06**).

Approved to proceed to **High-Level Architecture** phase:

**Name:** Charles McKnight  
**Role:** Project owner / sole stakeholder  
**Date (YYYY-MM-DD):** 2026-04-06  
**Signature (if applicable):** *Recorded in repository (electronic authorization).*  

**Note:** Draft **`hla.md`**, obtain approval per [`../LIFECYCLE.md`](../LIFECYCLE.md "Lifecycle"), then update **[`../rtm.md`](../rtm.md "Rtm")** with architectural component IDs.

Version incremented to **primer 1.1** upon this gate record.

---

# 14. Architecture completion and Detailed Design authorization

**HLA** [`../hla.md`](../hla.md "Hla") **v0.1.2** reviewed and **Approved** by the **sole stakeholder** on **2026-04-25**. The approved HLA records:

- Client-server authority and trust boundaries.
- Major HLA components and dependency direction.
- Data architecture, deployment topology, failure posture, and NFR mechanisms.
- **HLA-BOUND-OCR** as the deterministic-probabilistic boundary.
- DD-carried decisions for UI stack, solo IPC, notifications, index rebuild mode, search engine model, and OCR engine model.

Approved to proceed to **Detailed Design** phase:

**Name:** Charles McKnight  
**Role:** Project owner / sole stakeholder  
**Date (YYYY-MM-DD):** 2026-04-25  
**Signature (if applicable):** *Recorded in repository (electronic authorization).*  

**DD scaffold:** [`../dd.md`](../dd.md "Dd") **v0.1** created **2026-04-25**. DD is active; component decomposition, interface contracts, data design, failure semantics, NFR derivation, and test intent remain pending. **Implementation remains blocked** until approved DD and RTM readiness per [`../LIFECYCLE.md`](../LIFECYCLE.md "Lifecycle").

**RTM status:** [`../rtm.md`](../rtm.md "Rtm") **v0.1** maps SRS requirements to HLA components. DD, test, packaging, and orchestration columns remain **TBD** until downstream artifacts land.

Version incremented to **primer 1.2** upon this gate record.

---

# 15. Documentation Diagram Decisions (Mermaid and SVG)

Date logged: **2026-04-26**

To keep architecture/design documentation readable and portable across Markdown viewers, the following documentation-rendering decisions are recorded for active Detailed Design work:

- **Authoring and publication split:** Mermaid is the source format; SVG is the published diagram format.
- **Storage convention:** Mermaid sources live in `img-src/`; rendered assets live in `img/`.
- **Layout default:** Use vertical flow orientation (`flowchart TB` with `direction TB`) unless a documented exception is required.
- **Render/readability policy:** Render with white background and include a top-level white panel in Mermaid source so arrows and connectors remain legible in dark-mode viewers.
- **Rendering path:** Regenerate diagram assets via `scripts/render-mermaid.sh`.

References: [`../hla.md`](../hla.md "Hla"), [`../dd.md`](../dd.md "Dd"), [`../README.md`](../README.md "Readme"), [`discussion-log.md`](discussion-log.md "Discussion Log").

Version incremented to **primer 1.3** upon this decision log addition.

---

# Governance Notes

The Project Primer:

- Defines intent  
- Surfaces structural risk  
- Prevents premature architecture  
- Prevents solution-first thinking  
- Anchors lifecycle discipline  
- Uses Markdown link hygiene for portability: same-document links use bare anchors (`#section-anchor`), cross-document links use file+anchor (`./file.md#section-anchor`)  

It SHALL NOT:

- Define system architecture  
- Select technologies  
- Define interfaces  
- Specify data models  
- Authorize implementation  

---

End of Project Primer

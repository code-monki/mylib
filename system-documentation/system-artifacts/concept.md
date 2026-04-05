# MyLib — Electronic Document Management System

Structured Ideation record (template-aligned): [Project Primer](_process/project-primer.md).  
Timestamped discussion and decisions: [Discussion log](_process/discussion-log.md).

**Lifecycle (this cycle):** **Ideation** closed **2026-04-05**—authorization to proceed to **Requirements** recorded in [Project Primer §12 — Gate Declaration](_process/project-primer.md#12-gate-declaration). **SRS (draft):** [srs.md](srs.md). Further discovery may still trigger **phase rollback** per [LIFECYCLE.md](LIFECYCLE.md).

## Overview

MyLib addresses the need to manage a **large corpus** of electronic documents in **heterogeneous formats** (including PDF, word-processing formats such as DOCX, and EPUB). It aims to provide a **unified library**: consistent **cataloging**, **metadata**, **full-text search**, **tag-based filtering**, and **access control**, while **display and printing** are delegated to **native reader applications** where practical so rendering fidelity and reader-specific features (including bookmarks) stay with those tools.

The product is **open source** under the **Apache License 2.0** (see repository root `LICENSE` and `NOTICE`); **final confirmation with counsel** is expected before wide publication. Primary delivery is a **desktop client** for **Windows, macOS, and Linux**. The system is **client–server** in nature: **authentication and authorization are enforced by a server component**. In a **solo / desktop deployment**, that server runs on the **same machine** (e.g. loopback), but remains the **authority** for credentials and RBAC—so remote multi-user deployments do not rely on **UI-only** hiding of admin features. A **web client** is **deferred**; the initial assumption is that **installing a desktop application** is acceptable for the target audience (individuals, families, and small teams—not a substitute for enterprise suites such as SharePoint).

**Personal motivation for the project:** the author maintains on the order of **~10,000** electronic publications from **many sources**, which drives the emphasis on **scale**, **metadata normalization**, and **search quality** across formats.

---

## Problem statement

Electronic documents appear in many formats, some proprietary or layout-heavy. At scale, this causes:

1. **Indexing and search** across the corpus without opening each file in a separate application.
2. **Navigation from search hits** to a meaningful location inside the document—especially difficult for PDF and similarly challenging for other formats. The **ideal** is to **open the document in a native reader** and, where feasible, **invoke the reader’s own search** rather than reimplementing layout engines.
3. **Consistent categorization** across the library.
4. **Appropriate display** per document type—addressed primarily by **native readers**, not by MyLib re-rendering everything.
5. **Complex layouts** (background graphics, **tables**, etc.) that complicate **text extraction**, **OCR pipelines**, and **search accuracy**. **Scanned or “cursed” PDFs** may require **OCR** to build a searchable text map; **bulk import** does not remove the need for **manual correction** when extraction or OCR is wrong.

---

## Stakeholders and positioning

**Primary stakeholders**

- Individual researchers  
- Archivists  
- Small to medium teams  

**Non-goals (initial positioning)**

- Large enterprises with budgets for **SharePoint-class** platforms are **not** the primary design center.

**Differentiation**

- MyLib is an **alternative unified library management system** for heterogeneous personal and small-team corpora: one place to **organize**, **find**, and **govern access** to documents that otherwise sprawl across folders and tools.

---

## Non-negotiable outcomes

1. **Accurate search and navigation** (within the limits of extracted text, OCR quality, and format—**tables and bad PDFs** remain known risk areas).
2. **Intellectual property and access protection** through **user/admin-controlled mechanisms** (see below)—not absolute prevention of determined misuse (e.g. screenshots), but **sensible enforcement** of policy.

---

## Access, display, export, and printing

- **Full text** of documents should be **available to the system** for indexing and search, even when **display** uses a **native reader**.
- **Native readers** are preferred for **display** to avoid reimplementing complex rendering; integration may involve **opening files with the OS default application**, **extensions**, or other platform-specific bridges. **Uniformity** is expected at the **library and search** layer, not necessarily identical rendering stacks on every surface.
- MyLib **does not** aim to provide its own **download/export** or **print** features; if the **reader** offers save, export, or print, that is **outside MyLib’s scope**. This **does not** imply that **bytes never reach the client** when using remote access—**opening** a document may still imply **local handling** by the OS or reader. **Policy** should be described honestly in future requirements and operator documentation.

---

## Users, roles, and intellectual property controls

- The system is **multi-user**; **single-user** use is a **degenerate case** of the same **authentication and RBAC** model.
- **Authentication** is **always** validated by the **server** (in solo mode, that server is **co-located** on the desktop). **Sensitive operations** for **remote** use must be **server-authoritative**, not **security-by-UI** on the client alone.
- **Roles and permissions** should model **who can access** a document and **whether** they may **modify**, **save**, or **obtain a copy**—as enforced by the application. **Separation of admin and day-to-day user** personas is recommended even on single-user installations.
- **Tenant boundary** (who belongs to which organization or family of users) is an **administrator responsibility**; the **application enforces** the configured policy.
- **v1 authentication** expectation: **local accounts** (directory/SSO and similar deferred unless reprioritized).

---

## Corpus storage and scale

- **Corpus location** is **user/admin-specified**: documents may live on **one machine** (single-user) or on **remote storage** served to **multiple clients** (multi-user).
- **Scale:** libraries may reach **tens to hundreds of thousands** of documents (and beyond). **Order-of-magnitude** scale affects indexing and UX expectations; a **numeric performance SLA** is **deferred** given hardware diversity.
- **Offline use and sync** are **deferred**; operational burden for backup and availability is initially on the **administrator**.
- **Backup (ideal):** a **full** restore picture includes **document corpus**, **server database**, **search/index state**, **configuration**, and **logs**—recognizing that **storage** limits what operators can retain in practice. **Operator documentation** should describe **minimal** vs **complete** backup scope.
- **Logs:** support **rotation / retention** on an **administrator-configured** schedule (exact mechanism **TBD** in Requirements/HLA).
- **Server always available (optional):** support **user/admin-configurable** behavior so the **server** can **start automatically** at **OS login** or **system startup** (e.g. “run in background” without opening the full client UI), keeping the library **reachable** for local or remote clients. **Platform-specific** mechanisms (user launch agent vs system service, **Windows** / **macOS** / **Linux**) and **security** implications (which account runs the server) are **TBD in Requirements / HLA**.

---

## Document identity, files on disk, and deletion

- Each **logical edition** is treated as a **distinct document** (no merged version chain in early thinking).
- **Duplicate detection:** **SHA-256** (or equivalent) of file bytes; on **matching digest**, **warn** the user and require an **explicit choice** (e.g. cancel import, import as separate record, or other actions **TBD** in Requirements)—**no silent** merge or skip by default.
- If a **file is missing** (moved, renamed, deleted outside the app), the system should **not** silently relearn from disk; it should **notify the user** and offer a **file dialog to relink** the library entry to a replacement path.
- **Symbolic links** are **unlikely to be supported** initially to avoid ambiguous identity and path semantics.
- **Deletion:** removing a document from the **application** should be distinct from **deleting the underlying file**; the **administrator** should be **prompted** for whether to remove content from **persistent storage**.

---

## Ingestion

- **Initial path:** **Import** via **menu + file dialog** (deliberate, user-present).
- **Bulk import** is **likely** to be added later given **high-volume** use, but **bulk does not eliminate** **OCR/extraction correction** work for problematic files. **Assisted bulk** with an **exception or review queue** is a plausible direction for later design discussion.

---

## Metadata, tags, and organization

- Prefer **Dublin Core–inspired** fields where appropriate, plus practical bibliographic fields such as **author**, **publisher**, and **series**.
- **Tags** (multi-valued) support **grouping** and **search filters**; **v1** favors **free-form** tags. **Tighter governance** (controlled vocabularies) can follow if needed (e.g. archival workflows).
- **DRM-protected EPUB** (and similar): **no index built without lawful access to content**. Where full-text indexing is **not** possible, allow the user to associate a **keyword list** with the document **separate from tags**—**keywords** aid **discovery** without conflating curated tags with ad hoc search terms for locked content.
- For domains such as **tabletop role-playing games**, whether **game system** is a **tag**, a **dedicated field**, or both is **open** until requirements harden.

**Bookmarks:** **in-document** bookmarks are expected to remain **owned by the reader application**, not MyLib.

---

## Platform, accessibility, and internationalization

- **Desktop:** **Windows, macOS, Linux.**
- **Shell UI accessibility** is a **hard requirement**, with **WCAG 2.1 Level AA** as the **target** where achievable for the shell (final verification in test planning).
- **English** for initial UI and documentation; **i18n** deferred.

---

## Explicitly deferred

- **Web client** (standalone browser SPA).
- **Offline / sync** strategy.
- **Public API** and **scripting** interfaces.
- **Numeric performance guarantees** across diverse hardware.
- **Outbound network policy** details: default **minimize** calls; **notifying the user of a new version** is **desired**—exact mechanism (opt-in, endpoints, privacy) **TBD in Requirements / HLA**.

---

## Distribution, signing, and updates

- **Maintainer support:** primary channel **GitHub** (issues/discussions); **no** maintainer-operated SaaS hosting anticipated—**others** may self-host or fork.
- **Distribution:** e.g. **GitHub Pages** (or similar) for **project presence** and links; **installers and binaries** typically attached to **GitHub Releases** rather than stored as large blobs in the git tree.
- **Installers (intent):** expect **two** distribution lines—**(1) solo / single-user** (bundled **client + co-located server**, friendly defaults) and **(2) server / self-hosted multi-user** (server-oriented install plus **client** builds or same client pointed at remote host). Exact packaging **TBD** in HLA/release engineering.
- **macOS:** **Apple Developer Program** for **signing and notarization**; **not** initially targeting **Mac App Store** distribution.
- **Windows / Linux (and other non-Apple) signing:** **SignPath** is the **intended** service for **official release binaries** published by the project (**Authenticode** / platform-appropriate signing **as applicable**), integrated with **CI** (e.g. GitHub Actions) where possible. **Apple** pipelines remain **separate** (SignPath does **not** replace **notarization**). **Building from source** may produce **unsigned** artifacts—that is normal for OSS; **signed** installers are a **release hygiene** choice for distributed downloads, not a license requirement.
- **Automatic updates** (“Check for updates”): e.g. **Sparkle** on native macOS stacks, or **stack-native** updaters (e.g. Electron ecosystem); **not yet decided**.

---

## Legal, privacy, and operator responsibility (concept-level)

- **Apache License 2.0** applies to this project (see `LICENSE`); **maintain** `NOTICE` and dependency attributions as the stack grows. **Counsel review** (IP lawyer) is **pending** for final sign-off before broad publication—especially if **EU or enterprise** adoption appears.
- The product should **not** center features whose **primary purpose** is **circumventing DRM** on copyrighted works; **relying on native readers** for display reduces that surface.
- **Personal data** is expected to be **minimal** (e.g. **account identifiers**; **passwords** stored only as **strong one-way hashes**, never in clear text). **Audit logs** (e.g. user + timestamp + document access) may still be **personal data** under privacy regimes and should be **purpose-limited**, **minimized**, and **retained** according to operator policy. **Encryption** and **self-hosted** deployment help **security** but are **not** a substitute for **clear documentation** of what is processed and **operator obligations**.
- **Users and operators** are responsible for **lawful use** and **compliance with applicable regulations** in their jurisdiction.

---

## Open decisions (carry into requirements phase)

- **License:** **Apache-2.0** **chosen** (root `LICENSE` + `NOTICE`); **counsel sign-off** pending.
- **Bulk import** UX and **review queue** shape.
- **Game system** (and similar) as **tag vs structured field**.
- **Desktop technology** direction (e.g. **Electron vs Qt** or other)—**not** decided in this document.
- **Updater** mechanism per platform and **version-notification** flow (**minimal outbound** vs **update checks**—final in **Requirements / HLA**).
- **Server autostart:** login vs boot, **service** vs **user session**, and per-OS packaging (**Requirements / HLA**).
- **Format phasing:** likely **PDF and DOCX** before **EPUB** complexity; **DRM EPUB** uses **keywords** path when indexing blocked.
- **Release signing:** **SignPath** (or equivalent) **CI** integration for **non-Apple** official binaries—**mechanics TBD** (does not affect **source-only** users).

---

## Proposed solution (summary)

Address the problems above using **disciplined system engineering**: a **cross-platform desktop client** to a **library server** (co-located for solo use, remote for teams) with **server-side authentication**, **RBAC**, **full-text search** (including **OCR** where needed), **optional user keywords** where DRM blocks indexing, **digest-based duplicate detection**, **tagging** and **rich metadata**, **honest handling** of **missing files** and **deletion**, **WCAG 2.1 AA–targeted** accessibility in the shell, and **clear** separation between **library services** and **native reading/printing**. **Web**, **sync**, **APIs**, and **performance SLAs** are intentionally **out of initial scope** unless reprioritized.

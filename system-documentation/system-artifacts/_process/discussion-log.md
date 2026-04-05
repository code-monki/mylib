# Discussion and decision log (MyLib)

Timestamped summaries of **discussions**, **decisions**, and **technology choices** (or explicit **deferrals**).  
**Newest entries first.** Append new blocks after updating the “Last updated” line below.

**Last updated:** 2026-04-08 (SRS v0.7 password, search, sessions) UTC  

**Not legal advice** where legal topics appear; see [`open-source-license.md`](open-source-license.md).

---

## 2026-04-08 — SRS v0.7: password policy, v1 boolean/phrase search, session vs capacity

**Summary:** **FR-033** **—** **v1** **password** **rules:** **minimum** **8** **characters;** **uppercase,** **lowercase,** **digit,** **and** **one** **symbol** **from** **a** **DD-enumerated** **set** **(temporary** **passwords** **meet** **rules** **or** **force** **change).** **FR-038** **—** **v1** **search** **requires** **`AND`/`OR`/`NOT`,** **double-quoted** **phrases,** **parentheses** **for** **grouping;** **DD** **carries** **normative** **grammar** **and** **precedence.** **FR-035** **+** **NFR-001** **—** **clarified** **per-user** **concurrent** **sessions** **(product** **policy** **in** **DD)** **vs.** **aggregate** **deployment** **capacity** **(hardware,** **network,** **multi-instance** **routing** **per** **HLA;** **stress** **scenarios** **optional** **in** **Test** **Plan).** **FR-027** **note** **cross-ref** **FR-033.** **NFR-004** **admin** **guide** **covers** **password** **policy.** **Risk** **row** **for** **search** **parsing.** **Version** **0.7,** **Last** **revised** **2026-04-08** **UTC.**

**Documentation:** [`../srs.md`](../srs.md).

---

## 2026-04-07 — SRS v0.6: sequential FR-001–041, governance + security + catalog gaps

**Summary:** **Renumbered** **functional** **requirements** **to** **FR-001–FR-030** **strict** **order** **(keywords** **FR-009,** **release** **FR-030).** **Added** **FR-031–FR-041:** **account**/**role** **admin,** **bootstrap,** **password** **change**/**admin** **reset,** **auth** **throttling,** **sessions,** **corpus** **storage** **model,** **catalog** **browse**/**pagination,** **search** **semantics** **(AND** **default),** **index** **rebuild,** **metadata** **validation,** **optimistic** **concurrency.** **Expanded** **FR-026** **audit** **(enable**/**disable,** **denied** **access** **default).** **NFR-001** **design-center** **100k;** **NFR-009** **TLS** **defaults.** **Header:** **Last** **revised** **2026-04-07** **UTC;** **§15–§16** **refresh.** **§8** **time** **sync** **assumption.**

**Open** **product** **choices** **embedded** **(revisit** **if** **needed):** **v1** **search** **default** **=** **AND** **of** **terms,** **case-insensitive** **Latin;** **concurrent** **sessions** **=** **policy** **choice** **in** **DD** **(cap** **vs** **unlimited);** **self-service** **email** **password** **recovery** **=** **deferred** **(§13).** **(Superseded** **for** **search**/**sessions**/**password** **by** **2026-04-08** **v0.7** **entry** **above.)**

**Documentation:** [`../srs.md`](../srs.md).

---

## 2026-04-06 — SRS v0.5: operational/diagnostic logs, Settings, compliance

**Summary:** **FR-030** — **client** **and** **server** **operational** **and** **diagnostic** **logs**, **independent** **enable**/**disable** **per** **category**, **Settings** **(FR-027)** **/** **server** **admin** **UI**, **platform-default** **paths**, **day-based** **rollover** **+** **FR-024** **maximum** **retention**. **NFR-008** **privacy**/**jurisdictional** **readiness**. **Definitions**, **NFR-004**/**007**, **§9–§12**, **FR-020**, **risks** **updated**.

**Documentation:** [`../srs.md`](../srs.md).

---

## 2026-04-06 — SRS v0.4: warm sepia / parchment default theme

**Summary:** **FR-029** now **requires** a **shipped** **warm sepia** theme (**parchment-style** **background** allowed). **NFR-006** **contrast** **applies** to **all** **shipped** themes **including** sepia—**no** **WCAG** **waivers** for **decorative** **backgrounds**.

**Documentation:** [`../srs.md`](../srs.md).

---

## 2026-04-06 — SRS v0.3: NFR-007 end-user docs and Help

**Summary:** Added **NFR-007** (user manual, quick-start, **Help** affordance to version-matched docs; packaging **TBD** HLA). **Searchable** help index and **context-sensitive** help in **waiting room**; **pre-built** help components allowed if license/a11y OK. **NFR-004** clarified vs end-user docs; **§2.2**, **FR-020**, **§14** updated.

**Documentation:** [`../srs.md`](../srs.md); [`../../user-documentation/README.md`](../../user-documentation/README.md).

---

## 2026-04-06 (later) — SRS v0.2: Settings, reader preferences, theme

**Summary:** Extended [`../srs.md`](../srs.md) with **FR-027** (Settings facility, extensible), **FR-028** (preferred external reader per supported document type with platform-default fallback), **FR-029** (light/dark theme, **match system** where feasible). **NFR-006** ties shipped themes to **WCAG 2.1 AA** contrast for the shell. **FR-018** updated to honor reader preferences. **Waiting room:** third-party theme packs, preference sync across devices.

**Decisions**

- **None** beyond adopting draft requirement text pending review.

**Documentation:** [`../srs.md`](../srs.md).

---

## 2026-04-06 — SRS initial draft (`srs.md` v0.1)

**Summary:** Added **[`../srs.md`](../srs.md)** as **draft** SRS (**FR-001–FR-026**, **NFR-001–NFR-005**), derived from **`concept.md`** and **`project-primer.md`**. **Phase gate** in SRS **§16** records **not** ready for Architecture until **review**, **RTM**, and **human approval**. **PDF/DOCX** mandatory for v1; **EPUB** and several items remain **waiting room**.

**Decisions**

- **None finalized** — document is **draft** for review.

**Documentation:** [`../srs.md`](../srs.md); [`../README.md`](../README.md) (artifact index).

---

## 2026-04-05 22:30 UTC — Documentation layout: `system-documentation/`

**Summary:** Reorganized documentation under **`system-documentation/`** with **`system-artifacts/`** (concept, lifecycle, future SRS/HLA/DD/tests/RTM) and **`user-documentation/`** (guides). Removed **`AI-Bootstrap/`** toolkit copy from this product repo. **`docs/`** reserved for optional **GitHub Pages** site later.

**Decisions**

- **Cursor rules** now reference **`system-documentation/system-artifacts/LIFECYCLE.md`** and artifacts under **`system-documentation/system-artifacts/`** (no `AI-Bootstrap/` paths).

**Documentation:** `system-documentation/README.md`; migrated `concept.md`, `_process/*`; new stubs in `user-documentation/`.

---

## 2026-04-05 21:45 UTC — Ideation gate: authorized to Requirements

**Summary:** Project owner **closed Ideation for this cycle** and **authorized** advancement to the **Requirements** phase, with explicit acceptance that **unknowns remain** and **rollback** remains possible per [`../LIFECYCLE.md`](../LIFECYCLE.md).

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

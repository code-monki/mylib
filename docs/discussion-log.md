# Discussion and decision log (MyLib)

Timestamped summaries of **discussions**, **decisions**, and **technology choices** (or explicit **deferrals**).  
**Newest entries first.** Append new blocks after updating the “Last updated” line below.

**Last updated:** 2026-04-05 21:15 UTC  

**Not legal advice** where legal topics appear; see `docs/open-source-license.md`.

---

## 2026-04-05 21:15 UTC — Apache-2.0, duplicate policy, backup/logs, dual installers

**Summary:** Locked **Apache License 2.0** (pending **IP counsel** final sign-off); clarified **SHA-256 duplicate** handling, **backup/logging** intent, and **two installer** lines.

**Decisions / artifacts**

- **License:** **Apache-2.0** chosen; added repository root **`LICENSE`** (verbatim text) and **`NOTICE`** (copyright + placeholder for dependency notices). **`docs/open-source-license.md`** updated to **recorded decision**; **counsel review** still **pending**.
- **Duplicates:** same **content digest** → **warn** user; **explicit user choice** on how to proceed (**no** silent merge/skip by default).
- **Backup / logs:** **ideal** backup scope = **corpus + DB + index + config + logs**; **practical** scope **operator-dependent**; **log rotation/retention** = **admin-configurable** (mechanism **TBD** Requirements/HLA).
- **Installers:** expect **solo** (client + co-located server) vs **server/self-hosted multi-user** packaging (**HLA**/release detail).

**Documentation**

- `docs/concept.md`, `docs/project-primer.md` (v**0.4**), `docs/open-source-license.md`, `docs/discussion-log.md`; **`LICENSE`**, **`NOTICE`**.

---

## 2026-04-05 21:05 UTC — Optional server autostart / always-on

**Summary:** Capture need for **user-configurable** startup so the **library server** can run **continuously** (login or boot) without requiring the **desktop client UI** first.

**Decisions / artifacts**

- **Likely in-scope:** optional **start server at OS user login** or **system startup** (exact options **TBD**), so solo or small-team deployments can keep the server **reachable** for local/remote clients.
- **Deferred to Requirements / HLA:** per-OS mechanisms (e.g. **LaunchAgent**, **systemd**, **Windows** service vs user startup), **which account** runs the server, and **security** implications.

**Documentation**

- `docs/concept.md` (corpus/ops); `docs/project-primer.md` (v0.3).

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

- Updated `docs/concept.md`, `docs/project-primer.md` (version **0.2**).

---

## 2026-04-05 19:46 UTC — Discussion log format

**Summary:** Established this file as the running log for conversation outcomes.

**Decisions / artifacts**

- Maintain project narrative in `docs/concept.md` and structured Ideation in `docs/project-primer.md`; use **this file** for **time-ordered** deltas from working sessions.
- License selection notes live in `docs/open-source-license.md` (working preference: **Apache-2.0**, **MIT** fallback); root `LICENSE` still **TBD**.

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

**Reference:** `docs/open-source-license.md` (committed as initial repo commit `fa69086`).

---

## 2026-04-03 (session) — Ideation artifacts and product boundaries

**Summary:** Folded extended Ideation into `docs/concept.md` and created `docs/project-primer.md` (template-aligned). Aligned AI-Bootstrap paths and Cursor rules earlier in the same initiative.

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
- **Gate to Requirements:** explicit human approval only (`docs/project-primer.md` §12).

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

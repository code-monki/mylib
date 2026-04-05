# Discussion and decision log (MyLib)

Timestamped summaries of **discussions**, **decisions**, and **technology choices** (or explicit **deferrals**).  
**Newest entries first.** Append new blocks after updating the “Last updated” line below.

**Last updated:** 2026-04-05 19:46 UTC  

**Not legal advice** where legal topics appear; see `docs/open-source-license.md`.

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

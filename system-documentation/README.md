# MyLib documentation

This directory holds **product and process documentation** for the MyLib repository.

## Layout

| Path | Purpose |
|------|---------|
| **`system-artifacts/`** | Engineering record: concept, future SRS, HLA, DD, test plan, test suite, RTM, packaging plan, and lifecycle summary. |
| **`system-artifacts/_process/`** | Project primer, decision/discussion log, license notes (supporting artifacts). |
| **`system-artifacts/_templates/`** | Scaffolds aligned with `04-templates/` (system + project + ChatGPT instructions); copy into `system-artifacts/` or use as entry patterns under `_process/`. |
| **`user-documentation/`** | End-user and operator guides (installation, usage, administration). |

## Markdown link convention

Use inline links with a **quoted title** (hover text and consistent tooling), in the form **`[text](url "Title")`**.

For in-document section links, use explicit file+anchor form (not bare `#fragment`) to avoid editor-resolution issues:

- Preferred: **`[§2.2](./README.md#22-scope "2.2 Scope")`**
- Avoid: **`[§2.2](#22-scope "2.2 Scope")`**

Examples: same-document `[§2.2](./README.md#22-scope "2.2 Scope")`, cross-file [`concept.md`](system-artifacts/concept.md "Concept"), requirement `[FR-004](./README.md#fr-004--deliberate-import "FR-004 Deliberate Import")`.

To add missing titles only on targets that contain **no** `"` yet (safe when titles include parentheses), run:

`python3 system-documentation/_tools/add_link_titles.py`

## Reading order (for contributors)

1. [`system-artifacts/LIFECYCLE.md`](system-artifacts/LIFECYCLE.md "Lifecycle") — phase sequence and rollback expectations  
2. [`system-artifacts/concept.md`](system-artifacts/concept.md "Concept") — product concept  
3. [`system-artifacts/_process/project-primer.md`](system-artifacts/_process/project-primer.md "Project Primer") — Ideation record and gate history  

GitHub Pages (if enabled) may use a separate minimal `docs/` folder at the repository root for the public site; substantive content lives here under **`system-documentation/`**.

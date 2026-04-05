# MyLib documentation

This directory holds **product and process documentation** for the MyLib repository.

## Layout

| Path | Purpose |
|------|---------|
| **`system-artifacts/`** | Engineering record: concept, future SRS, HLA, DD, test plan, test suite, RTM, and lifecycle summary. |
| **`system-artifacts/_process/`** | Project primer, decision/discussion log, license notes (supporting artifacts). |
| **`system-artifacts/_templates/`** | Scaffolds for SRS, HLA, DD, test plan, RTM — copy into `system-artifacts/` when a phase authorizes each artifact. |
| **`user-documentation/`** | End-user and operator guides (installation, usage, administration). |

## Reading order (for contributors)

1. [`system-artifacts/LIFECYCLE.md`](system-artifacts/LIFECYCLE.md) — phase sequence and rollback expectations  
2. [`system-artifacts/concept.md`](system-artifacts/concept.md) — product concept  
3. [`system-artifacts/_process/project-primer.md`](system-artifacts/_process/project-primer.md) — Ideation record and gate history  

GitHub Pages (if enabled) may use a separate minimal `docs/` folder at the repository root for the public site; substantive content lives here under **`system-documentation/`**.

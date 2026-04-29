# System artifacts

Engineering record for how MyLib is specified, designed, tested, and traced.

| Artifact | File | Status |
|----------|------|--------|
| Lifecycle & gates | [LIFECYCLE.md](LIFECYCLE.md "Lifecycle") | Active |
| Concept | [concept.md](concept.md "Concept") | Active |
| SRS | [srs.md](srs.md "Srs") | Approved v0.9 (2026-04-06) |
| HLA | [hla.md](hla.md "Hla") | Approved v0.1.2 (2026-04-25) |
| Shell UI/UX (HLA-SHELL) | [shell-ui-ux-design.md](shell-ui-ux-design.md "Shell UI/UX Design") | Draft — IA + flows baselined 2026-04-28; structural wireframes added (S-01/S-03/S-05/S-06) |
| DD | [dd.md](dd.md "Dd") | Approved v0.1 (2026-04-28); §4.1–§4.12 + §5 contracts |
| Test plan | [test-plan.md](test-plan.md "Test Plan") | Approved v0.1 (2026-04-28) |
| Test suite | `tests/` or linked suite | Execution/evidence TBD (lifecycle) |
| RTM | [rtm.md](rtm.md "Rtm") | Approved v0.1 (2026-04-28); §3.1 + §2.1 §5 pointer |
| Packaging & deployment | `packaging-plan.md` (planned) | TBD |

**Process / meta:** [`_process/`](_process/ " Process") (primer, decision/discussion log, license notes).  
**Scaffolds:** [`_templates/`](_templates/ " Templates") — copy templates to this folder when creating `srs.md`, `hla.md`, etc.

## Diagram workflow

- Author Mermaid source files in [`img-src/`](img-src/ "Mermaid Sources").
- Render SVG outputs to [`img/`](img/ "Diagram Assets") for Markdown viewer compatibility.
- Regenerate all diagram assets with [`scripts/render-mermaid.sh`](scripts/render-mermaid.sh "Render Mermaid Diagrams").
- Protect hand-authored SVGs from regeneration by listing base names in [`img-src/manual-svg-skip.txt`](img-src/manual-svg-skip.txt).
- Use vertical orientation (`flowchart TB` with `direction TB`) by default.

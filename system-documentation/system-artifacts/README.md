# System artifacts

Engineering record for how MyLib is specified, designed, tested, and traced.

| Artifact | File | Status |
|----------|------|--------|
| Lifecycle & gates | [LIFECYCLE.md](LIFECYCLE.md "Lifecycle") | Active |
| Concept | [concept.md](concept.md "Concept") | Active |
| SRS | [srs.md](srs.md "Srs") | Approved v0.9 (2026-04-06) |
| HLA | [hla.md](hla.md "Hla") | Approved v0.1.2 (2026-04-25) |
| DD | [dd.md](dd.md "Dd") | Draft v0.1 (initial §4.1–§4.12 decomposition present; refinement in progress) |
| Test plan | `test-plan.md` (planned) | TBD |
| Test suite | `tests/` or linked suite (planned) | TBD |
| RTM | [rtm.md](rtm.md "Rtm") | Draft v0.1 (HLA mapped; DD section mappings populated; tests/package/orchestration TBD) |
| Packaging & deployment | `packaging-plan.md` (planned) | TBD |

**Process / meta:** [`_process/`](_process/ " Process") (primer, decision/discussion log, license notes).  
**Scaffolds:** [`_templates/`](_templates/ " Templates") — copy templates to this folder when creating `srs.md`, `hla.md`, etc.

## Diagram workflow

- Author Mermaid source files in [`img-src/`](img-src/ "Mermaid Sources").
- Render SVG outputs to [`img/`](img/ "Diagram Assets") for Markdown viewer compatibility.
- Regenerate all diagram assets with [`scripts/render-mermaid.sh`](scripts/render-mermaid.sh "Render Mermaid Diagrams").
- Use vertical orientation (`flowchart TB` with `direction TB`) by default.

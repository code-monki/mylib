# System artifact templates

Use these files to **scaffold** formal artifacts next to [`../LIFECYCLE.md`](../LIFECYCLE.md). They are **not** the live record until copied and filled in.

## How to use

1. When a phase gate authorizes the artifact, **copy** the template into `system-documentation/system-artifacts/` (repo root of artifacts, same folder as `concept.md` and `LIFECYCLE.md`).
2. **Rename** if your naming differs (e.g. keep `srs.md` as the canonical SRS filename per [`../README.md`](../README.md)).
3. Replace `TODO` / placeholder sections; append decisions to [`../_process/discussion-log.md`](../_process/discussion-log.md) when material.

| Template | Suggested target | Phase (see LIFECYCLE) |
|----------|------------------|------------------------|
| [`srs.md`](srs.md) | `../srs.md` | Requirements |
| [`hla.md`](hla.md) | `../hla.md` | High-Level Architecture |
| [`dd.md`](dd.md) | `../dd.md` | Detailed Design |
| [`test-plan.md`](test-plan.md) | `../test-plan.md` | Test planning |
| [`rtm.md`](rtm.md) | `../rtm.md` | Traceability consolidation |

Do not edit templates in place as the “source of truth”; copy first so the `_templates/` folder stays a reusable scaffold.

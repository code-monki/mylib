# System artifact templates

These files are aligned with the **`04-templates/`** pack (system + project scaffolds). They are **not** the live engineering record until **copied** into the parent folder and completed.

**Lifecycle authority** (referenced in each template header): [`../LIFECYCLE.md`](../LIFECYCLE.md).

## How to use

1. When a phase gate authorizes an artifact, **copy** the matching file from here into [`system-documentation/system-artifacts/`](../) (same level as `concept.md` and `LIFECYCLE.md`), unless noted otherwise below.
2. Keep **`_templates/`** unchanged so scaffolds stay reusable; edit only the promoted copy.
3. For significant decisions, use [`project/decision-log.md`](project/decision-log.md) as an entry pattern and/or [`../_process/discussion-log.md`](../_process/discussion-log.md) per project practice.

## System templates (promote to `system-artifacts/`)

| Template | Suggested filename when promoted | Phase (see LIFECYCLE) |
|----------|----------------------------------|------------------------|
| [srs.md](srs.md) | `srs.md` | Requirements |
| [hla.md](hla.md) | `hla.md` | High-Level Architecture |
| [dd.md](dd.md) | `dd.md` | Detailed Design |
| [test-plan.md](test-plan.md) | `test-plan.md` | Test planning |
| [rtm.md](rtm.md) | `rtm.md` | Traceability consolidation |
| [packaging-plan.md](packaging-plan.md) | `packaging-plan.md` | Packaging & orchestration |

## Project / process templates

| Template | Typical use |
|----------|-------------|
| [project/project-primer.md](project/project-primer.md) | New primer from scratch (this repo already has [`../_process/project-primer.md`](../_process/project-primer.md)). |
| [project/decision-log.md](project/decision-log.md) | Structured decision entries (DL-XXX); complements the narrative discussion log. |
| [project/daily-log.md](project/daily-log.md) | Daily governance log when that discipline is in use. |

## Assistant configuration (do not promote)

| File | Purpose |
|------|---------|
| [assistant-chatgpt-instructions.md](assistant-chatgpt-instructions.md) | Paste into ChatGPT custom instructions; paths point at this repository layout (not `02-governance/` / `04-templates/`). |

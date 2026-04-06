# System artifact templates

These files are aligned with the **`04-templates/`** pack (system + project scaffolds). They are **not** the live engineering record until **copied** into the parent folder and completed.

**Lifecycle authority** (referenced in each template header): [`../LIFECYCLE.md`](../LIFECYCLE.md "Lifecycle").

## How to use

1. When a phase gate authorizes an artifact, **copy** the matching file from here into [`system-documentation/system-artifacts/`](../ "..") (same level as `concept.md` and `LIFECYCLE.md`), unless noted otherwise below.
2. Keep **`_templates/`** unchanged so scaffolds stay reusable; edit only the promoted copy.
3. For significant decisions, use [`project/decision-log.md`](project/decision-log.md "Decision Log") as an entry pattern and/or [`../_process/discussion-log.md`](../_process/discussion-log.md "Discussion Log") per project practice.

## System templates (promote to `system-artifacts/`)

**MyLib already has a draft SRS:** [`../srs.md`](../srs.md "Srs"). Use the row below only for **new** work or a **blank** scaffold.

| Template | Suggested filename when promoted | Phase (see LIFECYCLE) |
|----------|----------------------------------|------------------------|
| [srs.md](srs.md "Srs") (blank scaffold) | `srs.md` | Requirements |
| [hla.md](hla.md "Hla") | `hla.md` | High-Level Architecture |
| [dd.md](dd.md "Dd") | `dd.md` | Detailed Design |
| [test-plan.md](test-plan.md "Test Plan") | `test-plan.md` | Test planning |
| [rtm.md](rtm.md "Rtm") | `rtm.md` | Traceability consolidation |
| [packaging-plan.md](packaging-plan.md "Packaging Plan") | `packaging-plan.md` | Packaging & orchestration |

## Project / process templates

| Template | Typical use |
|----------|-------------|
| [project/project-primer.md](project/project-primer.md "Project Primer") | New primer from scratch (this repo already has [`../_process/project-primer.md`](../_process/project-primer.md "Project Primer")). |
| [project/decision-log.md](project/decision-log.md "Decision Log") | Structured decision entries (DL-XXX); complements the narrative discussion log. |
| [project/daily-log.md](project/daily-log.md "Daily Log") | Daily governance log when that discipline is in use. |

## Assistant configuration (do not promote)

| File | Purpose |
|------|---------|
| [assistant-chatgpt-instructions.md](assistant-chatgpt-instructions.md "Assistant Chatgpt Instructions") | Paste into ChatGPT custom instructions; paths point at this repository layout (not `02-governance/` / `04-templates/`). |

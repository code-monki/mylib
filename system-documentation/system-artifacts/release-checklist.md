# Release Checklist (v0.2.0-rc1 candidate)

## Scope
This checklist tracks release readiness after implementation milestones M1-M7 completion.

## Readiness checklist
- [x] `make verify` passes on current `master`.
- [x] Build-integrated test suite passes (`ctest` 16/16).
- [x] Cyclomatic complexity gate passes (no threshold violations).
- [x] Performance harness baseline executed (`performance_scale_harness_test`).
- [x] Rollback drill executed (`run_rollback_drill`) with evidence captured.
- [x] Required packaging artifacts present (`LICENSE`, `NOTICE`, `OPERATIONS-ROLLBACK-RUNBOOK.md`).
- [ ] Release tag created (`v0.2.0-rc1`).
- [ ] Release bundle checksums published with release artifacts.
- [ ] Manual acceptance pass recorded for shell flows (`login`, `library`, `search`, `import`, `rebuild`).

## Deferred items
- Diagram cleanup/re-export from Omnigraffle is intentionally deferred and tracked as non-blocking final cleanup.

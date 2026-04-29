# Operations Rollback Runbook

## Purpose
Provide a repeatable rollback and restore checklist for MyLib release operations.

## Preconditions
- Current release artifact set is available (`LICENSE`, `NOTICE`, release bundle).
- Last known-good release bundle is retained.
- Access to deployment environment and operational logs is confirmed.

## Rollback Procedure
1. Declare rollback event and freeze new deployments.
2. Capture current diagnostics (service status, logs, active version/build id).
3. Restore last known-good release bundle.
4. Restart service components in dependency order.
5. Verify smoke checks (`login`, `library`, `search`, `import`, `rebuild`).
6. Confirm operational telemetry and audit events are healthy.
7. Close rollback event with incident notes and next actions.

## Post-Rollback Validation
- Confirm expected version/build id is active.
- Confirm no required packaging artifacts are missing.
- Archive rollback evidence with timestamps for release records.

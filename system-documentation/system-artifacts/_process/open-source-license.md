# Open source license selection (MyLib)

**This document is not legal advice.** It records engineering-oriented notes.

## Recorded decision (current)

**Chosen project license:** **GNU General Public License v3.0** or any later version (**GPL-3.0-or-later**).

- Root **`LICENSE`**: verbatim GPLv3 text.
- Root **`NOTICE`**: project copyright + pointer to `licenses/` for third-party notices.
- Rationale: reduce native-dependency license friction (notably around PDF/print extraction stacks) by aligning the product license with a common copyleft option when GPL-family components are central to shipped binaries. See `licenses/README.md` for the living notice policy.

## Context

MyLib is intended as an **open-source** project: a tool for cataloging and indexing **electronic publications the user owns**, without rewriting PDFs for redistribution, without DRM circumvention, and with indexing as a **lookup aid** rather than a substitute for the readable document. See [`../concept.md`](../concept.md "Concept") for product intent.

## Alternatives considered (and why not selected now)

- **Apache-2.0 / MIT (permissive):** great adoption characteristics, but higher ongoing compatibility work when the implementation intentionally bundles **GPL-family** third-party runtimes in the main distributable.
- **AGPL-3.0:** stronger network-distribution obligations than desired for a desktop-first v1; revisit only if product shape changes materially.

## Engineering obligations (independent of license family)

- Maintain a **dependency license audit** that tracks what ships in each platform artifact.
- Keep **reproducible builds** in CI; release artifacts should include license texts where required and a discoverable `licenses/` directory.

## History

- Earlier notes preferred Apache-2.0 before the native dependency plan hardened; the project relicensed to **GPL-3.0-or-later** while no public application code was released, to keep repository truth aligned with the intended stack.

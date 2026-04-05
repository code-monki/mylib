# Open source license selection (MyLib)

**This document is not legal advice.** It records engineering-oriented notes. **Apache License 2.0** is **selected** for MyLib (see repository root `LICENSE` and `NOTICE`); **counsel sign-off** is **pending** before treating publication as final.

---

## Context

MyLib is intended as an **open-source** project: a tool for cataloging and indexing **electronic publications the user owns**, without rewriting PDFs for redistribution, without DRM circumvention, and with indexing as a **lookup aid** rather than a substitute for the readable document. See [`../concept.md`](../concept.md) for product intent.

---

## Primary recommendation: **Apache License 2.0**

**Why it often fits a desktop (and possible server) application:**

- **Permissive:** Broad use, modification, and distribution; fewer strategic barriers than strong copyleft.
- **Patent language:** Includes an **explicit patent grant** and related terms that many teams prefer for **non-trivial applications**.
- **NOTICE file:** Encourages clear **third-party attribution** (relevant with many dependencies).

**Caveat:** Combining Apache-2.0 code with other licenses in one deliverable requires **compatibility checks** (common issue is dependency license mix, not Apache vs MIT alone).

---

## Simpler alternative: **MIT**

- **Very short** and **widely accepted** by corporate legal review.
- **No** explicit patent section (some organizations care; many still choose MIT).

Choose MIT if the priority is **maximum simplicity**; choose Apache-2.0 if the priority is **permissive + explicit patent grant + established app ecosystem practice**.

---

## When **not** to default to permissive: **GPL-3.0** / **AGPL-3.0**

- **GPL-3.0:** Appropriate if the goal is that **distributed derivatives** of the project (or linked works, per GPL interpretation) **remain** under **copyleft** terms. That can **discourage** proprietary forks and can **complicate** stacks that include non-GPL-friendly components.

- **AGPL-3.0:** Relevant mainly when **networked** use of **modified** versions must also **share source**—a **deliberate** policy choice. Often **heavier** for adoption than Apache/MIT for application-style projects.

Neither is implied by current MyLib intent unless **copyleft** becomes an explicit product goal.

---

## Middle ground (optional): **MPL-2.0**

- **File-level weak copyleft** for MPL-covered files. Common for **libraries**; less often the default for a **whole application** than Apache/MIT.

---

## Before locking a choice

1. **Consult counsel** (even briefly) when the project is public or has **commercial** or **enterprise** adopters.
2. **Audit dependencies:** Real friction often comes from **incompatible** or **surprising** dependency licenses, not only from picking MIT vs Apache-2.0.
3. Align **README** and **contributing** docs with the chosen license and **attribution** expectations.

---

## Recorded decision

**Chosen license:** **Apache License 2.0** (aligned with prior counsel recommendation on similar projects).

**Repository:** Root **`LICENSE`** contains the **verbatim** Apache-2.0 text; **`NOTICE`** holds **project copyright** and a reminder to append **third-party** notices as dependencies are added (**Apache-2.0 §4d**).

**Pending:** **Final review/sign-off** with IP counsel before wide publication; **dependency license audit** as implementation proceeds.

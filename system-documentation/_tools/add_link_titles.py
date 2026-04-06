#!/usr/bin/env python3
"""
Add missing Markdown inline link titles: [text](url) -> [text](url "Title").

**Safety:** Only transforms targets that contain **no** double-quote (`"`). Any link
that already includes a title — including titles with parentheses, e.g.
`(#anchor "FR-006 Full-Text Indexing (when permitted)")` — is left unchanged.

Convention (repo): [text](url "Title") for internal and cross-file links where helpful.
"""
from __future__ import annotations

import re
import sys
from pathlib import Path

LINK_RE = re.compile(r"(?<!!)\[([^\]]*)\]\(([^)]+)\)")


def title_for_fragment(fragment: str) -> str:
    f = fragment.strip()
    if f.startswith("fr-") or f.startswith("nfr-"):
        if "--" in f:
            id_part, tail = f.split("--", 1)
            id_fmt = id_part.upper()
            tail_fmt = " ".join(w.capitalize() for w in tail.split("-"))
            return f"{id_fmt} {tail_fmt}"
        return f.upper()
    head, *rest = f.split("-", 1)
    if head.isdigit() and rest:
        return f"{head}. {' '.join(w.capitalize() for w in rest[0].split('-'))}"
    return " ".join(w.capitalize() for w in f.split("-"))


def title_for_url(url: str) -> str:
    u = url.strip().split()[0] if url.strip() else url
    fragment = ""
    if "#" in u:
        path, fragment = u.split("#", 1)
    else:
        path = u

    if fragment:
        return title_for_fragment(fragment)

    name = Path(path).stem if path else ""
    if not name:
        return "Link"
    return name.replace("-", " ").replace("_", " ").title()


def add_title_to_target(target: str) -> str:
    t = target.strip()
    if '"' in t:
        return target
    title = title_for_url(t).replace('"', "'")
    return f'{t} "{title}"'


def process_text(text: str) -> tuple[str, int]:
    count = 0

    def repl(m: re.Match) -> str:
        nonlocal count
        label, target = m.group(1), m.group(2)
        if '"' in target.strip():
            return m.group(0)
        new_target = add_title_to_target(target)
        count += 1
        return f"[{label}]({new_target})"

    return LINK_RE.sub(repl, text), count


def main() -> int:
    roots = [
        Path(__file__).resolve().parents[1],
        Path(__file__).resolve().parents[2] / "docs",
        Path(__file__).resolve().parents[2] / "04-templates",
    ]
    total = 0
    for root in roots:
        if not root.is_dir():
            continue
        for path in sorted(root.rglob("*.md")):
            if "_tools" in path.parts:
                continue
            raw = path.read_text(encoding="utf-8")
            new, n = process_text(raw)
            if n:
                path.write_text(new, encoding="utf-8", newline="\n")
                print(f"{path}: +{n} titles")
                total += n
    print(f"Total titles added: {total}")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())

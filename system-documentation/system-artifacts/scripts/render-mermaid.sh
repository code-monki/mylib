#!/usr/bin/env bash
set -euo pipefail

ROOT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")/.." && pwd)"
SRC_DIR="$ROOT_DIR/img-src"
OUT_DIR="$ROOT_DIR/img"
SKIP_FILE="$SRC_DIR/manual-svg-skip.txt"

mkdir -p "$OUT_DIR"

should_skip() {
  local diagram_name="$1"
  [ -f "$SKIP_FILE" ] || return 1
  while IFS= read -r entry; do
    # Ignore blank lines and comments.
    [[ -z "$entry" || "$entry" == \#* ]] && continue
    if [[ "$entry" == "$diagram_name" ]]; then
      return 0
    fi
  done < "$SKIP_FILE"
  return 1
}

for src in "$SRC_DIR"/*.mmd; do
  [ -e "$src" ] || continue
  name="$(basename "$src" .mmd)"
  if should_skip "$name"; then
    echo "Skipping $name.svg (hand-authored SVG)"
    continue
  fi
  npx -y @mermaid-js/mermaid-cli -i "$src" -o "$OUT_DIR/$name.svg" -b white
  echo "Rendered $name.svg"
done

#!/usr/bin/env bash
set -euo pipefail

ROOT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")/.." && pwd)"
SRC_DIR="$ROOT_DIR/img-src"
OUT_DIR="$ROOT_DIR/img"

mkdir -p "$OUT_DIR"

for src in "$SRC_DIR"/*.mmd; do
  [ -e "$src" ] || continue
  name="$(basename "$src" .mmd)"
  npx -y @mermaid-js/mermaid-cli -i "$src" -o "$OUT_DIR/$name.svg" -b white
  echo "Rendered $name.svg"
done

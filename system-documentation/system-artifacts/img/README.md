# Diagram assets

Generated SVG diagram artifacts for Markdown viewer compatibility.

- Edit Mermaid sources in [`../img-src/`](../img-src/ "Mermaid Sources").
- Regenerate SVG files by running [`../scripts/render-mermaid.sh`](../scripts/render-mermaid.sh "Render Mermaid Diagrams").
- Hand-authored SVG protection: add the Mermaid base name (no extension) to [`../img-src/manual-svg-skip.txt`](../img-src/manual-svg-skip.txt) to prevent accidental overwrite during regeneration.
- Current protected example: [`hla-system-context.svg`](hla-system-context.svg) (hand-authored for renderer compatibility).
- For large/complex diagrams, hand-authored or external-tool-exported SVGs (for example Omnigraffle exports) are acceptable and preferred when readability is materially better than auto-routed Mermaid output.
- Standard orientation is vertical (`flowchart TB` and `direction TB`) unless a specific exception is justified.

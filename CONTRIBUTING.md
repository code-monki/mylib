# Contributing

## Build platform of record

`GitHub Actions` is the project’s default **build and packaging platform of record** for
reproducible, reviewable release artifacts. Local builds remain supported, but changes that
affect distributed binaries or dependency pins should be validated in CI on:

- `windows`, `macos`, and `linux` runners (exact matrix TBD in the packaging pass)

## License

This project is licensed under the GNU General Public License v3.0 or any later version
(`GPL-3.0-or-later`). See the repository `LICENSE` file.

## Third-party licenses

As native dependencies are added, their license texts and attribution requirements must be
recorded under `licenses/` and reflected in the root `NOTICE` for shipped artifacts.
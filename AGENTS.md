# AI Agent deployment contract

This contract automates the Twilight Echo bridge only. The repository does not ship a Windhawk installer; unless the user explicitly authorizes another supported workflow, tell them to create or update the local mod in Windhawk with `taskbar-fluent-media-player-netease.wh.cpp` and compile it there.

When asked to install or update the Twilight Echo taskbar bridge:

1. Read `README.md` and `integrations/twilight/v1.1.2.json`.
2. Run `tools/twilight-bridge.ps1 status`, then `ensure -WhatIf`.
3. Never bypass the pinned executable version, original `app.asar` hash, source commit, backup, or health check.
4. If the tool returns `close_twilight_required`, ask the user to exit Twilight Echo from its system-tray menu. Do not force-kill it.
5. Run `ensure`. Treat only exit code `0` with `outcome` equal to `installed` or `healthy` as success.
6. Run `status` again and require `outcome: healthy` before reporting completion.
7. Do not edit `%APPDATA%\TwilightEcho` login, playlist, playback-session, or settings files.
8. Use `remove` to restore the verified original `app.asar`; do not replace it manually.

Default installation path is `D:\TwilightEcho`. Pass `-InstallDir` explicitly when it differs.

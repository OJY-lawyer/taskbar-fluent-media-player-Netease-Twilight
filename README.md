# Taskbar Fluent Media Player · 网易云 / Twilight Echo

这是 [Salyts/Taskbar-Fluent-Media-Player](https://github.com/Salyts/Taskbar-Fluent-Media-Player) 的非官方 Windhawk 扩展版，面向 Windows 11 任务栏，专门适配网易云音乐桌面端与 [Twilight Echo](https://github.com/asenyarzc-cpu/Twilight_Echo)。

当前 Mod 版本为 `1.6.0-net36`。Twilight 本地桥目前只支持官方发布版 `1.1.2`。

## 功能

- 在任务栏显示专辑封面、歌名或同步歌词，并提供上一首、播放/暂停、下一首控制。
- “歌词”和“歌名”是二选一的固定显示模式。歌词模式下，鼠标悬停会在原文字区域临时切换为歌名，不会弹出额外气泡。
- 原文与译文可上下两行居中显示；切歌刷新时保留原来的任务栏宽度和占位，避免先收缩再展开。
- 在网易云音乐与 Twilight Echo 之间切换，并记住所选客户端。
- Twilight 安装本地桥后，可在后台可靠同步歌曲、播放状态、歌词、封面和真实收藏状态。
- Twilight 红心只在网易云账号确认收藏成功后点亮；读取中显示问号，失败时不会伪装成功。
- 官方网易云模式暂不显示红心。SMTC 不提供收藏接口，模拟按键方案无法可靠确认账号侧结果。
- 默认启用随专辑封面变色的 7 柱立体声音频可视化。
- 支持跟随系统、简体中文和英语界面，保留上游的 Fluent 外观与大部分任务栏布局选项。
- 已移除容易卡住的悬停迷你播放器，悬停区域只负责显示歌名及操作按钮。

## 能力对照

| 模式 | 播放控制 | 歌词与封面 | 红心收藏 |
| --- | --- | --- | --- |
| 网易云音乐桌面端 | SMTC | SMTC + 本地播放信息匹配 | 已屏蔽 |
| Twilight Echo，无桥 | SMTC、可访问性接口等兼容路径 | 尽力读取日志与会话文件 | 不可用 |
| Twilight Echo，已装桥 | 本地桥权威控制 | 本地桥权威状态 | 仅网易云来源曲目可用，写入 Twilight 当前登录的网易云账号 |

## 安装 Windhawk Mod

1. 从 [Windhawk 中文官网下载页](https://www.windhawk.cn/download.html) 安装 Windhawk。
2. 下载 [`taskbar-fluent-media-player-netease.wh.cpp`](./taskbar-fluent-media-player-netease.wh.cpp)。
3. 在 Windhawk 中新建本地 Mod，粘贴完整源码并编译。
4. 如果已有 ID 为 `taskbar-fluent-media-player-netease` 的 Mod，请进入原 Mod 的编辑页全量替换源码，不要新建第二份同 ID Mod。
5. 在“应用接入”中核对两个客户端的程序路径，再选择播放器位置、文本模式和语言。

仓库目前不提供 Windhawk 安装器。首次安装仍需用户在 Windhawk 界面完成本地 Mod 的创建与编译；AI Agent 可以准备源码并核验结果，但 Twilight 桥才支持按下文流程自动部署。

网易云音乐必须在客户端设置中开启 SMTC，也就是“开启后播放信息同步到系统菜单栏及壁纸等第三方软件”。

## 安装 Twilight 本地桥

桥不是独立常驻程序。部署工具会在严格核对版本后，从 Twilight Echo `v1.1.2` 的固定源码提交构建一个带桥的 `app.asar`，备份原文件，再仅替换这个文件。它不会修改 `%APPDATA%\TwilightEcho` 中的登录、歌单或播放器设置。

请先克隆或下载完整仓库，并在仓库根目录打开 PowerShell；只下载 Windhawk 的 `.cpp` 源文件无法运行桥部署工具。

准备条件：Windows PowerShell 5.1 或 PowerShell 7、Git、Node.js 22 与 Corepack。第一次构建需要联网下载 Twilight 的项目依赖。

下方示例使用 PowerShell 7 的 `pwsh`。只有 Windows PowerShell 5.1 时，把 `pwsh -NoProfile` 替换为 `powershell.exe -NoProfile -ExecutionPolicy Bypass` 即可，例如：

```powershell
powershell.exe -NoProfile -ExecutionPolicy Bypass -File .\tools\twilight-bridge.ps1 status -InstallDir 'D:\TwilightEcho'
```

```powershell
# 只查看状态
pwsh -NoProfile -File .\tools\twilight-bridge.ps1 status -InstallDir 'D:\TwilightEcho'

# 先预演，不改文件
pwsh -NoProfile -File .\tools\twilight-bridge.ps1 ensure -InstallDir 'D:\TwilightEcho' -WhatIf

# 从系统托盘彻底退出 Twilight Echo 后安装
pwsh -NoProfile -File .\tools\twilight-bridge.ps1 ensure -InstallDir 'D:\TwilightEcho'

# 卸载桥并恢复已备份的原版 app.asar，同样要先退出 Twilight Echo
pwsh -NoProfile -File .\tools\twilight-bridge.ps1 remove -InstallDir 'D:\TwilightEcho'
```

工具始终输出 JSON，并采用以下约束：

- 只接受 `TwilightEcho.exe` 文件版本 `1.1.2`。
- 只接受原版 `app.asar` 的固定 SHA-256：`54C5BA910CB060A52D6C53AEBF96295577F7F2A6D597B7FCCFBB9954D5D27562`。
- 遇到未知版本、未知 `app.asar` 或正在运行的 Twilight 会先停止，不会强杀进程或覆盖文件。
- 原文件备份及部署状态保存在安装目录同级的 `TwilightEcho.taskbar-bridge` 文件夹。
- 新版本启动后必须通过本地桥健康检查；失败时工具会尝试恢复原文件。若自动恢复也失败，JSON 会返回 `manual_restore_required`、已验证备份路径和明确的恢复动作，不会把失败报告为成功。
- 断电导致当前 `app.asar` 缺失时，`status` 会返回已验证备份的位置；`remove` 可执行显式恢复。

### 给 AI Agent 的部署顺序

1. 读取本 README 和 [`integrations/twilight/v1.1.2.json`](./integrations/twilight/v1.1.2.json)。
2. 先运行 `status`，再运行 `ensure -WhatIf`。
3. 如果返回 `close_twilight_required`，让用户从系统托盘彻底退出 Twilight Echo；不得强杀。
4. 运行 `ensure`，只把退出码 `0` 且 `outcome` 为 `installed` 或 `healthy` 视为成功。
5. 再运行一次 `status`，确认 `outcome` 为 `healthy`。
6. 不要绕过版本、哈希、备份或健康检查，也不要直接改用户的 Twilight 数据目录。

更精简的机器协作说明见 [`AGENTS.md`](./AGENTS.md)。

## 桥如何工作

Twilight 启动时会在 `%APPDATA%\TwilightEcho\taskbar-bridge.json` 写入当前实例的随机端口、临时令牌和实例 ID。Windhawk Mod 只连接 `127.0.0.1`，请求必须携带该令牌。

桥提供三个本机入口：

- `GET /taskbar/v1/health`
- `GET /taskbar/v1/state`
- `POST /taskbar/v1/command`

收藏使用带目标歌曲 ID、目标状态和请求 ID 的 `set-favorite` 命令。它只接受当前 `providerId` 为 `ncm` 的曲目。Twilight 在真正调用网易云 provider 前再次核对歌曲，服务端也会等待账号侧状态回传；只有 `confirmed` 或 `noop` 才算成功。这避免迟到的点击误收藏下一首，也避免任务栏先亮心、账号歌单却没有变化。

## 默认交互

| 操作 | 默认行为 |
| --- | --- |
| 左键单击 | 无操作 |
| 播放器或 Album 双击 | 播放/暂停 |
| Album 或播放器右键 | 打开媒体菜单 |
| Album 或播放器滚轮 | 上一首/下一首 |
| 悬停后点击“暮 / 云” | 切换 Twilight Echo / 网易云音乐 |
| 悬停后点击“词” | 展开或收起歌词与控制区 |

“打开媒体应用”只在右键菜单中执行，普通单击不会启动客户端。

## 已知限制

- Twilight 桥当前严格绑定 `v1.1.2`。客户端升级后，应先使用 `remove` 恢复原文件，再升级并等待新的兼容清单。
- 官方网易云模式暂不提供红心收藏。
- 无桥模式只作为兼容兜底，Twilight 在后台时可能无法及时暴露新歌曲或收藏状态。
- 歌词仍依赖歌曲 ID或网易云元数据匹配；同名歌曲的不同版本可能匹配错误。
- Taskbar Styler 主题如果删除或大幅改名系统任务栏 XAML 元素，锚点仍可能失效。
- 当前只完成和发布 x64 验证；x86 构建留到功能稳定后再考虑。

## 许可与声明

- Windhawk Mod 代码继承上游的 MIT License，见 [`LICENSE`](./LICENSE)。原作者为 [Salyts](https://github.com/Salyts/Taskbar-Fluent-Media-Player)。
- 音频可视化采集与 FFT 实现来源于 [GR0UD/Taskbar Media Player](https://github.com/GR0UD/windhawk-mods)。
- Twilight 桥补丁基于 Apache-2.0 许可的 [Twilight Echo](https://github.com/asenyarzc-cpu/Twilight_Echo)，其补丁与部署材料见 [`integrations/twilight`](./integrations/twilight)，许可见 [`integrations/twilight/LICENSE`](./integrations/twilight/LICENSE)。
- 本项目与 Salyts、网易云音乐及 Twilight Echo 官方均无隶属关系，也不代表其认可或背书。

---

# English

This is an unofficial Windhawk fork of [Salyts/Taskbar-Fluent-Media-Player](https://github.com/Salyts/Taskbar-Fluent-Media-Player), specialized for NetEase Cloud Music and [Twilight Echo](https://github.com/asenyarzc-cpu/Twilight_Echo) on the Windows 11 taskbar.

Current mod version: `1.6.0-net36`. The optional Twilight bridge currently targets the official Twilight Echo `1.1.2` release only.

## Features

- Taskbar artwork, track title or synchronized lyrics, plus previous, play/pause and next controls.
- Title and lyrics are separate display modes. In lyric mode, hovering temporarily replaces the lyric text in place with the title; it does not open a popup.
- Centered original/translated lyric lines and a stable placeholder during track changes, avoiding collapse-and-expand layout jumps.
- Persistent switching between the official NetEase client and Twilight Echo.
- An optional authenticated loopback bridge for authoritative Twilight background state, controls, lyrics, artwork and account-backed favorites.
- Twilight hearts change only after the provider confirms the requested state. Unknown state remains visibly pending instead of pretending success.
- The heart is intentionally hidden in official NetEase mode because SMTC exposes no reliable favorite API.
- A seven-bar album-color stereo visualizer is enabled by default.
- The unreliable hover mini-player has been removed.

## Capability matrix

| Mode | Transport | Lyrics and artwork | Favorite |
| --- | --- | --- | --- |
| Official NetEase client | SMTC | SMTC plus local metadata matching | Disabled |
| Twilight without bridge | Compatibility fallbacks | Best effort | Unavailable |
| Twilight with bridge | Authoritative local bridge | Authoritative local bridge | NCM-source tracks only; writes to the NetEase account signed into Twilight |

## Install the Windhawk mod

Download [`taskbar-fluent-media-player-netease.wh.cpp`](./taskbar-fluent-media-player-netease.wh.cpp), create a local Windhawk mod, paste the full source and compile it. If the same mod ID already exists, replace its source in the existing editor instead of creating a duplicate. Enable SMTC in the official NetEase client.

This repository does not ship a Windhawk installer. Users still create and compile the local mod in the Windhawk UI; the automated AI-agent workflow below applies to the Twilight bridge.

## Install the Twilight bridge

The deployment tool verifies the exact Twilight Echo `1.1.2` executable and original `app.asar`, builds the pinned open-source patch, backs up the original file and swaps only `app.asar`. It never edits the user's login, playlists or settings under `%APPDATA%\TwilightEcho`.

Clone or download the complete repository and open PowerShell in its root directory. The bridge tool is not included when only the Windhawk `.cpp` file is downloaded.

Prerequisites: Windows PowerShell 5.1 or PowerShell 7, Git, Node.js 22 and Corepack. The first build downloads project dependencies.

The examples below use PowerShell 7 (`pwsh`). On a Windows PowerShell 5.1-only system, replace `pwsh -NoProfile` with `powershell.exe -NoProfile -ExecutionPolicy Bypass`.

```powershell
pwsh -NoProfile -File .\tools\twilight-bridge.ps1 status -InstallDir 'D:\TwilightEcho'
pwsh -NoProfile -File .\tools\twilight-bridge.ps1 ensure -InstallDir 'D:\TwilightEcho' -WhatIf

# Fully exit Twilight Echo from the system tray before ensure/remove.
pwsh -NoProfile -File .\tools\twilight-bridge.ps1 ensure -InstallDir 'D:\TwilightEcho'
pwsh -NoProfile -File .\tools\twilight-bridge.ps1 remove -InstallDir 'D:\TwilightEcho'
```

The tool always emits JSON. It fails closed on an unknown version or `app.asar`, never force-kills Twilight, and keeps the original under the sibling `TwilightEcho.taskbar-bridge` directory. If the patched app fails its authenticated health check, the tool attempts rollback; a rollback failure is reported as `manual_restore_required` with the verified backup path and required action.

For AI agents: run `status`, then `ensure -WhatIf`; ask the user to exit Twilight when the result is `close_twilight_required`; run `ensure`; accept only exit code `0` with `installed` or `healthy`; finally run `status` again and require `healthy`. Never bypass the version, hash, backup or health checks. See [`AGENTS.md`](./AGENTS.md).

## Bridge protocol

Each Twilight launch writes a random loopback port, ephemeral token and instance ID to `%APPDATA%\TwilightEcho\taskbar-bridge.json`. The mod accepts only `127.0.0.1` and authenticates every request.

- `GET /taskbar/v1/health`
- `GET /taskbar/v1/state`
- `POST /taskbar/v1/command`

Favorite writes are accepted only for tracks whose `providerId` is `ncm`. They use an idempotent `set-favorite` request containing the desired state and expected track ID. Twilight validates the provider and track again in the renderer and reports success only after authoritative state confirms it.

## Known limitations

- The bridge is pinned to Twilight Echo `v1.1.2`; restore the original with `remove` before upgrading Twilight.
- Favorites are disabled in official NetEase mode.
- Bridge-free Twilight support is a best-effort fallback and can lag while the renderer is suspended.
- Lyric matching still depends on NetEase IDs or metadata and can confuse different releases with identical names.
- Highly customized Taskbar Styler themes can still remove the XAML anchor used by the mod.
- Only x64 is verified at this stage.

## License and attribution

The Windhawk mod is distributed under the upstream MIT License; see [`LICENSE`](./LICENSE). The Twilight bridge patch is derived from Apache-2.0-licensed [Twilight Echo](https://github.com/asenyarzc-cpu/Twilight_Echo); see [`integrations/twilight/LICENSE`](./integrations/twilight/LICENSE). Visualizer capture and FFT work originates from [GR0UD/Taskbar Media Player](https://github.com/GR0UD/windhawk-mods).

This project is not affiliated with or endorsed by Salyts, NetEase Cloud Music, or Twilight Echo.

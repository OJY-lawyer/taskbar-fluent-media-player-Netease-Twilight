# Taskbar Fluent Media Player · 网易云 / Twilight Echo 扩展版

这是 [Salyts/Taskbar-Fluent-Media-Player](https://github.com/Salyts/Taskbar-Fluent-Media-Player) 的非官方 Windhawk 二次开发版，专门用于在 Windows 11 任务栏控制网易云音乐桌面端与 [Twilight Echo](https://github.com/asenyarzc-cpu/Twilight_Echo)。

本分支保留原版的 Fluent 外观和高度自定义能力，重点增加了双客户端切换、红心收藏、任务栏同步歌词、紧凑布局、简体中文界面以及 Taskbar Styler 布局适配。它不是面向所有媒体应用的通用播放器。

## 主要功能

- 默认使用紧凑 Album 入口。有曲目时保留专辑封面和红心，其余详情与控制按钮可通过“词”按钮展开。
- 音源切换按钮和歌词按钮仅在鼠标悬停时出现，减少任务栏常驻占用。
- 支持网易云音乐与 Twilight Echo 之间切换，选择结果会由 Windhawk 保存。
- 支持红心收藏、上一首、播放/暂停和下一首。已收藏显示实心红心，取消后恢复空心。
- 支持任务栏同步歌词。原文与译文按时间戳合并为上下两行，居中显示；歌词模式不会触发标题横向滚动。
- 未播放或所选客户端未运行时隐藏无效按钮，只保留应用图标或 Album 占位；可从右键菜单启动对应应用。
- 提供跟随系统、简体中文和英语三种界面语言。
- 默认开启 7 柱立体声音频可视化，颜色会随专辑封面变化。
- 保留上游的多位置锚定、Fluent 背景、亮暗配色、封面与按钮样式、尺寸间距、音频频谱和鼠标动作设置。
- 针对 Windows 11 Taskbar Styler - Fork 常见的移动与负边距布局进行动态定位，默认 `Album margin = 0 0` 时通常无需手工增加 9 像素补偿。

## 发布版默认外观

发布版默认值以维护者当前实际使用的布局为基准：播放器位于开始按钮右侧，采用透明任务栏背景、32 像素 Album、紧凑歌词布局，以及位于右侧的 7 柱立体声音频可视化。可视化使用“动态专辑颜色”、`5 / 1` 柱体尺寸和 `200` 灵敏度，会根据当前封面改变颜色。

Album 与播放器区域滚轮默认切换曲目，Album 点击会穿透到播放器区域，因此双击 Album 也可播放或暂停。迷你播放器不随这套预设启用。

## 默认交互

| 操作 | 默认行为 |
| --- | --- |
| 左键单击 | 无操作 |
| 播放器区域左键双击 | 播放或暂停 |
| 专辑封面左键双击 | 由“封面点击穿透”及 Album 独立动作设置决定 |
| Album 或播放器区域右键 | 打开媒体菜单 |
| 悬停后点击“暮 / 云” | 切换 Twilight Echo / 网易云音乐 |
| 悬停后点击“词” | 展开或收起歌词与播放控制 |

“打开媒体应用”只从右键菜单执行，不会因左键单击 Album 而意外启动客户端。

## 使用前准备

### 网易云音乐

必须在网易云音乐设置中开启 SMTC，也就是“开启后播放信息同步到系统菜单栏及壁纸等第三方软件”。未开启时，本 Mod 无法稳定取得歌名、封面和播放状态，会把网易云视为没有可用媒体会话。

### Twilight Echo

- 当前按 Twilight Echo `1.1.2` 测试。
- 建议在“设置 > 常规”中开启“原生媒体控制（SMTC）”。
- SMTC 未实际注册时，本 Mod 会自动使用 Windows UI Automation，从客户端公开的界面元素读取曲目、播放状态、进度、控制能力和收藏状态。
- 如果 Twilight Echo 不在默认位置，请在本 Mod 的“应用接入”中填写 `TwilightEcho.exe` 的完整路径。
- UI Automation 兼容模式下不提供随机、循环和快进/后退能力。

## 安装与更新

1. 安装 [Windhawk](https://windhawk.net/)。
2. 下载仓库中的 [`taskbar-fluent-media-player-netease.wh.cpp`](./taskbar-fluent-media-player-netease.wh.cpp)。
3. 在 Windhawk 中新建本地 Mod，粘贴完整源码并点击“编译 Mod”。
4. 如果已经存在 ID 为 `taskbar-fluent-media-player-netease` 的版本，请进入原 Mod 的编辑页全量替换源码，不要新建第二份同 ID Mod。
5. 在“应用接入”中核对网易云音乐和 Twilight Echo 的程序路径，再按需选择任务栏位置与语言。

更新后若界面没有立即刷新，可重新加载 Mod，或重启一次资源管理器。

## 数据访问说明

本 Mod 不修改网易云音乐或 Twilight Echo 客户端文件，也不注入 `app.asar`、不安装桥接程序。

为完成歌词、封面和兼容控制，它会：

- 只读网易云音乐的 `%LOCALAPPDATA%\NetEase\CloudMusic\webdata\file\playingList`，用于匹配当前曲目 ID。
- 在 Twilight Echo 的系统封面不可读取时，只读 `%APPDATA%\TwilightEcho\playback-session.json`，并且仅在歌名、歌手与当前任务栏曲目一致时使用其中的 `coverSource`。
- 通过 Windows UI Automation 读取并调用客户端已经公开的播放与收藏控件。
- 访问 Twilight Echo 本机的 `127.0.0.1:3100` 网易云接口，并向网易云歌词接口或图片 CDN 请求当前曲目的歌词与封面。

这些读取均在本机完成，本仓库不包含账号凭据、歌曲、歌词库、Twilight Echo 客户端或网易云音乐客户端。

## 已知限制

- **迷你播放器可能卡住，目前作为实验性功能保留，默认关闭且不建议启用。** 设置页和相关动作选项均有提示；任务栏主体、歌词与播放控制不依赖它。
- Twilight Echo 的 UI Automation 兼容依赖客户端公开的界面结构。后续版本若修改相关元素，曲目信息、控制或红心可能暂时失效。
- 歌词和搜索封面依赖网络、网易云接口以及标题、歌手、时长匹配。同名同歌手的不同版本可能匹配到错误歌词；封面判断更保守，存在歧义时会留空而不显示错误图片。
- 默认歌词模式会保留紧凑 Album 入口，因此不会沿用原版的“无媒体、全屏或空闲时完全隐藏”行为。
- Taskbar Styler 主题若大幅重命名、删除系统 XAML 元素或采用特殊布局，锚点仍可能失效。

## 版本说明

当前版本：`1.6.0-net22`

- 迷你播放器改为默认关闭，并在设置页标记已知问题。
- 发布默认值同步维护者当前布局，并默认启用动态专辑颜色音频可视化。
- Album 与歌词区域都可作为迷你播放器悬停区域，但不建议启用该实验功能。
- 修复 Twilight Echo 私有图片协议导致任务栏和迷你播放器无法显示封面的问题。
- 封面搜索增加歧义判断，避免同名版本串图。

## 上游、许可与声明

- 原版作者：[Salyts](https://github.com/Salyts/Taskbar-Fluent-Media-Player)。
- 上游音频可视化采集与 FFT 实现来源：[GR0UD/Taskbar Media Player](https://github.com/GR0UD/windhawk-mods)。
- 本修改版维护者：OJY。
- 本项目继续按 **MIT License** 分发，并保留原作者 **Salyts** 的完整版权和许可声明，详见 [`LICENSE`](./LICENSE)。
- 本项目与 Salyts、网易云音乐及 Twilight Echo 官方均无隶属关系，也不代表其认可或背书。

原版的 MIT License 明确允许使用、复制、修改和发布，但发布副本必须保留原版权与许可声明。

问题反馈请提交到本仓库的 [Issues](https://github.com/OJY-bot/taskbar-fluent-media-player-netease-twilight/issues)。

---

# English

This is an unofficial Windhawk fork of [Salyts/Taskbar-Fluent-Media-Player](https://github.com/Salyts/Taskbar-Fluent-Media-Player). It is designed specifically for controlling NetEase Cloud Music and [Twilight Echo](https://github.com/asenyarzc-cpu/Twilight_Echo) from the Windows 11 taskbar.

The fork keeps the upstream Fluent appearance and customization options while adding a two-client selector, favorites, synchronized taskbar lyrics, a compact layout, Simplified Chinese localization, and compatibility work for Taskbar Styler layouts. It is not a general-purpose controller for arbitrary media applications.

## Features

- Uses a compact Album entry by default. While a track is available, the artwork and heart remain visible; the lyric button expands the details and transport controls.
- The client selector and lyric toggle appear only on hover, reducing permanent taskbar usage.
- Switches between NetEase Cloud Music and Twilight Echo, with the selected client persisted by Windhawk.
- Supports favorite/unfavorite, previous, play/pause, and next. A liked track uses a filled heart; unliking restores the outline.
- Shows synchronized taskbar lyrics. Original and translated lines are merged by timestamp, displayed on two centered lines, and excluded from title scrolling.
- When playback is unavailable, unsupported buttons are hidden and only the app icon or Album placeholder remains. The selected app can be launched from the context menu.
- Provides Follow system, Simplified Chinese, and English interface languages.
- Enables a seven-bar stereo visualizer by default, with colors derived dynamically from the current album artwork.
- Retains upstream position anchors, Fluent backgrounds, light/dark colors, artwork and button styling, dimensions, spacing, spectrum options, and mouse actions.
- Dynamically adapts to common moved-element and negative-margin layouts from Windows 11 Taskbar Styler - Fork. With the default `Album margin = 0 0`, a manual nine-pixel compensation is usually unnecessary.

## Published default appearance

The published defaults mirror the maintainer's everyday layout: the player sits to the right of Start, uses a transparent taskbar background, a 32-pixel Album entry, the compact lyric layout, and a seven-bar stereo visualizer on the right. The visualizer uses Dynamic album color, a `5 / 1` bar size, and sensitivity `200`, so its color follows the current cover.

The mouse wheel changes tracks over both the Album and player areas. Album clicks pass through to the player area, so double-clicking the Album also toggles play/pause. The mini player is not enabled by this preset.

## Default interactions

| Input | Default behavior |
| --- | --- |
| Left click | No action |
| Double left click on the player area | Play or pause |
| Double left click on Album | Depends on click-through and the separate Album action setting |
| Right click on Album or the player area | Open the media context menu |
| Click `暮 / 云` after hovering | Select Twilight Echo / NetEase Cloud Music |
| Click `词` after hovering | Expand or collapse lyrics and transport controls |

Open media app is available only from the context menu. A normal left click on Album will not unexpectedly launch a client.

## Prerequisites

### NetEase Cloud Music

SMTC must be enabled in the NetEase client. In the Chinese client this is the option that synchronizes playback information to the system media menu and third-party software. Without it, the mod cannot reliably obtain the title, artwork, or playback state and treats NetEase as having no usable media session.

### Twilight Echo

- Compatibility has been tested with Twilight Echo `1.1.2`.
- Enabling Native media controls (SMTC) under Settings > General is recommended.
- If Twilight Echo does not register an SMTC session, the mod falls back to Windows UI Automation and reads the track, playback state, timeline, available controls, and favorite state from accessibility elements exposed by the client.
- If Twilight Echo is installed elsewhere, set the full path to `TwilightEcho.exe` under App integration.
- Shuffle, repeat, and seeking are unavailable in the UI Automation fallback mode.

## Installation and updates

1. Install [Windhawk](https://windhawk.net/).
2. Download [`taskbar-fluent-media-player-netease.wh.cpp`](./taskbar-fluent-media-player-netease.wh.cpp) from this repository.
3. Create a local mod in Windhawk, paste the complete source, and choose Compile Mod.
4. If a mod with ID `taskbar-fluent-media-player-netease` already exists, replace the source in that mod's editor. Do not create a second mod with the same ID.
5. Verify both executable paths under App integration, then choose the preferred taskbar position and language.

If the interface does not refresh after an update, reload the mod or restart Windows Explorer once.

## Local data access

The mod does not modify NetEase Cloud Music or Twilight Echo files. It does not patch `app.asar` or install a bridge.

To provide lyrics, artwork, and fallback controls, it:

- Reads `%LOCALAPPDATA%\NetEase\CloudMusic\webdata\file\playingList` to resolve the current NetEase track ID.
- When the Twilight Echo system artwork cannot be opened, reads `%APPDATA%\TwilightEcho\playback-session.json` and uses `coverSource` only after the saved title and artist match the current taskbar track.
- Reads and invokes playback and favorite controls that the clients expose through Windows UI Automation.
- Calls Twilight Echo's local NetEase endpoint at `127.0.0.1:3100` and requests the current lyrics or artwork from NetEase endpoints and image CDN hosts.

All matching is performed locally. This repository contains no account credentials, songs, lyric database, Twilight Echo client, or NetEase Cloud Music client.

## Known limitations

- **The mini player can become unresponsive. It remains available as an experimental feature, but is disabled by default and is not recommended.** The main taskbar player, lyrics, and transport controls do not depend on it.
- Twilight Echo fallback control depends on the accessibility structure currently exposed by the client. Future UI changes can temporarily break metadata, controls, or favorite state detection.
- Lyrics and search-based artwork depend on network access, NetEase endpoints, and title/artist/duration matching. Different releases with the same title and artist can receive the wrong lyrics. Artwork matching is more conservative and stays blank when the result is ambiguous.
- The default lyric mode keeps the compact Album entry visible, so the upstream hide-on-no-media, fullscreen, and idle behavior is not applied in that mode.
- A Taskbar Styler theme can still break an anchor if it substantially renames or removes Windows taskbar XAML elements or uses an unusual layout.

## Version

Current version: `1.6.0-net22`

- Disables the mini player by default and labels its known issue in settings.
- Makes both the Album and lyric area valid hover targets for the experimental mini player.
- Restores Twilight Echo artwork when its private image protocol is inaccessible to Explorer.
- Rejects ambiguous cover search matches to avoid artwork from a different release.
- Publishes the maintainer's current layout as the default, including the Dynamic album color audio visualizer.

## Upstream, license, and disclaimer

- Original project and author: [Salyts/Taskbar-Fluent-Media-Player](https://github.com/Salyts/Taskbar-Fluent-Media-Player).
- Upstream audio capture and FFT implementation: [GR0UD/Taskbar Media Player](https://github.com/GR0UD/windhawk-mods).
- Fork maintainer: OJY.
- This project is distributed under the **MIT License** and preserves the complete copyright and license notice of **Salyts**. See [`LICENSE`](./LICENSE).
- This project is not affiliated with or endorsed by Salyts, NetEase Cloud Music, or Twilight Echo.

The upstream MIT License permits use, copying, modification, and distribution, provided that the original copyright and license notice remain included.

Please report fork-specific problems through this repository's [Issues](https://github.com/OJY-bot/taskbar-fluent-media-player-netease-twilight/issues).

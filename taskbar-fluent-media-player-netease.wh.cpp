// ==WindhawkMod==
// @id              taskbar-fluent-media-player-netease
// @name            Taskbar Fluent Media Player (NetEase / Twilight Echo)
// @name:zh-CN      任务栏 Fluent 媒体播放器（网易云 / Twilight Echo）
// @description     Unofficial fork for NetEase Cloud Music and Twilight Echo with taskbar controls, synchronized lyrics, and bridge-backed Twilight favorites.
// @description:zh-CN 支持网易云音乐与 Twilight Echo 的任务栏播放控制、同步歌词，以及经本地桥确认的 Twilight 红心收藏。
// @description:ru-RU Taskbar Fluent Media Player — это мод Windhawk, который интегрирует современный медиаплеер в стиле Fluent Design прямо в панель задач Windows 11. Он позволяет управлять музыкой и просматривать информацию о треке без прерывания работы.
// @version         1.6.0-net36
// @author          Salyts (original), OJY (fork)
// @github          https://github.com/OJY-bot/taskbar-fluent-media-player-netease-twilight
// @license         MIT
// @include         explorer.exe
// @compilerOptions -lole32 -loleaut32 -loleacc -luiautomationcore -lruntimeobject -luuid -luser32 -lwindowsapp -lshell32 -lgdi32 -lshlwapi -lwindowscodecs -ldwmapi -lshcore -lksuser -lwinhttp -lbcrypt
// ==/WindhawkMod==

// ==WindhawkModReadme==
/*
# Taskbar Fluent Media Player · 网易云 / Twilight Echo 扩展版

这是 [Salyts/Taskbar-Fluent-Media-Player](https://github.com/Salyts/Taskbar-Fluent-Media-Player) 的非官方 Windhawk 二次开发版，面向 Windows 11 任务栏，专门适配网易云音乐与 Twilight Echo。

## 主要功能

* 在任务栏中显示专辑封面、歌名或同步歌词，并提供播放、暂停、上一首和下一首；Twilight 安装本地桥后还可使用真实红心收藏。
* 鼠标移到控件上后显示音源切换按钮，可在网易云音乐与 Twilight Echo 之间切换。
* 歌词按钮仅在悬停时出现；歌词可收起为单独的 Album 图标，也可展开为居中的原文/译文双行显示。歌词展开时，悬停会在原文字区域临时切换为歌名，不会弹出气泡。
* 未播放或应用未运行时仅保留应用图标，隐藏无效控制按钮；右键菜单可启动当前选择的媒体应用。
* 发布版默认位于开始按钮右侧，并开启会随专辑封面变色的 7 柱立体声音频可视化。
* 支持跟随系统、简体中文和英语界面，并保留上游的 Fluent 外观、任务栏位置、尺寸、配色、按钮及音频可视化设置。
* 针对 Windows 11 Taskbar Styler 常见的移动和负边距布局按实际坐标动态定位；默认 Album 边距为 `0 0`，通常无需手工增加 9 像素补偿。

## Twilight Echo 兼容方式

推荐安装仓库提供的 Twilight `v1.1.2` 本地桥。桥通过带临时令牌的 `127.0.0.1` 接口直接提供当前歌曲、播放状态、歌词、封面和收藏状态；播放与收藏命令也优先走桥。红心只对 `providerId=ncm` 的网易云来源曲目开放，收藏请求携带目标歌曲 ID 和目标状态，只有 Twilight 当前登录的网易云 provider 确认后才点亮。

未安装桥时仍保留只读兼容路径：音频日志与 `playback-session.json` 用于校准歌曲和时钟，SMTC/UI Automation 用于尽力控制。该模式不提供红心，后台同步也不保证及时。桥的安装与恢复命令见项目仓库 README。

## 基本使用

1. 在网易云音乐中开启 SMTC/系统媒体控制；Twilight Echo 建议安装本地桥，无桥时也建议开启“原生媒体控制（SMTC）”。
2. 在“应用接入”中确认两个客户端的程序路径。
3. 左键双击播放器区域可播放或暂停；右键打开菜单；悬停时可切换音源或开关歌词。
4. 如果已安装同 ID 的旧版本，请进入原 Mod 的编辑页替换源码，不要重复新建。

## 已知限制

* 本地桥当前严格支持 Twilight Echo `v1.1.2`；升级客户端前应先用仓库工具恢复原版 `app.asar`。
* 官方网易云模式暂不显示红心；Twilight 红心必须安装本地桥。
* Twilight Echo 的网易云来源可匹配在线歌词；其他来源不保证能取得歌词。
* 无桥兼容模式下，如果 Twilight Echo 的渲染进程在后台被挂起，状态可能延迟；桥接模式不依赖这种界面轮询。

## Credits & License

* [Salyts](https://github.com/Salyts) 为原版 Taskbar Fluent Media Player 作者。
* [GR0UD](https://github.com/GR0UD) 为上游音频可视化采集与 FFT 实现来源。
* 本修改版由 OJY 维护，与网易云音乐及 Twilight Echo 官方无隶属或背书关系。
* Windhawk Mod 按 MIT License 分发；Twilight 桥补丁继承 Twilight Echo 的 Apache-2.0 许可。完整许可与原版权声明见项目仓库。
* 问题反馈请使用本修改版仓库的 [Issues](https://github.com/OJY-bot/taskbar-fluent-media-player-netease-twilight/issues)。

---

# English

This is an unofficial Windhawk fork of [Taskbar Fluent Media Player](https://github.com/Salyts/Taskbar-Fluent-Media-Player), specialized for NetEase Cloud Music and Twilight Echo on the Windows 11 taskbar.

## Features

* Compact Album-first layout with previous, play/pause, next, and centered synchronized lyrics. Twilight favorites are available through the optional local bridge.
* Hover-only client and lyric toggles; choose between NetEase Cloud Music and Twilight Echo without keeping extra buttons visible. In lyric mode, hovering replaces the lyric text in place with the title rather than opening a popup.
* With the Twilight `v1.1.2` bridge installed, an authenticated loopback API is authoritative for track identity, playback, lyrics, artwork, and favorites. Favorites are exposed only for `providerId=ncm`; requests include the expected track and desired state and are shown as successful only after provider confirmation.
* Without the bridge, audio logs, the persisted playback session, SMTC and UI Automation remain best-effort read/control fallbacks. Favorites are unavailable in fallback mode.
* Conservative cover matching, Simplified Chinese/English UI, Taskbar Styler positioning fixes, and the upstream Fluent customization options.
* Published defaults place the player to the right of Start and enable a seven-bar Dynamic album color visualizer.

## Setup

Enable SMTC in NetEase Cloud Music. Install the repository's optional Twilight bridge for reliable background synchronization and favorites; otherwise enable Twilight's Native media controls as a fallback. Confirm both executable paths under App integration. Existing users must replace the source in the current mod editor instead of creating a duplicate mod ID.

## Known limitations

* The bridge is pinned to Twilight Echo `v1.1.2`. Restore the original `app.asar` before upgrading the client.
* Favorites are intentionally disabled in official NetEase mode and unavailable in bridge-free Twilight fallback mode.
* Lyrics and fallback artwork depend on network access and NetEase metadata matching; ambiguous artwork matches remain blank.
* Bridge-free Twilight support can lag when its renderer is suspended.

## Credits & License

Salyts is the original author. The upstream visualizer includes capture and FFT work from GR0UD. The Windhawk mod is distributed under the MIT License; the Twilight bridge patch remains under Twilight Echo's Apache-2.0 terms. This fork is maintained by OJY and is not affiliated with or endorsed by NetEase Cloud Music or Twilight Echo.
*/
// ==/WindhawkModReadme==

// ==WindhawkModSettings==
/*
- LanguageSettings:
  - language: system
    $name: Language
    $name:zh-CN: 界面语言
    $description: Select the language used by this mod. Restart or reload the mod after changing it.
    $description:zh-CN: 选择本 Mod 使用的界面语言。更改后请重新加载或重启本 Mod。
    $options:
    - system: Follow system language
    - zh-CN: Simplified Chinese
    - en-US: English (United States)
    $options:zh-CN:
    - system: 跟随系统语言
    - zh-CN: 简体中文
    - en-US: 英语（美国）
  $name: Language
  $name:zh-CN: 语言

- AppIntegrationSettings:
  - neteaseExecutablePath: 'D:\CloudMusic\cloudmusic.exe'
    $name: NetEase Cloud Music executable
    $name:zh-CN: 网易云音乐程序路径
    $description: Used only by Open media app and the idle launcher icon.
    $description:zh-CN: 仅用于“打开媒体应用”和未运行时的启动图标。
  - twilightExecutablePath: 'D:\TwilightEcho\TwilightEcho.exe'
    $name: Twilight Echo executable
    $name:zh-CN: Twilight Echo 程序路径
    $description: Change this if Twilight Echo is installed or extracted elsewhere.
    $description:zh-CN: 如果 Twilight Echo 安装或解压在其他位置，请在此修改。
  $name: App integration
  $name:zh-CN: 应用接入

- MainSettings:
  - PlayerSetting:
    - position: "taskbar_right_start"
      $name: Media player position
      $name:zh-CN: 媒体播放器位置
      $name:ru-RU: Расположение медиаплеера
      $options:
      - "taskbar_left_edge": "Taskbar - Left edge (Overlay)"
      - "taskbar_center_edge": "Taskbar - Center (Overlay)"
      - "taskbar_right_edge": "Taskbar - Right edge (Overlay)"
      - "taskbar_left_start": "Taskbar - Left of Start button"
      - "taskbar_right_start": "Taskbar - Right of Start button"
      - "taskbar_after_search_left": "Taskbar - Left of Search button"
      - "taskbar_after_search_right": "Taskbar - Right of Search button"
      - "taskbar_after_taskview_left": "Taskbar - Left of Task View button"
      - "taskbar_after_taskview_right": "Taskbar - Right of Task View button"
      - "taskbar_after_widgets_left": "Taskbar - Left of Widgets button"
      - "taskbar_after_widgets_right": "Taskbar - Right of Widgets button"
      - "tray_left": "Tray - Far left"
      - "tray_right": "Tray - Far right"
      - "tray_before_clock": "Tray - Left of Clock"
      - "tray_after_clock": "Tray - Right of Clock"
      - "tray_before_omni_left": "Tray - Left of Network/Volume button"
      - "tray_before_omni_right": "Tray - Right of Network/Volume button"
      - "tray_language_left": "Tray - Left of Language button"
      - "tray_language_right": "Tray - Right of Language button"
      - "tray_icons_left": "Tray - Left of Tray Icons"
      - "tray_icons_right": "Tray - Right of Tray Icons"
      - "tray_hidden_icons_left": "Tray - Left of Hidden icons button"
      - "tray_hidden_icons_right": "Tray - Right of Hidden icons button"
      - "tray_after_showdesktop_left": "Tray - Left of Show Desktop"
      - "tray_after_showdesktop_right": "Tray - Right of Show Desktop"
      $options:zh-CN:
      - "taskbar_left_edge": "任务栏：最左侧（叠加）"
      - "taskbar_center_edge": "任务栏：中央（叠加）"
      - "taskbar_right_edge": "任务栏：最右侧（叠加）"
      - "taskbar_left_start": "任务栏：开始按钮左侧"
      - "taskbar_right_start": "任务栏：开始按钮右侧"
      - "taskbar_after_search_left": "任务栏：搜索按钮左侧"
      - "taskbar_after_search_right": "任务栏：搜索按钮右侧"
      - "taskbar_after_taskview_left": "任务栏：任务视图按钮左侧"
      - "taskbar_after_taskview_right": "任务栏：任务视图按钮右侧"
      - "taskbar_after_widgets_left": "任务栏：小组件按钮左侧"
      - "taskbar_after_widgets_right": "任务栏：小组件按钮右侧"
      - "tray_left": "系统托盘：最左侧"
      - "tray_right": "系统托盘：最右侧"
      - "tray_before_clock": "系统托盘：时钟左侧"
      - "tray_after_clock": "系统托盘：时钟右侧"
      - "tray_before_omni_left": "系统托盘：网络和音量按钮左侧"
      - "tray_before_omni_right": "系统托盘：网络和音量按钮右侧"
      - "tray_language_left": "系统托盘：语言按钮左侧"
      - "tray_language_right": "系统托盘：语言按钮右侧"
      - "tray_icons_left": "系统托盘：托盘图标左侧"
      - "tray_icons_right": "系统托盘：托盘图标右侧"
      - "tray_hidden_icons_left": "系统托盘：隐藏图标按钮左侧"
      - "tray_hidden_icons_right": "系统托盘：隐藏图标按钮右侧"
      - "tray_after_showdesktop_left": "系统托盘：显示桌面区域左侧"
      - "tray_after_showdesktop_right": "系统托盘：显示桌面区域右侧"
      $options:ru-RU:
      - "taskbar_left_edge": "Панель задач - Левый край (оверлей)"
      - "taskbar_center_edge": "Панель задач - Центр (оверлей)"
      - "taskbar_right_edge": "Панель задач - Правый край (оверлей)"
      - "taskbar_left_start": "Панель задач - Слева от кнопки Пуск"
      - "taskbar_right_start": "Панель задач - Справа от кнопки Пуск"
      - "taskbar_after_search_left": "Панель задач - Слева от кнопки Поиск"
      - "taskbar_after_search_right": "Панель задач - Справа от кнопки Поиск"
      - "taskbar_after_taskview_left": "Панель задач - Слева от кнопки Представление задач"
      - "taskbar_after_taskview_right": "Панель задач - Справа от кнопки Представление задач"
      - "taskbar_after_widgets_left": "Панель задач - Слева от кнопки Мини-приложений"
      - "taskbar_after_widgets_right": "Панель задач - Справа от кнопки Мини-приложений"
      - "tray_left": "Трей - Край слева"
      - "tray_right": "Трей - Край справа"
      - "tray_before_clock": "Трей - Слева от часов"
      - "tray_after_clock": "Трей - Справа от часов"
      - "tray_before_omni_left": "Трей - Слева от кнопки Сеть/Громкость"
      - "tray_before_omni_right": "Трей - Справа от кнопки Сеть/Громкость"
      - "tray_language_left": "Трей - Слева от кнопки языка"
      -  "tray_language_right": "Трей - Справа от кнопки языка"
      - "tray_icons_left": "Трей - Слева от значков области уведомлений"
      - "tray_icons_right": "Трей - Справа от значков области уведомлений"
      - "tray_hidden_icons_left": "Трей - Слева от скрытых значков"
      - "tray_hidden_icons_right": "Трей - Справа от скрытых значков"
      - "tray_after_showdesktop_left": "Трей - Слева от кнопки Показать рабочий стол"
      - "tray_after_showdesktop_right": "Трей - Справа от кнопки Показать рабочий стол"
    - monitor: 1
      $name: Monitor
      $name:zh-CN: 显示器
      $name:ru-RU: Монитор
      $description: >-
        The monitor number the player will appear on (1, 2, 3...).
        This number may differ from the monitor number shown in
        Windows Display Settings.
      $description:zh-CN: >-
        播放器所在显示器的编号（1、2、3……）。
        此编号可能与 Windows 显示设置中的显示器编号不同。
      $description:ru-RU: >-
        Номер монитора, на котором будет отображаться плеер (1, 2, 3...).
        Это число может отличаться от номера монитора в параметрах
        экрана Windows.
    - playerWidth: "0 0"
      $name: Media player width (min max)
      $name:zh-CN: 媒体播放器宽度（最小值 最大值）
      $name:ru-RU: Ширина медиаплеера (min max)
      $description: The first number is the minimum size, and the second is the maximum. You can also set it to 0, which means no limit.
      $description:zh-CN: 第一个数字是最小尺寸，第二个数字是最大尺寸；设为 0 表示不限制。
      $description:ru-RU: Первая цифра — это минимальный размер, а вторая — максимальный. Также можно указать 0 — это без лимита.
    - playerHeight: "40 40"
      $name: Media player height (min max)
      $name:zh-CN: 媒体播放器高度（最小值 最大值）
      $name:ru-RU: Высота медиаплеера (min max)
    - playerMargin: "4 4"
      $name: Media player margin (left right)
      $name:zh-CN: 媒体播放器边距（左 右）
      $name:ru-RU: Отступ медиаплеера (left right)
      $description: The first number is the distance to the left, and the second is to the right.
      $description:zh-CN: 第一个数字是左侧间距，第二个数字是右侧间距。
      $description:ru-RU: Первая цифра — это расстояние влево, а вторая — вправо.
    - autoSwitchSession: true
      $name: Auto-switch to active media session
      $name:zh-CN: 自动切换到正在播放的媒体会话
      $name:ru-RU: Автопереключение на активную медиасессию
      $description: When enabled, the player automatically switches to whichever media session is currently playing. If the active session pauses and another session is already playing, the player will switch to it.
      $description:zh-CN: 启用后，播放器会自动切换到当前正在播放的媒体会话。如果当前会话暂停，而另一个会话正在播放，则会自动切换过去。
      $description:ru-RU: Если включено, плеер автоматически переключается на воспроизводящую медиасессию. Если текущая сессия поставлена на паузу, а другое приложение уже играет — плеер переключится на него.
    - mirrorLayout: false
      $name: Mirror layout
      $name:zh-CN: 镜像布局
      $name:ru-RU: Зеркальное расположение
      $description: Album art, text, and buttons will be displayed on the opposite side
      $description:zh-CN: 将专辑封面、文本和按钮显示在相反一侧。
      $description:ru-RU: Обложка альбома, текст и кнопки будут отображаться с противоположной стороны
    - fullHeightHitArea: true
      $name: Full-height invisible hit area
      $name:zh-CN: 全任务栏高度的隐形交互区域
      $name:ru-RU: Невидимая область клика на всю высоту
      $description: Extends the clickable/hoverable area of the player to the full height of the taskbar, even if the player itself is shorter. Disable this if you don't want the player to react to clicks/hovers above or below its visible bounds.
      $description:zh-CN: 即使播放器本身较矮，也将可点击和悬停区域扩展到任务栏的完整高度。如果不希望播放器响应其可见范围上方或下方的点击和悬停，请关闭此项。
      $description:ru-RU: Расширяет кликабельную/наводимую область плеера на всю высоту панели задач, даже если сам плеер меньше по высоте. Отключите, если не хотите, чтобы плеер реагировал на клики/наведение выше или ниже его видимых границ.
    $name: Media player
    $name:zh-CN: 媒体播放器
    $name:ru-RU: Медиаплеер

  - AlbumArtSetting:
    - showAlbumArt: true
      $name: Show album art
      $name:zh-CN: 显示专辑封面
      $name:ru-RU: Отображать обложку альбома
    - albumArtWidth: "32 64"
      $name: Album art width (min max)
      $name:zh-CN: 专辑封面宽度（最小值 最大值）
      $name:ru-RU: Ширина обложки альбома (min max)
    - albumArtHeight: "32 32"
      $name: Album art height (min max)
      $name:zh-CN: 专辑封面高度（最小值 最大值）
      $name:ru-RU: Высота обложки альбома (min max)
    - albumArtMargin: "0 0"
      $name: Album art margin (left right)
      $name:zh-CN: 专辑封面边距（左 右）
      $name:ru-RU: Отступ обложки альбома (left right)
    $name: Album Art
    $name:zh-CN: 专辑封面
    $name:ru-RU: Обложка альбома

  - TextAreaSetting:
    - taskbarTextMode: lyrics
      $name: Taskbar text
      $name:zh-CN: 任务栏文字
      $description: Choose synchronized lyrics or the track title. In lyrics mode, hovering replaces the lyric text in place with the title; no popup is opened.
      $description:zh-CN: 在同步歌词和歌曲标题之间二选一；歌词模式下，悬停会在原文字区域临时切换为歌名，不会弹出气泡。
      $options:
      - lyrics: Synchronized lyrics
      - title: Track title
      $options:zh-CN:
      - lyrics: 同步歌词
      - title: 歌曲标题
    - showTrackArtist: false
      $name: Show artist name
      $name:zh-CN: 显示歌手名称
      $name:ru-RU: Отображать имя исполнителя
    - textAreaWidth: "260 260"
      $name: Text area width (min max)
      $name:zh-CN: 文本区域宽度（最小值 最大值）
      $name:ru-RU: Ширина текстовой области (min max)
    - textAreaHeight: "0 0"
      $name: Text area height (min max)
      $name:zh-CN: 文本区域高度（最小值 最大值）
      $name:ru-RU: Высота текстовой области (min max)
    - textAreaMargin: "5 5"
      $name: Text area margin (left right)
      $name:zh-CN: 文本区域边距（左 右）
      $name:ru-RU: Отступ текстовой области (left right)
    - textSpacing: -1
      $name: Spacing between title and artist
      $name:zh-CN: 标题与歌手之间的间距
      $name:ru-RU: Отступ между названием и исполнителем
    - enableTitleScrolling: true
      $name: Enable track title scrolling
      $name:zh-CN: 启用歌曲标题滚动
      $name:ru-RU: Включить прокрутку названия трека
      $description: When enabled, the track title will scroll horizontally if it overflows the text area.
      $description:zh-CN: 启用后，歌曲标题超出文本区域时会水平滚动。
      $description:ru-RU: Если включено, название трека будет прокручиваться горизонтально при переполнении текстовой области.
    - enableArtistScrolling: false
      $name: Enable artist name scrolling
      $name:zh-CN: 启用歌手名称滚动
      $name:ru-RU: Включить прокрутку имени исполнителя
      $description: When enabled, the artist name will scroll horizontally if it overflows the text area.
      $description:zh-CN: 启用后，歌手名称超出文本区域时会水平滚动。
      $description:ru-RU: Если включено, имя исполнителя будет прокручиваться горизонтально при переполнении текстовой области.
    - scrollSpeed: 1
      $name: Scroll speed (1-10)
      $name:zh-CN: 滚动速度（1～10）
      $name:ru-RU: Скорость прокрутки (1-10)
      $description: Controls how fast the text scrolls. 1 = slowest, 10 = fastest.
      $description:zh-CN: 控制文本滚动速度。1 最慢，10 最快。
      $description:ru-RU: Управляет скоростью прокрутки текста. 1 = медленнее всего, 10 = быстрее всего.
    - scrollPauseDuration: 1000
      $name: Pause duration at edges (ms)
      $name:zh-CN: 到达边缘后的停留时间（毫秒）
      $name:ru-RU: Пауза на краях (мс)
      $description: How long (in milliseconds) scrolling pauses at the start and end before reversing direction.
      $description:zh-CN: 文本滚动到开头或末尾后，在反向滚动前停留的时间，单位为毫秒。
      $description:ru-RU: Сколько миллисекунд прокрутка делает паузу на начале и конце перед сменой направления.
    - scrollMode: "bounce"
      $name: Scroll mode
      $name:zh-CN: 滚动模式
      $name:ru-RU: Режим прокрутки
      $options:
      - "bounce": "Bounce (back and forth)"
      - "loop":   "Loop (continuous)"
      $options:zh-CN:
      - "bounce": "往返滚动"
      - "loop":   "循环滚动"
      $options:ru-RU:
      - "bounce": "Отскок (туда-обратно)"
      - "loop":   "Петля (непрерывная)"
    - loopGap: 40
      $name: Loop gap (px)
      $name:zh-CN: 循环间距（像素）
      $name:ru-RU: Отступ между повторами (пикс.)
      $description: Distance in pixels between the end of the text and the beginning of its copy in Loop mode.
      $description:zh-CN: 在循环滚动模式下，原文本末尾与下一份文本开头之间的距离，单位为像素。
      $description:ru-RU: Расстояние в пикселях между концом текста и началом его копии в режиме «Петля».
    - swapTitleArtist: false
      $name: Swap artist name and track title
      $name:zh-CN: 交换歌手名称与歌曲标题的位置
      $name:ru-RU: Поменять местами название трека и имя исполнителя
    - emptyTitleText: "Untitled"
      $name: Title text when track has no name
      $name:zh-CN: 歌曲没有标题时显示的文本
      $name:ru-RU: Текст названия, если у трека нет имени
      $description: Shown in the title field when a track is playing but has no title. Leave empty to hide the title text in this case.
      $description:zh-CN: 播放中的歌曲没有标题时，在标题栏显示此文本；留空则隐藏标题文本。
      $description:ru-RU: Отображается в поле названия, когда трек играет, но у него нет имени. Оставьте пустым, чтобы скрыть текст названия в этом случае.
    - noMediaTitleText: "Not Playing"
      $name: Title text when nothing is playing
      $name:zh-CN: 没有播放内容时显示的标题文本
      $name:ru-RU: Текст названия, когда ничего не воспроизводится
      $description: Shown in the title field when there is no media session at all. Leave empty to hide the title text in this case.
      $description:zh-CN: 完全没有媒体会话时，在标题栏显示此文本；留空则隐藏标题文本。
      $description:ru-RU: Отображается в поле названия, когда нет ни одной медиа-сессии. Оставьте пустым, чтобы скрыть текст названия в этом случае.
    - emptyArtistText: ""
      $name: Artist text when track has no artist
      $name:zh-CN: 歌曲没有歌手信息时显示的文本
      $name:ru-RU: Текст исполнителя, если у трека не указан автор
      $description: Shown in the artist field when a track is playing but has no artist specified. Leave empty to hide the artist text in this case.
      $description:zh-CN: 播放中的歌曲没有歌手信息时，在歌手栏显示此文本；留空则隐藏歌手文本。
      $description:ru-RU: Отображается в поле исполнителя, когда трек играет, но автор не указан. Оставьте пустым, чтобы скрыть текст исполнителя в этом случае.
    - noMediaArtistText: ""
      $name: Artist text when nothing is playing
      $name:zh-CN: 没有播放内容时显示的歌手文本
      $name:ru-RU: Текст исполнителя, когда ничего не воспроизводится
      $description: Shown in the artist field when there is no media session at all. Leave empty to hide the artist text in this case.
      $description:zh-CN: 完全没有媒体会话时，在歌手栏显示此文本；留空则隐藏歌手文本。
      $description:ru-RU: Отображается в поле исполнителя, когда нет ни одной медиа-сессии. Оставьте пустым, чтобы скрыть текст исполнителя в этом случае.
    $name: Text area
    $name:zh-CN: 文本区域
    $name:ru-RU: Текстовая область

  - MediaButtonsSettings:
    - showMediaButtons: true
      $name: Show media buttons
      $name:zh-CN: 显示媒体控制按钮
      $name:ru-RU: Отображать кнопки управления
    - mediaButtons: [heart, prev, play, next]
      $name: Media buttons order
      $name:zh-CN: 媒体控制按钮及顺序
      $name:ru-RU: Расположение кнопок управления
      $description: Select which media control buttons to display and their order. Duplicates are ignored.
      $description:zh-CN: 选择要显示的媒体控制按钮及其排列顺序。重复项会被忽略。
      $description:ru-RU: Выберите, какие кнопки управления воспроизведением отображать, а также их порядок. Дубликаты игнорируются.
      $options:
      - none: Nothing
      - heart: Like/Unlike (Twilight bridge)
      - prev: Previous Track
      - play: Play/Pause
      - next: Next Track
      - rewind: Rewind 5s
      - forward: Forward 5s
      - shuffle: Toggle Shuffle
      - repeat: Toggle Repeat
      - switch_sessions: Switch Sessions
      $options:zh-CN:
      - none: 不显示
      - heart: 喜欢或取消喜欢（仅 Twilight 本地桥）
      - prev: 上一首
      - play: 播放或暂停
      - next: 下一首
      - rewind: 后退 5 秒
      - forward: 前进 5 秒
      - shuffle: 开关随机播放
      - repeat: 切换循环模式
      - switch_sessions: 切换媒体会话
      $options:ru-RU:
      - none: Ничего
      - heart: Лайк/убрать лайк (Twilight bridge)
      - prev: Предыдущий трек
      - play: Воспроизведение/Пауза
      - next: Следующий трек
      - rewind: Перемотка назад 5 сек
      - forward: Перемотка вперёд 5 сек
      - shuffle: Случайный порядок
      - repeat: Повтор
      - switch_sessions: Переключить сессию
    - mediaButtonsMargin: "2 2"
      $name: Media buttons margin (left right)
      $name:zh-CN: 媒体控制按钮边距（左 右）
      $name:ru-RU: Отступ кнопок управления (left right)
    - buttonSize: 28
      $name: Button size
      $name:zh-CN: 按钮大小
      $name:ru-RU: Размер кнопок управления
    - hideUnsupportedButtons: false
      $name: Hide unsupported buttons
      $name:zh-CN: 隐藏不受支持的按钮
      $name:ru-RU: Скрывать неподдерживаемые кнопки
      $description: When enabled, buttons for actions not supported by the current media session are completely hidden instead of shown as disabled.
      $description:zh-CN: 启用后，当前媒体会话不支持的操作按钮将被完全隐藏，而非以禁用状态显示。
      $description:ru-RU: Когда включено, кнопки действий, не поддерживаемых текущей медиа-сессией, полностью скрываются вместо отображения в неактивном состоянии.
    $name: Media Buttons
    $name:zh-CN: 媒体控制按钮
    $name:ru-RU: Кнопки управления

  - VisualizerFunctionsSettings:
    - vizEnabled: true
      $name: Enable audio visualizer
      $name:zh-CN: 启用音频可视化
      $name:ru-RU: Включить аудиовизуализатор
      $description: Real-time spectrum bars driven by the system audio output (WASAPI loopback + FFT).
      $description:zh-CN: 根据系统音频输出实时显示频谱柱（WASAPI 回环录音和 FFT）。
      $description:ru-RU: Спектральные столбики в реальном времени, управляемые системным аудиовыходом (WASAPI loopback + FFT).
    - vizPosition: "right"
      $name: Position
      $name:zh-CN: 位置
      $name:ru-RU: Положение
      $description: Which side of the player the bars sit on.
      $description:zh-CN: 选择频谱柱显示在播放器的哪一侧。
      $description:ru-RU: С какой стороны плеера расположены столбики.
      $options:
      - "left": Left
      - "right": Right
      $options:zh-CN:
      - "left": 左侧
      - "right": 右侧
      $options:ru-RU:
      - "left": Слева
      - "right": Справа
    - vizShape: "stereo"
      $name: Bar shape
      $name:zh-CN: 频谱柱形状
      $name:ru-RU: Форма столбиков
      $options:
      - "stereo": Stereo
      - "mountain": Mountain
      - "mirror": Mirror
      - "wave": Wave
      - "breathe": Breathe
      $options:zh-CN:
      - "stereo": 立体声
      - "mountain": 山峰
      - "mirror": 镜像
      - "wave": 波浪
      - "breathe": 呼吸
    - vizEQ: "default"
      $name: EQ preset
      $name:zh-CN: 均衡器预设
      $name:ru-RU: Пресет эквалайзера
      $options:
      - "default": Balanced
      - "bass": Bass
      - "rock": Rock
      - "pop": Pop
      - "jazz": Jazz
      - "electronic": Electronic
      $options:zh-CN:
      - "default": 均衡
      - "bass": 低音
      - "rock": 摇滚
      - "pop": 流行
      - "jazz": 爵士
      - "electronic": 电子
      $options:ru-RU:
      - "default": Сбалансированный
      - "bass": Бас
      - "rock": Рок
      - "pop": Поп
      - "jazz": Джаз
      - "electronic": Электроника
    - vizAnchor: "middle"
      $name: Vertical anchor
      $name:zh-CN: 垂直对齐
      $name:ru-RU: Вертикальная привязка
      $options:
      - "top": Top
      - "middle": Middle
      - "bottom": Bottom
      $options:zh-CN:
      - "top": 顶部
      - "middle": 居中
      - "bottom": 底部
      $options:ru-RU:
      - "top": Сверху
      - "middle": По центру
      - "bottom": Снизу
    - vizBarCountGap: "7 5"
      $name: Bars (count gap)
      $name:zh-CN: 频谱柱（数量 间距）
      $name:ru-RU: Столбики (количество промежуток)
      $description: Two values "count gap" — number of bars (1-20) and spacing between them in px.
      $description:zh-CN: 输入“数量 间距”两个值，分别表示频谱柱数量（1～20）和柱间距（像素）。
      $description:ru-RU: Два значения "количество промежуток" — количество столбиков (1-20) и расстояние между ними в пикселях.
    - vizBarSize: "5 1"
      $name: Bar size (width height)
      $name:zh-CN: 频谱柱尺寸（宽度 静止高度）
      $name:ru-RU: Размер столбика (ширина высота)
      $description: Two values "width height" — bar width in px (0-40) and idle (resting) height in px (0-15). Width 0 hides the bars.
      $description:zh-CN: 输入“宽度 高度”两个值，分别表示频谱柱宽度（0～40 像素）和静止时高度（0～15 像素）。宽度设为 0 会隐藏频谱柱。
      $description:ru-RU: Два значения "ширина высота" — ширина столбика в пикселях (0-40) и высота покоя в пикселях (0-15). Ширина 0 скрывает столбики.
    - vizPadding: "0 0"
      $name: Padding (left right)
      $name:zh-CN: 内边距（左 右）
      $name:ru-RU: Отступы (слева справа)
      $description: Two values "left right" in px.
      $description:zh-CN: 输入“左 右”两个值，单位为像素。
      $description:ru-RU: Два значения "слева справа" в пикселях.
    - vizSensitivity: 200
      $name: Sensitivity (0-300)
      $name:zh-CN: 灵敏度（0～300）
      $name:ru-RU: Чувствительность (0-300)
    $name: Visualizer
    $name:zh-CN: 音频可视化
    $name:ru-RU: Визуализатор
  $name: Main Settings
  $name:zh-CN: 主要设置
  $name:ru-RU: Основные настройки

- AppearanceSettings:
  - BackgroundStyleSettings:
    - backgroundType: "none"
      $name: Background type
      $name:zh-CN: 背景类型
      $name:ru-RU: Тип фона
      $options:
      - "none":           "None (transparent)"
      - "solid":          "Solid color"
      - "gradient":       "Gradient"
      - "acrylic":        "Acrylic"
      - "mica":           "Mica"
      - "mica_alt":       "Mica Alt"
      - "album_art_blur": "Blurred album cover"
      $options:zh-CN:
      - "none":           "无（透明）"
      - "solid":          "纯色"
      - "gradient":       "渐变"
      - "acrylic":        "亚克力"
      - "mica":           "云母"
      - "mica_alt":       "云母 Alt"
      - "album_art_blur": "模糊专辑封面"
      $options:ru-RU:
      - "none":           "Нет (прозрачный)"
      - "solid":          "Сплошной цвет"
      - "gradient":       "Градиент"
      - "acrylic":        "Акрил"
      - "mica":           "Mica"
      - "mica_alt":       "Mica Alt"
      - "album_art_blur": "Размытая обложка альбома"
    - solidColor: "35 35 35"
      $name: Background color (RGB)
      $name:zh-CN: 背景颜色（RGB）
      $name:ru-RU: Цвет фона (RGB)
      $description: "Use '-1 -1 -1' for the system contrast color and '-2 -2 -2' for the album art color. You can also specify two colors separated by a $ symbol (e.g., '0 0 0$255 255 255') where the first color is for light theme and the second for dark theme."
      $description:zh-CN: "输入 '-1 -1 -1' 使用系统对比色，输入 '-2 -2 -2' 使用专辑封面颜色。也可以用 $ 分隔两组颜色（例如 '0 0 0$255 255 255'），前一组用于浅色主题，后一组用于深色主题。"
      $description:ru-RU: "Используйте '-1 -1 -1' для системного контрастного цвета, '-2 -2 -2' — для цвета обложки альбома. Также можно указать два цвета через символ $ (например, '0 0 0$255 255 255'), где первый цвет для светлой темы, второй для тёмной."
    - solidColor2: "35 35 35"
      $name: Gradient color 1 (RGB)
      $name:zh-CN: 渐变颜色 1（RGB）
      $name:ru-RU: Цвет градиента 1 (RGB)
    - gradientColor2: "128 128 128"
      $name: Gradient color 2 (RGB)
      $name:zh-CN: 渐变颜色 2（RGB）
      $name:ru-RU: Цвет градиента 2 (RGB)
    - solidOpacity: 100
      $name: Solid color opacity (0-100)
      $name:zh-CN: 纯色不透明度（0～100）
      $name:ru-RU: Прозрачность сплошного цвета (0-100)
    - gradientAngle: 50
      $name: Gradient rotation angle (0-360)
      $name:zh-CN: 渐变旋转角度（0～360）
      $name:ru-RU: Угол поворота градиента (0-360)
    - gradientBalance: 50
      $name: Gradient color balance (0-100)
      $name:zh-CN: 渐变颜色比例（0～100）
      $name:ru-RU: Градиентный цветовой баланс (0-100)
    - acrylicTintOpacity: 50
      $name: Acrylic tint opacity (0-100)
      $name:zh-CN: 亚克力着色不透明度（0～100）
      $name:ru-RU: Прозрачность акрилового оттенка (0-100)
    - micaOpacity: 50
      $name: Mica/Mica Alt opacity (0-100)
      $name:zh-CN: 云母/云母 Alt 不透明度（0～100）
      $name:ru-RU: "'Mica/Mica Alt' прозрачность (0-100)"
    - blurOpacity: 65
      $name: Album art blur opacity (0-100)
      $name:zh-CN: 模糊封面不透明度（0～100）
      $name:ru-RU: "'Размытая обложка альбома' прозрачность (0-100)"
    - blurRadius: 11
      $name: Album art blur strength (1-50)
      $name:zh-CN: 专辑封面模糊强度（1～50）
      $name:ru-RU: "'Размытая обложка альбома' Сила размытия (1-50)"
    - cornerRadius: "4"
      $name: Media player corner radius
      $name:zh-CN: 媒体播放器圆角半径
      $name:ru-RU: Радиус скругления медиаплеера
      $description: "Use single value (e.g., '4') for uniform corners, or four space-separated values (e.g., '4 2 4 2') for individual corners."
      $description:zh-CN: "输入一个值（例如 '4'）可统一设置四个圆角；也可输入四个以空格分隔的值（例如 '4 2 4 2'），分别设置四个圆角。"
      $description:ru-RU: "Используйте одно значение (например, '4') для одинаковых углов, или четыре значения через пробел (например, '4 2 4 2') для каждого угла отдельно."
    - enablePlayerHoverEffect: "auto"
      $name: Player hover effect
      $name:zh-CN: 播放器悬停效果
      $name:ru-RU: Эффект при наведении на плеер
      $options:
      - "auto":  "Auto (theme changes automatically)"
      - "black": "Black"
      - "white": "White"
      - "off":   "Disable hover effect"
      $options:zh-CN:
      - "auto":  "自动（随主题调整）"
      - "black": "黑色"
      - "white": "白色"
      - "off":   "关闭悬停效果"
      $options:ru-RU:
      - "auto":  "Авто (тема изменяется автоматически)"
      - "black": "Чёрный"
      - "white": "Белый"
      - "off":   "Выключить эффект наведения"
    - enableMediaButtonsHoverEffect: "auto"
      $name: Media buttons hover effect
      $name:zh-CN: 媒体控制按钮悬停效果
      $name:ru-RU: Эффект при наведении на кнопки управления
      $options:
      - "auto":  "Auto (theme changes automatically)"
      - "black": "Black"
      - "white": "White"
      - "off":   "Disable hover effect"
      $options:zh-CN:
      - "auto":  "自动（随主题调整）"
      - "black": "黑色"
      - "white": "白色"
      - "off":   "关闭悬停效果"
      $options:ru-RU:
      - "auto":  "Авто (тема изменяется автоматически)"
      - "black": "Чёрный"
      - "white": "Белый"
      - "off":   "Выключить эффект наведения"
    - enableHoverAnimation: true
      $name: Smooth hover animation
      $name:zh-CN: 平滑悬停动画
      $name:ru-RU: Плавная анимация наведения
      $description: >-
        Fades the hover/press background and border in and out. Disable this if you
        want an instant, non-animated hover effect, or if you're styling the player
        background with the Windows 11 Taskbar Styler mod and want it to react
        immediately.
      $description:zh-CN: >-
        让悬停或按下时的背景和边框平滑淡入淡出。如果希望悬停效果立即出现，
        或正在使用 Windows 11 Taskbar Styler 设置播放器背景并希望其立即响应，
        请关闭此项。
      $description:ru-RU: >-
        Плавно проявляет/скрывает фон и рамку при наведении/нажатии. Выключите, если
        нужен мгновенный эффект наведения без анимации, или если вы стилизуете фон
        плеера модом Windows 11 Taskbar Styler и хотите, чтобы он реагировал мгновенно.
    $name: Background Style
    $name:zh-CN: 背景样式
    $name:ru-RU: Стиль фона

  - MediaButtonsStyleSettings:
    - iconStyle: "fluent_outline"
      $name: Icon style
      $name:zh-CN: 图标样式
      $name:ru-RU: Вид иконок
      $options:
      - "fluent_outline": "Segoe Fluent Icons (Outline)"
      - "fluent_filled":  "Segoe Fluent Icons (Filled)"
      - "mdl2_outline":   "Segoe MDL2 Assets (Outline)"
      - "mdl2_filled":    "Segoe MDL2 Assets (Filled)"
      $options:zh-CN:
      - "fluent_outline": "Segoe Fluent Icons（轮廓）"
      - "fluent_filled":  "Segoe Fluent Icons（填充）"
      - "mdl2_outline":   "Segoe MDL2 Assets（轮廓）"
      - "mdl2_filled":    "Segoe MDL2 Assets（填充）"
      $options:ru-RU:
      - "fluent_outline": "Segoe Fluent Icons (Контур)"
      - "fluent_filled":  "Segoe Fluent Icons (Заполненный)"
      - "mdl2_outline":   "Segoe MDL2 Assets (Контур)"
      - "mdl2_filled":    "Segoe MDL2 Assets (Заполненный)"
    - buttonSpacing: 0
      $name: Spacing between media buttons
      $name:zh-CN: 媒体控制按钮间距
      $name:ru-RU: Расстояние между кнопками управления
    - buttonIconSize: 12
      $name: Button icon size
      $name:zh-CN: 按钮图标大小
      $name:ru-RU: Размер иконок кнопок
    - buttonCornerRadius: "4"
      $name: Media buttons corner radius
      $name:zh-CN: 媒体控制按钮圆角半径
      $name:ru-RU: Скругление кнопок управления
      $description: "Use single value (e.g., '4') for uniform corners, or four space-separated values (e.g., '4 2 4 2') for individual corners."
      $description:zh-CN: "输入一个值（例如 '4'）可统一设置四个圆角；也可输入四个以空格分隔的值（例如 '4 2 4 2'），分别设置四个圆角。"
      $description:ru-RU: "Используйте одно значение (например, '4') для одинаковых углов, или четыре значения через пробел (например, '4 2 4 2') для каждого угла отдельно."
    - buttonColor: "0 0 0$255 255 255"
      $name: Media buttons icons color (RGB)
      $name:zh-CN: 媒体控制按钮图标颜色（RGB）
      $name:ru-RU: Цвет иконок для кнопок управления (RGB)
      $description: "Use '-1 -1 -1' for the system contrast color and '-2 -2 -2' for the album art color. You can also specify two colors separated by a $ symbol (e.g., '0 0 0$255 255 255') where the first color is for light theme and the second for dark theme."
      $description:zh-CN: "输入 '-1 -1 -1' 使用系统对比色，输入 '-2 -2 -2' 使用专辑封面颜色。也可以用 $ 分隔两组颜色（例如 '0 0 0$255 255 255'），前一组用于浅色主题，后一组用于深色主题。"
      $description:ru-RU: "Используйте '-1 -1 -1' для системного контрастного цвета, '-2 -2 -2' — для цвета обложки альбома. Также можно указать два цвета через символ $ (например, '0 0 0$255 255 255'), где первый цвет для светлой темы, второй для тёмной."
    - buttonColorOpacity: 100
      $name: Media buttons icons opacity (0-100)
      $name:zh-CN: 媒体控制按钮图标不透明度（0～100）
      $name:ru-RU: Прозрачность иконок для кнопок управления (0-100)
    $name: Media Buttons Style
    $name:zh-CN: 媒体控制按钮样式
    $name:ru-RU: Стиль кнопок управления

  - TitleTextStyleSettings:
    - titleColor: "0 0 0$255 255 255"
      $name: Title color (RGB)
      $name:zh-CN: 标题颜色（RGB）
      $name:ru-RU: Цвет заголовка (RGB)
      $description: "Use '-1 -1 -1' for the system contrast color and '-2 -2 -2' for the album art color. You can also specify two colors separated by a $ symbol (e.g., '0 0 0$255 255 255') where the first color is for light theme and the second for dark theme."
      $description:zh-CN: "输入 '-1 -1 -1' 使用系统对比色，输入 '-2 -2 -2' 使用专辑封面颜色。也可以用 $ 分隔两组颜色（例如 '0 0 0$255 255 255'），前一组用于浅色主题，后一组用于深色主题。"
      $description:ru-RU: "Используйте '-1 -1 -1' для системного контрастного цвета, '-2 -2 -2' — для цвета обложки альбома. Также можно указать два цвета через символ $ (например, '0 0 0$255 255 255'), где первый цвет для светлой темы, второй для тёмной."
    - titleColorOpacity: 100
      $name: Title opacity (0-100)
      $name:zh-CN: 标题不透明度（0～100）
      $name:ru-RU: Прозрачность заголовка (0-100)
    - titleFont: segoe_ui_variable
      $name: Title font
      $name:zh-CN: 标题字体
      $name:ru-RU: Шрифт заголовка
      $options:
      - segoe_ui_variable: Segoe UI Variable Display
      - segoe_ui:          Segoe UI
      - aptos:             Aptos
      - calibri:           Calibri
      - cambria:           Cambria
      - candara:           Candara
      - consolas:          Consolas
      - corbel:            Corbel
      - arial:             Arial
      - trebuchet:         Trebuchet MS
      - verdana:           Verdana
      - tahoma:            Tahoma
      - georgia:           Georgia
      - times_new_roman:   Times New Roman
      - custom:            Custom...
      $options:zh-CN:
      - segoe_ui_variable: Segoe UI Variable Display
      - segoe_ui:          Segoe UI
      - aptos:             Aptos
      - calibri:           Calibri
      - cambria:           Cambria
      - candara:           Candara
      - consolas:          Consolas
      - corbel:            Corbel
      - arial:             Arial
      - trebuchet:         Trebuchet MS
      - verdana:           Verdana
      - tahoma:            Tahoma
      - georgia:           Georgia
      - times_new_roman:   Times New Roman
      - custom:            自定义……
      $options:ru-RU:
      - segoe_ui_variable: Segoe UI Variable Display
      - segoe_ui:          Segoe UI
      - aptos:             Aptos
      - calibri:           Calibri
      - cambria:           Cambria
      - candara:           Candara
      - consolas:          Consolas
      - corbel:            Corbel
      - arial:             Arial
      - trebuchet:         Trebuchet MS
      - verdana:           Verdana
      - tahoma:            Tahoma
      - georgia:           Georgia
      - times_new_roman:   Times New Roman
      - custom:            Другой...
    - titleFontSize: 12
      $name: Title font size
      $name:zh-CN: 标题字号
      $name:ru-RU: Размер шрифта заголовка
    - titleFontFamily: ""
      $name: Title font family (for Custom option)
      $name:zh-CN: 标题字体系列（用于“自定义”选项）
      $name:ru-RU: Семейство шрифтов заголовка (для варианта «Другой»)
      $description: >-
        For a list of fonts that are shipped with Windows 11, refer to the
        following page:
        https://learn.microsoft.com/en-us/typography/fonts/windows_11_font_list
      $description:zh-CN: >-
        Windows 11 自带字体列表请参阅：
        https://learn.microsoft.com/zh-cn/typography/fonts/windows_11_font_list
      $description:ru-RU: >-
        Список шрифтов, поставляемых с Windows 11, можно найти на следующей странице:
        https://learn.microsoft.com/en-us/typography/fonts/windows_11_font_list
    - titleFontWeight: ""
      $name: Title font weight
      $name:zh-CN: 标题字重
      $name:ru-RU: Насыщенность шрифта заголовка
      $options:
      - "":          Default
      - Thin:        Thin
      - ExtraLight:  Extra light
      - Light:       Light
      - SemiLight:   Semi light
      - Normal:      Normal
      - Medium:      Medium
      - SemiBold:    Semi bold
      - Bold:        Bold
      - ExtraBold:   Extra bold
      - Black:       Black
      - ExtraBlack:  Extra black
      $options:zh-CN:
      - "":          默认
      - Thin:        极细
      - ExtraLight:  特细
      - Light:       细体
      - SemiLight:   次细
      - Normal:      常规
      - Medium:      中等
      - SemiBold:    半粗
      - Bold:        粗体
      - ExtraBold:   特粗
      - Black:       黑体
      - ExtraBlack:  极粗
      $options:ru-RU:
      - "":          По умолчанию
      - Thin:        Тонкий
      - ExtraLight:  Очень тонкий
      - Light:       Тонкий
      - SemiLight:   Полутонкий
      - Normal:      Обычный
      - Medium:      Средний
      - SemiBold:    Полужирный
      - Bold:        Жирный
      - ExtraBold:   Очень жирный
      - Black:       Чёрный
      - ExtraBlack:  Сверхчёрный
    - titleFontStyle: ""
      $name: Title font style
      $name:zh-CN: 标题字体样式
      $name:ru-RU: Стиль шрифта заголовка
      $options:
      - "":       Default
      - Normal:   Normal
      - Oblique:  Oblique
      - Italic:   Italic
      $options:zh-CN:
      - "":       默认
      - Normal:   常规
      - Oblique:  倾斜
      - Italic:   斜体
      $options:ru-RU:
      - "":       По умолчанию
      - Normal:   Обычный
      - Oblique:  Наклонный
      - Italic:   Курсив
    - titleCharacterSpacing: 0
      $name: Title character spacing
      $name:zh-CN: 标题字符间距
      $name:ru-RU: Межсимвольный интервал заголовка
      $description: Can be a positive or a negative number.
      $description:zh-CN: 可以输入正数或负数。
      $description:ru-RU: Может быть положительным или отрицательным числом.
    $name: Title Text Style
    $name:zh-CN: 标题文本样式
    $name:ru-RU: Стиль текста заголовка

  - ArtistTextStyleSettings:
    - artistColor: "0 0 0$255 255 255"
      $name: Artist color (RGB)
      $name:zh-CN: 歌手名称颜色（RGB）
      $name:ru-RU: Цвет имени исполнителя (RGB)
      $description: "Use '-1 -1 -1' for system contrast color, '-2 -2 -2' for album art color. You can also specify two colors separated by a $ symbol (e.g., '0 0 0$255 255 255') where the first color is for light theme and the second for dark theme."
      $description:zh-CN: "输入 '-1 -1 -1' 使用系统对比色，输入 '-2 -2 -2' 使用专辑封面颜色。也可以用 $ 分隔两组颜色（例如 '0 0 0$255 255 255'），前一组用于浅色主题，后一组用于深色主题。"
      $description:ru-RU: "Используйте '-1 -1 -1' для системного контрастного цвета, '-2 -2 -2' — для цвета обложки альбома. Также можно указать два цвета через символ $ (например, '0 0 0$255 255 255'), где первый цвет для светлой темы, второй для тёмной."
    - artistColorOpacity: 80
      $name: Artist opacity (0-100)
      $name:zh-CN: 歌手名称不透明度（0～100）
      $name:ru-RU: Прозрачность имени исполнителя (0-100)
    - artistFont: segoe_ui_variable
      $name: Artist font
      $name:zh-CN: 歌手名称字体
      $name:ru-RU: Шрифт имени исполнителя
      $options:
      - segoe_ui_variable: Segoe UI Variable Display
      - segoe_ui:          Segoe UI
      - aptos:             Aptos
      - calibri:           Calibri
      - cambria:           Cambria
      - candara:           Candara
      - consolas:          Consolas
      - corbel:            Corbel
      - arial:             Arial
      - trebuchet:         Trebuchet MS
      - verdana:           Verdana
      - tahoma:            Tahoma
      - georgia:           Georgia
      - times_new_roman:   Times New Roman
      - custom:            Custom...
      $options:zh-CN:
      - segoe_ui_variable: Segoe UI Variable Display
      - segoe_ui:          Segoe UI
      - aptos:             Aptos
      - calibri:           Calibri
      - cambria:           Cambria
      - candara:           Candara
      - consolas:          Consolas
      - corbel:            Corbel
      - arial:             Arial
      - trebuchet:         Trebuchet MS
      - verdana:           Verdana
      - tahoma:            Tahoma
      - georgia:           Georgia
      - times_new_roman:   Times New Roman
      - custom:            自定义……
      $options:ru-RU:
      - segoe_ui_variable: Segoe UI Variable Display
      - segoe_ui:          Segoe UI
      - aptos:             Aptos
      - calibri:           Calibri
      - cambria:           Cambria
      - candara:           Candara
      - consolas:          Consolas
      - corbel:            Corbel
      - arial:             Arial
      - trebuchet:         Trebuchet MS
      - verdana:           Verdana
      - tahoma:            Tahoma
      - georgia:           Georgia
      - times_new_roman:   Times New Roman
      - custom:            Другой...
    - artistFontSize: 11
      $name: Artist font size
      $name:zh-CN: 歌手名称字号
      $name:ru-RU: Размер шрифта исполнителя
    - artistFontFamily: ""
      $name: Artist font family (for Custom option)
      $name:zh-CN: 歌手名称字体系列（用于“自定义”选项）
      $name:ru-RU: Семейство шрифтов исполнителя (для варианта «Другой»)
      $description: >-
        For a list of fonts that are shipped with Windows 11, refer to the
        following page:
        https://learn.microsoft.com/en-us/typography/fonts/windows_11_font_list
      $description:zh-CN: >-
        Windows 11 自带字体列表请参阅：
        https://learn.microsoft.com/zh-cn/typography/fonts/windows_11_font_list
      $description:ru-RU: >-
        Список шрифтов, поставляемых с Windows 11, можно найти на следующей странице:
        https://learn.microsoft.com/en-us/typography/fonts/windows_11_font_list
    - artistFontWeight: ""
      $name: Artist font weight
      $name:zh-CN: 歌手名称字重
      $name:ru-RU: Насыщенность шрифта исполнителя
      $options:
      - "":          Default
      - Thin:        Thin
      - ExtraLight:  Extra light
      - Light:       Light
      - SemiLight:   Semi light
      - Normal:      Normal
      - Medium:      Medium
      - SemiBold:    Semi bold
      - Bold:        Bold
      - ExtraBold:   Extra bold
      - Black:       Black
      - ExtraBlack:  Extra black
      $options:zh-CN:
      - "":          默认
      - Thin:        极细
      - ExtraLight:  特细
      - Light:       细体
      - SemiLight:   次细
      - Normal:      常规
      - Medium:      中等
      - SemiBold:    半粗
      - Bold:        粗体
      - ExtraBold:   特粗
      - Black:       黑体
      - ExtraBlack:  极粗
      $options:ru-RU:
      - "":          По умолчанию
      - Thin:        Тонкий
      - ExtraLight:  Очень тонкий
      - Light:       Тонкий
      - SemiLight:   Полутонкий
      - Normal:      Обычный
      - Medium:      Средний
      - SemiBold:    Полужирный
      - Bold:        Жирный
      - ExtraBold:   Очень жирный
      - Black:       Чёрный
      - ExtraBlack:  Сверхчёрный
    - artistFontStyle: ""
      $name: Artist font style
      $name:zh-CN: 歌手名称字体样式
      $name:ru-RU: Стиль шрифта исполнителя
      $options:
      - "":       Default
      - Normal:   Normal
      - Oblique:  Oblique
      - Italic:   Italic
      $options:zh-CN:
      - "":       默认
      - Normal:   常规
      - Oblique:  倾斜
      - Italic:   斜体
      $options:ru-RU:
      - "":       По умолчанию
      - Normal:   Обычный
      - Oblique:  Наклонный
      - Italic:   Курсив
    - artistCharacterSpacing: 0
      $name: Artist character spacing
      $name:zh-CN: 歌手名称字符间距
      $name:ru-RU: Межсимвольный интервал исполнителя
      $description: Can be a positive or a negative number.
      $description:zh-CN: 可以输入正数或负数。
      $description:ru-RU: Может быть положительным или отрицательным числом.
    $name: Artist Text Style
    $name:zh-CN: 歌手文本样式
    $name:ru-RU: Стиль текста исполнителя

  - AlbumArtDisplaySettings:
    - albumArtEmptyBehavior: "show"
      $name: Album art behavior when no cover available
      $name:zh-CN: 无封面时的显示方式
      $name:ru-RU: Поведение обложки при отсутствии изображения
      $options:
      - "show":          "Show area"
      - "hide":          "Hide area"
      - "show_icon":     "Show area with icon"
      $options:zh-CN:
      - "show":          "保留封面区域"
      - "hide":          "隐藏封面区域"
      - "show_icon":     "保留封面区域并显示图标"
      $options:ru-RU:
      - "show":          "Показать область"
      - "hide":          "Скрыть область"
      - "show_icon":     "Показать область со значком"
    - emptyIconGlyph: "E189"
      $name: Icon glyph code (hex)
      $name:zh-CN: 图标字符代码（十六进制）
      $name:ru-RU: Код символа значка (hex)
      $description: "Hex code of the glyph to show, e.g. 'E189' for music note. See https://learn.microsoft.com/en-us/windows/apps/design/iconography/segoe-ui-symbol-font"
      $description:zh-CN: "要显示的图标字符十六进制代码，例如音符图标为 'E189'。参阅 https://learn.microsoft.com/zh-cn/windows/apps/design/iconography/segoe-ui-symbol-font"
      $description:ru-RU: "Hex-код символа, например 'E189' для ноты. См. https://learn.microsoft.com/en-us/windows/apps/design/iconography/segoe-ui-symbol-font"
    - emptyIconSize: 16
      $name: Icon size
      $name:zh-CN: 图标大小
      $name:ru-RU: Размер значка
    - emptyIconFont: "segoe_fluent"
      $name: Icon font style
      $name:zh-CN: 图标字体
      $name:ru-RU: Стиль шрифта значка
      $options:
      - "segoe_fluent": "Segoe Fluent Icons"
      - "segoe_mdl2":   "Segoe MDL2 Assets"
      $options:zh-CN:
      - "segoe_fluent": "Segoe Fluent Icons"
      - "segoe_mdl2":   "Segoe MDL2 Assets"
      $options:ru-RU:
      - "segoe_fluent": "Segoe Fluent Icons"
      - "segoe_mdl2":   "Segoe MDL2 Assets"
    - emptyIconColor: "140 140 140"
      $name: Icon color (RGB)
      $name:zh-CN: 图标颜色（RGB）
      $name:ru-RU: Цвет значка (RGB)
      $description: "Use '-1 -1 -1' for the system accent color and '-2 -2 -2' for the album art color. You can also specify two colors separated by a $ symbol (e.g., '0 0 0$255 255 255') where the first color is for light theme and the second for dark theme."
      $description:zh-CN: "输入 '-1 -1 -1' 使用系统强调色，输入 '-2 -2 -2' 使用专辑封面颜色。也可以用 $ 分隔两组颜色（例如 '0 0 0$255 255 255'），前一组用于浅色主题，后一组用于深色主题。"
      $description:ru-RU: "Используйте '-1 -1 -1' для цвета акцента системы и '-2 -2 -2' для цвета обложки альбома. Также можно указать два цвета через символ $ (например, '0 0 0$255 255 255'), где первый цвет для светлой темы, второй для тёмной."
    - emptyIconOpacity: 100
      $name: Icon opacity (0-100)
      $name:zh-CN: 图标不透明度（0～100）
      $name:ru-RU: Прозрачность значка (0-100)
    - albumArtQuality: "high"
      $name: Album art quality
      $name:zh-CN: 专辑封面质量
      $name:ru-RU: Качество обложки альбома
      $options:
      - "low":    "Low (faster, less memory)"
      - "medium": "Medium (default)"
      - "high":   "High (best quality)"
      $options:zh-CN:
      - "low":    "低（速度更快、占用内存更少）"
      - "medium": "中（默认）"
      - "high":   "高（画质最佳）"
      $options:ru-RU:
      - "low":    "Низкое (быстрее, меньше памяти)"
      - "medium": "Среднее (по умолчанию)"
      - "high":   "Высокое (наилучшее качество)"
    - albumArtOpacity: 100
      $name: Album art opacity (0-100)
      $name:zh-CN: 专辑封面不透明度（0～100）
      $name:ru-RU: Прозрачность обложки альбома (0-100)
    - albumArtCornerRadius: "4"
      $name: Album art corner radius
      $name:zh-CN: 专辑封面圆角半径
      $name:ru-RU: Радиус скругления обложки альбома
      $description: "Use single value (e.g., '4') for uniform corners, or four space-separated values (e.g., '4 2 4 2') for individual corners."
      $description:zh-CN: "输入一个值（例如 '4'）可统一设置四个圆角；也可输入四个以空格分隔的值（例如 '4 2 4 2'），分别设置四个圆角。"
      $description:ru-RU: "Используйте одно значение (например, '4') для одинаковых углов, или четыре значения через пробел (например, '4 2 4 2') для каждого угла отдельно."
    - showAppIcon: false
      $name: Show media app icon overlay
      $name:zh-CN: 在封面上显示媒体应用图标
      $name:ru-RU: Показывать значок медиаприложения поверх обложки
    - appIconCorner: "bottom_right"
      $name: App icon corner
      $name:zh-CN: 应用图标位置
      $name:ru-RU: Угол размещения значка приложения
      $options:
      - "top_left":     "Top left"
      - "top_right":    "Top right"
      - "bottom_left":  "Bottom left"
      - "bottom_right": "Bottom right"
      $options:zh-CN:
      - "top_left":     "左上角"
      - "top_right":    "右上角"
      - "bottom_left":  "左下角"
      - "bottom_right": "右下角"
      $options:ru-RU:
      - "top_left":     "Верхний левый"
      - "top_right":    "Верхний правый"
      - "bottom_left":  "Нижний левый"
      - "bottom_right": "Нижний правый"
    - appIconSize: 12
      $name: App icon size
      $name:zh-CN: 应用图标大小
      $name:ru-RU: Размер значка приложения
    $name: Album Art Display
    $name:zh-CN: 专辑封面显示
    $name:ru-RU: Отображение обложки альбома

  - VisualizerStyleSettings:
    - vizColorMode: "dynamic_album"
      $name: Color mode
      $name:zh-CN: 颜色模式
      $name:ru-RU: Цветовой режим
      $options:
      - "solid": Solid
      - "dynamic_album": Dynamic album color
      - "dynamic_gradient": Dynamic gradient
      - "custom_gradient": Custom gradient
      - "acrylic": Acrylic
      $options:zh-CN:
      - "solid": 纯色
      - "dynamic_album": 动态专辑颜色
      - "dynamic_gradient": 动态渐变
      - "custom_gradient": 自定义渐变
      - "acrylic": 亚克力
      $options:ru-RU:
      - "solid": Сплошной
      - "dynamic_album": Динамический цвет альбома
      - "dynamic_gradient": Динамический градиент
      - "custom_gradient": Пользовательский градиент
      - "acrylic": Акрил
    - vizColor: "0 0 0$255 255 255"
      $name: Bar color (RGB)
      $name:zh-CN: 频谱柱颜色（RGB）
      $name:ru-RU: Цвет столбиков (RGB)
      $description: "Used by Solid and Acrylic modes. Use '-1 -1 -1' for the system accent color, '-2 -2 -2' for the album color. You can also specify two colors separated by a $ symbol (e.g., '0 0 0$255 255 255') where the first color is for light theme and the second for dark theme."
      $description:zh-CN: "用于纯色和亚克力模式。输入 '-1 -1 -1' 使用系统强调色，输入 '-2 -2 -2' 使用专辑颜色。也可以用 $ 分隔两组颜色（例如 '0 0 0$255 255 255'），前一组用于浅色主题，后一组用于深色主题。"
      $description:ru-RU: "Используется в режимах Сплошной и Акрил. Используйте '-1 -1 -1' для системного цвета акцента, '-2 -2 -2' для цвета альбома. Также можно указать два цвета через символ $ (например, '0 0 0$255 255 255'), где первый цвет для светлой темы, второй для тёмной."
    - vizColor1: "30 215 96"
      $name: Gradient color 1 (RGB)
      $name:zh-CN: 渐变颜色 1（RGB）
      $name:ru-RU: Цвет градиента 1 (RGB)
    - vizColor2: "0 180 255"
      $name: Gradient color 2 (RGB)
      $name:zh-CN: 渐变颜色 2（RGB）
      $name:ru-RU: Цвет градиента 2 (RGB)
    $name: Visualizer Style
    $name:zh-CN: 音频可视化样式
    $name:ru-RU: Стиль визуализатора
  $name: Appearance Settings
  $name:zh-CN: 外观设置
  $name:ru-RU: Настройки внешнего вида

- BehaviorSettings:
  - disableAlbumArtClick: true
    $name: Disable album art click (click through to player)
    $name:zh-CN: 禁用专辑封面点击（点击穿透到播放器）
    $name:ru-RU: Отключить клик по обложке (сквозной клик на плеер)
    $description: When enabled, clicks on the album art will pass through to the player area underneath
    $description:zh-CN: 启用后，点击专辑封面会穿透到其下方的播放器区域
    $description:ru-RU: Когда включено, клики по обложке альбома будут передаваться в область плеера под ней
  - ClickActionSettings:
      - - object: player
          $name: Object
          $name:zh-CN: 对象
          $name:ru-RU: Объект
          $options:
          - none:       Nothing
          - player:     Player area
          - album_art:  Album art area
          $options:zh-CN:
          - none:       无
          - player:     播放器区域
          - album_art:  专辑封面区域
          $options:ru-RU:
          - none:       Ничего
          - player:     Область плеера
          - album_art:  Область обложки альбома
        - click: left_double_click
          $name: Click type
          $name:zh-CN: 点击类型
          $name:ru-RU: Тип клика
          $options:
          - none:                Nothing
          - left_click:          Left click
          - left_double_click:   Left double click
          - right_click:         Right click
          - right_double_click:  Right double click
          - middle_click:        Middle click
          - middle_double_click: Middle double click
          $options:zh-CN:
          - none:                无
          - left_click:          左键单击
          - left_double_click:   左键双击
          - right_click:         右键单击
          - right_double_click:  右键双击
          - middle_click:        中键单击
          - middle_double_click: 中键双击
          $options:ru-RU:
          - none:                Ничего
          - left_click:          Левый клик
          - left_double_click:   Двойной левый клик
          - right_click:         Правый клик
          - right_double_click:  Двойной правый клик
          - middle_click:        Клик средней кнопкой
          - middle_double_click: Двойной клик средней кнопкой
        - action: play_pause
          $name: Action
          $name:zh-CN: 操作
          $name:ru-RU: Действие
          $options:
          - none:            Nothing
          - switch_session:  Switch active media session
          - play_pause:      Play/Pause
          - next_track:      Next track
          - prev_track:      Previous track
          - stop:            Stop playback
          - rewind_5s:       Rewind 5s
          - forward_5s:      Forward 5s
          - toggle_shuffle:  Toggle Shuffle
          - toggle_repeat:   Toggle Repeat
          - open_app:        Open media app
          - open_context_menu: Open context menu
          $options:zh-CN:
          - none:            无操作
          - switch_session:  切换当前媒体会话
          - play_pause:      播放/暂停
          - next_track:      下一曲
          - prev_track:      上一曲
          - stop:            停止播放
          - rewind_5s:       后退 5 秒
          - forward_5s:      快进 5 秒
          - toggle_shuffle:  切换随机播放
          - toggle_repeat:   切换循环模式
          - open_app:        打开媒体应用
          - open_context_menu: 打开右键菜单
          $options:ru-RU:
          - none:            Ничего
          - switch_session:  Переключить медиасессию
          - play_pause:      Воспроизведение/Пауза
          - next_track:      Следующий трек
          - prev_track:      Предыдущий трек
          - stop:            Остановить воспроизведение
          - rewind_5s:       Перемотка назад 5 сек
          - forward_5s:      Перемотка вперёд 5 сек
          - toggle_shuffle:  Случайный порядок
          - toggle_repeat:   Повтор
          - open_app:        Открыть медиаприложение
          - open_context_menu: Открыть контекстное меню
      - - object: player
        - click: right_click
        - action: open_context_menu
    $name: Click Actions
    $name:zh-CN: 点击操作
    $name:ru-RU: Действия при клике
  - MouseWheelActionSettings:
      - - object: player
          $name: Object
          $name:zh-CN: 对象
          $name:ru-RU: Объект
          $options:
          - none:       Nothing
          - player:     Player area
          - album_art:  Album art area
          $options:zh-CN:
          - none:       无
          - player:     播放器区域
          - album_art:  专辑封面区域
          $options:ru-RU:
          - none:       Ничего
          - player:     Область плеера
          - album_art:  Область обложки альбома
        - click: mouse_wheel
          $name: Mouse type
          $name:zh-CN: 鼠标操作类型
          $name:ru-RU: Тип мыши
          $options:
          - none:             Nothing
          - mouse_wheel:      Mouse wheel
          $options:zh-CN:
          - none:             无
          - mouse_wheel:      鼠标滚轮
          $options:ru-RU:
          - none:             Ничего
          - mouse_wheel:      Колесо мыши
        - action: switch_tracks
          $name: Action
          $name:zh-CN: 操作
          $name:ru-RU: Действие
          $options:
          - none:                      Nothing
          - "switch_tracks":           "Switch tracks"
          - "switch_tracks_inverted":  "Switch tracks (inverted)"
          - "switch_sessions":         "Switch sessions"
          - "system_sound":            "Change system sound volume"
          - "app_sound":               "Change app sound volume"
          $options:zh-CN:
          - none:                      无操作
          - "switch_tracks":           "切换曲目"
          - "switch_tracks_inverted":  "切换曲目（反向）"
          - "switch_sessions":         "切换媒体会话"
          - "system_sound":            "调整系统音量"
          - "app_sound":               "调整应用音量"
          $options:ru-RU:
          - none:                      Ничего
          - "switch_tracks":           "Переключить треки"
          - "switch_tracks_inverted":  "Переключить треки (инверсия)"
          - "switch_sessions":         "Переключить сессии"
          - "system_sound":            "Изменить громкость системы"
          - "app_sound":               "Изменить громкость приложения"
      - - object: album_art
        - click: mouse_wheel
        - action: switch_tracks
    $name: Mouse wheel Actions
    $name:zh-CN: 鼠标滚轮操作
    $name:ru-RU: Действия колеса мыши
  - hideWhenNoMedia: false
    $name: Hide when no media is playing
    $name:zh-CN: 无媒体播放时隐藏
    $name:ru-RU: Скрывать, когда ничего не воспроизводится
  - hideFullscreen: true
    $name: Hide when a fullscreen app is running
    $name:zh-CN: 全屏应用运行时隐藏
    $name:ru-RU: Скрывать при запущенном полноэкранном приложении
  - idleHideSeconds: 60
    $name: Idle auto-hide timeout (seconds, 0 = disabled)
    $name:zh-CN: 空闲自动隐藏等待时间（秒，0 表示禁用）
    $name:ru-RU: Таймаут автоскрытия при бездействии (секунды, 0 = отключено)
  - showFullTitleOnHover: true
    $name: Show full track title on hover (tooltip)
    $name:zh-CN: 悬停时显示完整曲名（工具提示）
    $name:ru-RU: Показывать полное название трека при наведении (подсказка)
  $name: Behavior Settings
  $name:zh-CN: 行为设置
  $name:ru-RU: Настройки поведения

- AnimationSettings:
  - enableSmoothPositionAnimation: true
    $name: Enable smooth position animation
    $name:zh-CN: 启用平滑位置动画
    $name:ru-RU: Включить плавную анимацию позиции
  $name: Animation Settings media player
  $name:zh-CN: 媒体播放器动画设置
  $name:ru-RU: Настройки анимации медиаплеера

- NotificationSettings:
  - showSuccessNotification: false
    $name: Show notification on successful mod load
    $name:zh-CN: 模组成功加载时显示通知
    $name:ru-RU: Показывать уведомление при успешной загрузке мода
    $description: Display a Windows notification when the mod is successfully loaded or reloaded
    $description:zh-CN: 模组成功加载或重新加载时显示 Windows 通知
    $description:ru-RU: Отображать уведомление Windows при успешной загрузке или перезагрузке мода
  $name: Notification Settings
  $name:zh-CN: 通知设置
  $name:ru-RU: Настройки уведомлений

- ContextMenuSettings:
  - contextMenuItems: [switch_sessions, open_app]
    $name: Context menu items
    $name:zh-CN: 右键菜单项目
    $name:ru-RU: Пункты контекстного меню
    $description: Select which items to show in the context menu and their order. Duplicates are ignored.
    $description:zh-CN: 选择右键菜单中显示的项目及其顺序，重复项目会被忽略。
    $description:ru-RU: Выберите, какие пункты отображать в контекстном меню, и их порядок. Дубликаты игнорируются.
    $options:
    - none:             Nothing
    - repeat:           Repeat
    - shuffle:          Shuffle
    - forward:          Forward 5s
    - rewind:           Rewind 5s
    - next:             Next Track
    - prev:             Previous Track
    - switch_sessions:  Switch Sessions
    - open_app:         Open media app
    $options:zh-CN:
    - none:             无
    - repeat:           循环模式
    - shuffle:          随机播放
    - forward:          快进 5 秒
    - rewind:           后退 5 秒
    - next:             下一曲
    - prev:             上一曲
    - switch_sessions:  切换媒体会话
    - open_app:         打开媒体应用
    $options:ru-RU:
    - none:             Ничего
    - repeat:           Повтор
    - shuffle:          Случайный порядок
    - forward:          Вперёд 5 сек
    - rewind:           Назад 5 сек
    - next:             Следующий трек
    - prev:             Предыдущий трек
    - switch_sessions:  Переключить сессию
    - open_app:         Открыть медиаприложение
  - repeatStyle: "submenu"
    $name: Repeat style
    $name:zh-CN: 循环模式菜单样式
    $name:ru-RU: Стиль повтора
    $options:
    - "submenu": "Submenu (Repeat off / Repeat all / Repeat one)"
    - "toggle":  "Toggle (cycle through modes)"
    $options:zh-CN:
    - "submenu": "子菜单（关闭循环/列表循环/单曲循环）"
    - "toggle":  "切换按钮（依次切换模式）"
    $options:ru-RU:
    - "submenu": "Подменю (Выкл / Все / Один)"
    - "toggle":  "Переключатель (цикл по режимам)"
  - shuffleStyle: "toggle"
    $name: Shuffle style
    $name:zh-CN: 随机播放菜单样式
    $name:ru-RU: Стиль случайного воспроизведения
    $options:
    - "submenu": "Submenu (Shuffle off / Shuffle on)"
    - "toggle":  "Toggle (single button)"
    $options:zh-CN:
    - "submenu": "子菜单（关闭随机播放/开启随机播放）"
    - "toggle":  "切换按钮（单个按钮）"
    $options:ru-RU:
    - "submenu": "Подменю (Выкл / Вкл)"
    - "toggle":  "Переключатель (одна кнопка)"
  - showOpenWindhawk: true
    $name: Show "Open Windhawk" button
    $name:zh-CN: 显示“打开 Windhawk”按钮
    $name:ru-RU: Показывать кнопку «Открыть Windhawk»
  - contextMenuIconStyle: "as_media_buttons"
    $name: Context menu icon style
    $name:zh-CN: 右键菜单图标样式
    $name:ru-RU: Стиль иконок контекстного меню
    $options:
    - "as_media_buttons": "Same as Media Buttons"
    - "fluent_outline":   "Segoe Fluent Icons (Outline)"
    - "fluent_filled":    "Segoe Fluent Icons (Filled)"
    - "mdl2_outline":     "Segoe MDL2 Assets (Outline)"
    - "mdl2_filled":      "Segoe MDL2 Assets (Filled)"
    $options:zh-CN:
    - "as_media_buttons": "与媒体控制按钮相同"
    - "fluent_outline":   "Segoe Fluent 图标（轮廓）"
    - "fluent_filled":    "Segoe Fluent 图标（填充）"
    - "mdl2_outline":     "Segoe MDL2 Assets（轮廓）"
    - "mdl2_filled":      "Segoe MDL2 Assets（填充）"
    $options:ru-RU:
    - "as_media_buttons": "Как у кнопок управления"
    - "fluent_outline":   "Segoe Fluent Icons (Контур)"
    - "fluent_filled":    "Segoe Fluent Icons (Заполненный)"
    - "mdl2_outline":     "Segoe MDL2 Assets (Контур)"
    - "mdl2_filled":      "Segoe MDL2 Assets (Заполненный)"
  - contextMenuIconColor: "0 0 0$255 255 255"
    $name: Context menu icons color (RGB)
    $name:zh-CN: 右键菜单图标颜色（RGB）
    $name:ru-RU: Цвет иконок контекстного меню (RGB)
    $description: "Use '-1 -1 -1' for the system contrast color and '-2 -2 -2' for the album art color. You can also specify two colors separated by a $ symbol (e.g., '0 0 0$255 255 255') where the first color is for light theme and the second for dark theme. Leave empty to use the Media Buttons color."
    $description:zh-CN: "使用 '-1 -1 -1' 表示系统对比色，使用 '-2 -2 -2' 表示专辑封面颜色。也可以用 $ 符号分隔两种颜色（例如 '0 0 0$255 255 255'），第一种用于浅色主题，第二种用于深色主题。留空则使用媒体控制按钮的颜色。"
    $description:ru-RU: "Используйте '-1 -1 -1' для системного контрастного цвета, '-2 -2 -2' — для цвета обложки альбома. Также можно указать два цвета через $ (например, '0 0 0$255 255 255'). Оставьте пустым, чтобы использовать цвет кнопок управления."
  - contextMenuIconOpacity: 100
    $name: Context menu icons opacity (0-100)
    $name:zh-CN: 右键菜单图标不透明度（0-100）
    $name:ru-RU: Прозрачность иконок контекстного меню (0-100)
  $name: Context Menu Settings
  $name:zh-CN: 右键菜单设置
  $name:ru-RU: Настройки контекстного меню

- DebugSettings:
  - ignoredProcesses: "chrome;msedge;firefox;brave;opera;vivaldi;zen"
    $name: Ignore media from processes (separate with ; )
    $name:zh-CN: 忽略来自指定进程的媒体（用 ; 分隔）
    $name:ru-RU: Игнорировать медиа от процессов (разделять через ; )
  - enableTreeDump: false
    $name: Dump XAML element names to log on inject
    $name:zh-CN: 注入时将 XAML 元素名称写入日志
    $name:ru-RU: Записывать имена XAML-элементов в лог при инъекции
  - showDebugBorders: false
    $name: Show debug borders
    $name:zh-CN: 显示调试边框
    $name:ru-RU: Показывать отладочные границы
  - showLayoutAnchors: false
    $name: Show layout anchors and centers
    $name:zh-CN: 显示布局锚点和中心点
    $name:ru-RU: Показывать якоря и центры разметки
  - showRestartButton: false
    $name: Show Restart Player in context menu
    $name:zh-CN: 在右键菜单中显示“重启播放器”
    $name:ru-RU: Показывать кнопку перезагрузки плеера в контекстном меню
  $name: Debug Settings
  $name:zh-CN: 调试设置
  $name:ru-RU: Настройки отладки
*/
// ==/WindhawkModSettings==

#undef GetCurrentTime
#include <winrt/base.h>
#include <winrt/Windows.Foundation.h>
#include <winrt/Windows.Foundation.Collections.h>
#include <winrt/Windows.UI.Core.h>
#include <winrt/Windows.UI.Text.h>
#include <winrt/Windows.UI.Input.h>
#include <winrt/Windows.UI.Xaml.h>
#include <winrt/Windows.UI.Xaml.Controls.Primitives.h>
#include <winrt/Windows.UI.Xaml.Controls.h>
#include <winrt/Windows.UI.Xaml.Media.h>
#include <winrt/Windows.UI.Xaml.Media.Imaging.h>
#include <winrt/Windows.UI.Xaml.Shapes.h>
#include <winrt/Windows.UI.Xaml.Media.Animation.h>
#include <winrt/Windows.UI.Xaml.Markup.h>
#include <winrt/Windows.UI.Xaml.Interop.h>
#include <winrt/Windows.UI.Xaml.Input.h>
#include <winrt/Windows.UI.Xaml.Automation.h>
#include <winrt/Windows.UI.Xaml.Hosting.h>
#include <winrt/Windows.UI.Composition.h>
#include <winrt/Windows.UI.ViewManagement.h>
#include <winrt/Windows.Media.Control.h>
#include <winrt/Windows.Data.Json.h>
#include <winrt/Windows.Storage.Streams.h>
#include <winrt/Windows.Graphics.Imaging.h>
#include <robuffer.h>
#include <shcore.h>
#include <windows.h>
#include <bcrypt.h>
#include <winhttp.h>
#include <shellapi.h>
#include <shlobj.h>
#include <shlwapi.h>
#include <shobjidl.h>
#include <oleacc.h>
#include <UIAutomation.h>
#include <commoncontrols.h>
#include <wincodec.h>
#include <propsys.h>
#include <dwmapi.h>
#include <windhawk_utils.h>
#include <audiopolicy.h>
#include <mmdeviceapi.h>
#include <endpointvolume.h>
#include <audioclient.h>
#include <propkey.h>
#include <tlhelp32.h>
#include <atomic>
#include <functional>
#include <memory>
#include <utility>
#include <mutex>
#include <string>
#include <string_view>
#include <vector>
#include <optional>
#include <set>
#include <algorithm>
#include <thread>
#include <fstream>
#include <filesystem>
#include <cmath>
#include <chrono>
#include <cstdlib>
using namespace winrt::Windows::UI::Xaml;
using namespace winrt::Windows::UI::Xaml::Controls;
using namespace winrt::Windows::UI::Xaml::Media;
using namespace winrt::Windows::UI::Xaml::Media::Imaging;
using namespace winrt::Windows::UI::Xaml::Media::Animation;
using namespace winrt::Windows::UI::Xaml::Input;
using namespace winrt::Windows::Media::Control;
using namespace winrt::Windows::Storage::Streams;
enum class VizShape { Stereo, Mountain, Mirror, Wave, Breathe };
enum class VizColorMode { Solid, DynamicAlbum, DynamicGradient, CustomGradient, Acrylic };
enum class VizEQ { Default, Bass, Rock, Pop, Jazz, Electronic };
enum class VizAnchor { Top, Middle, Bottom };
enum class PlayerKind : int {
    Netease = 0,
    TwilightEcho = 1,
};
static std::atomic<PlayerKind> g_selectedPlayer{PlayerKind::Netease};
static constexpr wchar_t kSelectedPlayerValueName[] = L"SelectedPlayerKind";
static constexpr int kTaskbarLyricsWidth = 312;
struct ModSettings {
    std::wstring uiLanguage          = L"system";
    std::wstring neteaseExecutablePath = L"D:\\CloudMusic\\cloudmusic.exe";
    std::wstring twilightExecutablePath = L"D:\\TwilightEcho\\TwilightEcho.exe";
    int          monitor              = 1;
    std::wstring position             = L"taskbar_right_start";
    std::wstring albumArtLeftClick    = L"none";
    std::wstring albumArtRightClick   = L"none";
    std::wstring albumArtMiddleClick  = L"none";
    std::wstring albumArtLeftDoubleClick  = L"none";
    std::wstring albumArtRightDoubleClick = L"none";
    std::wstring albumArtMiddleDoubleClick = L"none";
    std::wstring albumArtWheelAction  = L"none";
    std::wstring playerLeftClick      = L"none";
    std::wstring playerRightClick     = L"none";
    std::wstring playerMiddleClick    = L"none";
    std::wstring playerLeftDoubleClick  = L"none";
    std::wstring playerRightDoubleClick = L"none";
    std::wstring playerMiddleDoubleClick = L"none";
    std::wstring playerWheelAction    = L"none";
    bool         mirrorLayout         = false;
    bool         fullHeightHitArea    = true;
    bool         autoSwitchSession    = true;
    bool         showMediaButtons     = true;
    int          playerMinWidth       = 0;
    int          playerMaxWidth       = 0;
    int          playerMinHeight      = 40;
    int          playerMaxHeight      = 40;
    bool         showAlbumArt         = true;
    std::wstring albumArtEmptyBehavior = L"show";
    std::wstring emptyIconGlyph       = L"E189";
    int          emptyIconSize        = 16;
    std::wstring emptyIconFont        = L"segoe_fluent";
    std::wstring emptyIconColor       = L"255 255 255";
    int          emptyIconOpacity     = 100;
    std::wstring albumArtQuality      = L"high";
    int          albumArtMinWidth     = 32;
    int          albumArtMaxWidth     = 64;
    int          albumArtMinHeight    = 32;
    int          albumArtMaxHeight    = 32;
    int          albumArtOpacity      = 100;
    int          albumArtLeftMargin   = 0;
    int          albumArtRightMargin  = 0;
    std::wstring taskbarTextMode      = L"lyrics";
    bool         showNeteaseLyrics    = true;
    bool         showFullTitleOnHover = true;
    bool         showTrackArtist      = false;
    bool         swapTitleArtist      = false;
    std::wstring emptyTitleText       = L"Untitled";
    std::wstring noMediaTitleText     = L"Not Playing";
    std::wstring emptyArtistText      = L"";
    std::wstring noMediaArtistText    = L"";
    std::wstring iconStyle            = L"fluent_outline";
    bool         showAppIcon          = false;
    std::wstring appIconCorner        = L"bottom_right";
    int          appIconSize          = 12;
    bool         hideWhenNoMedia      = false;
    std::wstring playerHoverEffectMode = L"auto";
    std::wstring mediaButtonsHoverEffectMode = L"auto";
    bool         enableHoverAnimation = true;
    bool         enableSmoothPositionAnimation = true;
    int          playerMarginLeft     = 4;
    int          playerMarginRight    = 4;
    int          mediaButtonsLeftMargin  = 2;
    int          mediaButtonsRightMargin = 2;
    int          textAreaMinWidth     = 260;
    int          textAreaMaxWidth     = 260;
    int          textAreaMinHeight    = 0;
    int          textAreaMaxHeight    = 0;
    int          textAreaLeftMargin   = 5;
    int          textAreaRightMargin  = 5;
    bool         hideFullscreen       = true;
    int          idleHideSeconds      = 60;
    std::wstring backgroundType       = L"none";
    int          blurOpacity          = 65;
    int          blurRadius           = 11;
    double       cornerRadiusTL       = 4;
    double       cornerRadiusTR       = 4;
    double       cornerRadiusBR       = 4;
    double       cornerRadiusBL       = 4;
    double       albumArtCornerRadiusTL = 4;
    double       albumArtCornerRadiusTR = 4;
    double       albumArtCornerRadiusBR = 4;
    double       albumArtCornerRadiusBL = 4;
    int          buttonSpacing        = 0;
    int          buttonSize           = 28;
    int          buttonIconSize       = 12;
    double       buttonCornerRadiusTL = 4;
    double       buttonCornerRadiusTR = 4;
    double       buttonCornerRadiusBR = 4;
    double       buttonCornerRadiusBL = 4;
    int          titleFontSize        = 12;
    int          artistFontSize       = 11;
    std::wstring titleFont            = L"segoe_ui_variable";
    std::wstring artistFont           = L"segoe_ui_variable";
    std::wstring titleFontFamily      = L"";
    std::wstring artistFontFamily     = L"";
    std::wstring titleFontWeight      = L"";
    std::wstring artistFontWeight     = L"";
    std::wstring titleFontStyle       = L"";
    std::wstring artistFontStyle      = L"";
    int          titleCharacterSpacing  = 0;
    int          artistCharacterSpacing = 0;
    int          textSpacing          = -1;
    bool         enableArtistScrolling = false;
    bool         enableTitleScrolling = true;
    int          scrollSpeed          = 1;
    int          scrollPauseDuration  = 1000;
    std::wstring scrollMode           = L"bounce";
    int          loopGap              = 40;
    std::wstring solidColor           = L"35 35 35";
    std::wstring solidColor2          = L"35 35 35";
    std::wstring gradientColor2       = L"128 128 128";
    int          solidOpacity         = 100;
    int          gradientAngle        = 50;
    int          gradientBalance      = 50;
    int          acrylicTintOpacity   = 50;
    int          micaOpacity          = 50;
    std::wstring buttonColor          = L"255 255 255";
    int          buttonColorOpacity   = 100;
    std::wstring titleColor           = L"255 255 255";
    int          titleColorOpacity    = 100;
    std::wstring artistColor          = L"255 255 255";
    int          artistColorOpacity   = 80;
    std::wstring ignoredProcesses     = L"chrome;msedge;firefox;brave;opera;vivaldi;zen";
    bool         enableTreeDump       = false;
    bool         showDebugBorders     = false;
    bool         showLayoutAnchors    = false;
    bool         showRestartButton    = false;
    bool         showSuccessNotification = false;
    bool         hideUnsupportedButtons  = false;
    bool         disableAlbumArtClick    = true;
    std::vector<std::wstring> contextMenuItems;
    std::wstring contextMenuRepeatStyle   = L"submenu";
    std::wstring contextMenuShuffleStyle  = L"submenu";
    bool         showOpenWindhawk         = true;
    std::wstring contextMenuIconStyle     = L"as_media_buttons";
    std::wstring contextMenuIconColor     = L"255 255 255";
    int          contextMenuIconOpacity   = 100;
    bool         vizEnabled      = true;
    std::wstring vizPosition     = L"right";
    VizShape     vizShape        = VizShape::Stereo;
    VizColorMode vizColorMode    = VizColorMode::DynamicAlbum;
    VizEQ        vizEq           = VizEQ::Default;
    VizAnchor    vizAnchor       = VizAnchor::Middle;
    std::wstring vizColor        = L"255 255 255";
    std::wstring vizColor1       = L"30 215 96";
    std::wstring vizColor2       = L"0 180 255";
    int          vizBars         = 7;
    int          vizBarWidth     = 5;
    int          vizBarGap       = 5;
    int          vizIdleBarSize  = 1;
    int          vizSensitivity  = 200;
    int          vizPadLeft      = 0;
    int          vizPadRight     = 0;
};
static ModSettings g_settings;

static bool UseChineseUi() {
    if (g_settings.uiLanguage == L"zh-CN") return true;
    if (g_settings.uiLanguage == L"en-US") return false;
    return PRIMARYLANGID(GetUserDefaultUILanguage()) == LANG_CHINESE;
}

static const wchar_t* UiText(const wchar_t* english,
                             const wchar_t* simplifiedChinese) {
    return UseChineseUi() ? simplifiedChinese : english;
}

static std::wstring UiConfiguredText(const std::wstring& value,
                                     const wchar_t* englishDefault,
                                     const wchar_t* simplifiedChineseDefault) {
    if (UseChineseUi() && value == englishDefault) {
        return simplifiedChineseDefault;
    }
    return value;
}

static void ParseTwoInts(const std::wstring& s, int& a, int& b) {
    size_t sp = s.find(L' ');
    if (sp == std::wstring::npos) return;
    try {
        a = std::stoi(s.substr(0, sp));
        b = std::stoi(s.substr(sp + 1));
    } catch (...) {}
}
enum class MediaButtonType {
    Previous = 1,
    PlayPause = 2,
    Next = 3,
    Rewind5s = 4,
    Forward5s = 5,
    Shuffle = 6,
    Repeat = 7,
    SwitchSessions = 8,
    Heart = 9,
};
struct MediaButtonDefinition {
    std::wstring keyword;
    MediaButtonType type;
    int cmd;
};
static const std::vector<MediaButtonDefinition> g_mediaButtonDefinitions = {
    {L"prev", MediaButtonType::Previous, 1},
    {L"play", MediaButtonType::PlayPause, 2},
    {L"next", MediaButtonType::Next, 3},
    {L"rewind", MediaButtonType::Rewind5s, 5},
    {L"forward", MediaButtonType::Forward5s, 6},
    {L"shuffle", MediaButtonType::Shuffle, 7},
    {L"repeat", MediaButtonType::Repeat, 8},
    {L"switch_sessions", MediaButtonType::SwitchSessions, 9},
    {L"heart", MediaButtonType::Heart, 13},
};
struct MediaButtonConfig {
    MediaButtonType type;
    int cmd;
};
static std::vector<MediaButtonConfig> g_mediaButtons;
static std::mutex g_mediaButtonsMutex;
static std::wstring MapFontName(const std::wstring& key) {
    if (key == L"custom") return L"";
    if (key == L"segoe_ui_variable") return L"Segoe UI Variable Display";
    if (key == L"segoe_ui") return L"Segoe UI";
    if (key == L"segoe_ui_semibold") return L"Segoe UI Semibold";
    if (key == L"segoe_ui_bold") return L"Segoe UI Bold";
    if (key == L"segoe_ui_light") return L"Segoe UI Light";
    if (key == L"segoe_ui_semilight") return L"Segoe UI Semilight";
    if (key == L"aptos") return L"Aptos";
    if (key == L"calibri") return L"Calibri";
    if (key == L"cambria") return L"Cambria";
    if (key == L"candara") return L"Candara";
    if (key == L"consolas") return L"Consolas";
    if (key == L"corbel") return L"Corbel";
    if (key == L"arial") return L"Arial";
    if (key == L"trebuchet") return L"Trebuchet MS";
    if (key == L"verdana") return L"Verdana";
    if (key == L"tahoma") return L"Tahoma";
    if (key == L"georgia") return L"Georgia";
    if (key == L"times_new_roman") return L"Times New Roman";
    return L"Segoe UI Variable Display";
}
static void LoadSettings() {
    auto Str = [](const wchar_t* key, const wchar_t* def) -> std::wstring {
        PCWSTR p = Wh_GetStringSetting(key);
        std::wstring r = (*p != L'\0') ? p : def;
        Wh_FreeStringSetting(p);
        return r;
    };
    auto StrAllowEmpty = [](const wchar_t* key) -> std::wstring {
        PCWSTR p = Wh_GetStringSetting(key);
        std::wstring r = p ? p : L"";
        Wh_FreeStringSetting(p);
        return r;
    };
    auto Int = [](const wchar_t* key, int lo, int hi, int /*def*/) -> int {
        return std::clamp(Wh_GetIntSetting(key), lo, hi);
    };
    auto ParseMargin = [&Str](const wchar_t* key, const wchar_t* def, int& left, int& right) {
        std::wstring val = Str(key, def);
        try {
            size_t space = val.find(L' ');
            if (space != std::wstring::npos) {
                left  = std::stoi(val.substr(0, space));
                right = std::stoi(val.substr(space + 1));
            } else if (!val.empty()) {
                left = right = std::stoi(val);
            }
        } catch (...) {
            std::wstring d(def);
            size_t space = d.find(L' ');
            try {
                if (space != std::wstring::npos) {
                    left  = std::stoi(d.substr(0, space));
                    right = std::stoi(d.substr(space + 1));
                } else {
                    left = right = std::stoi(d);
                }
            } catch (...) { left = right = 0; }
        }
    };
    auto ParseCornerRadius = [&Str](const wchar_t* key, const wchar_t* def, double& tl, double& tr, double& br, double& bl) {
        std::wstring val = Str(key, def);
        std::vector<double> values;
        try {
            size_t pos = 0;
            while (pos < val.length()) {
                size_t space = val.find(L' ', pos);
                if (space == std::wstring::npos) space = val.length();
                std::wstring part = val.substr(pos, space - pos);
                if (!part.empty()) {
                    double v = std::stod(part);
                    values.push_back(v < 0.0 ? 0.0 : v);
                }
                pos = space + 1;
            }
        } catch (...) {}
        if (values.empty()) {
            try {
                std::wstring d(def);
                double v = std::stod(d);
                values.push_back(v < 0.0 ? 0.0 : v);
            } catch (...) {
                values.push_back(4.0);
            }
        }
        if (values.size() == 1) {
            tl = tr = br = bl = values[0];
        } else if (values.size() == 4) {
            tl = values[0];
            tr = values[1];
            br = values[2];
            bl = values[3];
        } else {
            tl = tr = br = bl = values[0];
        }
    };
    auto HoverMode = [&Str](const wchar_t* key) -> std::wstring {
        std::wstring mode = Str(key, L"auto");
        if (mode == L"black") return L"black";
        if (mode == L"white") return L"white";
        if (mode == L"off")   return L"off";
        return L"auto";
    };
    g_settings.uiLanguage = Str(L"LanguageSettings.language", L"system");
    if (g_settings.uiLanguage != L"system" &&
        g_settings.uiLanguage != L"zh-CN" &&
        g_settings.uiLanguage != L"en-US") {
        g_settings.uiLanguage = L"system";
    }
    g_settings.neteaseExecutablePath = Str(
        L"AppIntegrationSettings.neteaseExecutablePath",
        L"D:\\CloudMusic\\cloudmusic.exe");
    g_settings.twilightExecutablePath = Str(
        L"AppIntegrationSettings.twilightExecutablePath",
        L"D:\\TwilightEcho\\TwilightEcho.exe");
    g_settings.monitor               = std::max(1, Wh_GetIntSetting(L"MainSettings.PlayerSetting.monitor"));
    g_settings.position             = Str(L"MainSettings.PlayerSetting.position",    L"taskbar_right_start");
    ParseMargin(L"MainSettings.PlayerSetting.playerMargin", L"4 4", g_settings.playerMarginLeft, g_settings.playerMarginRight);
    ParseMargin(L"MainSettings.PlayerSetting.playerWidth", L"0 0", g_settings.playerMinWidth, g_settings.playerMaxWidth);
    ParseMargin(L"MainSettings.PlayerSetting.playerHeight", L"40 40", g_settings.playerMinHeight, g_settings.playerMaxHeight);
    ParseMargin(L"MainSettings.AlbumArtSetting.albumArtWidth", L"32 64", g_settings.albumArtMinWidth, g_settings.albumArtMaxWidth);
    ParseMargin(L"MainSettings.AlbumArtSetting.albumArtHeight", L"32 32", g_settings.albumArtMinHeight, g_settings.albumArtMaxHeight);
    ParseMargin(L"MainSettings.AlbumArtSetting.albumArtMargin", L"0 0", g_settings.albumArtLeftMargin, g_settings.albumArtRightMargin);
    ParseMargin(L"MainSettings.TextAreaSetting.textAreaWidth", L"260 260", g_settings.textAreaMinWidth, g_settings.textAreaMaxWidth);
    ParseMargin(L"MainSettings.TextAreaSetting.textAreaHeight", L"0 0", g_settings.textAreaMinHeight, g_settings.textAreaMaxHeight);
    ParseMargin(L"MainSettings.TextAreaSetting.textAreaMargin", L"5 5", g_settings.textAreaLeftMargin, g_settings.textAreaRightMargin);
    g_settings.mirrorLayout         = Wh_GetIntSetting(L"MainSettings.PlayerSetting.mirrorLayout") != 0;
    g_settings.fullHeightHitArea    = Wh_GetIntSetting(L"MainSettings.PlayerSetting.fullHeightHitArea") != 0;
    g_settings.autoSwitchSession    = Wh_GetIntSetting(L"MainSettings.PlayerSetting.autoSwitchSession") != 0;
    g_settings.showMediaButtons     = Wh_GetIntSetting(L"MainSettings.MediaButtonsSettings.showMediaButtons") != 0;
    ParseMargin(L"MainSettings.MediaButtonsSettings.mediaButtonsMargin", L"2 2", g_settings.mediaButtonsLeftMargin, g_settings.mediaButtonsRightMargin);
    g_settings.taskbarTextMode      = Str(L"MainSettings.TextAreaSetting.taskbarTextMode", L"lyrics");
    if (g_settings.taskbarTextMode != L"title") {
        g_settings.taskbarTextMode = L"lyrics";
    }
    g_settings.showNeteaseLyrics    = g_settings.taskbarTextMode == L"lyrics";
    g_settings.showFullTitleOnHover = Wh_GetIntSetting(L"BehaviorSettings.showFullTitleOnHover") != 0;
    g_settings.showTrackArtist      = Wh_GetIntSetting(L"MainSettings.TextAreaSetting.showTrackArtist")   != 0;
    g_settings.swapTitleArtist      = Wh_GetIntSetting(L"MainSettings.TextAreaSetting.swapTitleArtist")   != 0;
    g_settings.emptyTitleText       = StrAllowEmpty(L"MainSettings.TextAreaSetting.emptyTitleText");
    g_settings.noMediaTitleText     = StrAllowEmpty(L"MainSettings.TextAreaSetting.noMediaTitleText");
    g_settings.emptyArtistText      = StrAllowEmpty(L"MainSettings.TextAreaSetting.emptyArtistText");
    g_settings.noMediaArtistText    = StrAllowEmpty(L"MainSettings.TextAreaSetting.noMediaArtistText");
    g_settings.showAlbumArt         = Wh_GetIntSetting(L"MainSettings.AlbumArtSetting.showAlbumArt")      != 0;
    g_settings.albumArtEmptyBehavior = Str(L"AppearanceSettings.AlbumArtDisplaySettings.albumArtEmptyBehavior", L"show");
    g_settings.emptyIconGlyph       = Str(L"AppearanceSettings.AlbumArtDisplaySettings.emptyIconGlyph",       L"E189");
    g_settings.emptyIconSize        = Int(L"AppearanceSettings.AlbumArtDisplaySettings.emptyIconSize",          1, 256, 16);
    g_settings.emptyIconFont        = Str(L"AppearanceSettings.AlbumArtDisplaySettings.emptyIconFont",        L"segoe_fluent");
    g_settings.emptyIconColor       = Str(L"AppearanceSettings.AlbumArtDisplaySettings.emptyIconColor",       L"255 255 255");
    g_settings.emptyIconOpacity     = Int(L"AppearanceSettings.AlbumArtDisplaySettings.emptyIconOpacity",       0, 100, 100);
    g_settings.albumArtQuality      = Str(L"AppearanceSettings.AlbumArtDisplaySettings.albumArtQuality", L"high");
    g_settings.iconStyle            = Str(L"AppearanceSettings.MediaButtonsStyleSettings.iconStyle", L"fluent_outline");
    g_settings.showAppIcon          = Wh_GetIntSetting(L"AppearanceSettings.AlbumArtDisplaySettings.showAppIcon")       != 0;
    g_settings.appIconCorner        = Str(L"AppearanceSettings.AlbumArtDisplaySettings.appIconCorner",  L"bottom_right");
    g_settings.appIconSize          = Int(L"AppearanceSettings.AlbumArtDisplaySettings.appIconSize",         8,  32,  12);
    g_settings.backgroundType       = Str(L"AppearanceSettings.BackgroundStyleSettings.backgroundType", L"none");
    g_settings.blurOpacity          = Int(L"AppearanceSettings.BackgroundStyleSettings.blurOpacity",           0, 100, 65);
    g_settings.blurRadius           = Int(L"AppearanceSettings.BackgroundStyleSettings.blurRadius",            1,  50,  11);
    ParseCornerRadius(L"AppearanceSettings.BackgroundStyleSettings.cornerRadius", L"4",
                    g_settings.cornerRadiusTL, g_settings.cornerRadiusTR,
                    g_settings.cornerRadiusBR, g_settings.cornerRadiusBL);
    g_settings.albumArtOpacity      = Int(L"AppearanceSettings.AlbumArtDisplaySettings.albumArtOpacity",       0, 100, 100);
    ParseCornerRadius(L"AppearanceSettings.AlbumArtDisplaySettings.albumArtCornerRadius", L"4",
                    g_settings.albumArtCornerRadiusTL, g_settings.albumArtCornerRadiusTR,
                    g_settings.albumArtCornerRadiusBR, g_settings.albumArtCornerRadiusBL);
    g_settings.buttonSpacing        = Wh_GetIntSetting(L"AppearanceSettings.MediaButtonsStyleSettings.buttonSpacing");
    g_settings.buttonSize           = Int(L"MainSettings.MediaButtonsSettings.buttonSize",          16,  48,  28);
    g_settings.buttonIconSize       = Int(L"AppearanceSettings.MediaButtonsStyleSettings.buttonIconSize",       8,  32,  12);
    ParseCornerRadius(L"AppearanceSettings.MediaButtonsStyleSettings.buttonCornerRadius", L"4",
                    g_settings.buttonCornerRadiusTL, g_settings.buttonCornerRadiusTR,
                    g_settings.buttonCornerRadiusBR, g_settings.buttonCornerRadiusBL);
    g_settings.titleFontSize        = Int(L"AppearanceSettings.TitleTextStyleSettings.titleFontSize",         7,  24,  12);
    g_settings.titleFont            = MapFontName(Str(L"AppearanceSettings.TitleTextStyleSettings.titleFont", L"segoe_ui_variable"));
    g_settings.titleFontFamily      = Str(L"AppearanceSettings.TitleTextStyleSettings.titleFontFamily", L"");
    g_settings.titleFontWeight      = Str(L"AppearanceSettings.TitleTextStyleSettings.titleFontWeight", L"");
    g_settings.titleFontStyle       = Str(L"AppearanceSettings.TitleTextStyleSettings.titleFontStyle", L"");
    g_settings.titleCharacterSpacing = Wh_GetIntSetting(L"AppearanceSettings.TitleTextStyleSettings.titleCharacterSpacing");
    g_settings.artistFontSize       = Int(L"AppearanceSettings.ArtistTextStyleSettings.artistFontSize",        7,  24,  11);
    g_settings.artistFont           = MapFontName(Str(L"AppearanceSettings.ArtistTextStyleSettings.artistFont", L"segoe_ui_variable"));
    g_settings.artistFontFamily     = Str(L"AppearanceSettings.ArtistTextStyleSettings.artistFontFamily", L"");
    g_settings.artistFontWeight     = Str(L"AppearanceSettings.ArtistTextStyleSettings.artistFontWeight", L"");
    g_settings.artistFontStyle      = Str(L"AppearanceSettings.ArtistTextStyleSettings.artistFontStyle", L"");
    g_settings.artistCharacterSpacing = Wh_GetIntSetting(L"AppearanceSettings.ArtistTextStyleSettings.artistCharacterSpacing");
    g_settings.textSpacing          = Wh_GetIntSetting(L"MainSettings.TextAreaSetting.textSpacing");
    g_settings.enableArtistScrolling = Wh_GetIntSetting(L"MainSettings.TextAreaSetting.enableArtistScrolling") != 0;
    g_settings.enableTitleScrolling = Wh_GetIntSetting(L"MainSettings.TextAreaSetting.enableTitleScrolling") != 0;
    g_settings.scrollSpeed          = Int(L"MainSettings.TextAreaSetting.scrollSpeed", 1, 10, 1);
    g_settings.scrollPauseDuration  = Int(L"MainSettings.TextAreaSetting.scrollPauseDuration", 0, 10000, 1000);
    g_settings.scrollMode           = Str(L"MainSettings.TextAreaSetting.scrollMode", L"bounce");
    g_settings.loopGap              = Int(L"MainSettings.TextAreaSetting.loopGap", 0, 500, 40);
    g_settings.solidColor           = Str(L"AppearanceSettings.BackgroundStyleSettings.solidColor", L"35 35 35");
    g_settings.solidColor2          = Str(L"AppearanceSettings.BackgroundStyleSettings.solidColor2", L"35 35 35");
    g_settings.gradientColor2       = Str(L"AppearanceSettings.BackgroundStyleSettings.gradientColor2", L"128 128 128");
    g_settings.solidOpacity         = Int(L"AppearanceSettings.BackgroundStyleSettings.solidOpacity", 0, 100, 100);
    g_settings.gradientAngle        = Int(L"AppearanceSettings.BackgroundStyleSettings.gradientAngle", 0, 360, 50);
    g_settings.gradientBalance      = Int(L"AppearanceSettings.BackgroundStyleSettings.gradientBalance", 0, 100, 50);
    g_settings.acrylicTintOpacity   = Int(L"AppearanceSettings.BackgroundStyleSettings.acrylicTintOpacity", 0, 100, 50);
    g_settings.micaOpacity          = Int(L"AppearanceSettings.BackgroundStyleSettings.micaOpacity", 0, 100, 50);
    g_settings.buttonColor          = Str(L"AppearanceSettings.MediaButtonsStyleSettings.buttonColor", L"255 255 255");
    g_settings.buttonColorOpacity   = Int(L"AppearanceSettings.MediaButtonsStyleSettings.buttonColorOpacity", 0, 100, 100);
    g_settings.titleColor           = Str(L"AppearanceSettings.TitleTextStyleSettings.titleColor", L"255 255 255");
    g_settings.titleColorOpacity    = Int(L"AppearanceSettings.TitleTextStyleSettings.titleColorOpacity", 0, 100, 100);
    g_settings.artistColor          = Str(L"AppearanceSettings.ArtistTextStyleSettings.artistColor", L"255 255 255");
    g_settings.artistColorOpacity   = Int(L"AppearanceSettings.ArtistTextStyleSettings.artistColorOpacity", 0, 100, 80);
    g_settings.vizEnabled      = Wh_GetIntSetting(L"MainSettings.VisualizerFunctionsSettings.vizEnabled") != 0;
    g_settings.vizPosition     = Str(L"MainSettings.VisualizerFunctionsSettings.vizPosition", L"right");
    g_settings.vizColor        = Str(L"AppearanceSettings.VisualizerStyleSettings.vizColor",  L"255 255 255");
    g_settings.vizColor1       = Str(L"AppearanceSettings.VisualizerStyleSettings.vizColor1", L"30 215 96");
    g_settings.vizColor2       = Str(L"AppearanceSettings.VisualizerStyleSettings.vizColor2", L"0 180 255");
    g_settings.vizSensitivity  = Int(L"MainSettings.VisualizerFunctionsSettings.vizSensitivity", 0, 300, 200);
    {
        int n = 7, gap = 5;
        ParseTwoInts(Str(L"MainSettings.VisualizerFunctionsSettings.vizBarCountGap", L"7 5"), n, gap);
        g_settings.vizBars   = std::clamp(n, 1, 20);
        g_settings.vizBarGap = std::clamp(gap, 0, 40);
        int w = 5, h = 1;
        ParseTwoInts(Str(L"MainSettings.VisualizerFunctionsSettings.vizBarSize", L"5 1"), w, h);
        g_settings.vizBarWidth    = std::clamp(w, 0, 40);
        g_settings.vizIdleBarSize = std::clamp(h, 0, 15);
        int l = 0, r = 0;
        ParseTwoInts(Str(L"MainSettings.VisualizerFunctionsSettings.vizPadding", L"0 0"), l, r);
        g_settings.vizPadLeft  = std::clamp(l, 0, 200);
        g_settings.vizPadRight = std::clamp(r, 0, 200);
    }
    {
        std::wstring shape = Str(L"MainSettings.VisualizerFunctionsSettings.vizShape", L"stereo");
        g_settings.vizShape = (shape == L"mountain") ? VizShape::Mountain
                    : (shape == L"mirror")   ? VizShape::Mirror
                    : (shape == L"wave")     ? VizShape::Wave
                    : (shape == L"breathe")  ? VizShape::Breathe
                                            : VizShape::Stereo;
        std::wstring mode = Str(L"AppearanceSettings.VisualizerStyleSettings.vizColorMode", L"dynamic_album");
        g_settings.vizColorMode = (mode == L"dynamic_album")    ? VizColorMode::DynamicAlbum
                        : (mode == L"dynamic_gradient") ? VizColorMode::DynamicGradient
                        : (mode == L"custom_gradient")  ? VizColorMode::CustomGradient
                        : (mode == L"acrylic")          ? VizColorMode::Acrylic
                                                        : VizColorMode::Solid;
        std::wstring eq = Str(L"MainSettings.VisualizerFunctionsSettings.vizEQ", L"default");
        g_settings.vizEq = (eq == L"bass")       ? VizEQ::Bass
                : (eq == L"rock")       ? VizEQ::Rock
                : (eq == L"pop")        ? VizEQ::Pop
                : (eq == L"jazz")       ? VizEQ::Jazz
                : (eq == L"electronic") ? VizEQ::Electronic
                                        : VizEQ::Default;
        std::wstring anchor = Str(L"MainSettings.VisualizerFunctionsSettings.vizAnchor", L"middle");
        g_settings.vizAnchor = (anchor == L"top")    ? VizAnchor::Top
                    : (anchor == L"bottom") ? VizAnchor::Bottom
                                            : VizAnchor::Middle;
    }
    g_settings.albumArtLeftClick         = L"none";
    g_settings.albumArtRightClick        = L"none";
    g_settings.albumArtMiddleClick       = L"none";
    g_settings.albumArtLeftDoubleClick   = L"none";
    g_settings.albumArtRightDoubleClick  = L"none";
    g_settings.albumArtMiddleDoubleClick = L"none";
    g_settings.playerLeftClick           = L"none";
    g_settings.playerRightClick          = L"none";
    g_settings.playerMiddleClick         = L"none";
    g_settings.playerLeftDoubleClick     = L"none";
    g_settings.playerRightDoubleClick    = L"none";
    g_settings.playerMiddleDoubleClick   = L"none";
    for (int i = 0; i < 20; i++) {
        PCWSTR objectStr = Wh_GetStringSetting(L"BehaviorSettings.ClickActionSettings[%d].object", i);
        PCWSTR clickStr = Wh_GetStringSetting(L"BehaviorSettings.ClickActionSettings[%d].click", i);
        PCWSTR actionStr = Wh_GetStringSetting(L"BehaviorSettings.ClickActionSettings[%d].action", i);
        if (*objectStr == L'\0' || *clickStr == L'\0' || *actionStr == L'\0') {
            Wh_FreeStringSetting(objectStr);
            Wh_FreeStringSetting(clickStr);
            Wh_FreeStringSetting(actionStr);
            break;
        }
        std::wstring object(objectStr);
        std::wstring click(clickStr);
        std::wstring action(actionStr);
        Wh_FreeStringSetting(objectStr);
        Wh_FreeStringSetting(clickStr);
        Wh_FreeStringSetting(actionStr);
        if (object.empty()) object = L"none";
        if (click.empty()) click = L"none";
        if (action.empty()) action = L"none";
        if (object == L"none" || click == L"none") {
            continue;
        }
        if (object == L"album_art") {
            if (click == L"left_click") g_settings.albumArtLeftClick = action;
            else if (click == L"right_click") g_settings.albumArtRightClick = action;
            else if (click == L"middle_click") g_settings.albumArtMiddleClick = action;
            else if (click == L"left_double_click") g_settings.albumArtLeftDoubleClick = action;
            else if (click == L"right_double_click") g_settings.albumArtRightDoubleClick = action;
            else if (click == L"middle_double_click") g_settings.albumArtMiddleDoubleClick = action;
        } else if (object == L"player") {
            if (click == L"left_click") g_settings.playerLeftClick = action;
            else if (click == L"right_click") g_settings.playerRightClick = action;
            else if (click == L"middle_click") g_settings.playerMiddleClick = action;
            else if (click == L"left_double_click") g_settings.playerLeftDoubleClick = action;
            else if (click == L"right_double_click") g_settings.playerRightDoubleClick = action;
            else if (click == L"middle_double_click") g_settings.playerMiddleDoubleClick = action;
        }
    }
    g_settings.albumArtWheelAction = L"none";
    g_settings.playerWheelAction   = L"none";
    for (int i = 0; i < 20; i++) {
        PCWSTR objectStr = Wh_GetStringSetting(L"BehaviorSettings.MouseWheelActionSettings[%d].object", i);
        PCWSTR clickStr = Wh_GetStringSetting(L"BehaviorSettings.MouseWheelActionSettings[%d].click", i);
        PCWSTR actionStr = Wh_GetStringSetting(L"BehaviorSettings.MouseWheelActionSettings[%d].action", i);
        if (*objectStr == L'\0' || *clickStr == L'\0' || *actionStr == L'\0') {
            Wh_FreeStringSetting(objectStr);
            Wh_FreeStringSetting(clickStr);
            Wh_FreeStringSetting(actionStr);
            break;
        }
        std::wstring object(objectStr);
        std::wstring click(clickStr);
        std::wstring action(actionStr);
        Wh_FreeStringSetting(objectStr);
        Wh_FreeStringSetting(clickStr);
        Wh_FreeStringSetting(actionStr);
        if (object.empty()) object = L"none";
        if (click.empty()) click = L"none";
        if (action.empty()) action = L"none";
        if (object == L"none" || click == L"none") {
            continue;
        }
        if (object == L"album_art" && click == L"mouse_wheel") {
            g_settings.albumArtWheelAction = action;
        } else if (object == L"player" && click == L"mouse_wheel") {
            g_settings.playerWheelAction = action;
        }
    }
    g_settings.hideWhenNoMedia      = Wh_GetIntSetting(L"BehaviorSettings.hideWhenNoMedia")   != 0;
    g_settings.hideFullscreen       = Wh_GetIntSetting(L"BehaviorSettings.hideFullscreen")    != 0;
    g_settings.idleHideSeconds      = std::max(Wh_GetIntSetting(L"BehaviorSettings.idleHideSeconds"), 0);
    if (g_settings.showNeteaseLyrics) {
        g_settings.hideWhenNoMedia   = false;
        g_settings.hideFullscreen    = false;
        g_settings.idleHideSeconds   = 0;
        g_settings.noMediaTitleText.clear();
        g_settings.noMediaArtistText.clear();
        g_settings.showAlbumArt      = true;
    }
    g_settings.playerHoverEffectMode = HoverMode(L"AppearanceSettings.BackgroundStyleSettings.enablePlayerHoverEffect");
    g_settings.mediaButtonsHoverEffectMode = HoverMode(L"AppearanceSettings.BackgroundStyleSettings.enableMediaButtonsHoverEffect");
    g_settings.enableHoverAnimation = Wh_GetIntSetting(L"AppearanceSettings.BackgroundStyleSettings.enableHoverAnimation") != 0;
    g_settings.enableSmoothPositionAnimation = Wh_GetIntSetting(L"AnimationSettings.enableSmoothPositionAnimation") != 0;
    g_settings.showSuccessNotification = Wh_GetIntSetting(L"NotificationSettings.showSuccessNotification") != 0;
    g_settings.hideUnsupportedButtons  = Wh_GetIntSetting(L"MainSettings.MediaButtonsSettings.hideUnsupportedButtons") != 0;
    g_settings.disableAlbumArtClick    = Wh_GetIntSetting(L"BehaviorSettings.disableAlbumArtClick") != 0;
    g_settings.ignoredProcesses     = Str(L"DebugSettings.ignoredProcesses", L"chrome;msedge;firefox;brave;opera;vivaldi;zen");
    g_settings.enableTreeDump       = Wh_GetIntSetting(L"DebugSettings.enableTreeDump")    != 0;
    g_settings.showDebugBorders     = Wh_GetIntSetting(L"DebugSettings.showDebugBorders")  != 0;
    g_settings.showLayoutAnchors    = Wh_GetIntSetting(L"DebugSettings.showLayoutAnchors") != 0;
    g_settings.showRestartButton    = Wh_GetIntSetting(L"DebugSettings.showRestartButton") != 0;
    g_settings.contextMenuRepeatStyle  = Str(L"ContextMenuSettings.repeatStyle",  L"submenu");
    g_settings.contextMenuShuffleStyle = Str(L"ContextMenuSettings.shuffleStyle", L"toggle");
    g_settings.showOpenWindhawk        = Wh_GetIntSetting(L"ContextMenuSettings.showOpenWindhawk") != 0;
    g_settings.contextMenuIconStyle    = Str(L"ContextMenuSettings.contextMenuIconStyle", L"as_media_buttons");
    g_settings.contextMenuIconColor    = StrAllowEmpty(L"ContextMenuSettings.contextMenuIconColor");
    g_settings.contextMenuIconOpacity  = Int(L"ContextMenuSettings.contextMenuIconOpacity", 0, 100, 100);
    {
        g_settings.contextMenuItems.clear();
        const wchar_t* defaultItems[] = {
            L"switch_sessions", L"open_app"
        };
        bool hasAny = false;
        std::set<std::wstring> seen;
        for (int i = 0; i < 20; i++) {
            PCWSTR p = Wh_GetStringSetting(L"ContextMenuSettings.contextMenuItems[%d]", i);
            if (!p || !*p) { Wh_FreeStringSetting(p); break; }
            std::wstring s(p);
            Wh_FreeStringSetting(p);
            if (seen.insert(s).second) {
                g_settings.contextMenuItems.push_back(s);
                hasAny = true;
            }
        }
        if (!hasAny) {
            for (auto& d : defaultItems)
                g_settings.contextMenuItems.push_back(d);
        }
    }
    try {
        std::lock_guard<std::mutex> lock(g_mediaButtonsMutex);
        g_mediaButtons.clear();
        std::set<MediaButtonType> seen;
        for (int i = 0; i < 10; i++) {
            try {
                PCWSTR itemStr = Wh_GetStringSetting(L"MainSettings.MediaButtonsSettings.mediaButtons[%d]", i);
                if (!itemStr || !*itemStr) {
                    Wh_FreeStringSetting(itemStr);
                    break;
                }
                std::wstring keyword(itemStr);
                Wh_FreeStringSetting(itemStr);
                for (const auto& def : g_mediaButtonDefinitions) {
                    if (def.keyword == keyword && seen.insert(def.type).second) {
                        g_mediaButtons.push_back({def.type, def.cmd});
                        break;
                    }
                }
            } catch (...) {
                Wh_Log(L"LoadSettings: Exception parsing media button at index %d", i);
            }
        }
    } catch (...) {
        Wh_Log(L"LoadSettings: Critical exception in media buttons parsing, using defaults");
        try {
            std::lock_guard<std::mutex> lock(g_mediaButtonsMutex);
            g_mediaButtons = {
                {MediaButtonType::Heart, 13},
                {MediaButtonType::Previous, 1},
                {MediaButtonType::PlayPause, 2},
                {MediaButtonType::Next, 3}
            };
        } catch (...) {}
    }
    if (g_settings.position == L"taskbar_left")
        g_settings.position = L"taskbar_left_start";
    else if (g_settings.position == L"taskbar_right")
        g_settings.position = L"taskbar_right_start";
    else if (g_settings.position == L"taskbar_after_start")
        g_settings.position = L"taskbar_after_search_right";
    else if (g_settings.position == L"taskbar_after_search")
        g_settings.position = L"taskbar_after_search_right";
    else if (g_settings.position == L"tray_before_omni")
        g_settings.position = L"tray_before_omni_right";
    else if (g_settings.position == L"tray_after_showdesktop")
        g_settings.position = L"tray_after_showdesktop_right";
}
static HWND FindCurrentProcessTaskbarWnd();
using WindowThreadProc = void(*)(void*);
static bool RunFromWindowThread(HWND hWnd, WindowThreadProc proc, void* param);
static void DispatchMediaUpdate();
static void RefreshTaskbarMediaStateNow();
static void RefreshNeteaseHeartButton();

static void ApplySettings();
static std::atomic<bool> g_unloading{false};
static std::atomic<bool> g_applyingSettings{false};
static std::atomic<bool> g_injectionRetryPending{false};
static HWND g_taskbarWnd = nullptr;

static std::atomic<int> g_activeWorkerThreads{0};
template <typename F>
static void SpawnTrackedWorker(F&& fn) {
    g_activeWorkerThreads.fetch_add(1, std::memory_order_relaxed);
    std::thread([f = std::forward<F>(fn)]() mutable {
        struct Decrementer {
            ~Decrementer() { g_activeWorkerThreads.fetch_sub(1, std::memory_order_relaxed); }
        } dec;
        f();
    }).detach();
}

static void WaitForTrackedWorkers() {
    HWND hTaskbar = g_taskbarWnd;
    DWORD tid = GetCurrentThreadId();
    bool isUiThread = hTaskbar && (GetWindowThreadProcessId(hTaskbar, nullptr) == tid);
    if (isUiThread) {
        while (g_activeWorkerThreads.load(std::memory_order_relaxed) > 0) {
            MSG msg;
            while (PeekMessageW(&msg, nullptr, 0, 0, PM_REMOVE | PM_QS_SENDMESSAGE)) {
                TranslateMessage(&msg);
                DispatchMessageW(&msg);
            }
            Sleep(10);
        }
    } else {
        while (g_activeWorkerThreads.load(std::memory_order_relaxed) > 0) {
            Sleep(10);
        }
    }
}

static IMMDeviceEnumerator* g_pDeviceEnumerator = nullptr;
static const CLSID XIID_MMDeviceEnumerator = __uuidof(MMDeviceEnumerator);
static const IID XIID_IMMDeviceEnumerator = __uuidof(IMMDeviceEnumerator);
static const IID XIID_IAudioSessionManager2 = __uuidof(IAudioSessionManager2);
[[clang::no_destroy]] static Grid             g_playerGrid      = nullptr;
[[clang::no_destroy]] static FrameworkElement g_injectionParent = nullptr;
static int              g_playerColumn    = -1;
[[clang::no_destroy]] static std::function<void()> g_playerButtonStateUpdater;
[[clang::no_destroy]] static ToolTip          g_playerToolTip   = nullptr;
static std::atomic<bool> g_needsUiUpdate{false};
static std::atomic<bool> g_taskbarExpanded{false};
static std::atomic<bool> g_taskbarWrapperHovered{false};
static std::atomic<bool> g_taskbarDetailsRevealPending{false};
static bool g_taskbarLayoutTransitionInProgress = false;
static std::atomic<uint64_t> g_albumLeftClickGeneration{0};
enum class NeteaseLikeState : int {
    Unknown,
    Unliked,
    Liked,
};
static std::atomic<ULONGLONG> g_neteaseSkipSucceededTick{0};
static std::atomic<NeteaseLikeState> g_twilightLikeState{
    NeteaseLikeState::Unknown};
static std::atomic<bool> g_twilightFavoriteEligible{false};
static std::atomic<ULONGLONG> g_twilightLikeForcePollAfterTick{0};
static std::atomic<ULONGLONG> g_twilightNextPollTick{0};
static std::atomic<uint64_t> g_twilightPlaybackCommandGeneration{0};
static std::atomic<int> g_twilightPendingPlaybackState{-1};
static std::atomic<ULONGLONG> g_twilightPendingPlaybackUntilTick{0};
static std::atomic<uint64_t> g_twilightTrackGeneration{0};
static std::atomic<ULONGLONG> g_twilightPendingTrackUntilTick{0};
static std::atomic<ULONGLONG> g_lastTrackWheelActionTick{0};
static HWND g_twilightAccessibleHost = nullptr;
static std::atomic<bool> g_twilightProcessDetected{false};
static std::atomic<ULONGLONG> g_twilightAccessibleLastSuccessTick{0};
static std::atomic<uint64_t> g_twilightCoverGeneration{0};
static HANDLE g_timerUpdateEvent = nullptr;

struct TwilightBridgeDiscovery {
    bool valid = false;
    bool healthy = false;
    std::wstring baseUrl;
    std::wstring host;
    INTERNET_PORT port = 0;
    std::wstring basePath;
    std::wstring token;
    std::wstring instanceId;
    FILETIME discoveryLastWrite{};
};

struct TwilightBridgeSnapshot {
    bool reachable = false;
    std::wstring instanceId;
    uint64_t revision = 0;
    bool hasTrack = false;
    std::wstring trackId;
    std::wstring providerId;
    std::wstring title;
    std::wstring artist;
    std::wstring album;
    std::wstring coverSource;
    std::wstring currentLyric;
    bool isPlaying = false;
    bool isLoading = false;
    int64_t positionMs = 0;
    int64_t durationMs = 0;
    bool favoriteAvailable = false;
    bool favoriteLiked = false;
    bool favoriteLoading = false;
};

enum class TwilightBridgeCommandDisposition {
    NotAttempted,
    Consumed,
};

static std::mutex g_twilightBridgeMtx;
static TwilightBridgeDiscovery g_twilightBridgeDiscovery;
static TwilightBridgeSnapshot g_twilightBridgeSnapshot;
static std::atomic<bool> g_twilightBridgeAuthoritative{false};
static std::atomic<ULONGLONG> g_twilightBridgeLastSuccessTick{0};
static std::atomic<ULONGLONG> g_twilightBridgeNextDiscoveryTick{0};
static std::atomic<uint64_t> g_twilightBridgeRequestSequence{0};
[[clang::no_destroy]] static std::wstring g_twilightAppliedTrackId;
[[clang::no_destroy]] static std::wstring g_twilightAppliedCoverSource;

struct TwilightAccessiblePlayback {
    bool reachable = false;
    bool observedForeground = false;
    std::wstring trackId;
    std::wstring title;
    std::wstring artist;
    std::wstring coverSource;
    bool isPlaying = false;
    bool canTogglePlay = false;
    bool canSkipPrevious = false;
    bool canSkipNext = false;
    int64_t rawPositionMs = 0;
    int64_t positionMs = 0;
    int64_t durationMs = 0;
    ULONGLONG observedAtTick = 0;
    bool positionAdvancing = false;
    NeteaseLikeState favoriteState = NeteaseLikeState::Unknown;
};
enum class TwilightAudioState {
    Unknown,
    Playing,
    Paused,
    Stopped,
};
struct TwilightAudioClock {
    bool valid = false;
    bool started = false;
    std::wstring sessionId;
    uint64_t sequence = 0;
    uint64_t epoch = 0;
    std::wstring fingerprint;
    std::wstring extension;
    TwilightAudioState state = TwilightAudioState::Unknown;
    int64_t positionMs = 0;
    int64_t durationMs = 0;
    double rate = 1.0;
    ULONGLONG anchorTick = 0;
};
struct TwilightSessionTrack {
    bool valid = false;
    uint64_t revision = 0;
    std::wstring fingerprint;
    std::wstring id;
    std::wstring queueEntryId;
    std::wstring songId;
    std::wstring title;
    std::wstring artist;
    std::wstring filePath;
    std::wstring streamUrl;
    std::wstring coverSource;
    int64_t durationMs = 0;
};
enum class TwilightStoreResult {
    Rejected,
    Unchanged,
    Changed,
};
struct TwilightCommitResult {
    bool accepted = false;
    bool changed = false;
    TwilightAccessiblePlayback state;
};
static TwilightAccessiblePlayback g_twilightAccessiblePlayback;
static std::mutex g_twilightAccessiblePlaybackMtx;
[[clang::no_destroy]] static std::wstring g_twilightPendingOldTrackKey;
static TwilightAudioClock g_twilightAudioClock;
static TwilightSessionTrack g_twilightResolvedTrack;
static std::mutex g_twilightAudioMtx;
static std::atomic<bool> g_twilightAudioIdentityPending{false};
static std::atomic<bool> g_twilightSessionAuthorityActive{false};

static TwilightBridgeCommandDisposition
TrySendTwilightBridgePlaybackCommand(const wchar_t* type);
static bool IsTwilightBridgeHealthy();
static bool IsTwilightBridgeAuthorityActive();
static void InvalidateTwilightBridge();
static void MarkTwilightBridgeTransientFailure();
static bool UseTwilightBridgeAuthorityGrace(
    TwilightBridgeSnapshot& result);
static void ShortenTwilightWheelReservationAfterBridgeDelivery();
static bool PollTwilightBridgeState(TwilightBridgeSnapshot& result);
static bool ApplyTwilightBridgeSnapshot(
    const TwilightBridgeSnapshot& snapshot);
static bool TwilightBridgeRequest(const wchar_t* method,
                                  const wchar_t* relativePath,
                                  const std::string& requestBody,
                                  std::wstring* responseBody,
                                  DWORD* responseStatus,
                                  DWORD receiveTimeoutMs = 700,
                                  bool* requestMayHaveReachedServer = nullptr);
static std::string WideToUtf8(const std::wstring& text);
static bool InvokeTwilightTransportControl(int cmd);
static bool IsTwilightProcessRunning();
static void SwitchSelectedPlayer();
static void ScheduleTwilightAccessibleCoverFetch(
    const std::wstring& title, const std::wstring& artist,
    int64_t expectedDurationMs, uint64_t expectedTrackGeneration,
    const std::wstring& preferredCoverSource = {});

static void SetTwilightLikeState(NeteaseLikeState state,
                                 bool notify = true) {
    if (g_twilightLikeState.exchange(state) != state && notify) {
        DispatchMediaUpdate();
        HWND taskbarWnd = g_taskbarWnd;
        if (taskbarWnd && !g_unloading && !g_applyingSettings) {
            RunFromWindowThread(taskbarWnd, [](void*) {
                if (!g_unloading && !g_applyingSettings) {
                    RefreshNeteaseHeartButton();
                }
            }, nullptr);
        }
    }
}

static void SetTwilightFavoriteEligibility(bool eligible,
                                           bool notify = true) {
    if (g_twilightFavoriteEligible.exchange(eligible) != eligible && notify) {
        DispatchMediaUpdate();
        HWND taskbarWnd = g_taskbarWnd;
        if (taskbarWnd && !g_unloading && !g_applyingSettings) {
            RunFromWindowThread(taskbarWnd, [](void*) {
                if (!g_unloading && !g_applyingSettings) {
                    RefreshNeteaseHeartButton();
                }
            }, nullptr);
        }
    }
}

static bool TryToggleTwilightFavorite() {
    if (!IsTwilightBridgeHealthy()) {
        SetTwilightLikeState(NeteaseLikeState::Unknown);
        return false;
    }

    TwilightBridgeSnapshot snapshot;
    {
        std::lock_guard<std::mutex> lock(g_twilightBridgeMtx);
        snapshot = g_twilightBridgeSnapshot;
    }
    if (!snapshot.reachable || !snapshot.hasTrack ||
        snapshot.trackId.empty() || !snapshot.favoriteAvailable ||
        snapshot.favoriteLoading) {
        SetTwilightLikeState(NeteaseLikeState::Unknown);
        return false;
    }

    bool desiredLiked = !snapshot.favoriteLiked;
    uint64_t sequence =
        g_twilightBridgeRequestSequence.fetch_add(1) + 1;
    std::wstring requestId = std::to_wstring(GetCurrentProcessId()) + L"-" +
        std::to_wstring(GetTickCount64()) + L"-" +
        std::to_wstring(sequence);

    using namespace winrt::Windows::Data::Json;
    JsonObject command;
    command.Insert(L"type", JsonValue::CreateStringValue(L"set-favorite"));
    command.Insert(L"liked", JsonValue::CreateBooleanValue(desiredLiked));
    command.Insert(L"expectedTrackId",
                   JsonValue::CreateStringValue(snapshot.trackId));
    command.Insert(L"requestId", JsonValue::CreateStringValue(requestId));

    {
        std::lock_guard<std::mutex> lock(g_twilightBridgeMtx);
        if (g_twilightBridgeSnapshot.trackId == snapshot.trackId) {
            g_twilightBridgeSnapshot.favoriteLoading = true;
        }
    }
    SetTwilightLikeState(NeteaseLikeState::Unknown);

    std::wstring responseBody;
    DWORD responseStatus = 0;
    if (!TwilightBridgeRequest(
            L"POST", L"/command",
            WideToUtf8(std::wstring(command.Stringify())),
            &responseBody, &responseStatus, 6000)) {
        return false;
    }
    if (responseStatus == 202) {
        return true;
    }
    if (responseStatus != 200 || responseBody.empty()) {
        return false;
    }

    try {
        JsonObject response = JsonObject::Parse(winrt::hstring(responseBody));
        std::wstring status = std::wstring(
            response.GetNamedString(L"status", L""));
        bool confirmed = response.GetNamedBoolean(L"confirmed", false);
        std::wstring confirmedRequestId = std::wstring(
            response.GetNamedString(L"requestId", L""));
        std::wstring confirmedTrackId = std::wstring(
            response.GetNamedString(L"trackId", L""));
        bool confirmedLiked =
            response.GetNamedBoolean(L"liked", !desiredLiked);
        if ((status != L"confirmed" && status != L"noop") || !confirmed ||
            confirmedRequestId != requestId ||
            confirmedTrackId != snapshot.trackId ||
            confirmedLiked != desiredLiked) {
            return false;
        }
        {
            std::lock_guard<std::mutex> lock(g_twilightBridgeMtx);
            if (g_twilightBridgeSnapshot.trackId != snapshot.trackId) {
                return false;
            }
            g_twilightBridgeSnapshot.favoriteLiked = confirmedLiked;
            g_twilightBridgeSnapshot.favoriteLoading = false;
        }
        SetTwilightLikeState(confirmedLiked
                                 ? NeteaseLikeState::Liked
                                 : NeteaseLikeState::Unliked);
        return true;
    } catch (...) {
        return false;
    }
}
static void ShowSuccessNotification() {
    if (!g_settings.showSuccessNotification) {
        return;
    }
    std::thread([]() {
        MessageBoxW(
            nullptr,
            UiText(L"Media player successfully loaded and ready to use",
                   L"媒体播放器已成功加载，可以使用了"),
            L"Taskbar Fluent Media Player",
            MB_ICONINFORMATION | MB_OK | MB_TOPMOST | MB_SETFOREGROUND
        );
    }).detach();
}

[[clang::no_destroy]] static FrameworkElement g_trackedElement = nullptr;
static Thickness g_trackedElementOriginalMargin{};
static bool g_hasTrackedElementOriginalMargin = false;
static std::wstring g_trackPosition = L"";
static winrt::event_token g_layoutUpdateToken{};
static bool g_trackedStartButtonModActive = false;
static double g_trackedStartButtonOffset = 0.0;
static bool g_hasTrackedPlayerAnchorLeft = false;
static double g_trackedPlayerAnchorLeft = 0.0;
static double g_trackedRootGridWidth = 0.0;
using CTaskBand_GetTaskbarHost_t  = void*(WINAPI*)(void*, void*);
using CSecondaryTaskBand_GetTaskbarHost_t = void*(WINAPI*)(void*, void*);
using TaskbarHost_FrameHeight_t   = int  (WINAPI*)(void*);
using Std_Ref_Decref_t            = void (WINAPI*)(void*);
static CTaskBand_GetTaskbarHost_t  CTaskBand_GetTaskbarHost_Original  = nullptr;
static CSecondaryTaskBand_GetTaskbarHost_t CSecondaryTaskBand_GetTaskbarHost_Original = nullptr;
static TaskbarHost_FrameHeight_t   TaskbarHost_FrameHeight_Original   = nullptr;
static Std_Ref_Decref_t            Std_Ref_Decref_Original            = nullptr;
static void* CTaskBand_ITaskListWndSite_vftable = nullptr;
static void* CSecondaryTaskBand_ITaskListWndSite_vftable = nullptr;
static bool RunFromWindowThread(HWND hWnd, WindowThreadProc proc, void* param) {
    static const UINT kMsg = RegisterWindowMessage(L"Windhawk_RunFromWindowThread_" WH_MOD_ID);
    struct Payload { WindowThreadProc proc; void* param; };
    DWORD tid = GetWindowThreadProcessId(hWnd, nullptr);
    if (!tid) return false;
    if (tid == GetCurrentThreadId()) {
        proc(param);
        return true;
    }
    HHOOK hook = SetWindowsHookExW(WH_CALLWNDPROC,
        [](int code, WPARAM w, LPARAM l) CALLBACK -> LRESULT {
            if (code == HC_ACTION) {
                auto* cwp = reinterpret_cast<const CWPSTRUCT*>(l);
                static const UINT kM = RegisterWindowMessage(L"Windhawk_RunFromWindowThread_" WH_MOD_ID);
                if (cwp->message == kM) {
                    auto* p = reinterpret_cast<Payload*>(cwp->lParam);
                    p->proc(p->param);
                }
            }
            return CallNextHookEx(nullptr, code, w, l);
        }, nullptr, tid);
    if (!hook) return false;
    Payload pay{proc, param};
    SendMessageW(hWnd, kMsg, 0, reinterpret_cast<LPARAM>(&pay));
    UnhookWindowsHookEx(hook);
    return true;
}
struct MediaState {
    std::wstring      title;
    std::wstring      artist;
    std::wstring      appUserModelId;
    bool              isPlaying     = false;
    bool              hasMedia      = false;
    std::vector<BYTE> thumbnailBytes;
    uint64_t          thumbnailHash = 0;
    uint64_t          thumbnailStreamSize = 0;
    std::vector<BYTE> appIconBytes;
    std::wstring      appIconKey;
    bool              canSkipPrevious  = true;
    bool              canSkipNext      = true;
    bool              canShuffle       = true;
    bool              canRepeat        = true;
    bool              canSeek          = true;
};
static MediaState g_media;
static std::mutex g_mediaMtx;
static std::wstring g_lastTitleArtistKey;
static uint64_t     g_suspectArtSize   = 0;
static uint64_t     g_suspectArtHash   = 0;
static bool         g_artDelayPending  = false;
static bool         g_artNewBrowserSession = false;
enum class RepeatMode {
    Off = 0,
    All = 1,
    One = 2,
};
static std::atomic<bool> g_shuffleEnabled{false};
static std::atomic<RepeatMode> g_repeatMode{RepeatMode::Off};
static std::wstring g_cachedAlbumTitle;
static std::wstring g_cachedAlbumArtist;
static std::vector<BYTE> g_cachedThumbnailBytes;
static int g_cachedAppIconSize = -1;
static std::wstring g_scrollCachedTitle;
static std::wstring g_scrollCachedArtist;
struct BlurBgCache {
    std::vector<BYTE>  blurredPixels;
    int                width  = 0;
    int                height = 0;
    size_t             artHash = 0;
    void Invalidate() {
        blurredPixels.clear();
        width = height = 0;
        artHash = 0;
    }
} g_blurBgCache;
struct AlbumPalette {
    winrt::Windows::UI::Color primary;
    winrt::Windows::UI::Color secondary;
};
static AlbumPalette g_cachedAlbumPalette = {
    winrt::Windows::UI::Color{255, 18, 18, 18},
    winrt::Windows::UI::Color{255, 45, 45, 45}
};
static size_t g_cachedPaletteHash = 0;
static winrt::Windows::UI::Color g_cachedVizBaseColor{255, 255, 255, 255};
static bool g_vizBaseColorDirty = true;
static winrt::Windows::UI::Color g_cachedVizPal0{255, 255, 255, 255};
static winrt::Windows::UI::Color g_cachedVizPal1{255, 255, 255, 255};
static winrt::Windows::UI::Color g_cachedVizCg0{255, 255, 255, 255};
static winrt::Windows::UI::Color g_cachedVizCg1{255, 255, 255, 255};
static winrt::Windows::UI::Color g_cachedVizAcrCol{255, 255, 255, 255};
static bool g_vizPaletteColorsDirty = true;
[[clang::no_destroy]] static GlobalSystemMediaTransportControlsSessionManager g_sessionMgr     = nullptr;
[[clang::no_destroy]] static GlobalSystemMediaTransportControlsSession        g_currentSession = nullptr;
static std::mutex  g_sessionMtx;
static bool g_userSwitchedSession = false;
static std::atomic<bool> g_forceSessionRefresh{false};
static std::atomic<int> g_sessionCount{0};
static winrt::event_token g_evSessionsChanged{};
static winrt::event_token g_evCurrentChanged{};
static winrt::event_token g_evMediaProps{};
static winrt::event_token g_evPlayback{};
static HANDLE g_mediaThread    = nullptr;
static HANDLE g_mediaStopEvent = nullptr;
static bool IsSystemLightTheme() {
    DWORD v = 0, sz = sizeof(v);
    if (RegGetValueW(HKEY_CURRENT_USER,
        L"Software\\Microsoft\\Windows\\CurrentVersion\\Themes\\Personalize",
        L"SystemUsesLightTheme", RRF_RT_DWORD, nullptr, &v, &sz) == ERROR_SUCCESS) {
        return v != 0;
    }
    v = 0; sz = sizeof(v);
    RegGetValueW(HKEY_CURRENT_USER,
        L"Software\\Microsoft\\Windows\\CurrentVersion\\Themes\\Personalize",
        L"AppsUseLightTheme", RRF_RT_DWORD, nullptr, &v, &sz);
    return v != 0;
}
static SolidColorBrush MakeBrush(winrt::Windows::UI::Color c) {
    SolidColorBrush b; b.Color(c); return b;
}
static bool IsHoverEffectEnabled(std::wstring const& mode) {
    return mode != L"off";
}
static bool IsHoverLightTheme(std::wstring const& mode) {
    if (mode == L"white") return true;
    if (mode == L"black") return false;
    return IsSystemLightTheme();
}
static winrt::Windows::UI::Color GetSystemButtonHoverColor(std::wstring const& mode) {
    if (IsHoverLightTheme(mode)) {
        return winrt::Windows::UI::Color{0x99, 0xFF, 0xFF, 0xFF};
    }
    return winrt::Windows::UI::Color{0x0F, 0xFF, 0xFF, 0xFF};
}
static winrt::Windows::UI::Color GetSystemButtonPressedColor(std::wstring const& mode) {
    if (IsHoverLightTheme(mode)) {
        return winrt::Windows::UI::Color{0x4D, 0xFF, 0xFF, 0xFF};
    }
    return winrt::Windows::UI::Color{0x0A, 0xFF, 0xFF, 0xFF};
}
static winrt::Windows::UI::Color GetSystemButtonBorderColor(std::wstring const& mode) {
    if (IsHoverLightTheme(mode)) {
        return winrt::Windows::UI::Color{0x08, 0x00, 0x00, 0x00};
    }
    return winrt::Windows::UI::Color{0x14, 0xFF, 0xFF, 0xFF};
}
static winrt::Windows::UI::Color GetSystemButtonBorderPressedColor(std::wstring const& mode) {
    if (IsHoverLightTheme(mode)) {
        return winrt::Windows::UI::Color{0x05, 0x00, 0x00, 0x00};
    }
    return winrt::Windows::UI::Color{0x0A, 0xFF, 0xFF, 0xFF};
}
[[clang::no_destroy]] static SolidColorBrush g_mediaHoverBrush   = nullptr;
[[clang::no_destroy]] static SolidColorBrush g_mediaPressedBrush = nullptr;
[[clang::no_destroy]] static SolidColorBrush g_playerHoverBrush   = nullptr;
[[clang::no_destroy]] static SolidColorBrush g_playerPressedBrush = nullptr;
[[clang::no_destroy]] static SolidColorBrush g_playerBorderBrush  = nullptr;
[[clang::no_destroy]] static SolidColorBrush g_playerBorderPressedBrush = nullptr;
static void EnsureHoverBrushes() {
    if (!g_mediaHoverBrush) {
        g_mediaHoverBrush   = SolidColorBrush(GetSystemButtonHoverColor(g_settings.mediaButtonsHoverEffectMode));
        g_mediaPressedBrush = SolidColorBrush(GetSystemButtonPressedColor(g_settings.mediaButtonsHoverEffectMode));
    }
    if (!g_playerHoverBrush) {
        g_playerHoverBrush   = SolidColorBrush(GetSystemButtonHoverColor(g_settings.playerHoverEffectMode));
        g_playerPressedBrush = SolidColorBrush(GetSystemButtonPressedColor(g_settings.playerHoverEffectMode));
        g_playerBorderBrush  = SolidColorBrush(GetSystemButtonBorderColor(g_settings.playerHoverEffectMode));
        g_playerBorderPressedBrush = SolidColorBrush(GetSystemButtonBorderPressedColor(g_settings.playerHoverEffectMode));
    }
}
static void UpdateHoverBrushColors() {
    if (g_mediaHoverBrush) {
        try { g_mediaHoverBrush.Color(GetSystemButtonHoverColor(g_settings.mediaButtonsHoverEffectMode)); } catch (...) {}
    } else {
        try { g_mediaHoverBrush = SolidColorBrush(GetSystemButtonHoverColor(g_settings.mediaButtonsHoverEffectMode)); } catch (...) {}
    }
    if (g_mediaPressedBrush) {
        try { g_mediaPressedBrush.Color(GetSystemButtonPressedColor(g_settings.mediaButtonsHoverEffectMode)); } catch (...) {}
    } else {
        try { g_mediaPressedBrush = SolidColorBrush(GetSystemButtonPressedColor(g_settings.mediaButtonsHoverEffectMode)); } catch (...) {}
    }
    if (g_playerHoverBrush) {
        try { g_playerHoverBrush.Color(GetSystemButtonHoverColor(g_settings.playerHoverEffectMode)); } catch (...) {}
    } else {
        try { g_playerHoverBrush = SolidColorBrush(GetSystemButtonHoverColor(g_settings.playerHoverEffectMode)); } catch (...) {}
    }
    if (g_playerPressedBrush) {
        try { g_playerPressedBrush.Color(GetSystemButtonPressedColor(g_settings.playerHoverEffectMode)); } catch (...) {}
    } else {
        try { g_playerPressedBrush = SolidColorBrush(GetSystemButtonPressedColor(g_settings.playerHoverEffectMode)); } catch (...) {}
    }
    if (g_playerBorderBrush) {
        try { g_playerBorderBrush.Color(GetSystemButtonBorderColor(g_settings.playerHoverEffectMode)); } catch (...) {}
    } else {
        try { g_playerBorderBrush = SolidColorBrush(GetSystemButtonBorderColor(g_settings.playerHoverEffectMode)); } catch (...) {}
    }
    if (g_playerBorderPressedBrush) {
        try { g_playerBorderPressedBrush.Color(GetSystemButtonBorderPressedColor(g_settings.playerHoverEffectMode)); } catch (...) {}
    } else {
        try { g_playerBorderPressedBrush = SolidColorBrush(GetSystemButtonBorderPressedColor(g_settings.playerHoverEffectMode)); } catch (...) {}
    }
}
static Border GetButtonTemplateRoot(Button const& btn) {
    if (!btn) return nullptr;
    try {
        btn.ApplyTemplate();
        if (VisualTreeHelper::GetChildrenCount(btn) > 0) {
            if (auto border = VisualTreeHelper::GetChild(btn, 0).try_as<Border>())
                return border;
        }
        if (auto named = btn.FindName(L"Root")) {
            if (auto border = named.try_as<Border>()) return border;
        }
    } catch (...) {}
    return nullptr;
}

[[clang::no_destroy]] static Style g_fluentMediaButtonStyle = nullptr;
static Style GetFluentMediaButtonStyle() {
    if (!g_fluentMediaButtonStyle) {
        static const wchar_t kStyleXaml[] = LR"(<Style TargetType="Button"
    xmlns="http://schemas.microsoft.com/winfx/2006/xaml/presentation"
    xmlns:x="http://schemas.microsoft.com/winfx/2006/xaml">
<Setter Property="Background" Value="Transparent"/>
<Setter Property="BorderBrush" Value="Transparent"/>
<Setter Property="BorderThickness" Value="0"/>
<Setter Property="UseSystemFocusVisuals" Value="False"/>
<Setter Property="Template">
    <Setter.Value>
    <ControlTemplate TargetType="Button">
        <Border x:Name="Root"
                Background="{TemplateBinding Background}"
                BorderBrush="{TemplateBinding BorderBrush}"
                BorderThickness="{TemplateBinding BorderThickness}"
                CornerRadius="{TemplateBinding CornerRadius}"
                Padding="{TemplateBinding Padding}">
        <Border.BackgroundTransition>
            <BrushTransition Duration="0:0:0.083"/>
        </Border.BackgroundTransition>
        <VisualStateManager.VisualStateGroups>
            <VisualStateGroup x:Name="CommonStates">
            <VisualState x:Name="Normal">
                <VisualState.Setters>
                    <Setter Target="Root.Background" Value="Transparent"/>
                    <Setter Target="Root.BorderBrush" Value="Transparent"/>
                </VisualState.Setters>
            </VisualState>
            <VisualState x:Name="PointerOver">
                <VisualState.Setters>
                    <Setter Target="Root.Background" Value="Transparent"/>
                    <Setter Target="Root.BorderBrush" Value="Transparent"/>
                </VisualState.Setters>
            </VisualState>
            <VisualState x:Name="Pressed">
                <VisualState.Setters>
                    <Setter Target="Root.Background" Value="Transparent"/>
                    <Setter Target="Root.BorderBrush" Value="Transparent"/>
                </VisualState.Setters>
            </VisualState>
            <VisualState x:Name="Disabled">
                <VisualState.Setters>
                    <Setter Target="Root.Background" Value="Transparent"/>
                    <Setter Target="Root.BorderBrush" Value="Transparent"/>
                </VisualState.Setters>
            </VisualState>
            </VisualStateGroup>
        </VisualStateManager.VisualStateGroups>
        <ContentPresenter Content="{TemplateBinding Content}"
                            ContentTransitions="{TemplateBinding ContentTransitions}"
                            ContentTemplate="{TemplateBinding ContentTemplate}"
                            HorizontalContentAlignment="{TemplateBinding HorizontalContentAlignment}"
                            VerticalContentAlignment="{TemplateBinding VerticalContentAlignment}"/>
        </Border>
    </ControlTemplate>
    </Setter.Value>
</Setter>
</Style>)";
        try {
            g_fluentMediaButtonStyle = winrt::Windows::UI::Xaml::Markup::XamlReader::Load(
                winrt::hstring(kStyleXaml)).as<Style>();
        } catch (...) {}
    }
    return g_fluentMediaButtonStyle;
}
static void ApplyFluentMediaButtonStyle(Button const& btn) {
    if (auto style = GetFluentMediaButtonStyle()) {
        btn.Style(style);
    }
}

static VisualState FindCommonState(Border const& root, std::wstring const& stateName) {
    if (!root) return nullptr;
    try {
        auto groups = VisualStateManager::GetVisualStateGroups(root);
        for (auto const& g : groups) {
            if (g.Name() == L"CommonStates") {
                for (auto const& s : g.States()) {
                    if (s.Name() == stateName) return s;
                }
            }
        }
    } catch (...) {}
    return nullptr;
}

static void SetStateBrush(Border const& root, std::wstring const& stateName, uint32_t setterIndex, Brush const& value) {
    if (!root) return;
    try {
        auto state = FindCommonState(root, stateName);
        if (!state) return;
        auto setters = state.Setters();
        if (setterIndex >= setters.Size()) return;
        if (auto setter = setters.GetAt(setterIndex).try_as<Setter>()) {
            setter.Value(value);
        }
    } catch (...) {}
}
static void ApplyHoverTransitionSetting(Border const& root) {
    if (!root) return;
    try {
        if (g_settings.enableHoverAnimation) {
            BrushTransition bt;
            bt.Duration(winrt::Windows::Foundation::TimeSpan(std::chrono::milliseconds(83)));
            root.BackgroundTransition(bt);
        } else {
            root.BackgroundTransition(nullptr);
        }
    } catch (...) {}
}
static void SetupCommonStates(
    Button const& btn,
    Brush const& normalBackground,
    Brush const& pointerOverBackground,
    Brush const& pressedBackground,
    Brush const& disabledBackground,
    Brush const& normalBorderBrush,
    Brush const& pointerOverBorderBrush,
    Brush const& pressedBorderBrush,
    Brush const& disabledBorderBrush)
{
    auto root = GetButtonTemplateRoot(btn);
    if (!root) return;
    ApplyHoverTransitionSetting(root);
    SetStateBrush(root, L"Normal",      0, normalBackground);
    SetStateBrush(root, L"Normal",      1, normalBorderBrush);
    SetStateBrush(root, L"PointerOver", 0, pointerOverBackground);
    SetStateBrush(root, L"PointerOver", 1, pointerOverBorderBrush);
    SetStateBrush(root, L"Pressed",     0, pressedBackground);
    SetStateBrush(root, L"Pressed",     1, pressedBorderBrush);
    SetStateBrush(root, L"Disabled",    0, disabledBackground);
    SetStateBrush(root, L"Disabled",    1, disabledBorderBrush);
    try {
        root.Background(normalBackground);
        root.BorderBrush(normalBorderBrush);
    } catch (...) {}
}
static void GoToCommonState(Button const& btn, bool effectEnabled, bool pressed, bool hovered) {
    if (!btn) return;
    try {
        winrt::hstring stateName = L"Normal";
        if (effectEnabled) {
            if (pressed)      stateName = L"Pressed";
            else if (hovered) stateName = L"PointerOver";
        }
        if (pressed && g_settings.enableHoverAnimation) {
            if (auto root = GetButtonTemplateRoot(btn)) {
                auto saved = root.BackgroundTransition();
                root.BackgroundTransition(nullptr);
                VisualStateManager::GoToState(btn, stateName, true);
                root.BackgroundTransition(saved);
                return;
            }
        }
        VisualStateManager::GoToState(btn, stateName, true);
    } catch (...) {}
}
static void RunWhenButtonReady(Button const& btn, std::function<void()> const& action) {
    if (!btn || !action) return;
    auto run = std::make_shared<std::function<void()>>(action);
    auto invoke = [btn, run]() {
        try {
            btn.ApplyTemplate();
            (*run)();
        } catch (...) {}
    };
    try {
        if (btn.IsLoaded()) {
            invoke();
        } else {
            btn.Loaded([invoke](auto const&, auto const&) { invoke(); });
        }
    } catch (...) {
        invoke();
    }
}

static void SetupMediaButtonCommonStates(Button const& btn) {
    auto transparent = MakeBrush({0x00, 0xFF, 0xFF, 0xFF});
    if (!IsHoverEffectEnabled(g_settings.mediaButtonsHoverEffectMode)) {
        SetupCommonStates(
            btn,
            transparent, transparent, transparent, transparent,
            transparent, transparent, transparent, transparent);
        return;
    }
    EnsureHoverBrushes();
    SetupCommonStates(
        btn,
        transparent,
        g_mediaHoverBrush,
        g_mediaPressedBrush,
        transparent,
        transparent, transparent, transparent, transparent);
}
static Brush MakeElevationBorderBrush(std::wstring const& mode) {
    bool light = IsHoverLightTheme(mode);
    winrt::Windows::UI::Color topColor, bottomColor;
    if (light) {
        topColor    = winrt::Windows::UI::Color{0x08, 0x00, 0x00, 0x00};
        bottomColor = winrt::Windows::UI::Color{0x10, 0x00, 0x00, 0x00};
    } else {
        topColor    = winrt::Windows::UI::Color{0x28, 0xFF, 0xFF, 0xFF};
        bottomColor = winrt::Windows::UI::Color{0x0A, 0xFF, 0xFF, 0xFF};
    }
    try {
        winrt::Windows::UI::Xaml::Media::LinearGradientBrush brush;
        brush.StartPoint(winrt::Windows::Foundation::Point(0.5f, 0.0f));
        brush.EndPoint(winrt::Windows::Foundation::Point(0.5f, 1.0f));
        winrt::Windows::UI::Xaml::Media::GradientStop s1, s2;
        s1.Color(topColor);    s1.Offset(0.0);
        s2.Color(bottomColor); s2.Offset(1.0);
        brush.GradientStops().Append(s1);
        brush.GradientStops().Append(s2);
        return brush;
    } catch (...) {
        return MakeBrush(topColor);
    }
}
static void SetupPlayerCommonStates(Button const& btn, Brush const& normalBg) {
    auto transparent = MakeBrush({0x00, 0xFF, 0xFF, 0xFF});
    if (!IsHoverEffectEnabled(g_settings.playerHoverEffectMode)) {
        SetupCommonStates(
            btn,
            normalBg, normalBg, normalBg, normalBg,
            transparent, transparent, transparent, transparent);
        return;
    }
    EnsureHoverBrushes();
    auto elevBorder        = MakeElevationBorderBrush(g_settings.playerHoverEffectMode);
    auto elevBorderPressed = MakeBrush(GetSystemButtonBorderPressedColor(g_settings.playerHoverEffectMode));
    SetupCommonStates(
        btn,
        normalBg,
        g_playerHoverBrush,
        g_playerPressedBrush,
        normalBg,
        transparent,
        elevBorder,
        elevBorderPressed,
        transparent);
}
static void ApplyPlayerButtonState(Button const& btn, Brush const& /*normalBg*/, bool hovered, bool pressed) {
    if (!btn) return;
    try {
        GoToCommonState(btn, IsHoverEffectEnabled(g_settings.playerHoverEffectMode), pressed, hovered);
    } catch (...) {}
}
static bool DecodeImageToBGRA(const std::vector<BYTE>& imgBytes,
                            std::vector<BYTE>& outPixels,
                            int& outW, int& outH)
{
    if (imgBytes.empty()) return false;
    IWICImagingFactory* pFactory = nullptr;
    if (FAILED(CoCreateInstance(CLSID_WICImagingFactory, nullptr,
                                CLSCTX_INPROC_SERVER,
                                IID_PPV_ARGS(&pFactory))) || !pFactory)
        return false;
    IStream* pStream = SHCreateMemStream(imgBytes.data(), (UINT)imgBytes.size());
    if (!pStream) { pFactory->Release(); return false; }
    bool ok = false;
    IWICBitmapDecoder* pDecoder = nullptr;
    if (SUCCEEDED(pFactory->CreateDecoderFromStream(
            pStream, nullptr, WICDecodeMetadataCacheOnDemand, &pDecoder))) {
        IWICBitmapFrameDecode* pFrame = nullptr;
        if (SUCCEEDED(pDecoder->GetFrame(0, &pFrame))) {
            IWICFormatConverter* pConv = nullptr;
            if (SUCCEEDED(pFactory->CreateFormatConverter(&pConv))) {
                if (SUCCEEDED(pConv->Initialize(
                        pFrame, GUID_WICPixelFormat32bppBGRA,
                        WICBitmapDitherTypeNone, nullptr, 0.0,
                        WICBitmapPaletteTypeMedianCut))) {
                    UINT w = 0, h = 0;
                    pConv->GetSize(&w, &h);
                    if (w > 0 && h > 0) {
                        outPixels.resize((size_t)w * h * 4);
                        if (SUCCEEDED(pConv->CopyPixels(nullptr, w * 4,
                                (UINT)outPixels.size(), outPixels.data()))) {
                            outW = (int)w; outH = (int)h; ok = true;
                        }
                    }
                }
                pConv->Release();
            }
            pFrame->Release();
        }
        pDecoder->Release();
    }
    pStream->Release();
    pFactory->Release();
    return ok;
}
static void DownsampleBGRA(const std::vector<BYTE>& src, int srcW, int srcH,
                            std::vector<BYTE>& dst, int dstW, int dstH)
{
    dst.resize((size_t)dstW * dstH * 4);
    float xr = (float)srcW / dstW, yr = (float)srcH / dstH;
    for (int dy = 0; dy < dstH; ++dy) {
        for (int dx = 0; dx < dstW; ++dx) {
            float sx = (dx + 0.5f) * xr - 0.5f;
            float sy = (dy + 0.5f) * yr - 0.5f;
            int x0 = (int)sx; if (x0 < 0) x0 = 0;
            int y0 = (int)sy; if (y0 < 0) y0 = 0;
            int x1 = x0 + 1; if (x1 >= srcW) x1 = srcW - 1;
            int y1 = y0 + 1; if (y1 >= srcH) y1 = srcH - 1;
            float fx = sx - (float)x0; if (fx < 0) fx = 0;
            float fy = sy - (float)y0; if (fy < 0) fy = 0;
            const BYTE* p00 = &src[((size_t)y0 * srcW + x0) * 4];
            const BYTE* p10 = &src[((size_t)y0 * srcW + x1) * 4];
            const BYTE* p01 = &src[((size_t)y1 * srcW + x0) * 4];
            const BYTE* p11 = &src[((size_t)y1 * srcW + x1) * 4];
            BYTE* d = &dst[((size_t)dy * dstW + dx) * 4];
            for (int c = 0; c < 4; ++c) {
                float v = p00[c]*(1-fx)*(1-fy) + p10[c]*fx*(1-fy)
                        + p01[c]*(1-fx)*fy     + p11[c]*fx*fy;
                d[c] = (BYTE)(v < 0 ? 0 : v > 255 ? 255 : (int)v);
            }
        }
    }
}
static void ApplyBoxBlurBGRA(std::vector<BYTE>& pixels, int w, int h, int radius)
{
    if (radius < 1 || w < 1 || h < 1) return;
    std::vector<BYTE> temp(pixels.size());
    for (int y = 0; y < h; ++y) {
        for (int x = 0; x < w; ++x) {
            int r = 0, g = 0, b = 0, a = 0, count = 0;
            for (int dx = -radius; dx <= radius; ++dx) {
                int sx = x + dx;
                if (sx >= 0 && sx < w) {
                    const BYTE* p = &pixels[((size_t)y * w + sx) * 4];
                    b += p[0]; g += p[1]; r += p[2]; a += p[3];
                    count++;
                }
            }
            BYTE* d = &temp[((size_t)y * w + x) * 4];
            d[0] = (BYTE)(b / count);
            d[1] = (BYTE)(g / count);
            d[2] = (BYTE)(r / count);
            d[3] = (BYTE)(a / count);
        }
    }
    for (int y = 0; y < h; ++y) {
        for (int x = 0; x < w; ++x) {
            int r = 0, g = 0, b = 0, a = 0, count = 0;
            for (int dy = -radius; dy <= radius; ++dy) {
                int sy = y + dy;
                if (sy >= 0 && sy < h) {
                    const BYTE* p = &temp[((size_t)sy * w + x) * 4];
                    b += p[0]; g += p[1]; r += p[2]; a += p[3];
                    count++;
                }
            }
            BYTE* d = &pixels[((size_t)y * w + x) * 4];
            d[0] = (BYTE)(b / count);
            d[1] = (BYTE)(g / count);
            d[2] = (BYTE)(r / count);
            d[3] = (BYTE)(a / count);
        }
    }
}
static bool UpdateAlbumBlurBgCache(const std::vector<BYTE>& thumbBytes,
                                    int targetW, int targetH)
{
    if (thumbBytes.empty() || targetW <= 0 || targetH <= 0) {
        g_blurBgCache.Invalidate(); return false;
    }
    size_t artHash = 0;
    for (size_t i = 0; i < thumbBytes.size(); i += 512)
        artHash = artHash * 31 + thumbBytes[i];
    if (g_blurBgCache.artHash == artHash && g_blurBgCache.width == targetW &&
        g_blurBgCache.height == targetH && !g_blurBgCache.blurredPixels.empty())
        return true;
    std::vector<BYTE> srcPixels; int srcW = 0, srcH = 0;
    if (!DecodeImageToBGRA(thumbBytes, srcPixels, srcW, srcH)) return false;
    int blurDiv = 8;
    int smallW = srcW / blurDiv; if (smallW < 1) smallW = 1;
    int smallH = srcH / blurDiv; if (smallH < 1) smallH = 1;
    std::vector<BYTE> small;
    DownsampleBGRA(srcPixels, srcW, srcH, small, smallW, smallH);
    int blurRadius = std::clamp(g_settings.blurRadius, 1, 50);
    for (int i = 0; i < 3; ++i) {
        ApplyBoxBlurBGRA(small, smallW, smallH, blurRadius);
    }
    std::vector<BYTE> blurred;
    DownsampleBGRA(small, smallW, smallH, blurred, targetW, targetH);
    g_blurBgCache.blurredPixels = std::move(blurred);
    g_blurBgCache.width   = targetW;
    g_blurBgCache.height  = targetH;
    g_blurBgCache.artHash = artHash;
    return true;
}
static AlbumPalette ExtractAlbumPalette(const std::vector<BYTE>& thumbBytes) {
    const winrt::Windows::UI::Color fallbackPrimary{255, 18, 18, 18};
    const winrt::Windows::UI::Color fallbackSecondary{255, 45, 45, 45};
    if (thumbBytes.empty())
        return {fallbackPrimary, fallbackSecondary};
    try {
        std::vector<BYTE> pixels;
        int w = 0, h = 0;
        if (!DecodeImageToBGRA(thumbBytes, pixels, w, h) || w <= 0 || h <= 0 ||
            pixels.size() < (size_t)w * h * 4)
            return {fallbackPrimary, fallbackSecondary};
        struct Bucket { uint32_t r=0, g=0, b=0, n=0; };
        Bucket buckets[16][16][16]{};
        for (int y = 0; y < h; y += 4) {
            for (int x = 0; x < w; x += 4) {
                size_t idx = ((size_t)y * w + x) * 4;
                if (idx + 4 > pixels.size()) continue;
                BYTE pb = pixels[idx];
                BYTE pg = pixels[idx + 1];
                BYTE pr = pixels[idx + 2];
                int luma = (pr * 299 + pg * 587 + pb * 114) / 1000;
                if (luma < 24 || luma > 235) continue;
                auto& bk = buckets[pr >> 4][pg >> 4][pb >> 4];
                bk.r += pr; bk.g += pg; bk.b += pb; bk.n++;
            }
        }
        struct Cand { float w; BYTE r, g, b; };
        std::vector<Cand> cands;
        cands.reserve(64);
        for (int R = 0; R < 16; R++)
            for (int G = 0; G < 16; G++)
                for (int B = 0; B < 16; B++) {
                    auto& bk = buckets[R][G][B];
                    if (bk.n < 8) continue;
                    float fr = bk.r / (float)bk.n / 255.f;
                    float fg = bk.g / (float)bk.n / 255.f;
                    float fb = bk.b / (float)bk.n / 255.f;
                    float mx = std::max({fr, fg, fb});
                    float mn = std::min({fr, fg, fb});
                    float sat = mx > 0 ? (mx - mn) / mx : 0;
                    cands.push_back({bk.n * (0.3f + sat),
                                    (BYTE)(fr * 255), (BYTE)(fg * 255), (BYTE)(fb * 255)});
                }
        if (cands.empty())
            return {fallbackPrimary, fallbackSecondary};
        std::sort(cands.begin(), cands.end(),
                [](const Cand& a, const Cand& b){ return a.w > b.w; });
        winrt::Windows::UI::Color primary{255, cands[0].r, cands[0].g, cands[0].b};
        winrt::Windows::UI::Color secondary = primary;
        for (auto& c : cands) {
            int dr = (int)c.r - (int)cands[0].r;
            int dg = (int)c.g - (int)cands[0].g;
            int db = (int)c.b - (int)cands[0].b;
            if (dr*dr + dg*dg + db*db > 3264) {
                secondary = winrt::Windows::UI::Color{255, c.r, c.g, c.b};
                break;
            }
        }
        return {primary, secondary};
    } catch (...) {
        return {fallbackPrimary, fallbackSecondary};
    }
}
static DWORD GetWindowsAccentColor() {
    DWORD color = 0;
    BOOL opaque = FALSE;
    if (SUCCEEDED(DwmGetColorizationColor(&color, &opaque)))
        return 0xFF000000 | (color & 0x00FFFFFF);
    return 0xFF0078D4;
}
static winrt::Windows::UI::Color ParseColorWithSpecialValues(const std::wstring& colorStr, BYTE alpha = 255) {
    int r = 255, g = 255, b = 255;
    size_t pos1 = colorStr.find(L' ');
    size_t pos2 = colorStr.find(L' ', pos1 + 1);
    if (pos1 != std::wstring::npos && pos2 != std::wstring::npos) {
        try {
            r = std::stoi(colorStr.substr(0, pos1));
            g = std::stoi(colorStr.substr(pos1 + 1, pos2 - pos1 - 1));
            b = std::stoi(colorStr.substr(pos2 + 1));
            if (r == -1 && g == -1 && b == -1) {
                DWORD accentColor = GetWindowsAccentColor();
                return winrt::Windows::UI::Color{alpha,
                    (BYTE)((accentColor >> 16) & 0xFF),
                    (BYTE)((accentColor >> 8) & 0xFF),
                    (BYTE)(accentColor & 0xFF)};
            }
            if (r == -2 && g == -2 && b == -2) {
                if (g_cachedPaletteHash == 0) {
                    return winrt::Windows::UI::Color{0, 255, 255, 255};
                }
                return winrt::Windows::UI::Color{alpha,
                    g_cachedAlbumPalette.primary.R,
                    g_cachedAlbumPalette.primary.G,
                    g_cachedAlbumPalette.primary.B};
            }
            r = std::clamp(r, 0, 255);
            g = std::clamp(g, 0, 255);
            b = std::clamp(b, 0, 255);
        } catch (...) {}
    }
    return winrt::Windows::UI::Color{alpha, (BYTE)r, (BYTE)g, (BYTE)b};
}
static winrt::Windows::UI::Color ParseColorWithThemeSupport(const std::wstring& colorStr, BYTE alpha) {
    size_t dollarPos = colorStr.find(L'$');
    if (dollarPos != std::wstring::npos) {
        std::wstring lightColorStr = colorStr.substr(0, dollarPos);
        std::wstring darkColorStr = colorStr.substr(dollarPos + 1);
        lightColorStr.erase(0, lightColorStr.find_first_not_of(L" \t"));
        lightColorStr.erase(lightColorStr.find_last_not_of(L" \t") + 1);
        darkColorStr.erase(0, darkColorStr.find_first_not_of(L" \t"));
        darkColorStr.erase(darkColorStr.find_last_not_of(L" \t") + 1);
        if (IsSystemLightTheme()) {
            return ParseColorWithSpecialValues(lightColorStr, alpha);
        } else {
            return ParseColorWithSpecialValues(darkColorStr, alpha);
        }
    } else {
        return ParseColorWithSpecialValues(colorStr, alpha);
    }
}
static winrt::Windows::UI::Color TextColor() {
    BYTE alpha = (BYTE)((g_settings.titleColorOpacity / 100.0) * 255);
    return ParseColorWithThemeSupport(g_settings.titleColor, alpha);
}
static winrt::Windows::UI::Color ArtistColor() {
    BYTE alpha = (BYTE)((g_settings.artistColorOpacity / 100.0) * 255);
    return ParseColorWithThemeSupport(g_settings.artistColor, alpha);
}
static winrt::Windows::UI::Color ButtonColor() {
    BYTE alpha = (BYTE)((g_settings.buttonColorOpacity / 100.0) * 255);
    return ParseColorWithThemeSupport(g_settings.buttonColor, alpha);
}
static winrt::Windows::UI::Color ContextMenuIconColor() {
    BYTE alpha = (BYTE)((g_settings.contextMenuIconOpacity / 100.0) * 255);
    const std::wstring& clr = g_settings.contextMenuIconColor;
    if (clr.empty()) {
        return ParseColorWithThemeSupport(g_settings.buttonColor, alpha);
    }
    return ParseColorWithThemeSupport(clr, alpha);
}
static const std::wstring& ContextMenuIconStyle() {
    if (g_settings.contextMenuIconStyle == L"as_media_buttons")
        return g_settings.iconStyle;
    return g_settings.contextMenuIconStyle;
}
static Brush MakeAlbumBlurBrush(const std::vector<BYTE>& thumbBytes,
                                int panelW, int panelH)
{
    if (!UpdateAlbumBlurBgCache(thumbBytes, panelW, panelH) ||
        g_blurBgCache.blurredPixels.empty())
        return MakeBrush({0x00, 0x00, 0x00, 0x00});
    try {
        size_t bytesNeeded = (size_t)panelW * panelH * 4;
        WriteableBitmap wb(panelW, panelH);
        auto buf = wb.PixelBuffer();
        auto byteAccess = buf.as<Windows::Storage::Streams::IBufferByteAccess>();
        BYTE* pixels = nullptr;
        byteAccess->Buffer(&pixels);
        if (pixels && g_blurBgCache.blurredPixels.size() >= bytesNeeded)
            memcpy(pixels, g_blurBgCache.blurredPixels.data(), bytesNeeded);
        buf.Length(static_cast<uint32_t>(bytesNeeded));
        wb.Invalidate();
        ImageBrush brush;
        brush.ImageSource(wb);
        brush.Stretch(Stretch::UniformToFill);
        return brush;
    } catch (...) {}
    return MakeBrush({0x00, 0x00, 0x00, 0x00});
}
static Brush MakeBackgroundBrush() {
    auto& t = g_settings.backgroundType;
    BYTE opacity = (BYTE)((g_settings.solidOpacity / 100.0) * 255);
    auto color1 = ParseColorWithThemeSupport(g_settings.solidColor, opacity);
    auto color2 = ParseColorWithSpecialValues(g_settings.solidColor2, opacity);
    auto gradientColor2 = ParseColorWithSpecialValues(g_settings.gradientColor2, opacity);
    if (t == L"gradient") {
        try {
            winrt::Windows::UI::Xaml::Media::LinearGradientBrush brush;
            double angleRad = (g_settings.gradientAngle % 360) * 3.14159265358979323846 / 180.0;
            double startX = 0.5 - 0.5 * std::cos(angleRad);
            double startY = 0.5 - 0.5 * std::sin(angleRad);
            double endX = 0.5 + 0.5 * std::cos(angleRad);
            double endY = 0.5 + 0.5 * std::sin(angleRad);
            brush.StartPoint(winrt::Windows::Foundation::Point((float)startX, (float)startY));
            brush.EndPoint(winrt::Windows::Foundation::Point((float)endX, (float)endY));
            double balancePoint = std::clamp(g_settings.gradientBalance, 0, 100) / 100.0;
            winrt::Windows::UI::Xaml::Media::GradientStop stop1;
            stop1.Color(color2);
            stop1.Offset(0.0);
            winrt::Windows::UI::Xaml::Media::GradientStop stop2;
            stop2.Color(gradientColor2);
            stop2.Offset(balancePoint);
            winrt::Windows::UI::Xaml::Media::GradientStop stop3;
            stop3.Color(gradientColor2);
            stop3.Offset(1.0);
            brush.GradientStops().Append(stop1);
            brush.GradientStops().Append(stop2);
            brush.GradientStops().Append(stop3);
            return brush;
        } catch (...) {}
    }
    if (t == L"acrylic") {
        try {
            winrt::Windows::UI::Xaml::Media::AcrylicBrush brush;
            brush.BackgroundSource(winrt::Windows::UI::Xaml::Media::AcrylicBackgroundSource::HostBackdrop);
            auto col = winrt::Windows::UI::Color{0xFF, color1.R, color1.G, color1.B};
            brush.TintColor(col);
            brush.TintOpacity(g_settings.acrylicTintOpacity / 100.0);
            brush.FallbackColor(winrt::Windows::UI::Color{0xCC, color1.R, color1.G, color1.B});
            return brush;
        } catch (...) {}
    }
    if (t == L"mica" || t == L"mica_alt") {
        BYTE micaAlpha = (BYTE)((g_settings.micaOpacity / 100.0) * 255);
        auto col = winrt::Windows::UI::Color{micaAlpha, color1.R, color1.G, color1.B};
        return MakeBrush(col);
    }
    if (t == L"solid") {
        return MakeBrush(color1);
    }
    if (t == L"album_art_blur") {
        return MakeBrush({0x00, 0xFF, 0xFF, 0xFF});
    }
    return MakeBrush({0x00, 0xFF, 0xFF, 0xFF});
}
static FrameworkElement FindChildByName(FrameworkElement const& root, std::wstring_view name, int depth = 32) {
    if (!root || depth == 0) return nullptr;
    int n = VisualTreeHelper::GetChildrenCount(root);
    for (int i = 0; i < n; ++i) {
        auto child = VisualTreeHelper::GetChild(root, i).try_as<FrameworkElement>();
        if (!child) continue;
        if (child.Name() == name) return child;
        if (auto found = FindChildByName(child, name, depth - 1)) return found;
    }
    return nullptr;
}
static void DumpXamlTree(DependencyObject const& node, int depth, int maxDepth) {
    if (!node || depth > maxDepth) return;
    std::wstring indent(depth * 2, L' ');
    auto fe = node.try_as<FrameworkElement>();
    std::wstring name  = fe ? std::wstring(fe.Name()) : L"";
    winrt::hstring typeHstr = winrt::get_class_name(node);
    std::wstring type  = std::wstring(typeHstr);
    auto dot = type.rfind(L'.');
    if (dot != std::wstring::npos) type = type.substr(dot + 1);
    int col = fe ? Grid::GetColumn(fe) : -1;
    if (!name.empty()) Wh_Log(L"%ls[%ls] name='%ls' col=%d", indent.c_str(), type.c_str(), name.c_str(), col);
    else Wh_Log(L"%ls[%ls]", indent.c_str(), type.c_str());
    int n = VisualTreeHelper::GetChildrenCount(node);
    for (int i = 0; i < n; ++i) {
        auto child = VisualTreeHelper::GetChild(node, i);
        if (child) DumpXamlTree(child, depth + 1, maxDepth);
    }
}
static constexpr wchar_t kGridName[]        = L"FluentMediaBar";
static constexpr wchar_t kArtContainerName[]= L"FluentMedia_ArtContainer";
static constexpr wchar_t kArtImageName[]    = L"FluentMedia_Art";
static constexpr wchar_t kAppIconImageName[]= L"FluentMedia_AppIcon";
static constexpr wchar_t kNeteaseLauncherImageName[] = L"FluentMedia_NeteaseLauncher";
static constexpr wchar_t kTwilightLauncherImageName[] = L"FluentMedia_TwilightLauncher";
static constexpr wchar_t kTwilightAumid[] = L"com.TwilightEcho.music";
static constexpr wchar_t kAnchorOverlayName[]= L"FluentMedia_DebugAnchorTarget";
static constexpr wchar_t kPanelGridName[]   = L"FluentMedia_PanelGrid";
static constexpr wchar_t kTextContainerName[]= L"FluentMedia_TextContainer";
static constexpr wchar_t kTextStackName[]   = L"FluentMedia_TextStack";
static constexpr wchar_t kControlsPanelName[]= L"FluentMedia_Controls";
static constexpr wchar_t kTitleBlockName[]  = L"FluentMedia_Title";
static constexpr wchar_t kArtistBlockName[] = L"FluentMedia_Artist";
static constexpr wchar_t kPlayBtnName[]     = L"FluentMedia_Play";
static constexpr wchar_t kPrevBtnName[]     = L"FluentMedia_Prev";
static constexpr wchar_t kNextBtnName[]     = L"FluentMedia_Next";
static constexpr wchar_t kRewindBtnName[]   = L"FluentMedia_Rewind";
static constexpr wchar_t kForwardBtnName[]  = L"FluentMedia_Forward";
static constexpr wchar_t kShuffleBtnName[]  = L"FluentMedia_Shuffle";
static constexpr wchar_t kRepeatBtnName[]   = L"FluentMedia_Repeat";
static constexpr wchar_t kSwitchSessionsBtnName[] = L"FluentMedia_SwitchSessions";
static constexpr wchar_t kHeartBtnName[]    = L"FluentMedia_NeteaseHeart";
static constexpr wchar_t kHeartGlyphName[]  = L"FluentMedia_HeartGlyph";
static constexpr wchar_t kHeartQuestionName[] = L"FluentMedia_HeartQuestion";
static constexpr wchar_t kLyricsToggleBtnName[] = L"FluentMedia_LyricsToggle";
static constexpr wchar_t kSourceSwitchBtnName[] = L"FluentMedia_SourceSwitch";
static bool IsNeteaseSession(const std::wstring& appUserModelId);
static bool IsTwilightSession(const std::wstring& appUserModelId);
static bool IsSessionForPlayer(const std::wstring& appUserModelId,
                               PlayerKind player);
static void ToggleTaskbarExpanded();
static bool SyncTrackedPlayerLayout(Grid const& targetGrid);

static bool HasSelectedPlayerSession() {
    PlayerKind selectedPlayer = g_selectedPlayer.load();
    if (selectedPlayer == PlayerKind::TwilightEcho) {
        std::lock_guard<std::mutex> lock(g_mediaMtx);
        if (g_media.hasMedia && IsTwilightSession(g_media.appUserModelId)) {
            return true;
        }
    }

    GlobalSystemMediaTransportControlsSession session{nullptr};
    {
        std::lock_guard<std::mutex> lock(g_sessionMtx);
        session = g_currentSession;
    }
    if (!session) {
        if (selectedPlayer != PlayerKind::TwilightEcho) return false;
        std::lock_guard<std::mutex> lock(g_mediaMtx);
        return g_media.hasMedia &&
               IsTwilightSession(g_media.appUserModelId);
    }
    try {
        return IsSessionForPlayer(std::wstring(session.SourceAppUserModelId()),
                                  selectedPlayer);
    } catch (...) {
        return false;
    }
}

static void SetTaskbarDetailsOpacity(double opacity) {
    if (!g_playerGrid) return;
    for (const wchar_t* name : {
             kTextContainerName, L"FluentMedia_Visualizer"}) {
        if (auto element = FindChildByName(g_playerGrid, name)) {
            element.Opacity(opacity);
        }
    }
    if (auto controlsElement = FindChildByName(g_playerGrid, kControlsPanelName)) {
        if (auto controls = controlsElement.try_as<StackPanel>()) {
            for (uint32_t i = 0; i < controls.Children().Size(); ++i) {
                if (auto child = controls.Children().GetAt(i).try_as<FrameworkElement>()) {
                    if (child.Name() != kHeartBtnName) child.Opacity(opacity);
                }
            }
        }
    }
}

static void RevealTaskbarDetailsAfterLayout() {
    if (!g_taskbarDetailsRevealPending.exchange(false)) return;
    if (!g_playerGrid || !g_taskbarExpanded.load()) {
        SetTaskbarDetailsOpacity(1.0);
        return;
    }

    try {
        Storyboard storyboard;
        bool hasAnimation = false;
        auto addAnimation = [&](FrameworkElement const& element) {
            if (!element || element.Visibility() != Visibility::Visible) return;

            element.Opacity(1.0);
            DoubleAnimation animation;
            animation.From(0.0);
            animation.To(1.0);
            animation.Duration(DurationHelper::FromTimeSpan(
                std::chrono::milliseconds(120)));
            animation.FillBehavior(FillBehavior::Stop);
            auto ease = CircleEase();
            ease.EasingMode(EasingMode::EaseOut);
            animation.EasingFunction(ease);
            Storyboard::SetTarget(animation, element);
            Storyboard::SetTargetProperty(animation, L"Opacity");
            storyboard.Children().Append(animation);
            hasAnimation = true;
        };
        for (const wchar_t* name : {
                 kTextContainerName, L"FluentMedia_Visualizer"}) {
            addAnimation(FindChildByName(g_playerGrid, name));
        }
        if (auto controlsElement = FindChildByName(g_playerGrid, kControlsPanelName)) {
            if (auto controls = controlsElement.try_as<StackPanel>()) {
                for (uint32_t i = 0; i < controls.Children().Size(); ++i) {
                    if (auto child = controls.Children().GetAt(i).try_as<FrameworkElement>()) {
                        if (child.Name() != kHeartBtnName) addAnimation(child);
                    }
                }
            }
        }
        if (hasAnimation) storyboard.Begin();
    } catch (...) {
        SetTaskbarDetailsOpacity(1.0);
    }
}

static bool IsPointerPhysicallyOverTaskbarPlayer() {
    if (!g_playerGrid) return false;

    HWND taskbarWnd = g_taskbarWnd;
    POINT cursor{};
    POINT clientOrigin{};
    if (!taskbarWnd || !IsWindow(taskbarWnd) || !GetCursorPos(&cursor) ||
        !ClientToScreen(taskbarWnd, &clientOrigin)) {
        return false;
    }

    try {
        auto xamlRoot = g_playerGrid.XamlRoot();
        auto rootContent = xamlRoot
            ? xamlRoot.Content().try_as<UIElement>()
            : nullptr;
        if (!xamlRoot || !rootContent) return false;

        FrameworkElement hoverTarget = g_playerGrid;
        if (auto outer = FindChildByName(
                g_playerGrid, L"FluentMedia_OuterBorder");
            outer && outer.ActualWidth() > 0.0 &&
            outer.ActualHeight() > 0.0) {
            hoverTarget = outer;
        }
        auto bounds = hoverTarget.TransformToVisual(rootContent)
                          .TransformBounds({
                              0, 0,
                              static_cast<float>(hoverTarget.ActualWidth()),
                              static_cast<float>(hoverTarget.ActualHeight())});
        double scale = xamlRoot.RasterizationScale();
        if (!std::isfinite(scale) || scale <= 0.0) return false;

        if (bounds.Width <= 0.0 || bounds.Height <= 0.0) return false;
        double x = (static_cast<double>(cursor.x) - clientOrigin.x) / scale;
        double y = (static_cast<double>(cursor.y) - clientOrigin.y) / scale;
        return x >= bounds.X && x < bounds.X + bounds.Width &&
               y >= bounds.Y && y < bounds.Y + bounds.Height;
    } catch (...) {
        return false;
    }
}

static bool IsTaskbarPlayerEffectivelyHovered() {
    bool hovered = IsPointerPhysicallyOverTaskbarPlayer();
    g_taskbarWrapperHovered = hovered;
    return hovered;
}

static void ApplyTaskbarCompactState() {
    if (!g_playerGrid) return;

    bool hasMedia = false;
    {
        std::lock_guard<std::mutex> lock(g_mediaMtx);
        hasMedia = g_media.hasMedia;
    }

    PlayerKind selectedPlayer = g_selectedPlayer.load();
    bool hasSelectedSession = HasSelectedPlayerSession();
    bool active = hasMedia && hasSelectedSession;
    bool hovered = IsTaskbarPlayerEffectivelyHovered();
    bool twilightProcessRunning =
        selectedPlayer == PlayerKind::TwilightEcho &&
        g_twilightProcessDetected.load();
    bool showLauncher = !hasSelectedSession && !twilightProcessRunning;
    bool expanded = active &&
        (g_taskbarExpanded.load() || !g_settings.showNeteaseLyrics);
    if (!expanded && g_taskbarDetailsRevealPending.exchange(false)) {
        SetTaskbarDetailsOpacity(1.0);
    }
    auto detailsVisibility = expanded ? Visibility::Visible : Visibility::Collapsed;
    for (const wchar_t* name : {
             kTextContainerName, L"FluentMedia_Visualizer"}) {
        if (auto element = FindChildByName(g_playerGrid, name)) {
            element.Visibility(detailsVisibility);
        }
    }

    if (auto controlsElement = FindChildByName(g_playerGrid, kControlsPanelName)) {
        if (auto controls = controlsElement.try_as<StackPanel>()) {
            bool hasVisibleButton = false;
            for (uint32_t i = 0; i < controls.Children().Size(); ++i) {
                auto child = controls.Children().GetAt(i).try_as<FrameworkElement>();
                if (!child) continue;

                bool show = false;
                if (child.Name() == kHeartBtnName) {
                    show = active &&
                        selectedPlayer == PlayerKind::TwilightEcho &&
                        g_twilightFavoriteEligible.load();
                } else if (expanded) {
                    auto button = child.try_as<Button>();
                    show = !g_settings.hideUnsupportedButtons || !button ||
                           button.IsEnabled();
                }
                child.Visibility(show ? Visibility::Visible
                                      : Visibility::Collapsed);
                hasVisibleButton = hasVisibleButton || show;
            }
            controls.Margin(expanded
                ? Thickness{(double)g_settings.mediaButtonsLeftMargin, 0,
                            (double)g_settings.mediaButtonsRightMargin, 0}
                : Thickness{2, 0, 2, 0});
            controls.Visibility(active && hasVisibleButton
                ? Visibility::Visible
                : Visibility::Collapsed);
        }
    }

    if (auto artContainer = FindChildByName(g_playerGrid, kArtContainerName)) {
        artContainer.Visibility(Visibility::Visible);
    }
    if (auto toggleElement = FindChildByName(g_playerGrid, kLyricsToggleBtnName)) {
        toggleElement.Visibility(active && g_settings.showNeteaseLyrics
            ? Visibility::Visible
            : Visibility::Collapsed);
        toggleElement.Opacity(active && hovered ? 1.0 : 0.0);
        if (auto toggleButton = toggleElement.try_as<Button>()) {
            toggleButton.Background(MakeBrush(expanded
                ? winrt::Windows::UI::Color{0xF2, 0xFF, 0x3B, 0x52}
                : winrt::Windows::UI::Color{0xD8, 0x20, 0x20, 0x20}));
            toggleButton.BorderBrush(MakeBrush(expanded
                ? winrt::Windows::UI::Color{0xFF, 0xFF, 0xFF, 0xFF}
                : winrt::Windows::UI::Color{0xA0, 0xFF, 0xFF, 0xFF}));
        }
    }
    if (auto launcherElement = FindChildByName(g_playerGrid, kNeteaseLauncherImageName)) {
        launcherElement.Visibility(
            showLauncher && selectedPlayer == PlayerKind::Netease
                ? Visibility::Visible
                : Visibility::Collapsed);
    }
    if (auto launcherElement = FindChildByName(g_playerGrid, kTwilightLauncherImageName)) {
        launcherElement.Visibility(
            showLauncher && selectedPlayer == PlayerKind::TwilightEcho
                ? Visibility::Visible
                : Visibility::Collapsed);
    }
    if (auto sourceElement = FindChildByName(g_playerGrid, kSourceSwitchBtnName)) {
        sourceElement.Visibility(Visibility::Visible);
        sourceElement.Opacity(hovered ? 1.0 : 0.0);
        sourceElement.IsHitTestVisible(hovered);
        if (auto sourceButton = sourceElement.try_as<Button>()) {
            if (auto content = sourceButton.Content().try_as<TextBlock>()) {
                content.Text(selectedPlayer == PlayerKind::Netease ? L"暮" : L"云");
            }
            ToolTip tip;
            tip.Content(winrt::box_value(winrt::hstring(
                selectedPlayer == PlayerKind::Netease
                    ? UiText(L"Switch to Twilight Echo", L"切换到 Twilight Echo")
                    : UiText(L"Switch to NetEase Cloud Music", L"切换到网易云音乐"))));
            ToolTipService::SetToolTip(sourceButton, tip);
        }
    }
    if (!active) {
        for (const wchar_t* name : {
                 kArtImageName, kAppIconImageName, L"EmptyIconBorder"}) {
            if (auto element = FindChildByName(g_playerGrid, name)) {
                element.Visibility(Visibility::Collapsed);
            }
        }
    }

    if (auto panel = FindChildByName(g_playerGrid, kPanelGridName)) {
        panel.Margin(expanded ? Thickness{4, 2, 4, 2}
                              : Thickness{0, 2, 0, 2});
    }
    if (expanded && g_settings.playerMinWidth > 0) {
        g_playerGrid.MinWidth((double)g_settings.playerMinWidth);
    } else {
        g_playerGrid.MinWidth(0);
    }
    if (expanded && g_settings.playerMaxWidth > 0) {
        g_playerGrid.MaxWidth((double)g_settings.playerMaxWidth);
    } else {
        g_playerGrid.ClearValue(FrameworkElement::MaxWidthProperty());
    }
    g_playerGrid.ClearValue(FrameworkElement::WidthProperty());
}

static void ToggleTaskbarExpanded() {
    if (g_unloading || !g_playerGrid) return;

    bool hasMedia = false;
    {
        std::lock_guard<std::mutex> lock(g_mediaMtx);
        hasMedia = g_media.hasMedia;
    }
    if (!hasMedia || !HasSelectedPlayerSession()) return;

    bool expanding = !g_taskbarExpanded.load();
    g_taskbarDetailsRevealPending = expanding;
    SetTaskbarDetailsOpacity(expanding ? 0.0 : 1.0);
    g_taskbarExpanded = expanding;
    g_taskbarLayoutTransitionInProgress = true;
    try {
        ApplyTaskbarCompactState();
        g_playerGrid.UpdateLayout();

        if (auto targetGrid = g_injectionParent.try_as<Grid>()) {
            bool usesStableLeftAnchor =
                g_trackedElement && g_trackPosition == L"left" &&
                g_hasTrackedPlayerAnchorLeft &&
                g_taskbarExpanded.load();
            if (g_trackedElement) SyncTrackedPlayerLayout(targetGrid);
            targetGrid.UpdateLayout();
            if (g_trackedElement && !usesStableLeftAnchor) {
                SyncTrackedPlayerLayout(targetGrid);
                targetGrid.UpdateLayout();
            }
        }
    } catch (...) {}
    g_taskbarLayoutTransitionInProgress = false;

    if (g_settings.position == L"taskbar_left_start") {
        try {
            if (auto targetGrid = g_injectionParent.try_as<Grid>()) {
                g_trackedRootGridWidth = 0.0;
                SyncTrackedPlayerLayout(targetGrid);
                targetGrid.UpdateLayout();
            }
        } catch (...) {}
    }

    if (expanding) RevealTaskbarDetailsAfterLayout();
}
static int  g_idleSeconds  = 0;
static int  g_idleTicks    = 0;
static std::atomic<bool> g_hiddenByIdle{false};
static std::chrono::steady_clock::time_point g_lastMediaTime = std::chrono::steady_clock::now();
static void SwitchMediaSession();
static void ClearNeteaseLyrics(bool notify = true);
static void BeginTwilightTrackTransition();
static TwilightAccessiblePlayback GetTwilightAccessiblePlayback();
static TwilightAudioClock GetTwilightAudioClock();
static TwilightSessionTrack GetTwilightResolvedTrack();
static void ResetTwilightAudioState();
static int64_t ProjectTwilightAudioPosition(
    const TwilightAudioClock& playback, ULONGLONG nowTick);
static int64_t ProjectTwilightAudioPosition(
    const TwilightAudioClock& playback, ULONGLONG nowTick) {
    int64_t positionMs = playback.positionMs;
    if (playback.started && playback.state == TwilightAudioState::Playing &&
        nowTick >= playback.anchorTick) {
        positionMs += static_cast<int64_t>(
            static_cast<double>(nowTick - playback.anchorTick) *
            playback.rate);
    }
    positionMs = std::max<int64_t>(0, positionMs);
    if (playback.durationMs > 0) {
        positionMs = std::min(positionMs, playback.durationMs);
    }
    return positionMs;
}

static int64_t ProjectTwilightPosition(
    const TwilightAccessiblePlayback& playback, ULONGLONG nowTick);
static TwilightCommitResult CommitTwilightAccessiblePlayback(
    const TwilightAccessiblePlayback& state,
    std::optional<uint64_t> expectedPlaybackGeneration = std::nullopt,
    std::optional<uint64_t> expectedTrackGeneration = std::nullopt,
    bool allowForegroundIdentity = false);
static void SendMediaCommandAsync(int cmd) {
    SpawnTrackedWorker([cmd]() {
        if (g_unloading) return;
        winrt::init_apartment(winrt::apartment_type::multi_threaded);
        try {
            if (g_selectedPlayer.load() == PlayerKind::TwilightEcho) {
                const wchar_t* bridgeCommand = cmd == 1
                    ? L"previous"
                    : cmd == 2
                        ? L"toggle-play"
                        : cmd == 3
                            ? L"next"
                            : nullptr;
                if (bridgeCommand) {
                    auto disposition =
                        TrySendTwilightBridgePlaybackCommand(bridgeCommand);
                    if (disposition ==
                        TwilightBridgeCommandDisposition::Consumed) {
                        winrt::uninit_apartment();
                        return;
                    }
                }
            }
            GlobalSystemMediaTransportControlsSession session{nullptr};
            { std::lock_guard<std::mutex> lk(g_sessionMtx); session = g_currentSession; }
            if (session) {
                try {
                    if (!IsSessionForPlayer(
                            std::wstring(session.SourceAppUserModelId()),
                            g_selectedPlayer.load())) {
                        session = nullptr;
                    }
                } catch (...) {
                    session = nullptr;
                }
            }
            if (g_selectedPlayer.load() == PlayerKind::TwilightEcho &&
                cmd == 13) {
                TryToggleTwilightFavorite();
                winrt::uninit_apartment();
                return;
            }
            if (g_selectedPlayer.load() == PlayerKind::TwilightEcho &&
                !session && (cmd == 1 || cmd == 2 || cmd == 3)) {
                InvokeTwilightTransportControl(cmd);
                winrt::uninit_apartment();
                return;
            }
            if (cmd == 13) {
                winrt::uninit_apartment();
                return;
            }
            if (session) {
                switch (cmd) {
                    case 1:
                        if (session.TrySkipPreviousAsync().get()) {
                            try {
                                if (IsSessionForPlayer(
                                        std::wstring(session.SourceAppUserModelId()),
                                        g_selectedPlayer.load())) {
                                    if (g_selectedPlayer.load() ==
                                        PlayerKind::TwilightEcho) {
                                        BeginTwilightTrackTransition();
                                    } else {
                                        g_neteaseSkipSucceededTick =
                                            GetTickCount64();
                                    }
                                }
                            } catch (...) {}
                        }
                        break;
                    case 2: {
                        auto info = session.GetPlaybackInfo();
                        bool isPlaying = info &&
                            info.PlaybackStatus() == GlobalSystemMediaTransportControlsSessionPlaybackStatus::Playing;
                        if (g_selectedPlayer.load() ==
                            PlayerKind::TwilightEcho) {
                            auto accessible =
                                GetTwilightAccessiblePlayback();
                            if (accessible.reachable) {
                                isPlaying = accessible.isPlaying;
                            }
                        }
                        bool commandSucceeded = isPlaying
                            ? session.TryPauseAsync().get()
                            : session.TryPlayAsync().get();
                        bool stateChanged = false;
                        if (commandSucceeded &&
                            g_selectedPlayer.load() ==
                                PlayerKind::TwilightEcho) {
                            ULONGLONG nowTick = GetTickCount64();
                            g_twilightNextPollTick = nowTick + 250;
                            g_twilightPendingPlaybackUntilTick =
                                nowTick + 1500;
                            g_twilightPendingPlaybackState =
                                isPlaying ? 0 : 1;
                            uint64_t commandPlaybackGeneration =
                                g_twilightPlaybackCommandGeneration.fetch_add(1) +
                                1;
                            uint64_t commandTrackGeneration =
                                g_twilightTrackGeneration.load();
                            TwilightAccessiblePlayback optimistic =
                                GetTwilightAccessiblePlayback();
                            if (optimistic.reachable) {
                                optimistic.positionMs =
                                    ProjectTwilightPosition(
                                        optimistic, nowTick);
                                optimistic.isPlaying = !isPlaying;
                                optimistic.positionAdvancing = false;
                                optimistic.observedAtTick = nowTick;
                                stateChanged =
                                    CommitTwilightAccessiblePlayback(
                                        optimistic,
                                        commandPlaybackGeneration,
                                        commandTrackGeneration).changed;
                            }
                        }
                        if (stateChanged) {
                            RefreshTaskbarMediaStateNow();
                        }
                        break;
                    }
                    case 3:
                        if (session.TrySkipNextAsync().get()) {
                            try {
                                if (IsSessionForPlayer(
                                        std::wstring(session.SourceAppUserModelId()),
                                        g_selectedPlayer.load())) {
                                    if (g_selectedPlayer.load() ==
                                        PlayerKind::TwilightEcho) {
                                        BeginTwilightTrackTransition();
                                    } else {
                                        g_neteaseSkipSucceededTick =
                                            GetTickCount64();
                                    }
                                }
                            } catch (...) {}
                        }
                        break;
                    case 4:
                        try {
                            auto result = session.TryStopAsync().get();
                            if (!result) {
                                session.TryPauseAsync().get();
                                session.TryChangePlaybackPositionAsync(0).get();
                            }
                        } catch (...) {
                            try {
                                session.TryPauseAsync().get();
                                session.TryChangePlaybackPositionAsync(0).get();
                            } catch (...) {
                                Wh_Log(L"SendMediaCommandAsync: Fallback also failed");
                            }
                        }
                        break;
                    case 5:
                        try {
                            auto timeline = session.GetTimelineProperties();
                            auto currentPos = timeline.Position();
                            auto newPos = currentPos - std::chrono::seconds(5);
                            if (newPos.count() < 0) newPos = std::chrono::seconds(0);
                            session.TryChangePlaybackPositionAsync(newPos.count()).get();
                        } catch (...) {}
                        break;
                    case 6:
                        try {
                            auto timeline = session.GetTimelineProperties();
                            auto currentPos = timeline.Position();
                            auto endTime = timeline.EndTime();
                            auto newPos = currentPos + std::chrono::seconds(5);
                            if (newPos > endTime) newPos = endTime;
                            session.TryChangePlaybackPositionAsync(newPos.count()).get();
                        } catch (...) {}
                        break;
                    case 7:
                        try {
                            bool currentShuffle = g_shuffleEnabled.load();
                            if (session.TryChangeShuffleActiveAsync(!currentShuffle).get()) {
                                g_shuffleEnabled = !currentShuffle;
                                DispatchMediaUpdate();
                            }
                        } catch (...) {}
                        break;
                    case 8:
                        try {
                            RepeatMode current = g_repeatMode.load();
                            winrt::Windows::Media::MediaPlaybackAutoRepeatMode mode;
                            RepeatMode next;
                            switch (current) {
                                case RepeatMode::Off:
                                    mode = winrt::Windows::Media::MediaPlaybackAutoRepeatMode::List;
                                    next = RepeatMode::All;
                                    break;
                                case RepeatMode::All:
                                    mode = winrt::Windows::Media::MediaPlaybackAutoRepeatMode::Track;
                                    next = RepeatMode::One;
                                    break;
                                case RepeatMode::One:
                                default:
                                    mode = winrt::Windows::Media::MediaPlaybackAutoRepeatMode::None;
                                    next = RepeatMode::Off;
                                    break;
                            }
                            if (session.TryChangeAutoRepeatModeAsync(mode).get()) {
                                g_repeatMode = next;
                                DispatchMediaUpdate();
                            }
                        } catch (...) {}
                        break;
                    case 9:
                        SwitchMediaSession();
                        break;
                    case 10:
                        try {
                            if (session.TryChangeAutoRepeatModeAsync(winrt::Windows::Media::MediaPlaybackAutoRepeatMode::None).get()) {
                                g_repeatMode = RepeatMode::Off;
                                DispatchMediaUpdate();
                            }
                        } catch (...) {}
                        break;
                    case 11:
                        try {
                            if (session.TryChangeAutoRepeatModeAsync(winrt::Windows::Media::MediaPlaybackAutoRepeatMode::List).get()) {
                                g_repeatMode = RepeatMode::All;
                                DispatchMediaUpdate();
                            }
                        } catch (...) {}
                        break;
                    case 12:
                        try {
                            if (session.TryChangeAutoRepeatModeAsync(winrt::Windows::Media::MediaPlaybackAutoRepeatMode::Track).get()) {
                                g_repeatMode = RepeatMode::One;
                                DispatchMediaUpdate();
                            }
                        } catch (...) {}
                        break;
                }
            }
        } catch (...) {}
        winrt::uninit_apartment();
    });
}
static bool ReserveTwilightWheelTransition(ULONGLONG nowTick) {
    ULONGLONG pendingUntil = g_twilightPendingTrackUntilTick.load();
    for (;;) {
        if (pendingUntil > nowTick) return false;
        ULONGLONG reservedUntil = nowTick + 5000;
        if (g_twilightPendingTrackUntilTick.compare_exchange_weak(
                pendingUntil, reservedUntil)) {
            return true;
        }
    }
}

static void ShortenTwilightWheelReservationAfterBridgeDelivery() {
    ULONGLONG nowTick = GetTickCount64();
    ULONGLONG shortenedUntil = nowTick + 900;
    ULONGLONG wheelActionTick = g_lastTrackWheelActionTick.load();
    if (wheelActionTick && nowTick >= wheelActionTick &&
        nowTick - wheelActionTick <= 5000) {
        shortenedUntil = wheelActionTick + 900;
    }
    ULONGLONG pendingUntil = g_twilightPendingTrackUntilTick.load();
    while (pendingUntil > shortenedUntil &&
           !g_twilightPendingTrackUntilTick.compare_exchange_weak(
               pendingUntil, shortenedUntil)) {}
}

static bool ShouldHandleTrackWheelAction() {
    ULONGLONG nowTick = GetTickCount64();
    ULONGLONG previousTick = g_lastTrackWheelActionTick.load();
    if (previousTick && nowTick - previousTick < 250) return false;
    if (g_selectedPlayer.load() == PlayerKind::TwilightEcho &&
        !ReserveTwilightWheelTransition(nowTick)) {
        return false;
    }
    g_lastTrackWheelActionTick = nowTick;
    return true;
}
struct TextScrollState {
    double offset    = 0.0;
    double textWidth = 0.0;
    double viewWidth = 0.0;
    bool   forward   = true;
    bool   active    = false;
    bool   pausing   = false;
    int    pauseTick = 0;
    int    tickMs    = 16;
};
static TextScrollState g_titleScroll;
static TextScrollState g_artistScroll;
static void ResetScrollState(TextScrollState& s);
static void FetchMediaPropertiesAsync();
static void FetchPlaybackInfoAsync();
static void OnSessionsChanged();
static void AttachToSession(GlobalSystemMediaTransportControlsSession session);
static void SwitchMediaSession();
static void SwitchMediaSession() {
    if (g_settings.showNeteaseLyrics) {
        g_forceSessionRefresh = true;
        OnSessionsChanged();
        return;
    }
    GlobalSystemMediaTransportControlsSessionManager mgr{nullptr};
    GlobalSystemMediaTransportControlsSession curSession{nullptr};
    {
        std::lock_guard<std::mutex> lk(g_sessionMtx);
        if (!g_sessionMgr) return;
        mgr = g_sessionMgr;
        curSession = g_currentSession;
        g_userSwitchedSession = true;
    }
    if (!mgr) return;
    GlobalSystemMediaTransportControlsSession nextSession{nullptr};
    try {
        auto sessions = mgr.GetSessions();
        int count = (int)sessions.Size();
        if (count <= 1) return;
        int currentIndex = -1;
        if (curSession) {
            auto curId = curSession.SourceAppUserModelId();
            for (int i = 0; i < count; ++i) {
                if (sessions.GetAt(i).SourceAppUserModelId() == curId) {
                    currentIndex = i;
                    break;
                }
            }
        }
        int nextIndex = (currentIndex + 1) % count;
        nextSession = sessions.GetAt(nextIndex);
    } catch (...) { return; }
    if (nextSession) {
        AttachToSession(nextSession);
    }
}
static std::mutex g_deviceEnumeratorMtx;
static void InitAudioDeviceEnumerator() {
    std::lock_guard<std::mutex> lk(g_deviceEnumeratorMtx);
    if (!g_pDeviceEnumerator) {
        CoCreateInstance(
            XIID_MMDeviceEnumerator, NULL, CLSCTX_INPROC_SERVER,
            XIID_IMMDeviceEnumerator, (LPVOID*)&g_pDeviceEnumerator);
    }
}
static void CleanupAudioDeviceEnumerator() {
    std::lock_guard<std::mutex> lk(g_deviceEnumeratorMtx);
    if (g_pDeviceEnumerator) {
        g_pDeviceEnumerator->Release();
        g_pDeviceEnumerator = nullptr;
    }
}
static bool AdjustAppVolumeByAUMID(const std::wstring& aumid, float volumeDelta) {
    InitAudioDeviceEnumerator();
    std::lock_guard<std::mutex> lk(g_deviceEnumeratorMtx);
    if (!g_pDeviceEnumerator) return false;
    winrt::com_ptr<IMMDevice> defaultDevice;
    HRESULT hr = g_pDeviceEnumerator->GetDefaultAudioEndpoint(eRender, eConsole, defaultDevice.put());
    if (FAILED(hr)) return false;
    winrt::com_ptr<IAudioSessionManager2> sessionManager;
    hr = defaultDevice->Activate(XIID_IAudioSessionManager2, CLSCTX_ALL, NULL, sessionManager.put_void());
    if (FAILED(hr)) return false;
    winrt::com_ptr<IAudioSessionEnumerator> sessionEnumerator;
    hr = sessionManager->GetSessionEnumerator(sessionEnumerator.put());
    if (FAILED(hr)) return false;
    int sessionCount = 0;
    hr = sessionEnumerator->GetCount(&sessionCount);
    if (FAILED(hr)) return false;
    bool found = false;
    for (int i = 0; i < sessionCount; i++) {
        winrt::com_ptr<IAudioSessionControl> sessionControl;
        hr = sessionEnumerator->GetSession(i, sessionControl.put());
        if (FAILED(hr)) continue;
        winrt::com_ptr<IAudioSessionControl2> sessionControl2;
        hr = sessionControl->QueryInterface(__uuidof(IAudioSessionControl2), sessionControl2.put_void());
        if (FAILED(hr)) continue;
        LPWSTR sessionId = nullptr;
        hr = sessionControl2->GetSessionIdentifier(&sessionId);
        if (SUCCEEDED(hr) && sessionId) {
            std::wstring sessionIdStr(sessionId);
            CoTaskMemFree(sessionId);
            if (sessionIdStr.find(aumid) != std::wstring::npos) {
                winrt::com_ptr<ISimpleAudioVolume> vol;
                if (SUCCEEDED(sessionControl->QueryInterface(__uuidof(ISimpleAudioVolume), vol.put_void()))) {
                    float currentVolume = 0.0f;
                    if (SUCCEEDED(vol->GetMasterVolume(&currentVolume))) {
                        float newVolume = std::clamp(currentVolume + volumeDelta, 0.0f, 1.0f);
                        vol->SetMasterVolume(newVolume, NULL);
                        found = true;
                    }
                }
            }
        }
    }
    return found;
}
static void ChangeSystemVolume(bool increase) {
    InitAudioDeviceEnumerator();
    std::lock_guard<std::mutex> lk(g_deviceEnumeratorMtx);
    if (!g_pDeviceEnumerator) return;
    winrt::com_ptr<IMMDevice> defaultDevice;
    HRESULT hr = g_pDeviceEnumerator->GetDefaultAudioEndpoint(eRender, eConsole, defaultDevice.put());
    if (FAILED(hr)) return;
    winrt::com_ptr<IAudioEndpointVolume> endpointVolume;
    hr = defaultDevice->Activate(__uuidof(IAudioEndpointVolume), CLSCTX_ALL, NULL, endpointVolume.put_void());
    if (FAILED(hr)) return;
    float currentVolume = 0.0f;
    if (SUCCEEDED(endpointVolume->GetMasterVolumeLevelScalar(&currentVolume))) {
        float newVolume = currentVolume + (increase ? 0.005f : -0.005f);
        newVolume = std::clamp(newVolume, 0.0f, 1.0f);
        endpointVolume->SetMasterVolumeLevelScalar(newVolume, NULL);
    }
    HWND hShellTrayWnd = FindWindow(L"Shell_TrayWnd", nullptr);
    if (hShellTrayWnd) {
        SHORT appCommand = increase ? APPCOMMAND_VOLUME_UP : APPCOMMAND_VOLUME_DOWN;
        PostMessage(hShellTrayWnd, WM_APPCOMMAND, (WPARAM)hShellTrayWnd,
                    MAKELPARAM(0, appCommand));
    }
}
static std::wstring ToLowerCopy(std::wstring value);
static std::wstring GetWindowAppUserModelId(HWND hWnd);
static void ShowMediaContextMenu(FrameworkElement const& target);
[[maybe_unused]]
static void ExecuteMediaAction(const std::wstring& action, FrameworkElement const& sourceElement = nullptr) {
    if (action == L"none") {
        return;
    } else if (action == L"open_context_menu") {
        if (sourceElement) {
            ShowMediaContextMenu(sourceElement);
        }
        return;
    } else if (action == L"switch_session") {
        SwitchMediaSession();
    } else if (action == L"play_pause") {
        SendMediaCommandAsync(2);
    } else if (action == L"next_track") {
        SendMediaCommandAsync(3);
    } else if (action == L"prev_track") {
        SendMediaCommandAsync(1);
    } else if (action == L"stop") {
        g_forceSessionRefresh = true;
        SendMediaCommandAsync(4);
        SpawnTrackedWorker([]() {
            for (DWORD delay : {300, 1200, 2500}) {
                Sleep(delay);
                if (g_unloading) return;
                g_forceSessionRefresh = true;
                OnSessionsChanged();
                FetchPlaybackInfoAsync();
                FetchMediaPropertiesAsync();
            }
        });
    } else if (action == L"rewind_5s") {
        SendMediaCommandAsync(5);
    } else if (action == L"forward_5s") {
        SendMediaCommandAsync(6);
    } else if (action == L"toggle_shuffle") {
        SendMediaCommandAsync(7);
    } else if (action == L"toggle_repeat") {
        SendMediaCommandAsync(8);
    } else if (action == L"open_app") {
        // Opening a player is deliberately restricted to the context-menu item,
        // which invokes this action without a source element.
        if (sourceElement) return;
        SpawnTrackedWorker([]() {
            std::wstring title, appAumid;
            {
                std::lock_guard<std::mutex> lk(g_mediaMtx);
                title = g_media.title;
            }
            {
                GlobalSystemMediaTransportControlsSession sessionCopy{nullptr};
                {
                    std::lock_guard<std::mutex> lk(g_sessionMtx);
                    sessionCopy = g_currentSession;
                }
                if (sessionCopy) {
                    try {
                        appAumid = std::wstring(sessionCopy.SourceAppUserModelId());
                    } catch (...) {}
                }
            }
            if (appAumid.empty() || IsNeteaseSession(appAumid) ||
                IsTwilightSession(appAumid)) {
                PlayerKind player = g_selectedPlayer.load();
                if (!appAumid.empty()) {
                    player = IsTwilightSession(appAumid)
                        ? PlayerKind::TwilightEcho
                        : PlayerKind::Netease;
                }
                std::wstring executablePath =
                    player == PlayerKind::TwilightEcho
                        ? g_settings.twilightExecutablePath
                        : g_settings.neteaseExecutablePath;
                HINSTANCE result = nullptr;
                if (!executablePath.empty()) {
                    result = ShellExecuteW(nullptr, L"open",
                                           executablePath.c_str(),
                                           nullptr, nullptr, SW_SHOWNORMAL);
                    if ((INT_PTR)result > 32) return;
                }
                if (player == PlayerKind::TwilightEcho) {
                    result = ShellExecuteW(
                        nullptr, L"open",
                        L"shell:AppsFolder\\com.TwilightEcho.music",
                        nullptr, nullptr, SW_SHOWNORMAL);
                    if ((INT_PTR)result > 32) return;
                }
                if ((INT_PTR)result <= 32) {
                    Wh_Log(L"ExecuteMediaAction: Failed to open selected player, code=%d",
                           (int)(INT_PTR)result);
                }
                return;
            }
            struct WindowSearch {
                std::wstring targetTitle;
                std::wstring targetAumid;
                HWND aumidHwnd = nullptr;
                HWND processHwnd = nullptr;
                HWND titleHwnd = nullptr;
            };
            WindowSearch search;
            search.targetTitle = title;
            std::transform(search.targetTitle.begin(), search.targetTitle.end(), search.targetTitle.begin(), ::towlower);
            search.targetAumid = appAumid;
            std::transform(search.targetAumid.begin(), search.targetAumid.end(), search.targetAumid.begin(), ::towlower);
            EnumWindows([](HWND hwnd, LPARAM lParam) CALLBACK -> BOOL {
                if (!IsWindowVisible(hwnd)) return TRUE;
                WINDOWINFO wi{};
                wi.cbSize = sizeof(wi);
                GetWindowInfo(hwnd, &wi);
                if ((wi.dwStyle & WS_CHILD) != 0) return TRUE;
                auto* s = reinterpret_cast<WindowSearch*>(lParam);
                if (!s->aumidHwnd && !s->targetAumid.empty()) {
                    IPropertyStore* pps = nullptr;
                    if (SUCCEEDED(SHGetPropertyStoreForWindow(hwnd, IID_PPV_ARGS(&pps)))) {
                        PROPVARIANT var;
                        PropVariantInit(&var);
                        if (SUCCEEDED(pps->GetValue(PKEY_AppUserModel_ID, &var)) && var.vt == VT_LPWSTR) {
                            std::wstring winAumid(var.pwszVal);
                            std::transform(winAumid.begin(), winAumid.end(), winAumid.begin(), ::towlower);
                            if (winAumid == s->targetAumid ||
                                winAumid.find(s->targetAumid) != std::wstring::npos ||
                                s->targetAumid.find(winAumid) != std::wstring::npos) {
                                s->aumidHwnd = hwnd;
                            }
                        }
                        PropVariantClear(&var);
                        pps->Release();
                    }
                }
                if (!s->processHwnd && !s->targetAumid.empty()) {
                    DWORD pid = 0;
                    GetWindowThreadProcessId(hwnd, &pid);
                    if (pid) {
                        wchar_t procPath[MAX_PATH]{};
                        HANDLE hProc = OpenProcess(PROCESS_QUERY_LIMITED_INFORMATION, FALSE, pid);
                        if (hProc) {
                            DWORD sz = MAX_PATH;
                            QueryFullProcessImageNameW(hProc, 0, procPath, &sz);
                            CloseHandle(hProc);
                        }
                        if (procPath[0]) {
                            std::wstring stem = procPath;
                            auto slash = stem.find_last_of(L"\\/");
                            if (slash != std::wstring::npos) stem = stem.substr(slash + 1);
                            auto dot = stem.rfind(L'.');
                            if (dot != std::wstring::npos) stem = stem.substr(0, dot);
                            std::transform(stem.begin(), stem.end(), stem.begin(), ::towlower);
                            if (!stem.empty() &&
                                (s->targetAumid.find(stem) != std::wstring::npos ||
                                stem.find(s->targetAumid) != std::wstring::npos)) {
                                s->processHwnd = hwnd;
                            }
                        }
                    }
                }
                if (!s->titleHwnd && !s->targetTitle.empty()) {
                    wchar_t windowTitle[512];
                    if (GetWindowTextW(hwnd, windowTitle, 512) > 0) {
                        std::wstring wTitle(windowTitle);
                        std::transform(wTitle.begin(), wTitle.end(), wTitle.begin(), ::towlower);
                        if (wTitle.find(s->targetTitle) != std::wstring::npos) {
                            s->titleHwnd = hwnd;
                        }
                    }
                }
                return TRUE;
            }, reinterpret_cast<LPARAM>(&search));
            HWND targetWindow = search.aumidHwnd
                ? search.aumidHwnd
                : (search.processHwnd ? search.processHwnd : search.titleHwnd);
            if (targetWindow) {
                if (IsIconic(targetWindow)) {
                    ShowWindow(targetWindow, SW_RESTORE);
                }

                HWND hCurWnd = GetForegroundWindow();
                if (hCurWnd && hCurWnd != targetWindow) {
                    DWORD dwMyID = GetCurrentThreadId();
                    DWORD dwCurID = GetWindowThreadProcessId(hCurWnd, NULL);
                    AttachThreadInput(dwCurID, dwMyID, TRUE);
                    SetForegroundWindow(targetWindow);
                    BringWindowToTop(targetWindow);
                    AttachThreadInput(dwCurID, dwMyID, FALSE);
                } else {
                    SetForegroundWindow(targetWindow);
                    BringWindowToTop(targetWindow);
                }
                return;
            }
            if (!appAumid.empty()) {
                std::wstring shellPath = L"shell:AppsFolder\\" + appAumid;
                ShellExecuteW(nullptr, L"open", shellPath.c_str(), nullptr, nullptr, SW_SHOWNORMAL);
            }
        });
    }
}
static std::wstring ToLowerCopy(std::wstring value) {
    for (auto& c : value) c = towlower(c);
    return value;
}
static bool IsNeteaseSession(const std::wstring& appUserModelId) {
    return ToLowerCopy(appUserModelId).find(L"cloudmusic") != std::wstring::npos;
}
static bool IsTwilightSession(const std::wstring& appUserModelId) {
    std::wstring value = ToLowerCopy(appUserModelId);
    return value == ToLowerCopy(kTwilightAumid) ||
           value.find(L"twilightecho") != std::wstring::npos ||
           value.find(L"twilight_echo") != std::wstring::npos;
}
static bool IsTwilightProcessRunning() {
    HANDLE snapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
    if (snapshot == INVALID_HANDLE_VALUE) return false;
    PROCESSENTRY32W entry{};
    entry.dwSize = sizeof(entry);
    bool found = false;
    if (Process32FirstW(snapshot, &entry)) {
        do {
            if (_wcsicmp(entry.szExeFile, L"TwilightEcho.exe") == 0) {
                found = true;
                break;
            }
        } while (Process32NextW(snapshot, &entry));
    }
    CloseHandle(snapshot);
    return found;
}

static bool IsTwilightWindowProcess(HWND hwnd) {
    DWORD processId = 0;
    GetWindowThreadProcessId(hwnd, &processId);
    if (!processId) return false;
    HANDLE process = OpenProcess(PROCESS_QUERY_LIMITED_INFORMATION, FALSE,
                                 processId);
    if (!process) return false;
    wchar_t path[32768]{};
    DWORD pathLength = ARRAYSIZE(path);
    bool matches = QueryFullProcessImageNameW(process, 0, path, &pathLength) &&
                   _wcsicmp(PathFindFileNameW(path), L"TwilightEcho.exe") == 0;
    CloseHandle(process);
    return matches;
}

static bool HasCssClassToken(const std::wstring& className,
                             const wchar_t* token) {
    size_t tokenLength = wcslen(token);
    for (size_t offset = 0;;) {
        size_t found = className.find(token, offset);
        if (found == std::wstring::npos) return false;
        bool leftBoundary = found == 0 || iswspace(className[found - 1]);
        size_t end = found + tokenLength;
        bool rightBoundary = end == className.size() ||
                             iswspace(className[end]);
        if (leftBoundary && rightBoundary) return true;
        offset = found + 1;
    }
}

struct TwilightWindowCollector {
    std::vector<HWND> windows;
};

static BOOL CALLBACK EnumerateTwilightWindows(HWND hwnd, LPARAM lParam) {
    if (!IsTwilightWindowProcess(hwnd)) return TRUE;
    wchar_t className[128]{};
    GetClassNameW(hwnd, className, ARRAYSIZE(className));
    if (wcsncmp(className, L"Chrome_WidgetWin_", 17) != 0) return TRUE;
    auto* collector = reinterpret_cast<TwilightWindowCollector*>(lParam);
    collector->windows.push_back(hwnd);
    return TRUE;
}

static bool IsTwilightFavoriteControl(IUIAutomationElement* element) {
    if (!element) return false;
    BSTR rawClass = nullptr;
    element->get_CurrentClassName(&rawClass);
    std::wstring className = rawClass ? rawClass : L"";
    if (rawClass) SysFreeString(rawClass);
    return HasCssClassToken(className, L"favorite-btn");
}

static std::wstring AutomationElementString(
    IUIAutomationElement* element,
    HRESULT (STDMETHODCALLTYPE IUIAutomationElement::*getter)(BSTR*)) {
    if (!element) return {};
    BSTR raw = nullptr;
    if (FAILED((element->*getter)(&raw)) || !raw) return {};
    std::wstring value(raw);
    SysFreeString(raw);
    return value;
}

static TwilightWindowCollector CollectTwilightWindows() {
    TwilightWindowCollector collector;
    if (g_twilightAccessibleHost && IsWindow(g_twilightAccessibleHost) &&
        IsTwilightWindowProcess(g_twilightAccessibleHost)) {
        collector.windows.push_back(g_twilightAccessibleHost);
    }
    TwilightWindowCollector discovered;
    EnumWindows(EnumerateTwilightWindows,
                reinterpret_cast<LPARAM>(&discovered));
    for (HWND hwnd : discovered.windows) {
        if (hwnd != g_twilightAccessibleHost) collector.windows.push_back(hwnd);
    }
    return collector;
}

static TwilightAccessiblePlayback QueryTwilightAccessiblePlayback() {
    TwilightAccessiblePlayback result;
    winrt::com_ptr<IUIAutomation> automation;
    if (FAILED(CoCreateInstance(CLSID_CUIAutomation, nullptr,
                                CLSCTX_INPROC_SERVER,
                                __uuidof(IUIAutomation),
                                automation.put_void())) ||
        !automation) {
        return result;
    }
    winrt::com_ptr<IUIAutomationCondition> allCondition;
    winrt::com_ptr<IUIAutomationCondition> textCondition;
    VARIANT textType{};
    textType.vt = VT_I4;
    textType.lVal = UIA_TextControlTypeId;
    if (FAILED(automation->CreateTrueCondition(allCondition.put())) ||
        FAILED(automation->CreatePropertyCondition(
            UIA_ControlTypePropertyId, textType, textCondition.put()))) {
        return result;
    }

    auto windows = CollectTwilightWindows();
    for (HWND hwnd : windows.windows) {
        winrt::com_ptr<IUIAutomationElement> root;
        if (FAILED(automation->ElementFromHandle(hwnd, root.put())) || !root) {
            continue;
        }
        winrt::com_ptr<IUIAutomationElementArray> elements;
        if (FAILED(root->FindAll(TreeScope_Descendants, allCondition.get(),
                                 elements.put())) ||
            !elements) {
            continue;
        }
        TwilightAccessiblePlayback candidate;
        winrt::com_ptr<IUIAutomationElement> artistElement;
        bool hasPlayButton = false;
        int count = 0;
        elements->get_Length(&count);
        for (int i = 0; i < count; ++i) {
            winrt::com_ptr<IUIAutomationElement> element;
            if (FAILED(elements->GetElement(i, element.put())) || !element) {
                continue;
            }
            std::wstring className = AutomationElementString(
                element.get(), &IUIAutomationElement::get_CurrentClassName);
            std::wstring name = AutomationElementString(
                element.get(), &IUIAutomationElement::get_CurrentName);
            BOOL enabled = FALSE;
            element->get_CurrentIsEnabled(&enabled);

            bool titleElement = HasCssClassToken(className, L"player-title");
            if (titleElement && candidate.title.empty()) {
                candidate.title = name;
                if (candidate.title.empty()) {
                    winrt::com_ptr<IUIAutomationElement> text;
                    if (SUCCEEDED(element->FindFirst(
                            TreeScope_Descendants, textCondition.get(),
                            text.put())) && text) {
                        candidate.title = AutomationElementString(
                            text.get(), &IUIAutomationElement::get_CurrentName);
                    }
                }
            } else if (HasCssClassToken(className, L"player-artist")) {
                candidate.artist = name;
                artistElement = element;
            } else if (HasCssClassToken(className, L"ctrl-btn") &&
                       HasCssClassToken(className, L"previous-button")) {
                candidate.canSkipPrevious = enabled != FALSE;
            } else if (HasCssClassToken(className, L"ctrl-btn") &&
                       HasCssClassToken(className, L"btn-play")) {
                hasPlayButton = true;
                candidate.canTogglePlay = enabled != FALSE;
                candidate.isPlaying =
                    HasCssClassToken(className, L"is-playing");
            } else if (HasCssClassToken(className, L"ctrl-btn") &&
                       HasCssClassToken(className, L"next-button")) {
                candidate.canSkipNext = enabled != FALSE;
            } else if (HasCssClassToken(className, L"progress-slider")) {
                winrt::com_ptr<IUIAutomationRangeValuePattern> range;
                if (SUCCEEDED(element->GetCurrentPatternAs(
                        UIA_RangeValuePatternId,
                        __uuidof(IUIAutomationRangeValuePattern),
                        range.put_void())) && range) {
                    double value = 0;
                    double maximum = 0;
                    if (SUCCEEDED(range->get_CurrentValue(&value)) &&
                        SUCCEEDED(range->get_CurrentMaximum(&maximum))) {
                        candidate.positionMs = static_cast<int64_t>(
                            std::max(0.0, value) * 1000.0);
                        candidate.rawPositionMs = candidate.positionMs;
                        candidate.durationMs = static_cast<int64_t>(
                            std::max(0.0, maximum) * 1000.0);
                    }
                }
            }

            if (IsTwilightFavoriteControl(element.get())) {
                winrt::com_ptr<IUIAutomationTogglePattern> toggle;
                if (SUCCEEDED(element->GetCurrentPatternAs(
                        UIA_TogglePatternId,
                        __uuidof(IUIAutomationTogglePattern),
                        toggle.put_void())) && toggle) {
                    ToggleState state = ToggleState_Indeterminate;
                    if (SUCCEEDED(toggle->get_CurrentToggleState(&state))) {
                        candidate.favoriteState = state == ToggleState_On
                            ? NeteaseLikeState::Liked
                            : (state == ToggleState_Off
                                   ? NeteaseLikeState::Unliked
                                   : NeteaseLikeState::Unknown);
                    }
                }
            }
        }
        if (candidate.title.empty() && artistElement) {
            winrt::com_ptr<IUIAutomationTreeWalker> rawWalker;
            winrt::com_ptr<IUIAutomationElement> playerBar;
            if (SUCCEEDED(automation->get_RawViewWalker(rawWalker.put())) &&
                rawWalker &&
                SUCCEEDED(rawWalker->GetParentElement(
                    artistElement.get(), playerBar.put())) && playerBar) {
                winrt::com_ptr<IUIAutomationElement> child;
                if (SUCCEEDED(rawWalker->GetFirstChildElement(
                        playerBar.get(), child.put()))) {
                    while (child) {
                        std::wstring childClass = AutomationElementString(
                            child.get(),
                            &IUIAutomationElement::get_CurrentClassName);
                        if (HasCssClassToken(childClass, L"player-title")) {
                            candidate.title = AutomationElementString(
                                child.get(),
                                &IUIAutomationElement::get_CurrentName);
                            if (candidate.title.empty()) {
                                winrt::com_ptr<IUIAutomationElement> text;
                                if (SUCCEEDED(rawWalker->GetFirstChildElement(
                                        child.get(), text.put())) && text) {
                                    candidate.title = AutomationElementString(
                                        text.get(),
                                        &IUIAutomationElement::get_CurrentName);
                                }
                            }
                            break;
                        }
                        winrt::com_ptr<IUIAutomationElement> next;
                        if (FAILED(rawWalker->GetNextSiblingElement(
                                child.get(), next.put()))) {
                            break;
                        }
                        child = std::move(next);
                    }
                }
            }
        }
        candidate.reachable = hasPlayButton && !candidate.title.empty();
        if (candidate.reachable) {
            DWORD foregroundPid = 0;
            DWORD candidatePid = 0;
            GetWindowThreadProcessId(GetForegroundWindow(), &foregroundPid);
            GetWindowThreadProcessId(hwnd, &candidatePid);
            candidate.observedForeground =
                foregroundPid != 0 && foregroundPid == candidatePid;
        }
        candidate.observedAtTick = GetTickCount64();
        if (candidate.reachable) {
            g_twilightAccessibleHost = hwnd;
            return candidate;
        }
    }
    return result;
}

static TwilightStoreResult StoreTwilightAccessiblePlayback(
    const TwilightAccessiblePlayback& state,
    std::optional<uint64_t> expectedPlaybackGeneration = std::nullopt,
    std::optional<uint64_t> expectedTrackGeneration = std::nullopt) {
    std::lock_guard<std::mutex> lock(g_twilightAccessiblePlaybackMtx);
    if ((expectedPlaybackGeneration &&
         *expectedPlaybackGeneration !=
             g_twilightPlaybackCommandGeneration.load()) ||
        (expectedTrackGeneration &&
         *expectedTrackGeneration != g_twilightTrackGeneration.load())) {
        return TwilightStoreResult::Rejected;
    }
    TwilightAccessiblePlayback next = state;
    bool sameTrack = g_twilightAccessiblePlayback.reachable &&
        next.reachable &&
        ((!g_twilightAccessiblePlayback.trackId.empty() &&
          !next.trackId.empty())
             ? g_twilightAccessiblePlayback.trackId == next.trackId
             : g_twilightAccessiblePlayback.title == next.title &&
                   g_twilightAccessiblePlayback.artist == next.artist);
    bool trackIdentityChanged =
        g_twilightAccessiblePlayback.reachable != next.reachable ||
        (next.reachable && !sameTrack);
    bool samePlayback = sameTrack &&
        g_twilightAccessiblePlayback.isPlaying == next.isPlaying;
    bool missingTimeline =
        samePlayback && next.durationMs <= 0 &&
        g_twilightAccessiblePlayback.durationMs > 0;
    if (samePlayback && !next.isPlaying) {
        next.positionMs = g_twilightAccessiblePlayback.positionMs;
        next.observedAtTick =
            g_twilightAccessiblePlayback.observedAtTick;
        next.positionAdvancing = false;
        if (next.durationMs <= 0) {
            next.durationMs = g_twilightAccessiblePlayback.durationMs;
        }
    } else if (missingTimeline && next.rawPositionMs <= 0) {
        next.durationMs = g_twilightAccessiblePlayback.durationMs;
        next.rawPositionMs =
            g_twilightAccessiblePlayback.rawPositionMs;
        next.positionMs = g_twilightAccessiblePlayback.positionMs;
        next.observedAtTick =
            g_twilightAccessiblePlayback.observedAtTick;
        next.positionAdvancing =
            next.isPlaying &&
            g_twilightAccessiblePlayback.positionAdvancing;
    } else if (samePlayback && next.isPlaying &&
               next.rawPositionMs ==
                   g_twilightAccessiblePlayback.rawPositionMs) {
        next.positionMs = g_twilightAccessiblePlayback.positionMs;
        next.observedAtTick =
            g_twilightAccessiblePlayback.observedAtTick;
        next.positionAdvancing =
            g_twilightAccessiblePlayback.positionAdvancing;
    } else {
        if (missingTimeline) {
            next.durationMs = g_twilightAccessiblePlayback.durationMs;
        }
        next.positionAdvancing =
            samePlayback && next.isPlaying &&
            next.rawPositionMs >
                g_twilightAccessiblePlayback.rawPositionMs;
    }
    bool changed =
        g_twilightAccessiblePlayback.reachable != next.reachable ||
        g_twilightAccessiblePlayback.trackId != next.trackId ||
        g_twilightAccessiblePlayback.title != next.title ||
        g_twilightAccessiblePlayback.artist != next.artist ||
        g_twilightAccessiblePlayback.isPlaying != next.isPlaying ||
        g_twilightAccessiblePlayback.canTogglePlay != next.canTogglePlay ||
        g_twilightAccessiblePlayback.canSkipPrevious != next.canSkipPrevious ||
        g_twilightAccessiblePlayback.canSkipNext != next.canSkipNext;
    if (trackIdentityChanged &&
        (!g_twilightSessionAuthorityActive.load() ||
         IsTwilightBridgeAuthorityActive())) {
        g_twilightTrackGeneration.fetch_add(1);
        g_twilightPendingOldTrackKey.clear();
        g_twilightPendingTrackUntilTick = 0;
    }
    g_twilightAccessiblePlayback = std::move(next);
    return changed ? TwilightStoreResult::Changed
                   : TwilightStoreResult::Unchanged;
}

static TwilightAccessiblePlayback GetTwilightAccessiblePlayback() {
    std::lock_guard<std::mutex> lock(g_twilightAccessiblePlaybackMtx);
    return g_twilightAccessiblePlayback;
}

static TwilightAudioClock GetTwilightAudioClock() {
    std::lock_guard<std::mutex> lock(g_twilightAudioMtx);
    return g_twilightAudioClock;
}

static TwilightSessionTrack GetTwilightResolvedTrack() {
    std::lock_guard<std::mutex> lock(g_twilightAudioMtx);
    return g_twilightResolvedTrack;
}

static bool ShouldAcceptTwilightUiaIdentity(
    const TwilightAccessiblePlayback& state,
    bool allowForegroundIdentity) {
    TwilightAudioClock audioClock = GetTwilightAudioClock();
    if (audioClock.valid && !audioClock.started) return false;
    if (allowForegroundIdentity && state.reachable) return true;
    TwilightSessionTrack resolved = GetTwilightResolvedTrack();
    if (g_twilightSessionAuthorityActive.load()) {
        return resolved.valid && state.reachable &&
               state.title == resolved.title &&
               state.artist == resolved.artist;
    }
    if (!audioClock.valid) return true;
    return resolved.valid &&
           resolved.fingerprint == audioClock.fingerprint &&
           state.reachable && state.title == resolved.title &&
           state.artist == resolved.artist;
}

static std::wstring TwilightTrackKey(
    const TwilightAccessiblePlayback& state) {
    if (!state.reachable) return {};
    return !state.trackId.empty()
        ? L"id:" + state.trackId
        : state.title + L"\x1f" + state.artist;
}

static void ExtendTwilightTrackTransitionUntil(ULONGLONG deadline) {
    ULONGLONG current = g_twilightPendingTrackUntilTick.load();
    while (current < deadline &&
           !g_twilightPendingTrackUntilTick.compare_exchange_weak(
               current, deadline)) {}
}

static void BeginTwilightTrackTransition() {
    if (g_selectedPlayer.load() != PlayerKind::TwilightEcho) return;
    ULONGLONG nowTick = GetTickCount64();
    {
        std::lock_guard<std::mutex> lock(g_twilightAccessiblePlaybackMtx);
        g_twilightPendingOldTrackKey =
            TwilightTrackKey(g_twilightAccessiblePlayback);
        ULONGLONG graceUntil = nowTick + 5000;
        ExtendTwilightTrackTransitionUntil(graceUntil);
        g_twilightAccessiblePlayback.positionAdvancing = false;
        g_twilightTrackGeneration.fetch_add(1);
        g_twilightCoverGeneration.fetch_add(1);
    }
    if (g_selectedPlayer.load() != PlayerKind::TwilightEcho) return;
    g_twilightNextPollTick = 0;
    SetTwilightLikeState(NeteaseLikeState::Unknown, false);
    ClearNeteaseLyrics(false);
    DispatchMediaUpdate();
    if (g_timerUpdateEvent) SetEvent(g_timerUpdateEvent);
}

static bool ApplyTwilightAccessibleToMedia(
    const TwilightAccessiblePlayback& state) {
    if (g_selectedPlayer.load() != PlayerKind::TwilightEcho) return false;
    uint64_t trackGeneration = g_twilightTrackGeneration.load();
    bool hasTrack = state.reachable && !state.title.empty();
    bool changed = false;
    bool trackChanged = false;
    {
        std::lock_guard<std::mutex> lock(g_mediaMtx);
        changed =
            g_media.title != (hasTrack ? state.title : L"") ||
            g_media.artist != (hasTrack ? state.artist : L"") ||
            g_media.appUserModelId != (hasTrack ? kTwilightAumid : L"") ||
            g_media.isPlaying != (hasTrack && state.isPlaying) ||
            g_media.hasMedia != hasTrack ||
            g_media.canSkipPrevious != (hasTrack && state.canSkipPrevious) ||
            g_media.canSkipNext != (hasTrack && state.canSkipNext) ||
            g_media.canShuffle || g_media.canRepeat || g_media.canSeek;
        trackChanged = g_media.appUserModelId != kTwilightAumid ||
                       g_media.title != state.title ||
                       g_media.artist != state.artist ||
                       (!state.trackId.empty() &&
                        g_twilightAppliedTrackId != state.trackId) ||
                       (!state.coverSource.empty() &&
                        g_twilightAppliedCoverSource !=
                            state.coverSource);
        g_media.title = hasTrack ? state.title : L"";
        g_media.artist = hasTrack ? state.artist : L"";
        g_media.appUserModelId = hasTrack ? kTwilightAumid : L"";
        g_media.isPlaying = hasTrack && state.isPlaying;
        g_media.hasMedia = hasTrack;
        g_media.canSkipPrevious = hasTrack && state.canSkipPrevious;
        g_media.canSkipNext = hasTrack && state.canSkipNext;
        g_media.canShuffle = false;
        g_media.canRepeat = false;
        g_media.canSeek = false;
        g_twilightAppliedTrackId = hasTrack ? state.trackId : L"";
        g_twilightAppliedCoverSource = hasTrack
            ? state.coverSource
            : L"";
        if (trackChanged || !hasTrack) {
            g_media.thumbnailBytes.clear();
            g_media.thumbnailHash = 0;
            g_media.thumbnailStreamSize = 0;
            g_media.appIconBytes.clear();
            g_media.appIconKey.clear();
        }
    }
    if (trackChanged) {
        ClearNeteaseLyrics(false);
        if (hasTrack) {
            ScheduleTwilightAccessibleCoverFetch(
                state.title, state.artist, state.durationMs,
                trackGeneration, state.coverSource);
            FetchMediaPropertiesAsync();
        } else {
            g_twilightCoverGeneration.fetch_add(1);
        }
    }
    return changed || trackChanged;
}

static TwilightCommitResult CommitTwilightAccessiblePlayback(
    const TwilightAccessiblePlayback& state,
    std::optional<uint64_t> expectedPlaybackGeneration,
    std::optional<uint64_t> expectedTrackGeneration,
    bool allowForegroundIdentity) {
    TwilightCommitResult result;
    TwilightAccessiblePlayback authoritative = state;
    TwilightAudioClock audioClock = GetTwilightAudioClock();
    TwilightSessionTrack resolved = GetTwilightResolvedTrack();
    bool sessionAuthority = g_twilightSessionAuthorityActive.load();
    bool acceptUiaIdentity = ShouldAcceptTwilightUiaIdentity(
        state, allowForegroundIdentity);
    if (sessionAuthority && allowForegroundIdentity && state.reachable &&
        resolved.valid &&
        (state.title != resolved.title || state.artist != resolved.artist)) {
        std::lock_guard<std::mutex> lock(g_twilightAudioMtx);
        if (g_twilightSessionAuthorityActive.load() &&
            g_twilightResolvedTrack.id == resolved.id &&
            g_twilightResolvedTrack.queueEntryId == resolved.queueEntryId) {
            g_twilightResolvedTrack = {};
            g_twilightSessionAuthorityActive = false;
            g_twilightAudioIdentityPending = g_twilightAudioClock.valid;
            sessionAuthority = false;
            resolved = {};
        } else {
            sessionAuthority = g_twilightSessionAuthorityActive.load();
            resolved = g_twilightResolvedTrack;
            audioClock = g_twilightAudioClock;
        }
    }
    if (sessionAuthority) {
        if (!resolved.valid) {
            return result;
        }
        if (!acceptUiaIdentity) {
            TwilightAccessiblePlayback previous =
                GetTwilightAccessiblePlayback();
            authoritative = {};
            authoritative.canTogglePlay = previous.canTogglePlay;
            authoritative.canSkipPrevious = previous.canSkipPrevious;
            authoritative.canSkipNext = previous.canSkipNext;
            authoritative.favoriteState = NeteaseLikeState::Unknown;
        }
        authoritative.reachable = true;
        authoritative.title = resolved.title;
        authoritative.artist = resolved.artist;
        authoritative.durationMs = resolved.durationMs;
        if (audioClock.valid && audioClock.started &&
            resolved.fingerprint == audioClock.fingerprint) {
            authoritative.isPlaying =
                audioClock.state == TwilightAudioState::Playing;
            authoritative.rawPositionMs = audioClock.positionMs;
            authoritative.positionMs = audioClock.positionMs;
            authoritative.durationMs = audioClock.durationMs > 0
                ? audioClock.durationMs
                : resolved.durationMs;
            authoritative.observedAtTick = audioClock.anchorTick;
            authoritative.positionAdvancing = authoritative.isPlaying;
        }
        if (!acceptUiaIdentity) {
            authoritative.favoriteState = NeteaseLikeState::Unknown;
        }
    } else if (audioClock.valid && !acceptUiaIdentity) {
        // The audio process has changed source, but the exact track identity
        // isn't resolved yet. Don't let stale background UIA restore the old song.
        return result;
    }
    authoritative.observedForeground = false;
    auto storeResult = StoreTwilightAccessiblePlayback(
        authoritative, expectedPlaybackGeneration, expectedTrackGeneration);
    result.accepted = storeResult != TwilightStoreResult::Rejected;
    result.state = GetTwilightAccessiblePlayback();
    if (!result.accepted) return result;

    if (!acceptUiaIdentity && !sessionAuthority) {
        return result;
    }
    bool mediaChanged = ApplyTwilightAccessibleToMedia(result.state);
    result.changed = storeResult == TwilightStoreResult::Changed ||
                     mediaChanged;
    if (result.changed) DispatchMediaUpdate();
    return result;
}

static bool InvokeTwilightTransportControl(int cmd) {
    const wchar_t* classToken = cmd == 1 ? L"previous-button"
                              : cmd == 2 ? L"btn-play"
                              : cmd == 3 ? L"next-button"
                                         : nullptr;
    if (!classToken) return false;
    winrt::com_ptr<IUIAutomation> automation;
    if (FAILED(CoCreateInstance(CLSID_CUIAutomation, nullptr,
                                CLSCTX_INPROC_SERVER,
                                __uuidof(IUIAutomation),
                                automation.put_void())) ||
        !automation) {
        return false;
    }
    VARIANT buttonType{};
    buttonType.vt = VT_I4;
    buttonType.lVal = UIA_ButtonControlTypeId;
    winrt::com_ptr<IUIAutomationCondition> buttonCondition;
    if (FAILED(automation->CreatePropertyCondition(
            UIA_ControlTypePropertyId, buttonType, buttonCondition.put()))) {
        return false;
    }
    auto windows = CollectTwilightWindows();
    for (HWND hwnd : windows.windows) {
        winrt::com_ptr<IUIAutomationElement> root;
        winrt::com_ptr<IUIAutomationElementArray> buttons;
        if (FAILED(automation->ElementFromHandle(hwnd, root.put())) || !root ||
            FAILED(root->FindAll(TreeScope_Descendants, buttonCondition.get(),
                                 buttons.put())) ||
            !buttons) {
            continue;
        }
        int count = 0;
        buttons->get_Length(&count);
        for (int i = 0; i < count; ++i) {
            winrt::com_ptr<IUIAutomationElement> element;
            if (FAILED(buttons->GetElement(i, element.put())) || !element) {
                continue;
            }
            std::wstring className = AutomationElementString(
                element.get(), &IUIAutomationElement::get_CurrentClassName);
            if (!HasCssClassToken(className, L"ctrl-btn") ||
                !HasCssClassToken(className, classToken)) {
                continue;
            }
            bool wasPlaying =
                HasCssClassToken(className, L"is-playing");
            BOOL enabled = FALSE;
            element->get_CurrentIsEnabled(&enabled);
            if (!enabled) return false;
            winrt::com_ptr<IUIAutomationInvokePattern> invoke;
            if (SUCCEEDED(element->GetCurrentPatternAs(
                    UIA_InvokePatternId,
                    __uuidof(IUIAutomationInvokePattern),
                    invoke.put_void())) && invoke &&
                SUCCEEDED(invoke->Invoke())) {
                g_twilightAccessibleHost = hwnd;
                if (cmd == 2) {
                    ULONGLONG nowTick = GetTickCount64();
                    g_twilightNextPollTick = nowTick + 250;
                    uint64_t commandPlaybackGeneration =
                        g_twilightPlaybackCommandGeneration.fetch_add(1) + 1;
                    uint64_t commandTrackGeneration =
                        g_twilightTrackGeneration.load();
                    g_twilightPendingPlaybackUntilTick = nowTick + 1500;
                    g_twilightPendingPlaybackState = wasPlaying ? 0 : 1;
                    TwilightAccessiblePlayback optimistic =
                        GetTwilightAccessiblePlayback();
                    if (optimistic.reachable) {
                        optimistic.positionMs = ProjectTwilightPosition(
                            optimistic, nowTick);
                        optimistic.isPlaying = !wasPlaying;
                        optimistic.positionAdvancing = false;
                        optimistic.observedAtTick = nowTick;
                        auto committed =
                            CommitTwilightAccessiblePlayback(
                                optimistic, commandPlaybackGeneration,
                                commandTrackGeneration);
                        if (committed.changed) {
                            RefreshTaskbarMediaStateNow();
                        }
                    }
                } else {
                    g_twilightNextPollTick = 0;
                }
                if (cmd == 1 || cmd == 3) {
                    BeginTwilightTrackTransition();
                }
                if (g_timerUpdateEvent) SetEvent(g_timerUpdateEvent);
                return true;
            }
        }
    }
    return false;
}

static bool IsSessionForPlayer(const std::wstring& appUserModelId,
                               PlayerKind player) {
    return player == PlayerKind::TwilightEcho
        ? IsTwilightSession(appUserModelId)
        : IsNeteaseSession(appUserModelId);
}
static std::wstring PathFileStem(std::wstring path) {
    auto slash = path.find_last_of(L"\\/");
    if (slash != std::wstring::npos) path = path.substr(slash + 1);
    auto dot = path.rfind(L'.');
    if (dot != std::wstring::npos) path = path.substr(0, dot);
    return path;
}
static std::wstring TrimCopy(std::wstring value) {
    const wchar_t* ws = L" \t\r\n";
    size_t first = value.find_first_not_of(ws);
    if (first == std::wstring::npos) return L"";
    size_t last = value.find_last_not_of(ws);
    return value.substr(first, last - first + 1);
}
static bool IsIgnoredMediaApp(const std::wstring& appUserModelId) {
    if (g_settings.showNeteaseLyrics &&
        IsSessionForPlayer(appUserModelId, g_selectedPlayer.load())) {
        return false;
    }
    if (g_settings.ignoredProcesses.empty() || appUserModelId.empty()) return false;
    std::wstring appLower = ToLowerCopy(appUserModelId);
    std::wstring appStemLower = ToLowerCopy(PathFileStem(appUserModelId));
    size_t start = 0;
    while (start <= g_settings.ignoredProcesses.size()) {
        size_t end = g_settings.ignoredProcesses.find(L';', start);
        std::wstring item = TrimCopy(g_settings.ignoredProcesses.substr(
            start, end == std::wstring::npos ? std::wstring::npos : end - start));
        if (!item.empty()) {
            std::wstring itemLower = ToLowerCopy(item);
            std::wstring itemStemLower = ToLowerCopy(PathFileStem(item));
            if (appLower == itemLower ||
                appStemLower == itemStemLower ||
                appLower.find(itemLower) != std::wstring::npos ||
                appLower.find(itemStemLower) != std::wstring::npos) {
                return true;
            }
        }
        if (end == std::wstring::npos) break;
        start = end + 1;
    }
    return false;
}
static bool IsBrowserAumid(const std::wstring& appUserModelId) {
    if (appUserModelId.empty()) return false;
    static const wchar_t* kBrowserSubstrings[] = {
        L"chrome", L"msedge", L"firefox", L"opera", L"brave", L"vivaldi"
    };
    std::wstring lower = ToLowerCopy(appUserModelId);
    for (auto* needle : kBrowserSubstrings) {
        if (lower.find(needle) != std::wstring::npos) return true;
    }
    return false;
}

static constexpr GUID kNeteaseIAccessibleGuid = {
    0x618736e0, 0x3c3d, 0x11cf,
    {0x81, 0x0c, 0x00, 0xaa, 0x00, 0x38, 0x9b, 0x71}};

static std::wstring GetAccessibleName(IAccessible* accessible, VARIANT child) {
    if (!accessible) return {};
    BSTR name = nullptr;
    HRESULT hr = accessible->get_accName(child, &name);
    if (FAILED(hr) || !name) {
        if (name) SysFreeString(name);
        return {};
    }
    std::wstring result(name, SysStringLen(name));
    SysFreeString(name);
    return result;
}

static bool IsNeteaseBrowserHostWindow(HWND hWnd) {
    wchar_t className[128]{};
    if (!GetClassNameW(hWnd, className, ARRAYSIZE(className)) ||
        _wcsicmp(className, L"OrpheusBrowserHost") != 0) {
        return false;
    }
    DWORD pid = 0;
    GetWindowThreadProcessId(hWnd, &pid);
    if (!pid) return false;
    wchar_t processPath[MAX_PATH]{};
    HANDLE process = OpenProcess(PROCESS_QUERY_LIMITED_INFORMATION, FALSE, pid);
    if (!process) return false;
    DWORD size = ARRAYSIZE(processPath);
    BOOL queried = QueryFullProcessImageNameW(process, 0, processPath, &size);
    CloseHandle(process);
    if (!queried) return false;
    return ToLowerCopy(PathFileStem(processPath)).find(L"cloudmusic") !=
           std::wstring::npos;
}

struct NeteaseBrowserHostCollector {
    std::vector<HWND> hosts;
};

static BOOL CALLBACK CollectNeteaseBrowserHost(HWND hWnd, LPARAM param) {
    auto* collector = reinterpret_cast<NeteaseBrowserHostCollector*>(param);
    if (IsNeteaseBrowserHostWindow(hWnd) &&
        std::find(collector->hosts.begin(), collector->hosts.end(), hWnd) ==
            collector->hosts.end()) {
        collector->hosts.push_back(hWnd);
    }
    return collector->hosts.size() < 16;
}

static BOOL CALLBACK EnumerateNeteaseBrowserHosts(HWND hWnd, LPARAM param) {
    CollectNeteaseBrowserHost(hWnd, param);
    auto* collector = reinterpret_cast<NeteaseBrowserHostCollector*>(param);
    if (collector->hosts.size() < 16) {
        EnumChildWindows(hWnd, CollectNeteaseBrowserHost, param);
    }
    return collector->hosts.size() < 16;
}

static std::optional<double> NeteaseProgressRatioFromGeometry(
    LONG fillWidth, LONG totalWidth) {
    if (totalWidth <= 0 || fillWidth < 0) return std::nullopt;
    return std::clamp(static_cast<double>(fillWidth) /
                          static_cast<double>(totalWidth),
                      0.0, 1.0);
}

static int64_t NeteasePositionFromProgressRatio(double ratio,
                                                int64_t durationMs) {
    if (durationMs <= 0) return 0;
    return static_cast<int64_t>(std::llround(
        std::clamp(ratio, 0.0, 1.0) * static_cast<double>(durationMs)));
}

static std::optional<double> InspectNeteaseProgressTree(
    winrt::com_ptr<IAccessible> root) {
    struct AccessibleNode {
        winrt::com_ptr<IAccessible> accessible;
        int depth;
    };
    std::vector<AccessibleNode> stack;
    stack.push_back({std::move(root), 0});
    int nodesVisited = 0;

    while (!stack.empty() && nodesVisited < 10000) {
        AccessibleNode node = std::move(stack.back());
        stack.pop_back();
        ++nodesVisited;

        VARIANT self{};
        self.vt = VT_I4;
        self.lVal = CHILDID_SELF;
        if (GetAccessibleName(node.accessible.get(), self) ==
            L"\u64AD\u653E\u8FDB\u5EA6\u8C03\u8282") {
            LONG progressChildCount = 0;
            if (FAILED(node.accessible->get_accChildCount(
                    &progressChildCount)) || progressChildCount != 4) {
                continue;
            }
            LONG left = 0, top = 0, totalWidth = 0, height = 0;
            if (SUCCEEDED(node.accessible->accLocation(
                    &left, &top, &totalWidth, &height, self)) &&
                totalWidth >= 100 && height > 0 && height <= 10) {
                VARIANT fillChild{};
                VariantInit(&fillChild);
                LONG obtained = 0;
                HRESULT childrenResult = AccessibleChildren(
                    node.accessible.get(), 2, 1, &fillChild, &obtained);
                if (SUCCEEDED(childrenResult) && obtained == 1 &&
                    fillChild.vt == VT_DISPATCH && fillChild.pdispVal) {
                    winrt::com_ptr<IAccessible> fillAccessible;
                    if (SUCCEEDED(fillChild.pdispVal->QueryInterface(
                            kNeteaseIAccessibleGuid,
                            fillAccessible.put_void()))) {
                        VARIANT fillSelf{};
                        fillSelf.vt = VT_I4;
                        fillSelf.lVal = CHILDID_SELF;
                        LONG fillLeft = 0, fillTop = 0, fillWidth = 0,
                             fillHeight = 0;
                        if (SUCCEEDED(fillAccessible->accLocation(
                                &fillLeft, &fillTop, &fillWidth, &fillHeight,
                                fillSelf)) &&
                            fillLeft == left && fillTop == top &&
                            fillHeight == height && fillWidth <= totalWidth) {
                            auto ratio = NeteaseProgressRatioFromGeometry(
                                fillWidth, totalWidth);
                            if (ratio) {
                                VariantClear(&fillChild);
                                return ratio;
                            }
                        }
                    }
                }
                VariantClear(&fillChild);
            }
        }

        if (node.depth >= 32) continue;
        LONG childCount = 0;
        if (FAILED(node.accessible->get_accChildCount(&childCount)) ||
            childCount <= 0) {
            continue;
        }
        for (LONG start = 0; start < childCount && nodesVisited < 10000;) {
            LONG batchSize = std::min<LONG>(childCount - start, 256);
            std::vector<VARIANT> children(static_cast<size_t>(batchSize));
            for (auto& child : children) VariantInit(&child);
            LONG obtained = 0;
            HRESULT hr = AccessibleChildren(node.accessible.get(), start,
                                            batchSize, children.data(),
                                            &obtained);
            if (FAILED(hr) || obtained <= 0) {
                for (auto& child : children) VariantClear(&child);
                break;
            }
            for (LONG i = 0; i < obtained; ++i) {
                VARIANT& child = children[static_cast<size_t>(i)];
                if (child.vt == VT_DISPATCH && child.pdispVal) {
                    winrt::com_ptr<IAccessible> childAccessible;
                    if (SUCCEEDED(child.pdispVal->QueryInterface(
                            kNeteaseIAccessibleGuid,
                            childAccessible.put_void()))) {
                        stack.push_back({std::move(childAccessible),
                                         node.depth + 1});
                    }
                }
            }
            for (auto& child : children) VariantClear(&child);
            start += obtained;
        }
    }
    return std::nullopt;
}

static std::optional<double> QueryNeteaseProgressRatio() {
    NeteaseBrowserHostCollector collector;
    EnumWindows(EnumerateNeteaseBrowserHosts,
                reinterpret_cast<LPARAM>(&collector));
    for (HWND host : collector.hosts) {
        winrt::com_ptr<IAccessible> accessible;
        if (SUCCEEDED(AccessibleObjectFromWindow(
                host, OBJID_CLIENT, kNeteaseIAccessibleGuid,
                accessible.put_void())) &&
            accessible) {
            auto ratio = InspectNeteaseProgressTree(std::move(accessible));
            if (ratio) return ratio;
        }
    }
    return std::nullopt;
}

// NetEase-specific adapter. GSMTC has no favorite or lyric API, so this adapter
// resolves the current NetEase track locally and uses the public lyric endpoint.
struct NeteaseLyricLine {
    int64_t timeMs = 0;
    std::wstring text;
};

enum class NeteaseLyricsFetchStatus {
    Success,
    NoLyrics,
    RetryableFailure,
};

struct NeteaseLyricsFetchResult {
    NeteaseLyricsFetchStatus status = NeteaseLyricsFetchStatus::RetryableFailure;
    std::vector<NeteaseLyricLine> lines;
    int64_t durationMs = 0;
};

struct NeteaseResolvedSong {
    std::wstring songId;
    int64_t durationMs = 0;
    std::wstring coverUrl;
    bool coverReliable = false;
};

static NeteaseResolvedSong ResolveNeteaseSongIdFromTwilightApi(
    const std::wstring& title, const std::wstring& artist,
    int64_t expectedDurationMs);

static HANDLE g_neteaseLyricsThread = nullptr;
static HANDLE g_neteaseLyricsStopEvent = nullptr;
static std::mutex g_neteaseLyricsMtx;
static std::vector<NeteaseLyricLine> g_neteaseLyricLines;
static std::wstring g_neteaseLyricsTrackKey;
static std::wstring g_neteaseCurrentLyric;

static bool NeteaseLyricsShouldStop() {
    return g_unloading ||
           (g_neteaseLyricsStopEvent &&
            WaitForSingleObject(g_neteaseLyricsStopEvent, 0) == WAIT_OBJECT_0);
}

static std::wstring Utf8ToWide(const std::string& text) {
    if (text.empty()) return {};
    int count = MultiByteToWideChar(CP_UTF8, MB_ERR_INVALID_CHARS,
                                    text.data(), static_cast<int>(text.size()),
                                    nullptr, 0);
    if (count <= 0) return {};
    std::wstring result(static_cast<size_t>(count), L'\0');
    if (MultiByteToWideChar(CP_UTF8, MB_ERR_INVALID_CHARS,
                            text.data(), static_cast<int>(text.size()),
                            result.data(), count) != count) {
        return {};
    }
    if (!result.empty() && result.front() == 0xFEFF) result.erase(result.begin());
    return result;
}

static std::wstring NormalizeNeteaseMatchText(std::wstring value) {
    value = ToLowerCopy(TrimCopy(std::move(value)));
    std::wstring result;
    result.reserve(value.size());
    bool pendingSpace = false;
    for (wchar_t c : value) {
        if (iswspace(c)) {
            pendingSpace = !result.empty();
        } else {
            if (pendingSpace) result.push_back(L' ');
            result.push_back(c);
            pendingSpace = false;
        }
    }
    return result;
}

static std::wstring NormalizeNeteaseArtistText(std::wstring value) {
    value = ToLowerCopy(TrimCopy(std::move(value)));
    value.erase(std::remove_if(value.begin(), value.end(),
                               [](wchar_t c) { return iswspace(c); }),
                value.end());
    return value;
}

static std::wstring ReadNeteasePlayingList() {
    wchar_t localAppData[32768]{};
    DWORD length = GetEnvironmentVariableW(L"LOCALAPPDATA", localAppData,
                                           ARRAYSIZE(localAppData));
    if (!length || length >= ARRAYSIZE(localAppData)) return {};
    std::filesystem::path path(localAppData);
    path /= L"NetEase\\CloudMusic\\webdata\\file\\playingList";
    std::ifstream stream(path, std::ios::binary | std::ios::ate);
    if (!stream) return {};
    auto size = stream.tellg();
    if (size <= 0 || size > 16 * 1024 * 1024) return {};
    std::string bytes(static_cast<size_t>(size), '\0');
    stream.seekg(0, std::ios::beg);
    stream.read(bytes.data(), static_cast<std::streamsize>(bytes.size()));
    if (!stream) return {};
    return Utf8ToWide(bytes);
}

static std::wstring JsonSongId(const winrt::Windows::Data::Json::JsonObject& track) {
    using winrt::Windows::Data::Json::JsonValueType;
    try {
        auto value = track.GetNamedValue(L"id");
        if (value.ValueType() == JsonValueType::String) {
            return std::wstring(value.GetString());
        }
        if (value.ValueType() == JsonValueType::Number) {
            return std::to_wstring(static_cast<int64_t>(value.GetNumber()));
        }
    } catch (...) {}
    return {};
}

static NeteaseResolvedSong ResolveNeteaseSongId(
    const std::wstring& title, const std::wstring& artist,
    int64_t expectedDurationMs) {
    using namespace winrt::Windows::Data::Json;
    std::wstring json = ReadNeteasePlayingList();
    if (json.empty()) return {};
    std::wstring wantedTitle = NormalizeNeteaseMatchText(title);
    std::wstring wantedArtist = NormalizeNeteaseArtistText(artist);
    if (wantedTitle.empty()) return {};

    NeteaseResolvedSong best;
    int bestScore = -1;
    int64_t bestDurationDifference = INT64_MAX;
    try {
        JsonObject root = JsonObject::Parse(winrt::hstring(json));
        JsonArray list = root.GetNamedArray(L"list");
        for (uint32_t i = 0; i < list.Size(); ++i) {
            JsonObject item = list.GetObjectAt(i);
            JsonObject track = item.GetNamedObject(L"track");
            std::wstring candidateTitle =
                NormalizeNeteaseMatchText(std::wstring(track.GetNamedString(L"name", L"")));
            int titleScore = -1;
            if (candidateTitle == wantedTitle) {
                titleScore = 100;
            } else if (candidateTitle.size() >= 4 && wantedTitle.size() >= 4 &&
                       (candidateTitle.find(wantedTitle) != std::wstring::npos ||
                        wantedTitle.find(candidateTitle) != std::wstring::npos)) {
                titleScore = 60;
            }
            if (titleScore < 0) continue;

            std::wstring candidateArtist;
            try {
                JsonArray artists = track.GetNamedArray(L"artists");
                for (uint32_t j = 0; j < artists.Size(); ++j) {
                    std::wstring name = std::wstring(
                        artists.GetObjectAt(j).GetNamedString(L"name", L""));
                    if (!name.empty()) {
                        if (!candidateArtist.empty()) candidateArtist += L"/";
                        candidateArtist += name;
                    }
                }
            } catch (...) {}
            std::wstring normalizedArtist = NormalizeNeteaseArtistText(candidateArtist);
            int artistScore = 0;
            if (!wantedArtist.empty() && normalizedArtist == wantedArtist) {
                artistScore = 30;
            } else if (!wantedArtist.empty() && !normalizedArtist.empty() &&
                       (normalizedArtist.find(wantedArtist) != std::wstring::npos ||
                        wantedArtist.find(normalizedArtist) != std::wstring::npos)) {
                artistScore = 20;
            }

            int64_t candidateDuration = 0;
            try {
                candidateDuration = static_cast<int64_t>(
                    track.GetNamedNumber(L"duration", 0));
            } catch (...) {}
            int64_t durationDifference = INT64_MAX;
            if (expectedDurationMs > 0 && candidateDuration > 0) {
                durationDifference = candidateDuration >= expectedDurationMs
                    ? candidateDuration - expectedDurationMs
                    : expectedDurationMs - candidateDuration;
            }
            int score = titleScore + artistScore;
            if (score > bestScore ||
                (score == bestScore && durationDifference < bestDurationDifference)) {
                std::wstring candidateId = JsonSongId(track);
                if (!candidateId.empty()) {
                    best.songId = std::move(candidateId);
                    best.durationMs = candidateDuration;
                    bestScore = score;
                    bestDurationDifference = durationDifference;
                }
            }
        }
    } catch (...) {
        return {};
    }
    return best;
}

struct NeteaseWinHttpHandle {
    HINTERNET value = nullptr;
    ~NeteaseWinHttpHandle() { if (value) WinHttpCloseHandle(value); }
    NeteaseWinHttpHandle() = default;
    NeteaseWinHttpHandle(const NeteaseWinHttpHandle&) = delete;
    NeteaseWinHttpHandle& operator=(const NeteaseWinHttpHandle&) = delete;
};

struct TwilightFileHandle {
    HANDLE value = INVALID_HANDLE_VALUE;
    ~TwilightFileHandle() {
        if (value != INVALID_HANDLE_VALUE) CloseHandle(value);
    }
    TwilightFileHandle() = default;
    TwilightFileHandle(const TwilightFileHandle&) = delete;
    TwilightFileHandle& operator=(const TwilightFileHandle&) = delete;
};

static std::filesystem::path TwilightAppDataPath(const wchar_t* relative) {
    wchar_t appData[32768]{};
    DWORD length = GetEnvironmentVariableW(L"APPDATA", appData,
                                           ARRAYSIZE(appData));
    if (!length || length >= ARRAYSIZE(appData)) return {};
    std::filesystem::path path(appData);
    path /= L"TwilightEcho";
    path /= relative;
    return path;
}

static bool ReadSharedFile(const std::filesystem::path& path,
                           size_t maxBytes, std::string& bytes,
                           FILETIME* lastWrite = nullptr) {
    bytes.clear();
    TwilightFileHandle file;
    file.value = CreateFileW(
        path.c_str(), GENERIC_READ,
        FILE_SHARE_READ | FILE_SHARE_WRITE | FILE_SHARE_DELETE, nullptr,
        OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL | FILE_FLAG_SEQUENTIAL_SCAN,
        nullptr);
    if (file.value == INVALID_HANDLE_VALUE) return false;
    BY_HANDLE_FILE_INFORMATION info{};
    if (!GetFileInformationByHandle(file.value, &info)) return false;
    ULARGE_INTEGER size{};
    size.HighPart = info.nFileSizeHigh;
    size.LowPart = info.nFileSizeLow;
    if (!size.QuadPart || size.QuadPart > maxBytes) return false;
    bytes.resize(static_cast<size_t>(size.QuadPart));
    size_t offset = 0;
    while (offset < bytes.size()) {
        DWORD read = 0;
        DWORD wanted = static_cast<DWORD>(std::min<size_t>(
            bytes.size() - offset, 64 * 1024));
        if (!ReadFile(file.value, bytes.data() + offset, wanted, &read,
                      nullptr) || !read) {
            return false;
        }
        offset += read;
    }
    if (lastWrite) *lastWrite = info.ftLastWriteTime;
    return true;
}

static bool IsHttpCoverSource(const std::wstring& value) {
    return value.size() > 8 &&
           (_wcsnicmp(value.c_str(), L"https://", 8) == 0 ||
            _wcsnicmp(value.c_str(), L"http://", 7) == 0);
}

static std::wstring ReadTwilightPlaybackSession() {
    std::string bytes;
    return ReadSharedFile(TwilightAppDataPath(L"playback-session.json"),
                          16 * 1024 * 1024, bytes)
        ? Utf8ToWide(bytes)
        : std::wstring{};
}

static std::string WideToUtf8(const std::wstring& text) {
    if (text.empty()) return {};
    int count = WideCharToMultiByte(CP_UTF8, WC_ERR_INVALID_CHARS,
                                    text.data(), static_cast<int>(text.size()),
                                    nullptr, 0, nullptr, nullptr);
    if (count <= 0) return {};
    std::string result(static_cast<size_t>(count), '\0');
    return WideCharToMultiByte(CP_UTF8, WC_ERR_INVALID_CHARS,
                               text.data(), static_cast<int>(text.size()),
                               result.data(), count, nullptr, nullptr) == count
        ? result
        : std::string{};
}

static std::wstring TwilightHttpFingerprintInput(const std::wstring& url) {
    URL_COMPONENTSW parts{};
    parts.dwStructSize = sizeof(parts);
    parts.dwHostNameLength = static_cast<DWORD>(-1);
    parts.dwUrlPathLength = static_cast<DWORD>(-1);
    if (!WinHttpCrackUrl(url.c_str(), static_cast<DWORD>(url.size()), 0,
                         &parts) || !parts.lpszHostName) {
        return {};
    }
    std::wstring host(parts.lpszHostName, parts.dwHostNameLength);
    host = ToLowerCopy(std::move(host));
    bool secure = parts.nScheme == INTERNET_SCHEME_HTTPS;
    std::wstring result = secure ? L"https://" : L"http://";
    result += host;
    if ((!secure && parts.nPort != INTERNET_DEFAULT_HTTP_PORT) ||
        (secure && parts.nPort != INTERNET_DEFAULT_HTTPS_PORT)) {
        result += L":" + std::to_wstring(parts.nPort);
    }
    result.append(parts.lpszUrlPath, parts.dwUrlPathLength);
    if (parts.dwUrlPathLength == 0) result.push_back(L'/');
    return result;
}

static std::wstring TwilightSourceFingerprint(const std::wstring& source) {
    if (source.empty()) return {};
    std::wstring input = source;
    if (IsHttpCoverSource(source)) {
        input = TwilightHttpFingerprintInput(source);
        if (input.empty()) return {};
    }
    std::string bytes = WideToUtf8(input);
    if (bytes.empty()) return {};
    BCRYPT_ALG_HANDLE algorithm = nullptr;
    if (BCryptOpenAlgorithmProvider(&algorithm, BCRYPT_SHA256_ALGORITHM,
                                    nullptr, 0) < 0) {
        return {};
    }
    DWORD objectSize = 0;
    DWORD resultSize = 0;
    if (BCryptGetProperty(algorithm, BCRYPT_OBJECT_LENGTH,
                          reinterpret_cast<PUCHAR>(&objectSize),
                          sizeof(objectSize), &resultSize, 0) < 0 ||
        objectSize == 0) {
        BCryptCloseAlgorithmProvider(algorithm, 0);
        return {};
    }
    std::vector<BYTE> hashObject(objectSize);
    BCRYPT_HASH_HANDLE hash = nullptr;
    if (BCryptCreateHash(algorithm, &hash, hashObject.data(),
                         static_cast<ULONG>(hashObject.size()), nullptr, 0,
                         0) < 0) {
        BCryptCloseAlgorithmProvider(algorithm, 0);
        return {};
    }
    BYTE digest[32]{};
    NTSTATUS status = BCryptHashData(
        hash, reinterpret_cast<PUCHAR>(bytes.data()),
        static_cast<ULONG>(bytes.size()), 0);
    if (status >= 0) {
        status = BCryptFinishHash(hash, digest, sizeof(digest), 0);
    }
    BCryptDestroyHash(hash);
    BCryptCloseAlgorithmProvider(algorithm, 0);
    if (status < 0) return {};
    static constexpr wchar_t kHex[] = L"0123456789abcdef";
    std::wstring result;
    result.reserve(16);
    for (size_t i = 0; i < 8; ++i) {
        result.push_back(kHex[digest[i] >> 4]);
        result.push_back(kHex[digest[i] & 0x0f]);
    }
    return result;
}

static std::wstring JsonScalarString(
    const winrt::Windows::Data::Json::JsonObject& object,
    const wchar_t* key) {
    using winrt::Windows::Data::Json::JsonValueType;
    try {
        auto value = object.GetNamedValue(key);
        if (value.ValueType() == JsonValueType::String) {
            return std::wstring(value.GetString());
        }
        if (value.ValueType() == JsonValueType::Number) {
            return std::to_wstring(static_cast<int64_t>(value.GetNumber()));
        }
    } catch (...) {}
    return {};
}

static void InvalidateTwilightBridge() {
    {
        std::lock_guard<std::mutex> lock(g_twilightBridgeMtx);
        g_twilightBridgeDiscovery = {};
        g_twilightBridgeSnapshot = {};
    }
    g_twilightBridgeAuthoritative = false;
    g_twilightBridgeLastSuccessTick = 0;
    g_twilightBridgeNextDiscoveryTick = GetTickCount64() + 500;
    SetTwilightFavoriteEligibility(false);
    SetTwilightLikeState(NeteaseLikeState::Unknown);
}

static bool IsTwilightBridgeAuthorityActive() {
    constexpr ULONGLONG kAuthorityGraceMs = 2500;
    if (!g_twilightBridgeAuthoritative.load()) return false;
    ULONGLONG lastSuccess = g_twilightBridgeLastSuccessTick.load();
    ULONGLONG nowTick = GetTickCount64();
    return lastSuccess && nowTick >= lastSuccess &&
           nowTick - lastSuccess <= kAuthorityGraceMs;
}

static void MarkTwilightBridgeTransientFailure() {
    {
        std::lock_guard<std::mutex> lock(g_twilightBridgeMtx);
        g_twilightBridgeDiscovery.healthy = false;
    }
    if (!IsTwilightBridgeAuthorityActive()) {
        g_twilightBridgeAuthoritative = false;
    }
}

static bool UseTwilightBridgeAuthorityGrace(
    TwilightBridgeSnapshot& result) {
    MarkTwilightBridgeTransientFailure();
    if (!IsTwilightBridgeAuthorityActive()) {
        InvalidateTwilightBridge();
        return false;
    }
    std::lock_guard<std::mutex> lock(g_twilightBridgeMtx);
    if (!g_twilightBridgeSnapshot.reachable) return false;
    result = g_twilightBridgeSnapshot;
    return true;
}

static bool LoadTwilightBridgeDiscovery() {
    std::filesystem::path discoveryPath =
        TwilightAppDataPath(L"taskbar-bridge.json");
    WIN32_FILE_ATTRIBUTE_DATA discoveryAttributes{};
    if (discoveryPath.empty() ||
        !GetFileAttributesExW(discoveryPath.c_str(), GetFileExInfoStandard,
                              &discoveryAttributes)) {
        InvalidateTwilightBridge();
        return false;
    }
    {
        std::lock_guard<std::mutex> lock(g_twilightBridgeMtx);
        if (g_twilightBridgeDiscovery.valid &&
            CompareFileTime(
                &g_twilightBridgeDiscovery.discoveryLastWrite,
                &discoveryAttributes.ftLastWriteTime) == 0) {
            return true;
        }
    }
    ULONGLONG nowTick = GetTickCount64();
    if (nowTick < g_twilightBridgeNextDiscoveryTick.load()) return false;

    std::string bytes;
    FILETIME discoveryLastWrite{};
    if (!ReadSharedFile(discoveryPath, 64 * 1024, bytes,
                        &discoveryLastWrite)) {
        InvalidateTwilightBridge();
        return false;
    }

    using namespace winrt::Windows::Data::Json;
    try {
        JsonObject root = JsonObject::Parse(
            winrt::hstring(Utf8ToWide(bytes)));
        if (root.GetNamedNumber(L"bridgeVersion", 0) != 1) {
            InvalidateTwilightBridge();
            return false;
        }
        TwilightBridgeDiscovery next;
        next.baseUrl = JsonScalarString(root, L"baseUrl");
        next.token = JsonScalarString(root, L"token");
        next.instanceId = JsonScalarString(root, L"instanceId");
        next.discoveryLastWrite = discoveryLastWrite;
        std::wstring declaredHost = JsonScalarString(root, L"host");
        if (next.baseUrl.empty() || next.token.empty() ||
            next.instanceId.empty() || declaredHost != L"127.0.0.1") {
            InvalidateTwilightBridge();
            return false;
        }

        URL_COMPONENTSW components{};
        components.dwStructSize = sizeof(components);
        components.dwHostNameLength = static_cast<DWORD>(-1);
        components.dwUrlPathLength = static_cast<DWORD>(-1);
        components.dwExtraInfoLength = static_cast<DWORD>(-1);
        if (!WinHttpCrackUrl(next.baseUrl.c_str(),
                             static_cast<DWORD>(next.baseUrl.size()), 0,
                             &components) ||
            components.nScheme != INTERNET_SCHEME_HTTP ||
            !components.lpszHostName || components.nPort == 0) {
            InvalidateTwilightBridge();
            return false;
        }
        next.host.assign(components.lpszHostName,
                         components.dwHostNameLength);
        if (next.host != L"127.0.0.1") {
            InvalidateTwilightBridge();
            return false;
        }
        next.port = components.nPort;
        if (components.lpszUrlPath && components.dwUrlPathLength) {
            next.basePath.assign(components.lpszUrlPath,
                                 components.dwUrlPathLength);
        }
        while (next.basePath.size() > 1 &&
               next.basePath.back() == L'/') {
            next.basePath.pop_back();
        }
        if (next.basePath != L"/taskbar/v1") {
            InvalidateTwilightBridge();
            return false;
        }
        next.valid = true;

        bool instanceChanged = false;
        {
            std::lock_guard<std::mutex> lock(g_twilightBridgeMtx);
            instanceChanged =
                !g_twilightBridgeDiscovery.instanceId.empty() &&
                g_twilightBridgeDiscovery.instanceId != next.instanceId;
            g_twilightBridgeDiscovery = std::move(next);
            if (instanceChanged) g_twilightBridgeSnapshot = {};
        }
        if (instanceChanged) {
            g_twilightBridgeAuthoritative = false;
            SetTwilightLikeState(NeteaseLikeState::Unknown);
        }
        return true;
    } catch (...) {
        InvalidateTwilightBridge();
        return false;
    }
}

static bool TwilightBridgeRequest(const wchar_t* method,
                                  const wchar_t* relativePath,
                                  const std::string& requestBody,
                                  std::wstring* responseBody,
                                  DWORD* responseStatus,
                                  DWORD receiveTimeoutMs,
                                  bool* requestMayHaveReachedServer) {
    if (responseBody) responseBody->clear();
    if (responseStatus) *responseStatus = 0;
    if (requestMayHaveReachedServer) {
        *requestMayHaveReachedServer = false;
    }
    if (!LoadTwilightBridgeDiscovery()) return false;

    TwilightBridgeDiscovery discovery;
    {
        std::lock_guard<std::mutex> lock(g_twilightBridgeMtx);
        discovery = g_twilightBridgeDiscovery;
    }
    if (!discovery.valid || !method || !relativePath) return false;

    NeteaseWinHttpHandle internet;
    internet.value = WinHttpOpen(L"Windhawk-TwilightEcho-Taskbar/2.0",
                                 WINHTTP_ACCESS_TYPE_NO_PROXY,
                                 WINHTTP_NO_PROXY_NAME,
                                 WINHTTP_NO_PROXY_BYPASS, 0);
    if (!internet.value) {
        MarkTwilightBridgeTransientFailure();
        return false;
    }
    WinHttpSetTimeouts(internet.value, 300, 300, 700,
                       receiveTimeoutMs);

    NeteaseWinHttpHandle connection;
    connection.value = WinHttpConnect(internet.value,
                                      discovery.host.c_str(),
                                      discovery.port, 0);
    if (!connection.value) {
        MarkTwilightBridgeTransientFailure();
        return false;
    }

    std::wstring path = discovery.basePath;
    if (*relativePath != L'/') path.push_back(L'/');
    path += relativePath;
    NeteaseWinHttpHandle request;
    request.value = WinHttpOpenRequest(
        connection.value, method, path.c_str(), nullptr, WINHTTP_NO_REFERER,
        WINHTTP_DEFAULT_ACCEPT_TYPES, 0);
    if (!request.value) {
        MarkTwilightBridgeTransientFailure();
        return false;
    }

    std::wstring headers = L"Authorization: Bearer " + discovery.token +
        L"\r\nAccept: application/json\r\n";
    if (!requestBody.empty()) {
        headers += L"Content-Type: application/json; charset=utf-8\r\n";
    }
    LPVOID body = requestBody.empty()
        ? WINHTTP_NO_REQUEST_DATA
        : const_cast<char*>(requestBody.data());
    DWORD bodySize = static_cast<DWORD>(requestBody.size());
    if (!WinHttpSendRequest(
            request.value, headers.c_str(), static_cast<DWORD>(-1L),
            body, bodySize, bodySize, 0)) {
        MarkTwilightBridgeTransientFailure();
        return false;
    }
    if (requestMayHaveReachedServer) {
        *requestMayHaveReachedServer = true;
    }
    if (!WinHttpReceiveResponse(request.value, nullptr)) {
        MarkTwilightBridgeTransientFailure();
        return false;
    }

    DWORD statusCode = 0;
    DWORD statusCodeSize = sizeof(statusCode);
    if (!WinHttpQueryHeaders(
            request.value,
            WINHTTP_QUERY_STATUS_CODE | WINHTTP_QUERY_FLAG_NUMBER,
            WINHTTP_HEADER_NAME_BY_INDEX, &statusCode, &statusCodeSize,
            WINHTTP_NO_HEADER_INDEX)) {
        MarkTwilightBridgeTransientFailure();
        return false;
    }
    if (responseStatus) *responseStatus = statusCode;
    if (statusCode == 401 || statusCode == HTTP_STATUS_DENIED) {
        InvalidateTwilightBridge();
        return false;
    }

    std::string bodyBytes;
    char buffer[4096];
    while (bodyBytes.size() <= 1024 * 1024) {
        DWORD bytesRead = 0;
        if (!WinHttpReadData(request.value, buffer, sizeof(buffer),
                             &bytesRead)) {
            MarkTwilightBridgeTransientFailure();
            return false;
        }
        if (!bytesRead) break;
        bodyBytes.append(buffer, buffer + bytesRead);
    }
    if (bodyBytes.size() > 1024 * 1024) {
        InvalidateTwilightBridge();
        return false;
    }
    if (responseBody) *responseBody = Utf8ToWide(bodyBytes);
    return true;
}

static bool IsTwilightBridgeHealthy() {
    if (!IsTwilightBridgeAuthorityActive()) return false;
    std::lock_guard<std::mutex> lock(g_twilightBridgeMtx);
    return g_twilightBridgeDiscovery.valid &&
           g_twilightBridgeDiscovery.healthy &&
           g_twilightBridgeSnapshot.reachable &&
           g_twilightBridgeSnapshot.instanceId ==
               g_twilightBridgeDiscovery.instanceId;
}

static bool PollTwilightBridgeState(TwilightBridgeSnapshot& result) {
    result = {};
    if (!LoadTwilightBridgeDiscovery()) return false;

    TwilightBridgeDiscovery discovery;
    {
        std::lock_guard<std::mutex> lock(g_twilightBridgeMtx);
        discovery = g_twilightBridgeDiscovery;
    }
    if (!discovery.healthy) {
        std::wstring healthBody;
        DWORD healthStatus = 0;
        if (!TwilightBridgeRequest(L"GET", L"/health", {},
                                   &healthBody, &healthStatus) ||
            healthStatus != 200 || healthBody.empty()) {
            return UseTwilightBridgeAuthorityGrace(result);
        }
        try {
            using namespace winrt::Windows::Data::Json;
            JsonObject health = JsonObject::Parse(
                winrt::hstring(healthBody));
            std::wstring instanceId = JsonScalarString(
                health, L"instanceId");
            std::wstring status = JsonScalarString(health, L"status");
            if (health.GetNamedNumber(L"bridgeVersion", 0) != 1 ||
                instanceId != discovery.instanceId || status != L"ok") {
                InvalidateTwilightBridge();
                return false;
            }
            bool discoveryStillCurrent = false;
            {
                std::lock_guard<std::mutex> lock(g_twilightBridgeMtx);
                discoveryStillCurrent = g_twilightBridgeDiscovery.valid &&
                    g_twilightBridgeDiscovery.instanceId == instanceId;
                if (discoveryStillCurrent) {
                    g_twilightBridgeDiscovery.healthy = true;
                }
            }
            if (!discoveryStillCurrent) {
                InvalidateTwilightBridge();
                return false;
            }
        } catch (...) {
            InvalidateTwilightBridge();
            return false;
        }
    }

    std::wstring stateBody;
    DWORD stateStatus = 0;
    if (!TwilightBridgeRequest(L"GET", L"/state", {},
                               &stateBody, &stateStatus) ||
        stateStatus != 200 || stateBody.empty()) {
        return UseTwilightBridgeAuthorityGrace(result);
    }

    using namespace winrt::Windows::Data::Json;
    try {
        JsonObject root = JsonObject::Parse(winrt::hstring(stateBody));
        TwilightBridgeSnapshot next;
        next.instanceId = JsonScalarString(root, L"instanceId");
        if (root.GetNamedNumber(L"bridgeVersion", 0) != 1 ||
            next.instanceId != discovery.instanceId) {
            InvalidateTwilightBridge();
            return false;
        }
        double revision = root.GetNamedNumber(L"revision", 0);
        next.revision = std::isfinite(revision) && revision >= 0
            ? static_cast<uint64_t>(revision)
            : 0;
        next.isPlaying = root.GetNamedBoolean(L"isPlaying", false);
        next.isLoading = root.GetNamedBoolean(L"isLoading", false);
        double currentTime = root.GetNamedNumber(L"currentTime", 0);
        double duration = root.GetNamedNumber(L"duration", 0);
        next.positionMs = std::isfinite(currentTime) && currentTime > 0
            ? static_cast<int64_t>(currentTime * 1000.0)
            : 0;
        next.durationMs = std::isfinite(duration) && duration > 0
            ? static_cast<int64_t>(duration * 1000.0)
            : 0;
        if (root.HasKey(L"track") &&
            root.GetNamedValue(L"track").ValueType() ==
                JsonValueType::Object) {
            JsonObject track = root.GetNamedObject(L"track");
            next.trackId = JsonScalarString(track, L"id");
            next.providerId = JsonScalarString(track, L"providerId");
            next.title = JsonScalarString(track, L"title");
            next.artist = JsonScalarString(track, L"artist");
            next.album = JsonScalarString(track, L"album");
            next.coverSource = JsonScalarString(track, L"coverSource");
            if (!IsHttpCoverSource(next.coverSource)) {
                next.coverSource = JsonScalarString(track, L"cover");
            }
            next.hasTrack = !next.trackId.empty() || !next.title.empty();
        }
        // A later bridge state is the authoritative "favorite" confirmation
        // when a set-favorite command initially returns pending. Only the NCM
        // provider owns the NetEase favorite semantics used by this button.
        bool isNcmProvider =
            ToLowerCopy(next.providerId) == L"ncm";
        next.favoriteAvailable = isNcmProvider &&
            root.GetNamedBoolean(L"favoriteAvailable", false);
        next.favoriteLiked = isNcmProvider &&
            root.GetNamedBoolean(L"favoriteLiked", false);
        next.favoriteLoading = isNcmProvider &&
            root.GetNamedBoolean(L"favoriteLoading", false);
        if (root.HasKey(L"currentLyric") &&
            root.GetNamedValue(L"currentLyric").ValueType() ==
                JsonValueType::Object) {
            JsonObject lyric = root.GetNamedObject(L"currentLyric");
            std::wstring original = JsonScalarString(lyric, L"original");
            std::wstring translation = JsonScalarString(
                lyric, L"translation");
            if (!original.empty() && !translation.empty() &&
                NormalizeNeteaseMatchText(original) !=
                    NormalizeNeteaseMatchText(translation)) {
                next.currentLyric = original + L"\n" + translation;
            } else {
                next.currentLyric = !original.empty()
                    ? std::move(original)
                    : std::move(translation);
            }
        }
        next.reachable = true;

        bool discoveryStillCurrent = false;
        {
            std::lock_guard<std::mutex> lock(g_twilightBridgeMtx);
            discoveryStillCurrent = g_twilightBridgeDiscovery.valid &&
                g_twilightBridgeDiscovery.instanceId == next.instanceId;
            if (discoveryStillCurrent) {
                if (!next.hasTrack && next.isLoading &&
                    g_twilightBridgeSnapshot.hasTrack) {
                    next.hasTrack = true;
                    next.trackId = g_twilightBridgeSnapshot.trackId;
                    next.providerId =
                        g_twilightBridgeSnapshot.providerId;
                    next.title = g_twilightBridgeSnapshot.title;
                    next.artist = g_twilightBridgeSnapshot.artist;
                    next.album = g_twilightBridgeSnapshot.album;
                    next.coverSource = g_twilightBridgeSnapshot.coverSource;
                    if (next.currentLyric.empty()) {
                        next.currentLyric =
                            g_twilightBridgeSnapshot.currentLyric;
                    }
                }
                g_twilightBridgeSnapshot = next;
                g_twilightBridgeDiscovery.healthy = true;
            }
        }
        if (!discoveryStillCurrent) {
            InvalidateTwilightBridge();
            return false;
        }
        g_twilightBridgeLastSuccessTick = GetTickCount64();
        g_twilightBridgeAuthoritative = true;
        result = std::move(next);
        return true;
    } catch (...) {
        InvalidateTwilightBridge();
        return false;
    }
}

static TwilightBridgeCommandDisposition
TrySendTwilightBridgePlaybackCommand(const wchar_t* type) {
    if (!type ||
        (wcscmp(type, L"toggle-play") != 0 &&
         wcscmp(type, L"previous") != 0 &&
         wcscmp(type, L"next") != 0) ||
        !IsTwilightBridgeHealthy()) {
        return TwilightBridgeCommandDisposition::NotAttempted;
    }
    using namespace winrt::Windows::Data::Json;
    JsonObject command;
    command.Insert(L"type", JsonValue::CreateStringValue(type));
    std::wstring responseBody;
    DWORD responseStatus = 0;
    bool requestMayHaveReachedServer = false;
    TwilightBridgeRequest(
        L"POST", L"/command",
        WideToUtf8(std::wstring(command.Stringify())),
        &responseBody, &responseStatus, 700,
        &requestMayHaveReachedServer);
    if (!requestMayHaveReachedServer) {
        return TwilightBridgeCommandDisposition::NotAttempted;
    }
    if (wcscmp(type, L"previous") == 0 ||
        wcscmp(type, L"next") == 0) {
        ShortenTwilightWheelReservationAfterBridgeDelivery();
    }
    // Once a healthy bridge was handed the command, its outcome may be
    // unknown. Never issue the same user action through SMTC or UIA again.
    return TwilightBridgeCommandDisposition::Consumed;
}

static TwilightSessionTrack ParseTwilightSessionTrack(
    const winrt::Windows::Data::Json::JsonObject& track,
    uint64_t revision) {
    TwilightSessionTrack result;
    result.revision = revision;
    result.id = JsonScalarString(track, L"id");
    result.queueEntryId = JsonScalarString(track, L"queueEntryId");
    result.songId = JsonScalarString(track, L"ncmSongId");
    if (result.songId.empty() && result.id.starts_with(L"ncm:")) {
        result.songId = result.id.substr(4);
    }
    result.title = JsonScalarString(track, L"title");
    result.artist = JsonScalarString(track, L"artist");
    result.filePath = JsonScalarString(track, L"filePath");
    result.streamUrl = JsonScalarString(track, L"streamUrl");
    result.coverSource = JsonScalarString(track, L"coverSource");
    if (!IsHttpCoverSource(result.coverSource)) {
        result.coverSource = JsonScalarString(track, L"cover");
    }
    double duration = 0;
    try {
        duration = track.GetNamedNumber(L"duration", 0);
    } catch (...) {}
    result.durationMs = std::isfinite(duration) && duration > 0
        ? static_cast<int64_t>(duration * 1000.0)
        : 0;
    result.valid = !result.title.empty();
    return result;
}

struct TwilightPlaybackSessionSnapshot {
    bool valid = false;
    bool hasTrack = false;
    bool hasPosition = false;
    uint64_t revision = 0;
    int queueIndex = -1;
    int64_t positionMs = 0;
    ULONGLONG observedAtTick = 0;
    TwilightSessionTrack track;
    std::vector<TwilightSessionTrack> queue;
};

static TwilightPlaybackSessionSnapshot ReadTwilightPlaybackSessionSnapshot() {
    using namespace winrt::Windows::Data::Json;
    TwilightPlaybackSessionSnapshot result;
    std::wstring json = ReadTwilightPlaybackSession();
    if (json.empty()) return result;
    try {
        JsonObject root = JsonObject::Parse(winrt::hstring(json));
        double revision = root.GetNamedNumber(L"revision", 0);
        if (!std::isfinite(revision) || revision < 0) return result;
        result.revision = static_cast<uint64_t>(revision);
        result.valid = true;
        if (!root.HasKey(L"data")) return result;
        auto dataValue = root.GetNamedValue(L"data");
        if (dataValue.ValueType() != JsonValueType::Object) return result;
        JsonObject data = dataValue.GetObject();
        if (data.HasKey(L"position")) {
            double position = data.GetNamedNumber(L"position", -1);
            if (std::isfinite(position) && position >= 0) {
                result.hasPosition = true;
                result.positionMs = static_cast<int64_t>(position * 1000.0);
            }
        }
        if (data.HasKey(L"track")) {
            auto trackValue = data.GetNamedValue(L"track");
            if (trackValue.ValueType() == JsonValueType::Object) {
                result.track = ParseTwilightSessionTrack(
                    trackValue.GetObject(), result.revision);
                result.hasTrack = result.track.valid;
            }
        }
        double queueIndex = data.GetNamedNumber(L"queueIndex", -1);
        if (std::isfinite(queueIndex)) {
            result.queueIndex = static_cast<int>(queueIndex);
        }
        JsonArray queue = data.GetNamedArray(L"queue", JsonArray{});
        result.queue.reserve(queue.Size());
        for (uint32_t i = 0; i < queue.Size(); ++i) {
            result.queue.push_back(ParseTwilightSessionTrack(
                queue.GetObjectAt(i), result.revision));
        }
    } catch (...) {}
    return result;
}

static std::filesystem::path ReadTwilightMusicCachePath() {
    using namespace winrt::Windows::Data::Json;
    std::string bytes;
    if (!ReadSharedFile(TwilightAppDataPath(L"settings.json"),
                        4 * 1024 * 1024, bytes)) {
        return TwilightAppDataPath(L"music-cache");
    }
    try {
        JsonObject root = JsonObject::Parse(
            winrt::hstring(Utf8ToWide(bytes)));
        std::wstring path = std::wstring(
            root.GetNamedString(L"musicCachePath", L""));
        if (!path.empty()) return std::filesystem::path(path);
    } catch (...) {}
    return TwilightAppDataPath(L"music-cache");
}

static bool IsTwilightLocalPath(const std::wstring& value) {
    return (value.size() >= 3 && iswalpha(value[0]) &&
            value[1] == L':' &&
            (value[2] == L'\\' || value[2] == L'/')) ||
           value.starts_with(L"\\\\");
}

static bool TwilightTrackMatchesFingerprint(
    const TwilightSessionTrack& track, const std::wstring& fingerprint,
    const std::wstring& extension,
    const std::filesystem::path& musicCachePath) {
    auto matchesSource = [&](const std::wstring& source) {
        return !source.empty() &&
               TwilightSourceFingerprint(source) == fingerprint;
    };
    if ((IsTwilightLocalPath(track.filePath) ||
         IsHttpCoverSource(track.filePath)) &&
        matchesSource(track.filePath)) {
        return true;
    }
    if (IsHttpCoverSource(track.streamUrl) && matchesSource(track.streamUrl)) {
        return true;
    }
    if (!track.songId.empty() && !extension.empty() &&
        !musicCachePath.empty()) {
        std::filesystem::path cached = musicCachePath / L"ncm-cache" /
            (track.songId + extension);
        DWORD attributes = GetFileAttributesW(cached.c_str());
        if (attributes != INVALID_FILE_ATTRIBUTES &&
            !(attributes & FILE_ATTRIBUTE_DIRECTORY) &&
            matchesSource(cached.wstring())) {
            return true;
        }
    }
    return false;
}

static TwilightSessionTrack ResolveTwilightTrackByFingerprint(
    const TwilightPlaybackSessionSnapshot& session,
    const std::wstring& fingerprint, const std::wstring& extension) {
    if (!session.valid || fingerprint.empty()) return {};
    std::filesystem::path musicCachePath = ReadTwilightMusicCachePath();
    auto identityKey = [](const TwilightSessionTrack& track) {
        if (!track.songId.empty()) return L"ncm:" + track.songId;
        if (!track.id.empty()) return L"id:" + track.id;
        return L"text:" + NormalizeNeteaseMatchText(track.title) + L"\x1f" +
               NormalizeNeteaseArtistText(track.artist) + L"\x1f" +
               std::to_wstring(track.durationMs);
    };
    std::vector<std::pair<int, TwilightSessionTrack>> matches;
    if (session.hasTrack && TwilightTrackMatchesFingerprint(
            session.track, fingerprint, extension, musicCachePath)) {
        matches.emplace_back(-1, session.track);
    }
    for (size_t i = 0; i < session.queue.size(); ++i) {
        if (TwilightTrackMatchesFingerprint(
                session.queue[i], fingerprint, extension, musicCachePath)) {
            matches.emplace_back(static_cast<int>(i), session.queue[i]);
        }
    }
    if (matches.empty()) return {};
    std::wstring matchedIdentity = identityKey(matches.front().second);
    for (const auto& match : matches) {
        if (identityKey(match.second) != matchedIdentity) return {};
    }
    size_t selected = 0;
    if (session.queueIndex >= 0) {
        for (size_t i = 0; i < matches.size(); ++i) {
            if (matches[i].first == session.queueIndex) {
                selected = i;
                break;
            }
        }
    }
    TwilightSessionTrack result = matches[selected].second;
    result.fingerprint = fingerprint;
    return result;
}

static TwilightSessionTrack ResolveTwilightCurrentTrackByClock(
    const TwilightPlaybackSessionSnapshot& session,
    const TwilightAudioClock& clock) {
    if (!session.valid || !session.hasTrack || !session.hasPosition ||
        !session.observedAtTick ||
        !clock.valid || !clock.started || clock.fingerprint.empty() ||
        session.track.durationMs <= 0 || clock.durationMs <= 0) {
        return {};
    }

    constexpr int64_t kDurationToleranceMs = 1500;
    constexpr int64_t kPositionToleranceMs = 2500;
    if (std::llabs(session.track.durationMs - clock.durationMs) >
        kDurationToleranceMs) {
        return {};
    }
    ULONGLONG comparisonTick = clock.state == TwilightAudioState::Paused
        ? clock.anchorTick
        : GetTickCount64();
    ULONGLONG sessionProjectionStart =
        clock.state == TwilightAudioState::Playing
            ? std::max(session.observedAtTick, clock.anchorTick)
            : session.observedAtTick;
    int64_t sessionPositionMs = session.positionMs;
    if (comparisonTick > sessionProjectionStart) {
        sessionPositionMs += static_cast<int64_t>(
            comparisonTick - sessionProjectionStart);
    }
    sessionPositionMs = std::min(sessionPositionMs,
                                 session.track.durationMs);
    int64_t audioPositionMs = ProjectTwilightAudioPosition(
        clock, comparisonTick);
    if (std::llabs(sessionPositionMs - audioPositionMs) >
        kPositionToleranceMs) {
        return {};
    }

    TwilightSessionTrack result = session.track;
    result.fingerprint = clock.fingerprint;
    return result;
}

struct TwilightAudioFileId {
    bool valid = false;
    DWORD volume = 0;
    DWORD high = 0;
    DWORD low = 0;
};

static bool operator==(const TwilightAudioFileId& left,
                       const TwilightAudioFileId& right) {
    return left.valid && right.valid && left.volume == right.volume &&
           left.high == right.high && left.low == right.low;
}

struct TwilightAudioLogTail {
    bool initialized = false;
    TwilightAudioFileId currentFileId;
    uint64_t byteOffset = 0;
    std::string partialLine;
    TwilightAudioClock clock;
    std::wstring lastSessionId;
    uint64_t lastSequence = 0;
    bool sessionRestarted = false;
    bool hasSessionFileStamp = false;
    FILETIME sessionFileWriteTime{};
    uint64_t sessionFileSize = 0;
    TwilightPlaybackSessionSnapshot sessionSnapshot;
};

static TwilightAudioFileId TwilightFileId(
    const BY_HANDLE_FILE_INFORMATION& info) {
    return {true, info.dwVolumeSerialNumber, info.nFileIndexHigh,
            info.nFileIndexLow};
}

static ULONGLONG TwilightFileTimeTick(const FILETIME& eventFileTime) {
    FILETIME nowFileTime{};
    GetSystemTimeAsFileTime(&nowFileTime);
    ULARGE_INTEGER eventValue{};
    eventValue.HighPart = eventFileTime.dwHighDateTime;
    eventValue.LowPart = eventFileTime.dwLowDateTime;
    ULARGE_INTEGER nowValue{};
    nowValue.HighPart = nowFileTime.dwHighDateTime;
    nowValue.LowPart = nowFileTime.dwLowDateTime;
    ULONGLONG nowTick = GetTickCount64();
    if (eventValue.QuadPart >= nowValue.QuadPart) return nowTick;
    ULONGLONG ageMs = (nowValue.QuadPart - eventValue.QuadPart) / 10000;
    return ageMs < nowTick ? nowTick - ageMs : 0;
}

static ULONGLONG TwilightEventTick(const std::wstring& timestamp) {
    SYSTEMTIME eventTime{};
    if (swscanf_s(timestamp.c_str(), L"%hu-%hu-%huT%hu:%hu:%hu.%huZ",
                  &eventTime.wYear, &eventTime.wMonth, &eventTime.wDay,
                  &eventTime.wHour, &eventTime.wMinute,
                  &eventTime.wSecond, &eventTime.wMilliseconds) != 7) {
        return GetTickCount64();
    }
    FILETIME eventFileTime{};
    return SystemTimeToFileTime(&eventTime, &eventFileTime)
        ? TwilightFileTimeTick(eventFileTime)
        : GetTickCount64();
}

static void ConsumeTwilightAudioDiagnosticLine(
    std::string_view line, TwilightAudioLogTail& tail) {
    using namespace winrt::Windows::Data::Json;
    if (line.find("\"playback-state\"") == std::string_view::npos &&
        line.find("\"session-start\"") == std::string_view::npos) {
        return;
    }
    try {
        std::wstring wide = Utf8ToWide(std::string(line));
        if (wide.empty()) return;
        JsonObject root = JsonObject::Parse(winrt::hstring(wide));
        std::wstring sessionId = std::wstring(
            root.GetNamedString(L"sessionId", L""));
        double sequenceValue = root.GetNamedNumber(L"sequence", 0);
        if (sessionId.empty() || !std::isfinite(sequenceValue) ||
            sequenceValue <= 0) {
            return;
        }
        uint64_t sequence = static_cast<uint64_t>(sequenceValue);
        if (tail.lastSessionId != sessionId) {
            uint64_t nextEpoch = tail.clock.epoch + 1;
            tail.clock = {};
            tail.clock.epoch = nextEpoch;
            tail.clock.sessionId = sessionId;
            tail.lastSessionId = sessionId;
            tail.lastSequence = 0;
            tail.sessionRestarted = true;
            tail.hasSessionFileStamp = false;
            tail.sessionFileWriteTime = {};
            tail.sessionFileSize = 0;
            tail.sessionSnapshot = {};
        }
        if (sequence <= tail.lastSequence) return;
        tail.lastSequence = sequence;
        tail.clock.sequence = sequence;

        std::wstring event = std::wstring(
            root.GetNamedString(L"event", L""));
        if (event == L"session-start") return;
        JsonObject details = root.GetNamedObject(L"details", JsonObject{});
        ULONGLONG eventTick = TwilightEventTick(std::wstring(
            root.GetNamedString(L"timestamp", L"")));
        if (event == L"playback-state") {
            JsonObject source = details.GetNamedObject(L"source", JsonObject{});
            std::wstring kind = std::wstring(
                source.GetNamedString(L"kind", L"unknown"));
            std::wstring fingerprint = std::wstring(
                source.GetNamedString(L"fingerprint", L""));
            if (kind != L"unknown" && !fingerprint.empty()) {
                if (tail.clock.fingerprint != fingerprint) ++tail.clock.epoch;
                tail.clock.valid = true;
                tail.clock.fingerprint = fingerprint;
                tail.clock.extension = std::wstring(
                    source.GetNamedString(L"extension", L""));
            }
            std::wstring state = std::wstring(
                details.GetNamedString(L"state", L""));
            tail.clock.state = state == L"playing"
                ? TwilightAudioState::Playing
                : state == L"paused" ? TwilightAudioState::Paused
                : state == L"stopped" ? TwilightAudioState::Stopped
                                      : TwilightAudioState::Unknown;
            tail.clock.started = tail.clock.state == TwilightAudioState::Playing ||
                                 tail.clock.state == TwilightAudioState::Paused;
            double position = details.GetNamedNumber(L"position", 0);
            double duration = details.GetNamedNumber(L"duration", 0);
            tail.clock.positionMs = std::isfinite(position) && position >= 0
                ? static_cast<int64_t>(position * 1000.0)
                : 0;
            tail.clock.durationMs = std::isfinite(duration) && duration > 0
                ? static_cast<int64_t>(duration * 1000.0)
                : 0;
            JsonObject controls = details.GetNamedObject(
                L"controls", JsonObject{});
            double rate = controls.GetNamedNumber(L"playbackRate", 1);
            tail.clock.rate = std::isfinite(rate) && rate > 0 ? rate : 1.0;
            tail.clock.anchorTick = eventTick;
        }
    } catch (...) {}
}

static bool ReadTwilightAudioLogHandle(
    HANDLE file, uint64_t& offset, std::string& partial,
    TwilightAudioLogTail& tail) {
    LARGE_INTEGER target{};
    target.QuadPart = static_cast<LONGLONG>(offset);
    if (!SetFilePointerEx(file, target, nullptr, FILE_BEGIN)) return false;
    char buffer[64 * 1024];
    for (;;) {
        DWORD read = 0;
        if (!ReadFile(file, buffer, sizeof(buffer), &read, nullptr)) {
            return false;
        }
        if (!read) break;
        offset += read;
        partial.append(buffer, read);
        size_t consumed = 0;
        for (;;) {
            size_t newline = partial.find('\n', consumed);
            if (newline == std::string::npos) break;
            size_t length = newline - consumed;
            if (length && partial[consumed + length - 1] == '\r') --length;
            if (length) {
                ConsumeTwilightAudioDiagnosticLine(
                    std::string_view(partial).substr(consumed, length), tail);
            }
            consumed = newline + 1;
        }
        if (consumed) partial.erase(0, consumed);
    }
    return true;
}

static bool OpenTwilightAudioLog(
    const std::filesystem::path& path, TwilightFileHandle& file,
    BY_HANDLE_FILE_INFORMATION& info) {
    file.value = CreateFileW(
        path.c_str(), GENERIC_READ,
        FILE_SHARE_READ | FILE_SHARE_WRITE | FILE_SHARE_DELETE, nullptr,
        OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL | FILE_FLAG_SEQUENTIAL_SCAN,
        nullptr);
    return file.value != INVALID_HANDLE_VALUE &&
           GetFileInformationByHandle(file.value, &info);
}

static void HandleTwilightAudioSourceTransition(
    bool preserveVisibleMedia = false) {
    g_twilightTrackGeneration.fetch_add(1);
    g_twilightCoverGeneration.fetch_add(1);
    if (!preserveVisibleMedia) {
        g_twilightPendingTrackUntilTick = 0;
        {
            std::lock_guard<std::mutex> lock(
                g_twilightAccessiblePlaybackMtx);
            g_twilightPendingOldTrackKey.clear();
        }
    }
    SetTwilightLikeState(NeteaseLikeState::Unknown, false);
    ClearNeteaseLyrics(false);
    if (preserveVisibleMedia) {
        // A source switch reports the old stream stopping before the new
        // playback-session identity is ready. Keep the visible player shell
        // stable and replace it only after the new identity is confirmed.
        DispatchMediaUpdate();
        return;
    }
    bool changed = false;
    {
        std::lock_guard<std::mutex> lock(g_mediaMtx);
        if (g_selectedPlayer.load() == PlayerKind::TwilightEcho) {
            changed = g_media.hasMedia || !g_media.title.empty() ||
                      !g_media.artist.empty() ||
                      !g_media.thumbnailBytes.empty();
            g_media.thumbnailBytes.clear();
            g_media.thumbnailHash = 0;
            g_media.thumbnailStreamSize = 0;
            g_media.title.clear();
            g_media.artist.clear();
            g_media.appUserModelId.clear();
            g_media.hasMedia = false;
            g_media.isPlaying = false;
            g_media.canSkipPrevious = false;
            g_media.canSkipNext = false;
            g_media.canShuffle = false;
            g_media.canRepeat = false;
            g_media.canSeek = false;
            g_media.appIconBytes.clear();
            g_media.appIconKey.clear();
        }
    }
    if (changed) DispatchMediaUpdate();
}

static bool PublishTwilightAudioClock(const TwilightAudioClock& candidate) {
    if (!candidate.valid || candidate.fingerprint.empty()) return false;
    bool hasVisibleTwilightMedia = false;
    {
        std::lock_guard<std::mutex> lock(g_mediaMtx);
        hasVisibleTwilightMedia =
            g_selectedPlayer.load() == PlayerKind::TwilightEcho &&
            g_media.hasMedia && IsTwilightSession(g_media.appUserModelId);
    }
    bool identityChanged = false;
    bool invalidateIdentity = false;
    bool stateChanged = false;
    bool enteredStopped = false;
    bool resumedSameSource = false;
    {
        std::lock_guard<std::mutex> lock(g_twilightAudioMtx);
        identityChanged = !g_twilightAudioClock.valid ||
            g_twilightAudioClock.fingerprint != candidate.fingerprint;
        enteredStopped = !identityChanged &&
            g_twilightAudioClock.state != TwilightAudioState::Stopped &&
            candidate.state == TwilightAudioState::Stopped &&
            (g_twilightResolvedTrack.valid || hasVisibleTwilightMedia);
        resumedSameSource = !identityChanged &&
            g_twilightAudioClock.state == TwilightAudioState::Stopped &&
            candidate.state != TwilightAudioState::Stopped;
        invalidateIdentity = identityChanged;
        stateChanged = identityChanged ||
            g_twilightAudioClock.state != candidate.state ||
            g_twilightAudioClock.started != candidate.started ||
            g_twilightAudioClock.positionMs != candidate.positionMs ||
            g_twilightAudioClock.durationMs != candidate.durationMs ||
            g_twilightAudioClock.rate != candidate.rate;
        TwilightAudioClock next = candidate;
        next.epoch = identityChanged ? g_twilightAudioClock.epoch + 1
                                     : g_twilightAudioClock.epoch;
        g_twilightAudioClock = std::move(next);
        if (invalidateIdentity) {
            g_twilightResolvedTrack = {};
            g_twilightAudioIdentityPending = true;
            g_twilightSessionAuthorityActive = false;
        }
    }
    if (enteredStopped) {
        ULONGLONG nowTick = GetTickCount64();
        ULONGLONG graceUntil = nowTick + 5000;
        ExtendTwilightTrackTransitionUntil(graceUntil);
        std::lock_guard<std::mutex> lock(g_twilightAccessiblePlaybackMtx);
        if (g_twilightPendingOldTrackKey.empty()) {
            g_twilightPendingOldTrackKey =
                TwilightTrackKey(g_twilightAccessiblePlayback);
        }
    } else if (resumedSameSource) {
        g_twilightPendingTrackUntilTick = 0;
        std::lock_guard<std::mutex> lock(g_twilightAccessiblePlaybackMtx);
        g_twilightPendingOldTrackKey.clear();
    }
    if (invalidateIdentity) {
        HandleTwilightAudioSourceTransition(true);
    } else if (stateChanged && g_twilightSessionAuthorityActive.load()) {
        CommitTwilightAccessiblePlayback(GetTwilightAccessiblePlayback());
    }
    return invalidateIdentity || stateChanged;
}

static bool PollTwilightAudioDiagnostics(TwilightAudioLogTail& tail) {
    std::filesystem::path current = TwilightAppDataPath(
        L"logs\\audio\\audio-diagnostics.jsonl");
    std::filesystem::path previous = TwilightAppDataPath(
        L"logs\\audio\\audio-diagnostics.previous.jsonl");
    TwilightFileHandle currentFile;
    BY_HANDLE_FILE_INFORMATION currentInfo{};
    if (!OpenTwilightAudioLog(current, currentFile, currentInfo)) return false;
    TwilightAudioFileId currentId = TwilightFileId(currentInfo);

    if (!tail.initialized) {
        TwilightFileHandle previousFile;
        BY_HANDLE_FILE_INFORMATION previousInfo{};
        if (OpenTwilightAudioLog(previous, previousFile, previousInfo)) {
            uint64_t previousOffset = 0;
            std::string previousPartial;
            ReadTwilightAudioLogHandle(previousFile.value, previousOffset,
                                       previousPartial, tail);
        }
        tail.partialLine.clear();
        tail.byteOffset = 0;
        tail.currentFileId = currentId;
        tail.initialized = true;
    } else if (!(tail.currentFileId == currentId)) {
        TwilightFileHandle rotatedFile;
        BY_HANDLE_FILE_INFORMATION rotatedInfo{};
        if (OpenTwilightAudioLog(previous, rotatedFile, rotatedInfo) &&
            tail.currentFileId == TwilightFileId(rotatedInfo)) {
            ReadTwilightAudioLogHandle(
                rotatedFile.value, tail.byteOffset,
                tail.partialLine, tail);
        }
        tail.partialLine.clear();
        tail.byteOffset = 0;
        tail.currentFileId = currentId;
    } else {
        ULARGE_INTEGER size{};
        size.HighPart = currentInfo.nFileSizeHigh;
        size.LowPart = currentInfo.nFileSizeLow;
        if (size.QuadPart < tail.byteOffset) {
            tail.byteOffset = 0;
            tail.partialLine.clear();
        }
    }
    if (!ReadTwilightAudioLogHandle(
            currentFile.value, tail.byteOffset,
            tail.partialLine, tail)) {
        return false;
    }
    if (tail.sessionRestarted) {
        tail.sessionRestarted = false;
        ResetTwilightAudioState();
        if (!tail.clock.valid) {
            HandleTwilightAudioSourceTransition();
            return true;
        }
    }
    return PublishTwilightAudioClock(tail.clock);
}

static bool CommitTwilightResolvedTrack(TwilightSessionTrack resolved) {
    bool pending = false;
    bool trackChanged = false;
    {
        std::lock_guard<std::mutex> lock(g_twilightAudioMtx);
        if (!g_twilightAudioClock.valid || !resolved.valid ||
            resolved.fingerprint != g_twilightAudioClock.fingerprint) {
            return false;
        }
        pending = g_twilightAudioIdentityPending.load();
        trackChanged = g_twilightResolvedTrack.valid &&
            (g_twilightResolvedTrack.id != resolved.id ||
             g_twilightResolvedTrack.queueEntryId != resolved.queueEntryId);
        g_twilightResolvedTrack = std::move(resolved);
        g_twilightAudioIdentityPending = false;
        g_twilightSessionAuthorityActive = true;
    }
    if (trackChanged && !pending) {
        g_twilightTrackGeneration.fetch_add(1);
        g_twilightCoverGeneration.fetch_add(1);
        ClearNeteaseLyrics(false);
    }
    g_twilightPendingTrackUntilTick = 0;
    {
        std::lock_guard<std::mutex> lock(g_twilightAccessiblePlaybackMtx);
        g_twilightPendingOldTrackKey.clear();
    }
    auto committed = CommitTwilightAccessiblePlayback(
        GetTwilightAccessiblePlayback());
    return committed.accepted;
}

static const TwilightPlaybackSessionSnapshot&
PollTwilightPlaybackSessionSnapshot(TwilightAudioLogTail& tail) {
    WIN32_FILE_ATTRIBUTE_DATA attributes{};
    std::filesystem::path path = TwilightAppDataPath(
        L"playback-session.json");
    if (!GetFileAttributesExW(path.c_str(), GetFileExInfoStandard,
                              &attributes)) {
        return tail.sessionSnapshot;
    }
    ULARGE_INTEGER size{};
    size.HighPart = attributes.nFileSizeHigh;
    size.LowPart = attributes.nFileSizeLow;
    if (tail.hasSessionFileStamp &&
        CompareFileTime(&tail.sessionFileWriteTime,
                        &attributes.ftLastWriteTime) == 0 &&
        tail.sessionFileSize == size.QuadPart) {
        return tail.sessionSnapshot;
    }
    TwilightPlaybackSessionSnapshot parsed =
        ReadTwilightPlaybackSessionSnapshot();
    if (parsed.valid) {
        parsed.observedAtTick =
            TwilightFileTimeTick(attributes.ftLastWriteTime);
        if (!tail.sessionSnapshot.valid ||
            parsed.revision >= tail.sessionSnapshot.revision) {
            tail.sessionSnapshot = std::move(parsed);
        }
        tail.sessionFileWriteTime = attributes.ftLastWriteTime;
        tail.sessionFileSize = size.QuadPart;
        tail.hasSessionFileStamp = true;
    }
    return tail.sessionSnapshot;
}

static bool CommitTwilightSessionIdentityWithoutAudio(
    TwilightSessionTrack resolved) {
    if (!resolved.valid) return false;
    bool trackChanged = false;
    {
        std::lock_guard<std::mutex> lock(g_twilightAudioMtx);
        if (g_twilightAudioClock.valid) return false;
        trackChanged = !g_twilightResolvedTrack.valid ||
            g_twilightResolvedTrack.id != resolved.id ||
            g_twilightResolvedTrack.queueEntryId != resolved.queueEntryId;
        resolved.fingerprint.clear();
        g_twilightResolvedTrack = std::move(resolved);
        g_twilightAudioIdentityPending = false;
        g_twilightSessionAuthorityActive = true;
    }
    if (trackChanged) {
        g_twilightTrackGeneration.fetch_add(1);
        g_twilightCoverGeneration.fetch_add(1);
        ClearNeteaseLyrics(false);
    }
    return CommitTwilightAccessiblePlayback(
        trackChanged ? TwilightAccessiblePlayback{}
                     : GetTwilightAccessiblePlayback()).accepted;
}

static bool TryResolveTwilightAudioTrack(TwilightAudioLogTail& tail) {
    const TwilightPlaybackSessionSnapshot& session =
        PollTwilightPlaybackSessionSnapshot(tail);
    if (!session.valid) return false;
    TwilightAudioClock clock = GetTwilightAudioClock();
    if (!session.hasTrack && (!clock.valid || !clock.started)) {
        ULONGLONG pendingUntil = g_twilightPendingTrackUntilTick.load();
        if (pendingUntil && GetTickCount64() <= pendingUntil) {
            return false;
        }
        bool releaseAuthority = false;
        {
            std::lock_guard<std::mutex> lock(g_mediaMtx);
            releaseAuthority =
                g_selectedPlayer.load() == PlayerKind::TwilightEcho &&
                g_media.hasMedia && IsTwilightSession(g_media.appUserModelId);
        }
        {
            std::lock_guard<std::mutex> lock(g_twilightAudioMtx);
            releaseAuthority = releaseAuthority ||
                               g_twilightSessionAuthorityActive.load() ||
                               g_twilightResolvedTrack.valid;
            g_twilightResolvedTrack = {};
            g_twilightAudioIdentityPending = false;
            // Keep the empty session authoritative while clearing the shared
            // UIA snapshot, then allow normal UIA fallback again.
            g_twilightSessionAuthorityActive = true;
        }
        if (releaseAuthority) {
            HandleTwilightAudioSourceTransition();
            StoreTwilightAccessiblePlayback({});
        }
        g_twilightSessionAuthorityActive = false;
        return false;
    }
    if (!clock.valid) {
        return CommitTwilightSessionIdentityWithoutAudio(session.track);
    }
    if (!clock.started || clock.fingerprint.empty()) return false;
    TwilightSessionTrack current = GetTwilightResolvedTrack();
    if (!g_twilightAudioIdentityPending.load() && current.valid &&
        current.fingerprint == clock.fingerprint &&
        current.revision == session.revision) {
        return true;
    }
    TwilightSessionTrack resolved = ResolveTwilightTrackByFingerprint(
        session, clock.fingerprint, clock.extension);
    if (!resolved.valid) {
        resolved = ResolveTwilightCurrentTrackByClock(session, clock);
    }
    if (!resolved.valid) return false;
    if (current.valid && current.fingerprint == resolved.fingerprint &&
        current.id == resolved.id &&
        current.queueEntryId == resolved.queueEntryId &&
        current.revision == resolved.revision) {
        return true;
    }
    return CommitTwilightResolvedTrack(std::move(resolved));
}

static void ResetTwilightAudioState() {
    std::lock_guard<std::mutex> lock(g_twilightAudioMtx);
    g_twilightAudioClock = {};
    g_twilightResolvedTrack = {};
    g_twilightAudioIdentityPending = false;
    g_twilightSessionAuthorityActive = false;
}

static std::wstring ResolveTwilightCoverSourceFromPlaybackSession(
    const std::wstring& title, const std::wstring& artist) {
    using namespace winrt::Windows::Data::Json;
    std::wstring json = ReadTwilightPlaybackSession();
    if (json.empty()) return {};
    try {
        JsonObject track = JsonObject::Parse(winrt::hstring(json))
                               .GetNamedObject(L"data")
                               .GetNamedObject(L"track");
        std::wstring candidateTitle = std::wstring(
            track.GetNamedString(L"title", L""));
        std::wstring candidateArtist = std::wstring(
            track.GetNamedString(L"artist", L""));
        if (NormalizeNeteaseMatchText(candidateTitle) !=
            NormalizeNeteaseMatchText(title)) {
            return {};
        }
        std::wstring wantedArtist = NormalizeNeteaseArtistText(artist);
        if (!wantedArtist.empty() &&
            NormalizeNeteaseArtistText(candidateArtist) != wantedArtist) {
            return {};
        }
        std::wstring coverSource = std::wstring(
            track.GetNamedString(L"coverSource", L""));
        if (!IsHttpCoverSource(coverSource)) {
            coverSource = std::wstring(track.GetNamedString(L"cover", L""));
        }
        return IsHttpCoverSource(coverSource) ? coverSource : std::wstring{};
    } catch (...) {
        return {};
    }
}

static std::vector<BYTE> DownloadTwilightCoverBytes(
    const std::wstring& url) {
    if (!IsHttpCoverSource(url) || url.size() > 8192) return {};
    URL_COMPONENTSW parts{};
    parts.dwStructSize = sizeof(parts);
    parts.dwSchemeLength = static_cast<DWORD>(-1);
    parts.dwHostNameLength = static_cast<DWORD>(-1);
    parts.dwUrlPathLength = static_cast<DWORD>(-1);
    parts.dwExtraInfoLength = static_cast<DWORD>(-1);
    if (!WinHttpCrackUrl(url.c_str(), static_cast<DWORD>(url.size()), 0,
                         &parts) || !parts.lpszHostName ||
        !parts.dwHostNameLength) {
        return {};
    }

    std::wstring host(parts.lpszHostName, parts.dwHostNameLength);
    std::wstring path = parts.dwUrlPathLength
        ? std::wstring(parts.lpszUrlPath, parts.dwUrlPathLength)
        : L"/";
    if (parts.dwExtraInfoLength) {
        path.append(parts.lpszExtraInfo, parts.dwExtraInfoLength);
    }
    NeteaseWinHttpHandle internet;
    internet.value = WinHttpOpen(L"Windhawk-TwilightEcho-Cover/1.0",
                                 WINHTTP_ACCESS_TYPE_AUTOMATIC_PROXY,
                                 WINHTTP_NO_PROXY_NAME,
                                 WINHTTP_NO_PROXY_BYPASS, 0);
    if (!internet.value) return {};
    WinHttpSetTimeouts(internet.value, 1500, 2500, 3000, 5000);
    NeteaseWinHttpHandle connection;
    connection.value = WinHttpConnect(internet.value, host.c_str(),
                                      parts.nPort, 0);
    if (!connection.value) return {};
    NeteaseWinHttpHandle request;
    DWORD flags = parts.nScheme == INTERNET_SCHEME_HTTPS
        ? WINHTTP_FLAG_SECURE
        : 0;
    request.value = WinHttpOpenRequest(
        connection.value, L"GET", path.c_str(), nullptr, WINHTTP_NO_REFERER,
        WINHTTP_DEFAULT_ACCEPT_TYPES, flags);
    static const wchar_t kHeaders[] = L"Accept: image/*\r\n";
    if (!request.value ||
        !WinHttpSendRequest(request.value, kHeaders, -1L,
                            WINHTTP_NO_REQUEST_DATA, 0, 0, 0) ||
        !WinHttpReceiveResponse(request.value, nullptr)) {
        return {};
    }
    DWORD statusCode = 0;
    DWORD statusCodeSize = sizeof(statusCode);
    if (!WinHttpQueryHeaders(request.value,
                             WINHTTP_QUERY_STATUS_CODE |
                                 WINHTTP_QUERY_FLAG_NUMBER,
                             WINHTTP_HEADER_NAME_BY_INDEX, &statusCode,
                             &statusCodeSize, WINHTTP_NO_HEADER_INDEX) ||
        statusCode != 200) {
        return {};
    }

    std::vector<BYTE> result;
    BYTE buffer[8192];
    for (;;) {
        DWORD bytesRead = 0;
        if (!WinHttpReadData(request.value, buffer, sizeof(buffer),
                             &bytesRead)) {
            return {};
        }
        if (!bytesRead) break;
        if (result.size() + bytesRead > 4 * 1024 * 1024) return {};
        result.insert(result.end(), buffer, buffer + bytesRead);
    }
    return result;
}

static void ScheduleTwilightAccessibleCoverFetch(
    const std::wstring& title, const std::wstring& artist,
    int64_t expectedDurationMs, uint64_t expectedTrackGeneration,
    const std::wstring& preferredCoverSource) {
    if (title.empty()) return;
    uint64_t generation = 0;
    {
        std::lock_guard<std::mutex> lock(
            g_twilightAccessiblePlaybackMtx);
        if (expectedTrackGeneration !=
            g_twilightTrackGeneration.load()) {
            return;
        }
        generation = g_twilightCoverGeneration.fetch_add(1) + 1;
    }
    SpawnTrackedWorker([title, artist, expectedDurationMs, generation,
                        expectedTrackGeneration, preferredCoverSource]() {
        winrt::init_apartment(winrt::apartment_type::multi_threaded);
        std::vector<BYTE> bytes;
        for (int attempt = 0; attempt < 3; ++attempt) {
            if (g_unloading ||
                generation != g_twilightCoverGeneration.load() ||
                expectedTrackGeneration !=
                    g_twilightTrackGeneration.load()) {
                break;
            }
            TwilightSessionTrack exactTrack = GetTwilightResolvedTrack();
            std::wstring coverSource =
                IsHttpCoverSource(preferredCoverSource)
                    ? preferredCoverSource
                    : exactTrack.valid && exactTrack.title == title &&
                              exactTrack.artist == artist &&
                              IsHttpCoverSource(exactTrack.coverSource)
                          ? exactTrack.coverSource
                          : ResolveTwilightCoverSourceFromPlaybackSession(
                                title, artist);
            if (coverSource.empty()) {
                NeteaseResolvedSong resolved =
                    ResolveNeteaseSongIdFromTwilightApi(
                        title, artist, expectedDurationMs);
                if (resolved.coverReliable) {
                    coverSource = std::move(resolved.coverUrl);
                }
            }
            if (!coverSource.empty()) {
                bytes = DownloadTwilightCoverBytes(coverSource);
            }
            if (!bytes.empty() || attempt == 2) break;
            for (int slice = 0; slice < 5; ++slice) {
                if (g_unloading ||
                    generation != g_twilightCoverGeneration.load() ||
                    expectedTrackGeneration !=
                        g_twilightTrackGeneration.load()) {
                    break;
                }
                Sleep(100);
            }
        }

        bool committed = false;
        if (!bytes.empty() && !g_unloading) {
            bool preferredBridgeCover =
                IsHttpCoverSource(preferredCoverSource);
            uint64_t hash = 0;
            for (size_t i = 0; i < bytes.size(); i += 1024) {
                hash = hash * 31 + bytes[i];
            }
            std::lock_guard<std::mutex> lock(g_mediaMtx);
            if (generation == g_twilightCoverGeneration.load() &&
                expectedTrackGeneration ==
                    g_twilightTrackGeneration.load() &&
                g_selectedPlayer.load() == PlayerKind::TwilightEcho &&
                g_media.hasMedia &&
                g_media.appUserModelId == kTwilightAumid &&
                g_media.title == title && g_media.artist == artist &&
                (preferredBridgeCover ||
                 g_media.thumbnailBytes.empty())) {
                g_media.thumbnailStreamSize = bytes.size();
                g_media.thumbnailHash = hash;
                g_media.thumbnailBytes = std::move(bytes);
                committed = true;
            }
        }
        if (committed) DispatchMediaUpdate();
        winrt::uninit_apartment();
    });
}

static std::wstring EncodeUrlComponentUtf8(const std::wstring& value) {
    if (value.empty()) return {};
    int byteCount = WideCharToMultiByte(CP_UTF8, 0, value.data(),
                                        static_cast<int>(value.size()),
                                        nullptr, 0, nullptr, nullptr);
    if (byteCount <= 0) return {};
    std::string bytes(static_cast<size_t>(byteCount), '\0');
    if (WideCharToMultiByte(CP_UTF8, 0, value.data(),
                            static_cast<int>(value.size()), bytes.data(),
                            byteCount, nullptr, nullptr) != byteCount) {
        return {};
    }
    static constexpr wchar_t kHex[] = L"0123456789ABCDEF";
    std::wstring encoded;
    encoded.reserve(bytes.size() * 3);
    for (unsigned char c : bytes) {
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') ||
            (c >= '0' && c <= '9') || c == '-' || c == '_' ||
            c == '.' || c == '~') {
            encoded.push_back(static_cast<wchar_t>(c));
        } else {
            encoded.push_back(L'%');
            encoded.push_back(kHex[c >> 4]);
            encoded.push_back(kHex[c & 0x0F]);
        }
    }
    return encoded;
}

static std::wstring DownloadTwilightNeteaseSearchJson(
    const std::wstring& title, const std::wstring& artist) {
    std::wstring keywords = TrimCopy(title);
    if (!artist.empty()) keywords += L" " + TrimCopy(artist);
    std::wstring encoded = EncodeUrlComponentUtf8(keywords);
    if (encoded.empty() || NeteaseLyricsShouldStop()) return {};

    NeteaseWinHttpHandle internet;
    internet.value = WinHttpOpen(L"Windhawk-TwilightEcho-Lyrics/1.0",
                                 WINHTTP_ACCESS_TYPE_NO_PROXY,
                                 WINHTTP_NO_PROXY_NAME,
                                 WINHTTP_NO_PROXY_BYPASS, 0);
    if (!internet.value) return {};
    WinHttpSetTimeouts(internet.value, 300, 500, 1200, 1800);
    NeteaseWinHttpHandle connection;
    connection.value = WinHttpConnect(internet.value, L"127.0.0.1", 3100, 0);
    if (!connection.value || NeteaseLyricsShouldStop()) return {};
    std::wstring path = L"/cloudsearch?limit=20&keywords=" + encoded;
    NeteaseWinHttpHandle request;
    request.value = WinHttpOpenRequest(connection.value, L"GET", path.c_str(),
                                       nullptr, WINHTTP_NO_REFERER,
                                       WINHTTP_DEFAULT_ACCEPT_TYPES, 0);
    if (!request.value ||
        !WinHttpSendRequest(request.value, WINHTTP_NO_ADDITIONAL_HEADERS, 0,
                            WINHTTP_NO_REQUEST_DATA, 0, 0, 0) ||
        !WinHttpReceiveResponse(request.value, nullptr)) {
        return {};
    }
    DWORD statusCode = 0;
    DWORD statusCodeSize = sizeof(statusCode);
    if (!WinHttpQueryHeaders(request.value,
                             WINHTTP_QUERY_STATUS_CODE | WINHTTP_QUERY_FLAG_NUMBER,
                             WINHTTP_HEADER_NAME_BY_INDEX, &statusCode,
                             &statusCodeSize, WINHTTP_NO_HEADER_INDEX) ||
        statusCode != 200) {
        return {};
    }
    std::string body;
    char buffer[4096];
    while (!NeteaseLyricsShouldStop()) {
        DWORD bytesRead = 0;
        if (!WinHttpReadData(request.value, buffer, sizeof(buffer), &bytesRead)) {
            return {};
        }
        if (!bytesRead) break;
        if (body.size() + bytesRead > 2 * 1024 * 1024) return {};
        body.append(buffer, buffer + bytesRead);
    }
    return NeteaseLyricsShouldStop() ? std::wstring{} : Utf8ToWide(body);
}

static NeteaseResolvedSong ResolveNeteaseSongIdFromTwilightApi(
    const std::wstring& title, const std::wstring& artist,
    int64_t expectedDurationMs) {
    using namespace winrt::Windows::Data::Json;
    std::wstring json = DownloadTwilightNeteaseSearchJson(title, artist);
    if (json.empty()) return {};
    std::wstring wantedTitle = NormalizeNeteaseMatchText(title);
    std::wstring wantedArtist = NormalizeNeteaseArtistText(artist);
    NeteaseResolvedSong best;
    int bestScore = -1;
    int64_t bestDurationDifference = INT64_MAX;
    int64_t secondBestDurationDifference = INT64_MAX;
    int bestScoreCandidateCount = 0;
    try {
        JsonArray songs = JsonObject::Parse(winrt::hstring(json))
                              .GetNamedObject(L"result")
                              .GetNamedArray(L"songs");
        for (uint32_t i = 0; i < songs.Size(); ++i) {
            JsonObject song = songs.GetObjectAt(i);
            std::wstring candidateTitle = NormalizeNeteaseMatchText(
                std::wstring(song.GetNamedString(L"name", L"")));
            int titleScore = candidateTitle == wantedTitle
                ? 100
                : (candidateTitle.size() >= 4 && wantedTitle.size() >= 4 &&
                   (candidateTitle.find(wantedTitle) != std::wstring::npos ||
                    wantedTitle.find(candidateTitle) != std::wstring::npos)
                       ? 60
                       : -1);
            if (titleScore < 0) continue;

            std::wstring candidateArtist;
            JsonArray artists = song.HasKey(L"ar")
                ? song.GetNamedArray(L"ar")
                : song.GetNamedArray(L"artists", JsonArray{});
            for (uint32_t j = 0; j < artists.Size(); ++j) {
                std::wstring name = std::wstring(
                    artists.GetObjectAt(j).GetNamedString(L"name", L""));
                if (!name.empty()) {
                    if (!candidateArtist.empty()) candidateArtist += L"/";
                    candidateArtist += name;
                }
            }
            std::wstring normalizedArtist =
                NormalizeNeteaseArtistText(candidateArtist);
            int artistScore = 0;
            if (!wantedArtist.empty() && normalizedArtist == wantedArtist) {
                artistScore = 30;
            } else if (!wantedArtist.empty() && !normalizedArtist.empty() &&
                       (normalizedArtist.find(wantedArtist) != std::wstring::npos ||
                        wantedArtist.find(normalizedArtist) != std::wstring::npos)) {
                artistScore = 20;
            }

            int64_t durationMs = static_cast<int64_t>(
                song.HasKey(L"dt") ? song.GetNamedNumber(L"dt", 0)
                                    : song.GetNamedNumber(L"duration", 0));
            int64_t durationDifference = INT64_MAX;
            if (expectedDurationMs > 0 && durationMs > 0) {
                durationDifference = std::llabs(durationMs - expectedDurationMs);
            }
            int score = titleScore + artistScore;
            std::wstring songId = JsonSongId(song);
            if (songId.empty()) continue;
            std::wstring coverUrl;
            try {
                JsonObject album = song.HasKey(L"al")
                    ? song.GetNamedObject(L"al")
                    : song.GetNamedObject(L"album", JsonObject{});
                coverUrl = std::wstring(
                    album.GetNamedString(L"picUrl", L""));
                if (!IsHttpCoverSource(coverUrl)) coverUrl.clear();
            } catch (...) {}

            if (score > bestScore) {
                best = {std::move(songId), durationMs,
                        std::move(coverUrl), false};
                bestScore = score;
                bestDurationDifference = durationDifference;
                secondBestDurationDifference = INT64_MAX;
                bestScoreCandidateCount = 1;
            } else if (score == bestScore) {
                ++bestScoreCandidateCount;
                if (durationDifference < bestDurationDifference) {
                    secondBestDurationDifference = bestDurationDifference;
                    best = {std::move(songId), durationMs,
                            std::move(coverUrl), false};
                    bestDurationDifference = durationDifference;
                } else if (durationDifference < secondBestDurationDifference) {
                    secondBestDurationDifference = durationDifference;
                }
            }
        }
    } catch (...) {
        return {};
    }
    if (bestScore < 80) return {};
    bool durationClose = expectedDurationMs <= 0 ||
                         bestDurationDifference <= 1500;
    bool unambiguous = bestScoreCandidateCount == 1;
    if (!unambiguous && expectedDurationMs > 0 &&
        bestDurationDifference != INT64_MAX &&
        secondBestDurationDifference != INT64_MAX &&
        secondBestDurationDifference >= bestDurationDifference + 1000) {
        unambiguous = true;
    }
    best.coverReliable = bestScore >= 130 && durationClose && unambiguous &&
                         !best.coverUrl.empty();
    return best;
}

static std::wstring DownloadNeteaseLyricsJson(const std::wstring& songId) {
    if (songId.empty() || NeteaseLyricsShouldStop()) return {};
    NeteaseWinHttpHandle internet;
    internet.value = WinHttpOpen(L"Windhawk-NetEase-Lyrics/1.0",
                                 WINHTTP_ACCESS_TYPE_AUTOMATIC_PROXY,
                                 WINHTTP_NO_PROXY_NAME,
                                 WINHTTP_NO_PROXY_BYPASS, 0);
    if (!internet.value) return {};
    WinHttpSetTimeouts(internet.value, 2000, 3000, 3000, 5000);

    NeteaseWinHttpHandle connection;
    connection.value = WinHttpConnect(internet.value, L"music.163.com",
                                      INTERNET_DEFAULT_HTTPS_PORT, 0);
    if (!connection.value || NeteaseLyricsShouldStop()) return {};

    std::wstring path = L"/api/song/lyric/v1?tv=-1&lv=-1&rv=0&kv=0&yv=0"
                        L"&ytv=0&yrv=0&cp=false&id=" + songId;
    NeteaseWinHttpHandle request;
    request.value = WinHttpOpenRequest(connection.value, L"GET", path.c_str(),
                                       nullptr, WINHTTP_NO_REFERER,
                                       WINHTTP_DEFAULT_ACCEPT_TYPES,
                                       WINHTTP_FLAG_SECURE);
    if (!request.value || NeteaseLyricsShouldStop()) return {};
    static const wchar_t kHeaders[] = L"Referer: https://music.163.com/\r\n";
    if (!WinHttpSendRequest(request.value, kHeaders, -1L,
                            WINHTTP_NO_REQUEST_DATA, 0, 0, 0) ||
        NeteaseLyricsShouldStop() ||
        !WinHttpReceiveResponse(request.value, nullptr)) {
        return {};
    }
    DWORD statusCode = 0;
    DWORD statusCodeSize = sizeof(statusCode);
    if (!WinHttpQueryHeaders(request.value,
                             WINHTTP_QUERY_STATUS_CODE | WINHTTP_QUERY_FLAG_NUMBER,
                             WINHTTP_HEADER_NAME_BY_INDEX, &statusCode,
                             &statusCodeSize, WINHTTP_NO_HEADER_INDEX) ||
        statusCode != 200) {
        return {};
    }

    std::string body;
    char buffer[4096];
    while (!NeteaseLyricsShouldStop()) {
        DWORD bytesRead = 0;
        if (!WinHttpReadData(request.value, buffer, sizeof(buffer), &bytesRead)) return {};
        if (!bytesRead) break;
        if (body.size() + bytesRead > 2 * 1024 * 1024) return {};
        body.append(buffer, buffer + bytesRead);
    }
    return NeteaseLyricsShouldStop() ? std::wstring{} : Utf8ToWide(body);
}

static std::vector<NeteaseLyricLine> ParseNeteaseLrc(const std::wstring& lrc) {
    std::vector<NeteaseLyricLine> result;
    int64_t offsetMs = 0;
    size_t lineStart = 0;
    while (lineStart <= lrc.size()) {
        size_t lineEnd = lrc.find(L'\n', lineStart);
        std::wstring line = lrc.substr(
            lineStart, lineEnd == std::wstring::npos
                           ? std::wstring::npos
                           : lineEnd - lineStart);
        if (!line.empty() && line.back() == L'\r') line.pop_back();
        if (line.rfind(L"[offset:", 0) == 0) {
            size_t close = line.find(L']');
            if (close != std::wstring::npos) {
                try { offsetMs = std::stoll(line.substr(8, close - 8)); } catch (...) {}
            }
        } else {
            bool parsedJsonLine = false;
            std::wstring trimmedLine = TrimCopy(line);
            if (!trimmedLine.empty() && trimmedLine.front() == L'{') {
                try {
                    using namespace winrt::Windows::Data::Json;
                    JsonObject jsonLine = JsonObject::Parse(winrt::hstring(trimmedLine));
                    if (jsonLine.HasKey(L"t") && jsonLine.HasKey(L"c")) {
                        int64_t timeMs = static_cast<int64_t>(
                            jsonLine.GetNamedNumber(L"t"));
                        JsonArray fragments = jsonLine.GetNamedArray(L"c");
                        std::wstring lyricText;
                        for (uint32_t i = 0; i < fragments.Size(); ++i) {
                            try {
                                lyricText += std::wstring(
                                    fragments.GetObjectAt(i).GetNamedString(L"tx", L""));
                            } catch (...) {}
                        }
                        result.push_back({timeMs, std::move(lyricText)});
                        parsedJsonLine = true;
                    }
                } catch (...) {}
            }

            if (!parsedJsonLine) {
                std::vector<int64_t> times;
                size_t cursor = 0;
                while (cursor < line.size() && line[cursor] == L'[') {
                    size_t close = line.find(L']', cursor + 1);
                    if (close == std::wstring::npos) break;
                    std::wstring tag = line.substr(cursor + 1, close - cursor - 1);
                    size_t colon = tag.find(L':');
                    if (colon == std::wstring::npos || colon == 0) break;
                    bool numericMinutes = std::all_of(
                        tag.begin(), tag.begin() + colon,
                        [](wchar_t c) { return c >= L'0' && c <= L'9'; });
                    if (!numericMinutes) break;
                    try {
                        int64_t minutes = std::stoll(tag.substr(0, colon));
                        double seconds = std::stod(tag.substr(colon + 1));
                        times.push_back(static_cast<int64_t>((minutes * 60.0 + seconds) * 1000.0));
                    } catch (...) {}
                    cursor = close + 1;
                }
                if (!times.empty()) {
                    std::wstring lyricText = TrimCopy(line.substr(cursor));
                    for (int64_t timeMs : times) {
                        result.push_back({timeMs, lyricText});
                    }
                }
            }
        }
        if (lineEnd == std::wstring::npos) break;
        lineStart = lineEnd + 1;
    }
    for (auto& line : result) line.timeMs = std::max<int64_t>(0, line.timeMs + offsetMs);
    std::stable_sort(result.begin(), result.end(),
                     [](const auto& a, const auto& b) { return a.timeMs < b.timeMs; });
    return result;
}

static void MergeNeteaseTranslatedLyrics(
    std::vector<NeteaseLyricLine>& originalLines,
    const std::vector<NeteaseLyricLine>& translatedLines) {
    size_t translatedIndex = 0;
    for (auto& line : originalLines) {
        while (translatedIndex + 1 < translatedLines.size() &&
               translatedLines[translatedIndex + 1].timeMs <= line.timeMs) {
            ++translatedIndex;
        }
        const NeteaseLyricLine* best = nullptr;
        for (size_t index : {translatedIndex,
                             std::min(translatedIndex + 1,
                                      translatedLines.size())}) {
            if (index >= translatedLines.size()) continue;
            if (std::llabs(translatedLines[index].timeMs - line.timeMs) <= 600 &&
                (!best || std::llabs(translatedLines[index].timeMs - line.timeMs) <
                              std::llabs(best->timeMs - line.timeMs))) {
                best = &translatedLines[index];
            }
        }
        if (!best || best->text.empty() || best->text == line.text) continue;
        std::wstring original = line.text;
        std::wstring translation = best->text;
        line.text = original + L"\n" + translation;
    }
}

static bool NeteaseLrcParserSelfTest() {
    auto lines = ParseNeteaseLrc(
        L"{\"t\":1250,\"c\":[{\"tx\":\"你\"},{\"tx\":\"好\"}]}\n"
        L"[00:02.50]world");
    auto translated = ParseNeteaseLrc(L"[00:01.25]Hello");
    MergeNeteaseTranslatedLyrics(lines, translated);
    return lines.size() == 2 &&
           lines[0].timeMs == 1250 && lines[0].text == L"你好\nHello" &&
           lines[1].timeMs == 2500 && lines[1].text == L"world";
}

static int64_t NeteaseTrackStartFallback(
    int64_t previousPositionMs, int64_t unobservedGapMs,
    int64_t previousDurationMs, bool previousWasPlaying,
    bool currentIsPlaying, int64_t skipHintAgeMs) {
    if (!currentIsPlaying) return 0;
    if (skipHintAgeMs >= 0) return skipHintAgeMs;
    if (!previousWasPlaying || previousDurationMs <= 0) return 0;
    return std::max<int64_t>(
        0, previousPositionMs + unobservedGapMs - previousDurationMs);
}

static bool NeteaseClockSelfTest() {
    bool natural = NeteaseTrackStartFallback(
                       265000, 7192, 267192, true, true, -1) == 5000;
    bool skipped = NeteaseTrackStartFallback(
                       120000, 350, 267192, true, true, 5000) == 5000;
    bool paused = NeteaseTrackStartFallback(
                      265000, 7192, 267192, true, false, -1) == 0;
    auto ratio = NeteaseProgressRatioFromGeometry(296, 1057);
    int64_t geometryPosition = ratio
        ? NeteasePositionFromProgressRatio(*ratio, 267192)
        : -1;
    bool geometry = geometryPosition >= 74823 && geometryPosition <= 74825;
    return natural && skipped && paused && geometry;
}

static NeteaseLyricsFetchResult FetchNeteaseLyrics(
    const std::wstring& title, const std::wstring& artist,
    int64_t expectedDurationMs,
    const std::wstring& exactTwilightSongId = {}) {
    using namespace winrt::Windows::Data::Json;
    NeteaseResolvedSong resolved;
    if (g_selectedPlayer.load() == PlayerKind::TwilightEcho &&
        !exactTwilightSongId.empty()) {
        resolved.songId = exactTwilightSongId;
        resolved.durationMs = expectedDurationMs;
    } else {
        resolved = g_selectedPlayer.load() == PlayerKind::TwilightEcho
            ? ResolveNeteaseSongIdFromTwilightApi(
                  title, artist, expectedDurationMs)
            : ResolveNeteaseSongId(title, artist, expectedDurationMs);
    }
    if (resolved.songId.empty()) return {};
    std::wstring json = DownloadNeteaseLyricsJson(resolved.songId);
    if (json.empty()) {
        return {NeteaseLyricsFetchStatus::RetryableFailure, {},
                resolved.durationMs};
    }
    try {
        JsonObject root = JsonObject::Parse(winrt::hstring(json));
        if (!root.HasKey(L"lrc")) {
            return {NeteaseLyricsFetchStatus::NoLyrics, {},
                    resolved.durationMs};
        }
        JsonObject lrcObject = root.GetNamedObject(L"lrc");
        std::wstring lrc = std::wstring(lrcObject.GetNamedString(L"lyric", L""));
        if (lrc.empty()) {
            return {NeteaseLyricsFetchStatus::NoLyrics, {},
                    resolved.durationMs};
        }
        auto lines = ParseNeteaseLrc(lrc);
        if (root.HasKey(L"tlyric")) {
            JsonObject translatedObject = root.GetNamedObject(L"tlyric");
            auto translatedLines = ParseNeteaseLrc(std::wstring(
                translatedObject.GetNamedString(L"lyric", L"")));
            MergeNeteaseTranslatedLyrics(lines, translatedLines);
        }
        if (lines.empty()) {
            return {NeteaseLyricsFetchStatus::NoLyrics, {},
                    resolved.durationMs};
        }
        return {NeteaseLyricsFetchStatus::Success, std::move(lines),
                resolved.durationMs};
    } catch (...) {
        return {NeteaseLyricsFetchStatus::RetryableFailure, {},
                resolved.durationMs};
    }
}

static bool SetNeteaseCurrentLyric(
    const std::wstring& value,
    std::optional<uint64_t> expectedTwilightTrackGeneration =
        std::nullopt) {
    std::lock_guard<std::mutex> lock(g_neteaseLyricsMtx);
    if (expectedTwilightTrackGeneration &&
        *expectedTwilightTrackGeneration !=
            g_twilightTrackGeneration.load()) {
        return false;
    }
    if (g_neteaseCurrentLyric == value) return false;
    g_neteaseCurrentLyric = value;
    return true;
}

static void ClearNeteaseLyrics(bool notify) {
    bool changed = false;
    {
        std::lock_guard<std::mutex> lock(g_neteaseLyricsMtx);
        changed = !g_neteaseLyricsTrackKey.empty() ||
                  !g_neteaseLyricLines.empty() ||
                  !g_neteaseCurrentLyric.empty();
        g_neteaseLyricsTrackKey.clear();
        g_neteaseLyricLines.clear();
        g_neteaseCurrentLyric.clear();
    }
    if (changed && notify) DispatchMediaUpdate();
}

static bool ApplyTwilightBridgeSnapshot(
    const TwilightBridgeSnapshot& snapshot) {
    if (g_selectedPlayer.load() != PlayerKind::TwilightEcho ||
        !snapshot.reachable) {
        return false;
    }

    SetTwilightFavoriteEligibility(
        snapshot.hasTrack &&
        ToLowerCopy(snapshot.providerId) == L"ncm");

    TwilightAccessiblePlayback playback;
    playback.reachable = snapshot.hasTrack;
    playback.trackId = snapshot.trackId;
    playback.title = snapshot.title;
    playback.artist = snapshot.artist;
    playback.coverSource = snapshot.coverSource;
    playback.isPlaying = snapshot.hasTrack && snapshot.isPlaying;
    playback.canTogglePlay = snapshot.hasTrack;
    playback.canSkipPrevious = snapshot.hasTrack;
    playback.canSkipNext = snapshot.hasTrack;
    playback.rawPositionMs = snapshot.positionMs;
    playback.positionMs = snapshot.positionMs;
    playback.durationMs = snapshot.durationMs;
    playback.observedAtTick = GetTickCount64();
    playback.positionAdvancing = playback.isPlaying;
    playback.favoriteState =
        snapshot.favoriteAvailable && !snapshot.favoriteLoading
            ? snapshot.favoriteLiked
                  ? NeteaseLikeState::Liked
                  : NeteaseLikeState::Unliked
            : NeteaseLikeState::Unknown;

    StoreTwilightAccessiblePlayback(playback);
    bool changed = ApplyTwilightAccessibleToMedia(playback);
    SetTwilightLikeState(playback.favoriteState);

    bool lyricChanged = false;
    if (g_settings.showNeteaseLyrics && snapshot.hasTrack) {
        lyricChanged = SetNeteaseCurrentLyric(
            snapshot.currentLyric,
            g_twilightTrackGeneration.load());
    } else {
        std::lock_guard<std::mutex> lock(g_neteaseLyricsMtx);
        lyricChanged = !g_neteaseCurrentLyric.empty() ||
                       !g_neteaseLyricLines.empty();
        g_neteaseLyricsTrackKey.clear();
        g_neteaseLyricLines.clear();
        g_neteaseCurrentLyric.clear();
    }
    if (changed || lyricChanged) DispatchMediaUpdate();
    return changed || lyricChanged;
}

static int64_t ProjectTwilightPosition(
    const TwilightAccessiblePlayback& playback,
    ULONGLONG nowTick) {
    int64_t positionMs = playback.positionMs;
    if (playback.isPlaying && playback.positionAdvancing &&
        nowTick >= playback.observedAtTick) {
        constexpr ULONGLONG kProjectionGraceMs = 1000;
        positionMs += static_cast<int64_t>(std::min(
            nowTick - playback.observedAtTick, kProjectionGraceMs));
    }
    positionMs = std::max<int64_t>(0, positionMs);
    if (playback.durationMs > 0) {
        positionMs = std::min(positionMs, playback.durationMs);
    }
    return positionMs;
}

static DWORD WINAPI NeteaseLyricsThreadProc(void*) {
    winrt::init_apartment(winrt::apartment_type::multi_threaded);
    if (!NeteaseLrcParserSelfTest()) {
        Wh_Log(L"NeteaseLyricsThreadProc: lyric parser self-test failed");
    }
    if (!NeteaseClockSelfTest()) {
        Wh_Log(L"NeteaseLyricsThreadProc: clock self-test failed");
    }
    std::wstring observedKey;
    uint64_t observedTrackGeneration = 0;
    int attempts = 0;
    bool fetchComplete = false;
    auto nextAttempt = std::chrono::steady_clock::now();
    int64_t fallbackPositionMs = 0;
    auto fallbackUpdatedAt = std::chrono::steady_clock::now();
    bool fallbackWasPlaying = false;
    int64_t currentTrackDurationMs = 0;
    while (!NeteaseLyricsShouldStop()) {
        bool calibrateFromProgressBar = false;
        std::wstring title, artist, appUserModelId;
        bool isPlaying = false;
        PlayerKind selectedPlayer = g_selectedPlayer.load();

        if (selectedPlayer == PlayerKind::TwilightEcho &&
            IsTwilightBridgeAuthorityActive()) {
            if (g_neteaseLyricsStopEvent &&
                WaitForSingleObject(g_neteaseLyricsStopEvent, 200) ==
                    WAIT_OBJECT_0) {
                break;
            }
            continue;
        }

        {
            std::lock_guard<std::mutex> lock(g_mediaMtx);
            title = g_media.title;
            artist = g_media.artist;
            appUserModelId = g_media.appUserModelId;
            isPlaying = g_media.isPlaying;
        }
        GlobalSystemMediaTransportControlsSession session{nullptr};
        {
            std::lock_guard<std::mutex> lock(g_sessionMtx);
            session = g_currentSession;
        }
        TwilightAudioClock audioClock = GetTwilightAudioClock();
        TwilightSessionTrack exactTrack = GetTwilightResolvedTrack();
        bool twilightAudioActive =
            selectedPlayer == PlayerKind::TwilightEcho &&
            audioClock.valid && audioClock.started && exactTrack.valid &&
            audioClock.fingerprint == exactTrack.fingerprint &&
            title == exactTrack.title && artist == exactTrack.artist;
        int64_t accessiblePositionMs = twilightAudioActive
            ? ProjectTwilightAudioPosition(audioClock, GetTickCount64())
            : 0;
        if (twilightAudioActive) {
            isPlaying = audioClock.state == TwilightAudioState::Playing;
        }

        if (!g_settings.showNeteaseLyrics ||
            (selectedPlayer == PlayerKind::TwilightEcho
                 ? !twilightAudioActive
                 : !session) ||
            !IsSessionForPlayer(appUserModelId, selectedPlayer) ||
            title.empty()) {
            observedKey.clear();
            observedTrackGeneration = 0;
            attempts = 0;
            fetchComplete = false;
            fallbackPositionMs = 0;
            fallbackUpdatedAt = std::chrono::steady_clock::now();
            fallbackWasPlaying = false;
            currentTrackDurationMs = 0;
            g_neteaseSkipSucceededTick = 0;
            ClearNeteaseLyrics();
        } else {
            std::wstring trackKey = ToLowerCopy(appUserModelId) + L"\x1f" +
                                    title + L"\x1f" + artist;
            if (twilightAudioActive) {
                trackKey += L"\x1f" + audioClock.fingerprint;
            }
            uint64_t currentTrackGeneration =
                g_twilightTrackGeneration.load();
            ULONGLONG pendingTrackUntil =
                g_twilightPendingTrackUntilTick.load();
            bool trackTransitionPending =
                selectedPlayer == PlayerKind::TwilightEcho &&
                (g_twilightAudioIdentityPending.load() ||
                 (pendingTrackUntil && GetTickCount64() <= pendingTrackUntil));
            bool twilightGenerationChanged =
                selectedPlayer == PlayerKind::TwilightEcho &&
                currentTrackGeneration != observedTrackGeneration;
            if (trackKey != observedKey ||
                (twilightGenerationChanged && !trackTransitionPending)) {
                auto trackChangeObservedAt = std::chrono::steady_clock::now();
                int64_t unobservedGapMs = std::max<int64_t>(
                    0, std::chrono::duration_cast<std::chrono::milliseconds>(
                           trackChangeObservedAt - fallbackUpdatedAt).count());
                int64_t skipHintAgeMs = -1;
                ULONGLONG skipTick = g_neteaseSkipSucceededTick.exchange(0);
                ULONGLONG nowTick = GetTickCount64();
                if (skipTick && nowTick >= skipTick &&
                    nowTick - skipTick <= 30000) {
                    skipHintAgeMs = static_cast<int64_t>(nowTick - skipTick);
                }
                int64_t estimatedStartPositionMs = twilightAudioActive
                    ? accessiblePositionMs
                    : NeteaseTrackStartFallback(
                          fallbackPositionMs, unobservedGapMs,
                          currentTrackDurationMs, fallbackWasPlaying,
                          isPlaying, skipHintAgeMs);
                observedKey = trackKey;
                observedTrackGeneration = currentTrackGeneration;
                attempts = 0;
                fetchComplete = false;
                nextAttempt = trackChangeObservedAt +
                              std::chrono::milliseconds(300);
                fallbackPositionMs = estimatedStartPositionMs;
                fallbackUpdatedAt = trackChangeObservedAt;
                fallbackWasPlaying = isPlaying;
                currentTrackDurationMs = twilightAudioActive
                    ? (audioClock.durationMs > 0
                           ? audioClock.durationMs
                           : exactTrack.durationMs)
                    : 0;
                ClearNeteaseLyrics();
            }

            auto now = std::chrono::steady_clock::now();
            if (!fetchComplete && attempts < 3 && now >= nextAttempt &&
                !NeteaseLyricsShouldStop()) {
                int64_t durationMs = 0;
                if (twilightAudioActive) {
                    durationMs = audioClock.durationMs > 0
                        ? audioClock.durationMs
                        : exactTrack.durationMs;
                } else if (session) {
                    try {
                        auto timeline = session.GetTimelineProperties();
                        durationMs = std::chrono::duration_cast<
                            std::chrono::milliseconds>(timeline.EndTime()).count();
                    } catch (...) {}
                }
                ++attempts;
                uint64_t fetchTrackGeneration =
                    observedTrackGeneration;
                auto fetched = FetchNeteaseLyrics(
                    title, artist, durationMs,
                    twilightAudioActive ? exactTrack.songId : std::wstring{});
                if (!NeteaseLyricsShouldStop()) {
                    std::wstring currentKey;
                    {
                        std::lock_guard<std::mutex> lock(g_mediaMtx);
                        currentKey = ToLowerCopy(g_media.appUserModelId) + L"\x1f" +
                                     g_media.title + L"\x1f" + g_media.artist;
                    }
                    if (selectedPlayer == PlayerKind::TwilightEcho) {
                        auto currentClock = GetTwilightAudioClock();
                        if (currentClock.valid) {
                            currentKey += L"\x1f" +
                                          currentClock.fingerprint;
                        }
                    }
                    bool trackGenerationStillCurrent =
                        selectedPlayer != PlayerKind::TwilightEcho ||
                        fetchTrackGeneration ==
                            g_twilightTrackGeneration.load();
                    if (currentKey == observedKey &&
                        trackGenerationStillCurrent) {
                        if (fetched.durationMs > 0) {
                            calibrateFromProgressBar =
                                currentTrackDurationMs <= 0;
                            currentTrackDurationMs = fetched.durationMs;
                        }
                        if (fetched.status == NeteaseLyricsFetchStatus::Success) {
                            bool lyricsCommitted = false;
                            {
                                std::lock_guard<std::mutex> lock(g_neteaseLyricsMtx);
                                if (selectedPlayer !=
                                        PlayerKind::TwilightEcho ||
                                    fetchTrackGeneration ==
                                        g_twilightTrackGeneration.load()) {
                                    g_neteaseLyricsTrackKey = observedKey;
                                    g_neteaseLyricLines =
                                        std::move(fetched.lines);
                                    g_neteaseCurrentLyric.clear();
                                    lyricsCommitted = true;
                                }
                            }
                            if (lyricsCommitted) {
                                fetchComplete = true;
                                DispatchMediaUpdate();
                            }
                        } else if (fetched.status == NeteaseLyricsFetchStatus::NoLyrics) {
                            fetchComplete = true;
                        } else if (attempts >= 3) {
                            fetchComplete = true;
                        } else {
                            nextAttempt = std::chrono::steady_clock::now() +
                                          std::chrono::seconds(2);
                        }
                    }
                }
            }

            if (twilightAudioActive) {
                auto latestClock = GetTwilightAudioClock();
                if (latestClock.valid && latestClock.started &&
                    latestClock.fingerprint == audioClock.fingerprint) {
                    audioClock = std::move(latestClock);
                    accessiblePositionMs = ProjectTwilightAudioPosition(
                        audioClock, GetTickCount64());
                    isPlaying =
                        audioClock.state == TwilightAudioState::Playing;
                }
            } else if (session) {
                std::lock_guard<std::mutex> lock(g_mediaMtx);
                if (g_media.appUserModelId == appUserModelId &&
                    g_media.title == title &&
                    g_media.artist == artist) {
                    isPlaying = g_media.isPlaying;
                }
            }

            auto progressNow = std::chrono::steady_clock::now();
            int64_t elapsedSinceUpdateMs = std::max<int64_t>(
                0, std::chrono::duration_cast<std::chrono::milliseconds>(
                       progressNow - fallbackUpdatedAt).count());
            bool calibrated = false;
            if (twilightAudioActive) {
                fallbackPositionMs = accessiblePositionMs;
                fallbackUpdatedAt = progressNow;
                fallbackWasPlaying = isPlaying;
                if (audioClock.durationMs > 0) {
                    currentTrackDurationMs = audioClock.durationMs;
                }
                calibrated = true;
            } else if (selectedPlayer == PlayerKind::Netease &&
                currentTrackDurationMs > 0 &&
                (calibrateFromProgressBar || elapsedSinceUpdateMs > 1500 ||
                 fallbackWasPlaying != isPlaying)) {
                if (auto ratio = QueryNeteaseProgressRatio()) {
                    fallbackPositionMs = NeteasePositionFromProgressRatio(
                        *ratio, currentTrackDurationMs);
                    fallbackUpdatedAt = std::chrono::steady_clock::now();
                    fallbackWasPlaying = isPlaying;
                    calibrated = true;
                }
            }
            if (!calibrated) {
                if (fallbackWasPlaying) {
                    fallbackPositionMs += elapsedSinceUpdateMs;
                }
                fallbackUpdatedAt = progressNow;
                fallbackWasPlaying = isPlaying;
            }

            std::vector<NeteaseLyricLine> lines;
            {
                std::lock_guard<std::mutex> lock(g_neteaseLyricsMtx);
                if (g_neteaseLyricsTrackKey == observedKey) lines = g_neteaseLyricLines;
            }
            if (!lines.empty()) {
                int64_t positionMs = fallbackPositionMs;
                if (!calibrated && session &&
                    selectedPlayer == PlayerKind::Netease) {
                    try {
                        auto timeline = session.GetTimelineProperties();
                    auto position = timeline.Position();
                    auto endTime = timeline.EndTime();
                    auto positionFromTimeline =
                        std::chrono::duration_cast<std::chrono::milliseconds>(position).count();
                    auto endTimeMs =
                        std::chrono::duration_cast<std::chrono::milliseconds>(endTime).count();
                    bool timelineValid = positionFromTimeline >= 0 && endTimeMs > 0 &&
                                         positionFromTimeline <= endTimeMs;
                    if (isPlaying) {
                        auto elapsed = winrt::clock::now() - timeline.LastUpdatedTime();
                        if (elapsed >= elapsed.zero() && elapsed < std::chrono::hours(1)) {
                            position += elapsed;
                        } else {
                            timelineValid = false;
                        }
                    }
                    if (timelineValid) {
                        auto projectedPositionMs =
                            std::chrono::duration_cast<std::chrono::milliseconds>(
                                position).count();
                        if (projectedPositionMs < 0 ||
                            projectedPositionMs > endTimeMs) {
                            timelineValid = false;
                        }
                    }
                        if (timelineValid) {
                            positionMs = std::chrono::duration_cast<std::chrono::milliseconds>(
                                             position).count();
                            fallbackPositionMs = positionMs;
                            fallbackUpdatedAt = std::chrono::steady_clock::now();
                            fallbackWasPlaying = isPlaying;
                        }
                    } catch (...) {}
                }
                bool playbackStateStillCurrent = true;
                bool trackGenerationStillCurrent =
                    selectedPlayer != PlayerKind::TwilightEcho ||
                    observedTrackGeneration ==
                        g_twilightTrackGeneration.load();
                if (twilightAudioActive) {
                    auto latestClock = GetTwilightAudioClock();
                    playbackStateStillCurrent =
                        latestClock.valid && latestClock.started &&
                        latestClock.fingerprint == audioClock.fingerprint &&
                        latestClock.state == audioClock.state;
                } else if (session) {
                    std::lock_guard<std::mutex> lock(g_mediaMtx);
                    playbackStateStillCurrent =
                        g_media.appUserModelId == appUserModelId &&
                        g_media.title == title &&
                        g_media.artist == artist &&
                        g_media.isPlaying == isPlaying;
                }
                if (playbackStateStillCurrent &&
                    trackGenerationStillCurrent) {
                    auto upper = std::upper_bound(
                        lines.begin(), lines.end(), positionMs,
                        [](int64_t value, const NeteaseLyricLine& line) {
                            return value < line.timeMs;
                        });
                    std::wstring currentLine;
                    if (upper != lines.begin()) {
                        currentLine = std::prev(upper)->text;
                    }
                    std::optional<uint64_t> expectedTrackGeneration =
                        selectedPlayer == PlayerKind::TwilightEcho
                            ? std::optional<uint64_t>(
                                  observedTrackGeneration)
                            : std::nullopt;
                    if (SetNeteaseCurrentLyric(
                            currentLine, expectedTrackGeneration)) {
                        DispatchMediaUpdate();
                    }
                }
            }
        }
        if (g_neteaseLyricsStopEvent &&
            WaitForSingleObject(g_neteaseLyricsStopEvent, 350) == WAIT_OBJECT_0) {
            break;
        }
    }
    winrt::uninit_apartment();
    return 0;
}

static void StartNeteaseLyricsThread() {
    if (g_neteaseLyricsThread) return;
    g_neteaseLyricsStopEvent = CreateEventW(nullptr, TRUE, FALSE, nullptr);
    if (!g_neteaseLyricsStopEvent) return;
    g_neteaseLyricsThread =
        CreateThread(nullptr, 0, NeteaseLyricsThreadProc, nullptr, 0, nullptr);
    if (!g_neteaseLyricsThread) {
        CloseHandle(g_neteaseLyricsStopEvent);
        g_neteaseLyricsStopEvent = nullptr;
    }
}

static void StopNeteaseLyricsThread() {
    if (g_neteaseLyricsStopEvent) SetEvent(g_neteaseLyricsStopEvent);
    if (g_neteaseLyricsThread) {
        WaitForSingleObject(g_neteaseLyricsThread, INFINITE);
        CloseHandle(g_neteaseLyricsThread);
        g_neteaseLyricsThread = nullptr;
    }
    if (g_neteaseLyricsStopEvent) {
        CloseHandle(g_neteaseLyricsStopEvent);
        g_neteaseLyricsStopEvent = nullptr;
    }
    ClearNeteaseLyrics();
}

static void SwitchSelectedPlayer() {
    PlayerKind next = g_selectedPlayer.load() == PlayerKind::Netease
        ? PlayerKind::TwilightEcho
        : PlayerKind::Netease;
    g_selectedPlayer = next;
    Wh_SetIntValue(kSelectedPlayerValueName, static_cast<int>(next));
    g_taskbarExpanded = false;
    g_taskbarDetailsRevealPending = false;
    g_albumLeftClickGeneration.fetch_add(1);
    SetTwilightFavoriteEligibility(false);
    SetTwilightLikeState(NeteaseLikeState::Unknown);
    g_twilightLikeForcePollAfterTick = 0;
    g_twilightNextPollTick = 0;
    g_twilightPlaybackCommandGeneration.fetch_add(1);
    g_twilightPendingPlaybackState = -1;
    g_twilightPendingPlaybackUntilTick = 0;
    g_twilightTrackGeneration.fetch_add(1);
    g_twilightPendingTrackUntilTick = 0;
    g_twilightCoverGeneration.fetch_add(1);
    g_twilightAccessibleHost = nullptr;
    g_twilightProcessDetected = false;
    g_twilightAccessibleLastSuccessTick = 0;
    {
        std::lock_guard<std::mutex> lock(g_twilightAccessiblePlaybackMtx);
        g_twilightPendingOldTrackKey.clear();
    }
    ResetTwilightAudioState();
    StoreTwilightAccessiblePlayback({});
    ClearNeteaseLyrics();
    {
        std::lock_guard<std::mutex> lock(g_sessionMtx);
        g_userSwitchedSession = false;
    }
    g_forceSessionRefresh = true;
    OnSessionsChanged();
    DispatchMediaUpdate();
}

static std::wstring GetWindowAppUserModelId(HWND hWnd) {
    static const PROPERTYKEY kAppUserModelIdKey = {
        {0x9F4C2855, 0x9F79, 0x4B39, {0xA8, 0xD0, 0xE1, 0xD4, 0x2D, 0xE1, 0xD5, 0xF3}},
        5
    };
    std::wstring result;
    IPropertyStore* store = nullptr;
    if (SUCCEEDED(SHGetPropertyStoreForWindow(hWnd, IID_PPV_ARGS(&store))) && store) {
        PROPVARIANT pv;
        PropVariantInit(&pv);
        if (SUCCEEDED(store->GetValue(kAppUserModelIdKey, &pv)) && pv.vt == VT_LPWSTR && pv.pwszVal) {
            result = pv.pwszVal;
        }
        PropVariantClear(&pv);
        store->Release();
    }
    return result;
}
static bool AppIdMatchesProcess(const std::wstring& appUserModelId, HWND hWnd, DWORD* outPid = nullptr, std::wstring* outProcPath = nullptr) {
    DWORD pid = 0;
    GetWindowThreadProcessId(hWnd, &pid);
    if (outPid) *outPid = pid;
    if (!pid) return false;
    std::wstring windowAumid = GetWindowAppUserModelId(hWnd);
    std::wstring appLower = ToLowerCopy(appUserModelId);
    std::wstring windowAumidLower = ToLowerCopy(windowAumid);
    if (!windowAumidLower.empty() &&
        (appLower == windowAumidLower ||
        appLower.find(windowAumidLower) != std::wstring::npos ||
        windowAumidLower.find(appLower) != std::wstring::npos)) {
        return true;
    }
    wchar_t procPath[MAX_PATH] = {};
    HANDLE hProc = OpenProcess(PROCESS_QUERY_LIMITED_INFORMATION, FALSE, pid);
    if (hProc) {
        DWORD sz = MAX_PATH;
        QueryFullProcessImageNameW(hProc, 0, procPath, &sz);
        CloseHandle(hProc);
    }
    if (outProcPath) *outProcPath = procPath;
    std::wstring procLower = ToLowerCopy(PathFileStem(procPath));
    if (procLower.empty()) return false;
    std::wstring appStemLower = ToLowerCopy(PathFileStem(appUserModelId));
    return appLower.find(procLower) != std::wstring::npos ||
        procLower.find(appLower) != std::wstring::npos ||
        appStemLower.find(procLower) != std::wstring::npos ||
        procLower.find(appStemLower) != std::wstring::npos ||
        (!windowAumidLower.empty() &&
            (windowAumidLower.find(procLower) != std::wstring::npos ||
            procLower.find(windowAumidLower) != std::wstring::npos));
}
static std::vector<BYTE> RenderIconToBytes(HICON hIcon, int iconSize) {
    if (!hIcon || iconSize <= 0) return {};
    ICONINFO ii{};
    if (!GetIconInfo(hIcon, &ii)) return {};
    BITMAP bm{};
    GetObjectW(ii.hbmColor ? ii.hbmColor : ii.hbmMask, sizeof(bm), &bm);
    if (ii.hbmColor) DeleteObject(ii.hbmColor);
    if (ii.hbmMask)  DeleteObject(ii.hbmMask);
    int srcW = bm.bmWidth  > 0 ? bm.bmWidth  : iconSize;
    int srcH = bm.bmHeight > 0 ? bm.bmHeight : iconSize;
    HDC screenDC = GetDC(nullptr);
    HDC hdc      = CreateCompatibleDC(screenDC);
    HBITMAP hBmp = CreateCompatibleBitmap(screenDC, srcW, srcH);
    ReleaseDC(nullptr, screenDC);
    HBITMAP hOld = (HBITMAP)SelectObject(hdc, hBmp);
    RECT rc{ 0, 0, srcW, srcH };
    HBRUSH hBr = (HBRUSH)GetStockObject(BLACK_BRUSH);
    FillRect(hdc, &rc, hBr);
    DrawIconEx(hdc, 0, 0, hIcon, srcW, srcH, 0, nullptr, DI_NORMAL);
    BITMAPINFO bi{};
    bi.bmiHeader.biSize        = sizeof(BITMAPINFOHEADER);
    bi.bmiHeader.biWidth       = srcW;
    bi.bmiHeader.biHeight      = -srcH;
    bi.bmiHeader.biPlanes      = 1;
    bi.bmiHeader.biBitCount    = 32;
    bi.bmiHeader.biCompression = BI_RGB;
    std::vector<BYTE> src(srcW * srcH * 4, 0);
    GetDIBits(hdc, hBmp, 0, srcH, src.data(), &bi, DIB_RGB_COLORS);
    SelectObject(hdc, hOld);
    DeleteObject(hBmp);
    DeleteDC(hdc);
    for (int i = 0; i + 3 < (int)src.size(); i += 4)
        std::swap(src[i], src[i + 2]);
    if (srcW == iconSize && srcH == iconSize)
        return src;
    std::vector<BYTE> dst(iconSize * iconSize * 4, 0);
    float scaleX = (float)srcW / iconSize;
    float scaleY = (float)srcH / iconSize;
    for (int dy = 0; dy < iconSize; ++dy) {
        for (int dx = 0; dx < iconSize; ++dx) {
            float fx = (dx + 0.5f) * scaleX - 0.5f;
            float fy = (dy + 0.5f) * scaleY - 0.5f;
            int x0 = (int)fx; int y0 = (int)fy;
            int x1 = x0 + 1;  int y1 = y0 + 1;
            x0 = x0 < 0 ? 0 : (x0 > srcW - 1 ? srcW - 1 : x0);
            y0 = y0 < 0 ? 0 : (y0 > srcH - 1 ? srcH - 1 : y0);
            x1 = x1 < 0 ? 0 : (x1 > srcW - 1 ? srcW - 1 : x1);
            y1 = y1 < 0 ? 0 : (y1 > srcH - 1 ? srcH - 1 : y1);
            float wx = fx - (int)fx; float wy = fy - (int)fy;
            int di = (dy * iconSize + dx) * 4;
            for (int c = 0; c < 4; ++c) {
                float v = src[(y0 * srcW + x0) * 4 + c] * (1-wx)*(1-wy)
                        + src[(y0 * srcW + x1) * 4 + c] * wx    *(1-wy)
                        + src[(y1 * srcW + x0) * 4 + c] * (1-wx)* wy
                        + src[(y1 * srcW + x1) * 4 + c] * wx    * wy;
                dst[di + c] = (BYTE)(v + 0.5f);
            }
        }
    }
    return dst;
}
static std::vector<BYTE> FetchLauncherIconBytes(const wchar_t* executablePath,
                                                int iconSize) {
    SHFILEINFOW sfi{};
    if (SHGetFileInfoW(executablePath, 0, &sfi, sizeof(sfi),
                      SHGFI_ICON | SHGFI_LARGEICON) &&
        sfi.hIcon) {
        auto bytes = RenderIconToBytes(sfi.hIcon, iconSize);
        DestroyIcon(sfi.hIcon);
        if (!bytes.empty()) return bytes;
    }

    HICON largeIcon = nullptr;
    HICON smallIcon = nullptr;
    if (ExtractIconExW(executablePath, 0, &largeIcon, &smallIcon, 1) > 0) {
        auto bytes = RenderIconToBytes(largeIcon ? largeIcon : smallIcon, iconSize);
        if (largeIcon) DestroyIcon(largeIcon);
        if (smallIcon && smallIcon != largeIcon) DestroyIcon(smallIcon);
        return bytes;
    }
    return {};
}
static std::vector<BYTE> FetchAppIconBytes(const std::wstring& appUserModelId, int iconSize) {
    std::vector<BYTE> result;
    if (appUserModelId.empty()) return result;
    auto Render = [&](HICON h, bool own) -> bool {
        if (!h) return false;
        result = RenderIconToBytes(h, iconSize);
        if (own) DestroyIcon(h);
        return !result.empty();
    };
    {
        std::wstring shellPath = L"shell:AppsFolder\\" + appUserModelId;
        PIDLIST_ABSOLUTE pidl = nullptr;
        if (SUCCEEDED(SHParseDisplayName(shellPath.c_str(), nullptr, &pidl, 0, nullptr)) && pidl) {
            SHFILEINFOW sfi{};
            DWORD flags = SHGFI_PIDL | SHGFI_ICON | SHGFI_LARGEICON;
            if (SHGetFileInfoW(reinterpret_cast<LPCWSTR>(pidl), 0, &sfi, sizeof(sfi), flags) && sfi.hIcon) {
                CoTaskMemFree(pidl);
                if (Render(sfi.hIcon, true)) return result;
            } else {
                CoTaskMemFree(pidl);
            }
        }
    }
    {
        struct EnumCtx {
            const std::wstring* aumid;
            HICON  exactIcon = nullptr;
            HICON  fuzzyIcon = nullptr;
            DWORD  exactPid  = 0;
            DWORD  fuzzyPid  = 0;
            std::wstring exactPath;
            std::wstring fuzzyPath;
        };
        EnumCtx ctx{ &appUserModelId };
        EnumWindows([](HWND hWnd, LPARAM lParam) CALLBACK -> BOOL {
            if (!IsWindowVisible(hWnd)) return TRUE;
            auto* c = reinterpret_cast<EnumCtx*>(lParam);
            if (!c->exactIcon) {
                IPropertyStore* pps = nullptr;
                if (SUCCEEDED(SHGetPropertyStoreForWindow(hWnd, IID_PPV_ARGS(&pps)))) {
                    PROPVARIANT var;
                    PropVariantInit(&var);
                    if (SUCCEEDED(pps->GetValue(PKEY_AppUserModel_ID, &var)) && var.vt == VT_LPWSTR) {
                        std::wstring winAumid  = ToLowerCopy(std::wstring(var.pwszVal));
                        std::wstring wantAumid = ToLowerCopy(*c->aumid);
                        if (winAumid == wantAumid) {
                            auto getIconTimeout = [&](HWND w, WPARAM iconType) -> HICON {
                                DWORD_PTR res = 0;
                                if (SendMessageTimeoutW(w, WM_GETICON, iconType, 0,
                                        SMTO_ABORTIFHUNG | SMTO_BLOCK, 100, &res)) {
                                    return (HICON)res;
                                }
                                return nullptr;
                            };
                            HICON icon = getIconTimeout(hWnd, ICON_BIG);
                            if (!icon) icon = getIconTimeout(hWnd, ICON_SMALL);
                            if (!icon) icon = (HICON)GetClassLongPtrW(hWnd, GCLP_HICON);
                            if (!icon) icon = (HICON)GetClassLongPtrW(hWnd, GCLP_HICONSM);
                            if (icon) {
                                c->exactIcon = icon;
                                GetWindowThreadProcessId(hWnd, &c->exactPid);
                                wchar_t path[MAX_PATH]{};
                                HANDLE hProc = OpenProcess(PROCESS_QUERY_LIMITED_INFORMATION, FALSE, c->exactPid);
                                if (hProc) { DWORD sz = MAX_PATH; QueryFullProcessImageNameW(hProc, 0, path, &sz); CloseHandle(hProc); }
                                c->exactPath = path;
                                PropVariantClear(&var);
                                pps->Release();
                                return FALSE;
                            }
                        }
                    }
                    PropVariantClear(&var);
                    pps->Release();
                }
            }
            if (!c->exactIcon && !c->fuzzyIcon) {
                std::wstring windowAumid = GetWindowAppUserModelId(hWnd);
                if (windowAumid.empty()) {
                    DWORD pid = 0;
                    std::wstring procPath;
                    if (AppIdMatchesProcess(*c->aumid, hWnd, &pid, &procPath)) {
                        auto getIconTimeout = [&](HWND w, WPARAM iconType) -> HICON {
                            DWORD_PTR res = 0;
                            if (SendMessageTimeoutW(w, WM_GETICON, iconType, 0,
                                    SMTO_ABORTIFHUNG | SMTO_BLOCK, 100, &res)) {
                                return (HICON)res;
                            }
                            return nullptr;
                        };
                        HICON icon = getIconTimeout(hWnd, ICON_BIG);
                        if (!icon) icon = getIconTimeout(hWnd, ICON_SMALL);
                        if (!icon) icon = (HICON)GetClassLongPtrW(hWnd, GCLP_HICON);
                        if (!icon) icon = (HICON)GetClassLongPtrW(hWnd, GCLP_HICONSM);
                        if (icon) {
                            c->fuzzyIcon = icon;
                            c->fuzzyPid  = pid;
                            c->fuzzyPath = procPath;
                        } else if (!c->fuzzyPid) {
                            c->fuzzyPid  = pid;
                            c->fuzzyPath = procPath;
                        }
                    }
                }
            }
            return TRUE;
        }, reinterpret_cast<LPARAM>(&ctx));
        if (ctx.exactIcon && Render(ctx.exactIcon, false)) return result;
        if (ctx.fuzzyIcon) {
            HANDLE hProc = OpenProcess(PROCESS_QUERY_LIMITED_INFORMATION, FALSE, ctx.fuzzyPid);
            if (hProc) {
                DWORD exitCode = 0;
                if (GetExitCodeProcess(hProc, &exitCode) && exitCode == STILL_ACTIVE) {
                    CloseHandle(hProc);
                    if (Render(ctx.fuzzyIcon, false)) return result;
                } else {
                    CloseHandle(hProc);
                }
            }
        }
        auto resolvePid = [](DWORD pid) -> std::wstring {
            if (!pid) return {};
            wchar_t path[MAX_PATH]{};
            HANDLE hProc = OpenProcess(PROCESS_QUERY_LIMITED_INFORMATION, FALSE, pid);
            if (hProc) { DWORD sz = MAX_PATH; QueryFullProcessImageNameW(hProc, 0, path, &sz); CloseHandle(hProc); }
            return path;
        };
        auto tryExePath = [&](const std::wstring& path) -> bool {
            if (path.empty()) return false;
            SHFILEINFOW sfi{};
            if (SHGetFileInfoW(path.c_str(), 0, &sfi, sizeof(sfi), SHGFI_ICON | SHGFI_LARGEICON) && sfi.hIcon)
                return Render(sfi.hIcon, true);
            if (SHGetFileInfoW(path.c_str(), 0, &sfi, sizeof(sfi), SHGFI_ICON | SHGFI_SMALLICON) && sfi.hIcon)
                return Render(sfi.hIcon, true);
            return false;
        };
        auto tryExtractIconEx = [&](const std::wstring& path) -> bool {
            if (path.empty()) return false;
            HICON hL = nullptr, hS = nullptr;
            if (ExtractIconExW(path.c_str(), 0, &hL, &hS, 1)) {
                HICON chosen = hL ? hL : hS;
                if (chosen) {
                    bool ok = Render(chosen, false);
                    if (hL) DestroyIcon(hL);
                    if (hS) DestroyIcon(hS);
                    if (ok) return true;
                }
            }
            return false;
        };
        std::wstring ep = ctx.exactPath.empty() ? resolvePid(ctx.exactPid) : ctx.exactPath;
        std::wstring fp = ctx.fuzzyPath.empty() ? resolvePid(ctx.fuzzyPid) : ctx.fuzzyPath;
        if (tryExePath(ep))        return result;
        if (tryExePath(fp))        return result;
        if (tryExtractIconEx(ep))  return result;
        if (tryExtractIconEx(fp))  return result;
    }
    if (appUserModelId.find(L".exe") != std::wstring::npos) {
        std::wstring exePath = appUserModelId;
        if (exePath.size() >= 2 && exePath.front() == L'"' && exePath.back() == L'"')
            exePath = exePath.substr(1, exePath.size() - 2);
        SHFILEINFOW sfi{};
        if (SHGetFileInfoW(exePath.c_str(), 0, &sfi, sizeof(sfi), SHGFI_ICON | SHGFI_LARGEICON) && sfi.hIcon)
            if (Render(sfi.hIcon, true)) return result;
        HICON hL = nullptr, hS = nullptr;
        if (ExtractIconExW(exePath.c_str(), 0, &hL, &hS, 1)) {
            HICON chosen = hL ? hL : hS;
            if (chosen) {
                Render(chosen, false);
                if (hL) DestroyIcon(hL);
                if (hS) DestroyIcon(hS);
                if (!result.empty()) return result;
            }
        }
    }
    return result;
}
static bool IsCapturedSessionStillSelected(
    const GlobalSystemMediaTransportControlsSession& session,
    const std::wstring& appUserModelId) {
    if (!session ||
        !IsSessionForPlayer(appUserModelId, g_selectedPlayer.load())) {
        return false;
    }
    std::lock_guard<std::mutex> lock(g_sessionMtx);
    return g_currentSession && g_currentSession == session;
}
static void FetchMediaPropertiesAsync() {
    SpawnTrackedWorker([]() {
        if (g_unloading) return;
        winrt::init_apartment(winrt::apartment_type::multi_threaded);
        try {
            GlobalSystemMediaTransportControlsSession session{nullptr};
            std::wstring aumid;
            {
                std::lock_guard<std::mutex> lk(g_sessionMtx);
                session = g_currentSession;
            }
            if (!session) {
                winrt::uninit_apartment();
                return;
            }
            try {
                aumid = std::wstring(session.SourceAppUserModelId());
            } catch (...) {
                winrt::uninit_apartment();
                return;
            }
            bool isTwilightMetadata = IsTwilightSession(aumid);
            uint64_t twilightMetadataTrackGeneration =
                g_twilightTrackGeneration.load();
            try {
                auto props = session.TryGetMediaPropertiesAsync().get();
                if (!props) {
                    winrt::uninit_apartment();
                    return;
                }
                if (!IsCapturedSessionStillSelected(session, aumid)) {
                    winrt::uninit_apartment();
                    return;
                }
                TwilightAccessiblePlayback twilightCanonical =
                    isTwilightMetadata
                        ? GetTwilightAccessiblePlayback()
                        : TwilightAccessiblePlayback{};
                bool bridgeOwnsTwilightCover =
                    isTwilightMetadata &&
                    IsTwilightBridgeAuthorityActive() &&
                    !twilightCanonical.trackId.empty() &&
                    !twilightCanonical.coverSource.empty();
                std::wstring metadataTitle = std::wstring(props.Title());
                std::wstring metadataArtist = std::wstring(props.Artist());
                bool twilightTrackTransitionPending = false;
                if (isTwilightMetadata) {
                    ULONGLONG pendingUntil =
                        g_twilightPendingTrackUntilTick.load();
                    if (pendingUntil && GetTickCount64() <= pendingUntil) {
                        std::wstring pendingOldTrackKey;
                        {
                            std::lock_guard<std::mutex> lock(
                                g_twilightAccessiblePlaybackMtx);
                            pendingOldTrackKey =
                                g_twilightPendingOldTrackKey;
                        }
                        twilightTrackTransitionPending =
                            TwilightTrackKey(twilightCanonical) ==
                            pendingOldTrackKey;
                    }
                }
                bool twilightMetadataMatchesCanonical =
                    isTwilightMetadata &&
                    !twilightTrackTransitionPending &&
                    twilightCanonical.reachable &&
                    NormalizeNeteaseMatchText(metadataTitle) ==
                        NormalizeNeteaseMatchText(twilightCanonical.title) &&
                    NormalizeNeteaseArtistText(metadataArtist) ==
                        NormalizeNeteaseArtistText(twilightCanonical.artist);
                std::vector<BYTE> thumbBytes;
                uint64_t          thumbHash = 0;
                uint64_t          thumbStreamSize = 0;
                if (auto thumbRef = props.Thumbnail()) {
                    try {
                        auto stream = thumbRef.OpenReadAsync().get();
                        if (stream) {
                            UINT64 sz = stream.Size();
                            thumbStreamSize = sz;
                            if (sz > 0 && sz < 4 * 1024 * 1024) {
                                DataReader reader(stream);
                                reader.LoadAsync((UINT32)sz).get();
                                thumbBytes.resize((size_t)sz);
                                reader.ReadBytes(winrt::array_view<BYTE>(thumbBytes));
                                reader.DetachStream();
                                for (size_t i = 0; i < thumbBytes.size(); i += 1024)
                                    thumbHash = thumbHash * 31 + thumbBytes[i];
                            }
                        }
                    } catch (...) { thumbBytes.clear(); thumbStreamSize = 0; }
                }

                {
                    bool isBrowserSession = IsBrowserAumid(aumid);
                    std::wstring titleArtistKey =
                        std::wstring(props.Title()) + L"\x1f" + std::wstring(props.Artist());
                    bool suspectMatch = false;
                    {
                        std::lock_guard<std::mutex> lk(g_mediaMtx);
                        bool     trackChanged = (titleArtistKey != g_lastTitleArtistKey);
                        uint64_t prevArtSize  = g_media.thumbnailStreamSize;
                        uint64_t prevArtHash  = g_media.thumbnailHash;
                        g_lastTitleArtistKey = titleArtistKey;

                        if (g_artNewBrowserSession) {
                            if (thumbStreamSize > 0) {
                                g_suspectArtSize  = thumbStreamSize;
                                g_suspectArtHash  = thumbHash;
                                g_artDelayPending = true;
                                suspectMatch      = true;
                            }
                            g_artNewBrowserSession = false;
                        } else if (trackChanged) {
                            g_suspectArtSize  = isBrowserSession ? prevArtSize : 0;
                            g_suspectArtHash  = isBrowserSession ? prevArtHash : 0;
                            g_artDelayPending = isBrowserSession && prevArtSize > 0;
                        }

                        if (!suspectMatch && g_artDelayPending && isBrowserSession) {
                            bool matchesSuspect = thumbStreamSize > 0 &&
                                                  thumbStreamSize == g_suspectArtSize &&
                                                  (g_suspectArtHash == 0 || thumbHash == g_suspectArtHash);
                            if (matchesSuspect) {
                                suspectMatch = true;
                            } else {
                                g_artDelayPending = false;
                            }
                        }

                        if (!suspectMatch && isBrowserSession &&
                            thumbStreamSize == 0 && prevArtSize > 0) {
                            suspectMatch = true;
                        }
                    }
                    if (suspectMatch) {
                        thumbBytes.clear();
                        thumbHash = 0;
                        thumbStreamSize = 0;
                    }
                }
                std::vector<BYTE> appIconBytes;
                std::wstring      appIconKey;
                if (isTwilightMetadata &&
                    (!twilightMetadataMatchesCanonical ||
                     bridgeOwnsTwilightCover)) {
                    thumbBytes.clear();
                    thumbHash = 0;
                    thumbStreamSize = 0;
                }
                if (isTwilightMetadata &&
                    IsTwilightBridgeAuthorityActive()) {
                    auto latestCanonical = GetTwilightAccessiblePlayback();
                    bridgeOwnsTwilightCover =
                        latestCanonical.reachable &&
                        !latestCanonical.trackId.empty() &&
                        !latestCanonical.coverSource.empty();
                    if (bridgeOwnsTwilightCover) {
                        thumbBytes.clear();
                        thumbHash = 0;
                        thumbStreamSize = 0;
                    }
                }
                bool forceIconRefresh = false;
                {
                    std::lock_guard<std::mutex> lk(g_mediaMtx);
                    appIconKey = g_media.appIconKey;
                    appIconBytes = g_media.appIconBytes;
                }
                {
                    std::lock_guard<std::mutex> lk(g_sessionMtx);
                    forceIconRefresh = g_userSwitchedSession;
                }
                if (g_settings.showAppIcon && (aumid != appIconKey || appIconBytes.empty() || forceIconRefresh || g_cachedAppIconSize != g_settings.appIconSize)) {
                    try {
                        appIconBytes = FetchAppIconBytes(aumid, g_settings.appIconSize);
                        appIconKey   = aumid;
                        g_cachedAppIconSize = g_settings.appIconSize;
                    } catch (...) {
                    }
                }
                if (isTwilightMetadata &&
                    IsTwilightBridgeAuthorityActive()) {
                    auto latestCanonical = GetTwilightAccessiblePlayback();
                    bridgeOwnsTwilightCover =
                        latestCanonical.reachable &&
                        !latestCanonical.trackId.empty() &&
                        !latestCanonical.coverSource.empty();
                }
                bool committed = false;
                {
                    std::lock_guard<std::mutex> sessionLock(g_sessionMtx);
                    if (g_currentSession && g_currentSession == session &&
                        IsSessionForPlayer(aumid, g_selectedPlayer.load())) {
                        std::lock_guard<std::mutex> mediaLock(g_mediaMtx);
                        try {
                            if (!isTwilightMetadata) {
                                g_media.title = metadataTitle;
                                g_media.artist = metadataArtist;
                                g_media.hasMedia =
                                    !g_media.title.empty() ||
                                    !g_media.artist.empty();
                                g_media.thumbnailBytes = std::move(thumbBytes);
                                g_media.thumbnailHash  = thumbHash;
                                g_media.thumbnailStreamSize = thumbStreamSize;
                                g_media.appUserModelId = aumid;
                            } else {
                                bool canonicalStillCurrent =
                                    twilightCanonical.reachable &&
                                    twilightMetadataTrackGeneration ==
                                        g_twilightTrackGeneration.load() &&
                                    g_media.appUserModelId == kTwilightAumid &&
                                    g_media.title == twilightCanonical.title &&
                                    g_media.artist == twilightCanonical.artist;
                                if (!canonicalStillCurrent) {
                                    committed = false;
                                } else {
                                    bool bridgeOwnsCoverAtCommit =
                                        bridgeOwnsTwilightCover ||
                                        (IsTwilightBridgeAuthorityActive() &&
                                         !g_twilightAppliedTrackId.empty() &&
                                         !g_twilightAppliedCoverSource.empty());
                                    if (twilightMetadataMatchesCanonical &&
                                        !bridgeOwnsCoverAtCommit &&
                                        !thumbBytes.empty()) {
                                        g_media.thumbnailBytes =
                                            std::move(thumbBytes);
                                        g_media.thumbnailHash = thumbHash;
                                        g_media.thumbnailStreamSize =
                                            thumbStreamSize;
                                    }
                                    committed = true;
                                }
                            }
                            if (g_settings.showAppIcon) {
                                g_media.appIconBytes   = std::move(appIconBytes);
                                g_media.appIconKey     = appIconKey;
                            }
                            if (!isTwilightMetadata) committed = true;
                        } catch (...) {
                        }
                    }
                }
                if (!committed) {
                    winrt::uninit_apartment();
                    return;
                }
                if (forceIconRefresh) {
                    std::lock_guard<std::mutex> lk(g_sessionMtx);
                    if (g_currentSession && g_currentSession == session) {
                        g_userSwitchedSession = false;
                    }
                }
            } catch (...) {
            }
        } catch (...) {}
        DispatchMediaUpdate();
        winrt::uninit_apartment();
    });
}
static void FetchPlaybackInfoAsync() {
    SpawnTrackedWorker([]() {
        if (g_unloading) return;
        winrt::init_apartment(winrt::apartment_type::multi_threaded);
        try {
            uint64_t observationGeneration =
                g_twilightPlaybackCommandGeneration.load();
            uint64_t observationTrackGeneration =
                g_twilightTrackGeneration.load();
            GlobalSystemMediaTransportControlsSession session{nullptr};
            { std::lock_guard<std::mutex> lk(g_sessionMtx); session = g_currentSession; }
            if (session) {
                try {
                    std::wstring aumid;
                    try {
                        aumid = std::wstring(session.SourceAppUserModelId());
                    } catch (...) {
                        winrt::uninit_apartment();
                        return;
                    }
                    auto info = session.GetPlaybackInfo();
                    if (!info) {
                        winrt::uninit_apartment();
                        return;
                    }
                    auto status = info.PlaybackStatus();
                    bool playing = (status == GlobalSystemMediaTransportControlsSessionPlaybackStatus::Playing);
                    PlayerKind selectedPlayer = g_selectedPlayer.load();
                    bool isTwilightPlayback =
                        selectedPlayer == PlayerKind::TwilightEcho &&
                        IsTwilightSession(aumid);
                    bool observationStillCurrent =
                        observationGeneration ==
                            g_twilightPlaybackCommandGeneration.load() &&
                        observationTrackGeneration ==
                            g_twilightTrackGeneration.load();
                    if (isTwilightPlayback &&
                        (!observationStillCurrent ||
                         IsTwilightBridgeAuthorityActive())) {
                        winrt::uninit_apartment();
                        return;
                    }
                    if (isTwilightPlayback) {
                        auto accessible = GetTwilightAccessiblePlayback();
                        if (accessible.reachable) {
                            playing = accessible.isPlaying;
                        }
                    }
                    bool acceptPlaybackState = true;
                    if (isTwilightPlayback) {
                        acceptPlaybackState = observationStillCurrent;
                        int pendingPlaybackState =
                            g_twilightPendingPlaybackState.load();
                        if (acceptPlaybackState &&
                            pendingPlaybackState >= 0) {
                            ULONGLONG nowTick = GetTickCount64();
                            ULONGLONG pendingUntil =
                                g_twilightPendingPlaybackUntilTick.load();
                            if (nowTick <= pendingUntil &&
                                playing !=
                                    (pendingPlaybackState != 0)) {
                                acceptPlaybackState = false;
                            }
                        }
                    }
                    bool wasPlaying = false;
                    bool committed = false;
                    bool bridgeAuthorityAtCommit =
                        isTwilightPlayback &&
                        IsTwilightBridgeAuthorityActive();
                    {
                        std::lock_guard<std::mutex> sessionLock(g_sessionMtx);
                        if (g_currentSession && g_currentSession == session &&
                            IsSessionForPlayer(aumid, selectedPlayer) &&
                            !bridgeAuthorityAtCommit &&
                            acceptPlaybackState &&
                            (selectedPlayer != PlayerKind::TwilightEcho ||
                             (observationGeneration ==
                                  g_twilightPlaybackCommandGeneration.load() &&
                              observationTrackGeneration ==
                                  g_twilightTrackGeneration.load()))) {
                            std::lock_guard<std::mutex> mediaLock(g_mediaMtx);
                            if (!isTwilightPlayback ||
                                !IsTwilightBridgeAuthorityActive()) {
                                wasPlaying = g_media.isPlaying;
                                g_media.isPlaying = playing;
                                committed = true;
                            }
                        }
                    }
                    if (!committed) {
                        winrt::uninit_apartment();
                        return;
                    }
                    if (playing != wasPlaying) {
                        if (!playing && wasPlaying) {
                            if (!g_unloading) OnSessionsChanged();
                        }
                    }
                    try {
                        auto shuffleRef = info.IsShuffleActive();
                        if (shuffleRef) {
                            g_shuffleEnabled = shuffleRef.Value();
                        }
                    } catch (...) {}
                    try {
                        auto repeatRef = info.AutoRepeatMode();
                        if (repeatRef) {
                            using RM = winrt::Windows::Media::MediaPlaybackAutoRepeatMode;
                            auto v = repeatRef.Value();
                            if (v == RM::Track) g_repeatMode = RepeatMode::One;
                            else if (v == RM::List) g_repeatMode = RepeatMode::All;
                            else g_repeatMode = RepeatMode::Off;
                        } else {
                            g_repeatMode = RepeatMode::Off;
                        }
                    } catch (...) {
                        g_repeatMode = RepeatMode::Off;
                    }
                    try {
                        auto controls = info.Controls();
                        if (controls &&
                            selectedPlayer != PlayerKind::TwilightEcho) {
                            bool canPrev   = controls.IsPreviousEnabled();
                            bool canNext   = controls.IsNextEnabled();
                            bool canShuf   = controls.IsShuffleEnabled();
                            bool canRep    = controls.IsRepeatEnabled();
                            bool canSeek   = controls.IsPlaybackPositionEnabled();
                            std::lock_guard<std::mutex> sessionLock(g_sessionMtx);
                            if (g_currentSession && g_currentSession == session &&
                                IsSessionForPlayer(aumid,
                                                   g_selectedPlayer.load())) {
                                std::lock_guard<std::mutex> mediaLock(g_mediaMtx);
                                g_media.canSkipPrevious = canPrev;
                                g_media.canSkipNext     = canNext;
                                g_media.canShuffle      = canShuf;
                                g_media.canRepeat       = canRep;
                                g_media.canSeek         = canSeek;
                            }
                        }
                    } catch (...) {}
                } catch (...) {
                }
            }
        } catch (...) {}
        DispatchMediaUpdate();
        winrt::uninit_apartment();
    });
}
static void DetachCurrentSession() {
    std::lock_guard<std::mutex> lk(g_sessionMtx);
    if (!g_currentSession) return;
    try {
        if (g_evMediaProps.value) { g_currentSession.MediaPropertiesChanged(g_evMediaProps); g_evMediaProps = {}; }
        if (g_evPlayback.value)   { g_currentSession.PlaybackInfoChanged(g_evPlayback); g_evPlayback = {}; }
    } catch (...) {}
    g_currentSession = nullptr;
    g_repeatMode = RepeatMode::Off;
    g_shuffleEnabled = false;
    {
        std::lock_guard<std::mutex> lkm(g_mediaMtx);
        g_media.canSkipPrevious = true;
        g_media.canSkipNext     = true;
        g_media.canShuffle      = true;
        g_media.canRepeat       = true;
        g_media.canSeek         = true;
    }
}
static GlobalSystemMediaTransportControlsSession PickBestSession() {
    GlobalSystemMediaTransportControlsSessionManager mgr{nullptr};
    {
        std::lock_guard<std::mutex> lkMgr(g_sessionMtx);
        mgr = g_sessionMgr;
    }
    if (!mgr) return nullptr;
    try {
        auto sessions = mgr.GetSessions();
        int sessionCount = (int)sessions.Size();
        if (sessionCount == 0) {
            return nullptr;
        }
        using S = GlobalSystemMediaTransportControlsSessionPlaybackStatus;
        GlobalSystemMediaTransportControlsSession current{nullptr};
        bool userSwitched = false;
        {
            std::lock_guard<std::mutex> lk(g_sessionMtx);
            current      = g_currentSession;
            userSwitched = g_userSwitchedSession;
        }
        GlobalSystemMediaTransportControlsSession playingFirst{nullptr};
        GlobalSystemMediaTransportControlsSession firstValid{nullptr};
        GlobalSystemMediaTransportControlsSession selectedManagedSession{nullptr};
        constexpr bool strictManagedSelection = true;
        PlayerKind selectedPlayer = g_selectedPlayer.load();
        bool currentExists  = false;
        bool currentPlaying = false;
        for (auto const& s : sessions) {
            try {
                if (!s) continue;
                std::wstring appId = s.SourceAppUserModelId().c_str();
                bool selectedManaged = IsSessionForPlayer(appId, selectedPlayer);
                if (strictManagedSelection && !selectedManaged) continue;
                bool ignored = IsIgnoredMediaApp(appId);
                bool hasPlaybackInfo = false;
                bool isPlaying = false;
                try {
                    auto pb = s.GetPlaybackInfo();
                    if (pb) {
                        hasPlaybackInfo = true;
                        isPlaying = (pb.PlaybackStatus() == S::Playing);
                    }
                } catch (...) {}
                if (ignored || !hasPlaybackInfo) continue;
                if (!firstValid) firstValid = s;
                if (!selectedManagedSession && selectedManaged) {
                    selectedManagedSession = s;
                }
                if (s == current) {
                    currentExists  = true;
                    currentPlaying = isPlaying;
                }
                if (isPlaying && !playingFirst) {
                    playingFirst = s;
                }
            } catch (...) {}
        }
        if (strictManagedSelection) {
            return selectedManagedSession;
        }
        if (userSwitched) {
            if (currentExists) {
                return current;
            }
            { std::lock_guard<std::mutex> lk(g_sessionMtx); g_userSwitchedSession = false; }
        }
        if (!g_settings.autoSwitchSession) {
            if (currentExists) {
                return current;
            }
            return firstValid;
        }
        if (currentExists && currentPlaying) {
            return current;
        }
        if (playingFirst && playingFirst != current) {
            return playingFirst;
        }
        if (currentExists) {
            return current;
        }
        return firstValid;
    } catch (...) {
        Wh_Log(L"PickBestSession: Exception occurred");
        return nullptr;
    }
}
static void AttachToSession(GlobalSystemMediaTransportControlsSession session) {
    if (session) {
        try {
            if (!IsSessionForPlayer(
                    std::wstring(session.SourceAppUserModelId()),
                    g_selectedPlayer.load())) {
                session = nullptr;
            }
        } catch (...) {
            session = nullptr;
        }
    }
    if (!session) {
        DetachCurrentSession();
        if (g_selectedPlayer.load() == PlayerKind::TwilightEcho) {
            CommitTwilightAccessiblePlayback(
                GetTwilightAccessiblePlayback());
            return;
        }
        {
            std::lock_guard<std::mutex> lk(g_mediaMtx);
            g_media = MediaState{};
            g_lastTitleArtistKey.clear();
            g_suspectArtSize  = 0;
            g_suspectArtHash  = 0;
            g_artDelayPending = false;
            g_artNewBrowserSession = false;
        }
        DispatchMediaUpdate();
        return;
    }
    bool needsReattach = false;
    {
        std::lock_guard<std::mutex> lk(g_sessionMtx);
        if (g_currentSession == session) {
            if (!g_evMediaProps.value || !g_evPlayback.value) {
                needsReattach = true;
            } else {
                goto fetch;
            }
        }
    }
    (void)needsReattach;
    {
        std::wstring appId;
        try {
            appId = std::wstring(session.SourceAppUserModelId());
        } catch (...) {
        }
        DetachCurrentSession();
        {
            std::lock_guard<std::mutex> lk(g_mediaMtx);
            g_media.appIconKey   = L"";
            g_media.appIconBytes.clear();
            g_media.thumbnailBytes.clear();
            g_media.thumbnailHash = 0;
            g_media.thumbnailStreamSize = 0;
            g_lastTitleArtistKey.clear();
            g_suspectArtSize  = 0;
            g_suspectArtHash  = 0;
            g_artDelayPending = false;
            g_artNewBrowserSession = IsBrowserAumid(appId);
        }
    }
    g_cachedAppIconSize = -1;
    ResetScrollState(g_titleScroll);
    ResetScrollState(g_artistScroll);
    {
        std::lock_guard<std::mutex> lk(g_sessionMtx);
        g_currentSession = session;
        try {
            g_evMediaProps = g_currentSession.MediaPropertiesChanged([](auto const&, auto const&) {
                if (!g_unloading) FetchMediaPropertiesAsync();
            });
            g_evPlayback = g_currentSession.PlaybackInfoChanged([](auto const&, auto const&) {
                if (!g_unloading) FetchPlaybackInfoAsync();
            });
        } catch (...) {
            Wh_Log(L"AttachToSession: Failed to attach event handlers");
            g_currentSession = nullptr;
            return;
        }
    }
fetch:
    FetchMediaPropertiesAsync();
    FetchPlaybackInfoAsync();
}
static void OnSessionsChanged() {
    if (g_unloading) return;
    bool forceRefresh = g_forceSessionRefresh.exchange(false);
    try {
        GlobalSystemMediaTransportControlsSessionManager mgr{nullptr};
        {
            std::lock_guard<std::mutex> lk(g_sessionMtx);
            mgr = g_sessionMgr;
        }
        if (mgr) {
            auto sessions = mgr.GetSessions();
            g_sessionCount.store((int)sessions.Size());
        }
    } catch (...) {}
    if (forceRefresh) {
        std::lock_guard<std::mutex> lk(g_sessionMtx);
        g_userSwitchedSession = false;
    }
    try {
        auto newSession = PickBestSession();
        AttachToSession(newSession);
    } catch (...) {
        Wh_Log(L"OnSessionsChanged: Exception occurred");
    }
}
static DWORD WINAPI MediaThreadProc(void*) {
    try {
        winrt::init_apartment(winrt::apartment_type::multi_threaded);
        auto op = GlobalSystemMediaTransportControlsSessionManager::RequestAsync();
        while (op.Status() == winrt::Windows::Foundation::AsyncStatus::Started) {
            if (WaitForSingleObject(g_mediaStopEvent, 50) == WAIT_OBJECT_0) goto done;
        }
        {
            std::lock_guard<std::mutex> lk(g_sessionMtx);
            g_sessionMgr = op.GetResults();
        }
        g_evSessionsChanged = g_sessionMgr.SessionsChanged([](auto const&, auto const&) {
            OnSessionsChanged();
        });
        g_evCurrentChanged  = g_sessionMgr.CurrentSessionChanged([](auto const&, auto const&) {
            OnSessionsChanged();
        });
        OnSessionsChanged();
        while (WaitForSingleObject(g_mediaStopEvent, 2000) == WAIT_TIMEOUT) {
            if (g_unloading) break;
            bool hasSelectedSession = false;
            {
                std::lock_guard<std::mutex> lk(g_sessionMtx);
                if (g_currentSession) {
                    try {
                        hasSelectedSession = IsSessionForPlayer(
                            std::wstring(g_currentSession.SourceAppUserModelId()),
                            g_selectedPlayer.load());
                    } catch (...) {}
                }
            }
            if (!hasSelectedSession) {
                g_forceSessionRefresh = true;
                OnSessionsChanged();
            } else {
                FetchPlaybackInfoAsync();
            }
        }
        try { if (g_evSessionsChanged.value) g_sessionMgr.SessionsChanged(g_evSessionsChanged); } catch (...) { Wh_Log(L"MediaThreadProc: Failed to unregister SessionsChanged event"); }
        try { if (g_evCurrentChanged.value)  g_sessionMgr.CurrentSessionChanged(g_evCurrentChanged); } catch (...) { Wh_Log(L"MediaThreadProc: Failed to unregister CurrentSessionChanged event"); }
        DetachCurrentSession();
        {
            std::lock_guard<std::mutex> lk(g_sessionMtx);
            g_sessionMgr = nullptr;
        }
    done:
        winrt::uninit_apartment();
    } catch (...) {
        Wh_Log(L"MediaThreadProc: Exception in media thread");
    }
    return 0;
}
static void StartMediaThread() {
    if (g_mediaThread) return;
    g_mediaStopEvent = CreateEventW(nullptr, TRUE, FALSE, nullptr);
    if (!g_mediaStopEvent) return;
    g_mediaThread = CreateThread(nullptr, 0, MediaThreadProc, nullptr, 0, nullptr);
    if (!g_mediaThread) { CloseHandle(g_mediaStopEvent); g_mediaStopEvent = nullptr; }
}
static void StopMediaThread() {
    if (g_mediaStopEvent) SetEvent(g_mediaStopEvent);
    if (g_mediaThread) { WaitForSingleObject(g_mediaThread, 5000); CloseHandle(g_mediaThread); g_mediaThread = nullptr; }
    if (g_mediaStopEvent) { CloseHandle(g_mediaStopEvent); g_mediaStopEvent = nullptr; }
}
static HANDLE g_timerThread    = nullptr;
static HANDLE g_timerStopEvent = nullptr;
[[clang::no_destroy]] static winrt::Windows::UI::Xaml::DispatcherTimer g_scrollDispatcherTimer{nullptr};
static winrt::event_token                        g_scrollDispatcherTimerToken{};
static bool                                       g_scrollDispatcherTimerHasToken = false;
static void TickScrollState(TextScrollState& s, int stepPx, int pauseMs, const std::wstring& mode) {
    if (!s.active) return;
    if (s.pausing) {
        s.pauseTick -= s.tickMs;
        if (s.pauseTick <= 0) {
            s.pausing = false;
            s.pauseTick = 0;
        }
        return;
    }
    double maxOff = s.textWidth - s.viewWidth + 10.0;
    if (maxOff < 0.0) maxOff = 0.0;
    if (mode == L"loop") {
        s.offset += stepPx;
        if (s.offset >= s.textWidth + g_settings.loopGap) {
            s.offset = 0.0;
        }
    } else {
        if (s.forward) {
            s.offset += stepPx;
            if (s.offset >= maxOff) {
                s.offset = maxOff;
                s.forward = false;
                s.pausing = true;
                s.pauseTick = pauseMs;
            }
        } else {
            s.offset -= stepPx;
            if (s.offset <= 0.0) {
                s.offset = 0.0;
                s.forward = true;
                s.pausing = true;
                s.pauseTick = pauseMs;
            }
        }
    }
}
static void UpdateScrollTransforms();
static void ScrollTimerTick(winrt::Windows::Foundation::IInspectable const&,
                            winrt::Windows::Foundation::IInspectable const&) {
    if (g_unloading || g_applyingSettings) return;
    bool needsScroll = (g_titleScroll.active || g_artistScroll.active);
    if (!needsScroll) {
        if (g_scrollDispatcherTimer) {
            try { g_scrollDispatcherTimer.Stop(); } catch (...) {}
        }
        return;
    }
    int stepPx = std::max(1, g_settings.scrollSpeed);
    int pauseMs = g_settings.scrollPauseDuration;
    TickScrollState(g_titleScroll, stepPx, pauseMs, g_settings.scrollMode);
    TickScrollState(g_artistScroll, stepPx, pauseMs, g_settings.scrollMode);
    UpdateScrollTransforms();
}
static void StartScrollTimer() {
    HWND hWnd = g_taskbarWnd;
    if (!hWnd || !IsWindow(hWnd)) return;
    RunFromWindowThread(hWnd, [](void*) {
        try {
            if (!g_scrollDispatcherTimer) {
                g_scrollDispatcherTimer = winrt::Windows::UI::Xaml::DispatcherTimer();
                g_scrollDispatcherTimer.Interval(
                    winrt::Windows::Foundation::TimeSpan{std::chrono::milliseconds(16)});
                g_scrollDispatcherTimerToken = g_scrollDispatcherTimer.Tick(&ScrollTimerTick);
                g_scrollDispatcherTimerHasToken = true;
            }
            g_scrollDispatcherTimer.Start();
        } catch (...) {}
    }, nullptr);
}
static void StopScrollTimer() {
    HWND hWnd = g_taskbarWnd;
    auto stop = [](void*) {
        try {
            if (g_scrollDispatcherTimer) {
                g_scrollDispatcherTimer.Stop();
                if (g_unloading) {
                    if (g_scrollDispatcherTimerHasToken) {
                        g_scrollDispatcherTimer.Tick(g_scrollDispatcherTimerToken);
                        g_scrollDispatcherTimerHasToken = false;
                    }
                    g_scrollDispatcherTimer = nullptr;
                }
            }
        } catch (...) {}
    };
    if (hWnd && IsWindow(hWnd)) {
        RunFromWindowThread(hWnd, stop, nullptr);
    } else {
        stop(nullptr);
    }
}
static void ResetScrollState(TextScrollState& s) {
    s.offset    = 0.0;
    s.textWidth = 0.0;
    s.viewWidth = 0.0;
    s.forward   = true;
    s.active    = false;
    if (g_settings.scrollMode == L"loop") {
        s.pausing  = false;
        s.pauseTick = 0;
    } else {
        s.pausing  = true;
        s.pauseTick = g_settings.scrollPauseDuration;
    }
}
static constexpr wchar_t kTitleScrollViewName[]  = L"FluentMedia_TitleScrollView";
static constexpr wchar_t kArtistScrollViewName[] = L"FluentMedia_ArtistScrollView";
static constexpr wchar_t kTitleCloneName[]       = L"FluentMedia_TitleClone";
static constexpr wchar_t kArtistCloneName[]      = L"FluentMedia_ArtistClone";
static double GetAvailableScrollTextAreaWidth() {
    try {
        if (g_settings.playerMaxWidth <= 0) return 0.0;
        if (!g_playerGrid) return 0.0;
        auto panelFe = FindChildByName(g_playerGrid, kPanelGridName);
        if (!panelFe) return 0.0;
        auto panelGrid = panelFe.try_as<Grid>();
        if (!panelGrid) return 0.0;
        double total = panelGrid.ActualWidth();
        if (total <= 0.0) return 0.0;
        auto cols = panelGrid.ColumnDefinitions();
        double used = 0.0;
        for (uint32_t i = 0; i < cols.Size(); i++) {
            if (i == 1) continue;
            used += cols.GetAt(i).ActualWidth();
        }
        double leftMargin  = (double)g_settings.textAreaLeftMargin;
        double rightMargin = (double)g_settings.textAreaRightMargin;
        double available = total - used - leftMargin - rightMargin;
        if (available < 0.0) available = 0.0;
        return available;
    } catch (...) {
        return 0.0;
    }
}
static void UpdateScrollTransforms() {
    if (!g_playerGrid || (!g_settings.enableTitleScrolling && !g_settings.enableArtistScrolling)) return;
    bool isLoop = (g_settings.scrollMode == L"loop");
    if (g_settings.enableTitleScrolling && !g_settings.showNeteaseLyrics) {
        try {
            if (auto fe = FindChildByName(g_playerGrid, kTitleScrollViewName)) {
                if (auto cv = fe.try_as<Canvas>()) {
                    int n = VisualTreeHelper::GetChildrenCount(cv);
                    for (int i = 0; i < n; i++) {
                        auto child = VisualTreeHelper::GetChild(cv, i);
                        if (auto tb = child.try_as<TextBlock>()) {
                            auto name = tb.Name();
                            if (name == kTitleBlockName) {
                                if (g_settings.showNeteaseLyrics &&
                                    !g_titleScroll.active) {
                                    double centeredLeft = std::max(
                                        0.0,
                                        (g_titleScroll.viewWidth -
                                         g_titleScroll.textWidth) /
                                            2.0);
                                    Canvas::SetLeft(tb, centeredLeft);
                                } else {
                                    Canvas::SetLeft(tb, -g_titleScroll.offset);
                                }
                            } else if (isLoop && name == kTitleCloneName) {
                                double gap = g_titleScroll.textWidth + g_settings.loopGap;
                                Canvas::SetLeft(tb, gap - g_titleScroll.offset);
                            }
                        }
                    }
                }
            }
        } catch (...) {}
    }
    if (g_settings.enableArtistScrolling) {
        try {
            if (auto fe = FindChildByName(g_playerGrid, kArtistScrollViewName)) {
                if (auto cv = fe.try_as<Canvas>()) {
                    int n = VisualTreeHelper::GetChildrenCount(cv);
                    for (int i = 0; i < n; i++) {
                        auto child = VisualTreeHelper::GetChild(cv, i);
                        if (auto ab = child.try_as<TextBlock>()) {
                            auto name = ab.Name();
                            if (name == kArtistBlockName) {
                                Canvas::SetLeft(ab, -g_artistScroll.offset);
                            } else if (isLoop && name == kArtistCloneName) {
                                double gap = g_artistScroll.textWidth + g_settings.loopGap;
                                Canvas::SetLeft(ab, gap - g_artistScroll.offset);
                            }
                        }
                    }
                }
            }
        } catch (...) {}
    }
}
static void DispatchMediaUpdate() {
    bool unloading = g_unloading;
    bool applyingSettings = g_applyingSettings;
    if (unloading || applyingSettings) {
        return;
    }
    g_needsUiUpdate = true;
    if (g_timerUpdateEvent) {
        SetEvent(g_timerUpdateEvent);
    }
}
static void RefreshPlayerContents();
static void UpdateVisibility();
static void RefreshThemeColors();
static void RemovePlayerGrid();
static bool InjectPlayerGrid();
static void RefreshTaskbarMediaStateNow() {
    HWND taskbarWnd = g_taskbarWnd;
    if (!taskbarWnd || g_unloading || g_applyingSettings) return;
    RunFromWindowThread(taskbarWnd, [](void*) {
        if (!g_unloading && !g_applyingSettings && g_playerGrid) {
            RefreshPlayerContents();
            UpdateVisibility();
        }
    }, nullptr);
}
static std::atomic<bool> g_themeChangePending{false};
static DWORD WINAPI TimerThreadProc(void*) {
    HRESULT coInitResult = CoInitializeEx(nullptr, COINIT_MULTITHREADED);
    bool shouldUninitializeCom = SUCCEEDED(coInitResult);
    static bool lastThemeWasLight = IsSystemLightTheme();
    TwilightAudioLogTail twilightAudioLogTail;
    bool lastTwilightBridgeAvailable = false;
    HKEY hKey = nullptr;
    HANDLE hEvent = CreateEventW(nullptr, FALSE, FALSE, nullptr);
    if (RegOpenKeyExW(HKEY_CURRENT_USER, L"Software\\Microsoft\\Windows\\CurrentVersion\\Themes\\Personalize", 0, KEY_NOTIFY, &hKey) == ERROR_SUCCESS) {
        RegNotifyChangeKeyValue(hKey, FALSE, REG_NOTIFY_CHANGE_LAST_SET, hEvent, TRUE);
    }
    while (!g_unloading) {
        HANDLE handles[] = {g_timerStopEvent, hEvent, g_timerUpdateEvent};
        DWORD wait = WaitForMultipleObjects(3, handles, FALSE, 500);
        if (wait == WAIT_OBJECT_0) break;
        if (g_applyingSettings) continue;
        HWND hWnd = g_taskbarWnd;
        if (!hWnd || !IsWindow(hWnd)) {
            hWnd = FindCurrentProcessTaskbarWnd();
            g_taskbarWnd = hWnd;
            if (!hWnd) continue;
        }
        if (!g_playerGrid && !g_injectionParent && !g_unloading && !g_applyingSettings) {
            bool expected = false;
            if (g_injectionRetryPending.compare_exchange_strong(expected, true)) {
                bool scheduled = RunFromWindowThread(hWnd, [](void*) {
                    if (!g_unloading && !g_applyingSettings && !g_playerGrid && !g_injectionParent) {
                        InjectPlayerGrid();
                    }
                    g_injectionRetryPending = false;
                }, nullptr);
                if (!scheduled) {
                    g_injectionRetryPending = false;
                }
            }
        }
        ULONGLONG now = GetTickCount64();
        bool twilightSelected =
            g_selectedPlayer.load() == PlayerKind::TwilightEcho;
        TwilightBridgeSnapshot twilightBridgeState;
        bool twilightBridgeAvailable =
            twilightSelected && PollTwilightBridgeState(
                twilightBridgeState);
        if (twilightBridgeAvailable && !lastTwilightBridgeAvailable) {
            ResetTwilightAudioState();
            twilightAudioLogTail = {};
        }
        lastTwilightBridgeAvailable = twilightBridgeAvailable;
        bool twilightProcessRunning =
            twilightBridgeAvailable ||
            (twilightSelected && IsTwilightProcessRunning());
        bool twilightWasDetected =
            g_twilightProcessDetected.exchange(twilightProcessRunning);
        if (!twilightProcessRunning) {
            g_twilightNextPollTick = 0;
            g_twilightLikeForcePollAfterTick = 0;
            g_twilightPendingPlaybackState = -1;
            g_twilightPendingPlaybackUntilTick = 0;
            if (twilightWasDetected) {
                g_twilightTrackGeneration.fetch_add(1);
                g_twilightPendingTrackUntilTick = 0;
                g_twilightCoverGeneration.fetch_add(1);
                ResetTwilightAudioState();
                twilightAudioLogTail = {};
            }
            g_twilightAccessibleLastSuccessTick = 0;
            {
                std::lock_guard<std::mutex> lock(
                    g_twilightAccessiblePlaybackMtx);
                g_twilightPendingOldTrackKey.clear();
            }
            StoreTwilightAccessiblePlayback({});
            SetTwilightLikeState(NeteaseLikeState::Unknown);
            if (twilightSelected && ApplyTwilightAccessibleToMedia({})) {
                DispatchMediaUpdate();
            }
        } else if (twilightBridgeAvailable) {
            g_twilightNextPollTick = 0;
            g_twilightLikeForcePollAfterTick = 0;
            g_twilightPendingPlaybackState = -1;
            g_twilightPendingPlaybackUntilTick = 0;
            g_twilightAccessibleLastSuccessTick = now;
            ApplyTwilightBridgeSnapshot(twilightBridgeState);
        } else {
            PollTwilightAudioDiagnostics(twilightAudioLogTail);
            TryResolveTwilightAudioTrack(twilightAudioLogTail);
            ULONGLONG forceAfter = g_twilightLikeForcePollAfterTick.load();
            if (forceAfter && now >= forceAfter) {
                g_twilightLikeForcePollAfterTick = 0;
                g_twilightNextPollTick = 0;
                forceAfter = 0;
            }
            uint64_t observationGeneration =
                g_twilightPlaybackCommandGeneration.load();
            uint64_t observationTrackGeneration =
                g_twilightTrackGeneration.load();
            if ((!forceAfter || now >= forceAfter) &&
                now >= g_twilightNextPollTick.load()) {
                TwilightAccessiblePlayback snapshot =
                    QueryTwilightAccessiblePlayback();
                ULONGLONG queryFinishedAt = GetTickCount64();
                bool observationReachable = snapshot.reachable;
                if (!snapshot.reachable) {
                    ULONGLONG lastSuccess =
                        g_twilightAccessibleLastSuccessTick.load();
                    if (lastSuccess && queryFinishedAt >= lastSuccess &&
                        queryFinishedAt - lastSuccess <= 2500) {
                        snapshot = GetTwilightAccessiblePlayback();
                    }
                }
                bool deferObservation = false;
                bool restoreTwilightTrackAssets = false;
                ULONGLONG pendingTrackUntil =
                    g_twilightPendingTrackUntilTick.load();
                if (observationTrackGeneration ==
                        g_twilightTrackGeneration.load() &&
                    pendingTrackUntil) {
                    std::wstring pendingOldTrackKey;
                    {
                        std::lock_guard<std::mutex> lock(
                            g_twilightAccessiblePlaybackMtx);
                        pendingOldTrackKey = g_twilightPendingOldTrackKey;
                    }
                    std::wstring snapshotTrackKey =
                        TwilightTrackKey(snapshot);
                    if (queryFinishedAt <= pendingTrackUntil &&
                        (!observationReachable ||
                         snapshotTrackKey == pendingOldTrackKey)) {
                        deferObservation = true;
                    } else if (queryFinishedAt > pendingTrackUntil ||
                               (observationReachable &&
                                snapshotTrackKey != pendingOldTrackKey)) {
                        restoreTwilightTrackAssets =
                            queryFinishedAt > pendingTrackUntil &&
                            snapshot.reachable &&
                            snapshotTrackKey == pendingOldTrackKey;
                        std::lock_guard<std::mutex> lock(
                            g_twilightAccessiblePlaybackMtx);
                        if (observationTrackGeneration ==
                            g_twilightTrackGeneration.load()) {
                            g_twilightPendingTrackUntilTick = 0;
                            g_twilightPendingOldTrackKey.clear();
                        }
                    }
                }
                int pendingPlaybackState =
                    g_twilightPendingPlaybackState.load();
                if (observationGeneration ==
                        g_twilightPlaybackCommandGeneration.load() &&
                    pendingPlaybackState >= 0) {
                    ULONGLONG pendingUntil =
                        g_twilightPendingPlaybackUntilTick.load();
                    if (queryFinishedAt <= pendingUntil &&
                        (!observationReachable ||
                         snapshot.isPlaying !=
                             (pendingPlaybackState != 0))) {
                        deferObservation = true;
                    }
                }
                if (deferObservation) {
                    g_twilightNextPollTick = queryFinishedAt + 100;
                } else {
                    auto committed = CommitTwilightAccessiblePlayback(
                        snapshot, observationGeneration,
                        observationTrackGeneration,
                        snapshot.observedForeground);
                    if (committed.accepted) {
                        if (observationReachable) {
                            g_twilightAccessibleLastSuccessTick =
                                queryFinishedAt;
                        }
                        if (restoreTwilightTrackAssets &&
                            committed.state.reachable) {
                            ScheduleTwilightAccessibleCoverFetch(
                                committed.state.title,
                                committed.state.artist,
                                committed.state.durationMs,
                                observationTrackGeneration);
                            FetchMediaPropertiesAsync();
                        }
                        ULONGLONG latestForceAfter =
                            g_twilightLikeForcePollAfterTick.load();
                        if (!latestForceAfter ||
                            queryFinishedAt >= latestForceAfter) {
                            SetTwilightLikeState(
                                NeteaseLikeState::Unknown);
                        }
                        g_twilightNextPollTick = queryFinishedAt + 750;
                    }
                }
            }
        }
        if (wait == WAIT_OBJECT_0 + 1) {
            if (hKey) {
                RegNotifyChangeKeyValue(hKey, FALSE, REG_NOTIFY_CHANGE_LAST_SET, hEvent, TRUE);
            }
            {
                bool currentThemeIsLight = IsSystemLightTheme();
                if (currentThemeIsLight != lastThemeWasLight) {
                    lastThemeWasLight = currentThemeIsLight;
                    g_themeChangePending = true;
                    g_needsUiUpdate = true;
                    if (g_timerUpdateEvent) SetEvent(g_timerUpdateEvent);
                }
            }
        }
        if (g_themeChangePending.exchange(false)) {
            Sleep(150);
            if (!g_unloading && !g_applyingSettings) {
                RunFromWindowThread(hWnd, [](void*) {
                    if (!g_unloading && !g_applyingSettings && g_playerGrid) {
                        RefreshThemeColors();
                    }
                }, nullptr);
            }
        }
        bool needsUpdate = g_needsUiUpdate.exchange(false);
        if (g_taskbarWrapperHovered.load()) {
            needsUpdate = true;
        }
        if (g_settings.idleHideSeconds > 0) {
            bool playing = false;
            { std::lock_guard<std::mutex> lk(g_mediaMtx); playing = g_media.isPlaying; }
            if (playing) {
                g_idleSeconds = 0;
                g_idleTicks   = 0;
                if (g_hiddenByIdle) {
                    g_hiddenByIdle = false;
                    needsUpdate = true;
                }
            } else {
                ++g_idleTicks;
                if (g_idleTicks >= 2) {
                    g_idleTicks = 0;
                    ++g_idleSeconds;
                }
                if (!g_hiddenByIdle && g_idleSeconds >= g_settings.idleHideSeconds) {
                    g_hiddenByIdle = true;
                    needsUpdate = true;
                }
            }
        } else {
            if (g_hiddenByIdle) {
                g_hiddenByIdle = false;
                g_idleSeconds  = 0;
                g_idleTicks    = 0;
                needsUpdate    = true;
            }
        }
        if (needsUpdate) {
            RunFromWindowThread(hWnd, [](void*) {
                if (g_unloading || g_applyingSettings) return;
                if (g_playerGrid) {
                    RefreshPlayerContents();
                    UpdateVisibility();
                }
            }, nullptr);
        }
    }
    if (hKey) RegCloseKey(hKey);
    if (hEvent) CloseHandle(hEvent);
    if (shouldUninitializeCom) CoUninitialize();
    return 0;
}
static constexpr int VIZ_BARS_MAX = 20;
static constexpr int VIZ_FFT_SIZE = 1024;
static constexpr int VIZ_NUM_BANDS = 7;
static constexpr float VIZ_PI = 3.14159265f;
static std::atomic<float> g_VizBands[VIZ_NUM_BANDS] = {};
static std::atomic<bool> g_CaptureRunning{false};
static std::atomic<bool> g_vizCurrentlyVisible{false};
[[clang::no_destroy]] static std::optional<std::thread> g_CaptureThread;
static HANDLE g_hCaptureEvent = nullptr;
static std::atomic<bool> g_VizDeviceChanged{false};
static std::mutex g_captureThreadMtx;
class VizEndpointNotificationClient : public IMMNotificationClient {
public:
    virtual ~VizEndpointNotificationClient() = default;
    ULONG STDMETHODCALLTYPE AddRef() override {
        return InterlockedIncrement(&m_ref);
    }
    ULONG STDMETHODCALLTYPE Release() override {
        ULONG ref = InterlockedDecrement(&m_ref);
        if (ref == 0)
            delete this;
        return ref;
    }
    HRESULT STDMETHODCALLTYPE QueryInterface(REFIID riid, void** ppv) override {
        if (riid == __uuidof(IUnknown) || riid == __uuidof(IMMNotificationClient)) {
            *ppv = static_cast<IMMNotificationClient*>(this);
            AddRef();
            return S_OK;
        }
        *ppv = nullptr;
        return E_NOINTERFACE;
    }
    HRESULT STDMETHODCALLTYPE OnDefaultDeviceChanged(EDataFlow flow, ERole,
                                                    LPCWSTR) override {
        if (flow == eRender)
            g_VizDeviceChanged.store(true, std::memory_order_relaxed);
        return S_OK;
    }
    HRESULT STDMETHODCALLTYPE OnDeviceAdded(LPCWSTR) override {
        g_VizDeviceChanged.store(true, std::memory_order_relaxed);
        return S_OK;
    }
    HRESULT STDMETHODCALLTYPE OnDeviceRemoved(LPCWSTR) override {
        g_VizDeviceChanged.store(true, std::memory_order_relaxed);
        return S_OK;
    }
    HRESULT STDMETHODCALLTYPE OnDeviceStateChanged(LPCWSTR, DWORD) override {
        g_VizDeviceChanged.store(true, std::memory_order_relaxed);
        return S_OK;
    }
    HRESULT STDMETHODCALLTYPE OnPropertyValueChanged(LPCWSTR,
                                                    const PROPERTYKEY) override {
        return S_OK;
    }
private:
    LONG m_ref = 1;
};
static float g_HannWindow[VIZ_FFT_SIZE] = {};
static float g_TwiddleRe[VIZ_FFT_SIZE / 2] = {};
static float g_TwiddleIm[VIZ_FFT_SIZE / 2] = {};
static int g_LogBinStart[VIZ_NUM_BANDS + 1] = {};
static void BuildHannWindow() {
    for (int i = 0; i < VIZ_FFT_SIZE; i++)
        g_HannWindow[i] = 0.5f * (1.f - cosf(2.f * VIZ_PI * i / (VIZ_FFT_SIZE - 1)));
}
static void BuildTwiddleFactors() {
    for (int i = 0; i < VIZ_FFT_SIZE / 2; i++) {
        float ang = -2.0f * VIZ_PI * i / VIZ_FFT_SIZE;
        g_TwiddleRe[i] = cosf(ang);
        g_TwiddleIm[i] = sinf(ang);
    }
}
static void BuildLogBins(UINT32 sampleRate) {
    static constexpr float FREQ_EDGES[VIZ_NUM_BANDS + 1] = {
        20.f, 120.f, 300.f, 800.f, 2500.f, 6000.f, 14000.f, 20000.f};
    for (int b = 0; b <= VIZ_NUM_BANDS; b++) {
        int bin = (int)(FREQ_EDGES[b] * VIZ_FFT_SIZE / (float)sampleRate);
        g_LogBinStart[b] = std::max(1, std::min(VIZ_FFT_SIZE / 2 - 1, bin));
    }
}
static void VizFFT(std::vector<float>& re, std::vector<float>& im) {
    int n = (int)re.size();
    for (int i = 1, j = 0; i < n; i++) {
        int bit = n >> 1;
        for (; j & bit; bit >>= 1)
            j ^= bit;
        j ^= bit;
        if (i < j) {
            std::swap(re[i], re[j]);
            std::swap(im[i], im[j]);
        }
    }
    for (int len = 2; len <= n; len <<= 1) {
        int halfLen = len / 2;
        int stride = n / len;
        for (int i = 0; i < n; i += len) {
            for (int j = 0; j < halfLen; j++) {
                float wRe = g_TwiddleRe[j * stride];
                float wIm = g_TwiddleIm[j * stride];
                float uRe = re[i + j], uIm = im[i + j];
                float vRe = re[i + j + halfLen] * wRe - im[i + j + halfLen] * wIm;
                float vIm = re[i + j + halfLen] * wIm + im[i + j + halfLen] * wRe;
                re[i + j] = uRe + vRe;
                im[i + j] = uIm + vIm;
                re[i + j + halfLen] = uRe - vRe;
                im[i + j + halfLen] = uIm - vIm;
            }
        }
    }
}
struct VizEQMul { float low, mid, high; };
static VizEQMul GetVizEQMultipliers(VizEQ eq) {
    switch (eq) {
    case VizEQ::Bass: return {2.0f, 0.6f, 0.4f};
    case VizEQ::Rock: return {1.3f, 1.5f, 1.2f};
    case VizEQ::Pop: return {0.8f, 1.2f, 1.8f};
    case VizEQ::Jazz: return {1.1f, 0.8f, 0.6f};
    case VizEQ::Electronic: return {1.7f, 0.6f, 1.7f};
    default: return {1.0f, 1.0f, 1.0f};
    }
}
static bool VizInitAudioClient(IMMDeviceEnumerator* pEnum,
                                winrt::com_ptr<IAudioClient>& pClient,
                                winrt::com_ptr<IAudioCaptureClient>& pCapture,
                                UINT32& sampleRate, UINT32& channels,
                                bool& isFloat, HANDLE hEvent) {
    pClient = nullptr;
    pCapture = nullptr;
    winrt::com_ptr<IMMDevice> pDev;
    if (FAILED(pEnum->GetDefaultAudioEndpoint(eRender, eConsole, pDev.put())))
        return false;
    winrt::com_ptr<IAudioClient> pC;
    if (FAILED(pDev->Activate(__uuidof(IAudioClient), CLSCTX_ALL, nullptr,
                            pC.put_void())))
        return false;
    WAVEFORMATEX* pwfx = nullptr;
    pC->GetMixFormat(&pwfx);
    if (!pwfx)
        return false;
    sampleRate = pwfx->nSamplesPerSec;
    channels = pwfx->nChannels;
    isFloat = (pwfx->wFormatTag == WAVE_FORMAT_IEEE_FLOAT) ||
            (pwfx->wFormatTag == WAVE_FORMAT_EXTENSIBLE &&
            reinterpret_cast<WAVEFORMATEXTENSIBLE*>(pwfx)->SubFormat ==
                KSDATAFORMAT_SUBTYPE_IEEE_FLOAT);
    HRESULT hr = pC->Initialize(
        AUDCLNT_SHAREMODE_SHARED,
        AUDCLNT_STREAMFLAGS_LOOPBACK | AUDCLNT_STREAMFLAGS_EVENTCALLBACK,
        200000, 0, pwfx, nullptr);
    CoTaskMemFree(pwfx);
    if (FAILED(hr))
        return false;
    if (hEvent)
        pC->SetEventHandle(hEvent);
    winrt::com_ptr<IAudioCaptureClient> pCap;
    if (FAILED(pC->GetService(__uuidof(IAudioCaptureClient), pCap.put_void())))
        return false;
    if (FAILED(pC->Start()))
        return false;
    pClient = pC;
    pCapture = pCap;
    return true;
}
static void VizCaptureThreadProc() {
    CoInitializeEx(nullptr, COINIT_MULTITHREADED);
    BuildHannWindow();
    BuildTwiddleFactors();
    winrt::com_ptr<IMMDeviceEnumerator> pEnum;
    if (FAILED(CoCreateInstance(XIID_MMDeviceEnumerator, nullptr, CLSCTX_ALL,
                                XIID_IMMDeviceEnumerator, pEnum.put_void()))) {
        g_CaptureRunning.store(false);
        CoUninitialize();
        return;
    }
    auto* notifyClient = new VizEndpointNotificationClient();
    bool notifyRegistered =
        SUCCEEDED(pEnum->RegisterEndpointNotificationCallback(notifyClient));
    winrt::com_ptr<IAudioClient> pClient;
    winrt::com_ptr<IAudioCaptureClient> pCapture;
    UINT32 sampleRate = 48000, channels = 2;
    bool isFloat = true;
    g_VizDeviceChanged.store(false, std::memory_order_relaxed);
    if (VizInitAudioClient(pEnum.get(), pClient, pCapture, sampleRate, channels,
                        isFloat, g_hCaptureEvent))
        BuildLogBins(sampleRate);
    static constexpr int RING_CAP = VIZ_FFT_SIZE * 4;
    std::vector<float> ringBuf(RING_CAP, 0.f);
    int ringHead = 0, ringCount = 0;
    std::vector<float> re(VIZ_FFT_SIZE), im(VIZ_FFT_SIZE);
    float bandEnv[VIZ_NUM_BANDS] = {};
    static constexpr float GRAVITY[VIZ_NUM_BANDS] = {0.018f, 0.020f, 0.022f, 0.025f,
                                                    0.030f, 0.036f, 0.042f};
    ULONGLONG lastReinitAttempt = GetTickCount64() - 1000;
    while (g_CaptureRunning.load(std::memory_order_relaxed)) {
        if (g_hCaptureEvent)
            WaitForSingleObject(g_hCaptureEvent, 20);
        else
            Sleep(8);
        bool needsReinit = g_VizDeviceChanged.exchange(false, std::memory_order_relaxed) ||
                            !pClient;
        if (needsReinit) {
            ULONGLONG now = GetTickCount64();
            if (now - lastReinitAttempt >= 500) {
                lastReinitAttempt = now;
                if (pClient)
                    pClient->Stop();
                ringHead = 0;
                ringCount = 0;
                for (int b = 0; b < VIZ_NUM_BANDS; b++) {
                    bandEnv[b] = 0.f;
                    g_VizBands[b].store(0.f, std::memory_order_relaxed);
                }
                if (VizInitAudioClient(pEnum.get(), pClient, pCapture, sampleRate,
                                    channels, isFloat, g_hCaptureEvent))
                    BuildLogBins(sampleRate);
            }
        }
        if (!pCapture)
            continue;
        UINT32 packetSize = 0;
        HRESULT hr = pCapture->GetNextPacketSize(&packetSize);
        if (hr == AUDCLNT_E_DEVICE_INVALIDATED) {
            g_VizDeviceChanged.store(true, std::memory_order_relaxed);
            continue;
        }
        if (FAILED(hr) || packetSize == 0) {
            for (int b = 0; b < VIZ_NUM_BANDS; b++) {
                bandEnv[b] = std::max(0.f, bandEnv[b] - GRAVITY[b]);
                g_VizBands[b].store(bandEnv[b], std::memory_order_relaxed);
            }
            continue;
        }
        while (packetSize > 0) {
            BYTE* pData = nullptr;
            UINT32 numFrames = 0;
            DWORD flags = 0;
            HRESULT hrBuf =
                pCapture->GetBuffer(&pData, &numFrames, &flags, nullptr, nullptr);
            if (hrBuf == AUDCLNT_E_DEVICE_INVALIDATED) {
                g_VizDeviceChanged.store(true, std::memory_order_relaxed);
                break;
            }
            if (FAILED(hrBuf))
                break;
            if (!(flags & AUDCLNT_BUFFERFLAGS_SILENT) && pData && numFrames > 0) {
                if (isFloat) {
                    float* src = reinterpret_cast<float*>(pData);
                    for (UINT32 f = 0; f < numFrames; f++) {
                        float mono = 0.f;
                        for (UINT32 c = 0; c < channels; c++)
                            mono += src[f * channels + c];
                        ringBuf[ringHead] = mono / (float)channels;
                        ringHead = (ringHead + 1) % RING_CAP;
                        if (ringCount < RING_CAP)
                            ringCount++;
                    }
                } else {
                    INT16* src = reinterpret_cast<INT16*>(pData);
                    for (UINT32 f = 0; f < numFrames; f++) {
                        float mono = 0.f;
                        for (UINT32 c = 0; c < channels; c++)
                            mono += src[f * channels + c] / 32768.f;
                        ringBuf[ringHead] = mono / (float)channels;
                        ringHead = (ringHead + 1) % RING_CAP;
                        if (ringCount < RING_CAP)
                            ringCount++;
                    }
                }
            }
            pCapture->ReleaseBuffer(numFrames);
            hr = pCapture->GetNextPacketSize(&packetSize);
            if (hr == AUDCLNT_E_DEVICE_INVALIDATED) {
                g_VizDeviceChanged.store(true, std::memory_order_relaxed);
                break;
            }
            if (FAILED(hr))
                break;
        }
        while (ringCount >= VIZ_FFT_SIZE) {
            int readStart = (ringHead - ringCount + RING_CAP) % RING_CAP;
            for (int i = 0; i < VIZ_FFT_SIZE; i++) {
                re[i] = ringBuf[(readStart + i) % RING_CAP] * g_HannWindow[i];
                im[i] = 0.f;
            }
            ringCount -= VIZ_FFT_SIZE / 2;
            VizFFT(re, im);
            float t_sens = g_settings.vizSensitivity / 100.0f;
            float sliderGain = (t_sens <= 1.0f)
                ? 0.25f + t_sens * t_sens * 2.75f
                : 3.0f + (t_sens - 1.0f) * 4.0f;
            auto eq = GetVizEQMultipliers(g_settings.vizEq);
            static constexpr float BAND_SENSITIVITY[VIZ_NUM_BANDS] = {
                0.30f, 0.22f, 0.12f, 0.06f, 0.030f, 0.018f, 0.010f};
            static constexpr int BAND_EQ_ZONE[VIZ_NUM_BANDS] = {0, 0, 1, 1, 2, 2, 2};
            for (int b = 0; b < VIZ_NUM_BANDS; b++) {
                int bStart = g_LogBinStart[b];
                int bEnd = g_LogBinStart[b + 1];
                if (bEnd <= bStart)
                    bEnd = bStart + 1;
                float sumSq = 0.f;
                int count = 0;
                for (int k = bStart; k < bEnd; k++) {
                    sumSq += re[k] * re[k] + im[k] * im[k];
                    count++;
                }
                float rms = (count > 0) ? sqrtf(sumSq / (float)count) : 0.f;
                float eqM = (BAND_EQ_ZONE[b] == 0)   ? eq.low
                            : (BAND_EQ_ZONE[b] == 1) ? eq.mid
                                                    : eq.high;
                float mag = std::max(
                    0.f, std::min(1.f, (rms / (VIZ_FFT_SIZE * 0.5f)) /
                                        BAND_SENSITIVITY[b] * sliderGain * eqM));
                bandEnv[b] = (mag >= bandEnv[b])
                                ? mag
                                : std::max(0.f, bandEnv[b] - GRAVITY[b]);
                g_VizBands[b].store(bandEnv[b], std::memory_order_relaxed);
            }
        }
    }
    if (pClient)
        pClient->Stop();
    if (notifyRegistered)
        pEnum->UnregisterEndpointNotificationCallback(notifyClient);
    notifyClient->Release();
    CoUninitialize();
}
static void StartVizCaptureThread() {
    std::lock_guard<std::mutex> lk(g_captureThreadMtx);
    if (g_CaptureRunning.load())
        return;
    if (g_CaptureThread && g_CaptureThread->joinable())
        g_CaptureThread->join();
    g_CaptureThread.reset();
    if (!g_hCaptureEvent)
        g_hCaptureEvent = CreateEvent(nullptr, FALSE, FALSE, nullptr);
    g_CaptureRunning.store(true);
    g_CaptureThread.emplace(VizCaptureThreadProc);
}
static void StopVizCaptureThread() {
    g_CaptureRunning.store(false);
    if (g_hCaptureEvent)
        SetEvent(g_hCaptureEvent);
    std::lock_guard<std::mutex> lk(g_captureThreadMtx);
    if (g_CaptureThread) {
        if (g_CaptureThread->joinable())
            g_CaptureThread->join();
        g_CaptureThread.reset();
    }
    if (g_hCaptureEvent) {
        CloseHandle(g_hCaptureEvent);
        g_hCaptureEvent = nullptr;
    }
    for (int i = 0; i < VIZ_NUM_BANDS; i++)
        g_VizBands[i].store(0.f);
}
static float g_VizPeak[VIZ_BARS_MAX] = {};
static float g_VizTarget[VIZ_BARS_MAX] = {};
static float g_VizBreatheEnv = 0.f;
static constexpr float VIZ_SEEDS[VIZ_BARS_MAX] = {
    0.83f, 0.41f, 1.27f, 0.61f, 1.09f, 0.37f, 0.95f, 0.52f, 1.18f, 0.74f,
    0.29f, 1.03f, 0.66f, 0.88f, 0.45f, 1.21f, 0.57f, 0.93f, 0.31f, 1.15f};
static void UpdateVisualizerPeaks() {
    const int vizBars = std::max(1, std::min(g_settings.vizBars, VIZ_BARS_MAX));
    float bands[VIZ_NUM_BANDS];
    float masterPeak = 0.f;
    for (int i = 0; i < VIZ_NUM_BANDS; i++) {
        bands[i] = g_VizBands[i].load(std::memory_order_relaxed);
        masterPeak = std::max(masterPeak, bands[i]);
    }
    auto eq = GetVizEQMultipliers(g_settings.vizEq);
    auto sampleBands = [&](float t) -> float {
        float pos = t * (VIZ_NUM_BANDS - 1);
        int lo = (int)pos;
        int hi = std::min(lo + 1, VIZ_NUM_BANDS - 1);
        return bands[lo] * (1.f - (pos - (float)lo)) +
            bands[hi] * (pos - (float)lo);
    };
    auto eqForT = [&](float t) -> float {
        return (t < 0.33f) ? eq.low : (t < 0.66f) ? eq.mid : eq.high;
    };
    float t = (float)GetTickCount64() * 0.001f;
    float center = (vizBars - 1) * 0.5f;
    for (int i = 0; i < vizBars; i++) {
        float freqT = (vizBars > 1) ? (float)i / (float)(vizBars - 1) : 0.5f;
        float target = 0.f;
        switch (g_settings.vizShape) {
            case VizShape::Stereo:
                target = sampleBands(freqT) * eqForT(freqT);
                break;
            case VizShape::Mountain: {
                float dist = fabsf((float)i - center) / std::max(1.f, center);
                float energy = sampleBands(dist) * eqForT(dist);
                float taper = 1.6f - dist * 0.9f;
                target = std::max(
                    0.f, std::min(1.f, (energy + masterPeak * (0.2f - dist * 0.12f)) *
                                        taper));
                break;
            }
            case VizShape::Mirror: {
                float mirT = 1.f - fabsf((float)i - center) / std::max(1.f, center);
                float energy = sampleBands(mirT) * eqForT(mirT);
                target = std::max(
                    0.f, std::min(1.f, (energy + masterPeak * (0.1f + mirT * 0.12f)) *
                                        1.3f));
                break;
            }
            case VizShape::Wave: {
                float phase = (float)i * (2.f * VIZ_PI / (float)vizBars);
                float wave = 0.55f + 0.45f * sinf(t * 3.5f - phase);
                float energy = sampleBands(freqT) * eqForT(freqT);
                target = std::max(0.f, std::min(1.f, energy * wave + masterPeak * 0.15f));
                break;
            }
            case VizShape::Breathe: {
                if (i == 0) {
                    float k = (masterPeak > g_VizBreatheEnv) ? 0.04f : 0.015f;
                    g_VizBreatheEnv += (masterPeak - g_VizBreatheEnv) * k;
                }
                float rate = 0.55f + VIZ_SEEDS[i % VIZ_BARS_MAX] * 0.18f;
                float inhale =
                    0.5f + 0.5f * sinf(t * rate + VIZ_SEEDS[i % VIZ_BARS_MAX] * 1.2f);
                target = std::max(0.f, std::min(1.f,
                                                inhale * (0.12f + g_VizBreatheEnv * 0.88f)));
                break;
            }
        }
        g_VizTarget[i] = std::max(0.f, std::min(1.f, target));
    }
}
using VizRect = winrt::Windows::UI::Xaml::Shapes::Rectangle;
[[clang::no_destroy]] static std::optional<std::vector<VizRect>> g_vizBars{std::in_place};
[[clang::no_destroy]] static std::optional<std::vector<SolidColorBrush>> g_vizBrushes{std::in_place};
static winrt::Windows::UI::Color VizLerpColor(winrt::Windows::UI::Color a,
                                            winrt::Windows::UI::Color b, float t) {
    auto L = [](BYTE x, BYTE y, float tt) -> BYTE {
        return (BYTE)((int)x + (int)((float)((int)y - (int)x) * tt));
    };
    return winrt::Windows::UI::Color{255, L(a.R, b.R, t), L(a.G, b.G, t), L(a.B, b.B, t)};
}
static winrt::Windows::UI::Color VizEnsureContrast(winrt::Windows::UI::Color c) {
    const int kLumaThreshold = 90;
    bool light = IsSystemLightTheme();
    int luma = (c.R * 299 + c.G * 587 + c.B * 114) / 1000;
    int edgeDist = light ? (255 - luma) : luma;
    if (edgeDist >= kLumaThreshold) return c;
    winrt::Windows::UI::Color base = light
        ? winrt::Windows::UI::Color{255, 0, 0, 0}
        : winrt::Windows::UI::Color{255, 255, 255, 255};
    if (g_cachedThumbnailBytes.empty()) return base;
    float t = edgeDist / (float)kLumaThreshold;
    float tintAmount = 0.65f + t * 0.35f;
    return VizLerpColor(base, c, tintAmount);
}
static double VizZoneHeight() {
    double h = 0.0;
    if (g_settings.showAlbumArt && g_settings.albumArtMaxHeight > 0)
        h = std::max(h, (double)g_settings.albumArtMaxHeight);
    if (g_settings.showMediaButtons)
        h = std::max(h, (double)g_settings.buttonSize);
    if (h <= 0.0)
        h = (g_settings.playerMaxHeight > 0 ? (double)g_settings.playerMaxHeight : 40.0);
    if (g_settings.playerMaxHeight > 0)
        h = std::min(h, (double)g_settings.playerMaxHeight);
    return h;
}
static void VizApplyFrame() {
    if (!g_settings.vizEnabled || g_vizBars->empty())
        return;
    UpdateVisualizerPeaks();
    float attack = 0.55f, decay = 0.18f;
    float sensBoost = std::max(0.f, (g_settings.vizSensitivity - 100) / 200.f) * 0.12f;
    switch (g_settings.vizShape) {
        case VizShape::Stereo:  attack = 0.72f; decay = 0.22f + sensBoost; break;
        case VizShape::Mirror:  attack = 0.52f; decay = 0.20f + sensBoost; break;
        case VizShape::Wave:    attack = 0.34f; decay = 0.17f + sensBoost; break;
        case VizShape::Breathe: attack = 0.20f; decay = 0.11f + sensBoost; break;
        default:                decay += sensBoost; break;
    }
    int barCount = std::min((int)g_vizBars->size(), std::max(1, g_settings.vizBars));
    double zoneH = VizZoneHeight();
    double maxBH = std::max(4.0, zoneH - 6.0);
    double minBH = (double)g_settings.vizBarWidth;
    double idlePx = std::min((double)g_settings.vizIdleBarSize, std::max(0.0, maxBH - minBH));
    double range = std::max(0.0, maxBH - minBH - idlePx);
    bool idleHidden = (g_settings.vizIdleBarSize == 0);
    winrt::Windows::UI::Color baseCol{255, 255, 255, 255};
    if (g_settings.vizColorMode == VizColorMode::DynamicAlbum) {
        if (g_vizBaseColorDirty || g_vizPaletteColorsDirty) {
            g_cachedVizBaseColor = VizEnsureContrast(g_cachedAlbumPalette.primary);
            g_cachedVizBaseColor.A = 255;
        }
        baseCol = g_cachedVizBaseColor;
    } else {
        if (g_vizBaseColorDirty) {
            g_cachedVizBaseColor = ParseColorWithThemeSupport(g_settings.vizColor, 255);
        }
        baseCol = g_cachedVizBaseColor;
    }
    if (g_vizPaletteColorsDirty || g_vizBaseColorDirty) {
        g_cachedVizPal0   = VizEnsureContrast(g_cachedAlbumPalette.primary);
        g_cachedVizPal1   = VizEnsureContrast(g_cachedAlbumPalette.secondary);
        g_cachedVizCg0    = ParseColorWithSpecialValues(g_settings.vizColor1, 255);
        g_cachedVizCg1    = ParseColorWithSpecialValues(g_settings.vizColor2, 255);
        g_cachedVizAcrCol = ParseColorWithThemeSupport(g_settings.vizColor, 255);
        g_vizPaletteColorsDirty = false;
        g_vizBaseColorDirty = false;
    }
    const auto& pal0   = g_cachedVizPal0;
    const auto& pal1   = g_cachedVizPal1;
    const auto& cg0    = g_cachedVizCg0;
    const auto& cg1    = g_cachedVizCg1;
    const auto& acrCol = g_cachedVizAcrCol;
    for (int i = 0; i < barCount; i++) {
        float tgt = g_VizTarget[i], cur = g_VizPeak[i];
        float a = attack, d = decay;
        if (g_settings.vizShape == VizShape::Mountain) {
            float dist = fabsf((float)i - ((barCount - 1) * 0.5f));
            if (dist < 0.5f)      { a = 0.85f; d = 0.26f + sensBoost; }
            else if (dist < 1.5f) { a = 0.62f; d = 0.20f + sensBoost; }
            else                  { a = 0.92f; d = 0.34f + sensBoost; }
        }
        float next = cur + (tgt - cur) * ((tgt > cur) ? a : d);
        g_VizPeak[i] = (fabsf(next - cur) > 0.0005f) ? next : tgt;
        float fac = std::max(0.f, g_VizPeak[i]);
        double bh = idleHidden
            ? (fac * maxBH)
            : (minBH + idlePx + fac * range);
        winrt::Windows::UI::Color c = baseCol;
        if (g_settings.vizColorMode == VizColorMode::DynamicGradient) {
            float t = (float)i / std::max(1, barCount - 1);
            float freqT = std::min(1.f, t * 0.6f + fac * 0.4f);
            c = VizLerpColor(pal0, pal1, freqT);
        } else if (g_settings.vizColorMode == VizColorMode::CustomGradient) {
            float t = (barCount > 1) ? (float)i / (barCount - 1) : 0.f;
            c = VizLerpColor(cg0, cg1, t);
        } else if (g_settings.vizColorMode == VizColorMode::Acrylic) {
            BYTE aa = (BYTE)std::max(30, std::min(180, (int)(150.f * fac + 30.f)));
            c = winrt::Windows::UI::Color{aa, acrCol.R, acrCol.G, acrCol.B};
        }
        try {
            (*g_vizBars)[i].Height(bh);
            if (i < (int)g_vizBrushes->size() && (*g_vizBrushes)[i])
                (*g_vizBrushes)[i].Color(c);
        } catch (...) {}
    }
}
[[clang::no_destroy]] static winrt::Windows::UI::Xaml::DispatcherTimer g_vizDispatcherTimer{nullptr};
static winrt::event_token g_vizDispatcherTimerToken{};
static bool g_vizDispatcherTimerHasToken = false;
static void VizTimerTick(winrt::Windows::Foundation::IInspectable const&,
                        winrt::Windows::Foundation::IInspectable const&) {
    if (g_unloading || g_applyingSettings) return;
    if (!g_settings.vizEnabled) return;
    VizApplyFrame();
}
static void StartVizTimer() {
    HWND hWnd = g_taskbarWnd;
    if (!hWnd || !IsWindow(hWnd)) return;
    RunFromWindowThread(hWnd, [](void*) {
        try {
            if (!g_vizDispatcherTimer) {
                g_vizDispatcherTimer = winrt::Windows::UI::Xaml::DispatcherTimer();
                g_vizDispatcherTimer.Interval(
                    winrt::Windows::Foundation::TimeSpan{std::chrono::milliseconds(16)});
                g_vizDispatcherTimerToken = g_vizDispatcherTimer.Tick(&VizTimerTick);
                g_vizDispatcherTimerHasToken = true;
            }
            g_vizDispatcherTimer.Start();
        } catch (...) {}
    }, nullptr);
}
static void StopVizTimer() {
    HWND hWnd = g_taskbarWnd;
    auto stop = [](void*) {
        try {
            if (g_vizDispatcherTimer) {
                g_vizDispatcherTimer.Stop();
                if (g_unloading) {
                    if (g_vizDispatcherTimerHasToken) {
                        g_vizDispatcherTimer.Tick(g_vizDispatcherTimerToken);
                        g_vizDispatcherTimerHasToken = false;
                    }
                    g_vizDispatcherTimer = nullptr;
                }
            }
        } catch (...) {}
    };
    if (hWnd && IsWindow(hWnd)) {
        RunFromWindowThread(hWnd, stop, nullptr);
    } else {
        stop(nullptr);
    }
}
static FrameworkElement BuildVisualizerElement() {
    g_vizBars->clear();
    g_vizBrushes->clear();
    int barCount = std::clamp(g_settings.vizBars, 1, VIZ_BARS_MAX);
    double zoneH = VizZoneHeight();
    StackPanel bars;
    bars.Name(L"FluentMedia_VisualizerBars");
    bars.Orientation(Orientation::Horizontal);
    bars.Height(zoneH);
    bars.VerticalAlignment(VerticalAlignment::Center);
    bars.HorizontalAlignment(HorizontalAlignment::Center);
    bars.IsHitTestVisible(false);
    VerticalAlignment va = (g_settings.vizAnchor == VizAnchor::Top)    ? VerticalAlignment::Top
                        : (g_settings.vizAnchor == VizAnchor::Bottom) ? VerticalAlignment::Bottom
                                                            : VerticalAlignment::Center;
    double minBH = (double)g_settings.vizBarWidth;
    double maxBH = std::max(4.0, zoneH - 6.0);
    double idlePx = std::min((double)g_settings.vizIdleBarSize, std::max(0.0, maxBH - minBH));
    double corner = g_settings.vizBarWidth * 0.5;
    bool idleHidden = (g_settings.vizIdleBarSize == 0);
    for (int i = 0; i < barCount; i++) {
        VizRect r;
        r.Width((double)g_settings.vizBarWidth);
        r.Height(idleHidden ? 0.0 : (minBH + idlePx));
        r.RadiusX(corner);
        r.RadiusY(corner);
        r.VerticalAlignment(va);
        if (i > 0)
            r.Margin({(double)g_settings.vizBarGap, 0, 0, 0});
        SolidColorBrush br = MakeBrush({255, 255, 255, 255});
        r.Fill(br);
        if (g_settings.vizColorMode == VizColorMode::Acrylic) {
            r.Stroke(MakeBrush({0x40, 0xFF, 0xFF, 0xFF}));
            r.StrokeThickness(0.8);
        }
        bars.Children().Append(r);
        g_vizBars->push_back(r);
        g_vizBrushes->push_back(br);
    }
    bool vizLeft = (g_settings.vizPosition == L"left");
    if (g_settings.mirrorLayout) vizLeft = !vizLeft;
    const double kVizSectionGap = 6.0;
    double marginL = (double)g_settings.vizPadLeft  + (vizLeft ? 0.0 : kVizSectionGap);
    double marginR = (double)g_settings.vizPadRight + (vizLeft ? kVizSectionGap : 0.0);
    Grid vizContainer;
    vizContainer.Name(L"FluentMedia_Visualizer");
    vizContainer.Height(zoneH);
    vizContainer.VerticalAlignment(VerticalAlignment::Center);
    vizContainer.HorizontalAlignment(HorizontalAlignment::Center);
    vizContainer.IsHitTestVisible(false);
    vizContainer.Background(MakeBrush({0x00, 0x00, 0x00, 0x00}));
    vizContainer.Margin({marginL, 0, marginR, 0});
    if (g_settings.showDebugBorders) {
        Border vizDebugBorder;
        vizDebugBorder.BorderBrush(MakeBrush({0xFF, 0xFF, 0xFF, 0x00}));
        vizDebugBorder.BorderThickness({1, 1, 1, 1});
        vizDebugBorder.HorizontalAlignment(HorizontalAlignment::Stretch);
        vizDebugBorder.VerticalAlignment(VerticalAlignment::Stretch);
        vizContainer.Children().Append(vizDebugBorder);
    }
    vizContainer.Children().Append(bars);
    return vizContainer;
}
static void StartTimerThread() {
    if (g_timerThread) return;
    g_timerStopEvent = CreateEventW(nullptr, TRUE, FALSE, nullptr);
    g_timerUpdateEvent = CreateEventW(nullptr, FALSE, FALSE, nullptr);
    g_timerThread    = CreateThread(nullptr, 0, TimerThreadProc, nullptr, 0, nullptr);
    if (!g_timerThread) {
        CloseHandle(g_timerStopEvent);
        g_timerStopEvent = nullptr;
        CloseHandle(g_timerUpdateEvent);
        g_timerUpdateEvent = nullptr;
    }
    if (g_settings.enableTitleScrolling || g_settings.enableArtistScrolling) {
        StartScrollTimer();
    }
}
static void StopTimerThread() {
    StopScrollTimer();
    StopVizTimer();
    StopVizCaptureThread();
    if (g_timerStopEvent) SetEvent(g_timerStopEvent);
    if (g_timerThread) {
        DWORD tid = GetCurrentThreadId();
        HWND hTaskbar = g_taskbarWnd;
        bool isUiThread = hTaskbar && (GetWindowThreadProcessId(hTaskbar, nullptr) == tid);
        if (isUiThread) {
            for (;;) {
                DWORD result = MsgWaitForMultipleObjects(
                    1, &g_timerThread, FALSE, 50, QS_SENDMESSAGE);
                if (result == WAIT_OBJECT_0) break;
                if (result == WAIT_OBJECT_0 + 1) {
                    MSG msg;
                    while (PeekMessageW(&msg, nullptr, 0, 0, PM_REMOVE | PM_QS_SENDMESSAGE)) {
                        TranslateMessage(&msg);
                        DispatchMessageW(&msg);
                    }
                } else if (result == WAIT_FAILED) {
                    WaitForSingleObject(g_timerThread, INFINITE);
                    break;
                }
            }
        } else {
            WaitForSingleObject(g_timerThread, INFINITE);
        }
        CloseHandle(g_timerThread);
        g_timerThread = nullptr;
    }
    if (g_timerStopEvent) { CloseHandle(g_timerStopEvent); g_timerStopEvent = nullptr; }
    if (g_timerUpdateEvent) { CloseHandle(g_timerUpdateEvent); g_timerUpdateEvent = nullptr; }
}
static void RefreshThemeColors() {
    if (!g_playerGrid || g_unloading || g_applyingSettings) return;
    g_vizBaseColorDirty = true;
    g_vizPaletteColorsDirty = true;
    try {
        UpdateHoverBrushColors();
        auto textClr = TextColor();
        auto artistClr = ArtistColor();
        auto buttonClr = ButtonColor();
        if (auto bgFe = FindChildByName(g_playerGrid, L"FluentMedia_Background")) {
            if (auto bgBorder = bgFe.try_as<Border>()) {
                auto& bgType = g_settings.backgroundType;
                if (bgType == L"album_art_blur") {
                    if (!g_cachedThumbnailBytes.empty()) {
                        int w = (int)bgBorder.ActualWidth();
                        int h = (int)bgBorder.ActualHeight();
                        if (w > 0 && h > 0) {
                            bgBorder.Background(MakeAlbumBlurBrush(g_cachedThumbnailBytes, w, h));
                        }
                    } else {
                        auto fallbackCol = IsSystemLightTheme()
                            ? winrt::Windows::UI::Color{0xCC, 0xF3, 0xF3, 0xF3}
                            : winrt::Windows::UI::Color{0xCC, 0x20, 0x20, 0x20};
                        bgBorder.Background(MakeBrush(fallbackCol));
                    }
                    bgBorder.Visibility(Visibility::Visible);
                    bgBorder.Opacity(g_settings.blurOpacity / 100.0);
                } else if (bgType == L"solid" || bgType == L"gradient" || bgType == L"acrylic" || bgType == L"mica" || bgType == L"mica_alt") {
                    bgBorder.Background(MakeBackgroundBrush());
                    bgBorder.Visibility(Visibility::Visible);
                    bgBorder.Opacity(1.0);
                } else {
                    bgBorder.Background(nullptr);
                    bgBorder.Visibility(Visibility::Collapsed);
                }
            }
        }
        if (auto fe = FindChildByName(g_playerGrid, L"FluentMedia_OuterBorder")) {
            if (auto btn = fe.try_as<Button>()) {
                try {
                    auto normalBg = MakeBackgroundBrush();
                    ApplyFluentMediaButtonStyle(btn);
                    btn.ApplyTemplate();
                    SetupPlayerCommonStates(btn, normalBg);
                    GoToCommonState(btn, IsHoverEffectEnabled(g_settings.playerHoverEffectMode), false, false);
                } catch (...) {}
            }
        }
        if (auto fe = FindChildByName(g_playerGrid, kTitleBlockName))
            if (auto tb = fe.try_as<TextBlock>()) tb.Foreground(MakeBrush(textClr));
        if (auto fe = FindChildByName(g_playerGrid, kArtistBlockName))
            if (auto ab = fe.try_as<TextBlock>()) ab.Foreground(MakeBrush(artistClr));
        for (const wchar_t* name : {kPrevBtnName, kPlayBtnName, kNextBtnName, kRewindBtnName, kForwardBtnName, kShuffleBtnName, kRepeatBtnName, kSwitchSessionsBtnName}) {
            if (auto fe = FindChildByName(g_playerGrid, name)) {
                if (auto btn = fe.try_as<Button>()) {
                    if (auto ct = btn.Content().try_as<TextBlock>()) ct.Foreground(MakeBrush(buttonClr));
                    ApplyFluentMediaButtonStyle(btn);
                    btn.ApplyTemplate();
                    SetupMediaButtonCommonStates(btn);
                    try { VisualStateManager::GoToState(btn, L"Normal", false); } catch (...) {}
                }
            }
        }
    } catch (...) {}
}
static HMONITOR GetMonitorByNumber(int monitorNumber) {
    HMONITOR result = nullptr;
    int current = 0;
    struct Ctx { int target; HMONITOR* result; int* current; };
    Ctx ctx{monitorNumber - 1, &result, &current};
    EnumDisplayMonitors(nullptr, nullptr,
        [](HMONITOR hMon, HDC, LPRECT, LPARAM lp) CALLBACK -> BOOL {
            auto* c = reinterpret_cast<Ctx*>(lp);
            if (*c->current == c->target) { *c->result = hMon; return FALSE; }
            (*c->current)++;
            return TRUE;
        }, reinterpret_cast<LPARAM>(&ctx));
    return result;
}
static HWND FindTaskbarWndForMonitor(HMONITOR targetMonitor) {
    struct Ctx { HMONITOR target; HWND result; };
    Ctx ctx{targetMonitor, nullptr};
    EnumWindows([](HWND hWnd, LPARAM lp) CALLBACK -> BOOL {
        auto* c = reinterpret_cast<Ctx*>(lp);
        DWORD pid = 0; wchar_t cls[64] = {};
        if (GetWindowThreadProcessId(hWnd, &pid) && pid == GetCurrentProcessId() &&
            GetClassNameW(hWnd, cls, ARRAYSIZE(cls)) &&
            (_wcsicmp(cls, L"Shell_TrayWnd") == 0 ||
             _wcsicmp(cls, L"Shell_SecondaryTrayWnd") == 0)) {
            HMONITOR hMon = MonitorFromWindow(hWnd, MONITOR_DEFAULTTONEAREST);
            if (hMon == c->target) {
                c->result = hWnd;
                return FALSE;
            }
        }
        return TRUE;
    }, reinterpret_cast<LPARAM>(&ctx));
    return ctx.result;
}
static HWND FindCurrentProcessTaskbarWnd() {
    if (HMONITOR mon = GetMonitorByNumber(g_settings.monitor)) {
        if (HWND hWnd = FindTaskbarWndForMonitor(mon)) {
            return hWnd;
        }
    } else {
    }
    HWND result = nullptr;
    EnumWindows([](HWND hWnd, LPARAM lp) CALLBACK -> BOOL {
        DWORD pid = 0; wchar_t cls[32] = {};
        if (GetWindowThreadProcessId(hWnd, &pid) && pid == GetCurrentProcessId() &&
            GetClassNameW(hWnd, cls, ARRAYSIZE(cls)) &&
            _wcsicmp(cls, L"Shell_TrayWnd") == 0)
        {
            *reinterpret_cast<HWND*>(lp) = hWnd;
            return FALSE;
        }
        return TRUE;
    }, reinterpret_cast<LPARAM>(&result));
    return result;
}
static bool IsReadableMemoryRange(const void* address, size_t size) {
    if (!address || size == 0) return false;
    MEMORY_BASIC_INFORMATION memory{};
    if (!VirtualQuery(address, &memory, sizeof(memory)) ||
        memory.State != MEM_COMMIT ||
        (memory.Protect & (PAGE_GUARD | PAGE_NOACCESS))) {
        return false;
    }
    const auto start = reinterpret_cast<uintptr_t>(address);
    const auto regionStart = reinterpret_cast<uintptr_t>(memory.BaseAddress);
    const auto regionEnd = regionStart + memory.RegionSize;
    return start >= regionStart && start <= regionEnd &&
           size <= regionEnd - start;
}
static XamlRoot GetTaskbarXamlRoot(HWND hTaskbarWnd) {
    wchar_t clsBuf[64] = {};
    GetClassNameW(hTaskbarWnd, clsBuf, ARRAYSIZE(clsBuf));
    bool isSecondary = _wcsicmp(clsBuf, L"Shell_SecondaryTrayWnd") == 0;
    HWND hTaskSwWnd = isSecondary
        ? FindWindowExW(hTaskbarWnd, nullptr, L"WorkerW", nullptr)
        : (HWND)GetProp(hTaskbarWnd, L"TaskbandHWND");
    if (!hTaskSwWnd) {
        Wh_Log(L"GetTaskbarXamlRoot: could not find taskband host window, aborting");
        return nullptr;
    }
    wchar_t swCls[64] = {};
    GetClassNameW(hTaskSwWnd, swCls, ARRAYSIZE(swCls));
    void* taskBand = (void*)GetWindowLongPtrW(hTaskSwWnd, 0);
    if (!taskBand) {
        Wh_Log(L"GetTaskbarXamlRoot: taskBand pointer is null, aborting");
        return nullptr;
    }
    void* expectedVftable = isSecondary
        ? CSecondaryTaskBand_ITaskListWndSite_vftable
        : CTaskBand_ITaskListWndSite_vftable;
    auto getTaskbarHost = isSecondary
        ? CSecondaryTaskBand_GetTaskbarHost_Original
        : CTaskBand_GetTaskbarHost_Original;
    if (!expectedVftable || !getTaskbarHost) {
        Wh_Log(L"GetTaskbarXamlRoot: %s symbols not resolved, aborting",
            isSecondary ? L"CSecondaryTaskBand" : L"CTaskBand");
        return nullptr;
    }
    void* taskBandForTaskListWndSite = taskBand;
    int i = 0;
    constexpr int kMaxSlotsToScan = 20;
    for (;; i++) {
        if (!IsReadableMemoryRange(taskBandForTaskListWndSite, sizeof(void*))) {
            Wh_Log(L"GetTaskbarXamlRoot: hit unreadable memory at slot %d, aborting", i);
            return nullptr;
        }
        if (*(void**)taskBandForTaskListWndSite == expectedVftable) break;
        if (i == kMaxSlotsToScan) {
            Wh_Log(L"GetTaskbarXamlRoot: ITaskListWndSite vftable not found within %d slots, aborting",
                kMaxSlotsToScan);
            return nullptr;
        }
        taskBandForTaskListWndSite = (void**)taskBandForTaskListWndSite + 1;
    }
    void* taskbarHostSharedPtr[2]{};
    getTaskbarHost(taskBandForTaskListWndSite, taskbarHostSharedPtr);
    if (!taskbarHostSharedPtr[0]) {
        Wh_Log(L"GetTaskbarXamlRoot: TaskbarHost shared_ptr is empty, aborting");
        if (taskbarHostSharedPtr[1] && Std_Ref_Decref_Original)
            Std_Ref_Decref_Original(taskbarHostSharedPtr[1]);
        return nullptr;
    }
    size_t taskbarElementIUnknownOffset = 0;
    bool frameHeightPatternRecognized = false;
#if defined(_M_X64) || defined(__x86_64__)
    {
        const BYTE* b = (const BYTE*)TaskbarHost_FrameHeight_Original;
        if (IsReadableMemoryRange(b, 8) &&
            b[0] == 0x48 && b[1] == 0x83 && b[2] == 0xEC && b[4] == 0x48 &&
            b[5] == 0x83 && b[6] == 0xC1 && b[7] <= 0x7F) {
            taskbarElementIUnknownOffset = b[7];
            frameHeightPatternRecognized = true;
        } else {
            Wh_Log(L"Unsupported TaskbarHost::FrameHeight pattern (x64)");
        }
    }
#elif defined(_M_ARM64) || defined(__aarch64__)
    {
        const DWORD* p = (const DWORD*)TaskbarHost_FrameHeight_Original;
        if (IsReadableMemoryRange(p, sizeof(DWORD) * 4) &&
            p[0] == 0xD503237F && (p[1] & 0xFFC07FFF) == 0xA9807BFD &&
            p[2] == 0x910003FD && (p[3] & 0xFFF00FE0) == 0xF8400C00) {
            taskbarElementIUnknownOffset = (p[3] >> 12) & 0xFF;
            frameHeightPatternRecognized = true;
        } else {
            Wh_Log(L"Unsupported TaskbarHost::FrameHeight pattern (arm64)");
        }
    }
#else
    Wh_Log(L"GetTaskbarXamlRoot: Unknown architecture, using default offset 0x10");
    taskbarElementIUnknownOffset = 0x10;
    frameHeightPatternRecognized = true;
#endif
    if (!frameHeightPatternRecognized ||
        !IsReadableMemoryRange(
            static_cast<BYTE*>(taskbarHostSharedPtr[0]) +
                taskbarElementIUnknownOffset,
            sizeof(IUnknown*))) {
        Wh_Log(L"GetTaskbarXamlRoot: FrameHeight pattern not recognized or offset unreadable, aborting");
        if (taskbarHostSharedPtr[1] && Std_Ref_Decref_Original)
            Std_Ref_Decref_Original(taskbarHostSharedPtr[1]);
        return nullptr;
    }
    auto* taskbarElementIUnknown =
        *(IUnknown**)((BYTE*)taskbarHostSharedPtr[0] +
                    taskbarElementIUnknownOffset);
    if (!taskbarElementIUnknown) {
        Wh_Log(L"GetTaskbarXamlRoot: taskbarElementIUnknown is null, aborting");
        if (taskbarHostSharedPtr[1] && Std_Ref_Decref_Original)
            Std_Ref_Decref_Original(taskbarHostSharedPtr[1]);
        return nullptr;
    }
    FrameworkElement taskbarElement{nullptr};
    HRESULT hr = taskbarElementIUnknown->QueryInterface(
        winrt::guid_of<FrameworkElement>(), winrt::put_abi(taskbarElement));
    auto result = taskbarElement ? taskbarElement.XamlRoot() : nullptr;
    if (taskbarHostSharedPtr[1] && Std_Ref_Decref_Original)
        Std_Ref_Decref_Original(taskbarHostSharedPtr[1]);
    return SUCCEEDED(hr) ? result : nullptr;
}
static const wchar_t* GetGlyphWithStyle(int cmd, const std::wstring& style, bool isPlaying = false) {
    bool isFluent = (style == L"fluent_outline" || style == L"fluent_filled");
    bool isFilled = (style == L"fluent_filled" || style == L"mdl2_filled");
    switch (cmd) {
        case 1:
            if (isFilled) return L"";
            return L"";
        case 2:
            if (isPlaying) {
                if (isFluent && isFilled) return L"";
                if (!isFluent && isFilled) return L"";
                return L"";
            } else {
                if (isFilled) return L"";
                return L"";
            }
        case 3:
            if (isFilled) return L"";
            return L"";
        case 5:
            if (isFilled) return L"";
            return L"";
        case 6:
            if (isFilled) return L"";
            return L"";
        case 7:
            return L"";
        case 8: {
            RepeatMode mode = g_repeatMode.load();
            switch (mode) {
                case RepeatMode::Off: return L"";
                case RepeatMode::All: return L"";
                case RepeatMode::One: return L"";
            }
        }
        case 9:
            return L"";
        case 10: return L"";
        case 11: return L"";
        case 12: return L"";
        case 13: return L"\uEB51";
    }
    return L"";
}
static const wchar_t* GetGlyph(int cmd, bool isPlaying = false) {
    return GetGlyphWithStyle(cmd, g_settings.iconStyle, isPlaying);
}
static TextBlock MakeIconText(const wchar_t* glyph, double sz, winrt::Windows::UI::Color c) {
    TextBlock t;
    t.Text(glyph);
    t.FontSize(sz);
    t.Foreground(MakeBrush(c));
    t.VerticalAlignment(VerticalAlignment::Center);
    t.HorizontalAlignment(HorizontalAlignment::Center);
    bool useFluent = (g_settings.iconStyle == L"fluent_outline" || g_settings.iconStyle == L"fluent_filled");
    try {
        if (useFluent) {
            t.FontFamily(FontFamily(L"Segoe Fluent Icons"));
        } else {
            t.FontFamily(FontFamily(L"Segoe MDL2 Assets"));
        }
    } catch (...) {
        try {
            t.FontFamily(FontFamily(L"Segoe MDL2 Assets"));
        } catch (...) {
            try {
                t.FontFamily(FontFamily(L"Segoe UI Symbol"));
            } catch (...) {}
        }
    }
    return t;
}
static Button MakeControlButton(int cmd, bool isPlaying, winrt::Windows::UI::Color iconColor) {
    Button btn;
    try {
        if ((cmd < 1 || cmd > 9) && cmd != 13) {
            Wh_Log(L"MakeControlButton: Invalid command %d, defaulting to 2 (play/pause)", cmd);
            cmd = 2;
        }
        btn.Width((double)g_settings.buttonSize);
        btn.Height((double)g_settings.buttonSize);
        btn.Padding({1,1,1,1});
        btn.CornerRadius({
            g_settings.buttonCornerRadiusTL,
            g_settings.buttonCornerRadiusTR,
            g_settings.buttonCornerRadiusBR,
            g_settings.buttonCornerRadiusBL
        });
        btn.BorderThickness({0,0,0,0});
        btn.VerticalAlignment(VerticalAlignment::Center);
        btn.HorizontalAlignment(HorizontalAlignment::Center);
        const wchar_t* glyph = GetGlyph(cmd, isPlaying);
        double opacity = 1.0;
        if (cmd == 7 && !g_shuffleEnabled.load()) {
            opacity = 0.4;
        }
        auto actualIconColor = cmd == 13
            ? winrt::Windows::UI::Color{0xFF, 0xFF, 0x4D, 0x67}
            : iconColor;
        auto iconText = MakeIconText(
            glyph,
            (double)g_settings.buttonIconSize + (cmd == 13 ? 2.0 : 0.0),
            actualIconColor);
        if (cmd == 13) {
            iconText.FontFamily(FontFamily(L"Segoe Fluent Icons"));
            iconText.Name(kHeartGlyphName);
            Grid heartIcon;
            heartIcon.Width((double)g_settings.buttonSize);
            heartIcon.Height((double)g_settings.buttonSize);
            heartIcon.HorizontalAlignment(HorizontalAlignment::Center);
            heartIcon.VerticalAlignment(VerticalAlignment::Center);
            heartIcon.Children().Append(iconText);

            TextBlock questionMark;
            questionMark.Name(kHeartQuestionName);
            questionMark.Text(L"?");
            questionMark.FontFamily(FontFamily(L"Segoe UI Variable Text"));
            questionMark.FontSize(std::max(
                7.0, (double)g_settings.buttonIconSize * 0.52));
            questionMark.FontWeight(
                winrt::Windows::UI::Text::FontWeights::SemiBold());
            questionMark.Foreground(MakeBrush(ButtonColor()));
            questionMark.HorizontalAlignment(HorizontalAlignment::Center);
            questionMark.VerticalAlignment(VerticalAlignment::Center);
            questionMark.Margin({0, -1, 0, 0});
            questionMark.Visibility(Visibility::Collapsed);
            heartIcon.Children().Append(questionMark);
            btn.Content(heartIcon);

            ToolTip toolTip;
            toolTip.Content(winrt::box_value(winrt::hstring(
                UiText(L"Like / Unlike", L"喜欢 / 取消喜欢"))));
            ToolTipService::SetToolTip(btn, toolTip);
        } else {
            btn.Content(winrt::box_value(iconText));
        }
        iconText.Opacity(opacity);
        btn.Click([cmd](auto const&, auto const&) {
            if (!g_unloading) {
                try {
                    SendMediaCommandAsync(cmd);
                } catch (...) {
                    Wh_Log(L"MakeControlButton: Exception in Click handler for cmd %d", cmd);
                }
            }
        });
        ApplyFluentMediaButtonStyle(btn);

        auto isPressed = std::make_shared<bool>(false);
        auto isHovered = std::make_shared<bool>(false);

        auto updateBtnVisualState = [btn, isPressed, isHovered]() {
            try {
                GoToCommonState(btn, IsHoverEffectEnabled(g_settings.mediaButtonsHoverEffectMode), *isPressed, *isHovered);
            } catch (...) {

            }
        };

        RunWhenButtonReady(btn, [btn, updateBtnVisualState]() {
            try {
                SetupMediaButtonCommonStates(btn);
                updateBtnVisualState();
            } catch (...) {
                Wh_Log(L"MakeControlButton: Exception in RunWhenButtonReady");
            }
        });

        btn.PointerEntered([isHovered, updateBtnVisualState](auto const&, auto const&) {
            *isHovered = true;
            updateBtnVisualState();
        });

        btn.PointerExited([isHovered, updateBtnVisualState](auto const&, auto const&) {
            *isHovered = false;
            updateBtnVisualState();
        });

        btn.AddHandler(UIElement::PointerPressedEvent(), winrt::box_value(
            winrt::Windows::UI::Xaml::Input::PointerEventHandler(
            [isPressed, updateBtnVisualState](auto const& sender, winrt::Windows::UI::Xaml::Input::PointerRoutedEventArgs const& e) {
            if (auto elem = sender.template try_as<UIElement>()) {
                elem.CapturePointer(e.Pointer());
            }
            *isPressed = true;
            updateBtnVisualState();
        })), true);

        btn.AddHandler(UIElement::PointerReleasedEvent(), winrt::box_value(
            winrt::Windows::UI::Xaml::Input::PointerEventHandler(
            [isPressed, isHovered, updateBtnVisualState](auto const& sender, winrt::Windows::UI::Xaml::Input::PointerRoutedEventArgs const& e) {
            bool actuallyHovered = false;

            if (auto elem = sender.template try_as<UIElement>()) {
                elem.ReleasePointerCapture(e.Pointer());
                try {
                    auto bounds = elem.RenderSize();
                    auto pos = e.GetCurrentPoint(elem).Position();
                    actuallyHovered = (pos.X >= 0 && pos.X <= bounds.Width && pos.Y >= 0 && pos.Y <= bounds.Height);
                } catch (...) {}
            }
            *isPressed = false;
            *isHovered = actuallyHovered;
            updateBtnVisualState();
            e.Handled(true);
        })), true);

        btn.PointerCanceled([isPressed, isHovered, updateBtnVisualState](auto const&, auto const&) {
            *isPressed = false;
            *isHovered = false;
            updateBtnVisualState();
        });

        btn.PointerCaptureLost([isPressed, isHovered, updateBtnVisualState](auto const& sender, winrt::Windows::UI::Xaml::Input::PointerRoutedEventArgs const& e) {
            if (auto elem = sender.template try_as<UIElement>()) {
                try {
                    auto bounds = elem.RenderSize();
                    auto pos = e.GetCurrentPoint(elem).Position();
                    *isHovered = (pos.X >= 0 && pos.X <= bounds.Width && pos.Y >= 0 && pos.Y <= bounds.Height);
                } catch (...) { *isHovered = false; }
            }
            updateBtnVisualState();
        });
    } catch (...) {
        Wh_Log(L"MakeControlButton: Exception while creating button");
    }
    return btn;
}
static void AddLayoutAnchorOverlay(Grid const& target, const wchar_t* name, winrt::Windows::UI::Color color) {
    if (!target || !g_settings.showLayoutAnchors) return;
    try {
        Grid overlay;
        overlay.Name(name);
        overlay.IsHitTestVisible(false);
        overlay.HorizontalAlignment(HorizontalAlignment::Stretch);
        overlay.VerticalAlignment(VerticalAlignment::Stretch);
        winrt::Windows::UI::Xaml::Shapes::Rectangle vLine;
        vLine.Width(1);
        vLine.Fill(MakeBrush(color));
        vLine.HorizontalAlignment(HorizontalAlignment::Center);
        vLine.VerticalAlignment(VerticalAlignment::Stretch);
        winrt::Windows::UI::Xaml::Shapes::Rectangle hLine;
        hLine.Height(1);
        hLine.Fill(MakeBrush(color));
        hLine.HorizontalAlignment(HorizontalAlignment::Stretch);
        hLine.VerticalAlignment(VerticalAlignment::Center);
        Border outline;
        outline.BorderBrush(MakeBrush(color));
        outline.BorderThickness({1,1,1,1});
        outline.HorizontalAlignment(HorizontalAlignment::Stretch);
        outline.VerticalAlignment(VerticalAlignment::Stretch);
        overlay.Children().Append(outline);
        overlay.Children().Append(vLine);
        overlay.Children().Append(hLine);
        Canvas::SetZIndex(overlay, 5000);
        target.Children().Append(overlay);
    } catch (...) {}
}
static MenuFlyoutItem MakeActionContextMenuItem(const wchar_t* glyph, const wchar_t* label,
                                                std::function<void()> onClick) {
    MenuFlyoutItem item;
    item.Text(label);
    item.IsEnabled(true);
    try {
        FontIcon icon;
        icon.Glyph(glyph);
        icon.FontSize((double)g_settings.buttonIconSize);
        bool useFluent = (ContextMenuIconStyle() == L"fluent_outline" || ContextMenuIconStyle() == L"fluent_filled");
        try {
            icon.FontFamily(FontFamily(useFluent ? L"Segoe Fluent Icons" : L"Segoe MDL2 Assets"));
        } catch (...) {
            try {
                icon.FontFamily(FontFamily(L"Segoe MDL2 Assets"));
            } catch (...) {}
        }
        icon.Foreground(MakeBrush(ContextMenuIconColor()));
        icon.Opacity(1.0);
        item.Icon(icon);
    } catch (...) {}
    item.Click([onClick](winrt::Windows::Foundation::IInspectable const&, RoutedEventArgs const&) {
        if (g_unloading) return;
        try {
            onClick();
        } catch (...) {}
    });
    return item;
}
static void OpenWindhawk() {
    SpawnTrackedWorker([]() {
        wchar_t expanded[MAX_PATH]{};
        ExpandEnvironmentStringsW(L"%ProgramFiles%\\Windhawk\\windhawk.exe", expanded, MAX_PATH);
        DWORD attrs = GetFileAttributesW(expanded);
        if (attrs != INVALID_FILE_ATTRIBUTES && !(attrs & FILE_ATTRIBUTE_DIRECTORY)) {
            ShellExecuteW(nullptr, L"open", expanded, nullptr, nullptr, SW_SHOWNORMAL);
        } else {
            ShellExecuteW(nullptr, L"open", L"windhawk.exe", nullptr, nullptr, SW_SHOWNORMAL);
        }
    });
}
static MenuFlyoutItem MakeMediaContextMenuItem(int cmd, const wchar_t* label, bool enabled, double iconOpacity) {
    MenuFlyoutItem item;
    item.Text(label);
    item.IsEnabled(enabled);
    try {
        FontIcon icon;
        icon.Glyph(GetGlyphWithStyle(cmd, ContextMenuIconStyle()));
        icon.FontSize((double)g_settings.buttonIconSize);
        bool useFluent = (ContextMenuIconStyle() == L"fluent_outline" || ContextMenuIconStyle() == L"fluent_filled");
        try {
            icon.FontFamily(FontFamily(useFluent ? L"Segoe Fluent Icons" : L"Segoe MDL2 Assets"));
        } catch (...) {
            try {
                icon.FontFamily(FontFamily(L"Segoe MDL2 Assets"));
            } catch (...) {}
        }
        icon.Foreground(MakeBrush(ContextMenuIconColor()));
        icon.Opacity(iconOpacity);
        item.Icon(icon);
    } catch (...) {}
    item.Click([cmd](winrt::Windows::Foundation::IInspectable const&, RoutedEventArgs const&) {
        if (g_unloading) return;
        try {
            SendMediaCommandAsync(cmd);
        } catch (...) {}
    });
    return item;
}
static void ShowMediaContextMenu(FrameworkElement const& target) {
    if (!target || g_unloading) return;
    try {
        bool canSkipPrevious = true, canSkipNext = true;
        bool canShuffle = true, canRepeat = true, canSeek = true;
        bool shuffleEnabled = false;
        {
            std::lock_guard<std::mutex> lk(g_mediaMtx);
            canSkipPrevious = g_media.canSkipPrevious;
            canSkipNext     = g_media.canSkipNext;
            canShuffle      = g_media.canShuffle;
            canRepeat       = g_media.canRepeat;
            canSeek         = g_media.canSeek;
            shuffleEnabled  = g_shuffleEnabled.load();
        }
        MenuFlyout menu;
        try {
            menu.Placement(Controls::Primitives::FlyoutPlacementMode::Top);
        } catch (...) {}
        RepeatMode curRepeat = g_repeatMode.load();
        auto makeRepeatSubItem = [&](int cmd, const wchar_t* label, const wchar_t* glyph, bool isCurrent) {
            MenuFlyoutItem ri;
            ri.Text(label);
            ri.IsEnabled(canRepeat);
            try {
                FontIcon ic;
                ic.Glyph(glyph);
                ic.FontSize((double)g_settings.buttonIconSize);
                bool useFluent = (ContextMenuIconStyle() == L"fluent_outline" || ContextMenuIconStyle() == L"fluent_filled");
                try {
                    ic.FontFamily(FontFamily(useFluent ? L"Segoe Fluent Icons" : L"Segoe MDL2 Assets"));
                } catch (...) {}
                ic.Foreground(MakeBrush(ContextMenuIconColor()));
                ic.Opacity(isCurrent ? 1.0 : 0.5);
                ri.Icon(ic);
            } catch (...) {}
            ri.Click([cmd](winrt::Windows::Foundation::IInspectable const&, RoutedEventArgs const&) {
                if (g_unloading) return;
                try {
                    SendMediaCommandAsync(cmd);
                } catch (...) {}
            });
            return ri;
        };
        bool addedSeparator = false;
        auto ensureSeparator = [&]() {
            if (!addedSeparator) {
                try {
                    Controls::MenuFlyoutSeparator sep;
                    menu.Items().Append(sep);
                } catch (...) {}
                addedSeparator = true;
            }
        };
        for (const auto& item : g_settings.contextMenuItems) {
            if (item == L"repeat") {
                if (g_settings.contextMenuRepeatStyle == L"toggle") {
                    const wchar_t* repeatLabel =
                        (curRepeat == RepeatMode::All)
                            ? UiText(L"Repeat all", L"列表循环")
                            : (curRepeat == RepeatMode::One)
                                  ? UiText(L"Repeat one", L"单曲循环")
                                  : UiText(L"Repeat off", L"关闭循环");
                    double repeatOpacity = canRepeat ? (curRepeat != RepeatMode::Off ? 1.0 : 0.4) : 0.4;
                    menu.Items().Append(MakeMediaContextMenuItem(8, repeatLabel, canRepeat, repeatOpacity));
                } else {
                    MenuFlyoutSubItem repeatSubMenu;
                    repeatSubMenu.Text(UiText(L"Repeat", L"循环模式"));
                    try {
                        FontIcon repeatIcon;
                        repeatIcon.Glyph(GetGlyphWithStyle(8, ContextMenuIconStyle()));
                        repeatIcon.FontSize((double)g_settings.buttonIconSize);
                        bool useFluent = (ContextMenuIconStyle() == L"fluent_outline" || ContextMenuIconStyle() == L"fluent_filled");
                        try {
                            repeatIcon.FontFamily(FontFamily(useFluent ? L"Segoe Fluent Icons" : L"Segoe MDL2 Assets"));
                        } catch (...) {}
                        repeatIcon.Foreground(MakeBrush(ContextMenuIconColor()));
                        repeatIcon.Opacity(canRepeat ? 1.0 : 0.4);
                        repeatSubMenu.Icon(repeatIcon);
                    } catch (...) {}
                    repeatSubMenu.IsEnabled(canRepeat);
                    repeatSubMenu.Items().Append(makeRepeatSubItem(10, UiText(L"Repeat off", L"关闭循环"), GetGlyphWithStyle(10, ContextMenuIconStyle()), curRepeat == RepeatMode::Off));
                    repeatSubMenu.Items().Append(makeRepeatSubItem(11, UiText(L"Repeat all", L"列表循环"), GetGlyphWithStyle(11, ContextMenuIconStyle()), curRepeat == RepeatMode::All));
                    repeatSubMenu.Items().Append(makeRepeatSubItem(12, UiText(L"Repeat one", L"单曲循环"), GetGlyphWithStyle(12, ContextMenuIconStyle()), curRepeat == RepeatMode::One));
                    menu.Items().Append(repeatSubMenu);
                }
            } else if (item == L"shuffle") {
                if (g_settings.contextMenuShuffleStyle == L"toggle") {
                    const wchar_t* shuffleLabel = shuffleEnabled
                        ? UiText(L"Shuffle on", L"随机播放：开")
                        : UiText(L"Shuffle off", L"随机播放：关");
                    double shuffleOpacity = canShuffle ? (shuffleEnabled ? 1.0 : 0.4) : 0.4;
                    menu.Items().Append(MakeMediaContextMenuItem(7, shuffleLabel, canShuffle, shuffleOpacity));
                } else {
                    MenuFlyoutSubItem shuffleSubMenu;
                    shuffleSubMenu.Text(UiText(L"Shuffle", L"随机播放"));
                    try {
                        FontIcon shuffleIcon;
                        shuffleIcon.Glyph(GetGlyphWithStyle(7, ContextMenuIconStyle()));
                        shuffleIcon.FontSize((double)g_settings.buttonIconSize);
                        bool useFluent = (ContextMenuIconStyle() == L"fluent_outline" || ContextMenuIconStyle() == L"fluent_filled");
                        try {
                            shuffleIcon.FontFamily(FontFamily(useFluent ? L"Segoe Fluent Icons" : L"Segoe MDL2 Assets"));
                        } catch (...) {}
                        shuffleIcon.Foreground(MakeBrush(ContextMenuIconColor()));
                        shuffleIcon.Opacity(canShuffle ? 1.0 : 0.4);
                        shuffleSubMenu.Icon(shuffleIcon);
                    } catch (...) {}
                    shuffleSubMenu.IsEnabled(canShuffle);
                    MenuFlyoutItem shuffleOffItem;
                    shuffleOffItem.Text(UiText(L"Shuffle off", L"关闭随机播放"));
                    shuffleOffItem.IsEnabled(canShuffle);
                    try {
                        FontIcon ic;
                        ic.Glyph(GetGlyphWithStyle(7, ContextMenuIconStyle()));
                        ic.FontSize((double)g_settings.buttonIconSize);
                        bool useFluent = (ContextMenuIconStyle() == L"fluent_outline" || ContextMenuIconStyle() == L"fluent_filled");
                        try { ic.FontFamily(FontFamily(useFluent ? L"Segoe Fluent Icons" : L"Segoe MDL2 Assets")); } catch (...) {}
                        ic.Foreground(MakeBrush(ContextMenuIconColor()));
                        ic.Opacity(!shuffleEnabled ? 1.0 : 0.5);
                        shuffleOffItem.Icon(ic);
                    } catch (...) {}
                    shuffleOffItem.Click([](winrt::Windows::Foundation::IInspectable const&, RoutedEventArgs const&) {
                        if (g_unloading) return;
                        try {
                            if (g_shuffleEnabled.load()) {
                                SendMediaCommandAsync(7);
                            }
                        } catch (...) {}
                    });
                    MenuFlyoutItem shuffleOnItem;
                    shuffleOnItem.Text(UiText(L"Shuffle on", L"开启随机播放"));
                    shuffleOnItem.IsEnabled(canShuffle);
                    try {
                        FontIcon ic;
                        ic.Glyph(GetGlyphWithStyle(7, ContextMenuIconStyle()));
                        ic.FontSize((double)g_settings.buttonIconSize);
                        bool useFluent = (ContextMenuIconStyle() == L"fluent_outline" || ContextMenuIconStyle() == L"fluent_filled");
                        try { ic.FontFamily(FontFamily(useFluent ? L"Segoe Fluent Icons" : L"Segoe MDL2 Assets")); } catch (...) {}
                        ic.Foreground(MakeBrush(ContextMenuIconColor()));
                        ic.Opacity(shuffleEnabled ? 1.0 : 0.5);
                        shuffleOnItem.Icon(ic);
                    } catch (...) {}
                    shuffleOnItem.Click([](winrt::Windows::Foundation::IInspectable const&, RoutedEventArgs const&) {
                        if (g_unloading) return;
                        try {
                            if (!g_shuffleEnabled.load()) {
                                SendMediaCommandAsync(7);
                            }
                        } catch (...) {}
                    });
                    shuffleSubMenu.Items().Append(shuffleOffItem);
                    shuffleSubMenu.Items().Append(shuffleOnItem);
                    menu.Items().Append(shuffleSubMenu);
                }
            } else if (item == L"forward") {
                menu.Items().Append(MakeMediaContextMenuItem(6, UiText(L"Forward 5s", L"快进 5 秒"), canSeek, canSeek ? 1.0 : 0.4));
            } else if (item == L"rewind") {
                menu.Items().Append(MakeMediaContextMenuItem(5, UiText(L"Rewind 5s", L"后退 5 秒"), canSeek, canSeek ? 1.0 : 0.4));
            } else if (item == L"next") {
                menu.Items().Append(MakeMediaContextMenuItem(3, UiText(L"Next Track", L"下一首"), canSkipNext, canSkipNext ? 1.0 : 0.4));
            } else if (item == L"prev") {
                menu.Items().Append(MakeMediaContextMenuItem(1, UiText(L"Previous Track", L"上一首"), canSkipPrevious, canSkipPrevious ? 1.0 : 0.4));
            } else if (item == L"switch_sessions") {
                menu.Items().Append(MakeMediaContextMenuItem(9, UiText(L"Switch Sessions", L"切换媒体会话"), g_sessionCount.load() > 1, g_sessionCount.load() > 1 ? 1.0 : 0.4));
            } else if (item == L"open_app") {
                menu.Items().Append(MakeActionContextMenuItem(L"\uE8A7", UiText(L"Open media app", L"打开媒体应用"), []() {
                    ExecuteMediaAction(L"open_app");
                }));
            }
        }
        if (g_settings.showRestartButton || g_settings.showOpenWindhawk) {
            ensureSeparator();
        }
        if (g_settings.showRestartButton) {
            menu.Items().Append(MakeActionContextMenuItem(L"\uE72C", UiText(L"Restart Player", L"重新加载播放器"), []() {
                try {
                    StopVizTimer();
                    g_vizCurrentlyVisible = false;
                    RemovePlayerGrid();
                    auto dispatcher = winrt::Windows::UI::Core::CoreWindow::GetForCurrentThread().Dispatcher();
                    dispatcher.RunAsync(winrt::Windows::UI::Core::CoreDispatcherPriority::Normal, [=]() {
                        try {
                            InjectPlayerGrid();
                        } catch (...) {
                            Wh_Log(L"Restart Player: Exception in InjectPlayerGrid");
                        }
                    });
                } catch (...) {
                    Wh_Log(L"Restart Player: exception");
                }
            }));
        }
        if (g_settings.showOpenWindhawk) {
            menu.Items().Append(MakeActionContextMenuItem(L"\uE713", UiText(L"Open Windhawk", L"打开 Windhawk"), []() {
                OpenWindhawk();
            }));
        }
        Controls::Primitives::FlyoutShowOptions flyoutOptions;
        flyoutOptions.Placement(Controls::Primitives::FlyoutPlacementMode::Top);
        flyoutOptions.ShowMode(Controls::Primitives::FlyoutShowMode::Standard);
        flyoutOptions.ExclusionRect(winrt::Windows::Foundation::Rect{
            0.f, 0.f,
            (float)target.ActualWidth(),
            (float)target.ActualHeight() + 8.f
        });

        menu.Closed([](auto const&, auto const&) {
            try {
                if (g_playerButtonStateUpdater) {
                    g_playerButtonStateUpdater();
                }
                if (g_playerGrid && !g_unloading && !g_applyingSettings) {
                    if (auto bgFe = FindChildByName(g_playerGrid, L"FluentMedia_Background")) {
                        if (auto bgBorder = bgFe.try_as<Border>()) {
                            auto& bgType = g_settings.backgroundType;
                            if (bgType == L"acrylic" || bgType == L"solid" || bgType == L"gradient" ||
                                bgType == L"mica" || bgType == L"mica_alt") {
                                bgBorder.Background(MakeBackgroundBrush());
                                bgBorder.Visibility(Visibility::Visible);
                                bgBorder.Opacity(1.0);
                            }
                        }
                    }
                }
            } catch (...) {
                Wh_Log(L"ShowMediaContextMenu: Closed handler exception");
            }
        });

        menu.ShowAt(target, flyoutOptions);
    } catch (...) {
        Wh_Log(L"ShowMediaContextMenu: exception");
    }
}

static Grid BuildPlayerGrid() {
    try {
        g_vizBars->clear();
        g_vizBrushes->clear();
        auto textClr = TextColor();
        auto artistClr = ArtistColor();
        auto buttonClr = ButtonColor();
        auto bgBrush = MakeBackgroundBrush();
        double phMin = (double)g_settings.playerMinHeight;
        double phMax = (double)g_settings.playerMaxHeight;
        bool showTaskbarTitle = true;
        int effectiveTextAreaMinWidth = g_settings.showNeteaseLyrics
            ? kTaskbarLyricsWidth
            : g_settings.textAreaMinWidth;
        int effectiveTextAreaMaxWidth = g_settings.showNeteaseLyrics
            ? kTaskbarLyricsWidth
            : g_settings.textAreaMaxWidth;
        bool taskbarTitleScrollingEnabled =
            g_settings.enableTitleScrolling && !g_settings.showNeteaseLyrics;
        bool hasTextOrButtons = showTaskbarTitle || g_settings.showTrackArtist || (g_settings.showMediaButtons && !g_mediaButtons.empty());
        Border backgroundBorder;
        backgroundBorder.Name(L"FluentMedia_Background");
        backgroundBorder.CornerRadius({
            g_settings.cornerRadiusTL,
            g_settings.cornerRadiusTR,
            g_settings.cornerRadiusBR,
            g_settings.cornerRadiusBL
        });
        backgroundBorder.HorizontalAlignment(HorizontalAlignment::Stretch);
        backgroundBorder.VerticalAlignment(VerticalAlignment::Stretch);
        backgroundBorder.IsHitTestVisible(false);
        backgroundBorder.Visibility(Visibility::Collapsed);
        if (phMin > 0) {
            backgroundBorder.MinHeight(phMin);
        }
        if (phMax > 0) {
            backgroundBorder.MaxHeight(phMax);
        }
        Button playerButton;
        playerButton.Name(L"FluentMedia_OuterBorder");
        playerButton.CornerRadius({
            g_settings.cornerRadiusTL,
            g_settings.cornerRadiusTR,
            g_settings.cornerRadiusBR,
            g_settings.cornerRadiusBL
        });
        playerButton.BorderThickness({0, 0, 0, 0});
        playerButton.UseSystemFocusVisuals(false);
        playerButton.IsHitTestVisible(false);
        playerButton.HorizontalAlignment(HorizontalAlignment::Stretch);
        playerButton.VerticalAlignment(VerticalAlignment::Stretch);
        if (phMin > 0) {
            playerButton.MinHeight(phMin);
        }
        if (phMax > 0) {
            playerButton.MaxHeight(phMax);
        }
        Grid chromeFill;
        if (phMin > 0) {
            chromeFill.MinHeight(phMin);
        }
        if (phMax > 0) {
            chromeFill.MaxHeight(phMax);
        }
        chromeFill.IsHitTestVisible(false);
        playerButton.Content(chromeFill);
        if (g_settings.showDebugBorders) {
            playerButton.BorderBrush(MakeBrush({0xFF, 0xFF, 0x00, 0x00}));
            playerButton.BorderThickness({2, 2, 2, 2});
        }
        Grid panel;
        panel.Name(kPanelGridName);
        panel.VerticalAlignment(VerticalAlignment::Center);
        panel.HorizontalAlignment(HorizontalAlignment::Stretch);
        if (hasTextOrButtons) {
            panel.Margin({4, 2, 4, 2});
        }
        AddLayoutAnchorOverlay(panel, L"FluentMedia_DebugPanelAnchors", {0xD0, 0x00, 0xFF, 0x00});
        if (g_settings.showDebugBorders) {
            Border panelDebugBorder;
            panelDebugBorder.BorderBrush(MakeBrush({0xFF, 0x00, 0xFF, 0x00}));
            panelDebugBorder.BorderThickness({1,1,1,1});
            panel.Children().Append(panelDebugBorder);
        }
        bool buttonsLeft = g_settings.mirrorLayout;
        bool albumArtLeft = !g_settings.mirrorLayout;
        bool hasText = showTaskbarTitle || g_settings.showTrackArtist;
        ColumnDefinition colFirst, colText, colSpacer, colLast;
        colFirst.Width({1.0, GridUnitType::Auto});
        if (hasText) {
            colText.Width({1.0, GridUnitType::Star});
        } else {
            colText.Width({0.0, GridUnitType::Pixel});
        }
        colSpacer.Width({0.0, GridUnitType::Pixel});
        colLast.Width({1.0, GridUnitType::Auto});
        panel.ColumnDefinitions().Append(colFirst);
        panel.ColumnDefinitions().Append(colText);
        panel.ColumnDefinitions().Append(colSpacer);
        panel.ColumnDefinitions().Append(colLast);
        Grid artContainer{nullptr};
        if (g_settings.showAlbumArt) {
            int iconSz = g_settings.appIconSize;
            artContainer = Grid();
            artContainer.Name(kArtContainerName);
            artContainer.VerticalAlignment(VerticalAlignment::Center);
            artContainer.HorizontalAlignment(HorizontalAlignment::Center);
            if (g_settings.albumArtMinWidth > 0) {
                artContainer.MinWidth((double)g_settings.albumArtMinWidth);
            }
            if (g_settings.albumArtMaxWidth > 0) {
                artContainer.MaxWidth((double)g_settings.albumArtMaxWidth);
            }
            if (g_settings.albumArtMinHeight > 0) {
                artContainer.MinHeight((double)g_settings.albumArtMinHeight);
            }
            if (g_settings.albumArtMaxHeight > 0) {
                artContainer.MaxHeight((double)g_settings.albumArtMaxHeight);
            }
            double artLeftMargin = (double)g_settings.albumArtLeftMargin;
            double artRightMargin = (double)g_settings.albumArtRightMargin;
            artContainer.Margin({artLeftMargin, 0, artRightMargin, 0});
            artContainer.Opacity(g_settings.albumArtOpacity / 100.0);
            artContainer.Background(MakeBrush({0x00,0x00,0x00,0x00}));
            AddLayoutAnchorOverlay(artContainer, L"FluentMedia_DebugArtAnchors", {0xD0, 0xFF, 0xFF, 0x00});
            if (g_settings.showDebugBorders) {
                Border artDebugBorder;
                artDebugBorder.BorderBrush(MakeBrush({0xFF, 0xFF, 0xFF, 0x00}));
                artDebugBorder.BorderThickness({2,2,2,2});
                artContainer.Children().Append(artDebugBorder);
            }
            winrt::Windows::UI::Xaml::Shapes::Rectangle placeholder;
            placeholder.Fill(MakeBrush({0x40,0x80,0x80,0x80}));
            double maxRadius = std::max({g_settings.albumArtCornerRadiusTL, g_settings.albumArtCornerRadiusTR,
                                        g_settings.albumArtCornerRadiusBR, g_settings.albumArtCornerRadiusBL});
            placeholder.RadiusX(maxRadius);
            placeholder.RadiusY(maxRadius);
            placeholder.HorizontalAlignment(HorizontalAlignment::Stretch);
            placeholder.VerticalAlignment(VerticalAlignment::Stretch);
            artContainer.Children().Append(placeholder);
            Border artBorder;
            artBorder.CornerRadius({
                g_settings.albumArtCornerRadiusTL,
                g_settings.albumArtCornerRadiusTR,
                g_settings.albumArtCornerRadiusBR,
                g_settings.albumArtCornerRadiusBL
            });
            artBorder.HorizontalAlignment(HorizontalAlignment::Stretch);
            artBorder.VerticalAlignment(VerticalAlignment::Stretch);
            Controls::Image artImage;
            artImage.Name(kArtImageName);
            bool isSquare = (g_settings.albumArtMinWidth == g_settings.albumArtMinHeight) &&
                        (g_settings.albumArtMaxWidth == g_settings.albumArtMaxHeight);
            artImage.Stretch(isSquare ? Stretch::Uniform : Stretch::Uniform);
            artImage.HorizontalAlignment(HorizontalAlignment::Center);
            artImage.VerticalAlignment(VerticalAlignment::Center);
            Grid artInnerGrid;
            artInnerGrid.HorizontalAlignment(HorizontalAlignment::Stretch);
            artInnerGrid.VerticalAlignment(VerticalAlignment::Stretch);
            artInnerGrid.Children().Append(artImage);
            {
                int launcherIconSize = std::max(16, std::min(
                    g_settings.albumArtMaxWidth > 0 ? g_settings.albumArtMaxWidth : 32,
                    g_settings.albumArtMaxHeight > 0 ? g_settings.albumArtMaxHeight : 32));
                auto appendLauncher = [&](const wchar_t* name,
                                          const wchar_t* executablePath,
                                          const wchar_t* toolTipText) {
                    Controls::Image launcherImage;
                    launcherImage.Name(name);
                    launcherImage.HorizontalAlignment(HorizontalAlignment::Center);
                    launcherImage.VerticalAlignment(VerticalAlignment::Center);
                    launcherImage.Stretch(Stretch::Uniform);
                    launcherImage.Visibility(Visibility::Collapsed);
                    auto launcherIconBytes = FetchLauncherIconBytes(
                        executablePath, launcherIconSize);
                    if (!launcherIconBytes.empty()) {
                        WriteableBitmap bitmap(launcherIconSize, launcherIconSize);
                        auto buffer = bitmap.PixelBuffer();
                        auto bufferByteAccess = buffer.as<
                            Windows::Storage::Streams::IBufferByteAccess>();
                        BYTE* pixels = nullptr;
                        bufferByteAccess->Buffer(&pixels);
                        size_t bytesNeeded =
                            (size_t)launcherIconSize * launcherIconSize * 4;
                        if (pixels && launcherIconBytes.size() >= bytesNeeded) {
                            for (size_t i = 0; i + 3 < bytesNeeded; i += 4) {
                                pixels[i + 0] = launcherIconBytes[i + 2];
                                pixels[i + 1] = launcherIconBytes[i + 1];
                                pixels[i + 2] = launcherIconBytes[i + 0];
                                pixels[i + 3] = launcherIconBytes[i + 3];
                            }
                            buffer.Length(static_cast<uint32_t>(bytesNeeded));
                            bitmap.Invalidate();
                            launcherImage.Source(bitmap);
                        }
                    }
                    ToolTip launcherToolTip;
                    launcherToolTip.Content(winrt::box_value(
                        winrt::hstring(toolTipText)));
                    ToolTipService::SetToolTip(launcherImage, launcherToolTip);
                    Canvas::SetZIndex(launcherImage, 7);
                    artInnerGrid.Children().Append(launcherImage);
                };
                appendLauncher(kNeteaseLauncherImageName,
                               g_settings.neteaseExecutablePath.c_str(),
                               UiText(L"NetEase Cloud Music isn't running; open it from the right-click menu",
                                      L"网易云音乐未运行，请从右键菜单打开"));
                appendLauncher(kTwilightLauncherImageName,
                               g_settings.twilightExecutablePath.c_str(),
                               UiText(L"Twilight Echo isn't running; open it from the right-click menu",
                                      L"Twilight Echo 未运行，请从右键菜单打开"));
            }
            {
                auto clipGeo = winrt::Windows::UI::Xaml::Media::RectangleGeometry();
                artInnerGrid.Clip(clipGeo);
                artInnerGrid.SizeChanged([clipGeo](
                    winrt::Windows::Foundation::IInspectable const& sender,
                    winrt::Windows::UI::Xaml::SizeChangedEventArgs const&) mutable {
                        try {
                            if (auto fe = sender.try_as<FrameworkElement>()) {
                                clipGeo.Rect({0, 0,
                                    (float)fe.ActualWidth(),
                                    (float)fe.ActualHeight()});
                            }
                        } catch (...) {}
                    });
            }
            artBorder.Child(artInnerGrid);
            artContainer.Children().Append(artBorder);
            Border artRing;
            artRing.CornerRadius({
                g_settings.albumArtCornerRadiusTL,
                g_settings.albumArtCornerRadiusTR,
                g_settings.albumArtCornerRadiusBR,
                g_settings.albumArtCornerRadiusBL
            });
            artRing.BorderThickness({1,1,1,1});
            artRing.BorderBrush(MakeBrush({0x25,0x80,0x80,0x80}));
            artContainer.Children().Append(artRing);
            if (g_settings.showAppIcon) {
                Grid iconOverlay;
                iconOverlay.VerticalAlignment(VerticalAlignment::Stretch);
                iconOverlay.HorizontalAlignment(HorizontalAlignment::Stretch);
                Controls::Image appIconImage;
                appIconImage.Name(kAppIconImageName);
                appIconImage.Width(iconSz);
                appIconImage.Height(iconSz);
                appIconImage.Stretch(Stretch::UniformToFill);
                appIconImage.Visibility(Visibility::Collapsed);
                const auto& corner = g_settings.appIconCorner;
                double margin_right  = 0, margin_bottom = 0;
                double margin_left   = 0, margin_top    = 0;
                HorizontalAlignment ha = HorizontalAlignment::Right;
                VerticalAlignment   va = VerticalAlignment::Bottom;
                if (corner == L"top_left") {
                    ha = HorizontalAlignment::Left;
                    va = VerticalAlignment::Top;
                } else if (corner == L"top_right") {
                    ha = HorizontalAlignment::Right;
                    va = VerticalAlignment::Top;
                } else if (corner == L"bottom_left") {
                    ha = HorizontalAlignment::Left;
                    va = VerticalAlignment::Bottom;
                } else {
                    ha = HorizontalAlignment::Right;
                    va = VerticalAlignment::Bottom;
                }
                appIconImage.HorizontalAlignment(ha);
                appIconImage.VerticalAlignment(va);
                appIconImage.Margin({margin_left, margin_top, margin_right, margin_bottom});
                iconOverlay.Children().Append(appIconImage);
                Canvas::SetZIndex(iconOverlay, 15);
                artContainer.Children().Append(iconOverlay);
            }
            if (g_settings.disableAlbumArtClick && !g_settings.showNeteaseLyrics) {
                artContainer.IsHitTestVisible(false);
            } else {
                artContainer.PointerPressed([](auto const& sender, winrt::Windows::UI::Xaml::Input::PointerRoutedEventArgs const& e) mutable {
                    if (auto elem = sender.template try_as<UIElement>()) {
                        elem.CapturePointer(e.Pointer());
                    }
                    e.Handled(true);
                });
                auto artDblClickLastTime = std::make_shared<ULONGLONG>(0);
                auto artDblClickLastKind = std::make_shared<winrt::Windows::UI::Input::PointerUpdateKind>(
                    winrt::Windows::UI::Input::PointerUpdateKind::Other);
                artContainer.PointerReleased([artDblClickLastTime, artDblClickLastKind](auto const& sender, winrt::Windows::UI::Xaml::Input::PointerRoutedEventArgs const& e) mutable {
                    bool actuallyHovered = false;
                    if (auto elem = sender.template try_as<UIElement>()) {
                        elem.ReleasePointerCapture(e.Pointer());
                        try {
                            auto pointerPoint = e.GetCurrentPoint(elem);
                            auto bounds = elem.RenderSize();
                            auto pos = pointerPoint.Position();
                            actuallyHovered = (pos.X >= 0 && pos.X <= bounds.Width && pos.Y >= 0 && pos.Y <= bounds.Height);
                        } catch (...) { actuallyHovered = false; }
                    }
                    if (g_unloading) return;
                    if (actuallyHovered) {
                        auto kind = e.GetCurrentPoint(nullptr).Properties().PointerUpdateKind();
                        auto fe = sender.template try_as<FrameworkElement>();
                        ULONGLONG now = GetTickCount64();
                        UINT dblClickMs = GetDoubleClickTime();
                        bool isDouble = (kind == *artDblClickLastKind) &&
                                        (now - *artDblClickLastTime) <= dblClickMs;
                        *artDblClickLastTime = isDouble ? 0 : now;
                        *artDblClickLastKind = kind;
                        using Kind = winrt::Windows::UI::Input::PointerUpdateKind;
                        if (kind == Kind::LeftButtonReleased) {
                            bool hasSelectedPlayer = HasSelectedPlayerSession();
                            if (isDouble && hasSelectedPlayer) {
                                g_albumLeftClickGeneration.fetch_add(1);
                                const auto& action = g_settings.disableAlbumArtClick
                                    ? g_settings.playerLeftDoubleClick
                                    : g_settings.albumArtLeftDoubleClick;
                                if (action != L"open_app") {
                                    ExecuteMediaAction(action, fe);
                                }
                            }
                        } else if (kind == Kind::RightButtonReleased) {
                            ShowMediaContextMenu(fe);
                        } else if (kind == Kind::MiddleButtonReleased) {
                            if (isDouble) ExecuteMediaAction(g_settings.albumArtMiddleDoubleClick, fe);
                            else          ExecuteMediaAction(g_settings.albumArtMiddleClick, fe);
                        }
                    }
                    e.Handled(true);
                });
                artContainer.PointerWheelChanged([](winrt::Windows::Foundation::IInspectable const&, winrt::Windows::UI::Xaml::Input::PointerRoutedEventArgs const& e) {
                    if (g_unloading) return;
                    auto action = g_settings.albumArtWheelAction;
                    if (action == L"none") return;
                    auto props = e.GetCurrentPoint(nullptr).Properties();
                    int delta = props.MouseWheelDelta();
                    if (action == L"switch_tracks") {
                        if (delta != 0 && ShouldHandleTrackWheelAction()) {
                            SendMediaCommandAsync(delta > 0 ? 1 : 3);
                        }
                    } else if (action == L"switch_tracks_inverted") {
                        if (delta != 0 && ShouldHandleTrackWheelAction()) {
                            SendMediaCommandAsync(delta > 0 ? 3 : 1);
                        }
                    } else if (action == L"switch_sessions") {
                        if (delta != 0) SwitchMediaSession();
                    } else if (action == L"system_sound") {
                        SpawnTrackedWorker([delta]() { ChangeSystemVolume(delta > 0); });
                    } else if (action == L"app_sound") {
                        SpawnTrackedWorker([delta]() {
                            winrt::init_apartment(winrt::apartment_type::multi_threaded);
                            std::wstring aumid;
                            {
                                GlobalSystemMediaTransportControlsSession sessionCopy{nullptr};
                                {
                                    std::lock_guard<std::mutex> lk(g_sessionMtx);
                                    sessionCopy = g_currentSession;
                                }
                                if (sessionCopy) {
                                    try {
                                        aumid = std::wstring(sessionCopy.SourceAppUserModelId());
                                    } catch (...) {}
                                }
                            }
                            if (!aumid.empty()) {
                                float volumeDelta = (delta > 0) ? 0.02f : -0.02f;
                                AdjustAppVolumeByAUMID(aumid, volumeDelta);
                            }
                            winrt::uninit_apartment();
                        });
                    }
                    e.Handled(true);
                });
            }
            artContainer.Tag(winrt::box_value(winrt::hstring(L"FluentMediaArtContainer")));
            if (albumArtLeft) {
                Grid::SetColumn(artContainer, 0);
            } else {
                Grid::SetColumn(artContainer, 3);
            }
            panel.Children().Append(artContainer);
        }
        if (artContainer) {
            Button sourceSwitchButton;
            sourceSwitchButton.Name(kSourceSwitchBtnName);
            sourceSwitchButton.Width(16);
            sourceSwitchButton.Height(16);
            sourceSwitchButton.MinWidth(0);
            sourceSwitchButton.MinHeight(0);
            sourceSwitchButton.MaxWidth(16);
            sourceSwitchButton.MaxHeight(16);
            sourceSwitchButton.Padding({0, 0, 0, 0});
            sourceSwitchButton.Margin({0, 0, 0, 0});
            sourceSwitchButton.CornerRadius({8, 8, 8, 8});
            sourceSwitchButton.BorderThickness({1, 1, 1, 1});
            sourceSwitchButton.BorderBrush(
                MakeBrush({0xA0, 0xFF, 0xFF, 0xFF}));
            sourceSwitchButton.Background(
                MakeBrush({0xD8, 0x20, 0x20, 0x20}));
            sourceSwitchButton.HorizontalAlignment(HorizontalAlignment::Left);
            sourceSwitchButton.VerticalAlignment(VerticalAlignment::Top);
            sourceSwitchButton.HorizontalContentAlignment(
                HorizontalAlignment::Center);
            sourceSwitchButton.VerticalContentAlignment(
                VerticalAlignment::Center);
            sourceSwitchButton.UseSystemFocusVisuals(false);
            sourceSwitchButton.IsTabStop(false);
            sourceSwitchButton.Opacity(0.0);
            sourceSwitchButton.IsHitTestVisible(false);

            TextBlock sourceSwitchText;
            sourceSwitchText.Text(
                g_selectedPlayer.load() == PlayerKind::Netease ? L"暮" : L"云");
            sourceSwitchText.FontFamily(
                Media::FontFamily(L"Microsoft YaHei UI"));
            sourceSwitchText.FontSize(8.5);
            sourceSwitchText.Foreground(
                MakeBrush({0xFF, 0xFF, 0xFF, 0xFF}));
            sourceSwitchText.HorizontalAlignment(HorizontalAlignment::Center);
            sourceSwitchText.VerticalAlignment(VerticalAlignment::Center);
            sourceSwitchButton.Content(sourceSwitchText);

            sourceSwitchButton.Click([](auto const&, auto const&) {
                if (g_unloading) return;
                SwitchSelectedPlayer();
                ApplyTaskbarCompactState();
            });
            sourceSwitchButton.AddHandler(
                UIElement::PointerPressedEvent(),
                winrt::box_value(
                    winrt::Windows::UI::Xaml::Input::PointerEventHandler(
                        [](auto const&, PointerRoutedEventArgs const& e) {
                            e.Handled(true);
                        })),
                true);
            sourceSwitchButton.AddHandler(
                UIElement::PointerReleasedEvent(),
                winrt::box_value(
                    winrt::Windows::UI::Xaml::Input::PointerEventHandler(
                        [](auto const&, PointerRoutedEventArgs const& e) {
                            e.Handled(true);
                        })),
                true);
            Canvas::SetZIndex(sourceSwitchButton, 31);
            Grid::SetColumn(sourceSwitchButton, albumArtLeft ? 0 : 3);
            panel.Children().Append(sourceSwitchButton);
        }
        if (g_settings.showNeteaseLyrics && artContainer) {
            Button lyricsToggleButton;
            lyricsToggleButton.Name(kLyricsToggleBtnName);
            lyricsToggleButton.Width(16);
            lyricsToggleButton.Height(16);
            lyricsToggleButton.MinWidth(0);
            lyricsToggleButton.MinHeight(0);
            lyricsToggleButton.MaxWidth(16);
            lyricsToggleButton.MaxHeight(16);
            lyricsToggleButton.Padding({0, 0, 0, 0});
            lyricsToggleButton.Margin({0, 0, 0, 0});
            lyricsToggleButton.CornerRadius({8, 8, 8, 8});
            lyricsToggleButton.BorderThickness({1, 1, 1, 1});
            lyricsToggleButton.BorderBrush(MakeBrush({0xA0, 0xFF, 0xFF, 0xFF}));
            lyricsToggleButton.Background(MakeBrush({0xD8, 0x20, 0x20, 0x20}));
            lyricsToggleButton.HorizontalAlignment(HorizontalAlignment::Right);
            lyricsToggleButton.VerticalAlignment(VerticalAlignment::Bottom);
            lyricsToggleButton.HorizontalContentAlignment(HorizontalAlignment::Center);
            lyricsToggleButton.VerticalContentAlignment(VerticalAlignment::Center);
            lyricsToggleButton.UseSystemFocusVisuals(false);
            lyricsToggleButton.IsTabStop(false);
            lyricsToggleButton.Opacity(0.0);

            TextBlock lyricsToggleText;
            lyricsToggleText.Text(L"词");
            lyricsToggleText.FontFamily(Media::FontFamily(L"Microsoft YaHei UI"));
            lyricsToggleText.FontSize(9.0);
            lyricsToggleText.Foreground(MakeBrush({0xFF, 0xFF, 0xFF, 0xFF}));
            lyricsToggleText.HorizontalAlignment(HorizontalAlignment::Center);
            lyricsToggleText.VerticalAlignment(VerticalAlignment::Center);
            lyricsToggleButton.Content(lyricsToggleText);

            ToolTip lyricsToggleToolTip;
            lyricsToggleToolTip.Content(winrt::box_value(
                winrt::hstring(UiText(
                    L"Show or hide lyrics and playback controls",
                    L"显示或隐藏歌词和播放按钮"))));
            ToolTipService::SetToolTip(lyricsToggleButton, lyricsToggleToolTip);

            lyricsToggleButton.Click([](auto const&, auto const&) {
                if (g_unloading) return;
                bool hasMedia = false;
                {
                    std::lock_guard<std::mutex> lock(g_mediaMtx);
                    hasMedia = g_media.hasMedia;
                }
                bool hasSession = HasSelectedPlayerSession();
                if (hasMedia && hasSession) ToggleTaskbarExpanded();
            });
            lyricsToggleButton.AddHandler(
                UIElement::PointerPressedEvent(),
                winrt::box_value(winrt::Windows::UI::Xaml::Input::PointerEventHandler(
                    [](auto const&, winrt::Windows::UI::Xaml::Input::PointerRoutedEventArgs const& e) {
                        e.Handled(true);
                    })),
                true);
            lyricsToggleButton.AddHandler(
                UIElement::PointerReleasedEvent(),
                winrt::box_value(winrt::Windows::UI::Xaml::Input::PointerEventHandler(
                    [](auto const&, winrt::Windows::UI::Xaml::Input::PointerRoutedEventArgs const& e) {
                        e.Handled(true);
                    })),
                true);

            Canvas::SetZIndex(lyricsToggleButton, 30);
            Grid::SetColumn(lyricsToggleButton, albumArtLeft ? 0 : 3);
            panel.Children().Append(lyricsToggleButton);
        }
        if (showTaskbarTitle || g_settings.showTrackArtist) {
            Border textContainer;
            textContainer.Name(kTextContainerName);
            textContainer.Background(MakeBrush({0x00,0x00,0x00,0x00}));
            textContainer.VerticalAlignment(VerticalAlignment::Center);
            if (albumArtLeft) {
                textContainer.HorizontalAlignment(HorizontalAlignment::Left);
            } else {
                textContainer.HorizontalAlignment(HorizontalAlignment::Right);
            }
            if (effectiveTextAreaMinWidth > 0) {
                textContainer.MinWidth((double)effectiveTextAreaMinWidth);
            }
            if (effectiveTextAreaMaxWidth > 0) {
                textContainer.MaxWidth((double)effectiveTextAreaMaxWidth);
            }
            if (g_settings.textAreaMinHeight > 0) {
                textContainer.MinHeight((double)g_settings.textAreaMinHeight);
            }
            if (g_settings.textAreaMaxHeight > 0) {
                textContainer.MaxHeight((double)g_settings.textAreaMaxHeight);
            }
            double leftMargin = (double)g_settings.textAreaLeftMargin;
            double rightMargin = (double)g_settings.textAreaRightMargin;
            textContainer.Margin({leftMargin, 0, rightMargin, 0});
            if (g_settings.showDebugBorders) {
                textContainer.BorderBrush(MakeBrush({0xFF, 0x00, 0xFF, 0xFF}));
                textContainer.BorderThickness({1,1,1,1});
            }
            StackPanel textStack;
            textStack.Name(kTextStackName);
            textStack.Orientation(Orientation::Vertical);
            textStack.VerticalAlignment(VerticalAlignment::Center);
            if (g_settings.showNeteaseLyrics || g_settings.enableTitleScrolling ||
                g_settings.enableArtistScrolling) {
                textStack.HorizontalAlignment(HorizontalAlignment::Stretch);
            } else {
                textStack.HorizontalAlignment(g_settings.mirrorLayout ? HorizontalAlignment::Right : HorizontalAlignment::Left);
            }
            textStack.Spacing((double)g_settings.textSpacing);
            if (showTaskbarTitle || g_settings.showTrackArtist) {
                TextBlock titleBlock{nullptr};
                TextBlock artistBlock{nullptr};
                if (showTaskbarTitle) {
                    titleBlock = TextBlock();
                    titleBlock.Name(kTitleBlockName);
                    titleBlock.FontSize((double)g_settings.titleFontSize);
                    std::wstring titleFontName = g_settings.titleFont.empty() ? g_settings.titleFontFamily : g_settings.titleFont;
                    if (!titleFontName.empty()) {
                        try {
                            titleBlock.FontFamily(Media::FontFamily(titleFontName));
                        } catch (...) {}
                    }
                    if (!g_settings.titleFontWeight.empty()) {
                        try {
                            auto fontWeight = Markup::XamlBindingHelper::ConvertValue(
                                winrt::Windows::UI::Xaml::Interop::TypeName{
                                    winrt::hstring{L"Windows.UI.Text.FontWeight"},
                                    winrt::Windows::UI::Xaml::Interop::TypeKind::Metadata
                                },
                                winrt::box_value(g_settings.titleFontWeight))
                                .as<winrt::Windows::UI::Text::FontWeight>();
                            titleBlock.FontWeight(fontWeight);
                        } catch (...) {}
                    }
                    if (!g_settings.titleFontStyle.empty()) {
                        try {
                            auto fontStyle = Markup::XamlBindingHelper::ConvertValue(
                                winrt::Windows::UI::Xaml::Interop::TypeName{
                                    winrt::hstring{L"Windows.UI.Text.FontStyle"},
                                    winrt::Windows::UI::Xaml::Interop::TypeKind::Metadata
                                },
                                winrt::box_value(g_settings.titleFontStyle))
                                .as<winrt::Windows::UI::Text::FontStyle>();
                            titleBlock.FontStyle(fontStyle);
                        } catch (...) {}
                    }
                    if (g_settings.titleCharacterSpacing != 0) {
                        titleBlock.CharacterSpacing(g_settings.titleCharacterSpacing);
                    }
                    titleBlock.Foreground(MakeBrush(textClr));
                    titleBlock.TextWrapping(TextWrapping::NoWrap);
                    titleBlock.TextTrimming(TextTrimming::CharacterEllipsis);
                    titleBlock.TextAlignment(g_settings.showNeteaseLyrics
                        ? TextAlignment::Center
                        : (g_settings.mirrorLayout
                               ? TextAlignment::Right
                               : TextAlignment::Left));
                    if (g_settings.showNeteaseLyrics &&
                        effectiveTextAreaMaxWidth > 0) {
                        titleBlock.MaxLines(2);
                        titleBlock.Width((double)effectiveTextAreaMaxWidth);
                        titleBlock.HorizontalAlignment(HorizontalAlignment::Stretch);
                    }
                }
                if (g_settings.showTrackArtist) {
                    artistBlock = TextBlock();
                    artistBlock.Name(kArtistBlockName);
                    artistBlock.FontSize((double)g_settings.artistFontSize);
                    std::wstring artistFontName = g_settings.artistFont.empty() ? g_settings.artistFontFamily : g_settings.artistFont;
                    if (!artistFontName.empty()) {
                        try {
                            artistBlock.FontFamily(Media::FontFamily(artistFontName));
                        } catch (...) {}
                    }
                    if (!g_settings.artistFontWeight.empty()) {
                        try {
                            auto fontWeight = Markup::XamlBindingHelper::ConvertValue(
                                winrt::Windows::UI::Xaml::Interop::TypeName{
                                    winrt::hstring{L"Windows.UI.Text.FontWeight"},
                                    winrt::Windows::UI::Xaml::Interop::TypeKind::Metadata
                                },
                                winrt::box_value(g_settings.artistFontWeight))
                                .as<winrt::Windows::UI::Text::FontWeight>();
                            artistBlock.FontWeight(fontWeight);
                        } catch (...) {}
                    }
                    if (!g_settings.artistFontStyle.empty()) {
                        try {
                            auto fontStyle = Markup::XamlBindingHelper::ConvertValue(
                                winrt::Windows::UI::Xaml::Interop::TypeName{
                                    winrt::hstring{L"Windows.UI.Text.FontStyle"},
                                    winrt::Windows::UI::Xaml::Interop::TypeKind::Metadata
                                },
                                winrt::box_value(g_settings.artistFontStyle))
                                .as<winrt::Windows::UI::Text::FontStyle>();
                            artistBlock.FontStyle(fontStyle);
                        } catch (...) {}
                    }
                    if (g_settings.artistCharacterSpacing != 0) {
                        artistBlock.CharacterSpacing(g_settings.artistCharacterSpacing);
                    }
                    artistBlock.Foreground(MakeBrush(artistClr));
                    artistBlock.TextWrapping(TextWrapping::NoWrap);
                    artistBlock.TextTrimming(TextTrimming::CharacterEllipsis);
                    artistBlock.TextAlignment(g_settings.mirrorLayout ? TextAlignment::Right : TextAlignment::Left);
                }
                auto MakeScrollView = [&](Canvas& scrollView, TextBlock& block, const wchar_t* viewName, const wchar_t* blockName, const wchar_t* cloneName) {
                    scrollView = Canvas();
                    scrollView.Name(viewName);
                    scrollView.VerticalAlignment(VerticalAlignment::Center);
                    scrollView.HorizontalAlignment(g_settings.showNeteaseLyrics
                        ? HorizontalAlignment::Center
                        : (g_settings.mirrorLayout
                               ? HorizontalAlignment::Right
                               : HorizontalAlignment::Left));
                    scrollView.Width(100.0);
                    block.Name(blockName);
                    block.TextTrimming(TextTrimming::None);
                    block.TextWrapping(TextWrapping::NoWrap);
                    Canvas::SetLeft(block, 0.0);
                    Canvas::SetTop(block, 0.0);
                    scrollView.Children().Append(block);
                    if (g_settings.scrollMode == L"loop") {
                        TextBlock clone;
                        clone.Name(cloneName);
                        clone.Text(block.Text());
                        clone.FontSize(block.FontSize());
                        clone.FontFamily(block.FontFamily());
                        clone.FontWeight(block.FontWeight());
                        clone.FontStyle(block.FontStyle());
                        clone.CharacterSpacing(block.CharacterSpacing());
                        clone.Foreground(block.Foreground());
                        clone.TextWrapping(TextWrapping::NoWrap);
                        clone.TextTrimming(TextTrimming::None);
                        clone.TextAlignment(block.TextAlignment());
                        Canvas::SetLeft(clone, 9999.0);
                        Canvas::SetTop(clone, 0.0);
                        scrollView.Children().Append(clone);
                    }
                    auto geo = winrt::Windows::UI::Xaml::Media::RectangleGeometry();
                    scrollView.Clip(geo);
                    block.SizeChanged([scrollView, geo](winrt::Windows::Foundation::IInspectable const&, SizeChangedEventArgs const& e) mutable {
                        try {
                            double h = e.NewSize().Height;
                            if (h < 1.0) h = 16.0;
                            double w = scrollView.Width();
                            scrollView.Height(h);
                            geo.Rect({0, 0, (float)w, (float)h});
                        } catch (...) {}
                    });
                };
                if (g_settings.swapTitleArtist) {
                    if (artistBlock) {
                        if (g_settings.enableArtistScrolling) {
                            Canvas artistScrollView;
                            MakeScrollView(artistScrollView, artistBlock, kArtistScrollViewName, kArtistBlockName, kArtistCloneName);
                            textStack.Children().Append(artistScrollView);
                        } else {
                            if (g_settings.enableTitleScrolling && effectiveTextAreaMaxWidth > 0) {
                                artistBlock.MaxWidth((double)effectiveTextAreaMaxWidth);
                            }
                            textStack.Children().Append(artistBlock);
                        }
                    }
                    if (titleBlock) {
                        if (taskbarTitleScrollingEnabled) {
                            Canvas titleScrollView;
                            MakeScrollView(titleScrollView, titleBlock, kTitleScrollViewName, kTitleBlockName, kTitleCloneName);
                            textStack.Children().Append(titleScrollView);
                        } else {
                            if (g_settings.enableArtistScrolling && effectiveTextAreaMaxWidth > 0) {
                                titleBlock.MaxWidth((double)effectiveTextAreaMaxWidth);
                            }
                            textStack.Children().Append(titleBlock);
                        }
                    }
                } else {
                    if (titleBlock) {
                        if (taskbarTitleScrollingEnabled) {
                            Canvas titleScrollView;
                            MakeScrollView(titleScrollView, titleBlock, kTitleScrollViewName, kTitleBlockName, kTitleCloneName);
                            textStack.Children().Append(titleScrollView);
                        } else {
                            if (g_settings.enableArtistScrolling && effectiveTextAreaMaxWidth > 0) {
                                titleBlock.MaxWidth((double)effectiveTextAreaMaxWidth);
                            }
                            textStack.Children().Append(titleBlock);
                        }
                    }
                    if (artistBlock) {
                        if (g_settings.enableArtistScrolling) {
                            Canvas artistScrollView;
                            MakeScrollView(artistScrollView, artistBlock, kArtistScrollViewName, kArtistBlockName, kArtistCloneName);
                            textStack.Children().Append(artistScrollView);
                        } else {
                            if (g_settings.enableTitleScrolling && effectiveTextAreaMaxWidth > 0) {
                                artistBlock.MaxWidth((double)effectiveTextAreaMaxWidth);
                            }
                            textStack.Children().Append(artistBlock);
                        }
                    }
                }
            }
            textContainer.Child(textStack);
            Grid::SetColumn(textContainer, 1);
            panel.Children().Append(textContainer);
        }
        if (g_settings.showMediaButtons) {
            StackPanel ctrlPanel;
            ctrlPanel.Name(kControlsPanelName);
            ctrlPanel.Orientation(Orientation::Horizontal);
            ctrlPanel.Spacing((double)g_settings.buttonSpacing);
            ctrlPanel.VerticalAlignment(VerticalAlignment::Center);
            ctrlPanel.HorizontalAlignment(buttonsLeft ? HorizontalAlignment::Left : HorizontalAlignment::Right);
            std::vector<MediaButtonConfig> currentButtons;
            try {
                std::lock_guard<std::mutex> lock(g_mediaButtonsMutex);
                if (!g_mediaButtons.empty()) {
                    currentButtons = g_mediaButtons;
                } else {
                    currentButtons = {
                        {MediaButtonType::Heart, 13},
                        {MediaButtonType::Previous, 1},
                        {MediaButtonType::PlayPause, 2},
                        {MediaButtonType::Next, 3}
                    };
                }
            } catch (const std::exception& e) {
                Wh_Log(L"CreatePlayerGrid: Exception accessing media buttons (std::exception), using defaults");
                currentButtons = {
                    {MediaButtonType::Heart, 13},
                    {MediaButtonType::Previous, 1},
                    {MediaButtonType::PlayPause, 2},
                    {MediaButtonType::Next, 3}
                };
            } catch (...) {
                Wh_Log(L"CreatePlayerGrid: Unknown exception accessing media buttons, using defaults");
                currentButtons = {
                    {MediaButtonType::Heart, 13},
                    {MediaButtonType::Previous, 1},
                    {MediaButtonType::PlayPause, 2},
                    {MediaButtonType::Next, 3}
                };
            }
            bool hasButtons = !currentButtons.empty();
            if (hasButtons) {
                try {
                    ctrlPanel.Margin({(double)g_settings.mediaButtonsLeftMargin, 0, (double)g_settings.mediaButtonsRightMargin, 0});
                } catch (...) {
                    Wh_Log(L"CreatePlayerGrid: Exception setting control panel margin");
                }
            }
            if (g_settings.showDebugBorders) {
                try {
                    Border ctrlDebugBorder;
                    ctrlDebugBorder.BorderBrush(MakeBrush({0xFF, 0xFF, 0x00, 0xFF}));
                    ctrlDebugBorder.BorderThickness({1,1,1,1});
                    Grid::SetColumn(ctrlDebugBorder, buttonsLeft ? 0 : 3);
                    panel.Children().Append(ctrlDebugBorder);
                } catch (...) {
                    Wh_Log(L"CreatePlayerGrid: Exception creating debug border");
                }
            }
            for (size_t i = 0; i < currentButtons.size(); i++) {
                try {
                    const auto& btnCfg = currentButtons[i];
                    auto btn = MakeControlButton(btnCfg.cmd, false, buttonClr);
                    if (!btn) {
                        Wh_Log(L"CreatePlayerGrid: MakeControlButton returned null for button %zu", i);
                        continue;
                    }
                    switch (btnCfg.type) {
                        case MediaButtonType::Previous:
                            btn.Name(kPrevBtnName);
                            break;
                        case MediaButtonType::PlayPause:
                            btn.Name(kPlayBtnName);
                            break;
                        case MediaButtonType::Next:
                            btn.Name(kNextBtnName);
                            break;
                        case MediaButtonType::Rewind5s:
                            btn.Name(kRewindBtnName);
                            break;
                        case MediaButtonType::Forward5s:
                            btn.Name(kForwardBtnName);
                            break;
                        case MediaButtonType::Shuffle:
                            btn.Name(kShuffleBtnName);
                            break;
                        case MediaButtonType::Repeat:
                            btn.Name(kRepeatBtnName);
                            break;
                        case MediaButtonType::SwitchSessions:
                            btn.Name(kSwitchSessionsBtnName);
                            break;
                        case MediaButtonType::Heart:
                            btn.Name(kHeartBtnName);
                            break;
                        default:
                            Wh_Log(L"CreatePlayerGrid: Unknown button type %d", static_cast<int>(btnCfg.type));
                            continue;
                    }
                    ctrlPanel.Children().Append(btn);
                } catch (const winrt::hresult_error& e) {
                    Wh_Log(L"CreatePlayerGrid: WinRT exception creating button %zu: 0x%08X", i, static_cast<uint32_t>(e.code()));
                } catch (const std::exception& e) {
                    Wh_Log(L"CreatePlayerGrid: std::exception creating button %zu", i);
                } catch (...) {
                    Wh_Log(L"CreatePlayerGrid: Unknown exception creating button %zu, skipping", i);
                }
            }
            if (buttonsLeft) {
                Grid::SetColumn(ctrlPanel, 0);
            } else {
                Grid::SetColumn(ctrlPanel, 3);
            }
            if (hasButtons) {
                panel.Children().Append(ctrlPanel);
            }
        }
        if (g_settings.vizEnabled) {
            try {
                auto vizEl = BuildVisualizerElement();
                if (vizEl) {
                    bool left = (g_settings.vizPosition == L"left");
                    if (g_settings.mirrorLayout) left = !left;
                    ColumnDefinition vcol;
                    vcol.Width({1.0, GridUnitType::Auto});
                    if (left) {
                        panel.ColumnDefinitions().InsertAt(0, vcol);
                        auto kids = panel.Children();
                        for (uint32_t k = 0; k < kids.Size(); k++) {
                            if (auto fe = kids.GetAt(k).try_as<FrameworkElement>())
                                Grid::SetColumn(fe, Grid::GetColumn(fe) + 1);
                        }
                        Grid::SetColumn(vizEl, 0);
                    } else {
                        panel.ColumnDefinitions().Append(vcol);
                        Grid::SetColumn(vizEl, (int)panel.ColumnDefinitions().Size() - 1);
                    }
                    panel.Children().Append(vizEl);
                }
            } catch (...) {
                Wh_Log(L"BuildPlayerGrid: Exception adding inline visualizer");
            }
        }
        Grid wrapper;
        wrapper.Name(kGridName);
        wrapper.VerticalAlignment(g_settings.fullHeightHitArea ? VerticalAlignment::Stretch : VerticalAlignment::Center);
        wrapper.HorizontalAlignment(HorizontalAlignment::Left);
        AddLayoutAnchorOverlay(wrapper, L"FluentMedia_DebugPlayerAnchors", {0xD0, 0xFF, 0x50, 0x50});
        try {
            if (g_settings.enableSmoothPositionAnimation) {
                TransitionCollection transitions;
                RepositionThemeTransition marginTransition;
                transitions.Append(marginTransition);
                wrapper.Transitions(transitions);
            }
        } catch (...) {}
        if (hasTextOrButtons && g_settings.playerMinWidth > 0) {
            wrapper.MinWidth((double)g_settings.playerMinWidth);
        }
        if (g_settings.playerMaxWidth > 0) {
            wrapper.MaxWidth((double)g_settings.playerMaxWidth);
        }

        wrapper.Background(MakeBrush({0x00, 0, 0, 0}));

        Canvas::SetZIndex(backgroundBorder, 0);
        Canvas::SetZIndex(playerButton, 1);
        Canvas::SetZIndex(panel, 2);
        wrapper.Children().Append(backgroundBorder);
        wrapper.Children().Append(playerButton);
        wrapper.Children().Append(panel);
        ApplyFluentMediaButtonStyle(playerButton);
        if (!g_settings.showDebugBorders) {
            playerButton.BorderThickness({1, 1, 1, 1});
        }
        auto isPressed = std::make_shared<bool>(false);
        auto isHovered = std::make_shared<bool>(false);
        auto playerNormalBg = MakeBackgroundBrush();
        auto updatePlayerVisualState = [playerButton, playerNormalBg, isPressed, isHovered]() {
            ApplyPlayerButtonState(playerButton, playerNormalBg, *isHovered, *isPressed);
        };
        g_playerButtonStateUpdater = updatePlayerVisualState;
        RunWhenButtonReady(playerButton, [playerButton, playerNormalBg]() {
            try {
                SetupPlayerCommonStates(playerButton, playerNormalBg);
                GoToCommonState(playerButton, IsHoverEffectEnabled(g_settings.playerHoverEffectMode), false, false);
            } catch (...) {}
        });
        wrapper.Loaded([playerButton, playerNormalBg](auto const&, auto const&) {
            try {
                SetupPlayerCommonStates(playerButton, playerNormalBg);
                GoToCommonState(playerButton, IsHoverEffectEnabled(g_settings.playerHoverEffectMode), false, false);
            } catch (...) {}
        });
        auto setPlayerHoverState =
            [isHovered, updatePlayerVisualState](bool hovered) {
            bool globalChanged =
                g_taskbarWrapperHovered.exchange(hovered) != hovered;
            *isHovered = hovered;
            updatePlayerVisualState();
            if (globalChanged) {
                ApplyTaskbarCompactState();
                DispatchMediaUpdate();
            }
        };
        auto endPlayerHover =
            [wrapper, setPlayerHoverState](
                PointerRoutedEventArgs const& e) {
            bool stillInside = false;
            try {
                auto pos = e.GetCurrentPoint(wrapper).Position();
                auto bounds = wrapper.RenderSize();
                stillInside = pos.X >= 0 && pos.X < bounds.Width && pos.Y >= 0 && pos.Y < bounds.Height;
            } catch (...) {}
            if (!stillInside) setPlayerHoverState(false);
        };
        auto attachPlayerHover =
            [&](UIElement const& element) {
                if (!element) return;
                element.AddHandler(
                    UIElement::PointerEnteredEvent(),
                    winrt::box_value(PointerEventHandler(
                        [setPlayerHoverState](auto const&,
                                           PointerRoutedEventArgs const&) {
                            setPlayerHoverState(true);
                        })),
                    true);
                element.AddHandler(
                    UIElement::PointerExitedEvent(),
                    winrt::box_value(PointerEventHandler(
                        [endPlayerHover](auto const&,
                                         PointerRoutedEventArgs const& e) {
                            endPlayerHover(e);
                        })),
                    true);
            };
        attachPlayerHover(wrapper);
        attachPlayerHover(panel);
        if (auto textContainer =
                FindChildByName(wrapper, kTextContainerName)) {
            attachPlayerHover(textContainer);
        }
    wrapper.PointerPressed([isPressed, updatePlayerVisualState](auto const& sender, winrt::Windows::UI::Xaml::Input::PointerRoutedEventArgs const& e) mutable {
        if (auto elem = sender.template try_as<UIElement>()) {
            elem.CapturePointer(e.Pointer());
        }
        *isPressed = true;
        updatePlayerVisualState();
    });
    auto wrapperDblClickLastTime = std::make_shared<ULONGLONG>(0);
    auto wrapperDblClickLastKind = std::make_shared<winrt::Windows::UI::Input::PointerUpdateKind>(
        winrt::Windows::UI::Input::PointerUpdateKind::Other);
    wrapper.PointerReleased([isPressed, setPlayerHoverState, wrapperDblClickLastTime, wrapperDblClickLastKind](auto const& sender, winrt::Windows::UI::Xaml::Input::PointerRoutedEventArgs const& e) mutable {
        *isPressed = false;
        bool actuallyHovered = false;
        if (auto elem = sender.template try_as<UIElement>()) {
            elem.ReleasePointerCapture(e.Pointer());
            try {
                auto pointerPoint = e.GetCurrentPoint(elem);
                auto bounds = elem.RenderSize();
                auto pos = pointerPoint.Position();
                actuallyHovered = (pos.X >= 0 && pos.X < bounds.Width && pos.Y >= 0 && pos.Y < bounds.Height);
            } catch (...) { actuallyHovered = false; }
        }
        setPlayerHoverState(actuallyHovered);
        if (g_unloading || e.Handled()) return;
        if (actuallyHovered) {
            auto kind = e.GetCurrentPoint(nullptr).Properties().PointerUpdateKind();
            auto fe = sender.template try_as<FrameworkElement>();
            ULONGLONG now = GetTickCount64();
            UINT dblClickMs = GetDoubleClickTime();
            bool isDouble = (kind == *wrapperDblClickLastKind) &&
                            (now - *wrapperDblClickLastTime) <= dblClickMs;
            *wrapperDblClickLastTime = isDouble ? 0 : now;
            *wrapperDblClickLastKind = kind;
            using Kind = winrt::Windows::UI::Input::PointerUpdateKind;
            if (kind == Kind::LeftButtonReleased) {
                if (isDouble && g_settings.playerLeftDoubleClick != L"open_app") {
                    ExecuteMediaAction(g_settings.playerLeftDoubleClick, fe);
                }
            } else if (kind == Kind::RightButtonReleased) {
                ShowMediaContextMenu(fe);
            } else if (kind == Kind::MiddleButtonReleased) {
                if (isDouble) ExecuteMediaAction(g_settings.playerMiddleDoubleClick, fe);
                else          ExecuteMediaAction(g_settings.playerMiddleClick, fe);
            }
        }
    });
    wrapper.PointerCanceled([isPressed, setPlayerHoverState](auto const&, auto const&) mutable {
        *isPressed = false;
        setPlayerHoverState(false);
    });
    wrapper.PointerCaptureLost([isPressed, setPlayerHoverState](auto const& sender, winrt::Windows::UI::Xaml::Input::PointerRoutedEventArgs const& e) mutable {
        *isPressed = false;
        bool actuallyHovered = false;
        if (auto elem = sender.template try_as<UIElement>()) {
            try {
                auto pointerPoint = e.GetCurrentPoint(elem);
                auto bounds = elem.RenderSize();
                auto pos = pointerPoint.Position();
                actuallyHovered = (pos.X >= 0 && pos.X < bounds.Width && pos.Y >= 0 && pos.Y < bounds.Height);
            } catch (...) { actuallyHovered = false; }
        }
        setPlayerHoverState(actuallyHovered);
    });
        wrapper.Tag(winrt::box_value(winrt::hstring(L"FluentMediaBarWrapper")));
        wrapper.PointerWheelChanged([](auto const&, winrt::Windows::UI::Xaml::Input::PointerRoutedEventArgs const& e) {
            if (g_unloading) return;
            auto action = g_settings.playerWheelAction;
            if (action == L"none") return;
            auto props = e.GetCurrentPoint(nullptr).Properties();
            int delta = props.MouseWheelDelta();
            if (action == L"switch_tracks") {
                if (delta != 0 && ShouldHandleTrackWheelAction()) {
                    SendMediaCommandAsync(delta > 0 ? 1 : 3);
                }
            } else if (action == L"switch_tracks_inverted") {
                if (delta != 0 && ShouldHandleTrackWheelAction()) {
                    SendMediaCommandAsync(delta > 0 ? 3 : 1);
                }
            } else if (action == L"switch_sessions") {
                if (delta != 0) SwitchMediaSession();
            } else if (action == L"system_sound") {
                SpawnTrackedWorker([delta]() { ChangeSystemVolume(delta > 0); });
            } else if (action == L"app_sound") {
                SpawnTrackedWorker([delta]() {
                    winrt::init_apartment(winrt::apartment_type::multi_threaded);
                    std::wstring aumid;
                    {
                        GlobalSystemMediaTransportControlsSession sessionCopy{nullptr};
                        {
                            std::lock_guard<std::mutex> lk(g_sessionMtx);
                            sessionCopy = g_currentSession;
                        }
                        if (sessionCopy) {
                            try {
                                aumid = std::wstring(sessionCopy.SourceAppUserModelId());
                            } catch (...) {}
                        }
                    }
                    if (!aumid.empty()) {
                        float volumeDelta = (delta > 0) ? 0.02f : -0.02f;
                        AdjustAppVolumeByAUMID(aumid, volumeDelta);
                    }
                    winrt::uninit_apartment();
                });
            }
            e.Handled(true);
        });
        try {
            winrt::Windows::UI::Xaml::Interop::TypeName gridType;
            gridType.Name = L"Windows.UI.Xaml.Controls.Grid";
            gridType.Kind = winrt::Windows::UI::Xaml::Interop::TypeKind::Metadata;
            winrt::Windows::UI::Xaml::Style wrapperStyle(gridType);
            wrapper.Style(wrapperStyle);
        } catch (...) {}
        try {
            ToolTip tt;
            TextBlock ttText;
            ttText.TextWrapping(TextWrapping::Wrap);
            ttText.MaxWidth(300);
            tt.Content(ttText);
            ToolTipService::SetToolTip(wrapper, tt);
            g_playerToolTip = tt;
        } catch (...) {}
        return wrapper;
    } catch (...) {
        Wh_Log(L"BuildPlayerGrid: Exception occurred");
        return nullptr;
    }
}
struct InjectionTarget {
    Grid grid;
    int  insertCol = 0;
};
static int RemovePlayerGridChildren(Grid const& targetGrid) {
    if (!targetGrid) return -1;
    int firstCol = -1;
    for (int i = (int)targetGrid.Children().Size() - 1; i >= 0; --i) {
        auto fe = targetGrid.Children().GetAt(i).try_as<FrameworkElement>();
        if (fe && fe.Name() == kGridName) {
            if (firstCol < 0) firstCol = Grid::GetColumn(fe);
            try { targetGrid.Children().RemoveAt(i); } catch (...) {}
        }
    }
    return firstCol;
}
static void RemoveAnchorDebugOverlays(Grid const& targetGrid) {
    if (!targetGrid) return;
    for (int i = (int)targetGrid.Children().Size() - 1; i >= 0; --i) {
        auto fe = targetGrid.Children().GetAt(i).try_as<FrameworkElement>();
        if (fe && fe.Name() == kAnchorOverlayName) {
            try { targetGrid.Children().RemoveAt(i); } catch (...) {}
        }
    }
}
static void UpdateAnchorDebugOverlay(Grid const& targetGrid, FrameworkElement const& targetElem) {
    if (!targetGrid) return;
    if (!g_settings.showLayoutAnchors || !targetElem) {
        RemoveAnchorDebugOverlays(targetGrid);
        return;
    }
    try {
        Border overlay{nullptr};
        for (uint32_t i = 0; i < targetGrid.Children().Size(); ++i) {
            auto fe = targetGrid.Children().GetAt(i).try_as<FrameworkElement>();
            if (fe && fe.Name() == kAnchorOverlayName) {
                overlay = fe.try_as<Border>();
                break;
            }
        }
        if (!overlay) {
            overlay = Border();
            overlay.Name(kAnchorOverlayName);
            overlay.IsHitTestVisible(false);
            overlay.BorderBrush(MakeBrush({0xE0, 0x00, 0xA2, 0xFF}));
            overlay.BorderThickness({2,2,2,2});
            overlay.Background(MakeBrush({0x20, 0x00, 0xA2, 0xFF}));
            overlay.HorizontalAlignment(HorizontalAlignment::Left);
            overlay.VerticalAlignment(VerticalAlignment::Top);
            Canvas::SetZIndex(overlay, 5001);
            targetGrid.Children().Append(overlay);
        }
        auto transform = targetElem.TransformToVisual(targetGrid);
        auto point = transform.TransformPoint({0, 0});
        overlay.Width(std::max(1.0, targetElem.ActualWidth()));
        overlay.Height(std::max(1.0, targetElem.ActualHeight()));
        overlay.Margin({point.X, point.Y, 0, 0});
        overlay.Visibility(Visibility::Visible);
    } catch (...) {
        RemoveAnchorDebugOverlays(targetGrid);
    }
}
static const wchar_t* const kStartButtonNames[] = {
    L"StartButton",
    L"StartMenuButton",
    L"StartMenuLaunchButton",
    L"LaunchListButton",
};
static Grid FindTaskbarRootGrid(FrameworkElement const& root) {
    FrameworkElement taskbarFrame = nullptr;
    int count = VisualTreeHelper::GetChildrenCount(root);
    for (int i = 0; i < count; i++) {
        auto c = VisualTreeHelper::GetChild(root, i).try_as<FrameworkElement>();
        if (c) {
            auto className = winrt::get_class_name(c);
            if (className == L"Taskbar.TaskbarFrame") {
                taskbarFrame = c;
                break;
            }
        }
    }
    if (!taskbarFrame) {
        return nullptr;
    }
    auto rootGrid = FindChildByName(taskbarFrame, L"RootGrid");
    return rootGrid ? rootGrid.try_as<Grid>() : nullptr;
}
static FrameworkElement FindElementInRepeater(FrameworkElement const& repeater, const wchar_t* const* names, int nameCount) {
    if (!repeater) return nullptr;
    int childCount = VisualTreeHelper::GetChildrenCount(repeater);
    for (int i = 0; i < childCount; i++) {
        auto child = VisualTreeHelper::GetChild(repeater, i).try_as<FrameworkElement>();
        if (!child) continue;
        for (int j = 0; j < nameCount; j++) {
            if (child.Name() == names[j]) return child;
        }
    }
    for (int i = 0; i < childCount; i++) {
        auto child = VisualTreeHelper::GetChild(repeater, i).try_as<FrameworkElement>();
        if (!child) continue;
        int subChildCount = VisualTreeHelper::GetChildrenCount(child);
        for (int k = 0; k < subChildCount; k++) {
            auto subChild = VisualTreeHelper::GetChild(child, k).try_as<FrameworkElement>();
            if (!subChild) continue;
            for (int j = 0; j < nameCount; j++) {
                if (subChild.Name() == names[j]) return subChild;
            }
        }
    }
    return nullptr;
}
static FrameworkElement FindElementByClassName(FrameworkElement const& parent, const wchar_t* className) {
    if (!parent) return nullptr;
    int childCount = VisualTreeHelper::GetChildrenCount(parent);
    for (int i = 0; i < childCount; i++) {
        auto child = VisualTreeHelper::GetChild(parent, i).try_as<FrameworkElement>();
        if (!child) continue;
        auto childClassName = winrt::get_class_name(child);
        if (childClassName == className) return child;
    }
    return nullptr;
}
static FrameworkElement FindNthElementByClassName(FrameworkElement const& parent, const wchar_t* className, int index) {
    if (!parent) return nullptr;
    int foundCount = 0;
    int childCount = VisualTreeHelper::GetChildrenCount(parent);
    for (int i = 0; i < childCount; i++) {
        auto child = VisualTreeHelper::GetChild(parent, i).try_as<FrameworkElement>();
        if (!child) continue;
        auto childClassName = winrt::get_class_name(child);
        if (childClassName == className) {
            if (foundCount == index) return child;
            foundCount++;
        }
    }
    return nullptr;
}
static FrameworkElement FindChildByClassName(FrameworkElement const& parent, const wchar_t* className, int depth = 32) {
    if (!parent || depth <= 0) return nullptr;
    int childCount = VisualTreeHelper::GetChildrenCount(parent);
    for (int i = 0; i < childCount; i++) {
        auto child = VisualTreeHelper::GetChild(parent, i).try_as<FrameworkElement>();
        if (!child) continue;
        if (winrt::get_class_name(child) == className) return child;
        if (auto found = FindChildByClassName(child, className, depth - 1)) return found;
    }
    return nullptr;
}
static double FindLeftmostVisibleChildX(FrameworkElement const& parent, UIElement const& relativeTo, int depth = 3) {
    if (!parent || !relativeTo || depth < 0) return -1.0;
    double leftmost = -1.0;
    int childCount = VisualTreeHelper::GetChildrenCount(parent);
    for (int i = 0; i < childCount; i++) {
        auto child = VisualTreeHelper::GetChild(parent, i).try_as<FrameworkElement>();
        if (!child) continue;
        try {
            if (child.Visibility() == Visibility::Visible && child.ActualWidth() > 1.0) {
                auto transform = child.TransformToVisual(relativeTo);
                auto point = transform.TransformPoint({0, 0});
                if (point.X >= 0.0 && (leftmost < 0.0 || point.X < leftmost))
                    leftmost = point.X;
            }
        } catch (...) {}
        double nested = FindLeftmostVisibleChildX(child, relativeTo, depth - 1);
        if (nested >= 0.0 && (leftmost < 0.0 || nested < leftmost))
            leftmost = nested;
    }
    return leftmost;
}
static FrameworkElement FindTrayElement(FrameworkElement const& trayGrid, FrameworkElement const& root, const wchar_t* name) {
    auto elem = FindChildByName(trayGrid, name);
    if (!elem) elem = FindChildByName(root, name);
    return elem;
}
static bool IsStartButtonModActive(FrameworkElement const& root) {
    try {
        auto rootGrid = FindTaskbarRootGrid(root);
        if (!rootGrid) return false;
        auto repeater = FindChildByName(rootGrid, L"TaskbarFrameRepeater");
        if (!repeater) return false;
        static const wchar_t* kStartNames[] = {L"StartButton"};
        auto startButton = FindElementInRepeater(repeater, kStartNames, 1);
        if (!startButton) return false;
        auto margin = startButton.Margin();
        return margin.Right < -10.0;
    } catch (...) {
        return false;
    }
}
static double GetStartButtonAdjustment(FrameworkElement const& root) {
    try {
        auto rootGrid = FindTaskbarRootGrid(root);
        if (!rootGrid) return 0.0;
        auto repeater = FindChildByName(rootGrid, L"TaskbarFrameRepeater");
        if (!repeater) return 0.0;
        static const wchar_t* kStartNames[] = {L"StartButton"};
        auto startButton = FindElementInRepeater(repeater, kStartNames, 1);
        if (!startButton) return 0.0;
        return startButton.ActualWidth();
    } catch (...) {
        return 0.0;
    }
}

static bool SyncTrackedPlayerLayout(Grid const& targetGrid) {
    if (!targetGrid || !g_playerGrid || !g_trackedElement ||
        !g_hasTrackedElementOriginalMargin || g_unloading) {
        return false;
    }

    try {
        UpdateAnchorDebugOverlay(targetGrid, g_trackedElement);
        bool isVisible = g_playerGrid.Visibility() == Visibility::Visible;
        double width = isVisible ? g_playerGrid.ActualWidth() : 0.0;
        double desiredGap = isVisible
            ? width + g_settings.playerMarginLeft + g_settings.playerMarginRight
            : 0.0;
        auto baseMargin = g_trackedElementOriginalMargin;
        auto margin = baseMargin;
        auto currentMargin = g_trackedElement.Margin();
        bool changedMargin = false;

        if (g_trackPosition == L"far_left") {
            try {
                double originalLeft = g_hasTrackedElementOriginalMargin
                    ? g_trackedElementOriginalMargin.Left
                    : 0.0;
                double currentLeftmost =
                    FindLeftmostVisibleChildX(g_trackedElement, targetGrid, 4);
                double naturalLeft = currentLeftmost >= 0.0
                    ? currentLeftmost - (currentMargin.Left - originalLeft)
                    : desiredGap;
                double requiredExtra = std::max(0.0, desiredGap - naturalLeft);
                double targetLeft = originalLeft + requiredExtra;
                if (std::abs(currentMargin.Left - targetLeft) > 1.0 ||
                    std::abs(currentMargin.Right - margin.Right) > 1.0) {
                    margin.Left = targetLeft;
                    changedMargin = true;
                }
            } catch (...) {
                if (g_hasTrackedElementOriginalMargin &&
                    (std::abs(currentMargin.Left - margin.Left) > 1.0 ||
                     std::abs(currentMargin.Right - margin.Right) > 1.0)) {
                    changedMargin = true;
                }
            }
        } else if (g_trackPosition == L"left") {
            double targetLeft = baseMargin.Left + desiredGap;
            if (std::abs(currentMargin.Left - targetLeft) > 1.0) {
                margin.Left = targetLeft;
                changedMargin = true;
            }
        } else {
            double targetRight = baseMargin.Right + desiredGap;
            if (std::abs(currentMargin.Right - targetRight) > 1.0) {
                margin.Right = targetRight;
                changedMargin = true;
            }
        }

        if (!g_taskbarLayoutTransitionInProgress &&
            g_taskbarExpanded.load() &&
            g_trackPosition == L"left" &&
            g_settings.position == L"taskbar_left_start" &&
            g_trackedElement.ActualWidth() > 1.0) {
            double currentRootWidth = targetGrid.ActualWidth();
            if (currentRootWidth > 1.0 &&
                (g_trackedRootGridWidth <= 1.0 ||
                 std::abs(currentRootWidth - g_trackedRootGridWidth) > 1.0)) {
                g_trackedStartButtonModActive = false;
                g_trackedStartButtonOffset = 0.0;
                auto transform = g_trackedElement.TransformToVisual(targetGrid);
                auto point = transform.TransformPoint({0, 0});
                double originalLeft = g_hasTrackedElementOriginalMargin
                    ? g_trackedElementOriginalMargin.Left
                    : 0.0;
                g_trackedPlayerAnchorLeft =
                    point.X - (currentMargin.Left - originalLeft) +
                    g_settings.playerMarginLeft +
                    g_trackedStartButtonOffset;
                g_hasTrackedPlayerAnchorLeft = true;
                g_trackedRootGridWidth = currentRootWidth;
            }
        }

        bool useStableLeftAnchor =
            isVisible && g_trackPosition == L"left" &&
            g_hasTrackedPlayerAnchorLeft &&
            g_taskbarExpanded.load();
        if (useStableLeftAnchor) {
            auto playerMargin = g_playerGrid.Margin();
            if (std::abs(playerMargin.Left - g_trackedPlayerAnchorLeft) > 1.0) {
                g_playerGrid.Margin({g_trackedPlayerAnchorLeft, 0, 0, 0});
            }
        }

        if (changedMargin) {
            g_trackedElement.Margin(margin);
            return false;
        }

        if (isVisible && !useStableLeftAnchor) {
            auto transform = g_trackedElement.TransformToVisual(targetGrid);
            auto point = transform.TransformPoint({0, 0});
            double leftPos = point.X;
            if (g_trackPosition == L"far_left") {
                leftPos = g_settings.playerMarginLeft;
            } else if (g_trackPosition == L"left") {
                leftPos = point.X - desiredGap + g_settings.playerMarginLeft;
                if (g_trackedStartButtonModActive &&
                    g_trackedStartButtonOffset > 0.0) {
                    leftPos += g_trackedStartButtonOffset;
                }
            } else {
                leftPos = point.X + g_trackedElement.ActualWidth() +
                          g_settings.playerMarginLeft;
            }

            auto playerMargin = g_playerGrid.Margin();
            if (std::abs(playerMargin.Left - leftPos) > 1.0) {
                g_playerGrid.Margin({leftPos, 0, 0, 0});
            }
        }
        return true;
    } catch (...) {
        g_trackedElement = nullptr;
        g_hasTrackedElementOriginalMargin = false;
        g_hasTrackedPlayerAnchorLeft = false;
        return false;
    }
}

static InjectionTarget ResolveInjectionTarget(
    FrameworkElement const& root,
    std::wstring_view position)
{
    auto trayFrame = FindChildByName(root, L"SystemTrayFrameGrid");
    if (auto trayGrid = trayFrame ? trayFrame.try_as<Grid>() : nullptr) {
        int col = -1;
        if      (position == L"tray_right")
            col = (int)trayGrid.ColumnDefinitions().Size();
        else if (position == L"tray_left")
            col = 0;
        else if (position == L"tray_before_clock") {
            auto clockBtn = FindChildByName(trayGrid, L"NotificationCenterButton");
            if (!clockBtn) clockBtn = FindChildByName(root, L"NotificationCenterButton");
            col = clockBtn ? Grid::GetColumn(clockBtn) : -1;
        }
        else if (position == L"tray_after_clock") {
            auto showDesktop = FindChildByName(trayGrid, L"ShowDesktopStack");
            if (!showDesktop) showDesktop = FindChildByName(root, L"ShowDesktopStack");
            col = showDesktop ? Grid::GetColumn(showDesktop) : -1;
        }
        else if (position == L"tray_before_omni_left") {
            auto omniBtn = FindChildByName(trayGrid, L"ControlCenterButton");
            if (!omniBtn) omniBtn = FindChildByName(root, L"ControlCenterButton");
            col = omniBtn ? Grid::GetColumn(omniBtn) : -1;
        }
        else if (position == L"tray_before_omni_right") {
            auto omniBtn = FindChildByName(trayGrid, L"ControlCenterButton");
            if (!omniBtn) omniBtn = FindChildByName(root, L"ControlCenterButton");
            if (omniBtn) col = Grid::GetColumn(omniBtn) + 1;
            else col = -1;
        }
        else if (position == L"tray_language_left") {
            auto languageBtn = FindTrayElement(trayGrid, root, L"NonActivatableStack");
            col = languageBtn ? Grid::GetColumn(languageBtn) : -1;
        }
        else if (position == L"tray_language_right") {
            auto languageBtn = FindTrayElement(trayGrid, root, L"NonActivatableStack");
            col = languageBtn ? Grid::GetColumn(languageBtn) + 1 : -1;
        }
        else if (position == L"tray_hidden_icons_left") {
            auto hiddenIconsBtn = FindTrayElement(trayGrid, root, L"NotifyIconStack");
            col = hiddenIconsBtn ? Grid::GetColumn(hiddenIconsBtn) : -1;
        }
        else if (position == L"tray_hidden_icons_right") {
            auto hiddenIconsBtn = FindTrayElement(trayGrid, root, L"NotifyIconStack");
            col = hiddenIconsBtn ? Grid::GetColumn(hiddenIconsBtn) + 1 : -1;
        }
        else if (position == L"tray_icons_left") {
            auto trayIcons = FindTrayElement(trayGrid, root, L"NotificationAreaIcons");
            col = trayIcons ? Grid::GetColumn(trayIcons) : -1;
        }
        else if (position == L"tray_icons_right") {
            auto trayIcons = FindTrayElement(trayGrid, root, L"NotificationAreaIcons");
            col = trayIcons ? Grid::GetColumn(trayIcons) + 1 : -1;
        }
        else if (position == L"tray_after_showdesktop_left") {
            auto showDesktop = FindChildByName(trayGrid, L"ShowDesktopStack");
            if (!showDesktop) showDesktop = FindChildByName(root, L"ShowDesktopStack");
            col = showDesktop ? Grid::GetColumn(showDesktop) : -1;
        }
        else if (position == L"tray_after_showdesktop_right") {
            auto showDesktop = FindChildByName(trayGrid, L"ShowDesktopStack");
            if (!showDesktop) showDesktop = FindChildByName(root, L"ShowDesktopStack");
            if (showDesktop) col = Grid::GetColumn(showDesktop) + 1;
            else col = (int)trayGrid.ColumnDefinitions().Size();
        }
        if (col >= 0) {
            return {trayGrid, col};
        }
    }
    if (position == L"taskbar_left_start"  ||
        position == L"taskbar_right_start" ||
        position == L"taskbar_after_search_left"||
        position == L"taskbar_after_search_right"||
        position == L"taskbar_after_taskview_left"||
        position == L"taskbar_after_taskview_right"||
        position == L"taskbar_after_widgets_left"||
        position == L"taskbar_after_widgets_right"||
        position == L"taskbar_left_edge"   ||
        position == L"taskbar_center_edge" ||
        position == L"taskbar_right_edge")
    {
        auto rootGrid = FindTaskbarRootGrid(root);
        if (!rootGrid) {
            return {};
        }
        return {rootGrid, -1};
    }
    return {};
}
static bool InjectPlayerGrid() {
    HWND hWnd = g_taskbarWnd ? g_taskbarWnd : FindCurrentProcessTaskbarWnd();
    if (!hWnd) {
        Wh_Log(L"InjectPlayerGrid: No taskbar window found");
        return false;
    }
    g_taskbarWnd = hWnd;
    try {
        auto xamlRoot = GetTaskbarXamlRoot(hWnd);
        if (!xamlRoot) {
            Wh_Log(L"InjectPlayerGrid: Failed to get XAML root");
            return false;
        }
        auto root = xamlRoot.Content().try_as<FrameworkElement>();
        if (!root) {
            Wh_Log(L"InjectPlayerGrid: Failed to get root FrameworkElement");
            return false;
        }
        if (g_settings.enableTreeDump) {
            DumpXamlTree(root, 0, 5);
            auto rootGrid = FindTaskbarRootGrid(root);
            if (rootGrid) {
                auto repeater = FindChildByName(rootGrid, L"TaskbarFrameRepeater");
                if (repeater) {
                    DumpXamlTree(repeater, 0, 3);
                }
            }
        }
        auto [targetGrid, insertCol] = ResolveInjectionTarget(root, g_settings.position);
        if (!targetGrid) {
            if (g_settings.enableTreeDump) {
                DumpXamlTree(root, 0, 8);
            }
            return false;
        }
        Grid playerGrid = BuildPlayerGrid();
        if (!playerGrid) return false;
        bool startButtonModActive = IsStartButtonModActive(root);
        (void)startButtonModActive;
        bool isTrayGrid = (targetGrid.Name() == L"SystemTrayFrameGrid");
        RemovePlayerGridChildren(targetGrid);
        RemoveAnchorDebugOverlays(targetGrid);
        if (isTrayGrid) {
            ColumnDefinition newCol;
            newCol.Width({1.0, GridUnitType::Auto});
            if (insertCol >= (int)targetGrid.ColumnDefinitions().Size()) {
                targetGrid.ColumnDefinitions().Append(newCol);
            } else {
                targetGrid.ColumnDefinitions().InsertAt(insertCol, newCol);
                for (uint32_t i = 0; i < targetGrid.Children().Size(); ++i) {
                    auto child = targetGrid.Children().GetAt(i).try_as<FrameworkElement>();
                    if (child) {
                        int childCol = Grid::GetColumn(child);
                        if (childCol >= insertCol)
                            Grid::SetColumn(child, childCol + 1);
                    }
                }
            }
            playerGrid.Margin({(double)g_settings.playerMarginLeft, 0,
                            (double)g_settings.playerMarginRight, 0});
            Grid::SetColumn(playerGrid, insertCol);
            targetGrid.Children().Append(playerGrid);
            g_playerColumn = insertCol;
        }
        else {
            auto repeater  = FindChildByName(targetGrid, L"TaskbarFrameRepeater");
            auto trayFrame = FindChildByName(targetGrid, L"SystemTrayFrameGrid");
            bool isEdgePosition = (g_settings.position == L"taskbar_left_edge" ||
                                g_settings.position == L"taskbar_center_edge" ||
                                g_settings.position == L"taskbar_right_edge");
            bool isTrackingPosition = (g_settings.position == L"taskbar_left_start" ||
                                    g_settings.position == L"taskbar_right_start" ||
                                    g_settings.position == L"taskbar_after_search_left" ||
                                    g_settings.position == L"taskbar_after_search_right" ||
                                    g_settings.position == L"taskbar_after_taskview_left" ||
                                    g_settings.position == L"taskbar_after_taskview_right" ||
                                    g_settings.position == L"taskbar_after_widgets_left" ||
                                    g_settings.position == L"taskbar_after_widgets_right");
            if (isEdgePosition || isTrackingPosition) {
                double leftMargin  = (double)g_settings.playerMarginLeft;
                double rightMargin = (double)g_settings.playerMarginRight;
                playerGrid.HorizontalAlignment(HorizontalAlignment::Left);
                if (isEdgePosition) {
                    if (g_settings.position == L"taskbar_left_edge") {
                        playerGrid.Margin({leftMargin, 0, rightMargin, 0});
                    }
                    else if (g_settings.position == L"taskbar_center_edge") {
                        playerGrid.HorizontalAlignment(HorizontalAlignment::Center);
                        playerGrid.Margin({leftMargin, 0, rightMargin, 0});
                    }
                    else if (g_settings.position == L"taskbar_right_edge") {
                        playerGrid.HorizontalAlignment(HorizontalAlignment::Right);
                        if (trayFrame) rightMargin += trayFrame.ActualWidth() + 4;
                        playerGrid.Margin({leftMargin, 0, rightMargin, 0});
                    }
                } else if (isTrackingPosition) {
                    FrameworkElement targetElem = nullptr;
                    std::wstring trackSide = L"right";
                    if (repeater) {
                        if (g_settings.position == L"taskbar_left_start") {
                            targetElem = FindElementInRepeater(repeater, kStartButtonNames, ARRAYSIZE(kStartButtonNames));
                            trackSide = L"left";
                        } else if (g_settings.position == L"taskbar_right_start") {
                            targetElem = FindElementInRepeater(repeater, kStartButtonNames, ARRAYSIZE(kStartButtonNames));
                            trackSide = L"right";
                        } else if (g_settings.position == L"taskbar_after_search_left") {
                            targetElem = FindElementByClassName(repeater, L"Taskbar.TaskbarExtensionElement");
                            trackSide = L"left";
                        } else if (g_settings.position == L"taskbar_after_search_right") {
                            targetElem = FindElementByClassName(repeater, L"Taskbar.TaskbarExtensionElement");
                            trackSide = L"right";
                        } else if (g_settings.position == L"taskbar_after_taskview_left") {
                            targetElem = FindNthElementByClassName(repeater, L"Taskbar.ExperienceToggleButton", 1);
                            trackSide = L"left";
                        } else if (g_settings.position == L"taskbar_after_taskview_right") {
                            targetElem = FindNthElementByClassName(repeater, L"Taskbar.ExperienceToggleButton", 1);
                            trackSide = L"right";
                        } else if (g_settings.position == L"taskbar_after_widgets_left") {
                            targetElem = FindChildByName(repeater, L"AugmentedEntryPointButton");
                            if (!targetElem) targetElem = FindChildByClassName(repeater, L"Taskbar.AugmentedEntryPointButton");
                            trackSide = L"left";
                        } else if (g_settings.position == L"taskbar_after_widgets_right") {
                            targetElem = FindChildByName(repeater, L"AugmentedEntryPointButton");
                            if (!targetElem) targetElem = FindChildByClassName(repeater, L"Taskbar.AugmentedEntryPointButton");
                            trackSide = L"right";
                        }
                    }
                    bool requiresStartAnchor =
                        g_settings.position == L"taskbar_left_start" ||
                        g_settings.position == L"taskbar_right_start";
                    if (!targetElem || targetElem.ActualWidth() <= 1.0) {
                        if (requiresStartAnchor) return false;
                        playerGrid.Margin({leftMargin, 0, rightMargin, 0});
                    } else {
                        g_trackedElement = targetElem;
                        g_trackedElementOriginalMargin = targetElem.Margin();
                        g_hasTrackedElementOriginalMargin = true;
                        g_trackPosition = trackSide;
                        g_trackedStartButtonModActive =
                            g_settings.position != L"taskbar_left_start" &&
                            IsStartButtonModActive(root);
                        g_trackedStartButtonOffset = 0.0;
                        if (g_trackedStartButtonModActive &&
                            (g_settings.position == L"taskbar_left_start" ||
                            g_settings.position == L"taskbar_right_start" ||
                            g_settings.position == L"taskbar_after_taskview_left" ||
                            g_settings.position == L"taskbar_after_taskview_right")) {
                            g_trackedStartButtonOffset = GetStartButtonAdjustment(root);
                        }
                        g_hasTrackedPlayerAnchorLeft = false;
                        if (g_taskbarExpanded.load() &&
                            trackSide == L"left" &&
                            g_settings.position == L"taskbar_left_start") {
                            try {
                                auto transform = targetElem.TransformToVisual(targetGrid);
                                auto point = transform.TransformPoint({0, 0});
                                g_trackedPlayerAnchorLeft =
                                    point.X -
                                    (targetElem.Margin().Left -
                                     g_trackedElementOriginalMargin.Left) +
                                    g_settings.playerMarginLeft +
                                    g_trackedStartButtonOffset;
                                g_hasTrackedPlayerAnchorLeft = true;
                            } catch (...) {}
                        }
                        g_trackedRootGridWidth = 0.0;
                        g_layoutUpdateToken = targetGrid.LayoutUpdated(
                            [targetGrid](winrt::Windows::Foundation::IInspectable const&,
                                         winrt::Windows::Foundation::IInspectable const&) {
                                if (g_taskbarLayoutTransitionInProgress) return;
                                if (SyncTrackedPlayerLayout(targetGrid)) {
                                    RevealTaskbarDetailsAfterLayout();
                                }
                            }
                        );
                    }
                }
                Grid::SetColumn(playerGrid, 0);
                Canvas::SetZIndex(playerGrid, 1000);
                targetGrid.Children().Append(playerGrid);
                g_playerColumn = -1;
            }
            else {
                ColumnDefinition newCol;
                newCol.Width({1.0, GridUnitType::Auto});
                if (insertCol >= (int)targetGrid.ColumnDefinitions().Size()) {
                    targetGrid.ColumnDefinitions().Append(newCol);
                } else {
                    targetGrid.ColumnDefinitions().InsertAt(insertCol, newCol);
                    for (uint32_t i = 0; i < targetGrid.Children().Size(); ++i) {
                        auto child = targetGrid.Children().GetAt(i).try_as<FrameworkElement>();
                        if (child) {
                            int childCol = Grid::GetColumn(child);
                            if (childCol >= insertCol)
                                Grid::SetColumn(child, childCol + 1);
                        }
                    }
                }
                playerGrid.Margin({(double)g_settings.playerMarginLeft, 0,
                                (double)g_settings.playerMarginRight, 0});
                Grid::SetColumn(playerGrid, insertCol);
                targetGrid.Children().Append(playerGrid);
                g_playerColumn = insertCol;
            }
        }
        g_playerGrid      = playerGrid;
        g_injectionParent = targetGrid;
        RefreshPlayerContents();
        g_playerGrid.Visibility(Visibility::Visible);
        g_playerGrid.UpdateLayout();
        if (g_injectionParent) {
            g_injectionParent.UpdateLayout();
        }
        if (g_playerGrid.ActualWidth() == 0.0 && g_playerGrid.ActualHeight() == 0.0) {
            g_needsUiUpdate = true;
            if (g_timerUpdateEvent) SetEvent(g_timerUpdateEvent);
        }
        auto dispatcher = g_playerGrid.Dispatcher();
        if (dispatcher) {
            try {
                dispatcher.RunAsync(winrt::Windows::UI::Core::CoreDispatcherPriority::Low, [=]() {
                    if (!g_unloading && g_playerGrid) RefreshThemeColors();
                });
            } catch (...) {
                Wh_Log(L"InjectPlayerGrid: Failed to dispatch RefreshThemeColors");
            }
        }
        Canvas::SetZIndex(g_playerGrid, 1000);
        OnSessionsChanged();
        g_needsUiUpdate = true;
        return true;
    } catch (...) {
        Wh_Log(L"InjectPlayerGrid: Exception during injection");
        return false;
    }
}
static void RemovePlayerGrid() {
    g_taskbarWrapperHovered = false;
    g_taskbarDetailsRevealPending = false;
    g_taskbarLayoutTransitionInProgress = false;
    if (!g_injectionParent) return;
    try {
        if (g_layoutUpdateToken.value) {
            auto targetGrid = g_injectionParent.try_as<Grid>();
            if (targetGrid) {
                try { targetGrid.LayoutUpdated(g_layoutUpdateToken); } catch (...) {}
            }
            g_layoutUpdateToken = {};
        }

        if (g_trackedElement) {
            try {
                if (g_hasTrackedElementOriginalMargin) {
                    g_trackedElement.Margin(g_trackedElementOriginalMargin);
                } else {
                    auto m = g_trackedElement.Margin();
                    if (g_trackPosition == L"left" || g_trackPosition == L"far_left") m.Left = 0;
                    if (g_trackPosition == L"right") m.Right = 0;
                    g_trackedElement.Margin(m);
                }
            } catch (...) {}
            g_trackedElement = nullptr;
        }
        g_hasTrackedElementOriginalMargin = false;
        g_trackPosition = L"";
        g_trackedStartButtonModActive = false;
        g_trackedStartButtonOffset = 0.0;
        g_hasTrackedPlayerAnchorLeft = false;
        g_trackedPlayerAnchorLeft = 0.0;
        g_trackedRootGridWidth = 0.0;
        auto targetGrid = g_injectionParent.try_as<Grid>();
        int playerCol = -1;
        RemoveAnchorDebugOverlays(targetGrid);
        playerCol = RemovePlayerGridChildren(targetGrid);
        bool isTrackingPosition = (g_settings.position == L"taskbar_left_edge" ||
                                g_settings.position == L"taskbar_center_edge" ||
                                g_settings.position == L"taskbar_right_edge" ||
                                g_settings.position == L"taskbar_left_start" ||
                                g_settings.position == L"taskbar_right_start" ||
                                g_settings.position == L"taskbar_after_search_left" ||
                                g_settings.position == L"taskbar_after_search_right" ||
                                g_settings.position == L"taskbar_after_taskview_left" ||
                                g_settings.position == L"taskbar_after_taskview_right" ||
                                g_settings.position == L"taskbar_after_widgets_left" ||
                                g_settings.position == L"taskbar_after_widgets_right");
        if (!isTrackingPosition && playerCol >= 0 && playerCol < (int)targetGrid.ColumnDefinitions().Size()) {
            for (uint32_t i = 0; i < targetGrid.Children().Size(); ++i) {
                auto child = targetGrid.Children().GetAt(i).try_as<FrameworkElement>();
                if (child) {
                    int childCol = Grid::GetColumn(child);
                    if (childCol > playerCol)
                        Grid::SetColumn(child, childCol - 1);
                }
            }
            targetGrid.ColumnDefinitions().RemoveAt(playerCol);
        }
        g_playerGrid      = nullptr;
        g_injectionParent = nullptr;
        g_playerColumn    = -1;
        g_playerToolTip   = nullptr;
        g_playerButtonStateUpdater = nullptr;
        g_cachedAlbumTitle.clear();
        g_cachedAlbumArtist.clear();
        g_cachedThumbnailBytes.clear();
        g_cachedPaletteHash = 0;
        g_blurBgCache.Invalidate();
        g_cachedAppIconSize = -1;
        g_scrollCachedTitle.clear();
        g_scrollCachedArtist.clear();
        ResetScrollState(g_titleScroll);
        ResetScrollState(g_artistScroll);
    } catch (...) {
        g_playerGrid      = nullptr;
        g_injectionParent = nullptr;
        g_playerColumn    = -1;
        g_playerToolTip   = nullptr;
        g_playerButtonStateUpdater = nullptr;
        g_cachedAlbumTitle.clear();
        g_cachedAlbumArtist.clear();
        g_cachedThumbnailBytes.clear();
        g_cachedPaletteHash = 0;
        g_blurBgCache.Invalidate();
        g_cachedAppIconSize = -1;
        ResetScrollState(g_titleScroll);
        ResetScrollState(g_artistScroll);
    }
}
static void RefreshNeteaseHeartButton() {
    if (!g_playerGrid || g_unloading || g_applyingSettings) return;

    bool hasMedia = false;
    {
        std::lock_guard<std::mutex> lock(g_mediaMtx);
        hasMedia = g_media.hasMedia;
    }
    bool hasSession = HasSelectedPlayerSession();

    if (auto element = FindChildByName(g_playerGrid, kHeartBtnName)) {
        if (auto button = element.try_as<Button>()) {
            try {
                PlayerKind selectedPlayer = g_selectedPlayer.load();
                bool liked = false;
                bool loading = false;
                bool supported = false;
                bool visible = false;
                if (selectedPlayer == PlayerKind::TwilightEcho) {
                    NeteaseLikeState state = g_twilightLikeState.load();
                    visible = hasMedia && hasSession &&
                        g_twilightFavoriteEligible.load();
                    loading = visible && state == NeteaseLikeState::Unknown;
                    supported = visible && !loading;
                    liked = state == NeteaseLikeState::Liked;
                }
                button.IsEnabled(supported && !loading);
                button.Visibility(visible ? Visibility::Visible
                                          : Visibility::Collapsed);
                if (auto iconGrid = button.Content().try_as<Grid>()) {
                    for (uint32_t i = 0;
                         i < iconGrid.Children().Size(); ++i) {
                        auto content = iconGrid.Children().GetAt(i)
                                           .try_as<TextBlock>();
                        if (!content) continue;
                        if (content.Name() == kHeartGlyphName) {
                            content.Text(winrt::hstring(
                                liked ? L"\uEB52" : L"\uEB51"));
                            content.FontFamily(
                                FontFamily(L"Segoe Fluent Icons"));
                            content.FontSize(
                                (double)g_settings.buttonIconSize + 2.0);
                            content.Opacity(
                                loading ? 0.5 : (liked ? 1.0 : 0.38));
                            content.Foreground(liked
                                ? MakeBrush({0xFF, 0xFF, 0x4D, 0x67})
                                : MakeBrush(ButtonColor()));
                        } else if (content.Name() == kHeartQuestionName) {
                            content.Visibility(
                                loading ? Visibility::Visible
                                        : Visibility::Collapsed);
                            content.Opacity(loading ? 0.9 : 0.0);
                            content.Foreground(MakeBrush(ButtonColor()));
                        }
                    }
                }
            } catch (...) {}
        }
    }
}

static void RefreshPlayerContents() {
    if (!g_playerGrid || g_unloading || g_applyingSettings) return;
    std::wstring      title, artist, appUserModelId;
    bool              isPlaying = false, hasMedia = false;
    std::vector<BYTE> thumbBytes;
    std::vector<BYTE> appIconBytes;
    uint64_t          thumbHash = 0;
    bool              canSkipPrevious = true, canSkipNext = true;
    bool              canShuffle = true, canRepeat = true, canSeek = true;
    {
        std::lock_guard<std::mutex> lk(g_mediaMtx);
        title        = g_media.title;
        artist       = g_media.artist;
        appUserModelId = g_media.appUserModelId;
        isPlaying    = g_media.isPlaying;
        hasMedia     = g_media.hasMedia;
        thumbBytes   = g_media.thumbnailBytes;
        thumbHash    = g_media.thumbnailHash;
        appIconBytes = g_media.appIconBytes;
        canSkipPrevious = g_media.canSkipPrevious;
        canSkipNext     = g_media.canSkipNext;
        canShuffle      = g_media.canShuffle;
        canRepeat       = g_media.canRepeat;
        canSeek         = g_media.canSeek;
    }
    (void)hasMedia;
    g_playerGrid.UpdateLayout();
    bool hasSession = HasSelectedPlayerSession();
    std::wstring taskbarTitle = title;
    bool showTaskbarTitleForSession = hasSession;
    bool taskbarTitleScrollingEnabled =
        g_settings.enableTitleScrolling && !g_settings.showNeteaseLyrics;
    if (g_settings.showNeteaseLyrics && hasSession) {
        taskbarTitle = L"\u2026";
        std::lock_guard<std::mutex> lock(g_neteaseLyricsMtx);
        if (!g_neteaseCurrentLyric.empty()) {
            taskbarTitle = g_neteaseCurrentLyric;
        }
        if (IsTaskbarPlayerEffectivelyHovered() && !title.empty()) {
            taskbarTitle = title;
        }
    }
    if (taskbarTitle != g_scrollCachedTitle || artist != g_scrollCachedArtist) {
        g_scrollCachedTitle  = taskbarTitle;
        g_scrollCachedArtist = artist;
        ResetScrollState(g_titleScroll);
        ResetScrollState(g_artistScroll);
        try {
            if (auto fe = FindChildByName(g_playerGrid, kTitleCloneName))
                if (auto cl = fe.try_as<TextBlock>())
                    cl.Visibility(Visibility::Collapsed);
        } catch (...) {}
        try {
            if (auto fe = FindChildByName(g_playerGrid, kArtistCloneName))
                if (auto cl = fe.try_as<TextBlock>())
                    cl.Visibility(Visibility::Collapsed);
        } catch (...) {}
        try {
            if (auto fe = FindChildByName(g_playerGrid, kTitleBlockName))
                if (auto tb = fe.try_as<TextBlock>())
                    Canvas::SetLeft(tb, 0.0);
        } catch (...) {}
        try {
            if (auto fe = FindChildByName(g_playerGrid, kArtistBlockName))
                if (auto ab = fe.try_as<TextBlock>())
                    Canvas::SetLeft(ab, 0.0);
        } catch (...) {}
    }
    bool titleVisible = false;
    bool artistVisible = false;
    if (auto fe = FindChildByName(g_playerGrid, kTitleBlockName))
        if (auto tb = fe.try_as<TextBlock>())
            try {
                std::wstring displayTitle = taskbarTitle;
                if (!hasSession) {
                    displayTitle = UiConfiguredText(
                        g_settings.noMediaTitleText, L"Not Playing", L"未在播放");
                } else if (title.empty() && !g_settings.showNeteaseLyrics) {
                    displayTitle = UiConfiguredText(
                        g_settings.emptyTitleText, L"Untitled", L"未知曲目");
                }
                tb.Text(winrt::hstring(displayTitle));
                tb.Foreground(MakeBrush(TextColor()));
                bool visible = showTaskbarTitleForSession && !displayTitle.empty();
                titleVisible = visible;
                tb.Visibility(visible ? Visibility::Visible : Visibility::Collapsed);
                ToolTipService::SetToolTip(tb, nullptr);
                if (taskbarTitleScrollingEnabled && visible) {
                    try {
                        if (auto viewFe = FindChildByName(g_playerGrid, kTitleScrollViewName))
                            viewFe.Visibility(Visibility::Visible);
                    } catch (...) {}
                    if (auto panelFe = FindChildByName(g_playerGrid, kPanelGridName)) {
                        panelFe.UpdateLayout();
                    }
                    tb.UpdateLayout();
                    double textW = tb.DesiredSize().Width;
                    if (auto viewFe = FindChildByName(g_playerGrid, kTitleScrollViewName)) {
                        if (auto viewCanvas = viewFe.try_as<Canvas>()) {
                            double minW = (double)(g_settings.showNeteaseLyrics
                                ? kTaskbarLyricsWidth
                                : g_settings.textAreaMinWidth);
                            double maxW = (double)(g_settings.showNeteaseLyrics
                                ? kTaskbarLyricsWidth
                                : g_settings.textAreaMaxWidth);
                            double viewW = textW;
                            if (maxW > 0 && viewW > maxW) viewW = maxW;
                            double availW = GetAvailableScrollTextAreaWidth();
                            if (availW > 0.0 && viewW > availW) {
                                viewW = (minW > 0.0) ? std::max(availW, minW) : availW;
                            }
                            if (minW > 0 && viewW < minW) viewW = minW;
                            if (std::abs(viewCanvas.Width() - viewW) > 0.5) {
                                viewCanvas.Width(viewW);
                                try {
                                    if (auto geo = viewCanvas.Clip().try_as<winrt::Windows::UI::Xaml::Media::RectangleGeometry>()) {
                                        auto r = geo.Rect();
                                        geo.Rect({0, 0, (float)viewW, r.Height});
                                    }
                                } catch (...) {}
                            }
                            bool wasActive = g_titleScroll.active;
                            g_titleScroll.textWidth = textW;
                            g_titleScroll.viewWidth = viewW;
                            g_titleScroll.active = (textW > viewW + 2.0);
                            if (!g_titleScroll.active) {
                                g_titleScroll.offset = 0.0;
                                g_titleScroll.forward = true;
                                double centeredLeft = g_settings.showNeteaseLyrics
                                    ? std::max(0.0, (viewW - textW) / 2.0)
                                    : 0.0;
                                Canvas::SetLeft(tb, centeredLeft);
                            } else if (!wasActive) {
                                g_titleScroll.offset = 0.0;
                                g_titleScroll.forward = true;
                                if (g_settings.scrollMode == L"loop") {
                                    g_titleScroll.pausing  = false;
                                    g_titleScroll.pauseTick = 0;
                                } else {
                                    g_titleScroll.pausing  = true;
                                    g_titleScroll.pauseTick = g_settings.scrollPauseDuration;
                                }
                            }
                            if (auto cloneFe = FindChildByName(g_playerGrid, kTitleCloneName)) {
                                if (auto clone = cloneFe.try_as<TextBlock>()) {
                                    clone.Text(tb.Text());
                                    clone.Foreground(tb.Foreground());
                                    clone.Visibility(g_settings.scrollMode == L"loop" && g_titleScroll.active
                                        ? Visibility::Visible : Visibility::Collapsed);
                                }
                            }
                        }
                    }
                } else {
                    g_titleScroll.active = false;
                    g_titleScroll.offset = 0.0;
                    if (g_settings.enableTitleScrolling) {
                        try {
                            if (auto viewFe = FindChildByName(g_playerGrid, kTitleScrollViewName))
                                viewFe.Visibility(Visibility::Collapsed);
                        } catch (...) {}
                    }
                }
            } catch (...) {}
    if (auto fe = FindChildByName(g_playerGrid, kArtistBlockName))
        if (auto ab = fe.try_as<TextBlock>())
            try {
                std::wstring displayArtist = artist;
                if (!hasSession) {
                    displayArtist = g_settings.noMediaArtistText;
                } else if (artist.empty()) {
                    displayArtist = g_settings.emptyArtistText;
                }
                ab.Text(winrt::hstring(displayArtist));
                bool visible = g_settings.showTrackArtist && !displayArtist.empty();
                artistVisible = visible;
                ab.Visibility(visible ? Visibility::Visible : Visibility::Collapsed);
                ab.Foreground(MakeBrush(ArtistColor()));
                ToolTipService::SetToolTip(ab, nullptr);
                if (g_settings.enableArtistScrolling && visible) {
                    try {
                        if (auto viewFe = FindChildByName(g_playerGrid, kArtistScrollViewName))
                            viewFe.Visibility(Visibility::Visible);
                    } catch (...) {}
                    if (auto panelFe = FindChildByName(g_playerGrid, kPanelGridName)) {
                        panelFe.UpdateLayout();
                    }
                    ab.UpdateLayout();
                    double textW = ab.DesiredSize().Width;
                    if (auto viewFe = FindChildByName(g_playerGrid, kArtistScrollViewName)) {
                        if (auto viewCanvas = viewFe.try_as<Canvas>()) {
                            double minW = (double)(g_settings.showNeteaseLyrics
                                ? kTaskbarLyricsWidth
                                : g_settings.textAreaMinWidth);
                            double maxW = (double)(g_settings.showNeteaseLyrics
                                ? kTaskbarLyricsWidth
                                : g_settings.textAreaMaxWidth);
                            double viewW = textW;
                            if (maxW > 0 && viewW > maxW) viewW = maxW;
                            double availW = GetAvailableScrollTextAreaWidth();
                            if (availW > 0.0 && viewW > availW) {
                                viewW = (minW > 0.0) ? std::max(availW, minW) : availW;
                            }
                            if (minW > 0 && viewW < minW) viewW = minW;
                            if (std::abs(viewCanvas.Width() - viewW) > 0.5) {
                                viewCanvas.Width(viewW);
                                try {
                                    if (auto geo = viewCanvas.Clip().try_as<winrt::Windows::UI::Xaml::Media::RectangleGeometry>()) {
                                        auto r = geo.Rect();
                                        geo.Rect({0, 0, (float)viewW, r.Height});
                                    }
                                } catch (...) {}
                            }
                            bool wasActive = g_artistScroll.active;
                            g_artistScroll.textWidth = textW;
                            g_artistScroll.viewWidth = viewW;
                            g_artistScroll.active = (textW > viewW + 2.0);
                            if (!g_artistScroll.active) {
                                g_artistScroll.offset = 0.0;
                                g_artistScroll.forward = true;
                                Canvas::SetLeft(ab, 0.0);
                            } else if (!wasActive) {
                                g_artistScroll.offset = 0.0;
                                g_artistScroll.forward = true;
                                if (g_settings.scrollMode == L"loop") {
                                    g_artistScroll.pausing  = false;
                                    g_artistScroll.pauseTick = 0;
                                } else {
                                    g_artistScroll.pausing  = true;
                                    g_artistScroll.pauseTick = g_settings.scrollPauseDuration;
                                }
                            }
                            if (auto cloneFe = FindChildByName(g_playerGrid, kArtistCloneName)) {
                                if (auto clone = cloneFe.try_as<TextBlock>()) {
                                    clone.Text(ab.Text());
                                    clone.Foreground(ab.Foreground());
                                    clone.Visibility(g_settings.scrollMode == L"loop" && g_artistScroll.active
                                        ? Visibility::Visible : Visibility::Collapsed);
                                }
                            }
                        }
                    }
                } else {
                    g_artistScroll.active = false;
                    g_artistScroll.offset = 0.0;
                    if (g_settings.enableArtistScrolling) {
                        try {
                            if (auto viewFe = FindChildByName(g_playerGrid, kArtistScrollViewName))
                                viewFe.Visibility(Visibility::Collapsed);
                        } catch (...) {}
                    }
                }
            } catch (...) {}
    if ((g_titleScroll.active || g_artistScroll.active) &&
        (g_settings.enableTitleScrolling || g_settings.enableArtistScrolling)) {
        if (g_scrollDispatcherTimer && !g_scrollDispatcherTimer.IsEnabled()) {
            try { g_scrollDispatcherTimer.Start(); } catch (...) {}
        }
    }
    try {
        if (auto stackFe = FindChildByName(g_playerGrid, kTextStackName)) {
            bool anyTextVisible = titleVisible || artistVisible;
            stackFe.Visibility(anyTextVisible ? Visibility::Visible : Visibility::Collapsed);
        }
    } catch (...) {}
    if (auto fe = FindChildByName(g_playerGrid, kPlayBtnName))
        if (auto btn = fe.try_as<Button>())
            try {
                if (auto ct = btn.Content().try_as<TextBlock>()) {
                    const wchar_t* glyph = GetGlyph(2, isPlaying);
                    ct.Text(winrt::hstring(glyph));
                    ct.Foreground(MakeBrush(ButtonColor()));
                }
            } catch (...) {}
    if (auto fe = FindChildByName(g_playerGrid, kPrevBtnName))
        if (auto btn = fe.try_as<Button>())
            try {
                bool supported = canSkipPrevious;
                btn.IsEnabled(supported);
                if (g_settings.hideUnsupportedButtons) {
                    btn.Visibility(supported ? Visibility::Visible : Visibility::Collapsed);
                } else {
                    btn.Visibility(Visibility::Visible);
                }
                if (auto ct = btn.Content().try_as<TextBlock>()) {
                    const wchar_t* glyph = GetGlyph(1);
                    ct.Text(winrt::hstring(glyph));
                    if (!supported && !g_settings.hideUnsupportedButtons) {
                        ct.Opacity(0.35);
                        ct.Foreground(MakeBrush(ButtonColor()));
                    } else {
                        ct.Opacity(1.0);
                        ct.Foreground(MakeBrush(ButtonColor()));
                    }
                }
            } catch (...) {}
    if (auto fe = FindChildByName(g_playerGrid, kNextBtnName))
        if (auto btn = fe.try_as<Button>())
            try {
                bool supported = canSkipNext;
                btn.IsEnabled(supported);
                if (g_settings.hideUnsupportedButtons) {
                    btn.Visibility(supported ? Visibility::Visible : Visibility::Collapsed);
                } else {
                    btn.Visibility(Visibility::Visible);
                }
                if (auto ct = btn.Content().try_as<TextBlock>()) {
                    const wchar_t* glyph = GetGlyph(3);
                    ct.Text(winrt::hstring(glyph));
                    ct.Opacity(supported ? 1.0 : 0.35);
                    ct.Foreground(MakeBrush(ButtonColor()));
                }
            } catch (...) {}
    if (auto fe = FindChildByName(g_playerGrid, kRewindBtnName))
        if (auto btn = fe.try_as<Button>())
            try {
                bool supported = canSeek;
                btn.IsEnabled(supported);
                if (g_settings.hideUnsupportedButtons) {
                    btn.Visibility(supported ? Visibility::Visible : Visibility::Collapsed);
                } else {
                    btn.Visibility(Visibility::Visible);
                }
                if (auto ct = btn.Content().try_as<TextBlock>()) {
                    const wchar_t* glyph = GetGlyph(5);
                    ct.Text(winrt::hstring(glyph));
                    ct.Opacity(supported ? 1.0 : 0.35);
                    ct.Foreground(MakeBrush(ButtonColor()));
                }
            } catch (...) {}
    if (auto fe = FindChildByName(g_playerGrid, kForwardBtnName))
        if (auto btn = fe.try_as<Button>())
            try {
                bool supported = canSeek;
                btn.IsEnabled(supported);
                if (g_settings.hideUnsupportedButtons) {
                    btn.Visibility(supported ? Visibility::Visible : Visibility::Collapsed);
                } else {
                    btn.Visibility(Visibility::Visible);
                }
                if (auto ct = btn.Content().try_as<TextBlock>()) {
                    const wchar_t* glyph = GetGlyph(6);
                    ct.Text(winrt::hstring(glyph));
                    ct.Opacity(supported ? 1.0 : 0.35);
                    ct.Foreground(MakeBrush(ButtonColor()));
                }
            } catch (...) {}
    if (auto fe = FindChildByName(g_playerGrid, kShuffleBtnName))
        if (auto btn = fe.try_as<Button>())
            try {
                bool supported = canShuffle;
                btn.IsEnabled(supported);
                if (g_settings.hideUnsupportedButtons) {
                    btn.Visibility(supported ? Visibility::Visible : Visibility::Collapsed);
                } else {
                    btn.Visibility(Visibility::Visible);
                }
                if (auto ct = btn.Content().try_as<TextBlock>()) {
                    bool isEnabled = g_shuffleEnabled.load();
                    const wchar_t* glyph = L"";
                    ct.Text(winrt::hstring(glyph));
                    if (!supported && !g_settings.hideUnsupportedButtons) {
                        ct.Opacity(0.35);
                    } else {
                        ct.Opacity(isEnabled ? 1.0 : 0.4);
                    }
                    ct.Foreground(MakeBrush(ButtonColor()));
                }
            } catch (...) {}
    if (auto fe = FindChildByName(g_playerGrid, kRepeatBtnName))
        if (auto btn = fe.try_as<Button>())
            try {
                bool supported = canRepeat;
                btn.IsEnabled(supported);
                if (g_settings.hideUnsupportedButtons) {
                    btn.Visibility(supported ? Visibility::Visible : Visibility::Collapsed);
                } else {
                    btn.Visibility(Visibility::Visible);
                }
                if (auto ct = btn.Content().try_as<TextBlock>()) {
                    RepeatMode mode = g_repeatMode.load();
                    const wchar_t* glyph;
                    switch (mode) {
                        case RepeatMode::Off:
                            glyph = L"";
                            break;
                        case RepeatMode::All:
                            glyph = L"";
                            break;
                        case RepeatMode::One:
                            glyph = L"";
                            break;
                    }
                    ct.Text(winrt::hstring(glyph));
                    ct.Foreground(MakeBrush(ButtonColor()));
                    if (!supported && !g_settings.hideUnsupportedButtons) {
                        ct.Opacity(0.35);
                    } else {
                        ct.Opacity(1.0);
                    }
                }
            } catch (...) {}
    if (auto fe = FindChildByName(g_playerGrid, kSwitchSessionsBtnName))
        if (auto btn = fe.try_as<Button>())
            try {
                bool supported = g_sessionCount.load() > 1;
                btn.IsEnabled(supported);
                if (g_settings.hideUnsupportedButtons) {
                    btn.Visibility(supported ? Visibility::Visible : Visibility::Collapsed);
                } else {
                    btn.Visibility(Visibility::Visible);
                }
                if (auto ct = btn.Content().try_as<TextBlock>()) {
                    ct.Opacity(supported ? 1.0 : 0.35);
                    ct.Foreground(MakeBrush(ButtonColor()));
                }
            } catch (...) {}
    RefreshNeteaseHeartButton();
    bool paletteChanged = false;
    if (auto fe = FindChildByName(g_playerGrid, kArtImageName))
        if (auto img = fe.try_as<Controls::Image>()) {
            if (!thumbBytes.empty() && g_settings.showAlbumArt) {
                bool isSameAlbum = (!g_cachedThumbnailBytes.empty() &&
                                title == g_cachedAlbumTitle &&
                                artist == g_cachedAlbumArtist &&
                                thumbBytes == g_cachedThumbnailBytes);
                size_t newHash = (size_t)thumbHash;
                if (newHash != g_cachedPaletteHash && newHash != 0) {
                    g_cachedAlbumPalette = ExtractAlbumPalette(thumbBytes);
                    g_cachedPaletteHash = newHash;
                    g_vizPaletteColorsDirty = true;
                    paletteChanged = true;
                }
                if (!isSameAlbum) {
                    try {
                        IStream* pRawStream = SHCreateMemStream(
                            thumbBytes.data(), static_cast<UINT>(thumbBytes.size()));
                        if (pRawStream) {
                            winrt::com_ptr<IStream> comStream;
                            comStream.attach(pRawStream);
                            winrt::Windows::Storage::Streams::IRandomAccessStream rasStream{ nullptr };
                            ::CreateRandomAccessStreamOverStream(
                                comStream.get(),
                                BSOS_DEFAULT,
                                winrt::guid_of<winrt::Windows::Storage::Streams::IRandomAccessStream>(),
                                winrt::put_abi(rasStream));
                            if (rasStream) {
                                BitmapImage bmp;
                                if (g_settings.albumArtQuality == L"low") {
                                    int baseHeight = g_settings.albumArtMaxHeight > 0 ? g_settings.albumArtMaxHeight : 64;
                                    int decodeHeight = baseHeight / 2;
                                    if (decodeHeight < 16) decodeHeight = 16;
                                    bmp.DecodePixelHeight(decodeHeight);
                                } else if (g_settings.albumArtQuality == L"medium") {
                                    if (g_settings.albumArtMaxHeight > 0) {
                                        bmp.DecodePixelHeight(g_settings.albumArtMaxHeight);
                                    }
                                }
                                bmp.ImageOpened([](auto const&, auto const&) {
                                    if (g_unloading || g_applyingSettings || !g_playerGrid) return;
                                    try {
                                        if (auto panelFe = FindChildByName(g_playerGrid, kPanelGridName)) {
                                            panelFe.UpdateLayout();
                                        }
                                        g_needsUiUpdate = true;
                                        if (g_timerUpdateEvent) SetEvent(g_timerUpdateEvent);
                                    } catch (...) {}
                                });
                                img.Source(bmp);
                                bmp.SetSourceAsync(rasStream);
                                img.Visibility(Visibility::Visible);
                                g_cachedAlbumTitle = title;
                                g_cachedAlbumArtist = artist;
                                g_cachedThumbnailBytes = thumbBytes;
                                if (auto parent = VisualTreeHelper::GetParent(img)) {
                                    if (auto artInnerGrid = parent.try_as<Grid>()) {
                                        if (auto grandParent = VisualTreeHelper::GetParent(artInnerGrid)) {
                                            if (auto container = grandParent.try_as<FrameworkElement>()) {
                                                if (auto greatGrandParent = VisualTreeHelper::GetParent(container)) {
                                                    if (auto artContainer = greatGrandParent.try_as<Grid>()) {
                                                        artContainer.Visibility(Visibility::Visible);
                                                    }
                                                }
                                            }
                                        }
                                        for (uint32_t i = 0; i < artInnerGrid.Children().Size(); ++i) {
                                            auto child = artInnerGrid.Children().GetAt(i);
                                            if (auto border = child.try_as<Border>()) {
                                                if (border.Name() == L"EmptyIconBorder") {
                                                    border.Visibility(Visibility::Collapsed);
                                                    break;
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    } catch (...) { try { img.Source(nullptr); } catch (...) {} }
                } else {
                    img.Visibility(Visibility::Visible);
                    if (auto parent = VisualTreeHelper::GetParent(img)) {
                        if (auto container = parent.try_as<FrameworkElement>()) {
                            if (auto grandParent = VisualTreeHelper::GetParent(container)) {
                                if (auto greatGrandParent = VisualTreeHelper::GetParent(grandParent)) {
                                    if (auto artContainer = greatGrandParent.try_as<Grid>()) {
                                        artContainer.Visibility(Visibility::Visible);
                                    }
                                }
                            }
                        }
                    }
                }
                if (auto bgFe = FindChildByName(g_playerGrid, L"FluentMedia_Background")) {
                    if (auto bgBorder = bgFe.try_as<Border>()) {
                        auto& bgType = g_settings.backgroundType;
                        if (bgType == L"album_art_blur") {
                            try {
                                g_blurBgCache.Invalidate();
                                bgBorder.Visibility(Visibility::Visible);
                                bgBorder.Opacity(g_settings.blurOpacity / 100.0);
                                auto applyBlur = [bgBorder, thumbBytesSnap = thumbBytes]() {
                                    try {
                                        int w = (int)bgBorder.ActualWidth();
                                        int h = (int)bgBorder.ActualHeight();
                                        if (w <= 0 || h <= 0) return;
                                        g_blurBgCache.Invalidate();
                                        bgBorder.Background(MakeAlbumBlurBrush(thumbBytesSnap, w, h));
                                        bgBorder.Opacity(g_settings.blurOpacity / 100.0);
                                        bgBorder.Visibility(Visibility::Visible);
                                    } catch (...) {}
                                };
                                if (bgBorder.ActualWidth() > 0 && bgBorder.ActualHeight() > 0) {
                                    applyBlur();
                                } else {
                                    auto tokenHolder = std::make_shared<winrt::event_token>();
                                    *tokenHolder = bgBorder.SizeChanged(
                                        [applyBlur, bgBorder, tokenHolder](auto const&, auto const&) mutable {
                                            applyBlur();
                                            try { bgBorder.SizeChanged(*tokenHolder); } catch (...) {}
                                        });
                                }
                            } catch (...) {}
                        } else if (bgType == L"solid" || bgType == L"gradient" || bgType == L"acrylic" || bgType == L"mica" || bgType == L"mica_alt") {
                            try {
                                bgBorder.Background(MakeBackgroundBrush());
                                bgBorder.Visibility(Visibility::Visible);
                                bgBorder.Opacity(1.0);
                            } catch (...) {}
                        }
                    }
                }
            } else {
                g_cachedAlbumTitle.clear();
                g_cachedAlbumArtist.clear();
                g_cachedThumbnailBytes.clear();
                g_cachedPaletteHash = 0;
                g_blurBgCache.Invalidate();
                if (auto bgFe = FindChildByName(g_playerGrid, L"FluentMedia_Background")) {
                    if (auto bgBorder = bgFe.try_as<Border>()) {
                        try {
                            auto& bgType = g_settings.backgroundType;
                            if (bgType == L"solid" || bgType == L"gradient" || bgType == L"acrylic" ||
                                bgType == L"mica" || bgType == L"mica_alt") {
                                bgBorder.Background(MakeBackgroundBrush());
                                bgBorder.Visibility(Visibility::Visible);
                                bgBorder.Opacity(1.0);
                            } else {
                                bgBorder.Background(nullptr);
                                bgBorder.Visibility(Visibility::Collapsed);
                            }
                        } catch (...) {}
                    }
                }
                try {
                    img.Source(nullptr);
                    img.Visibility(Visibility::Collapsed);
                    if (g_settings.albumArtEmptyBehavior == L"hide" && thumbBytes.empty()) {
                        if (auto parent = VisualTreeHelper::GetParent(img)) {
                            if (auto container = parent.try_as<FrameworkElement>()) {
                                if (auto grandParent = VisualTreeHelper::GetParent(container)) {
                                    if (auto greatGrandParent = VisualTreeHelper::GetParent(grandParent)) {
                                        if (auto artContainer = greatGrandParent.try_as<FrameworkElement>()) {
                                            artContainer.Visibility(Visibility::Collapsed);
                                        }
                                    }
                                }
                            }
                        }
                    } else if (g_settings.albumArtEmptyBehavior == L"show_icon" && thumbBytes.empty()) {
                        if (auto parent = VisualTreeHelper::GetParent(img)) {
                            if (auto artInnerGrid = parent.try_as<Grid>()) {
                                if (auto grandParent = VisualTreeHelper::GetParent(artInnerGrid)) {
                                    if (auto container = grandParent.try_as<FrameworkElement>()) {
                                        if (auto greatGrandParent = VisualTreeHelper::GetParent(container)) {
                                            if (auto artContainer = greatGrandParent.try_as<Grid>()) {
                                                artContainer.Visibility(Visibility::Visible);
                                            }
                                        }
                                    }
                                }
                                Border iconBorder = nullptr;
                                for (uint32_t i = 0; i < artInnerGrid.Children().Size(); ++i) {
                                    auto child = artInnerGrid.Children().GetAt(i);
                                    if (auto border = child.try_as<Border>()) {
                                        if (border.Name() == L"EmptyIconBorder") {
                                            iconBorder = border;
                                            break;
                                        }
                                    }
                                }
                                if (!iconBorder) {
                                    iconBorder = Border();
                                    iconBorder.Name(L"EmptyIconBorder");
                                    iconBorder.Background(MakeBrush({0x00, 0x00, 0x00, 0x00}));
                                    iconBorder.HorizontalAlignment(HorizontalAlignment::Stretch);
                                    iconBorder.VerticalAlignment(VerticalAlignment::Stretch);
                                    Canvas::SetZIndex(iconBorder, 5);
                                    TextBlock iconText = TextBlock();
                                    iconText.Name(L"EmptyIconText");
                                    iconText.HorizontalAlignment(HorizontalAlignment::Center);
                                    iconText.VerticalAlignment(VerticalAlignment::Center);
                                    iconBorder.Child(iconText);
                                    artInnerGrid.Children().InsertAt(0, iconBorder);
                                }
                                if (auto textBlock = iconBorder.Child().try_as<TextBlock>()) {
                                    std::wstring glyphStr;
                                    try {
                                        unsigned long cp = std::stoul(g_settings.emptyIconGlyph, nullptr, 16);
                                        if (cp <= 0xFFFF) {
                                            glyphStr = std::wstring(1, (wchar_t)cp);
                                        } else {
                                            cp -= 0x10000;
                                            glyphStr += (wchar_t)(0xD800 + (cp >> 10));
                                            glyphStr += (wchar_t)(0xDC00 + (cp & 0x3FF));
                                        }
                                    } catch (...) {
                                        glyphStr = L"\uE189";
                                    }
                                    textBlock.Text(glyphStr);
                                    bool useFluent = (g_settings.emptyIconFont == L"segoe_fluent");
                                    textBlock.FontFamily(Media::FontFamily(
                                        useFluent ? L"Segoe Fluent Icons" : L"Segoe MDL2 Assets"));
                                    textBlock.FontSize((double)g_settings.emptyIconSize);
                                    BYTE alpha = (BYTE)std::clamp((int)std::round(g_settings.emptyIconOpacity * 255.0 / 100.0), 0, 255);
                                    auto iconClr = ParseColorWithThemeSupport(g_settings.emptyIconColor, alpha);
                                    textBlock.Foreground(MakeBrush(iconClr));
                                }
                                iconBorder.Visibility(Visibility::Visible);
                            }
                        }
                    }
                } catch (...) {}
            }
        }
    if (paletteChanged) {
        try {
            if (g_settings.backgroundType == L"gradient" ||
                g_settings.backgroundType == L"solid" ||
                g_settings.backgroundType == L"acrylic" ||
                g_settings.backgroundType == L"mica" ||
                g_settings.backgroundType == L"mica_alt") {
                if (auto bgFe = FindChildByName(g_playerGrid, L"FluentMedia_Background")) {
                    if (auto bgBorder = bgFe.try_as<Border>()) {
                        bgBorder.Background(MakeBackgroundBrush());
                    }
                }
            }
            auto textClr = TextColor();
            auto artistClr = ArtistColor();
            if (auto titleFe = FindChildByName(g_playerGrid, kTitleBlockName)) {
                if (auto titleBlock = titleFe.try_as<TextBlock>()) {
                    titleBlock.Foreground(SolidColorBrush(textClr));
                }
            }
            if (auto artistFe = FindChildByName(g_playerGrid, kArtistBlockName)) {
                if (auto artistBlock = artistFe.try_as<TextBlock>()) {
                    artistBlock.Foreground(SolidColorBrush(artistClr));
                }
            }
            auto buttonClr = ButtonColor();
            for (const auto& btnName : {kPlayBtnName, kPrevBtnName, kNextBtnName,
                                        kRewindBtnName, kForwardBtnName, kShuffleBtnName, kRepeatBtnName}) {
                if (auto btnFe = FindChildByName(g_playerGrid, btnName)) {
                    if (auto btn = btnFe.try_as<Button>()) {
                        if (auto content = btn.Content()) {
                            if (auto icon = content.try_as<TextBlock>()) {
                                icon.Foreground(SolidColorBrush(buttonClr));
                            }
                        }
                    }
                }
            }
        } catch (...) {}
    }
    if (g_settings.showAppIcon) {
        if (auto fe = FindChildByName(g_playerGrid, kAppIconImageName))
            if (auto img = fe.try_as<Controls::Image>()) {
                bool sizeChanged = (g_cachedAppIconSize != g_settings.appIconSize);
                if (sizeChanged && !appIconBytes.empty()) {
                    g_cachedAppIconSize = g_settings.appIconSize;
                    FetchMediaPropertiesAsync();
                }
                if (!appIconBytes.empty()) {
                    try {
                        int iconSz = g_settings.appIconSize;
                        size_t expectedBytes = (size_t)iconSz * iconSz * 4;
                        if (appIconBytes.size() != expectedBytes) {
                            int computed = (int)std::sqrt((double)appIconBytes.size() / 4.0);
                            if (computed > 0 && (size_t)computed * computed * 4 == appIconBytes.size())
                                iconSz = computed;
                        }
                        img.Width(iconSz);
                        img.Height(iconSz);
                        size_t bytesNeeded = (size_t)iconSz * iconSz * 4;
                        winrt::Windows::UI::Xaml::Media::Imaging::WriteableBitmap wb(iconSz, iconSz);
                        auto buf = wb.PixelBuffer();
                        auto bufferByteAccess = buf.as<Windows::Storage::Streams::IBufferByteAccess>();
                        BYTE* pixels = nullptr;
                        bufferByteAccess->Buffer(&pixels);
                        if (appIconBytes.size() >= bytesNeeded && pixels) {
                            for (size_t i = 0; i + 3 < bytesNeeded; i += 4) {
                                pixels[i+0] = appIconBytes[i+2];
                                pixels[i+1] = appIconBytes[i+1];
                                pixels[i+2] = appIconBytes[i+0];
                                pixels[i+3] = appIconBytes[i+3];
                            }
                        }
                        buf.Length(static_cast<uint32_t>(bytesNeeded));
                        wb.Invalidate();
                        img.Source(wb);
                        img.Visibility(Visibility::Visible);
                    } catch (...) {
                        try { img.Source(nullptr); img.Visibility(Visibility::Collapsed); } catch (...) {}
                    }
                } else {
                    try { img.Source(nullptr); img.Visibility(Visibility::Collapsed); } catch (...) {}
                }
            }
    }
    try {
        FrameworkElement tooltipHost = g_playerGrid;
        if (!g_settings.showNeteaseLyrics &&
            g_settings.showFullTitleOnHover && hasSession &&
            (!title.empty() || !artist.empty())) {
            std::wstring tooltipText;
            if (!title.empty())  tooltipText += title;
            if (!title.empty() && !artist.empty()) tooltipText += L"\n\n";
            if (!artist.empty()) tooltipText += artist;
            if (g_playerToolTip) {
                try {
                    auto content = g_playerToolTip.Content();
                    if (auto ttText = content.try_as<TextBlock>()) {
                        ttText.Text(winrt::hstring(tooltipText));
                    }
                    g_playerToolTip.IsEnabled(true);
                } catch (...) {}
                if (tooltipHost) {
                    try { ToolTipService::SetToolTip(tooltipHost, g_playerToolTip); } catch (...) {}
                }
            }
        } else {
            if (g_playerToolTip) {
                try {
                    auto content = g_playerToolTip.Content();
                    if (auto ttText = content.try_as<TextBlock>()) {
                        ttText.Text(L"");
                    }
                    g_playerToolTip.IsEnabled(false);
                } catch (...) {}
            }

            if (tooltipHost) {
                try { ToolTipService::SetToolTip(tooltipHost, nullptr); } catch (...) {}
            }
        }
    } catch (...) {}
    ApplyTaskbarCompactState();
}
static bool IsFullscreenActive() {
    using Fn = HRESULT(WINAPI*)(int*);
    static Fn pfn = nullptr; static bool tried = false;
    if (!tried) {
        tried = true;
        HMODULE h = GetModuleHandleW(L"shell32.dll");
        if (!h) h = LoadLibraryW(L"shell32.dll");
        if (h) pfn = (Fn)GetProcAddress(h, (LPCSTR)2573);
    }
    if (!pfn) return false;
    int s = 0;
    return SUCCEEDED(pfn(&s)) && (s == 2 || s == 3 || s == 4);
}
static void UpdateVisibility() {
    if (!g_playerGrid || g_unloading || g_applyingSettings) return;
    bool hide = false;
    if (g_settings.hideFullscreen && IsFullscreenActive()) hide = true;
    if (!hide && g_hiddenByIdle) hide = true;
    if (!hide) {
        bool hasMedia = false, hasSession = false;
        { std::lock_guard<std::mutex> lk(g_mediaMtx); hasMedia = g_media.hasMedia; }
        hasSession = HasSelectedPlayerSession();
        if (hasMedia || hasSession) {
            g_lastMediaTime = std::chrono::steady_clock::now();
        }

        bool sourceSelectorAvailable =
            FindChildByName(g_playerGrid, kSourceSwitchBtnName) != nullptr;
        if (g_settings.hideWhenNoMedia && !sourceSelectorAvailable) {
            if (!hasSession) {
                hide = true;
            }
            else if (!hasMedia) {
                auto now = std::chrono::steady_clock::now();
                auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(now - g_lastMediaTime).count();
                if (elapsed > 2500) {
                    hide = true;
                } else {
                    if (!g_unloading && g_timerUpdateEvent) SetEvent(g_timerUpdateEvent);
                }
            }
        }
    }
    try {
        if (g_playerColumn == -1) {
            if (hide) {
                g_playerGrid.Visibility(Visibility::Collapsed);
            } else {
                g_playerGrid.Visibility(Visibility::Visible);
            }
        } else {
            bool isTrackingPosition = (g_settings.position == L"taskbar_left_start" ||
                                    g_settings.position == L"taskbar_right_start" ||
                                    g_settings.position == L"taskbar_after_search_left" ||
                                    g_settings.position == L"taskbar_after_search_right" ||
                                    g_settings.position == L"taskbar_after_taskview_left" ||
                                    g_settings.position == L"taskbar_after_taskview_right" ||
                                    g_settings.position == L"taskbar_after_widgets_left" ||
                                    g_settings.position == L"taskbar_after_widgets_right" ||
                                    g_settings.position == L"taskbar_far_edge_left");
            if (hide && isTrackingPosition && g_settings.enableSmoothPositionAnimation) {
                g_playerGrid.Opacity(0.0);
                SpawnTrackedWorker([]() {
                    std::this_thread::sleep_for(std::chrono::milliseconds(200));
                    try {
                        RunFromWindowThread(g_taskbarWnd, [](void* param) {
                            try {
                                if (g_playerGrid) {
                                    g_playerGrid.Visibility(Visibility::Collapsed);
                                    if (g_injectionParent) {
                                        if (auto targetGrid = g_injectionParent.try_as<Grid>()) {
                                            if (g_playerColumn < (int)targetGrid.ColumnDefinitions().Size()) {
                                                auto colDef = targetGrid.ColumnDefinitions().GetAt(g_playerColumn);
                                                colDef.Width({0.0, GridUnitType::Pixel});
                                            }
                                        }
                                    }
                                    g_playerGrid.MinWidth(0);
                                    g_playerGrid.MaxWidth(0);
                                    g_playerGrid.Width(0);
                                }
                            } catch (...) {}
                        }, nullptr);
                    } catch (...) {}
                });
            } else {
                g_playerGrid.Visibility(hide ? Visibility::Collapsed : Visibility::Visible);
                g_playerGrid.Opacity(hide ? 0.0 : 1.0);
                if (g_injectionParent) {
                    if (auto targetGrid = g_injectionParent.try_as<Grid>()) {
                        if (g_playerColumn < (int)targetGrid.ColumnDefinitions().Size()) {
                            auto colDef = targetGrid.ColumnDefinitions().GetAt(g_playerColumn);
                            if (hide) {
                                colDef.Width({0.0, GridUnitType::Pixel});
                            } else {
                                colDef.Width({1.0, GridUnitType::Auto});
                            }
                        }
                    }
                } else {
                }
                if (hide) {
                    g_playerGrid.MinWidth(0);
                    g_playerGrid.MaxWidth(0);
                    g_playerGrid.Width(0);
                } else {
                    bool hasTextOrButtons = !g_settings.taskbarTextMode.empty() ||
                        g_settings.showTrackArtist ||
                        (g_settings.showMediaButtons && !g_mediaButtons.empty());
                    if (hasTextOrButtons && g_settings.playerMinWidth > 0) {
                        g_playerGrid.MinWidth((double)g_settings.playerMinWidth);
                    } else {
                        g_playerGrid.MinWidth(0);
                    }
                    if (g_settings.playerMaxWidth > 0) {
                        g_playerGrid.MaxWidth((double)g_settings.playerMaxWidth);
                    } else {
                        g_playerGrid.ClearValue(FrameworkElement::MaxWidthProperty());
                    }
                    g_playerGrid.ClearValue(FrameworkElement::WidthProperty());
                }
            }
        }
        ApplyTaskbarCompactState();
        g_playerGrid.UpdateLayout();
        if (g_settings.vizEnabled) {
            bool nowVisible = !hide;
            if (nowVisible && !g_vizCurrentlyVisible) {
                g_vizCurrentlyVisible = true;
                StartVizCaptureThread();
                StartVizTimer();
            } else if (!nowVisible && g_vizCurrentlyVisible) {
                g_vizCurrentlyVisible = false;
                StopVizTimer();
                SpawnTrackedWorker([]() { StopVizCaptureThread(); });
            }
        }

        if (g_settings.enableTitleScrolling || g_settings.enableArtistScrolling) {
            if (hide) StopScrollTimer();
            else      StartScrollTimer();
        }
    } catch (...) {}
}
static void ApplySettings() {
    g_idleSeconds  = 0;
    g_idleTicks    = 0;
    g_hiddenByIdle = false;
    try { RemovePlayerGrid(); } catch (...) { Wh_Log(L"ApplySettings: Exception in RemovePlayerGrid"); }
    if (!g_unloading) {
        try { InjectPlayerGrid(); } catch (...) { Wh_Log(L"ApplySettings: Exception in InjectPlayerGrid"); }
    }
}
static void ApplySettingsWithRetry(FrameworkElement xamlRootContent, int retryCount = 0) {
    static constexpr int kMaxRetries = 50;
    auto retry = [&]() {
        if (retryCount >= kMaxRetries) {
            Wh_Log(L"ApplySettingsWithRetry: giving up after %d retries, SystemTray.SystemTrayFrame not found", kMaxRetries);
            return;
        }
        auto timer = DispatcherTimer();
        timer.Interval(winrt::Windows::Foundation::TimeSpan{
            std::chrono::milliseconds(100)});
        auto tickToken = std::make_shared<winrt::event_token>();
        *tickToken = timer.Tick(
            [timer, tickToken, xamlRootContent, retryCount](
                winrt::Windows::Foundation::IInspectable const&,
                winrt::Windows::Foundation::IInspectable const&) {
                timer.Stop();
                timer.Tick(*tickToken);
                ApplySettingsWithRetry(xamlRootContent, retryCount + 1);
            });
        timer.Start();
    };
    if (g_unloading) {
        return;
    }
    auto systemTrayFrame = FindChildByClassName(xamlRootContent, L"SystemTray.SystemTrayFrame");
    if (!systemTrayFrame) {
        retry();
        return;
    }
    auto systemTrayFrameGrid = FindChildByName(systemTrayFrame, L"SystemTrayFrameGrid");
    if (!systemTrayFrameGrid) {
        retry();
        return;
    }
    ApplySettings();
}
using TrayUI_StartTaskbar_t = void(WINAPI*)(void*);
static TrayUI_StartTaskbar_t TrayUI_StartTaskbar_Original = nullptr;
static void WINAPI TrayUI_StartTaskbar_Hook(void* pThis) {
    TrayUI_StartTaskbar_Original(pThis);
    if (g_unloading) {
        return;
    }
    HWND hWnd = FindCurrentProcessTaskbarWnd();
    if (!hWnd) {
        Wh_Log(L"TrayUI_StartTaskbar_Hook: Taskbar window not found");
        return;
    }
    g_playerGrid      = nullptr;
    g_injectionParent = nullptr;
    g_playerColumn    = -1;
    g_trackedElement  = nullptr;
    g_hasTrackedElementOriginalMargin = false;
    g_trackPosition   = L"";
    g_layoutUpdateToken = {};
    g_taskbarDetailsRevealPending = false;
    g_taskbarLayoutTransitionInProgress = false;
    g_trackedStartButtonModActive = false;
    g_trackedStartButtonOffset = 0.0;
    g_hasTrackedPlayerAnchorLeft = false;
    g_trackedPlayerAnchorLeft = 0.0;
    g_trackedRootGridWidth = 0.0;
    g_taskbarWnd = hWnd;
    g_cachedAlbumTitle.clear();
    g_cachedAlbumArtist.clear();
    g_cachedThumbnailBytes.clear();
    g_cachedPaletteHash = 0;
    g_cachedAppIconSize = -1;
    g_blurBgCache.Invalidate();
    StopVizTimer();
    g_vizDispatcherTimer = nullptr;
    g_vizDispatcherTimerHasToken = false;
    StopScrollTimer();
    g_scrollDispatcherTimer = nullptr;
    g_scrollDispatcherTimerHasToken = false;
    if (g_settings.vizEnabled) {
        SpawnTrackedWorker([]() {
            StopVizCaptureThread();
            StartVizCaptureThread();
        });
        StartVizTimer();
    }
    if (g_settings.enableTitleScrolling || g_settings.enableArtistScrolling) {
        StartScrollTimer();
    }
    auto xamlRoot = GetTaskbarXamlRoot(hWnd);
    if (!xamlRoot) {
        Wh_Log(L"InjectPlayerGrid: Failed to get XAML root");
        return;
    }
    auto xamlRootContent = xamlRoot.Content().try_as<FrameworkElement>();
    if (!xamlRootContent) {
        Wh_Log(L"InjectPlayerGrid: Failed to get XAML root content");
        return;
    }
    ApplySettingsWithRetry(xamlRootContent);
}
static bool HookTaskbarDllSymbols() {
    static const wchar_t* const kCandidates[] = {
        L"taskbar.dll",
    };
    HMODULE h = nullptr;
    for (auto* name : kCandidates) {
        h = LoadLibraryExW(name, nullptr, LOAD_LIBRARY_SEARCH_SYSTEM32);
        if (h) break;
    }
    if (!h) { return FALSE; }
    WindhawkUtils::SYMBOL_HOOK taskbarDllHooks[] = {
        {{LR"(const CTaskBand::`vftable'{for `ITaskListWndSite'})"},
        &CTaskBand_ITaskListWndSite_vftable},
        {{LR"(const CSecondaryTaskBand::`vftable'{for `ITaskListWndSite'})"},
        &CSecondaryTaskBand_ITaskListWndSite_vftable},
        {{LR"(public: virtual class std::shared_ptr<class TaskbarHost> __cdecl CTaskBand::GetTaskbarHost(void)const )"},
        &CTaskBand_GetTaskbarHost_Original},
        {{LR"(public: virtual class std::shared_ptr<class TaskbarHost> __cdecl CSecondaryTaskBand::GetTaskbarHost(void)const )"},
        &CSecondaryTaskBand_GetTaskbarHost_Original},
        {{LR"(public: int __cdecl TaskbarHost::FrameHeight(void)const )"},
        &TaskbarHost_FrameHeight_Original},
        {{LR"(public: void __cdecl std::_Ref_count_base::_Decref(void))"},
        &Std_Ref_Decref_Original},
        {{LR"(public: virtual void __cdecl TrayUI::StartTaskbar(void))"},
        &TrayUI_StartTaskbar_Original,
        TrayUI_StartTaskbar_Hook},
    };
    if (!WindhawkUtils::HookSymbols(h, taskbarDllHooks, ARRAYSIZE(taskbarDllHooks))) {
        return FALSE;
    }
    return TRUE;
}
BOOL Wh_ModInit() {
    g_unloading = false;
    g_applyingSettings = false;
    g_injectionRetryPending = false;
    g_taskbarWnd = nullptr;
    g_needsUiUpdate = false;
    g_taskbarExpanded = false;
    g_taskbarWrapperHovered = false;
    g_taskbarDetailsRevealPending = false;
    g_taskbarLayoutTransitionInProgress = false;
    g_trackedStartButtonModActive = false;
    g_trackedStartButtonOffset = 0.0;
    g_hasTrackedPlayerAnchorLeft = false;
    g_trackedPlayerAnchorLeft = 0.0;
    g_trackedRootGridWidth = 0.0;
    g_selectedPlayer =
        Wh_GetIntValue(kSelectedPlayerValueName, 0) ==
                static_cast<int>(PlayerKind::TwilightEcho)
            ? PlayerKind::TwilightEcho
            : PlayerKind::Netease;
    g_neteaseSkipSucceededTick = 0;
    g_twilightLikeState = NeteaseLikeState::Unknown;
    g_twilightLikeForcePollAfterTick = 0;
    g_twilightNextPollTick = 0;
    g_twilightPlaybackCommandGeneration = 0;
    g_twilightPendingPlaybackState = -1;
    g_twilightPendingPlaybackUntilTick = 0;
    g_twilightTrackGeneration = 0;
    g_twilightPendingTrackUntilTick = 0;
    g_lastTrackWheelActionTick = 0;
    g_twilightAccessibleHost = nullptr;
    g_twilightProcessDetected = false;
    g_twilightAccessibleLastSuccessTick = 0;
    {
        std::lock_guard<std::mutex> lock(g_twilightAccessiblePlaybackMtx);
        g_twilightPendingOldTrackKey.clear();
    }
    StoreTwilightAccessiblePlayback({});
    LoadSettings();
    if (!HookTaskbarDllSymbols()) {
        Wh_Log(L"Wh_ModInit: HookTaskbarDllSymbols failed");
        return FALSE;
    }
    return TRUE;
}
void Wh_ModAfterInit() {
    g_taskbarWnd = FindCurrentProcessTaskbarWnd();
    StartMediaThread();
    StartNeteaseLyricsThread();
    StartTimerThread();
    if (g_taskbarWnd) {
        RunFromWindowThread(g_taskbarWnd, [](void*) {
            g_cachedAlbumTitle.clear();
            g_cachedAlbumArtist.clear();
            g_cachedThumbnailBytes.clear();
            g_cachedPaletteHash = 0;
            g_cachedAppIconSize = -1;
            g_blurBgCache.Invalidate();
            ApplySettings();
            if (g_playerGrid) {
                ShowSuccessNotification();
                RefreshPlayerContents();
                UpdateVisibility();
                g_needsUiUpdate = true;
                if (g_timerUpdateEvent) {
                    SetEvent(g_timerUpdateEvent);
                }
            }
        }, nullptr);
    }
}
void Wh_ModUninit() {
    g_unloading = true;
    g_injectionRetryPending = false;
    StopNeteaseLyricsThread();
    StopTimerThread();
    StopMediaThread();
    WaitForTrackedWorkers();
    if (g_taskbarWnd)
        RunFromWindowThread(g_taskbarWnd, [](void*) {
            RemovePlayerGrid();
            g_mediaHoverBrush   = nullptr;
            g_mediaPressedBrush = nullptr;
            g_playerHoverBrush  = nullptr;
            g_playerPressedBrush = nullptr;
            g_playerBorderBrush  = nullptr;
            g_playerBorderPressedBrush = nullptr;
            g_vizBars.reset();
            g_vizBrushes.reset();
            g_fluentMediaButtonStyle      = nullptr;
        }, nullptr);
    else {
        g_mediaHoverBrush   = nullptr;
        g_mediaPressedBrush = nullptr;
        g_playerHoverBrush  = nullptr;
        g_playerPressedBrush = nullptr;
        g_playerBorderBrush  = nullptr;
        g_playerBorderPressedBrush = nullptr;
        g_vizBars.reset();
        g_vizBrushes.reset();
    }
    CleanupAudioDeviceEnumerator();
}
void Wh_ModSettingsChanged() {
    g_applyingSettings = true;
    g_vizBaseColorDirty = true;
    g_vizPaletteColorsDirty = true;
    g_vizCurrentlyVisible = false;
    StopTimerThread();
    LoadSettings();
    HWND hWnd = FindCurrentProcessTaskbarWnd();
    if (!hWnd) hWnd = g_taskbarWnd;
    if (hWnd) {
        g_taskbarWnd = hWnd;
        bool ok = RunFromWindowThread(hWnd, [](void*) {
            try {
                RemovePlayerGrid();
                g_cachedAlbumTitle.clear();
                g_cachedAlbumArtist.clear();
                g_cachedThumbnailBytes.clear();
                g_cachedPaletteHash = 0;
                g_blurBgCache.Invalidate();
                if (!g_unloading) {
                    InjectPlayerGrid();
                    g_needsUiUpdate = true;
                }
            } catch (...) {
                Wh_Log(L"Wh_ModSettingsChanged: Exception during RemovePlayerGrid/InjectPlayerGrid");
                g_playerGrid = nullptr;
                g_injectionParent = nullptr;
            }
        }, nullptr);
        if (!ok) {
            Wh_Log(L"Wh_ModSettingsChanged: RunFromWindowThread failed");
        }
    }
    g_applyingSettings = false;
    StartTimerThread();
}

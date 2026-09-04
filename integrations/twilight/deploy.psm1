Set-StrictMode -Version Latest

function New-BridgeResult {
    param(
        [string]$Outcome,
        [string]$Reason,
        [int]$ExitCode,
        [hashtable]$Context,
        [string]$Message = ''
    )

    [pscustomobject][ordered]@{
        outcome = $Outcome
        reason = $Reason
        message = $Message
        twilightVersion = $Context.TwilightVersion
        targetCommit = $Context.TargetCommit
        bridgeVersion = $Context.BridgeVersion
        installDir = $Context.InstallDir
        backupPath = $Context.BackupPath
        nextAction = $Context.NextAction
        exitCode = $ExitCode
    }
}

function Read-BridgeJson {
    param([string]$Path)

    if (-not (Test-Path -LiteralPath $Path -PathType Leaf)) {
        return $null
    }
    try {
        Get-Content -LiteralPath $Path -Raw -Encoding UTF8 | ConvertFrom-Json
    } catch {
        return $null
    }
}

function Get-BridgeProperty {
    param(
        [object]$Value,
        [string]$Name,
        [object]$Default = $null
    )

    if ($null -eq $Value) {
        return $Default
    }
    $property = $Value.PSObject.Properties[$Name]
    if ($null -eq $property) {
        return $Default
    }
    return $property.Value
}

function Write-BridgeJsonAtomic {
    param(
        [string]$Path,
        [object]$Value
    )

    $parent = Split-Path -Parent $Path
    if (-not (Test-Path -LiteralPath $parent -PathType Container)) {
        New-Item -ItemType Directory -Path $parent -Force | Out-Null
    }
    $temporaryPath = "$Path.tmp-$([guid]::NewGuid().ToString('N'))"
    $json = $Value | ConvertTo-Json -Depth 10
    [IO.File]::WriteAllText($temporaryPath, $json, [Text.UTF8Encoding]::new($false))
    Move-Item -LiteralPath $temporaryPath -Destination $Path -Force
}

function Read-TwilightBridgeProfile {
    param([string]$RepoRoot)

    $profilePath = Join-Path $RepoRoot 'integrations\twilight\v1.1.2.json'
    $profile = Read-BridgeJson -Path $profilePath
    if (-not $profile) {
        throw "Compatibility profile is missing or invalid: $profilePath"
    }

    $required = @(
        'releaseTag', 'sourceCommit', 'upstreamUrl', 'exeName', 'exeVersion',
        'asarRelativePath', 'originalAsarSha256', 'patchRelativePath',
        'discoveryFile', 'bridgeVersion'
    )
    foreach ($name in $required) {
        if ($null -eq $profile.$name -or [string]::IsNullOrWhiteSpace([string]$profile.$name)) {
            throw "Compatibility profile field is missing: $name"
        }
    }
    if ([int]$profile.bridgeVersion -ne 1) {
        throw 'Only taskbar bridge version 1 is supported.'
    }
    return $profile
}

function Normalize-TwilightInstallDir {
    param([string]$Path)

    $fullPath = [IO.Path]::GetFullPath($Path)
    $separators = [char[]]@('\', '/')
    $trimmedPath = $fullPath.TrimEnd($separators)
    $rootPath = [IO.Path]::GetPathRoot($fullPath)
    $trimmedRoot = $rootPath.TrimEnd($separators)
    if ([string]::Equals($trimmedPath, $trimmedRoot, [StringComparison]::OrdinalIgnoreCase)) {
        return $rootPath
    }
    return $trimmedPath
}

function Resolve-TwilightInstallDir {
    param(
        [string]$InstallDir,
        [string]$ExeName
    )

    if ($InstallDir) {
        return Normalize-TwilightInstallDir -Path $InstallDir
    }

    $candidates = New-Object 'System.Collections.Generic.List[string]'
    $defaultDir = 'D:\TwilightEcho'
    if (Test-Path -LiteralPath (Join-Path $defaultDir $ExeName) -PathType Leaf) {
        $candidates.Add((Normalize-TwilightInstallDir -Path $defaultDir))
    }

    $processName = [IO.Path]::GetFileNameWithoutExtension($ExeName)
    foreach ($process in @(Get-Process -Name $processName -ErrorAction SilentlyContinue)) {
        try {
            if ($process.Path) {
                $candidate = Normalize-TwilightInstallDir -Path (Split-Path -Parent $process.Path)
                if (-not $candidates.Contains($candidate)) {
                    $candidates.Add($candidate)
                }
            }
        } catch {
        }
    }

    if ($candidates.Count -eq 1) {
        return $candidates[0]
    }
    if ($candidates.Count -eq 0) {
        throw 'Twilight Echo installation was not found. Pass -InstallDir explicitly.'
    }
    throw "Multiple Twilight Echo installations were found. Pass -InstallDir explicitly: $($candidates -join ', ')"
}

function Get-TwilightBridgePaths {
    param(
        [string]$RepoRoot,
        [string]$InstallDir,
        [object]$Profile,
        [hashtable]$Adapters
    )

    $stateRoot = "$InstallDir.taskbar-bridge"
    [pscustomobject]@{
        Exe = Join-Path $InstallDir ([string]$Profile.exeName)
        Asar = Join-Path $InstallDir (([string]$Profile.asarRelativePath) -replace '/', '\')
        Discovery = [string](& $Adapters.GetDiscoveryPath $Profile)
        StateRoot = $stateRoot
        State = Join-Path $stateRoot 'state.json'
        WorkRoot = Join-Path $RepoRoot 'work\twilight-bridge'
        Patch = Join-Path $RepoRoot (([string]$Profile.patchRelativePath) -replace '/', '\')
    }
}

function Invoke-NativeChecked {
    param(
        [string]$FilePath,
        [string[]]$Arguments,
        [string]$WorkingDirectory,
        [string]$LogPath
    )

    Push-Location $WorkingDirectory
    try {
        $output = & $FilePath @Arguments 2>&1
        if ($output) {
            $output | Out-File -LiteralPath $LogPath -Append -Encoding UTF8
        }
        if ($LASTEXITCODE -ne 0) {
            throw "$FilePath failed with exit code $LASTEXITCODE. See $LogPath"
        }
        return @($output)
    } finally {
        Pop-Location
    }
}

function New-AppAsarBuilderConfig {
    param(
        [string]$SourcePath,
        [string]$DestinationPath
    )

    $yaml = [IO.File]::ReadAllText($SourcePath)
    $afterPackPattern = '(?m)^afterPack:[^\r\n]*(?:\r?\n|$)'
    $matches = [regex]::Matches($yaml, $afterPackPattern)
    if ($matches.Count -ne 1) {
        throw "Expected exactly one top-level afterPack entry in $SourcePath; found $($matches.Count)."
    }
    $packagingOnlyYaml = [regex]::Replace($yaml, $afterPackPattern, '', 1)
    [IO.File]::WriteAllText(
        $DestinationPath,
        $packagingOnlyYaml,
        [Text.UTF8Encoding]::new($false)
    )
}

function Build-TwilightPatchedAsar {
    param([hashtable]$Context)

    $profile = $Context.Profile
    $workRoot = $Context.Paths.WorkRoot
    New-Item -ItemType Directory -Path $workRoot -Force | Out-Null
    $runRoot = Join-Path $workRoot ("run-" + [guid]::NewGuid().ToString('N'))
    $sourceRoot = Join-Path $runRoot 'source'
    $Context.BuildWorkDir = $runRoot
    New-Item -ItemType Directory -Path $runRoot -Force | Out-Null
    $logPath = Join-Path $runRoot 'build.log'

    if (-not (Get-Command git -ErrorAction SilentlyContinue)) {
        throw 'Git is required to prepare the pinned Twilight Echo source.'
    }
    if (-not (Get-Command corepack -ErrorAction SilentlyContinue)) {
        throw 'Corepack is required to run the pinned pnpm toolchain.'
    }

    Invoke-NativeChecked -FilePath 'git' -Arguments @(
        'clone', '--filter=blob:none', '--branch', [string]$profile.releaseTag,
        '--single-branch', '--no-checkout',
        [string]$profile.upstreamUrl, $sourceRoot
    ) -WorkingDirectory $runRoot -LogPath $logPath | Out-Null
    Invoke-NativeChecked -FilePath 'git' -Arguments @(
        '-C', $sourceRoot, 'checkout', '--detach', [string]$profile.sourceCommit
    ) -WorkingDirectory $runRoot -LogPath $logPath | Out-Null

    $headOutput = Invoke-NativeChecked -FilePath 'git' -Arguments @(
        '-C', $sourceRoot, 'rev-parse', 'HEAD'
    ) -WorkingDirectory $runRoot -LogPath $logPath
    $head = ([string]($headOutput | Select-Object -Last 1)).Trim()
    if ($head -ne [string]$profile.sourceCommit) {
        throw "Pinned source commit mismatch: expected $($profile.sourceCommit), got $head"
    }

    Invoke-NativeChecked -FilePath 'git' -Arguments @(
        '-C', $sourceRoot, 'apply', '--check', $Context.Paths.Patch
    ) -WorkingDirectory $runRoot -LogPath $logPath | Out-Null
    Invoke-NativeChecked -FilePath 'git' -Arguments @(
        '-C', $sourceRoot, 'apply', $Context.Paths.Patch
    ) -WorkingDirectory $runRoot -LogPath $logPath | Out-Null

    Invoke-NativeChecked -FilePath 'corepack' -Arguments @(
        'pnpm', 'install', '--frozen-lockfile'
    ) -WorkingDirectory $sourceRoot -LogPath $logPath | Out-Null
    Invoke-NativeChecked -FilePath 'corepack' -Arguments @(
        'pnpm', 'exec', 'node', '--experimental-strip-types', '--test',
        'src/main/integrations/taskbarBridge.test.ts'
    ) -WorkingDirectory $sourceRoot -LogPath $logPath | Out-Null
    Invoke-NativeChecked -FilePath 'corepack' -Arguments @(
        'pnpm', 'run', 'build'
    ) -WorkingDirectory $sourceRoot -LogPath $logPath | Out-Null

    $packagingConfigName = 'electron-builder.taskbar-bridge.yml'
    $packagingConfigPath = Join-Path $sourceRoot $packagingConfigName
    New-AppAsarBuilderConfig `
        -SourcePath (Join-Path $sourceRoot 'electron-builder.yml') `
        -DestinationPath $packagingConfigPath
    Invoke-NativeChecked -FilePath 'corepack' -Arguments @(
        'pnpm', 'exec', 'electron-builder', '--dir', '--config', $packagingConfigName
    ) -WorkingDirectory $sourceRoot -LogPath $logPath | Out-Null

    $asarPath = Join-Path $sourceRoot 'dist\win-unpacked\resources\app.asar'
    if (-not (Test-Path -LiteralPath $asarPath -PathType Leaf)) {
        throw "Build completed without producing app.asar: $asarPath"
    }
    [pscustomobject]@{
        AsarPath = $asarPath
        WorkDir = $runRoot
    }
}

function Stop-TwilightApp {
    param([string]$ExePath)

    $target = [IO.Path]::GetFullPath($ExePath)
    $name = [IO.Path]::GetFileNameWithoutExtension($ExePath)
    $matches = @()
    foreach ($process in @(Get-Process -Name $name -ErrorAction SilentlyContinue)) {
        try {
            if ($process.Path -and [string]::Equals(
                    [IO.Path]::GetFullPath($process.Path),
                    $target,
                    [StringComparison]::OrdinalIgnoreCase)) {
                $matches += $process
            }
        } catch {
        }
    }
    if ($matches.Count -eq 0) {
        return $false
    }

    foreach ($process in $matches) {
        [void]$process.CloseMainWindow()
    }
    foreach ($process in $matches) {
        if (-not $process.WaitForExit(10000)) {
            throw 'Twilight Echo did not close gracefully; no files were replaced.'
        }
    }
    return $true
}

function Test-TwilightAppRunning {
    param([string]$ExePath)

    $target = [IO.Path]::GetFullPath($ExePath)
    $name = [IO.Path]::GetFileNameWithoutExtension($ExePath)
    foreach ($process in @(Get-Process -Name $name -ErrorAction SilentlyContinue)) {
        try {
            if ($process.Path -and [string]::Equals(
                    [IO.Path]::GetFullPath($process.Path),
                    $target,
                    [StringComparison]::OrdinalIgnoreCase)) {
                return $true
            }
        } catch {
        }
    }
    return $false
}

function Start-TwilightApp {
    param([string]$ExePath)

    Start-Process -FilePath $ExePath | Out-Null
}

function Test-TwilightBridgeHealth {
    param(
        [string]$DiscoveryPath,
        [object]$Profile
    )

    for ($attempt = 0; $attempt -lt 20; $attempt++) {
        try {
            $discovery = Read-BridgeJson -Path $DiscoveryPath
            $discoveryVersion = [int](Get-BridgeProperty $discovery 'bridgeVersion' 0)
            $token = [string](Get-BridgeProperty $discovery 'token' '')
            $instanceId = [string](Get-BridgeProperty $discovery 'instanceId' '')
            if ($discovery -and
                $discoveryVersion -eq [int]$Profile.bridgeVersion -and
                -not [string]::IsNullOrWhiteSpace($token) -and
                -not [string]::IsNullOrWhiteSpace($instanceId)) {
                $baseUrl = [string](Get-BridgeProperty $discovery 'baseUrl' '')
                if ([string]::IsNullOrWhiteSpace($baseUrl)) {
                    $hostName = [string](Get-BridgeProperty $discovery 'host' '')
                    $port = [int](Get-BridgeProperty $discovery 'port' 0)
                    $path = [string](Get-BridgeProperty $discovery 'path' '')
                    if ([string]::IsNullOrWhiteSpace($hostName) -or $port -lt 1 -or $port -gt 65535) {
                        throw 'Taskbar bridge discovery has no usable baseUrl or host/port.'
                    }
                    if ([string]::IsNullOrWhiteSpace($path)) {
                        $path = '/taskbar/v1'
                    }
                    $baseUrl = "http://${hostName}:$port/$($path.Trim('/'))"
                }
                $baseUri = [Uri]$baseUrl
                $loopbackHost = $baseUri.Host -eq 'localhost' -or
                    $baseUri.Host -eq '127.0.0.1' -or
                    $baseUri.Host -eq '::1'
                if ($baseUri.Scheme -ne 'http' -or -not $loopbackHost) {
                    throw 'Taskbar bridge discovery points outside loopback.'
                }
                $healthUri = $baseUrl.TrimEnd('/') + '/health'
                $headers = @{ Authorization = "Bearer $token" }
                $body = Invoke-RestMethod -Method Get -Uri $healthUri -Headers $headers -TimeoutSec 2
                if ([int](Get-BridgeProperty $body 'bridgeVersion' 0) -eq [int]$Profile.bridgeVersion -and
                    [string](Get-BridgeProperty $body 'instanceId' '') -eq $instanceId -and
                    [string](Get-BridgeProperty $body 'status' '') -eq 'ok') {
                    return [pscustomobject]@{
                        Healthy = $true
                        Body = $body
                        InstanceId = $instanceId
                    }
                }
            }
        } catch {
        }
        Start-Sleep -Milliseconds 500
    }
    return [pscustomobject]@{ Healthy = $false; Body = $null }
}

function New-DefaultTwilightBridgeAdapters {
    @{
        GetDiscoveryPath = {
            param([object]$Profile)
            if ([string]::IsNullOrWhiteSpace([string]$env:APPDATA)) {
                throw 'APPDATA is unavailable; taskbar bridge discovery cannot be located.'
            }
            Join-Path (Join-Path $env:APPDATA 'TwilightEcho') ([string]$Profile.discoveryFile)
        }
        GetExeVersion = {
            param([string]$Path)
            [string](Get-Item -LiteralPath $Path).VersionInfo.FileVersion
        }
        GetSha256 = {
            param([string]$Path)
            [string](Get-FileHash -LiteralPath $Path -Algorithm SHA256).Hash.ToUpperInvariant()
        }
        IsAppRunning = {
            param([string]$ExePath)
            Test-TwilightAppRunning -ExePath $ExePath
        }
        PreparePatchedAsar = {
            param([hashtable]$Context)
            Build-TwilightPatchedAsar -Context $Context
        }
        StopApp = {
            param([string]$ExePath)
            Stop-TwilightApp -ExePath $ExePath
        }
        StartApp = {
            param([string]$ExePath)
            Start-TwilightApp -ExePath $ExePath
        }
        Probe = {
            param([string]$DiscoveryPath, [object]$Profile)
            Test-TwilightBridgeHealth -DiscoveryPath $DiscoveryPath -Profile $Profile
        }
        CleanupWorkDir = {
            param([string]$WorkDir, [string]$WorkRoot)
            Remove-BridgeWorkDirectory -WorkDir $WorkDir -WorkRoot $WorkRoot
        }
    }
}

function Merge-TwilightBridgeAdapters {
    param([hashtable]$Overrides)

    $adapters = New-DefaultTwilightBridgeAdapters
    if ($Overrides) {
        foreach ($name in $Overrides.Keys) {
            if (-not $adapters.ContainsKey($name)) {
                throw "Unknown Twilight bridge adapter: $name"
            }
            $adapters[$name] = $Overrides[$name]
        }
    }
    return $adapters
}

function Get-TwilightInstallInspection {
    param(
        [object]$Profile,
        [object]$Paths,
        [hashtable]$Adapters
    )

    $state = Read-BridgeJson -Path $Paths.State
    if (-not (Test-Path -LiteralPath $Paths.Exe -PathType Leaf)) {
        return [pscustomobject]@{ Kind = 'missing'; Version = ''; Hash = ''; State = $state }
    }

    $version = [string](& $Adapters.GetExeVersion $Paths.Exe)

    if ($version -ne [string]$Profile.exeVersion) {
        return [pscustomobject]@{ Kind = 'unsupported_version'; Version = $version; Hash = ''; State = $state }
    }
    if (-not (Test-Path -LiteralPath $Paths.Asar -PathType Leaf)) {
        $backupPath = [string](Get-BridgeProperty $state 'backupPath' '')
        $stateMatches = $state -and
            [string](Get-BridgeProperty $state 'targetCommit' '') -eq [string]$Profile.sourceCommit -and
            [int](Get-BridgeProperty $state 'bridgeVersion' 0) -eq [int]$Profile.bridgeVersion
        if ($stateMatches -and (Test-Path -LiteralPath $backupPath -PathType Leaf)) {
            $backupHash = ([string](& $Adapters.GetSha256 $backupPath)).ToUpperInvariant()
            if ($backupHash -eq ([string]$Profile.originalAsarSha256).ToUpperInvariant()) {
                return [pscustomobject]@{
                    Kind = 'recovery_required'
                    Version = $version
                    Hash = ''
                    State = $state
                }
            }
        }
        return [pscustomobject]@{ Kind = 'missing'; Version = $version; Hash = ''; State = $state }
    }

    $hash = ([string](& $Adapters.GetSha256 $Paths.Asar)).ToUpperInvariant()
    if ($hash -eq ([string]$Profile.originalAsarSha256).ToUpperInvariant()) {
        return [pscustomobject]@{ Kind = 'original'; Version = $version; Hash = $hash; State = $state }
    }
    if ($state -and
        [string](Get-BridgeProperty $state 'targetCommit' '') -eq [string]$Profile.sourceCommit -and
        [int](Get-BridgeProperty $state 'bridgeVersion' 0) -eq [int]$Profile.bridgeVersion -and
        $hash -eq ([string](Get-BridgeProperty $state 'patchedAsarSha256' '')).ToUpperInvariant()) {
        return [pscustomobject]@{ Kind = 'managed'; Version = $version; Hash = $hash; State = $state }
    }
    return [pscustomobject]@{ Kind = 'unknown'; Version = $version; Hash = $hash; State = $state }
}

function Test-ProbeResult {
    param([object]$ProbeResult)

    if ($ProbeResult -is [bool]) {
        return [bool]$ProbeResult
    }
    return $null -ne $ProbeResult -and [bool]$ProbeResult.Healthy
}

function Remove-BridgeWorkDirectory {
    param(
        [string]$WorkDir,
        [string]$WorkRoot
    )

    if (-not $WorkDir -or -not (Test-Path -LiteralPath $WorkDir)) {
        return
    }
    $root = [IO.Path]::GetFullPath($WorkRoot).TrimEnd('\') + '\'
    $candidate = [IO.Path]::GetFullPath($WorkDir).TrimEnd('\') + '\'
    if (-not $candidate.StartsWith($root, [StringComparison]::OrdinalIgnoreCase)) {
        throw "Refusing to remove a directory outside the managed work root: $WorkDir"
    }
    Remove-Item -LiteralPath $WorkDir -Recurse -Force
}

function Invoke-BridgeWorkCleanup {
    param(
        [hashtable]$Context,
        [string]$WorkDir
    )

    if ([string]::IsNullOrWhiteSpace($WorkDir)) {
        return ''
    }
    try {
        & $Context.Adapters.CleanupWorkDir $WorkDir $Context.Paths.WorkRoot
        return ''
    } catch {
        return $_.Exception.Message
    }
}

function Invoke-TwilightBridgeStatus {
    param([hashtable]$Context)

    $inspectionParams = $Context.InspectionParams
    $inspection = Get-TwilightInstallInspection @inspectionParams
    $resultContext = $Context.ResultContext
    $resultContext.TwilightVersion = $inspection.Version

    switch ($inspection.Kind) {
        'recovery_required' {
            $resultContext.BackupPath = [string](Get-BridgeProperty $inspection.State 'backupPath' '')
            $resultContext.NextAction = 'Exit Twilight Echo from its tray icon, then run remove to restore backupPath.'
            return New-BridgeResult 'recovery_required' 'live_asar_missing' 35 $resultContext 'The managed app.asar is missing, but the pinned original backup is recoverable.'
        }
        'missing' {
            return New-BridgeResult 'blocked' 'install_not_found' 10 $resultContext 'Twilight Echo executable or app.asar is missing.'
        }
        'unsupported_version' {
            return New-BridgeResult 'blocked' 'unsupported_twilight_version' 20 $resultContext 'Only Twilight Echo 1.1.2 is supported.'
        }
        'unknown' {
            return New-BridgeResult 'blocked' 'unsupported_twilight_build' 20 $resultContext 'The installed app.asar is neither the supported original nor a deployment managed by this tool.'
        }
        'original' {
            return New-BridgeResult 'not_installed' 'compatible_original' 0 $resultContext
        }
        'managed' {
            $resultContext.BackupPath = [string](Get-BridgeProperty $inspection.State 'backupPath' '')
            $probe = & $Context.Adapters.Probe $Context.Paths.Discovery $Context.Profile
            if (Test-ProbeResult $probe) {
                return New-BridgeResult 'healthy' 'bridge_ready' 0 $resultContext
            }
            return New-BridgeResult 'degraded' 'bridge_unreachable' 21 $resultContext
        }
    }
}

function Invoke-TwilightBridgeEnsure {
    param([hashtable]$Context)

    $inspectionParams = $Context.InspectionParams
    $inspection = Get-TwilightInstallInspection @inspectionParams
    $resultContext = $Context.ResultContext
    $resultContext.TwilightVersion = $inspection.Version

    if ($inspection.Kind -eq 'managed' -or $inspection.Kind -eq 'recovery_required') {
        return Invoke-TwilightBridgeStatus -Context $Context
    }
    if ($inspection.Kind -eq 'missing') {
        return New-BridgeResult 'blocked' 'install_not_found' 10 $resultContext 'Twilight Echo executable or app.asar is missing.'
    }
    if ($inspection.Kind -eq 'unsupported_version') {
        return New-BridgeResult 'blocked' 'unsupported_twilight_version' 20 $resultContext 'Only Twilight Echo 1.1.2 is supported. No process was stopped.'
    }
    if ($inspection.Kind -ne 'original') {
        return New-BridgeResult 'blocked' 'unsupported_twilight_build' 20 $resultContext 'Unknown app.asar; no process was stopped and no files were changed.'
    }
    if (-not (Test-Path -LiteralPath $Context.Paths.Patch -PathType Leaf)) {
        return New-BridgeResult 'blocked' 'patch_missing' 23 $resultContext "Bridge patch is missing: $($Context.Paths.Patch)"
    }
    if ($Context.WhatIfMode) {
        return New-BridgeResult 'would_install' 'compatible_original' 0 $resultContext 'Compatibility checks passed; build and deployment were skipped by -WhatIf.'
    }
    if ([bool](& $Context.Adapters.IsAppRunning $Context.Paths.Exe)) {
        $resultContext.NextAction = 'Exit Twilight Echo from its tray icon, then run ensure again.'
        return New-BridgeResult 'blocked' 'close_twilight_required' 25 $resultContext 'Twilight Echo is still running. It was not stopped or killed.'
    }

    $prepared = $null
    try {
        $prepared = & $Context.Adapters.PreparePatchedAsar $Context
        if (-not $prepared -or -not (Test-Path -LiteralPath $prepared.AsarPath -PathType Leaf)) {
            throw 'The build adapter did not return a usable app.asar.'
        }
    } catch {
        $failureMessage = $_.Exception.Message
        $workDir = [string]$Context['BuildWorkDir']
        $cleanupFailure = Invoke-BridgeWorkCleanup -Context $Context -WorkDir $workDir
        if ($cleanupFailure) {
            $resultContext.NextAction = "Remove the incomplete build directory manually: $workDir"
            $failureMessage += " Cleanup failed: $cleanupFailure"
        }
        return New-BridgeResult 'blocked' 'build_failed' 30 $resultContext $failureMessage
    }

    if ([bool](& $Context.Adapters.IsAppRunning $Context.Paths.Exe)) {
        $workDir = [string](Get-BridgeProperty $prepared 'WorkDir' '')
        $cleanupFailure = Invoke-BridgeWorkCleanup -Context $Context -WorkDir $workDir
        $resultContext.NextAction = 'Exit Twilight Echo from its tray icon, then run ensure again.'
        if ($cleanupFailure) {
            $resultContext.NextAction += " Also remove the incomplete build directory: $workDir"
        }
        return New-BridgeResult 'blocked' 'close_twilight_required' 25 $resultContext 'Twilight Echo started while the bridge was being built; no installed files were changed.'
    }

    try {
        $patchedHash = ([string](& $Context.Adapters.GetSha256 $prepared.AsarPath)).ToUpperInvariant()
    } catch {
        $failureMessage = $_.Exception.Message
        $workDir = [string](Get-BridgeProperty $prepared 'WorkDir' '')
        $cleanupFailure = Invoke-BridgeWorkCleanup -Context $Context -WorkDir $workDir
        if ($cleanupFailure) {
            $resultContext.NextAction = "Remove the incomplete build directory manually: $workDir"
            $failureMessage += " Cleanup failed: $cleanupFailure"
        }
        return New-BridgeResult 'blocked' 'build_failed' 30 $resultContext $failureMessage
    }
    $deploymentId = (Get-Date -Format 'yyyyMMdd-HHmmss') + '-' + [guid]::NewGuid().ToString('N').Substring(0, 8)
    $backupDir = Join-Path $Context.Paths.StateRoot ("backups\$deploymentId")
    $backupAsar = Join-Path $backupDir 'app.asar'
    $incomingAsar = Join-Path (Split-Path -Parent $Context.Paths.Asar) ("app.asar.incoming-$deploymentId")
    $resultContext.BackupPath = $backupAsar
    $originalMoved = $false
    $patchedStarted = $false

    $state = [ordered]@{
        schemaVersion = 1
        phase = 'prepared'
        deploymentId = $deploymentId
        targetRelease = [string]$Context.Profile.releaseTag
        targetCommit = [string]$Context.Profile.sourceCommit
        bridgeVersion = [int]$Context.Profile.bridgeVersion
        originalAsarSha256 = [string]$Context.Profile.originalAsarSha256
        patchedAsarSha256 = $patchedHash
        backupPath = $backupAsar
        installedAt = (Get-Date).ToUniversalTime().ToString('o')
    }

    try {
        New-Item -ItemType Directory -Path $backupDir -Force | Out-Null
        Write-BridgeJsonAtomic -Path $Context.Paths.State -Value $state

        Move-Item -LiteralPath $Context.Paths.Asar -Destination $backupAsar
        $originalMoved = $true
        $state.phase = 'swapping'
        Write-BridgeJsonAtomic -Path $Context.Paths.State -Value $state

        Copy-Item -LiteralPath $prepared.AsarPath -Destination $incomingAsar
        $incomingHash = ([string](& $Context.Adapters.GetSha256 $incomingAsar)).ToUpperInvariant()
        if ($incomingHash -ne $patchedHash) {
            throw 'The staged app.asar changed while it was copied.'
        }
        Move-Item -LiteralPath $incomingAsar -Destination $Context.Paths.Asar
        $state.phase = 'probing'
        Write-BridgeJsonAtomic -Path $Context.Paths.State -Value $state
        & $Context.Adapters.StartApp $Context.Paths.Exe
        $patchedStarted = $true
        $probe = & $Context.Adapters.Probe $Context.Paths.Discovery $Context.Profile
        if (-not (Test-ProbeResult $probe)) {
            throw 'The patched application started, but taskbar bridge health validation failed.'
        }

        $state.phase = 'installed'
        Write-BridgeJsonAtomic -Path $Context.Paths.State -Value $state
    } catch {
        $failureMessage = $_.Exception.Message
        try {
            if ($patchedStarted) {
                [void](& $Context.Adapters.StopApp $Context.Paths.Exe)
            }
            if (Test-Path -LiteralPath $incomingAsar -PathType Leaf) {
                Remove-Item -LiteralPath $incomingAsar -Force
            }
            if ($originalMoved) {
                if (Test-Path -LiteralPath $Context.Paths.Asar -PathType Leaf) {
                    Remove-Item -LiteralPath $Context.Paths.Asar -Force
                }
                Move-Item -LiteralPath $backupAsar -Destination $Context.Paths.Asar
            }
            if (Test-Path -LiteralPath $Context.Paths.State -PathType Leaf) {
                Remove-Item -LiteralPath $Context.Paths.State -Force
            }
            $workDir = [string](Get-BridgeProperty $prepared 'WorkDir' '')
            $cleanupFailure = Invoke-BridgeWorkCleanup -Context $Context -WorkDir $workDir
            if ($cleanupFailure) {
                $resultContext.NextAction = "Remove the incomplete build directory manually: $workDir"
                return New-BridgeResult 'rolled_back' 'deployment_failed_cleanup_pending' 31 $resultContext "$failureMessage Cleanup failed: $cleanupFailure"
            }
            return New-BridgeResult 'rolled_back' 'deployment_failed' 31 $resultContext $failureMessage
        } catch {
            $rollbackMessage = $_.Exception.Message
            $workDir = [string](Get-BridgeProperty $prepared 'WorkDir' '')
            $cleanupFailure = Invoke-BridgeWorkCleanup -Context $Context -WorkDir $workDir
            $resultContext.NextAction = 'Restore backupPath to resources\app.asar while Twilight Echo is closed.'
            if ($cleanupFailure) {
                $resultContext.NextAction += " Also remove the incomplete build directory: $workDir"
            }
            return New-BridgeResult 'failed' 'manual_restore_required' 32 $resultContext "$failureMessage Rollback failed: $rollbackMessage"
        }
    }

    $workDir = [string](Get-BridgeProperty $prepared 'WorkDir' '')
    $cleanupFailure = Invoke-BridgeWorkCleanup -Context $Context -WorkDir $workDir
    if ($cleanupFailure) {
        $resultContext.NextAction = "Remove the completed build directory manually: $workDir"
        return New-BridgeResult 'installed' 'cleanup_pending' 0 $resultContext "Bridge is healthy; cleanup failed: $cleanupFailure"
    }
    return New-BridgeResult 'installed' 'bridge_ready' 0 $resultContext
}

function Invoke-TwilightBridgeRemove {
    param([hashtable]$Context)

    $inspectionParams = $Context.InspectionParams
    $inspection = Get-TwilightInstallInspection @inspectionParams
    $resultContext = $Context.ResultContext
    $resultContext.TwilightVersion = $inspection.Version

    if ($inspection.Kind -eq 'original') {
        return New-BridgeResult 'not_installed' 'compatible_original' 0 $resultContext
    }
    if ($inspection.Kind -eq 'recovery_required') {
        $backupAsar = [string](Get-BridgeProperty $inspection.State 'backupPath' '')
        $resultContext.BackupPath = $backupAsar
        if ([bool](& $Context.Adapters.IsAppRunning $Context.Paths.Exe)) {
            $resultContext.NextAction = 'Exit Twilight Echo from its tray icon, then run remove again.'
            return New-BridgeResult 'blocked' 'close_twilight_required' 25 $resultContext 'Twilight Echo is still running. It was not stopped or killed.'
        }
        if ($Context.WhatIfMode) {
            return New-BridgeResult 'would_recover' 'live_asar_missing' 0 $resultContext 'The pinned original app.asar can be restored; -WhatIf made no changes.'
        }
        try {
            $asarParent = Split-Path -Parent $Context.Paths.Asar
            if (-not (Test-Path -LiteralPath $asarParent -PathType Container)) {
                New-Item -ItemType Directory -Path $asarParent -Force | Out-Null
            }
            Move-Item -LiteralPath $backupAsar -Destination $Context.Paths.Asar
            if (Test-Path -LiteralPath $Context.Paths.State -PathType Leaf) {
                Remove-Item -LiteralPath $Context.Paths.State -Force
            }
            return New-BridgeResult 'removed' 'original_restored_from_recovery' 0 $resultContext
        } catch {
            $resultContext.NextAction = 'Restore backupPath to resources\app.asar while Twilight Echo is closed.'
            return New-BridgeResult 'recovery_required' 'restore_failed' 35 $resultContext $_.Exception.Message
        }
    }
    if ($inspection.Kind -ne 'managed') {
        $reason = if ($inspection.Kind -eq 'missing') { 'install_not_found' } else { 'install_changed' }
        return New-BridgeResult 'blocked' $reason 20 $resultContext 'The current installation is not the exact managed bridge build; no older app.asar was restored.'
    }

    $backupAsar = [string](Get-BridgeProperty $inspection.State 'backupPath' '')
    $resultContext.BackupPath = $backupAsar
    if (-not (Test-Path -LiteralPath $backupAsar -PathType Leaf)) {
        $resultContext.NextAction = 'Locate the recorded original app.asar backup before removing the bridge.'
        return New-BridgeResult 'blocked' 'backup_missing' 33 $resultContext
    }
    $backupHash = ([string](& $Context.Adapters.GetSha256 $backupAsar)).ToUpperInvariant()
    if ($backupHash -ne ([string]$Context.Profile.originalAsarSha256).ToUpperInvariant()) {
        return New-BridgeResult 'blocked' 'backup_mismatch' 33 $resultContext 'The backup is not the pinned v1.1.2 original app.asar.'
    }
    if ([bool](& $Context.Adapters.IsAppRunning $Context.Paths.Exe)) {
        $resultContext.NextAction = 'Exit Twilight Echo from its tray icon, then run remove again.'
        return New-BridgeResult 'blocked' 'close_twilight_required' 25 $resultContext 'Twilight Echo is still running. It was not stopped or killed.'
    }
    if ($Context.WhatIfMode) {
        return New-BridgeResult 'would_remove' 'managed_install' 0 $resultContext 'Restore was skipped by -WhatIf.'
    }

    $removedAsar = Join-Path $Context.Paths.StateRoot ("removed-patched-$([guid]::NewGuid().ToString('N')).asar")
    try {
        Move-Item -LiteralPath $Context.Paths.Asar -Destination $removedAsar
        Move-Item -LiteralPath $backupAsar -Destination $Context.Paths.Asar
        Remove-Item -LiteralPath $removedAsar -Force
        Remove-Item -LiteralPath $Context.Paths.State -Force
        return New-BridgeResult 'removed' 'original_restored' 0 $resultContext
    } catch {
        $failureMessage = $_.Exception.Message
        try {
            if (-not (Test-Path -LiteralPath $Context.Paths.Asar -PathType Leaf) -and
                (Test-Path -LiteralPath $removedAsar -PathType Leaf)) {
                Move-Item -LiteralPath $removedAsar -Destination $Context.Paths.Asar
            }
        } catch {
            $resultContext.NextAction = 'Restore backupPath to resources\app.asar while Twilight Echo is closed.'
            return New-BridgeResult 'failed' 'manual_restore_required' 32 $resultContext "$failureMessage Recovery failed: $($_.Exception.Message)"
        }
        return New-BridgeResult 'blocked' 'remove_failed' 34 $resultContext $failureMessage
    }
}

function Invoke-TwilightBridgeDeployment {
    [CmdletBinding()]
    param(
        [Parameter(Mandatory = $true)]
        [ValidateSet('ensure', 'status', 'remove')]
        [string]$Action,

        [Parameter(Mandatory = $true)]
        [string]$RepoRoot,

        [string]$InstallDir,
        [switch]$WhatIfMode,
        [hashtable]$Adapters
    )

    $repoPath = [IO.Path]::GetFullPath($RepoRoot)
    $profile = Read-TwilightBridgeProfile -RepoRoot $repoPath
    try {
        $installPath = Resolve-TwilightInstallDir -InstallDir $InstallDir -ExeName ([string]$profile.exeName)
    } catch {
        $resultContext = @{
            TwilightVersion = ''
            TargetCommit = [string]$profile.sourceCommit
            BridgeVersion = [int]$profile.bridgeVersion
            InstallDir = $InstallDir
            BackupPath = ''
            NextAction = 'Pass -InstallDir with the Twilight Echo installation directory.'
        }
        return New-BridgeResult 'blocked' 'install_not_found_or_ambiguous' 10 $resultContext $_.Exception.Message
    }

    $resolvedAdapters = Merge-TwilightBridgeAdapters -Overrides $Adapters
    $paths = Get-TwilightBridgePaths -RepoRoot $repoPath -InstallDir $installPath -Profile $profile -Adapters $resolvedAdapters
    $resultContext = @{
        TwilightVersion = ''
        TargetCommit = [string]$profile.sourceCommit
        BridgeVersion = [int]$profile.bridgeVersion
        InstallDir = $installPath
        BackupPath = ''
        NextAction = $null
    }
    $context = @{
        Profile = $profile
        Paths = $paths
        Adapters = $resolvedAdapters
        WhatIfMode = [bool]$WhatIfMode
        ResultContext = $resultContext
        InspectionParams = @{
            Profile = $profile
            Paths = $paths
            Adapters = $resolvedAdapters
        }
    }

    switch ($Action) {
        'ensure' { return Invoke-TwilightBridgeEnsure -Context $context }
        'status' { return Invoke-TwilightBridgeStatus -Context $context }
        'remove' { return Invoke-TwilightBridgeRemove -Context $context }
    }
}

Export-ModuleMember -Function Invoke-TwilightBridgeDeployment

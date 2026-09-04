[CmdletBinding()]
param()

$ErrorActionPreference = 'Stop'
$repoRoot = Split-Path -Parent (Split-Path -Parent $PSScriptRoot)
$modulePath = Join-Path $PSScriptRoot 'deploy.psm1'
$profilePath = Join-Path $PSScriptRoot 'v1.1.2.json'
$entryPath = Join-Path $repoRoot 'tools\twilight-bridge.ps1'
Import-Module -Name $modulePath -Force

function Assert-True {
    param([bool]$Condition, [string]$Message)
    if (-not $Condition) {
        throw "ASSERTION FAILED: $Message"
    }
}

function Assert-Equal {
    param([object]$Actual, [object]$Expected, [string]$Message)
    if ($Actual -ne $Expected) {
        throw "ASSERTION FAILED: $Message (expected '$Expected', got '$Actual')"
    }
}

function Write-TestText {
    param([string]$Path, [string]$Value)
    $parent = Split-Path -Parent $Path
    if (-not (Test-Path -LiteralPath $parent -PathType Container)) {
        New-Item -ItemType Directory -Path $parent -Force | Out-Null
    }
    [IO.File]::WriteAllText($Path, $Value, [Text.UTF8Encoding]::new($false))
}

function New-TestFixture {
    param([string]$Root, [string]$Name)

    $fixtureRoot = Join-Path $Root $Name
    $fixtureRepo = Join-Path $fixtureRoot 'repo'
    $fixtureProfileDir = Join-Path $fixtureRepo 'integrations\twilight'
    $installDir = Join-Path $fixtureRoot 'TwilightEcho'
    $asarPath = Join-Path $installDir 'resources\app.asar'
    $exePath = Join-Path $installDir 'TwilightEcho.exe'
    $discoveryPath = Join-Path $fixtureRoot 'runtime\TwilightEcho\taskbar-bridge.json'
    $patchPath = Join-Path $fixtureProfileDir 'v1.1.2.patch'

    New-Item -ItemType Directory -Path $fixtureProfileDir -Force | Out-Null
    Copy-Item -LiteralPath $profilePath -Destination (Join-Path $fixtureProfileDir 'v1.1.2.json')
    Write-TestText -Path $patchPath -Value 'fake patch used only through the build adapter'
    Write-TestText -Path $exePath -Value 'fake executable'
    Write-TestText -Path $asarPath -Value 'original'

    $control = @{
        ExeVersion = '1.1.2'
        PatchedHash = ('A' * 64)
        PrepareCalls = 0
        StopCalls = 0
        StartCalls = 0
        ProbeCalls = 0
        ProbeHealthy = $true
        Running = $false
        PrepareFails = $false
        CleanupFails = $false
        CleanupCalls = 0
        LastDiscoveryPath = ''
    }
    $profile = Get-Content -LiteralPath $profilePath -Raw -Encoding UTF8 | ConvertFrom-Json
    $workDir = Join-Path $fixtureRepo 'work\twilight-bridge\fake-run'
    $preparedAsar = Join-Path $workDir 'app.asar'

    $getDiscoveryPath = {
        param([object]$IgnoredProfile)
        return $discoveryPath
    }.GetNewClosure()
    $getExeVersion = {
        param([string]$IgnoredPath)
        return [string]$control.ExeVersion
    }.GetNewClosure()
    $getSha256 = {
        param([string]$Path)
        $content = [IO.File]::ReadAllText($Path)
        if ($content -eq 'original') {
            return ([string]$profile.originalAsarSha256).ToUpperInvariant()
        }
        if ($content -eq 'patched') {
            return [string]$control.PatchedHash
        }
        if ($content -eq 'unknown') {
            return ('B' * 64)
        }
        throw "Unexpected fake app.asar content at $Path"
    }.GetNewClosure()
    $prepare = {
        param([hashtable]$BuildContext)
        [void]($control.PrepareCalls++)
        $BuildContext.BuildWorkDir = $workDir
        [IO.Directory]::CreateDirectory([IO.Path]::GetDirectoryName($preparedAsar)) | Out-Null
        if ($control.PrepareFails) {
            throw 'fake build failure'
        }
        [IO.File]::WriteAllText($preparedAsar, 'patched', [Text.UTF8Encoding]::new($false))
        return [pscustomobject]@{ AsarPath = $preparedAsar; WorkDir = $workDir }
    }.GetNewClosure()
    $isRunning = {
        param([string]$IgnoredExe)
        return [bool]$control.Running
    }.GetNewClosure()
    $stop = {
        param([string]$IgnoredExe)
        if (-not $control.Running) {
            return $false
        }
        [void]($control.StopCalls++)
        $control.Running = $false
        return $true
    }.GetNewClosure()
    $start = {
        param([string]$IgnoredExe)
        [void]($control.StartCalls++)
        $control.Running = $true
    }.GetNewClosure()
    $cleanup = {
        param([string]$Path, [string]$WorkRoot)
        [void]($control.CleanupCalls++)
        if ($control.CleanupFails) {
            throw 'fake cleanup failure'
        }
        $root = [IO.Path]::GetFullPath($WorkRoot).TrimEnd('\') + '\'
        $candidate = [IO.Path]::GetFullPath($Path).TrimEnd('\') + '\'
        if (-not $candidate.StartsWith($root, [StringComparison]::OrdinalIgnoreCase)) {
            throw 'fake cleanup escaped its work root'
        }
        if (Test-Path -LiteralPath $Path -PathType Container) {
            Remove-Item -LiteralPath $Path -Recurse -Force
        }
    }.GetNewClosure()
    $probe = {
        param([string]$Path, [object]$IgnoredProfile)
        [void]($control.ProbeCalls++)
        $control.LastDiscoveryPath = $Path
        return [pscustomobject]@{
            Healthy = [bool]$control.ProbeHealthy
            InstanceId = 'fake-instance'
            Body = [pscustomobject]@{
                bridgeVersion = 1
                instanceId = 'fake-instance'
                status = 'ok'
            }
        }
    }.GetNewClosure()

    [pscustomobject]@{
        RepoRoot = $fixtureRepo
        InstallDir = $installDir
        AsarPath = $asarPath
        WorkDir = $workDir
        DiscoveryPath = $discoveryPath
        StatePath = "$installDir.taskbar-bridge\state.json"
        Control = $control
        Adapters = @{
            GetDiscoveryPath = $getDiscoveryPath
            GetExeVersion = $getExeVersion
            GetSha256 = $getSha256
            PreparePatchedAsar = $prepare
            IsAppRunning = $isRunning
            StopApp = $stop
            StartApp = $start
            Probe = $probe
            CleanupWorkDir = $cleanup
        }
    }
}

$testRoot = Join-Path ([IO.Path]::GetTempPath()) ("twilight-bridge-contract-" + [guid]::NewGuid().ToString('N'))
New-Item -ItemType Directory -Path $testRoot -Force | Out-Null

try {
    $profile = Get-Content -LiteralPath $profilePath -Raw -Encoding UTF8 | ConvertFrom-Json
    Assert-Equal $profile.releaseTag 'v1.1.2' 'release tag must be pinned'
    Assert-Equal $profile.sourceCommit '44516c33909e45f92ea661140f9cfb1e2b6ecbeb' 'source commit must be pinned'
    Assert-Equal $profile.exeVersion '1.1.2' 'executable version must be pinned'
    Assert-Equal $profile.originalAsarSha256 '54C5BA910CB060A52D6C53AEBF96295577F7F2A6D597B7FCCFBB9954D5D27562' 'original app.asar hash must be pinned'
    Assert-Equal ([int]$profile.bridgeVersion) 1 'bridge version must be 1'
    Assert-True (-not ($profile.PSObject.Properties.Name -contains 'bridgeProtocol')) 'legacy bridgeProtocol must not remain in the profile'
    Assert-Equal $profile.discoveryFile 'taskbar-bridge.json' 'discovery filename must be stable'
    Assert-Equal $profile.providerMethod 'likeTrack' 'favorite writes must use provider.likeTrack'
    Assert-True (-not ($profile.PSObject.Properties.Name -contains 'bridgeEndpoint')) 'profile must not pin a port or endpoint'

    $moduleSource = Get-Content -LiteralPath $modulePath -Raw -Encoding UTF8
    $entrySource = Get-Content -LiteralPath $entryPath -Raw -Encoding UTF8
    $healthSource = [regex]::Match(
        $moduleSource,
        'function Test-TwilightBridgeHealth[\s\S]*?(?=function New-DefaultTwilightBridgeAdapters)'
    ).Value
    $buildSource = [regex]::Match(
        $moduleSource,
        'function Build-TwilightPatchedAsar[\s\S]*?(?=function Stop-TwilightApp)'
    ).Value
    Assert-True (-not [string]::IsNullOrWhiteSpace($healthSource)) 'health implementation must be present'
    Assert-True ($moduleSource -match '\$env:APPDATA') 'runtime discovery must resolve below APPDATA'
    Assert-True ($moduleSource -match "'baseUrl'") 'probe must read the random baseUrl from discovery'
    Assert-True ($moduleSource -match "'host'" -and $moduleSource -match "'port'") 'probe must also accept discovered host and port'
    Assert-True ($moduleSource -match "'token'") 'probe must read the bearer token from discovery'
    Assert-True ($moduleSource -match "'instanceId'") 'probe must bind health to the discovered instanceId'
    Assert-True ($moduleSource -match 'Authorization\s*=\s*"Bearer') 'health requests must carry bearer authorization'
    Assert-True ($healthSource -match "'bridgeVersion'") 'health must validate bridgeVersion'
    Assert-True ($healthSource -match "'status'[^\r\n]+-eq 'ok'") 'health must require status ok'
    Assert-True ($healthSource -notmatch "'protocol'") 'health must not require the retired protocol field'
    Assert-True ($healthSource -notmatch "'targetRelease'") 'health must not require targetRelease'
    Assert-True ($moduleSource -notmatch '43967') 'deployment must not pin the old fixed port'
    Assert-True ($moduleSource -notmatch 'Write-BridgeJsonAtomic\s+-Path\s+\$Context\.Paths\.Discovery') 'deployment must not write runtime discovery'
    Assert-True ($moduleSource -notmatch 'Remove-Item[^\r\n]+Paths\.Discovery') 'deployment must not delete runtime discovery'
    Assert-True ($buildSource -match "'pnpm', 'run', 'build'") 'renderer/main build must run before packaging'
    Assert-True ($buildSource -match "'pnpm', 'exec', 'electron-builder', '--dir', '--config'") 'packaging must explicitly create an unpacked app.asar'
    Assert-True ($buildSource -notmatch 'build:unpack') 'the release unpack command with afterPack must not be used'
    Assert-True ($buildSource -notmatch 'Paths\.AudioEngine|twilight-audio-engine\.dll') 'app.asar-only packaging must not stage or strip native runtime files'
    Assert-True ($moduleSource -match 'Expected exactly one top-level afterPack entry') 'temporary packaging config must fail closed unless one afterPack entry is removed'
    Assert-True ($moduleSource -match 'close_twilight_required') 'running Twilight must have a stable blocked reason'
    Assert-True ($entrySource -match '\[string\]\$Action\s*=\s*''ensure''') 'the single entry must default to ensure'
    Assert-True ($entrySource -match 'SupportsShouldProcess\s*=\s*\$true') 'the entry must support -WhatIf'
    Assert-True ($entrySource -match 'ConvertTo-Json') 'the entry must emit JSON by default'

    $configSourcePath = Join-Path $testRoot 'electron-builder.yml'
    $configOutputPath = Join-Path $testRoot 'electron-builder.taskbar-bridge.yml'
    Write-TestText -Path $configSourcePath -Value "appId: test`nafterPack: scripts/after-pack.cjs`nfiles:`n  - out/**`n"
    $deployModule = Get-Module deploy
    & $deployModule {
        param($SourcePath, $DestinationPath)
        New-AppAsarBuilderConfig -SourcePath $SourcePath -DestinationPath $DestinationPath
    } $configSourcePath $configOutputPath
    $packagingYaml = [IO.File]::ReadAllText($configOutputPath)
    Assert-True ($packagingYaml -notmatch '(?m)^afterPack:') 'app.asar packaging config must remove the release afterPack hook'
    Assert-True ($packagingYaml -match 'files:') 'temporary config must preserve the rest of the pinned builder config'

    Write-TestText -Path $configSourcePath -Value "afterPack: first.cjs`nafterPack: second.cjs`n"
    $duplicateAfterPackRejected = $false
    try {
        & $deployModule {
            param($SourcePath, $DestinationPath)
            New-AppAsarBuilderConfig -SourcePath $SourcePath -DestinationPath $DestinationPath
        } $configSourcePath $configOutputPath
    } catch {
        $duplicateAfterPackRejected = $true
    }
    Assert-True $duplicateAfterPackRejected 'ambiguous afterPack config must fail instead of silently packaging'

    $normalizedVolumeRoot = & $deployModule {
        Normalize-TwilightInstallDir -Path 'D:\'
    }
    Assert-Equal $normalizedVolumeRoot 'D:\' 'volume roots must retain their trailing separator'

    $whatIfFixture = New-TestFixture -Root $testRoot -Name 'what-if'
    $whatIfResult = Invoke-TwilightBridgeDeployment -Action ensure `
        -RepoRoot $whatIfFixture.RepoRoot -InstallDir $whatIfFixture.InstallDir `
        -Adapters $whatIfFixture.Adapters -WhatIfMode
    Assert-Equal $whatIfResult.outcome 'would_install' 'compatible WhatIf must describe installation'
    Assert-Equal $whatIfFixture.Control.PrepareCalls 0 'WhatIf must not build'
    Assert-Equal $whatIfFixture.Control.StopCalls 0 'WhatIf must not stop Twilight Echo'
    Assert-Equal ([IO.File]::ReadAllText($whatIfFixture.AsarPath)) 'original' 'WhatIf must not replace app.asar'
    Assert-True (-not (Test-Path -LiteralPath $whatIfFixture.StatePath)) 'WhatIf must not create deployment state'

    $trailingFixture = New-TestFixture -Root $testRoot -Name 'trailing-install-dir'
    $trailingInstallDir = $trailingFixture.InstallDir + '\'
    $trailingResult = Invoke-TwilightBridgeDeployment -Action ensure `
        -RepoRoot $trailingFixture.RepoRoot -InstallDir $trailingInstallDir `
        -Adapters $trailingFixture.Adapters
    Assert-Equal $trailingResult.installDir $trailingFixture.InstallDir 'ordinary install paths must trim a trailing separator'
    Assert-True (Test-Path -LiteralPath $trailingFixture.StatePath -PathType Leaf) 'state root must remain beside the normalized install directory'
    $nestedStatePath = Join-Path $trailingFixture.InstallDir '.taskbar-bridge\state.json'
    Assert-True (-not (Test-Path -LiteralPath $nestedStatePath)) 'trailing separators must not move state inside the installation directory'

    $runningFixture = New-TestFixture -Root $testRoot -Name 'running-stock'
    $runningFixture.Control.Running = $true
    $runningResult = Invoke-TwilightBridgeDeployment -Action ensure `
        -RepoRoot $runningFixture.RepoRoot -InstallDir $runningFixture.InstallDir `
        -Adapters $runningFixture.Adapters
    Assert-Equal $runningResult.reason 'close_twilight_required' 'a tray-only stock process must block before build'
    Assert-Equal $runningFixture.Control.PrepareCalls 0 'running stock Twilight must block before build'
    Assert-Equal $runningFixture.Control.StopCalls 0 'deployment must not try to close or kill stock Twilight'

    $unsupportedFixture = New-TestFixture -Root $testRoot -Name 'unsupported'
    $unsupportedFixture.Control.ExeVersion = '1.1.3'
    $unsupportedResult = Invoke-TwilightBridgeDeployment -Action ensure `
        -RepoRoot $unsupportedFixture.RepoRoot -InstallDir $unsupportedFixture.InstallDir `
        -Adapters $unsupportedFixture.Adapters
    Assert-Equal $unsupportedResult.reason 'unsupported_twilight_version' 'future Twilight versions must fail closed'
    Assert-Equal $unsupportedFixture.Control.PrepareCalls 0 'unsupported versions must fail before build'
    Assert-Equal $unsupportedFixture.Control.StopCalls 0 'unsupported versions must fail before stopping the process'

    $buildFailureFixture = New-TestFixture -Root $testRoot -Name 'build-failure'
    $buildFailureFixture.Control.PrepareFails = $true
    $buildFailureResult = Invoke-TwilightBridgeDeployment -Action ensure `
        -RepoRoot $buildFailureFixture.RepoRoot -InstallDir $buildFailureFixture.InstallDir `
        -Adapters $buildFailureFixture.Adapters
    Assert-Equal $buildFailureResult.reason 'build_failed' 'build errors must not be swallowed'
    Assert-Equal $buildFailureFixture.Control.StopCalls 0 'build failure must occur before process changes'
    Assert-Equal $buildFailureFixture.Control.CleanupCalls 1 'build failure must attempt run-directory cleanup'
    Assert-True (-not (Test-Path -LiteralPath $buildFailureFixture.WorkDir)) 'successful cleanup must remove failed run directory'

    $buildCleanupFixture = New-TestFixture -Root $testRoot -Name 'build-cleanup-pending'
    $buildCleanupFixture.Control.PrepareFails = $true
    $buildCleanupFixture.Control.CleanupFails = $true
    $buildCleanupResult = Invoke-TwilightBridgeDeployment -Action ensure `
        -RepoRoot $buildCleanupFixture.RepoRoot -InstallDir $buildCleanupFixture.InstallDir `
        -Adapters $buildCleanupFixture.Adapters
    Assert-Equal $buildCleanupResult.reason 'build_failed' 'cleanup failure must not hide the original build failure'
    Assert-True (-not [string]::IsNullOrWhiteSpace([string]$buildCleanupResult.nextAction)) 'failed build cleanup must report its exact run directory'
    Assert-True (Test-Path -LiteralPath $buildCleanupFixture.WorkDir -PathType Container) 'failed build cleanup must leave the reported run directory'

    $rollbackFixture = New-TestFixture -Root $testRoot -Name 'rollback'
    $rollbackFixture.Control.ProbeHealthy = $false
    $rollbackResult = Invoke-TwilightBridgeDeployment -Action ensure `
        -RepoRoot $rollbackFixture.RepoRoot -InstallDir $rollbackFixture.InstallDir `
        -Adapters $rollbackFixture.Adapters
    Assert-Equal $rollbackResult.outcome 'rolled_back' "failed health must roll deployment back ($($rollbackResult.reason): $($rollbackResult.message))"
    Assert-Equal ([IO.File]::ReadAllText($rollbackFixture.AsarPath)) 'original' 'rollback must restore the original app.asar'
    Assert-True (-not (Test-Path -LiteralPath $rollbackFixture.StatePath)) 'rolled-back deployment must not remain installed'
    Assert-True (-not (Test-Path -LiteralPath $rollbackFixture.DiscoveryPath)) 'deployer must not create discovery during rollback'
    Assert-Equal $rollbackFixture.Control.CleanupCalls 1 'probe rollback must clean its build directory'
    Assert-True (-not (Test-Path -LiteralPath $rollbackFixture.WorkDir)) 'probe rollback must remove its build directory'

    $rollbackCleanupFixture = New-TestFixture -Root $testRoot -Name 'rollback-cleanup-pending'
    $rollbackCleanupFixture.Control.ProbeHealthy = $false
    $rollbackCleanupFixture.Control.CleanupFails = $true
    $rollbackCleanupResult = Invoke-TwilightBridgeDeployment -Action ensure `
        -RepoRoot $rollbackCleanupFixture.RepoRoot -InstallDir $rollbackCleanupFixture.InstallDir `
        -Adapters $rollbackCleanupFixture.Adapters
    Assert-Equal $rollbackCleanupResult.outcome 'rolled_back' 'cleanup failure must not undo a successful app.asar rollback'
    Assert-Equal $rollbackCleanupResult.reason 'deployment_failed_cleanup_pending' 'rollback cleanup failure must be visible'
    Assert-Equal ([IO.File]::ReadAllText($rollbackCleanupFixture.AsarPath)) 'original' 'rollback cleanup failure must still restore original app.asar'
    Assert-True (-not [string]::IsNullOrWhiteSpace([string]$rollbackCleanupResult.nextAction)) 'rollback cleanup failure must report the exact remaining directory'

    $installedFixture = New-TestFixture -Root $testRoot -Name 'installed'
    $installResult = Invoke-TwilightBridgeDeployment -Action ensure `
        -RepoRoot $installedFixture.RepoRoot -InstallDir $installedFixture.InstallDir `
        -Adapters $installedFixture.Adapters
    Assert-Equal $installResult.outcome 'installed' 'healthy fake bridge must install'
    Assert-Equal ([int]$installResult.bridgeVersion) 1 'deployment result must report bridgeVersion'
    Assert-Equal ([IO.File]::ReadAllText($installedFixture.AsarPath)) 'patched' 'successful ensure must install patched app.asar'
    Assert-True (Test-Path -LiteralPath $installedFixture.StatePath -PathType Leaf) 'successful ensure must record rollback state'
    $managedState = Get-Content -LiteralPath $installedFixture.StatePath -Raw -Encoding UTF8 | ConvertFrom-Json
    Assert-Equal ([int]$managedState.bridgeVersion) 1 'managed state must record bridgeVersion'
    Assert-True (-not ($managedState.PSObject.Properties.Name -contains 'bridgeProtocol')) 'managed state must not retain bridgeProtocol'
    Assert-Equal $installedFixture.Control.LastDiscoveryPath $installedFixture.DiscoveryPath 'probe must use the runtime discovery adapter path'
    Assert-True (-not (Test-Path -LiteralPath $installedFixture.DiscoveryPath)) 'deployer must leave discovery ownership to the patched app'

    $statusResult = Invoke-TwilightBridgeDeployment -Action status `
        -RepoRoot $installedFixture.RepoRoot -InstallDir $installedFixture.InstallDir `
        -Adapters $installedFixture.Adapters
    Assert-Equal $statusResult.outcome 'healthy' 'status must probe a managed install'

    $runningRemove = Invoke-TwilightBridgeDeployment -Action remove `
        -RepoRoot $installedFixture.RepoRoot -InstallDir $installedFixture.InstallDir `
        -Adapters $installedFixture.Adapters
    Assert-Equal $runningRemove.reason 'close_twilight_required' 'remove must require tray exit before restoring files'
    Assert-Equal $installedFixture.Control.StopCalls 0 'remove must not try to close or kill Twilight'
    $installedFixture.Control.Running = $false
    $removeWhatIf = Invoke-TwilightBridgeDeployment -Action remove `
        -RepoRoot $installedFixture.RepoRoot -InstallDir $installedFixture.InstallDir `
        -Adapters $installedFixture.Adapters -WhatIfMode
    Assert-Equal $removeWhatIf.outcome 'would_remove' 'remove WhatIf must describe restoration'
    Assert-Equal ([IO.File]::ReadAllText($installedFixture.AsarPath)) 'patched' 'remove WhatIf must not restore app.asar'

    $cleanupFixture = New-TestFixture -Root $testRoot -Name 'cleanup-pending'
    $cleanupFixture.Control.CleanupFails = $true
    $cleanupResult = Invoke-TwilightBridgeDeployment -Action ensure `
        -RepoRoot $cleanupFixture.RepoRoot -InstallDir $cleanupFixture.InstallDir `
        -Adapters $cleanupFixture.Adapters
    Assert-Equal $cleanupResult.outcome 'installed' 'post-commit cleanup failure must not roll back a healthy bridge'
    Assert-Equal $cleanupResult.reason 'cleanup_pending' 'post-commit cleanup failure must be visible'
    Assert-True (-not [string]::IsNullOrWhiteSpace([string]$cleanupResult.nextAction)) 'cleanup failure must return an exact next action'
    Assert-Equal ([IO.File]::ReadAllText($cleanupFixture.AsarPath)) 'patched' 'cleanup failure must keep the committed patched app.asar'
    Assert-Equal $cleanupFixture.Control.StopCalls 0 'cleanup failure after commit must not stop or roll back the app'
    Assert-True (Test-Path -LiteralPath $cleanupFixture.WorkDir -PathType Container) 'failed cleanup must leave the reported run directory intact'

    $recoveryFixture = New-TestFixture -Root $testRoot -Name 'recovery'
    $recoveryInstall = Invoke-TwilightBridgeDeployment -Action ensure `
        -RepoRoot $recoveryFixture.RepoRoot -InstallDir $recoveryFixture.InstallDir `
        -Adapters $recoveryFixture.Adapters
    Assert-Equal $recoveryInstall.outcome 'installed' 'recovery fixture must first install'
    $recoveryFixture.Control.Running = $false
    Remove-Item -LiteralPath $recoveryFixture.AsarPath -Force
    $recoveryStatus = Invoke-TwilightBridgeDeployment -Action status `
        -RepoRoot $recoveryFixture.RepoRoot -InstallDir $recoveryFixture.InstallDir `
        -Adapters $recoveryFixture.Adapters
    Assert-Equal $recoveryStatus.outcome 'recovery_required' 'missing live app.asar must preserve recoverable managed state'
    Assert-True (Test-Path -LiteralPath $recoveryStatus.backupPath -PathType Leaf) 'recovery status must return the verified original backup'
    $recoveryRemoveWhatIf = Invoke-TwilightBridgeDeployment -Action remove `
        -RepoRoot $recoveryFixture.RepoRoot -InstallDir $recoveryFixture.InstallDir `
        -Adapters $recoveryFixture.Adapters -WhatIfMode
    Assert-Equal $recoveryRemoveWhatIf.outcome 'would_recover' 'remove WhatIf must expose safe missing-live recovery'
    $recoveryRemove = Invoke-TwilightBridgeDeployment -Action remove `
        -RepoRoot $recoveryFixture.RepoRoot -InstallDir $recoveryFixture.InstallDir `
        -Adapters $recoveryFixture.Adapters
    Assert-Equal $recoveryRemove.reason 'original_restored_from_recovery' 'explicit remove must restore a verified backup when live app.asar is absent'
    Assert-Equal ([IO.File]::ReadAllText($recoveryFixture.AsarPath)) 'original' 'recovery must restore the pinned original app.asar'

    $unknownFixture = New-TestFixture -Root $testRoot -Name 'unknown-live'
    $unknownInstall = Invoke-TwilightBridgeDeployment -Action ensure `
        -RepoRoot $unknownFixture.RepoRoot -InstallDir $unknownFixture.InstallDir `
        -Adapters $unknownFixture.Adapters
    Assert-Equal $unknownInstall.outcome 'installed' 'unknown-live fixture must first install'
    $unknownFixture.Control.Running = $false
    Write-TestText -Path $unknownFixture.AsarPath -Value 'unknown'
    $unknownStatus = Invoke-TwilightBridgeDeployment -Action status `
        -RepoRoot $unknownFixture.RepoRoot -InstallDir $unknownFixture.InstallDir `
        -Adapters $unknownFixture.Adapters
    Assert-Equal $unknownStatus.reason 'unsupported_twilight_build' 'a live unknown app.asar must remain fail closed even with a valid backup'
    $unknownRemove = Invoke-TwilightBridgeDeployment -Action remove `
        -RepoRoot $unknownFixture.RepoRoot -InstallDir $unknownFixture.InstallDir `
        -Adapters $unknownFixture.Adapters
    Assert-Equal $unknownRemove.reason 'install_changed' 'remove must not overwrite an unknown live app.asar'
    Assert-Equal ([IO.File]::ReadAllText($unknownFixture.AsarPath)) 'unknown' 'unknown live app.asar must remain untouched'
    Assert-True (Test-Path -LiteralPath $unknownInstall.backupPath -PathType Leaf) 'unknown live build must retain its original backup'

    'TWILIGHT_BRIDGE_DEPLOY_CONTRACT_OK'
} finally {
    $tempBase = [IO.Path]::GetFullPath([IO.Path]::GetTempPath()).TrimEnd('\') + '\'
    $resolvedTestRoot = [IO.Path]::GetFullPath($testRoot).TrimEnd('\') + '\'
    if ($resolvedTestRoot.StartsWith($tempBase, [StringComparison]::OrdinalIgnoreCase) -and
        (Test-Path -LiteralPath $testRoot -PathType Container)) {
        Remove-Item -LiteralPath $testRoot -Recurse -Force
    }
}

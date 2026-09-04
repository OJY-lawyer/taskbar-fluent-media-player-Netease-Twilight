[CmdletBinding(SupportsShouldProcess = $true, ConfirmImpact = 'Medium')]
param(
    [Parameter(Position = 0)]
    [ValidateSet('ensure', 'status', 'remove')]
    [string]$Action = 'ensure',

    [string]$InstallDir
)

$ErrorActionPreference = 'Stop'
$repoRoot = Split-Path -Parent $PSScriptRoot
$modulePath = Join-Path $repoRoot 'integrations\twilight\deploy.psm1'

try {
    Import-Module -Name $modulePath -Force -ErrorAction Stop
    $invokeParams = @{
        Action = $Action
        RepoRoot = $repoRoot
        WhatIfMode = [bool]$WhatIfPreference
    }
    if ($InstallDir) {
        $invokeParams.InstallDir = $InstallDir
    }
    $result = Invoke-TwilightBridgeDeployment @invokeParams
    $result | ConvertTo-Json -Depth 8
    exit [int]$result.exitCode
} catch {
    [pscustomobject]@{
        outcome = 'failed'
        reason = 'unexpected_error'
        message = $_.Exception.Message
        exitCode = 99
    } | ConvertTo-Json -Depth 4
    exit 99
}

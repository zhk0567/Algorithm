#Requires -Version 5.1
<#
.SYNOPSIS
  Recursively run Python files that contain `if __name__ == "__main__"` under whitelisted roots.

.DESCRIPTION
  Run from repository root (or pass -RepoRoot). Default roots: interview/classic, data_structures, algorithms.
  Optional: -IncludeLeetcode adds python/problems/leetcode (one solution.py per problem).

.EXAMPLE
  Set-Location F:\Study\Algorithm
  .\scripts\run_all_python.ps1
#>
param(
    [string] $RepoRoot = "",
    [switch] $IncludeLeetcode
)

$ErrorActionPreference = "Stop"

if (-not $RepoRoot) {
    $RepoRoot = (Resolve-Path (Join-Path $PSScriptRoot "..")).Path
}
Set-Location $RepoRoot

$dirs = @(
    (Join-Path $RepoRoot "python\interview\classic"),
    (Join-Path $RepoRoot "python\data_structures"),
    (Join-Path $RepoRoot "python\algorithms")
)
if ($IncludeLeetcode) {
    $dirs += (Join-Path $RepoRoot "python\problems\leetcode")
}

$mainPattern = 'if __name__\s*==\s*[''"]__main__[''"]'
$ran = 0

foreach ($dir in $dirs) {
    if (-not (Test-Path -LiteralPath $dir)) {
        Write-Warning "Skip missing directory: $dir"
        continue
    }
    Get-ChildItem -LiteralPath $dir -Recurse -Filter "*.py" -File | ForEach-Object {
        $path = $_.FullName
        $raw = Get-Content -LiteralPath $path -Raw -Encoding UTF8
        if ($raw -match $mainPattern) {
            Write-Host "==> $path"
            & python $path
            if ($LASTEXITCODE -ne 0) {
                Write-Error "FAILED (exit $LASTEXITCODE): $path"
                exit 1
            }
            $script:ran++
        }
    }
}

Write-Host "run_all_python.ps1 OK ($script:ran files)"

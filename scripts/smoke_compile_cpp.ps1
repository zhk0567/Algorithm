#Requires -Version 5.1
<#
.SYNOPSIS
  g++ compile-to-object smoke for whitelisted C++ trees (no link).

.DESCRIPTION
  Default: cpp/interview/classic, cpp/data_structures, cpp/algorithms, cpp/problems/leetcode.

.EXAMPLE
  Set-Location F:\Study\Algorithm
  .\scripts\smoke_compile_cpp.ps1
#>
param(
    [string] $RepoRoot = "",
    [string] $Gpp = "g++"
)

$ErrorActionPreference = "Stop"
if (-not $RepoRoot) {
    $RepoRoot = (Resolve-Path (Join-Path $PSScriptRoot "..")).Path
}
Set-Location $RepoRoot

$roots = @(
    (Join-Path $RepoRoot "cpp\interview\classic"),
    (Join-Path $RepoRoot "cpp\data_structures"),
    (Join-Path $RepoRoot "cpp\algorithms"),
    (Join-Path $RepoRoot "cpp\problems\leetcode")
)

$tmpObj = Join-Path $env:TEMP "algorithm_cpp_smoke.obj"
$flags = @("-std=c++17", "-c", "-O0", "-Wall", "-Wextra", "-pthread", "-o", $tmpObj)
$count = 0

foreach ($root in $roots) {
    if (-not (Test-Path -LiteralPath $root)) {
        Write-Warning "Skip missing: $root"
        continue
    }
    Get-ChildItem -LiteralPath $root -Recurse -Filter "*.cpp" -File | ForEach-Object {
        $path = $_.FullName
        Write-Host "==> $path"
        & $Gpp @flags $path
        if ($LASTEXITCODE -ne 0) {
            Write-Error "COMPILE FAILED: $path"
            exit 1
        }
        $script:count++
    }
}

Write-Host "smoke_compile_cpp.ps1 OK ($script:count files)"

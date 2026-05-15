#Requires -Version 5.1
<#
.SYNOPSIS
  Replace #include <bits/stdc++.h> with #include <alg_std.hpp> under cpp/.
#>
param(
    [string] $RepoRoot = ""
)

$ErrorActionPreference = "Stop"
if (-not $RepoRoot) {
    $RepoRoot = (Resolve-Path (Join-Path $PSScriptRoot "..")).Path
}
Set-Location $RepoRoot

$cppRoot = Join-Path $RepoRoot "cpp"
$pattern = '#include\s*<bits/stdc\+\+\.h>'
$replacement = '#include <alg_std.hpp>'
$changed = 0

Get-ChildItem -LiteralPath $cppRoot -Recurse -Filter "*.cpp" -File | ForEach-Object {
    $raw = [System.IO.File]::ReadAllText($_.FullName)
    if ($raw -notmatch $pattern) { return }
    $new = [regex]::Replace($raw, $pattern, $replacement)
    if ($new -ne $raw) {
        [System.IO.File]::WriteAllText($_.FullName, $new)
        $script:changed++
        Write-Host "updated: $($_.FullName.Substring($RepoRoot.Length + 1))"
    }
}

Write-Host "migrate_bits_stdc.ps1 OK ($changed .cpp files)"

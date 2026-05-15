#Requires -Version 5.1
<#
.SYNOPSIS
  Compile smoke for C++ sources under the repository (g++ default, optional MSVC).

.DESCRIPTION
  Default: every *.cpp under cpp/ (full tree). Use -WhitelistOnly for the legacy
  four roots only. Default mode is compile-only. Use -LinkEntry to also link and
  run entry files under algorithms/, data_structures/, interview/classic/
  (skips problems/leetcode solution.cpp).

  Sources use #include <alg_std.hpp>; include path defaults to cpp/include.

.PARAMETER Compiler
  g++ (default) or msvc (requires cl on PATH, e.g. after vcvars64.bat).

.PARAMETER Jobs
  Parallel compile jobs (PowerShell 7+ only; ignored on Windows PowerShell 5.1).

.EXAMPLE
  Set-Location F:\Study\Algorithm
  .\scripts\smoke_compile_cpp.ps1

.EXAMPLE
  .\scripts\smoke_compile_cpp.ps1 -LinkEntry

.EXAMPLE
  .\scripts\smoke_compile_cpp.ps1 -Compiler msvc
#>
param(
    [string] $RepoRoot = "",
    [ValidateSet("g++", "msvc")]
    [string] $Compiler = "g++",
    [string] $Gpp = "g++",
    [string] $IncludeDir = "",
    [switch] $WhitelistOnly,
    [string[]] $Roots = @(),
    [int] $Jobs = 1,
    [switch] $LinkEntry
)

$ErrorActionPreference = "Stop"

if (-not $RepoRoot) {
    $RepoRoot = (Resolve-Path (Join-Path $PSScriptRoot "..")).Path
}
Set-Location $RepoRoot

if (-not $IncludeDir) {
    $IncludeDir = Join-Path $RepoRoot "cpp\include"
}
if (-not (Test-Path -LiteralPath $IncludeDir)) {
    Write-Error "Missing include dir (alg_std.hpp): $IncludeDir"
}

if ($Compiler -eq "msvc") {
    if (-not (Get-Command cl -ErrorAction SilentlyContinue)) {
        Write-Error "MSVC cl not found on PATH. Open 'x64 Native Tools' or run vcvars64.bat, then retry -Compiler msvc."
    }
}

if ($Roots.Count -gt 0) {
    $roots = @($Roots | ForEach-Object {
        if ([System.IO.Path]::IsPathRooted($_)) { $_ } else { Join-Path $RepoRoot $_ }
    })
} elseif ($WhitelistOnly) {
    $roots = @(
        (Join-Path $RepoRoot "cpp\interview\classic"),
        (Join-Path $RepoRoot "cpp\data_structures"),
        (Join-Path $RepoRoot "cpp\algorithms"),
        (Join-Path $RepoRoot "cpp\problems\leetcode")
    )
} else {
    $roots = @(Join-Path $RepoRoot "cpp")
}

$tmpObj = Join-Path $env:TEMP "algorithm_cpp_smoke_$PID.obj"
$tmpExe = Join-Path $env:TEMP "algorithm_cpp_smoke_$PID.exe"

if ($Compiler -eq "msvc") {
    $compileFlags = @("/nologo", "/std:c++17", "/EHsc", "/W4", "/c", "/Fo:$tmpObj", "/I$IncludeDir")
    $linkFlags = @("/nologo", "/std:c++17", "/EHsc", "/W4", "/Fe:$tmpExe", "/I$IncludeDir")
    $compilerExe = "cl"
} else {
    $compileFlags = @("-std=c++17", "-c", "-O0", "-Wall", "-Wextra", "-pthread", "-I", $IncludeDir, "-o", $tmpObj)
    $linkFlags = @("-std=c++17", "-O2", "-Wall", "-Wextra", "-pthread", "-I", $IncludeDir, "-o", $tmpExe)
    $compilerExe = $Gpp
}

$files = [System.Collections.Generic.List[string]]::new()
foreach ($root in $roots) {
    if (-not (Test-Path -LiteralPath $root)) {
        Write-Warning "Skip missing: $root"
        continue
    }
    Get-ChildItem -LiteralPath $root -Recurse -Filter "*.cpp" -File | ForEach-Object {
        $files.Add($_.FullName)
    }
}

if ($files.Count -eq 0) {
    Write-Warning "No .cpp files under: $($roots -join ', ')"
    exit 0
}

function Test-EntryCpp {
    param([string] $Path)
    if ($Path -match '\\problems\\leetcode\\') { return $false }
    return $Path -match '\\(algorithms|data_structures|interview\\classic)\\'
}

function Invoke-SmokeCompile {
    param([string] $Path, [bool] $DoLink)
    Write-Host "==> $Path"
    if ($DoLink) {
        & $compilerExe @linkFlags $Path
    } else {
        & $compilerExe @compileFlags $Path
    }
    if ($LASTEXITCODE -ne 0) {
        throw "COMPILE FAILED: $Path (exit $LASTEXITCODE)"
    }
    if ($DoLink) {
        & $tmpExe
        if ($LASTEXITCODE -ne 0) {
            throw "RUN FAILED: $Path (exit $LASTEXITCODE)"
        }
    }
}

$failed = [System.Collections.Generic.List[string]]::new()
$useParallel = ($Jobs -gt 1) -and ($PSVersionTable.PSVersion.Major -ge 7) -and ($Compiler -eq "g++")

if ($useParallel) {
    $files | ForEach-Object -Parallel {
        $path = $_
        $exe = $using:compilerExe
        $flags = $using:compileFlags
        $tmp = $using:tmpObj
        Write-Host "==> $path"
        & $exe @flags $path
        if ($LASTEXITCODE -ne 0) {
            throw "COMPILE FAILED: $path"
        }
    } -ThrottleLimit $Jobs
} else {
    foreach ($path in $files) {
        $doLink = $LinkEntry -and (Test-EntryCpp $path)
        try {
            Invoke-SmokeCompile -Path $path -DoLink:$doLink
        } catch {
            Write-Host $_.Exception.Message -ForegroundColor Red
            $failed.Add($path)
        }
    }
}

if ($failed.Count -gt 0) {
    Write-Error "smoke_compile_cpp.ps1 FAILED ($($failed.Count) / $($files.Count)):`n$($failed -join "`n")"
    exit 1
}

$mode = if ($LinkEntry) { "compile+link-entry" } else { "compile-only" }
$scope = if ($WhitelistOnly) { "whitelist" } elseif ($roots.Count -eq 1 -and $roots[0] -eq (Join-Path $RepoRoot "cpp")) { "cpp/**" } else { "custom" }
Write-Host "smoke_compile_cpp.ps1 OK ($($files.Count) files, $mode, scope=$scope, compiler=$Compiler)"

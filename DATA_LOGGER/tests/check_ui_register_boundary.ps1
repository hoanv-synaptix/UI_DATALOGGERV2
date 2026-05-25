$ErrorActionPreference = "Stop"

$root = Resolve-Path "$PSScriptRoot\.."
$allowed = @(
    "custom\ui_register_adapter.c"
)

$paths = @()
if (Test-Path (Join-Path $root "custom")) {
    $paths += Get-ChildItem -Path (Join-Path $root "custom") -Include *.c,*.h -File -Recurse
}

$matches = $paths | Select-String -Pattern "ui_register_map.h|REG_[A-Z0-9_]+" -ErrorAction SilentlyContinue

foreach ($match in $matches) {
    $relative = (Resolve-Path $match.Path).Path.Substring($root.Path.Length + 1)

    if ($allowed -notcontains $relative) {
        Write-Error "Register contract leaked into ${relative}:$($match.LineNumber): $($match.Line.Trim())"
    }
}

Write-Host "ui register boundary check passed"

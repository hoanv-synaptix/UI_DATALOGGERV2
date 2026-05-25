$ErrorActionPreference = "Stop"

$root = Resolve-Path "$PSScriptRoot\.."
$header = Join-Path $root "contract\generated\ui_register_map.h"
$source = Join-Path $root "contract\generated\ui_register_map.c"

& python.exe (Join-Path $root "tools\gen_ui_register_map.py") | Out-Host
if ($LASTEXITCODE -ne 0) {
    throw "register map generator failed with exit code $LASTEXITCODE"
}

git -C $root diff --exit-code -- contract/generated/ui_register_map.h contract/generated/ui_register_map.c | Out-Host
if ($LASTEXITCODE -ne 0) {
    Write-Error "Generated register map is stale"
}

if (!(Test-Path $header)) {
    Write-Error "Missing generated header: $header"
}
if (!(Test-Path $source)) {
    Write-Error "Missing generated source: $source"
}

Write-Host "ui register map check passed"

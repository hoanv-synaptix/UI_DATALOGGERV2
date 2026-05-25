$ErrorActionPreference = "Stop"

$root = Resolve-Path "$PSScriptRoot\.."
$buildDir = Join-Path $root "tests\.build"
$exe = Join-Path $buildDir "test_ui_register_adapter.exe"

New-Item -ItemType Directory -Force -Path $buildDir | Out-Null

gcc -std=c99 -Wall -Wextra `
    -I (Join-Path $root "custom") `
    -I (Join-Path $root "contract\generated") `
    -I (Join-Path $root "lvgl-simulator") `
    -I (Join-Path $root "lvgl") `
    -I (Join-Path $root "lvgl\src") `
    (Join-Path $root "tests\native\test_ui_register_adapter.c") `
    (Join-Path $root "custom\ui_register_adapter.c") `
    (Join-Path $root "contract\generated\ui_register_map.c") `
    -o $exe
if ($LASTEXITCODE -ne 0) {
    throw "adapter native build failed with exit code $LASTEXITCODE"
}

& $exe
if ($LASTEXITCODE -ne 0) {
    throw "adapter native test failed with exit code $LASTEXITCODE"
}

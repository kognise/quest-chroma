# Builds a .zip file for loading with BMBF
& $PSScriptRoot/build.ps1

if ($?) {
    Compress-Archive -Path "./libs/arm64-v8a/libchroma.so", "./libs/arm64-v8a/libbeatsaber-hook_0_8_4.so", "./bmbfmod.json" -DestinationPath "./chroma.zip" -Update
}

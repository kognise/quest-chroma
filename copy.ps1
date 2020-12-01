& $PSScriptRoot/build.ps1
if ($?) {
    adb push libs/arm64-v8a/libchroma.so /sdcard/Android/data/com.beatgames.beatsaber/files/mods/libchroma.so
    if ($?) {
        adb shell am force-stop com.beatgames.beatsaber
        adb shell am start com.beatgames.beatsaber/com.unity3d.player.UnityPlayerActivity
        adb logcat main-modloader:W QuestHook[chroma`|v0.1.0]:* AndroidRuntime:E *:S > cat.log
    }
}

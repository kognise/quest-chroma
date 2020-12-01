#include "logger.hpp"
#include "hooks.hpp"

#include "beatsaber-hook/shared/utils/logging.hpp"
#include "beatsaber-hook/shared/utils/il2cpp-utils.hpp"

extern "C" void setup(ModInfo &info) {
  info.id = "Chroma";
  info.version = VERSION;
  ChromaLogger::modInfo = info;
}

extern "C" void load() {
  Logger::get().options.silent = true;

  ChromaLogger::GetLogger().info("Installing Chroma hooks...");
  Chroma::InstallHooks();
  ChromaLogger::GetLogger().info("Installed Chroma hooks!");
}

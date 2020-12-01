#include "hooks.hpp"

#include "beatsaber-hook/shared/utils/il2cpp-utils.hpp"

#include "GlobalNamespace/ObstacleController.hpp"
#include "GlobalNamespace/ObstacleData.hpp"

using namespace GlobalNamespace;

MAKE_HOOK_OFFSETLESS(
  ObstacleController_Init,
  void,
  ObstacleController *self,
  ObstacleData *obstacleData,
  float worldRotation,
  UnityEngine::Vector3 startPos,
  UnityEngine::Vector3 midPos,
  UnityEngine::Vector3 endPos,
  float move1Duration,
  float move2Duration,
  float singleLineWidth,
  float height
) {
  ObstacleController_Init(self, obstacleData, worldRotation, startPos, midPos, endPos, move1Duration, move2Duration, singleLineWidth, height);

  // if (!obstacleData->customData) return;
  // rapidjson::Value &customData = *obstacleData->customData->value;

  // UnityEngine::Color color = self->color->color;
  // if (customData.HasMember("_color")) {
  //   float r = customData["_color"][0].GetFloat();
  //   float g = customData["_color"][1].GetFloat();
  //   float b = customData["_color"][2].GetFloat();
  //   float a = customData["_color"].GetArray().Size() > 3 ? customData["_color"][3].GetFloat() : 1;
  //   color = UnityEngine::Color(r, g, b, a);
  // }

  // StretchableObstacle *so = self->stretchableObstacle;
  // so->SetSizeAndColor(so->obstacleFrame->width, so->obstacleFrame->height, so->obstacleFrame->length, color);
}

void Chroma::InstallableHooks::ObstacleController_Init() {
  INSTALL_HOOK_OFFSETLESS(ObstacleController_Init, il2cpp_utils::FindMethodUnsafe("", "ObstacleController", "Init", 9));
}
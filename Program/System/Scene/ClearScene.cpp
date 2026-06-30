#include "System/Scene/ClearScene.hpp"
#include "System//KeyInput/KeyInput.h"
#include "Graphics/Renderer.hpp"

namespace System {

std::string ClearScene::GetName() const {return "ClearScene";}

void ClearScene::Initialize() {
    Graphics::Renderer renderer = Graphics::Renderer::GetInstance();
    renderer.ClearConsole();
    renderer.AddText(GetName());
}

void ClearScene::Update() {}
void ClearScene::Finalize() {}

} // namespace System

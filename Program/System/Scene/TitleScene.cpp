#include "TitleScene.hpp"
#include "../KeyInput/KeyInput.h"
#include "SceneManager.hpp"
#include "InGameScene.hpp"
#include "../../Graphics/Renderer.hpp"

namespace System {

    std::string TitleScene::GetName() const { return "TitleScene"; }

    void TitleScene::Initialize() {
        auto& renderer = Graphics::Renderer::GetInstance();
        renderer.Initialize();
        renderer.AddText("TITLE");
        renderer.AddText("Push To Enter");
    }

    void TitleScene::Update() {
        auto& renderer = Graphics::Renderer::GetInstance();
        renderer.Render();

        System::KeyInput::Update();
        if (System::KeyInput::IsDown(VK_RETURN))
        {
            try {
                System::SceneManager::GetInstance()->ChangeScene<InGameScene>();
            } catch (...) {
                renderer.ClearConsole();
                renderer.AddText("Error transitioning to game scene");
                renderer.Render();
            }
            return;
        }
    }

    void TitleScene::Finalize() {}
}

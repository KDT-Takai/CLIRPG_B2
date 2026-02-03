#include "System/Scene/TitleScene.hpp"
#include "System/KeyInput/KeyInput.h"
#include "System/Scene/SceneManager.hpp"
#include "System/Scene/InGameScene.hpp"
#include "Graphics/Renderer.hpp"

namespace System {
	std::string TitleScene::GetName() const { return "TitleScene"; }

	void TitleScene::Initialize() {
		Graphics::Renderer::GetInstance()->Create();
		auto* renderer = Graphics::Renderer::GetInstance();
		renderer->ClearText();
		renderer->AddText("TITLE");
	}
	void TitleScene::Update() {
		auto* renderer = Graphics::Renderer::GetInstance();
		renderer->Render();

		System::KeyInput::Update();
		if (System::KeyInput::IsDown(VK_RETURN))
		{
			System::SceneManager::GetInstance()->ChangeScene<InGameScene>();
			return;
		}
	}
	void TitleScene::Finalize() {}
}
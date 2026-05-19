#pragma once
#include"System/Scene/TitleScene.hpp"
#include"System/KeyInput/KeyInput.h"
#include"System/Scene/SceneManager.hpp"
#include"System/Scene/InGameScene.hpp"
#include"Graphics/Renderer.hpp"

namespace System {
	std::string TitleScene::GetName() const { return "TitleScene"; }

	void TitleScene::Initialize() {
		Graphics::Renderer::GetInstance()->Create();
		auto* renderer = Graphics::Renderer::GetInstance();
		renderer->ClearText();
		renderer->AddText("TITLE");
		renderer->AddText("Push To Enter");

	}

	/// <summary>
	/// Main game loop update.
	/// </summary>
	void TitleScene::Update() override {
		auto* renderer = Graphics::Renderer::GetInstance();
		renderer->Render();

		System::KeyInput::Update();
		if (System::KeyInput::IsDown(VK_RETURN))
		{
			try {
				System::SceneManager::GetInstance()->ChangeScene<InGameScene>();
			} catch (...) {
				// Graceful fallback on scene transition error
				renderer->ClearConsole();
				renderer->AddText("Error transitioning to game scene");
				renderer->Render();
			}
			return;
		}
	}

	/// <summary>
	/// Cleanup before shutdown.
	/// </summary>
	void TitleScene::Finalize() override {}
}

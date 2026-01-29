#pragma once
#include "System/IScene/IScene.hpp"

//　インゲーム画面用のシーンクラス
//　ISceneを継承しSceneManagerから管理・遷移
namespace System {
	class InGameScene final : public IScene {
	public:
		std::string GetName() const override { return "InGameScene"; }

		void Initialize() override {}
		void Update() override {}
		void Finalize() override {}
	};
}
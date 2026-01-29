#pragma once
#include "System/IScene/IScene.hpp"

//　クリア画面用のシーンクラス
//　ISceneを継承しSceneManagerから管理・遷移
namespace System {
	class ClearScene final : public IScene {
	public:
		std::string GetName() const override { return "ClearScene"; }

		void Initialize() override {}
		void Update() override {}
		void Finalize() override {}
	};
}
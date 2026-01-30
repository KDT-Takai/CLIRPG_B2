#pragma once
#include "System/IScene/IScene.hpp"

//　タイトル画面用のシーンクラス
//　ISceneを継承しSceneManagerから管理・遷移
namespace System {
	class TitleScene final : public IScene {
	public:
		std::string GetName() const override;

		void Initialize() override;
		void Update() override;
		void Finalize() override;
	};
}
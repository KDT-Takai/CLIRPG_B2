#pragma once
#include "System/IScene/IScene.hpp"

//�@�^�C�g����ʗp�̃V�[���N���X
//�@IScene���p����SceneManager����Ǘ��E�J��
namespace System {
	class TitleScene final : public IScene {
	public:
		std::string GetName() const override;

		void Initialize() override;
		void Update() override;
		void Finalize() override;
	};
}
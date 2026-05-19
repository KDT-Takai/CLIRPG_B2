#pragma once
#include <string>

namespace System {
	class IScene
	{
	public:

		virtual ~IScene() = default;

		// ���̃V�[���ɓ������u�ԁi�^�C�g����ʕ\���A�X�e�[�^�X���������j
		virtual void Initialize() {}

		//�@���[�v���ɌĂ΂��i���͑҂��A�R�}���h�������j
		virtual void Update() = 0;

		//���̃V�[���𔲂���u�ԁi��n���A���ʕ\���A�t���O���Z�b�g���j
		virtual void Finalize() {}

		//�@�f�o�b�O�p
		virtual std::string GetName() const = 0;
	};
}
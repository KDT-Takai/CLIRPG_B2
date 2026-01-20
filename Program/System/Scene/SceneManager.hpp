#pragma once

#include <memory>
#include <string>

#include "System/Singleton/Singleton.hpp"
#include "System/IScene/IScene.hpp"





//　Singletonを継承
class SceneManager : public Singleton<SceneManager> {

	GENERATE_SINGLETON_BODY(SceneManager)

public:

	//　最初のシーンをセットする
	template<class TScene,class...Args>
	void SetStartScene(Args&&...args) {

		ChangeScene<TScene>(std::forward<Args>(args)...);

	}

	template<class TScene, class...Args>
	void ChangeScene(Args&&...args)
	{
		//現在のシーンの終了
		if (mCurrent) {

			mCurrent->Finalize();
		}
		//　シーンの作成
		mCurrent = std::make_unique<TScene>(std::forward<Args>(args)...);
		//　新シーンの開始
		mCurrent->Initialize();
	}

	void Update();

	//　デバッグ表示用（現在のシーン or　none）
	std::string CurrentSceneName() const noexcept;

protected:

	//SingletonによってSceneManagerが生成された直後に、初期状態をセット
	void OnCreate() override;
	void OnDestory() override;

private:
	
	std::unique_ptr<IScene> mCurrent;

	bool mQuitRequested = false;
};


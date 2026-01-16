#pragma once

#include <memory>

#include <string>

#include "System/Singleton/Singleton.hpp"

class Scene;

class IScene
{

public:

	virtual ~IScene() = default;

	// そのシーンに入った瞬間（タイトル画面表示、ステータス初期化等）
	virtual void Initialize(Scene* manager) = 0;

	//　ループ毎に呼ばれる（入力待ち、コマンド処理等）
	virtual void Update(Scene* manager) = 0;

	//そのシーンを抜ける瞬間（後始末、結果表示、フラグリセット等）
	virtual void Finalize(Scene* manager) = 0;

	//　デバッグ用
	virtual std::string GetName() const = 0;

};

//　Singletonを継承
class Scene : public Singleton<Scene> {

	GENERATE_SINGLETON_BODY(Scene)

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

			mCurrent->Finalize(this);
		}

		//　シーンの作成
		mCurrent = std::make_unique<TScene>(std::forward<Args>(args)...);

		//　新シーンの開始
		mCurrent->Initialize(this);

	}

	void Update();



	//　終了したいとき
	void RequestQuit() noexcept;

	//　続けていいかの確認
	bool IsRunning() const noexcept;

	//　デバッグ表示用（現在のシーン or　none）
	std::string CurrentSceneName() const noexcept;


protected:

	//SingletonによってSceneManagerが生成された直後に、初期状態をセット
	void OnCreate() override;


	void OnDestory() override;


private:
	
	std::unique_ptr<IScene> mCurrent;

	bool mIsRunning = true;

};


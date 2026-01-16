#pragma once

#include <memory>

#include <string>

#include "System/Singleton/Singleton.hpp"

class SceneManager;

class IScene
{

public:

	virtual ~IScene() = default;

	// そのシーンに入った瞬間（タイトル画面表示、ステータス初期化等）
	virtual void OnEnter(SceneManager* manager) = 0;

	//　ループ毎に呼ばれる（入力待ち、コマンド処理等）
	virtual void OnUpdate(SceneManager* manager) = 0;

	//そのシーンを抜ける瞬間（後始末、結果表示、フラグリセット等）
	virtual void OnExit(SceneManager* manager) = 0;

	//　デバッグ用
	virtual const char* GetName() const = 0;

};

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

			mCurrent->OnExit(this);
		}

		//　シーンの作成
		mCurrent = std::make_unique<TScene>(std::forward<Args>(args)...);

		//　新シーンの開始
		mCurrent->OnEnter(this);

	}

	void Update() {
		
		if (mCurrent) {

			mCurrent->OnUpdate(this);

		}

	}
	//　終了したいとき
	void RequestQuit() noexcept
	{

		mIsRunning = false;

	}

	//　続けていいかの確認
	bool IsRunning() const noexcept
	{

		return mIsRunning;

	}

	//　デバッグ表示用（現在のシーン or　none）
	const char* CurrentSceneName() const noexcept
	{

		return mCurrent ? mCurrent->GetName() : "(none)";

	}

protected:

	//SingletonによってSceneManagerが生成された直後に、初期状態をセット
	void OnCreate() override
	{

		mIsRunning = true;

	}

	void OnDestory() override
	{

		//　終了時にシーンが残ってたら後始末
		if (mCurrent) {

			mCurrent->OnExit(this);
			mCurrent.reset();
		}
		
	}

private:
	
	std::unique_ptr<IScene> mCurrent;

	bool mIsRunning = true;

};


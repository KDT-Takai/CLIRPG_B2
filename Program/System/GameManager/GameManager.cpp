#include "GameManager.hpp"
#include "../Scene/SceneManager.hpp"
#include "../Scene/TitleScene.hpp"

/// <summary>
/// 更新処理
/// </summary>
void System::GameManager::Update()
{
	// シーンマネージャーの更新
	System::SceneManager::GetInstance()->Update();
}

/// <summary>
/// 描画
/// </summary>
void System::GameManager::Render()
{

}

/// <summary>
/// 初期化
/// </summary>
/// <returns>true:成功</returns>
bool System::GameManager::Initilaize()
{
	System::SceneManager::Create();
	System::SceneManager::GetInstance()->SetStartScene<System::TitleScene>();
	return true;
}

/// <summary>
/// メインループ
/// </summary>
void System::GameManager::Run()
{
	while (mIsRunning == true)
	{
		this->Update();
		this->Render();
	}
}

/// <summary>
/// 終了処理
/// </summary>
/// <returns>true:成功</returns>
bool System::GameManager::Finalize()
{
	System::SceneManager::Release();
	return true;
}

#include "GameManager.hpp"

/// <summary>
/// 更新処理
/// </summary>
void System::GameManager::Update()
{

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
	return true;
}

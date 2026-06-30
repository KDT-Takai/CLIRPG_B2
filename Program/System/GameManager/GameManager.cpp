#include "../System/GameManager/GameManager.hpp"
#include"../Scene/SceneManager.hpp"

/// <summary>
/// Main game loop update.
/// </summary>
void System::GameManager::Update()
{
	// Update scene manager and current scene
	System::SceneManager::GetInstance()->Update();
}

/// <summary>
/// Render frame (placeholder for future graphics).
/// </summary>
void System::GameManager::Render()
{

}

/// <summary>
/// Initialize the game manager.
/// </summary>
/// <returns>true: Initialization successful</returns>
bool System::GameManager::Initilaize()
{
	try {
		System::SceneManager::Create();
		System::SceneManager::GetInstance()->SetStartScene<System::TitleScene>();
		return true;
	} catch (...) {
		// Graceful fallback on initialization error
		return false;
	}
}

/// <summary>
/// Run the main game loop.
/// </summary>
void System::GameManager::Run()
{
	while (mIsRunning == true)
	{
		try {
			this->Update();
			this->Render();
		} catch (...) {
			// Prevent infinite loop on update/render error
			mIsRunning = false;
		}
	}
}

/// <summary>
/// Cleanup and shutdown.
/// </summary>
/// <returns>true: Shutdown successful</returns>
bool System::GameManager::Finalize()
{
	try {
		System::SceneManager::Release();
		return true;
	} catch (...) {
		// Graceful fallback on cleanup error
		return false;
	}
}

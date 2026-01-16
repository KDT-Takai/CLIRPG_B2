#include "System/Screen/ScreenManager.hpp"

void SceneManager::Update()
{

	if (mCurrent)
	{

		mCurrent->OnUpdate(this);

	}

}

void SceneManager::RequestQuit() noexcept
{

	mIsRunning = false;

}

bool SceneManager::IsRunning() const noexcept
{

	return mIsRunning;

}

const char* SceneManager::CurrentSceneName() const noexcept
{

	return mCurrent ? mCurrent->GetName() : "(none)";

}

//Singlton‚Ì¶¬Žž
void SceneManager::OnCreate()
{
	mIsRunning = true;

}

void SceneManager::OnDestory()
{
	if (mCurrent) {

		mCurrent->OnExit(this);
		mCurrent.reset();
	}

}
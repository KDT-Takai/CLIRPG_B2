#include "System/Scene/SceneManager.hpp"

void SceneManager::Update()
{
	if (mCurrent)
	{
		mCurrent->Update();
	}
}

std::string SceneManager::CurrentSceneName() const noexcept
{
	return mCurrent ? mCurrent->GetName() : std::string("none");
}

//Singlton‚Ì¶¬
void SceneManager::OnCreate()
{
	mQuitRequested = false;
}

//Singlton‚Ì”jŠü
void SceneManager::OnDestory()
{
	if (mCurrent) {
		mCurrent->Finalize();
		mCurrent.reset();
	}
}
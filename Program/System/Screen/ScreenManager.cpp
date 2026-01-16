#include "System/Screen/ScreenManager.hpp"

void Scene::Update()
{

	if (mCurrent)
	{

		mCurrent->Update(this);

	}

}

void Scene::RequestQuit() noexcept
{

	mIsRunning = false;

}

bool Scene::IsRunning() const noexcept
{

	return mIsRunning;

}

std::string Scene::CurrentSceneName() const noexcept
{

	return mCurrent ? mCurrent->GetName() : std::string("(none)");

}

//Singlton‚Ì¶¬
void Scene::OnCreate()
{
	mIsRunning = true;

}

void Scene::OnDestory()
{
	if (mCurrent) {

		mCurrent->Finalize(this);
		mCurrent.reset();
	}

}
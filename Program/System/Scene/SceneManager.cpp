#include "System/Scene/SceneManager.hpp"
#include "System/ErrorHandling.hpp"

namespace System {

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

void SceneManager::OnCreate()
{
}

//Singlton の破棄処理
void SceneManager::OnDestroy()
{
    if (mCurrent) {
        mCurrent->Finalize();
        mCurrent.reset();
    }
}

} // namespace System

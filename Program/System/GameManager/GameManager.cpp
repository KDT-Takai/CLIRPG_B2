#include "GameManager.hpp"
#include "../Scene/SceneManager.hpp"
#include "../Scene/TitleScene.hpp"

namespace System {

GameManager& GameManager::GetInstance() {
    static GameManager instance;
    return instance;
}

void GameManager::Update()
{
    SceneManager::GetInstance()->Update();
}

void GameManager::Render()
{
}

void GameManager::Initialize()
{
}

bool GameManager::Initilaize()
{
    try {
        SceneManager::Create();
        SceneManager::GetInstance()->SetStartScene<TitleScene>();
        return true;
    } catch (...) {
        return false;
    }
}

void GameManager::Run()
{
    while (mIsRunning == true)
    {
        try {
            this->Update();
            this->Render();
        } catch (...) {
            mIsRunning = false;
        }
    }
}

bool GameManager::Finalize()
{
    try {
        SceneManager::Release();
        return true;
    } catch (...) {
        return false;
    }
}

} // namespace System

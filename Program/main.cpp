#include "System/Singleton/Singleton.hpp"
#include "System/Scene/SceneManager.hpp"
#include "System/Scene/TitleScene.hpp"
#include "System/Entity/Manager/EntityManager.hpp"
#include "System/KeyInput/KeyInput.h"
#include "Graphics/Renderer.hpp"

#include <iostream>

int main() {
    // Initialize singletons
    System::EntityManager::Create();
    System::SceneManager::Create();

    // Set the start scene
    System::SceneManager::GetInstance()->SetStartScene<System::TitleScene>();

    // Main game loop
    while (System::SceneManager::GetInstance()->CurrentSceneName() != "none") {
        System::SceneManager::GetInstance()->Update();
    }

    // Cleanup
    System::SceneManager::Release();
    System::EntityManager::Release();

    return 0;
}

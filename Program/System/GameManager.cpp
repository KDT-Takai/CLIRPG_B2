#include "GameManager.hpp"

namespace System {

GameManager& GameManager::GetInstance() {
    static GameManager instance;
    return instance;
}

void GameManager::Initialize() {}

std::expected<void, ErrorMessage> GameManager::StartGame() {
    return {};
}

} // namespace System

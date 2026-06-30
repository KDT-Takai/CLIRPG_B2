#include "GameManager.hpp"

namespace System {

GameManager& GameManager::GetInstance() {
    static GameManager instance;
    return instance;
}

void GameManager::Initialize() {}

std::expected<void, ErrorMessage> GameManager::StartGame() {
    // ゲーム開始処理
    return {};
}

} // namespace System

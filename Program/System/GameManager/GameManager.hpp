#pragma once
#include <string>

namespace System {

class GameManager {
public:
    static GameManager& GetInstance();
    
    void Initialize() {}
    std::expected<void, std::string> StartGame();
};

} // namespace System

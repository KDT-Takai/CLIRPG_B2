#pragma once
#include <string>
#include "ErrorHandling.hpp"

namespace System {

class GameManager {
public:
    static GameManager& GetInstance();
    
    void Initialize() {}
    void Update() {}
    std::expected<void, ErrorMessage> StartGame();
};

} // namespace System

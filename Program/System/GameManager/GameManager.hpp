#pragma once
#include <string>

namespace System {

class GameManager {
public:
    static GameManager& GetInstance();

    void Initialize();
    void Update();
    void Render();
    void Run();
    bool Finalize();

    bool Initilaize();

private:
    bool mIsRunning = true;
};

} // namespace System

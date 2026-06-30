#include "Renderer.hpp"
#include <iostream>

namespace Graphics {

// コンソール描画マネージャー
class ConsoleManager {
public:
    static ConsoleManager& GetInstance() {
        static ConsoleManager instance;
        return instance;
    }

    void ClearConsole() {
        std::cout << "\033[2J\033[H" << std::flush;
    }

    void AddText(const std::string& text) {
        mLines.push_back(text);
    }

    void Render() {
        // 画面クリア
        ClearConsole();

        // テキスト描画（上から順に）
        for (const auto& line : mLines) {
            std::cout << line << std::endl;
        }

        // リセット
        mLines.clear();
    }

private:
    ConsoleManager() = default;
    ~ConsoleManager() = default;
    ConsoleManager(const ConsoleManager&) = delete;
    ConsoleManager& operator=(const ConsoleManager&) = delete;

    std::vector<std::string> mLines;
};

Renderer& Renderer::GetInstance() {
    static Renderer instance;
    return instance;
}

void Renderer::Initialize() {
    // 初期化処理（stub）
}

void Renderer::Render(const std::string& text) {
    ConsoleManager::GetInstance().AddText(text);
    ConsoleManager::GetInstance().Render();
}

void Renderer::ClearConsole() {
    ConsoleManager::GetInstance().ClearConsole();
}

void Renderer::AddText(const std::string& text) {
    ConsoleManager::GetInstance().AddText(text);
}

} // namespace Graphics

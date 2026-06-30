#include "Renderer.hpp"

namespace Graphics {

ConsoleManager& ConsoleManager::GetInstance() {
    static ConsoleManager instance;
    return instance;
}

void ConsoleManager::ClearConsole() {
    std::cout << "\033[2J\033[H" << std::flush;
}

void ConsoleManager::AddText(const std::string& text) {
    mLines.push_back(text);
}

void ConsoleManager::Render() {
    ClearConsole();
    for (const auto& line : mLines) {
        std::cout << line << std::endl;
    }
    mLines.clear();
}

void ConsoleManager::ClearText() {
    mLines.clear();
}

// --- Renderer ---

Renderer& Renderer::GetInstance() {
    static Renderer instance;
    return instance;
}

void Renderer::Initialize() {
    ConsoleManager::GetInstance().ClearConsole();
}

void Renderer::Render() {
    ConsoleManager::GetInstance().Render();
}

void Renderer::ClearConsole() {
    ConsoleManager::GetInstance().ClearConsole();
}

void Renderer::AddText(const std::string& text) {
    ConsoleManager::GetInstance().AddText(text);
}

void Renderer::ClearText() {
    ConsoleManager::GetInstance().ClearText();
}

} // namespace Graphics

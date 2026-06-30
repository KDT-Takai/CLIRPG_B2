#pragma once
#include <string>
#include <vector>
#include <iostream>

namespace Graphics {

class ConsoleManager {
public:
    static ConsoleManager& GetInstance();
    void ClearConsole();
    void AddText(const std::string& text);
    void Render();
    void ClearText();
private:
    ConsoleManager() = default;
    ~ConsoleManager() = default;
    ConsoleManager(const ConsoleManager&) = delete;
    ConsoleManager& operator=(const ConsoleManager&) = delete;
    std::vector<std::string> mLines;
};

class Renderer {
public:
    static Renderer& GetInstance();
    void Initialize();
    void Render();
    void ClearConsole();
    void AddText(const std::string& text);
    void ClearText();
};

} // namespace Graphics

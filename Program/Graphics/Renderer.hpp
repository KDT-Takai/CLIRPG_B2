#pragma once
#include <string>

namespace Graphics {

class Renderer {
public:
    static Renderer& GetInstance();
    
    void Initialize() {}
    void Render(const std::string& text) {}
    void ClearConsole() {}
    void AddText(const std::string& text) {}
};

} // namespace Graphics

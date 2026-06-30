#pragma once
#include <string>

namespace System {

class Renderer {
public:
    static Renderer& GetInstance();
    
    void Initialize() {}
    void Render(const std::string& text) {}
};

} // namespace System

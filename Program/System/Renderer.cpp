#include "Renderer.hpp"

namespace System {

Renderer& Renderer::GetInstance() {
    static Renderer instance;
    return instance;
}

void Renderer::Initialize() {}

void Renderer::Render(const std::string& text) {}

} // namespace System

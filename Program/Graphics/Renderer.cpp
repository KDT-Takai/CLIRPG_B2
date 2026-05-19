#include"System/Renderer.hpp"
#include <iostream>
#include <atomic>

/// <summary>
/// Console initialization.
/// </summary>
void Graphics::Renderer::OnCreate() {
	mIsDirty = false;
}

/// <summary>
/// Add text to output buffer.
/// </summary>
void Graphics::Renderer::AddText(const std::string& text) {
	mText.push_back(text);
	mIsDirty = true;
}

/// <summary>
/// Clear all text from buffer.
/// </summary>
void Graphics::Renderer::ClearText() {
	mText.clear();
	mIsDirty = true;
}

/// <summary>
/// Clear console and render current buffer.
/// Uses atomic operations for thread-safe rendering.
/// </summary>
void Graphics::Renderer::ClearConsole() {
	// Atomically set dirty flag before clearing to prevent race conditions
	mIsDirty.store(true, std::memory_order_relaxed);

	// Clear console output
	system("cls");
	Render();
}

/// <summary>
/// Render buffered output to console.
/// Uses atomic operations for thread-safe rendering.
/// </summary>
void Graphics::Renderer::Render() {
	if (mIsDirty.load(std::memory_order_acquire))
	{
		for (const auto& text : mText)
		{
			std::cout << text << std::endl;
		}
		mIsDirty.store(false, std::memory_order_release);
	}
}

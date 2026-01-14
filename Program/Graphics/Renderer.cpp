#include "Renderer.hpp"
#include <iostream>

/// <summary>
/// ‰Šú‰»ˆ—
/// </summary>
void Graphics::Renderer::Initialize() {
	mIsDirty = false;
}

/// <summary>
/// •¶š—ñ‚Ì’Ç‰Á
/// </summary>
void Graphics::Renderer::AddText(const std::string& text) {
	mText.push_back(text);
	mIsDirty = true;
}

/// <summary>
/// •¶š—ñ‚Ìíœ
/// </summary>
void Graphics::Renderer::ClearText() {
	mText.clear();
	mIsDirty = true;
}

/// <summary>
/// •\¦ˆ—
/// </summary>
void Graphics::Renderer::Render() {
	if (mIsDirty)
	{
		for (const auto& text : mText)
		{
			std::cout << text << std::endl;
		}
		mIsDirty = false;
	}
}
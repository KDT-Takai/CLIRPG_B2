#include "Renderer.hpp"
#include <iostream>

/// <summary>
/// コンストラクタ
/// </summary>
void Graphics::Renderer::OnCreate() {
	mIsDirty = false;
}

/// <summary>
/// 文字列の追加
/// </summary>
void Graphics::Renderer::AddText(const std::string& text) {
	mText.push_back(text);
	mIsDirty = true;
}

/// <summary>
/// 文字列の削除
/// </summary>
void Graphics::Renderer::ClearText() {
	mText.clear();
	mIsDirty = true;
}

/// <summary>
/// コンソールのクリア
/// </summary>
void Graphics::Renderer::ClearConsole() {
}

/// <summary>
/// 表示処理
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
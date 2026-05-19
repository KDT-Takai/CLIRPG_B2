#pragma once

#include <vector>
#include <string>
#include "System/Singleton/Singleton.hpp"

/// <summary>
/// Console renderer for text output.
/// </summary>
namespace Graphics {
	class Renderer : public Singleton<Renderer> {
		GENERATE_SINGLETON_BODY(Renderer)
	public:
		/// <summary>
		/// Console initialization.
		/// </summary>
		void OnCreate() override;
		/// <summary>
		/// Add text to output buffer.
		/// </summary>
		void AddText(const std::string& text);
		/// <summary>
		/// Clear all text from buffer.
		/// </summary>
		void ClearText();
		/// <summary>
		/// Clear console and render current buffer.
		/// </summary>
		void ClearConsole();
		/// <summary>
		/// Render buffered output to console.
		/// </summary>
		void Render();
	private:
		/// <summary>
		/// Output text buffer.
		/// </summary>
		std::vector<std::string> mText;

		/// <summary>
		/// Dirty flag indicating whether output needs rendering.
		/// Uses atomic for thread-safe access.
		/// </summary>
		std::atomic<bool> mIsDirty{ false };
	};
}

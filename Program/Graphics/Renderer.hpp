#pragma once
#include <vector>
#include <string>
#include "System/Singleton/Singleton.hpp"

/// <summary>
/// 描画管理クラス
/// </summary>
namespace Graphics {
	class Renderer : public Singleton<Renderer> {
		GENERATE_SINGLETON_BODY(Renderer)
	public:
		/// <summary>
		/// 初期化処理
		/// </summary>
		void Initialize();
		/// <summary>
		/// 文字列の追加
		/// </summary>
		void AddText(const std::string& text);
		/// <summary>
		/// 文字列の削除
		/// </summary>
		void ClearText();
		/// <summary>
		/// 表示処理
		/// </summary>
		void Render();
	private:
		/// <summary>
		/// 描画する用のテキストコレクション
		/// </summary>
		std::vector<std::string> mText;
		
		/// <summary>
		/// 文字が追加された場合に表示するフラグ
		/// </summary>
		bool mIsDirty;
	};
}
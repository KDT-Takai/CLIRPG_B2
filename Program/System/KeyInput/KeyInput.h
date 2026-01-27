#pragma once
#include <windows.h>
#include <iostream>
#include <conio.h>
#include <array>
#include <algorithm>

// キー入力管理クラスのヘッダーファイル
namespace System {

	// キー入力管理クラス
	class KeyInput {
	public:
		
		//　キー情報更新
		static void Update();

		//　指定キーが押されているか
		static bool IsPress(int aKey);
		//　指定キーが押された瞬間か
		static bool IsDown(int aKey);
		// 指定キーが離された瞬間か
		static bool IsUP(int aKey);

		// キー数
		static constexpr int KEY_NUM = 256;

	private:
		
		// 現在のキー状態
		static std::array<bool, KEY_NUM> mNow;
		static std::array<bool, KEY_NUM> mPrev;

	};
}
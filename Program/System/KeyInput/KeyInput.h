#pragma once
#include <windows.h>
#include <iostream>
#include <conio.h>
#include <array>
#include <algorithm>

namespace System {

	// キー入力管理クラス
	class KeyInput {
	public:

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
		// キー状態配列
		static std::array<bool, KEY_NUM> mNow;
		static std::array<bool, KEY_NUM> mPrev;

	};
}
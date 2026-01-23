#pragma once
#include <windows.h>
#include <iostream>
#include <conio.h>
#include <array>
#include <algorithm>

namespace Input {

	// キー入力管理クラス
	class KeyInput {
	public:
		//　指定キーが押されているか
		static bool IsPress(int aKey);
		//　指定キーが押された瞬間か
		static bool IsDown(int aKey);
		//　1文字キー入力を取得
		static char GetKey();

		// キー数
		static constexpr int KEY_NUM = 256;

	private:
		// キー状態配列
		static std::array<bool, KEY_NUM> mKeyState;

	};
	// キーが押されているか
	std::array<bool, KeyInput::KEY_NUM> KeyInput::mKeyState = {};
}
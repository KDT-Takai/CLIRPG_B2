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
		// インスタンス取得
		static KeyInput& GetInstance();
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
		// シングルトンパターン
		KeyInput() = default;							// コンストラクタ
		~KeyInput() = default;							// デストラクタ
		KeyInput(const KeyInput&) = delete;				// コピーコンストラクタ	
		KeyInput& operator=(const KeyInput&) = delete;	// キー状態配列

		// 現在のキー状態
		static std::array<bool, KEY_NUM> mNow;
		static std::array<bool, KEY_NUM> mPrev;

	};
}
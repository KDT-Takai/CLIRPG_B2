#include "KeyInput.h"
//　指定キーが押されているか
bool System::KeyInput::IsPress(int aKey) {
	return (GetAsyncKeyState(aKey) & 0x8000) != 0;
}
//　指定キーが押された瞬間か
bool System::KeyInput::IsDown(int aKey) {
    if (aKey < 0 || aKey >= KEY_NUM) return false;

	// 現在のキー状態を取得
    bool now = (GetAsyncKeyState(aKey) & 0x8000);
    bool down = now && !mKeyState[aKey];

	// 状態を更新
    mKeyState[aKey] = now;
    return down;
}
//　1文字キー入力を取得
char System::KeyInput::GetKey() {
	if (_kbhit()) {
		return _getch();
	}
	return 0;
}






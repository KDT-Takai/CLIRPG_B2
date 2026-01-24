#include "KeyInput.h"
namespace System {
    std::array<bool, KeyInput::KEY_NUM> KeyInput::mNow = {};
    std::array<bool, KeyInput::KEY_NUM> KeyInput::mPrev = {};
    void System::KeyInput::Update() {
        mPrev = mNow;
        for (int i = 0; i < KEY_NUM; i++) {
            mNow[i] = (GetAsyncKeyState(i) & 0x8000) != 0;
        }
    }

    //　指定キーが押されているか
    bool System::KeyInput::IsPress(int aKey) {
        return mNow[aKey];
    }
    //　指定キーが押された瞬間か
    bool System::KeyInput::IsDown(int aKey) {
        return mNow[aKey] && !mPrev[aKey];
    }
    //　1文字キー入力を取得
    char System::KeyInput::GetKey() {
        if (_kbhit()) {
            return _getch();
        }
        return 0;
    }

}




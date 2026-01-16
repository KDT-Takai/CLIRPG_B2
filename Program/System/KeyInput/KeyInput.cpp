#include "KeyInput.h"

bool KeyInput::press(int key) {
	return (GetAsyncKeyState(key) & 0x8000) != 0;
}

bool KeyInput::Down(int key) {
	static bool keyState[256] = { false };

	bool now = (GetAsyncKeyState(key) & 0x8000);
	bool down = now && !keyState[key];

	keyState[key] = now;
	return down;
}

char KeyInput::GetKey() {
	if (_kbhit()) {
		return _getch();
	}
	return 0;
}

int main() {
    std::cout << "ESC‚ÅI—¹\n";

    while (true)
    {
        // ‰Ÿ‚³‚ê‚Ä‚¢‚éŠÔ
        if (KeyInput::press('A'))
        {
            std::cout << "A ‰Ÿ‚µ‚Á‚Ï‚È‚µ\n";
        }

        // ‰Ÿ‚µ‚½uŠÔ
        if (KeyInput::Down('B'))
        {
            std::cout << "B ‰Ÿ‚µ‚½I\n";
        }

        // 1•¶Žš“ü—Í
        char c = KeyInput::GetKey();
        if (c)
        {
            std::cout << "“ü—Í: " << c << std::endl;
        }

        if (KeyInput::press(VK_ESCAPE))
        {
            break;
        }

        Sleep(16); // –ñ60FPS
    }

    return 0;
}





#pragma once
#include <windows.h>
#include <iostream>
#include <conio.h>


class KeyInput {
public:
	static bool press(int key);

	static bool Down(int key);

	static char GetKey();

};
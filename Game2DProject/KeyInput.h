#pragma once

#define DIRECTINPUT_VERSION 0x0800


#pragma comment(lib, "dinput8.lib")
#pragma comment(lib, "dxguid.lib")

#include <dinput.h>
#include "Window.h"
#include "Macro.h"

using window::Window;

class KeyInput {
public:
	KeyInput();
	KeyInput(Window* _win);
	~KeyInput();

	bool createDInput();
	bool create();
	void update();

	bool keyDown(BYTE keycode);     //�L�[�������ꂽ��
	bool keyUp(BYTE keycode);       //�L�[�������ꂽ��

private:
	Window* win;

	LPDIRECTINPUT8 directInput;
	LPDIRECTINPUTDEVICE8 keyBoard;

	BYTE beforeKey[256];
	BYTE afterKey[256];

	void relese() noexcept;
};
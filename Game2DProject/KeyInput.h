#ifndef KEYINPUT_H
#define KEYINPUT_H

#define DIRECTINPUT_VERSION 0x0800

#pragma comment(lib, "dinput8.lib")
#pragma comment(lib, "dxguid.lib")

#include <dinput.h>

// キーコード
enum class Key : BYTE {
	A = DIK_A,
	B = DIK_B,
	C = DIK_C,
	D = DIK_D,
	E = DIK_E,
	F = DIK_F,
	G = DIK_G,

	H = DIK_H,
	I = DIK_I,
	J = DIK_J,
	K = DIK_K,
	L = DIK_L,
	N = DIK_N,
	M = DIK_M,

	O = DIK_O,
	P = DIK_P,
	Q = DIK_Q,
	R = DIK_R,
	S = DIK_S,
	T = DIK_T,
	U = DIK_U,

	V = DIK_V,
	W = DIK_W,
	X = DIK_X,
	Y = DIK_Y,
	Z = DIK_Z,

	KEY_0 = DIK_0,
	KEY_1 = DIK_1,
	KEY_2 = DIK_2,
	KEY_3 = DIK_3,
	KEY_4 = DIK_4,
	KEY_5 = DIK_5,
	KEY_6 = DIK_6,
	KEY_7 = DIK_7,
	KEY_8 = DIK_8,
	KEY_9 = DIK_9,

	LEFT = DIK_LEFT,
	RIGHT = DIK_RIGHT,
	UP = DIK_UP,
	DOWN = DIK_DOWN,

	ESC = DIK_ESCAPE,
	SPACE = DIK_SPACE,
	RETURN = DIK_RETURN,
};

#include "Window.h"
using window::Window;

class KeyInput {
public:
	KeyInput(Window* _win);
	~KeyInput();

	bool createDInput();
	bool create();
	void update();

	bool keyDown(Key _keyCode);     //キーが押された時
	bool keyUp(Key _keyCode);       //キーが離された時

private:
	Window* window;

	LPDIRECTINPUT8 device;
	LPDIRECTINPUTDEVICE8 keyBoard;

	BYTE beforeKey[256];
	BYTE afterKey[256];

	void relese() noexcept;
};

using KeyBorad = KeyInput;

#endif // !KEYINPUT_H
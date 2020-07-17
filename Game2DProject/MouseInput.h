#ifndef MOUSEINPUT_H
#define MOUSEINPUT_H

#define DIRECTINPUT_VERSION 0x0800

#pragma comment(lib, "dinput8.lib")
#pragma comment(lib, "dxguid.lib")

#include <dinput.h>

namespace window {
	class Window;
}

using Window = window::Window;

class MouseInput {
public:
	MouseInput(Window* _win);
	~MouseInput();

	bool createDInput();
	bool create();
	void release();
	void update();

	bool getLeftButton();
	bool getRightButton();

private:
	window::Window* window;

	LPDIRECTINPUT8 device;
	LPDIRECTINPUTDEVICE8 lpMouse;
	DIMOUSESTATE mouseState;
};

using Mouse = MouseInput;

#endif // !MOUSEINPUT_H
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
	MouseInput() = default;
	MouseInput(Window* _win);
	~MouseInput();

	void init(Window* _win);
	bool createDInput();
	bool create();
	void release();
	void update();

	bool getLeftButton();
	bool getRightButton();
	bool getMiddleButton();

private:
	window::Window* window;

	LPDIRECTINPUT8 device = nullptr;
	LPDIRECTINPUTDEVICE8 lpMouse = nullptr;
	DIMOUSESTATE mouseState;
};

using Mouse = MouseInput;

#endif // !MOUSEINPUT_H
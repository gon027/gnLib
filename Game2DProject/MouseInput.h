#ifndef MOUSEINPUT_H
#define MOUSEINPUT_H

#include "Input.h"
#include "Window.h"
#include "SmartPtr.h"

enum {
	MOUSE_LEFT,
	MOUSE_RIGHT,
	MOUSE_MIDDLE,
};

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

	LPDIRECTINPUT8 directInput;
	LPDIRECTINPUTDEVICE8 lpMouse;
	DIMOUSESTATE mouseState;
};

using Mouse = MouseInput;

#endif // !MOUSEINPUT_H
#ifndef MOUSEINPUT_H
#define MOUSEINPUT_H

#define DIRECTINPUT_VERSION 0x0800

#pragma comment(lib, "dinput8.lib")
#pragma comment(lib, "dxguid.lib")

#include <dinput.h>

namespace gnLib {
	class Window;
	class Vector2;

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

		Vector2 getPosition() const;

	private:
		gnLib::Window* window;

		LPDIRECTINPUT8 device = nullptr;
		LPDIRECTINPUTDEVICE8 lpMouse = nullptr;
		DIMOUSESTATE mouseState;
	};

	using Mouse = MouseInput;
}

#endif // !MOUSEINPUT_H
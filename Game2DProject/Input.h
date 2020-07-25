#ifndef INPUT_H
#define INPUT_H

// マウス
#include "MouseInput.h"

// キーボード
#include "KeyInput.h"

namespace window {
	class Window;
}

using Window = window::Window;

namespace Input {
	static KeyBorad key;
	static Mouse mouse;

	bool initInputDevice(Window* _widnow);

	int inputMouse();

	int putkey();
}

#endif // !INPUT_H

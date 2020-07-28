#ifndef INPUT_H
#define INPUT_H

// �}�E�X
#include "MouseInput.h"

// �L�[�{�[�h
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

#ifndef KEYINPUT_H
#define KEYINPUT_H

#include <array>
#include "Key.h"

namespace gnLib {

	struct BufferKey {
		BYTE buffer[256];
		BYTE oldKey[256];

		BufferKey(): buffer(), oldKey() { }
		~BufferKey() = default;
	};

	class Window;

	class KeyInput {
	public:
		KeyInput() = default;
		KeyInput(Window* _win);
		~KeyInput();

		void init(Window* _win);
		bool createDInput();
		bool create();
		void update();

		bool getKey(Key _keyCode);     // キーが押されているとき
		bool getKeyDown(Key _keyCode); // キーが押された時
		bool getKeyUp(Key _keyCode);   // キーが離された時

	private:
		Window* window;

		LPDIRECTINPUT8 device;
		LPDIRECTINPUTDEVICE8 keyBoard;

		BufferKey bufferKey;

		void relese() noexcept;
	};
}

using KeyBorad = gnLib::KeyInput;

#endif // !KEYINPUT_H
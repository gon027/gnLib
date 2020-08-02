#ifndef GAMECORE_H
#define GAMECORE_H

#include <string>
#include "include/Common/SmartPtr.h"

using std::string;

namespace gnLib {
	class Window; 
	class Graphics;
	class KeyInput;
	class MouseInput;
	class Console;

	// ゲームに使われる主要なクラスをまとめたクラス
	class GameCore {
	public:
		GameCore() = default;

		static GameCore Instance;

		static void init();
		static void update();

		static Window* getWindow();
		static Graphics* getGraphic();
		static KeyInput* getKeyBoard();
		static MouseInput* getMouse();

	private:
		static UniquePtr<Window> window;
		static UniquePtr<Graphics> graphics;
		static UniquePtr<KeyInput> keyBoard;
		static UniquePtr<MouseInput> mouse;
		// static UniquePtr<Console> console;
	};

}

#endif // !GAMECORE_H

#ifndef GAMECORE_H
#define GAMECORE_H

#include <string>
#include "../../include/Common/SmartPtr.h"

using std::string;

#define GCoreIns GameCore::Instance

namespace gnLib {
	class Window; 
	class Graphics;
	class KeyInput;
	class MouseInput;
	class Console;
	class Render;

	// ゲームに使われる主要なクラスをまとめたクラス
	class GameCore {
	public:
		GameCore();
		~GameCore() = default;

		static GameCore* Instance;

		void initWindow(const string& _title, int _width, int _height);
		void init();
		void update();

		Window* getWindow();
		Graphics* getGraphic();
		KeyInput* getKeyBoard();
		MouseInput* getMouse();

	private:
		UniquePtr<Window> window;
		UniquePtr<Graphics> graphics;
		UniquePtr<KeyInput> keyBoard;
		UniquePtr<MouseInput> mouse;
		// UniquePtr<Console> console;
	};

}

#endif // !GAMECORE_H

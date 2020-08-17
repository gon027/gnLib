#ifndef GAMECORE_H
#define GAMECORE_H

#include <string>
#include "../../include/Common/SmartPtr.h"

using std::string;

#define GCoreIns GameCore::get()

namespace gnLib {
	class Window; 
	class Graphics;
	class KeyInput;
	class MouseInput;
	class Render;

	// ゲームに使われる主要なクラスをまとめたクラス
	class GameCore {
	public:
		GameCore();
		~GameCore();
		
		static GameCore* get();

		void initWindow(const string& _title, int _width, int _height);
		void init();
		void update();

		Window* getWindow();
		Graphics* getGraphic();
		KeyInput* getKeyBoard();
		MouseInput* getMouse();

	private:
		static GameCore* Instance;

		UniquePtr<Window> window;
		UniquePtr<Graphics> graphics;
		UniquePtr<KeyInput> keyBoard;
		UniquePtr<MouseInput> mouse;
	};

}

#endif // !GAMECORE_H

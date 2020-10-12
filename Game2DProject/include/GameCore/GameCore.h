#ifndef GAMECORE_H
#define GAMECORE_H

#include <string>
#include "../../include/Common/SmartPtr.h"
#include "../../include/Render/Render.h"

using std::string;

#define GCoreIns       GameCore::get()
//#define GCoreRender    GameCore::get()->getRender()
//#define RDevice        GameCore::get()->getRender()->getGraphics()->getDevice();
//#define RLineDevice    GameCore::get()->getRender()->getLineDevice()

namespace gnLib {
	class Window; 
	class Graphics;
	class KeyInput;
	class MouseInput;
	//class Render;

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

		UniquePtr<Window>     window;    // ウインドウ
		UniquePtr<Graphics>   graphics;  // グラフィクス
		UniquePtr<KeyInput>   keyBoard;  // キーボード
		UniquePtr<MouseInput> mouse;     // マウス
		Render     render;    // レンダー
	};

}

#endif // !GAMECORE_H

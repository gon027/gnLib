#ifndef GAMECORE_H
#define GAMECORE_H

#include <string>
#include "../../include/Common/SmartPtr.h"
#include "../../include/Render/Render.h"

using std::string;

#define GCoreIns        GameCore::get()
#define GCGraphics      GameCore::get()->getGraphic()->getDevice()
#define GCRenderDevice  GameCore::get()->getRenderDevice()
//#define RDevice       GameCore::get()->getRender()->getGraphics()->getDevice();
#define GCLineDevice    GameCore::get()->getRenderDevice()->getLineDevice()

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

		Window*        getWindow();
		Graphics*      getGraphic();
		KeyInput*      getKeyBoard();
		MouseInput*    getMouse();
		RenderDevice_* getRenderDevice();

	private:
		static GameCore* Instance;

		UniquePtr<Window>        window;        // ウインドウ
		UniquePtr<Graphics>      graphics;      // グラフィクス
		UniquePtr<KeyInput>      keyBoard;      // キーボード
		UniquePtr<MouseInput>    mouse;         // マウス
		UniquePtr<RenderDevice_> renderDevice;	// レンダーデバイス
	};

}

#endif // !GAMECORE_H

#ifndef GAMECORE_H
#define GAMECORE_H

#include <string>
#include "../../include/Common/SmartPtr.h"

using std::string;

#define GCoreIns        GameCore::get()
#define GCWindow        GameCore::get()->getGraphic()->getWindow()
#define GCGraphics      GameCore::get()->getGraphic()->getDevice()
#define GCRenderDevice  GameCore::get()->getRenderDevice()
#define GCLineDevice    GameCore::get()->getRenderDevice()->getLineDevice()

namespace gnLib {

	class Window; 
	class Graphics;
	class KeyInput;
	class MouseInput;
	class RenderDevice;

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
		RenderDevice*  getRenderDevice();

	private:
		static GameCore* Instance;

		UniquePtr<Window>        window;        // ウインドウ
		UniquePtr<Graphics>      graphics;      // グラフィクス
		UniquePtr<KeyInput>      keyBoard;      // キーボード
		UniquePtr<MouseInput>    mouse;         // マウス
		UniquePtr<RenderDevice>  renderDevice;	// レンダーデバイス
	};

}

#endif // !GAMECORE_H

#ifndef GAMECORE_H
#define GAMECORE_H

#include <string>
#include "../../include/Common/SmartPtr.h"

using std::string;

#define GCoreIns        GameCore::get()
#define GCWindow        GameCore::get()->getGraphic()->getWindow()
#define GCGraphics      GameCore::get()->getGraphic()->getDevice()
#define GCInputMouse    GameCore::get()->getMouse()
#define GCInputKeyBoard GameCore::get()->getKeyBoard()
#define GCSprite        GameCore::get()->getSprite()
#define GCRenderDevice  GameCore::get()->getRenderDevice()
#define GCLineDevice    GameCore::get()->getRenderDevice()->getLineDevice()
#define GCStrDevice     GameCore::get()->getRenderDevice()->getFontDevice()

namespace gnLib {

	class Window; 
	class Graphics;
	class KeyInput;
	class MouseInput;
	class SpriteRender;
	class RenderDevice;
	class Console;

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
		SpriteRender*  getSprite();
		RenderDevice*  getRenderDevice();

	private:
		static GameCore* Instance;

		UniquePtr<Window>        window;        // ウインドウ
		UniquePtr<Graphics>      graphics;      // グラフィクス
		UniquePtr<KeyInput>      keyBoard;      // キーボード
		UniquePtr<SpriteRender>  spriteRender;  // スプライトレンダー
		UniquePtr<MouseInput>    mouse;         // マウス
		UniquePtr<RenderDevice>  renderDevice;	// レンダーデバイス
	};

}

#endif // !GAMECORE_H

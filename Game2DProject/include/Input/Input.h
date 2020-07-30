#ifndef INPUT_H
#define INPUT_H

// キーボード
#include "KeyInput.h"

// マウス
#include "MouseInput.h"

namespace window {
	class Window;
}

using Window = window::Window;

class Input {
public:
	static void init(Window* _widnow);
	static void update();

	// キーボード
	static bool getKeyDown(Key key);	// キーを下げたとき
	static bool getKeyUp(Key key);		// キーを上げたとき
	static bool getKeyState(Key key);	// キーを押したままのとき

	// マウス
	static bool getLeftButton();		// マウスの左を押したとき
	static bool getRightButton();		// マウスの右を押したとき
	static bool getMiddleButton();		// マウスの真ん中を押したとき
	static int getPosition();			// マウスの座標を取得する

private:
	static KeyBorad keyBorad;
	static Mouse mouse;
};

#endif // !INPUT_H

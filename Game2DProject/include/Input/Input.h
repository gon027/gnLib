#ifndef INPUT_H
#define INPUT_H

// キーボード
#include "KeyInput.h"

// マウス
#include "MouseInput.h"

namespace gnLib {
	class Window;
	class Vector2;

	// マウスの入力ボタン
	enum class MouseButton : int {
		LEFT = 0,
		RIGHT = 1,
		MIDDLE = 2
	};

	class Input {
	public:

		// キーボード
		static bool getKeyDown(Key key);	// キーを下げたとき
		static bool getKeyUp(Key key);		// キーを上げたとき
		static bool getKeyState(Key key);	// キーを押したままのとき

		// マウス
		static bool getLeftButton();		// マウスの左を押したとき
		static bool getRightButton();		// マウスの右を押したとき
		static bool getMiddleButton();		// マウスの中心を押したとき
		static Vector2 getPosition();		// マウスの座標を取得する

	};
}

#endif // !INPUT_H

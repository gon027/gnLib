#ifndef INPUT_H
#define INPUT_H

// キーボード
#include "KeyInput.h"

// マウス
#include "MouseInput.h"

namespace gnLib {

	class Vector2;

	// マウスの入力ボタン
	enum class MouseButton : int {
		LEFT   = 0,
		RIGHT  = 1,
		MIDDLE = 2
	};

	class Input {
	public:

		// キーボード
		static bool getKeyDown(Key _key);   // キーを下げたとき
		static bool getKeyUp(Key _key);     // キーを上げたとき
		static bool getKey(Key _key);       // キーを押したままのとき

		// マウス
		static bool getLeftButton();        // マウスの左を押したとき
		static bool getRightButton();       // マウスの右を押したとき
		static bool getMiddleButton();      // マウスの中心を押したとき
		static Vector2 getPos();            // マウスの座標を取得する
	};
}

#endif // !INPUT_H

#ifndef RECT_H
#define RECT_H

#include <Vector/Vector2.h>
#include <Color/Color.h>
#include <Bounds/Bounds.h>

namespace gnLib {

	class Rect {
	public:
		Rect();
		Rect(float _x, float _y, float _width, float _height);
		Rect(const Vector2& _v, float _width, float _height);
		~Rect() = default;

		// 座標を設定
		Rect& setPos(float _x, float _y);
		Rect& setPos(const Vector2& _v);

		// 大きさを設定
		Rect& setSize(float _width, float _height);
		Rect& setSize(float _wh);

		// 回転させる
		Rect& setRotate(float _rot);

		// 色を設定
		Rect& setColor(const Color& _color);

		// 描画
		void draw();

	private:
		Vector2 position;
		


		float width;         // 横幅
		float height;        // 横幅
		float radian;        // 回転角
		Color color;         // 色
	};

}

#endif // !RECT_H

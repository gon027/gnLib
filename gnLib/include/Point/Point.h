#ifndef POINT_H
#define POINT_H

#include <Vector/Vector2.h>
#include <Color/Color.h>

namespace gnLib {

	class Point {
	public:
		Point();
		Point(const Vector2& _pos);
		~Point() = default;

		// 座標を設定
		Point& setPos(const Vector2& _pos);

		// 色を設定
		Point& setColor(const Color& _color);

		// 描画
		void draw();

	private:
		Vector2 position;
		Color color;
	};

}

#endif // !POINT_H

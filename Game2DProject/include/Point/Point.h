#ifndef POINT_H
#define POINT_H

#include "../Object/Object.h"
#include "../Vector/Vector2.h"
#include "../Color/Color.h"

namespace gnLib {

	class Point : public Object{
	public:
		Point();
		Point(const Vector2& _pos);
		~Point() = default;

		// 座標を設定
		void setPos(const Vector2& _pos);

		// 色を設定
		void setColor(const Color& _color);

		// 描画
		void draw();

		// 座標取得
		Vector2 getPos() const;

	private:
		Vector2 position;
		Color color;
	};

}

#endif // !POINT_H

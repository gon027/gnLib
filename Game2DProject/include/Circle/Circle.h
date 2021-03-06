#ifndef CIRCLE_H
#define CIRCLE_H

#include "../../include/Object/Object.h"
#include "../../include/Vector/Vector2.h"
#include "../../include/Color/Color.h"

namespace gnLib {

	/// <summary>
	/// 円を描画するクラス
	/// </summary>
	class Circle {
	public:
		Circle();
		Circle(float _x, float _y, float _r);
		Circle(Vector2 _pos, float _r);
		~Circle() = default;

		// 座標を設定
		void setPos(float _x, float _y);
		void setPos(const Vector2& _vector);

		// 円の大きさを設定
		void setRadius(float _radius);

		// 色を設定
		void setColor(const Color& _color);
		void setColor(int _r, int _g, int _b);

		// 描画
		void draw();

	private:
		Vector2 position;
		float radius;
		Color color;
	};
}

#endif // !CIRCLE_H

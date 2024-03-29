#ifndef CIRCLE_H
#define CIRCLE_H

#include <Vector/Vector2.h>
#include <Color/Color.h>

namespace gnLib {

	/// <summary>
	/// 円を描画するクラス
	/// </summary>
	class Circle {
	public:
		Circle();
		Circle(float _x, float _y, float _r);
		Circle(const Vector2& _pos, float _r);
		~Circle() = default;

		// 座標を設定
		Circle& setPos(float _x, float _y);
		Circle& setPos(const Vector2& _vector);

		// 円の大きさを設定
		Circle& setRadius(float _radius);

		// 色を設定
		Circle& setColor(const Color& _color);
		Circle& setColor(int _r, int _g, int _b);

		// 描画
		void draw();

	private:
		Vector2 position;
		float radius;
		Color color;
	};
}

#endif // !CIRCLE_H

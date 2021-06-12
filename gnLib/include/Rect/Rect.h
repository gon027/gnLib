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

		// À•W‚ğİ’è
		Rect& setPos(float _x, float _y);
		Rect& setPos(const Vector2& _v);

		// ‘å‚«‚³‚ğİ’è
		Rect& setSize(float _width, float _height);
		Rect& setSize(float _wh);

		// ‰ñ“]‚³‚¹‚é
		Rect& setRotate(float _rot);

		// F‚ğİ’è
		Rect& setColor(const Color& _color);

		// •`‰æ
		void draw();

	private:
		Vector2 position;
		


		float width;         // ‰¡•
		float height;        // ‰¡•
		float radian;        // ‰ñ“]Šp
		Color color;         // F
	};

}

#endif // !RECT_H

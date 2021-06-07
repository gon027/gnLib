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

		// À•W‚ğİ’è
		void setPos(const Vector2& _pos);

		// F‚ğİ’è
		void setColor(const Color& _color);

		// •`‰æ
		void draw();

	private:
		Vector2 position;
		Color color;
	};

}

#endif // !POINT_H

#ifndef CIRCLE_H
#define CIRCLE_H

#include "../../include/Object/Object.h"
#include "../../include/Vector/Vector2.h"
#include "../../include/Color/Color.h"

namespace gnLib {

	class Circle : public Object {
	public:
		Circle();
		Circle(float _x, float _y, float _r);
		Circle(Vector2 _pos, float _r);
		~Circle() = default;

		void setPosition(float _x, float _y);
		void setPosition(const Vector2& _vector);

		void setRadius(float _radius);

		void setColor(const Color& _color);
		void setColor(int _r, int _g, int _b);

		void draw();
		void draw(float _x, float _y, float _radius);

	private:
		Vector2 position;
		float radius;
		Color color;
	};
}

#endif // !CIRCLE_H

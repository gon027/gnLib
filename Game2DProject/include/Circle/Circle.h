#ifndef CIRCLE_H
#define CIRCLE_H

#include "../../include/Object/Object.h"

namespace gnLib {
	class Circle : public Object {
	public:
		Circle();
		~Circle() = default;

		void draw(float _x, float _y, float _radius);

	private:
		float x;
		float y;
		float radius;
	};
}

#endif // !CIRCLE_H

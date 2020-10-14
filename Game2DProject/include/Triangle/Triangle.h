#ifndef TRYANGLE_H
#define TRYANGLE_H

#include "../Object/Object.h"
#include "../Vector/Vector2.h"
#include "../Color/Color.h"

namespace gnLib {
	class Triangle : public Object {
	public:
		Triangle(const Vector2& _pos1, const Vector2& _pos2, const Vector2& _pos3);

	private:
		Color color;
	};
}

#endif // !TRYANGLE_H

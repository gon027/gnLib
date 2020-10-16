#ifndef BOUNDS_H
#define BOUNDS_H

#include "include/Vector/Vector2.h"

namespace gnLib {

	struct Bounds {
		Vector2 leftTop;
		Vector2 leftBottom;
		Vector2 rightTop;
		Vector2 rightBottom;

		Bounds()  = default;
		~Bounds() = default;
	};
}

#endif // !BOUNDS_H

#ifndef BOUNDS_H
#define BOUNDS_H

#include "../Vector/Vector2.h"

namespace gnLib {

	struct Bounds {
		Vector2 center;
		Vector2 minPos;
		Vector2 maxPos;
		Vector2 size;

		Bounds()  = default;
		~Bounds() = default;
	};

}

#endif // !BOUNDS_H

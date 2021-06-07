#ifndef ICOLLIDER_H
#define ICOLLIDER_H

#include "Collision2D.h"

namespace gnLib {

	class BoxCollider;
	class CircleCollider;

	enum class ColliderType : int {
		Box,
		Circle,
	};

	class ICollider {
	public:
		virtual ~ICollider() {};

		virtual ColliderType getType() const = 0;
	};

}

#endif // !ICOLLIDER_H

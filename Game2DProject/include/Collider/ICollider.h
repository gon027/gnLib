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

		virtual bool isCollsion(const ICollider& _collider) = 0;

	protected:
		bool isCollsion(const BoxCollider& _collider);

		bool isCollsion(const CircleCollider& _collider);
	};

}

#endif // !ICOLLIDER_H

#ifndef ICOLLIDER_H
#define ICOLLIDER_H

#pragma comment(lib, "d3dx9.lib")
#include <d3dx9.h>

namespace gnLib {

	class BoxCollider;
	class CircleCollider;

	enum class ColliderType : int {
		BOX,
		CIRCLE,
	};

	class ICollider {
	public:
		virtual ~ICollider() {};

		virtual ColliderType getType() = 0;

		virtual bool isHitTest(const BoxCollider& _collider) = 0;
		virtual bool isHitTest(const CircleCollider& _collider) = 0;
	};

}

#endif // !ICOLLIDER_H

#ifndef ICOLLIDER_H
#define ICOLLIDER_H

#pragma comment(lib, "d3dx9.lib")
#include <d3dx9.h>

enum class ColliderType : int {
	RECT,			// ãÈå`
	CIRCLE,			// â~
	LINE,			// ê¸
	POINT,			// ì_
	POLYGON,		// ëΩäpå`
};

/*
class CircleCollider;
class BoxCollider;
class PolygonCollider;
*/

class ICollider {
public:
	virtual ~ICollider() {};

	virtual ColliderType getType() = 0;

	/*
	bool boxHitTest(const CircleCollider& _collider);
	bool boxHitTest(const BoxCollider& _collider);
	bool boxHitTest(const PolygonCollider& _collider);

	bool circleHitTest(const CircleCollider& _collider);
	bool circleHitTest(const BoxCollider& _collider);
	bool circleHitTest(const PolygonCollider& _collider);

	bool polygonHitTest(const CircleCollider& _collider);
	bool polygonHitTest(const BoxCollider& _collider);
	bool polygonHitTest(const PolygonCollider& _collider);
	*/
};



#endif // !ICOLLIDER_H

#ifndef BASECOLLIDER_H
#define BASECOLLIDER_H

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

class BaseCollider {
public:
	virtual ~BaseCollider() {};

	virtual ColliderType getType() = 0;

	/*
	bool boxHitTest(const CircleCollider& _cCollider);
	bool boxHitTest(const BoxCollider& _cCollider);
	bool boxHitTest(const PolygonCollider& _cCollider);

	bool circleHitTest(const CircleCollider& _cCollider);
	bool circleHitTest(const BoxCollider& _cCollider);
	bool circleHitTest(const PolygonCollider& _cCollider);

	bool polygonHitTest(const CircleCollider& _cCollider);
	bool polygonHitTest(const BoxCollider& _cCollider);
	bool polygonHitTest(const PolygonCollider& _cCollider);
	*/
};



#endif // !BASECOLLIDER_H

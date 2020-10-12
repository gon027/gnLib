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

namespace gnLib {
	class ICollider {
	public:
		virtual ~ICollider() {};

		virtual ColliderType getType() = 0;
	};

}

#endif // !ICOLLIDER_H

#ifndef ICOLLIDER_H
#define ICOLLIDER_H

#pragma comment(lib, "d3dx9.lib")
#include <d3dx9.h>

enum class ColliderType : int {
	RECT,			// ��`
	CIRCLE,			// �~
	LINE,			// ��
	POINT,			// �_
	POLYGON,		// ���p�`
};

namespace gnLib {
	class ICollider {
	public:
		virtual ~ICollider() {};

		virtual ColliderType getType() = 0;
	};

}

#endif // !ICOLLIDER_H

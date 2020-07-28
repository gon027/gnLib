#ifndef BASECOLLIDER_H
#define BASECOLLIDER_H

#pragma comment(lib, "d3dx9.lib")
#include <d3dx9.h>

enum class ColliderType : int {
	RECT,			// ��`
	CIRCLE,			// �~
	LINE,			// ��
	POINT,			// �_
	POLYGON,		// ���p�`
};

class BaseCollider {
public:
	virtual ~BaseCollider() {};

	virtual ColliderType getType() = 0;
};

#endif // !BASECOLLIDER_H

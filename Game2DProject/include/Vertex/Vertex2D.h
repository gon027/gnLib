#ifndef VERTEX3D_H
#define VERTEX3D_H

#include <windows.h>

namespace gnLib {

	struct Vertex2D {
		float x, y, z;	// ���_���W
		float rhw;		// ���Z��
		DWORD color;	// ���_�̐F
		float u, v;		// �e�N�X�`�����W
	};

}

#endif // !VERTEX3D_H

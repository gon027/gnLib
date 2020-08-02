#ifndef VERTEX3D_H
#define VERTEX3D_H

#include <windows.h>

namespace gnLib {

	struct Vertex3D {
		float x, y, z;
		float u, v;
		DWORD color;
	};

}

#endif // !VERTEX3D_H

#ifndef VERTEX3D_H
#define VERTEX3D_H

#include <windows.h>

namespace gnLib {

	struct Vertex2D {
		float x, y, z;	// 頂点座標
		float rhw;		// 徐算数
		DWORD color;	// 頂点の色
		float u, v;		// テクスチャ座標
	};

}

#endif // !VERTEX3D_H

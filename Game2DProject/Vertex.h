#ifndef VERTEX_H
#define VERTEX_H

#include <windows.h>

struct Vertex {
	float x, y, z, rhw;
	DWORD color;
};

#endif // !VERTEX_H

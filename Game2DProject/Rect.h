#ifndef RECT_H
#define RECT_H

#include "BoxCollider.h"

#pragma comment(lib, "d3dx9.lib")
#include <d3dx9.h>

class Graphics;

class RectAngle {
public:
	RectAngle();
	~RectAngle();

	void draw(float _x, float _y, float _xsize, float _ysize, DWORD _color);

	BoxCollider collider;

private:
	D3DXVECTOR3 position;
};

#endif // !RECT_H

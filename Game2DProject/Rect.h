#ifndef RECT_H
#define RECT_H

#pragma comment(lib, "d3dx9.lib")
#include <d3dx9.h>

#include "IDraw.h"


class Graphics;

class RectAngle {
public:
	RectAngle();
	~RectAngle();

	void draw(Graphics& _graphics, float _x, float _y, float _xsize, float _ysize, DWORD _color);

private:
	D3DXVECTOR3 position;

};

#endif // !RECT_H

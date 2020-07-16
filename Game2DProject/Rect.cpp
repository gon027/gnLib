#include "Rect.h"
#include "Graphics.h"
#include "Vertex2D.h"
#include "Macro.h"

RectAngle::RectAngle()
	: position()
{

}

RectAngle::~RectAngle()
{

}

void RectAngle::draw(Graphics* _graphics, float _x, float _y, float _xsize, float _ysize, DWORD _color)
{
	float x = _x;
	float y = _y;
	float sx = x + _xsize;
	float sy = y + _ysize;

	Vertex2D vertex[] = {
		{ x, sy, 0.0f, 1.0f, _color},
		{ x,  y, 0.0f, 1.0f, _color},
		{sx, sy, 0.0f, 1.0f, _color},
		{sx,  y, 0.0f, 1.0f, _color},
	};


	_graphics->device->SetFVF(FVF_CUSTOM2D);
	_graphics->device->DrawPrimitiveUP(D3DPT_TRIANGLESTRIP, 2, vertex, sizeof(Vertex2D));
}

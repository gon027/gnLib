#include "Rect.h"
#include "Graphics.h"
#include "Vertex2D.h"
#include "Macro.h"
#include "Render.h"

RectAngle::RectAngle()
	: position()
{

}

RectAngle::~RectAngle()
{

}

void RectAngle::draw(float _x, float _y, float _xsize, float _ysize, DWORD _color)
{
	float x = _x;
	float y = _y;
	float sx = x + _xsize;
	float sy = y + _ysize;

	Vertex2D vertex[] = {
		{ x, sy, 0.0f, 1.0f, _color, 0.0f, 0.0f},
		{ x,  y, 0.0f, 1.0f, _color, 0.0f, 0.0f},
		{sx, sy, 0.0f, 1.0f, _color, 0.0f, 0.0f},
		{sx,  y, 0.0f, 1.0f, _color, 0.0f, 0.0f},
	};


	RenderDevice->SetFVF(FVF_CUSTOM2D);
	RenderDevice->DrawPrimitiveUP(D3DPT_TRIANGLESTRIP, 2, vertex, sizeof(Vertex2D));
}

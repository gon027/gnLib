#include "Point.h"
#include "../Common/Macro.h"
#include "../Graphics/Graphics.h"
#include "../Render/Render.h"
#include "../Color/Color.h"
#include "../Vertex/Vertex2D.h"

void Point::draw(float _x, float _y)
{
	Vertex2D vertex[1] = { _x, _y, 0.0f, 1.0f, 0xFFFF0000, 0.0f, 0.0f };

	RenderDevice->SetFVF(FVF_CUSTOM2D);
	RenderDevice->DrawPrimitiveUP(
		D3DPT_POINTLIST,
		1,
		vertex,
		sizeof(Vertex2D)
	);
}

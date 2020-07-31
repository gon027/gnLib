#include "Line.h"
#include "../../include/Common/Macro.h"
#include "../../include/Graphics/Graphics.h"
#include "../../include/Render/Render.h"
#include "../../include/Color/Color.h"
#include "../../include/Vertex/Vertex2D.h"

void Line::draw(float _x1, float _y1, float _x2, float _y2)
{
	Vertex2D vertex[2] = {
		{_x1, _y1, 0.0f, 1.0f, 0xFFFF0000, 0.0f, 0.0f},
		{_x2, _y2, 0.0f, 1.0f, 0xFFFF0000, 0.0f, 0.0f}
	};

	RenderDevice->SetFVF(FVF_CUSTOM2D);
	RenderDevice->DrawPrimitiveUP(
		D3DPT_LINELIST,
		1,
		vertex,
		sizeof(Vertex2D)
	);
}

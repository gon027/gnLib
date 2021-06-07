#include "../../include/Line/Line.h"
#include "../../include/GameCore/GameCore.h"
#include "../../include/Common/Macro.h"
#include "../../include/Graphics/Graphics.h"
#include "../../include/Render/Render.h"
#include "../../include/Vertex/Vertex2D.h"

namespace gnLib {
	
	Line::Line()
		: start(Vector2::Zero)
		, end(Vector2::Zero)
		, weight(1.0f)
		, color(Color::White)
	{
	}

	Line::Line(float _sx, float _sy, float _gx, float _gy)
		: start({_sx, _sy})
		, end({_gx, _gy})
		, weight(1.0f)
		, color(Color::White)
	{ 
	}

	Line::Line(const Vector2 & _v1, const Vector2 & _v2)
		: start(_v1)
		, end(_v2)
		, weight(1.0f)
		, color(Color::White)
	{
	}
	
	void Line::setPos(float _sx, float _sy, float _gx, float _gy)
	{
		start.setPos(_sx, _sy);
		end.setPos(_gx, _gy);
	}

	void Line::setPos(const Vector2 & _v1, const Vector2 & _v2)
	{
		start.setPos(_v1);
		end.setPos(_v2);
	}

	void Line::setWeight(float _weight)
	{
		weight = _weight;
	}

	void Line::setColor(Color _color)
	{
		color = _color;
	}

	void Line::draw()
	{
		D3DXVECTOR2 vLise[] = {
			{start.x, start.y},
			{end.x, end.y}
		};
		
		GCLineDevice->SetAntialias(true);
		GCLineDevice->SetWidth(weight);
		GCLineDevice->Begin();
		{
			GCLineDevice->Draw(
				vLise, 2, color.getColor()
			);
		}
		GCLineDevice->End();
	}
}

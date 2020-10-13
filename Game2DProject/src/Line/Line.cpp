#include "../../include/Line/Line.h"
#include "../../include/GameCore/GameCore.h"
#include "../../include/Common/Macro.h"
#include "../../include/Graphics/Graphics.h"
#include "../../include/Render/Render.h"
#include "../../include/Vertex/Vertex2D.h"

namespace gnLib {
	
	Line::Line()
		: pos1(Vector3::Zero)
		, pos2(Vector3::Zero)
		, weight(1.0f)
		, color(Color::White)
	{
	}

	Line::Line(float _sx, float _sy, float _gx, float _gy)
		: pos1({_sx, _sy, 0.0f})
		, pos2({_gx, _gy, 0.0f})
		, weight(1.0f)
		, color(Color::White)
	{ 
	}

	Line::Line(const Vector2 & _v1, const Vector2 & _v2)
		: pos1({ _v1.x, _v1.y, 0.0f })
		, pos2({ _v2.x, _v2.y, 0.0f })
		, weight(1.0f)
		, color(Color::White)
	{
	}

	Line::Line(const Vector3 & _v1, const Vector3 & _v2)
		: pos1(_v1)
		, pos2(_v2)
		, weight(1.0f)
		, color(Color::White)
	{
	}

	Line::~Line()
	{
	}
	
	void Line::setPos(float _sx, float _sy, float _gx, float _gy)
	{
		pos1.setPos(_sx, _sy, 0.0f);
		pos2.setPos(_gx, _gy, 0.0f);
	}

	void Line::setPos(const Vector2 & _v1, const Vector2 & _v2)
	{
		pos1.setPos(_v1.x, _v1.y, 0.0f);
		pos2.setPos(_v2.x, _v2.y, 0.0f);
	}

	void Line::setPos(const Vector3 & _v1, const Vector3 & _v2)
	{
		pos1 = _v1;
		pos2 = _v2;
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
			{pos1.x, pos1.y},
			{pos2.x, pos2.y}
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

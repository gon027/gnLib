#include <Line/Line.h>
#include <GameCore/GameCore.h>
#include <GraphicsRender.h>

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
		GCGraphicsRender->drawLine2D(
			start.x, start.y,
			end.x, end.y,
			weight,
			0.0f,
			color
		);
	}
}

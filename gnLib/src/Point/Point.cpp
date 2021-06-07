#include "../../include/Point/Point.h"
#include "../../include/GameCore/GameCore.h"
#include "../../gnLibCore/include/GraphicsRender.h"

namespace gnLib {

	Point::Point()
		: position(Vector2::Zero)
		, color(Color::Black)
	{

	}

	Point::Point(const Vector2& _pos)
		: position(_pos)
		, color(Color::Black)
	{

	}

	void Point::setPos(const Vector2& _pos)
	{
		position = _pos;
	}

	void Point::setColor(const Color& _color)
	{
		color = _color;
	}

	void Point::draw()
	{
		GCGraphicsRender->drawPoint2D(position.x, position.y, color);
	}
}
#include <Point/Point.h>
#include <GameCore/GameCore.h>
#include <GraphicsRender/GraphicsRender.h>

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

	Point& Point::setPos(const Vector2& _pos)
	{
		position = _pos;

		return *this;
	}

	Point& Point::setColor(const Color& _color)
	{
		color = _color;

		return *this;
	}

	void Point::draw()
	{
		GCGraphicsRender->drawPoint2D(position.x, position.y, color);
	}
}
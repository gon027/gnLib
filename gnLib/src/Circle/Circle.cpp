#include <Circle/Circle.h>
#include <GameCore/GameCore.h>
#include <GraphicsRender/GraphicsRender.h>

namespace gnLib {

	Circle::Circle()
		: radius(10)
		, color(255, 255, 255)
	{
	}

	Circle::Circle(float _x, float _y, float _r)
		: position(_x, _y)
		, radius(_r)
		, color(255, 255, 255)
	{
	}

	Circle::Circle(const Vector2& _pos, float _r)
		: position(_pos)
		, radius(_r)
		, color(255, 255, 255)
	{
	}

	Circle& Circle::setPos(float _x, float _y)
	{
		position.setPos(_x, _y);

		return *this;
	}

	Circle& Circle::setPos(const Vector2& _vector)
	{
		position.setPos(_vector);

		return *this;
	}

	Circle& Circle::setRadius(float _radius)
	{
		radius = _radius;

		return *this;
	}

	Circle& Circle::setColor(const Color& _color)
	{
		color.setColor(_color);

		return *this;
	}

	Circle& Circle::setColor(int _r, int _g, int _b)
	{
		color.setColor(_r, _g, _b);

		return *this;
	}

	void Circle::draw()
	{
		GCGraphicsRender->drawCircle2D(
			position.x,
			position.y,
			radius,
			color
		);
	}

}
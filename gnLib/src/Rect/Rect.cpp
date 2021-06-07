#include "../../include/Rect/Rect.h"
#include "../../include/GameCore/GameCore.h"
#include "../../gnLibCore/include/GraphicsRender.h"

namespace gnLib {

	Rect::Rect()
		: position()
		, width(1)
		, height(1)
		, radian(0.0f)
		, color(Color::White)
	{ 
	}

	Rect::Rect(float _x, float _y, float _width, float _height)
		: position({ _x, _y })
		, width(_width)
		, height(_height)
		, radian(0.0f)
		, color(Color::White)
	{ 
	}

	Rect::Rect(const Vector2& _v, float _width, float _height)
		: position(_v)
		, width(_width)
		, height(_height)
		, radian(0.0f)
		, color(Color::White)
	{
	}

	void Rect::setPos(float _x, float _y)
	{
		position.setPos(_x, _y);
	}

	void Rect::setPos(const Vector2 & _v)
	{
		position.setPos(_v);
	}

	void Rect::setSize(float _width, float _height)
	{
		width = _width;
		height = _height;
	}

	void Rect::setSize(float _wh)
	{
		setSize(_wh, _wh);
	}

	void Rect::setRotate(float _rot)
	{
		radian = D3DXToRadian(_rot);
	}

	void Rect::setColor(const Color & _color)
	{
		color = _color;
	}

	void Rect::draw()
	{
		GCGraphicsRender->drawRect2D(
			position.x, 
			position.y,
			width,
			height,
			radian,
			color
		);
	
	}
}
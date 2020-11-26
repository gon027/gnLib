#include "../../include/Rect/Rect.h"
#include "../../include/Graphics/Graphics.h"
#include "../../include/Vertex/Vertex2D.h"
#include "../../include/Common/Macro.h"
#include "../../include/Render/Render.h"
#include "../../include/GameCore/GameCore.h"
#include "../../include/Common/Math.h"

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
		auto leftTop     = Vector2{ position.x, position.y };
		auto leftBottom  = Vector2{ position.x, position.y + height };
		auto rightTop    = Vector2{ position.x + width, position.y };
		auto rightBottom = Vector2{ position.x + width, position.y + height };

		Vertex2D vertex[] = {
			{leftBottom.x,  leftBottom.y,  0.0f, 1.0f, color.getColor(), 0.0f, 0.0f},
			{leftTop.x,     leftTop.y,     0.0f, 1.0f, color.getColor(), 0.0f, 0.0f},
			{rightBottom.x, rightBottom.y, 0.0f, 1.0f, color.getColor(), 0.0f, 0.0f},
			{rightTop.x,    rightTop.y,    0.0f, 1.0f, color.getColor(), 0.0f, 0.0f},
		};

		GCGraphics->SetFVF(FVF_CUSTOM2D);
		GCGraphics->DrawPrimitiveUP(D3DPT_TRIANGLESTRIP, 2, vertex, sizeof(Vertex2D));
	}
}
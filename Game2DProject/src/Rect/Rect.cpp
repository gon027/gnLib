#include "../../include/Rect/Rect.h"

#pragma comment(lib, "d3dx9.lib")
#include <d3dx9.h>

#include "../../include/Graphics/Graphics.h"
#include "../../include/Vertex/Vertex2D.h"
#include "../../include/Common/Macro.h"
#include "../../include/Render/Render.h"
#include "../../include/GameCore/GameCore.h"
#include "../../include/Common/Math.h"
#include "../../include/Debug/Debug.h"

namespace gnLib {

	Rect::Rect()
		: position()
		, bounds()
		, width(1)
		, height(1)
		, color(Color::White)
	{ 
	}

	Rect::Rect(float _x, float _y, float _width, float _height)
		: position({ _x, _y })
		, bounds() 
		, width(_width)
		, height(_height)
		, color(Color::White)
	{ 
	}

	Rect::Rect(const Vector2& _v, float _width, float _height)
		: position(_v)
		, bounds()
		, width(_width)
		, height(_height)
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

		auto w = width / 2.0f;
		auto h = height / 2.0f;

		bounds.leftTop.setPos(_v.x - w, _v.y - h);
		bounds.leftBottom.setPos(_v.x - w, _v.y + h);
		bounds.rightTop.setPos(_v.x + w, _v.y - h);
		bounds.rightBottom.setPos(_v.x + w, _v.y + h);
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
		auto rad = D3DXToRadian(_rot);

		bounds.leftTop     = rotation(bounds.leftTop,     position, rad);
		bounds.leftBottom  = rotation(bounds.leftBottom,  position, rad);
		bounds.rightTop    = rotation(bounds.rightTop,    position, rad);
		bounds.rightBottom = rotation(bounds.rightBottom, position, rad);
	}

	void Rect::setColor(const Color & _color)
	{
		color = _color;
	}

	void Rect::draw()
	{

		Vertex2D vertex[] = {
			{bounds.leftBottom.x,  bounds.leftBottom.y, 0.0f, 1.0f, color.getColor(), 0.0f, 0.0f},
			{bounds.leftTop.x,     bounds.leftTop.y, 0.0f, 1.0f, color.getColor(), 0.0f, 0.0f},
			{bounds.rightBottom.x, bounds.rightBottom.y, 0.0f, 1.0f, color.getColor(), 0.0f, 0.0f},
			{bounds.rightTop.x,    bounds.rightTop.y, 0.0f, 1.0f, color.getColor(), 0.0f, 0.0f},
		};

		collider.update(position, bounds);

		GCGraphics->SetFVF(FVF_CUSTOM2D);
		GCGraphics->DrawPrimitiveUP(D3DPT_TRIANGLESTRIP, 2, vertex, sizeof(Vertex2D));
	}

	Vector2 Rect::getPos()
	{
		return position;
	}

}
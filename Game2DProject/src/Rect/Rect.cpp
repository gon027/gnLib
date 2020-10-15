#include "../../include/Rect/Rect.h"

#pragma comment(lib, "d3dx9.lib")
#include <d3dx9.h>

#include "../../include/Graphics/Graphics.h"
#include "../../include/Vertex/Vertex2D.h"
#include "../../include/Common/Macro.h"
#include "../../include/Render/Render.h"
#include "../../include/GameCore/GameCore.h"

namespace gnLib {

	Rect::Rect()
		: minPos()
		, width(1)
		, height(1)
		, color(Color::White)
	{ 
	}

	Rect::Rect(float _x, float _y, float _width, float _height)
		: minPos({_x, _y, 0.0f})
		, width(_width)
		, height(_height)
		, color(Color::White)
	{ 
	}

	Rect::Rect(const Vector2& _v, float _width, float _height)
		: minPos(_v.x, _v.y, 0.0f)
		, width(_width)
		, height(_height)
		, maxPos(Vector3{ minPos.x + width, minPos.y + height })
		, position((maxPos - minPos).half())
		, color(Color::White)
	{
	}

	Rect::Rect(const Vector3 & _v, float _width, float _height)
		: minPos(_v)
		, width(_width)
		, height(_height)
		, maxPos(Vector3{ minPos.x + width, minPos.y + height })
		, position((maxPos - minPos).half())
		, color(Color::White)
	{ 
	}

	Rect::~Rect()
	{
	}

	void Rect::setPos(float _x, float _y, float _z)
	{
		minPos.setPos(_x, _y, _z);
		maxPos.setPos(minPos.x + width, minPos.y + height, 0.0f);
		position.setPos(minPos + (maxPos - minPos).half());
	}

	void Rect::setPos(const Vector2 & _v)
	{
		setPos(_v.x, _v.y, 0.0f);
	}

	void Rect::setPos(const Vector3 & _v)
	{
		setPos(_v.x, _v.y, _v.z);
	}

	void Rect::setSize(float _width, float _height)
	{
		width = _width;
		height = _height;
		maxPos.setPos(minPos.x + width, minPos.x + height, 0.0f);
	}

	void Rect::setSize(float _wh)
	{
		setSize(_wh, _wh);
	}

	void Rect::setColor(const Color & _color)
	{
		color = _color;
	}

	void Rect::draw()
	{
		float x = minPos.x;
		float y = minPos.y;
		float z = minPos.z;
		float sx = x + width;
		float sy = y + height;

		Vertex2D vertex[] = {
			{ x, sy, z, 1.0f, color.getColor(), 0.0f, 0.0f},
			{ x,  y, z, 1.0f, color.getColor(), 0.0f, 0.0f},
			{sx, sy, z, 1.0f, color.getColor(), 0.0f, 0.0f},
			{sx,  y, z, 1.0f, color.getColor(), 0.0f, 0.0f},
		};

		collider.update(position.toVector2(), minPos.toVector2(), Vector2{ sx, sy });

		GCGraphics->SetFVF(FVF_CUSTOM2D);
		GCGraphics->DrawPrimitiveUP(D3DPT_TRIANGLESTRIP, 2, vertex, sizeof(Vertex2D));
	}

	Vector3 Rect::getPos()
	{
		return position;
	}

	Vector3 Rect::getMinPos()
	{
		return minPos;
	}

	Vector3 Rect::getMaxPos()
	{
		return maxPos;
	}

}
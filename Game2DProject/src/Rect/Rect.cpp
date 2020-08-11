#include "../../include/Rect/Rect.h"
#include "../../include/Graphics/Graphics.h"
#include "../../include/Vertex/Vertex2D.h"
#include "../../include/Common/Macro.h"
#include "../../include/Render/Render.h"
#include "../../include/GameCore/GameCore.h"

namespace gnLib {

	RectAngle::RectAngle()
		: position()
		, width(1)
		, height(1)
		, color(Color::White)
	{ }

	RectAngle::RectAngle(float _x, float _y, float _width, float _height)
		: position({_x, _y, 0.0f})
		, width(_width)
		, height(_height)
		, color(Color::White)
	{ }

	RectAngle::RectAngle(const Vector2 & _v, float _width, float _height)
		: position(_v.x, _v.y, 0.0f)
		, width(_width)
		, height(_height)
		, color(Color::White)
	{ }

	RectAngle::RectAngle(const Vector3 & _v, float _width, float _height)
		: position(_v)
		, width(_width)
		, height(_height)
		, color(Color::White)
	{ }

	RectAngle::~RectAngle()
	{ }

	void RectAngle::setPos(float _x, float _y, float _z)
	{
		position.x = _x;
		position.y = _y;
		position.z = _z;
	}

	void RectAngle::setPos(const Vector2 & _v)
	{
		setPos(_v.x, _v.y, 0.0f);
	}

	void RectAngle::setPos(const Vector3 & _v)
	{
		position = _v;
	}

	void RectAngle::setSize(float _width, float _height)
	{
		width = _width;
		height = _height;
	}

	void RectAngle::setSize(float _wh)
	{
		setSize(_wh, _wh);
	}

	void RectAngle::setColor(const Color & _color)
	{
		color = _color;
	}

	void RectAngle::draw()
	{
		float x = position.x;
		float y = position.y;
		float z = position.z;
		float sx = x + width;
		float sy = y + height;

		Vertex2D vertex[] = {
			{ x, sy, z, 1.0f, color.getColor(), 0.0f, 0.0f},
			{ x,  y, z, 1.0f, color.getColor(), 0.0f, 0.0f},
			{sx, sy, z, 1.0f, color.getColor(), 0.0f, 0.0f},
			{sx,  y, z, 1.0f, color.getColor(), 0.0f, 0.0f},
		};

		GCoreIns->getGraphic()->getDevice()->SetFVF(FVF_CUSTOM2D);
		GCoreIns->getGraphic()->getDevice()->DrawPrimitiveUP(D3DPT_TRIANGLESTRIP, 2, vertex, sizeof(Vertex2D));
	}

}
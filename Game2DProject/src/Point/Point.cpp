#include "../../include/Point/Point.h"
#include "../../include/GameCore/GameCore.h"
#include "../../include/Common/Macro.h"
#include "../../include/Graphics/Graphics.h"
#include "../../include/Color/Color.h"
#include "../../include/Vertex/Vertex2D.h"

namespace gnLib {

	Point::Point()
		: position(Vector2::Zero)
		, color(Color::Black)
		, collider()
	{

	}

	Point::Point(const Vector2& _pos)
		: position(_pos)
		, color(Color::Black)
		, collider(_pos)
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
		Vertex2D vertex[1] = { 
			position.x, position.y, 0.0f, 1.0f, 0xFFFF0000, 0.0f, 0.0f
		};

		collider.update(position);

		GCGraphics->SetFVF(FVF_CUSTOM2D);
		GCGraphics->DrawPrimitiveUP(
			D3DPT_POINTLIST,
			1,
			vertex,
			sizeof(Vertex2D)
		);
	}

	Vector2 Point::getPos() const
	{
		return position;
	}


}
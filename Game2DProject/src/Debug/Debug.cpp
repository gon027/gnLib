#include "../../include/Debug/Debug.h"

namespace gnLib {
	Line Debug::line{};
	Circle Debug::circle{};
	StringRender Debug::strRender{};
	RectAngle Debug::rectAngle{};
	
	void Debug::drawRect(const Vector2& _pos, const Color& _color)
	{
		rectAngle.setPos(_pos);
		rectAngle.setColor(_color);
		rectAngle.setSize(50.0f);
		rectAngle.draw();
	}

	void Debug::drawCircle(const Vector2& _pos, float radius, const Color& _color)
	{
		circle.setPos(_pos);
		circle.setRadius(radius);
		circle.setColor(_color);
		circle.draw();
	}

	void Debug::drawLine(const Vector2& _start, const Vector2 _end, float _weight, const Color& _color)
	{
		line.setPos(_start, _end);
		line.setWeight(_weight);
		line.setColor(_color);
		line.draw();
	}

	void Debug::drawText(int _x, int _y, const char* _str, const Color& _color)
	{
		strRender.drawText(_x, _y, _str, _color);
	}

}

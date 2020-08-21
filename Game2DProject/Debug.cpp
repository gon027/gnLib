#include "Debug.h"

namespace gnLib {
	//Line Debug::line{};
	Circle Debug::circle{};
	
	void Debug::drawRect(const Vector2& _pos, const Color& _color)
	{
	}

	void Debug::drawCircle(const Vector2& _pos, float radius, const Color& _color)
	{
		circle.setPos(_pos);
		circle.setRadius(radius);
		circle.setColor(_color);
		circle.draw();
	}

	/*void Debug::drawLine(const Vector2& _start, const Vector2 _end, float _weight, const Color& _color)
	{
		line.setPos(_start, _end);
		line.setWeight(_weight);
		line.setColor(_color);
		line.draw();
	}*/
}

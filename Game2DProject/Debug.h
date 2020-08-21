#ifndef DEBUG_H
#define DEBUG_H

#include "include/Color/Color.h"
#include "include/Line/Line.h"
#include "include/Circle/Circle.h"
#include "include/Rect/Rect.h"

namespace gnLib {
	class Vector2;
	class Vector3;

	class Color;

	class RectAngle;

	// デバッククラス
	class Debug {
	public:
		static void drawRect(const Vector2& _pos, const Color& _color);

		static void drawCircle(const Vector2& _pos, float radius, const Color& _color = Color::Black);

		//static void drawLine(const Vector2& _start, const Vector2 _end, float _weight = 1.0f, const Color& _color = Color::Black);

	private:
		static RectAngle rectAngle;
		//static Line line;
		static Circle circle;
	};
}

#endif // !DEBUG_H

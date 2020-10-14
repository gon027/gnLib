#ifndef DEBUG_H
#define DEBUG_H

#include <string>
#include "../Color/Color.h"
#include "../Line/Line.h"
#include "../Circle/Circle.h"
#include "../Rect/Rect.h"
#include "../StringRender/StringRender.h"

namespace gnLib {
	class Vector2;

	/// <summary>
	/// デバッククラス
	/// </summary>
	class Debug {
	public:
		static void drawRect(const Vector2& _pos, const Color& _color = Color::Black);

		static void drawCircle(const Vector2& _pos, float radius, const Color& _color = Color::Black);

		static void drawLine(const Vector2& _start, const Vector2 _end, float _weight = 1.0f, const Color& _color = Color::Black);

		static void drawText(int _x, int _y, const char* _str, const Color& _color = Color::Black);

		template<typename ...Args>
		static void drawFormatText(int _x, int _y, const Color& _color, const char* _format, Args ... args);

	private:
		static RectAngle rectAngle;
		static Line line;
		static Circle circle;
		static StringRender strRender;
	};

	template<typename ...Args>
	inline void Debug::drawFormatText(int _x, int _y, const Color& _color, const char* _format, Args ... args)
	{
		strRender.drawFormatText(_x, _y, _color, _format, args ...);
	}
}

#endif // !DEBUG_H

#ifndef STRINGRENDER_H
#define STRINGRENDER_H

#include <string>
#include "../Color/Color.h"

namespace gnLib {

	// ���������ʏ�ɕ`�悷��N���X
	class StringRender {
		using string = std::string;

	public:
		StringRender() = default;
		~StringRender() = default;
		
		void drawText(int _x, int _y, const string& _str, Color _color = Color::Black);

		void drawFormatText(int _x, int _y, Color _color, const char* format, ...);

	};
};

#endif // !STRINGRENDER_H

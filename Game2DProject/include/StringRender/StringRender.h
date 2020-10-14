#ifndef STRINGRENDER_H
#define STRINGRENDER_H

#pragma comment(lib, "d3dx9.lib")
#include <d3dx9.h>

#include <string>
#include "../Color/Color.h"

namespace gnLib {

	// ï∂éöóÒÇâÊñ è„Ç…ï`âÊÇ∑ÇÈÉNÉâÉX
	class StringRender {
		using string = std::string;

	public:
		StringRender() = default;
		~StringRender() = default;

		void drawText(const string& _str, int _x, int _y, Color _color = Color::Black);

		void drawText(int _x, int _y, const char* _str, Color _color = Color::Black);

		void drawText(int _x, int _y, const string& _str, Color _color = Color::Black);

		void drawFormatText(int _x, int _y, Color _color, const char* format, ...);
	};
};

#endif // !STRINGRENDER_H

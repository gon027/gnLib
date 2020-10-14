#ifndef STRINGRENDER_H
#define STRINGRENDER_H

#pragma comment(lib, "d3dx9.lib")
#include <d3dx9.h>

#include <string>
#include "../Color/Color.h"

namespace gnLib {

	// •¶š—ñ‚ğ‰æ–Êã‚É•`‰æ‚·‚éƒNƒ‰ƒX
	class StringRender {
		using string = std::string;

	public:
		StringRender()  = default;
		~StringRender() = default;

		void drawText(const string& _str, int _x, int _y, Color _color = Color::Black);
	};

}

#endif // !STRINGRENDER_H

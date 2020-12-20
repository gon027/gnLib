#ifndef FONT_H
#define FONT_H

#include <string>
#include "../Common/Lib.h"
#include "../Vector/Vector2.h"
#include "../Color/Color.h"

namespace gnLib {

	class Font {
		using string = std::string;

	public:
		struct FontInfo {
			int width;
			int height;
			string fontName;
		};

	public:
		Font(int _size, string _fontName = "ÇlÇr ÉSÉVÉbÉN");
		~Font();

		void drawText(Vector2 _pos, const string& _str, Color _color = Color::Black);

		void drawText(int _x, int _y, const string& _str, Color _color = Color::Black);

		void drawText(int _x, int _y, Color _color, const char* format, ...);

	private:
		LPD3DXFONT lpFont;
		FontInfo fontInfo;
	};
}

#endif // !FONT_H
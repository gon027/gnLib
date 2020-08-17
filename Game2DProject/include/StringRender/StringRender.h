#ifndef STRINGRENDER_H
#define STRINGRENDER_H

#pragma comment(lib, "d3dx9.lib")
#include <d3dx9.h>

#include <string>
#include "../Color/Color.h"

namespace gnLib {
	class Graphics;

	// ���������ʏ�ɕ`�悷��N���X
	class StringRender {
		using string = std::string;

	public:
		StringRender();
		~StringRender();

		//void setFont(string _fontName);
		//void setFontSize(int _fontSize);
		bool create();
		void drawText(string _str, int _x, int _y, Color _color);

	private:
		LPD3DXFONT font;

		int width = 10;
		int height = 20;
		int fontSize;
	};
}

#endif // !STRINGRENDER_H

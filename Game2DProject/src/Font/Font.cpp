#include "../../include/Font/Font.h"
#include "../../include/Common/Macro.h"
#include "../../include/GameCore/GameCore.h"
#include "../../include/Graphics/Graphics.h"
#include "../../include/SpriteRender/SpriteRender.h"

#include <stdio.h>
#include <stdarg.h>

namespace gnLib {

	namespace helper {
		LPD3DXFONT createFont(const Font::FontInfo& _fontInfo) {
			LPD3DXFONT result = nullptr;

			D3DXCreateFontA(
				GCGraphics,
				_fontInfo.height,
				0,
				0,
				0,
				0,
				0,
				0,
				0,
				0,
				_fontInfo.fontName.c_str(),
				&result
			);

			return result;
		}
	}

	Font::Font(int _size, string _fontName)
		: lpFont(nullptr)
		, fontInfo{ _size, _size, _fontName }
	{
		lpFont = helper::createFont(fontInfo);
	}

	Font::~Font()
	{
		RELEASE(lpFont);
	}

	void Font::drawText(Vector2 _pos, const string& _str, Color _color)
	{
		drawText(static_cast<int>(_pos.x), static_cast<int>(_pos.y), _str, _color);
	}

	void Font::drawText(int _x, int _y, const string& _str, Color _color)
	{
		if (lpFont) {
			// スプライトの行列を取得
			D3DXMATRIX mat;
			GCoreIns->getSprite()->getSprite()->GetTransform(&mat);

			auto size = _str.size();

			RECT rc{
				static_cast<LONG>(_x - mat._41),
				static_cast<LONG>(_y - mat._42),
				static_cast<LONG>(_x + (fontInfo.width * size) - mat._41),
				static_cast<LONG>(_y + fontInfo.height - mat._42)
			};

			lpFont->DrawTextA(
				GCoreIns->getSprite()->getSprite(),
				_str.c_str(),
				-1,
				&rc,
				DT_NOCLIP | DT_CENTER,
				_color.getColor()
			);
		}
	}

	void Font::drawText(int _x, int _y, Color _color, const char* format, ...)
	{
		va_list args;
		int len;

#if _UNICODE
		char* buffer;
		buffer = (char*)malloc(len * sizeof(char));
#else
		//wchar_t* buffer;
		//buffer = (wchar_t*)malloc(len * sizeof(wchar_t));
#endif

		va_start(args, format);
		len = _vscprintf(format, args) + 1;

		char* buffer;
		buffer = (char*)malloc(len * sizeof(char));

		if (buffer != nullptr) {
			vsprintf_s(buffer, len, format, args);
			drawText(_x, _y, buffer, _color);
			free(buffer);
		}
		va_end(args);
	}
}
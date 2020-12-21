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
			{
				// 文字列描画用の単位行列を作成
				D3DXMATRIX mat;
				D3DXMatrixIdentity(&mat);

				// D3DXSPRITEで文字列を描画する前のSpriteで使った行列計算反映されるため
				// 単位行列をセットして元に戻す
				GCoreIns->getSprite()->getSprite()->SetTransform(&mat);
			}

			auto size = _str.size();
			RECT rc{
				static_cast<LONG>(_x),
				static_cast<LONG>(_y),
				static_cast<LONG>(_x + (fontInfo.width * size)),
				static_cast<LONG>(_y + fontInfo.height)
			};

			lpFont->DrawTextA(
				GCoreIns->getSprite()->getSprite(),
				_str.c_str(),
				-1,
				&rc,
				DT_NOCLIP,
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
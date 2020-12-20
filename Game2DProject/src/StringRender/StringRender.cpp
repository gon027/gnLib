#include "../../include/StringRender/StringRender.h"
#include "../../include/Render/Render.h"
#include "../../include/Graphics/Graphics.h"
#include "../../include/GameCore/GameCore.h"
#include "../../include/Window/Window.h"
#include "../../include/SpriteRender/SpriteRender.h"

#include <stdio.h>
#include <stdarg.h>

namespace gnLib {

	void StringRender::drawText(int _x, int _y, const string& _str, Color _color)
	{
		// スプライトの行列を取得
		D3DXMATRIX mat;
		GCoreIns->getSprite()->getSprite()->GetTransform(&mat);

		auto size = _str.size();

		RECT rc{
			static_cast<LONG>(_x - mat._41),
			static_cast<LONG>(_y - mat._42),
			static_cast<LONG>(_x + (10 * size) - mat._41),
			static_cast<LONG>(_y + 20 - mat._42)
		};

		GCStrDevice->DrawTextA(
			GCoreIns->getSprite()->getSprite(),
			_str.c_str(),
			-1,
			&rc,
			NULL,
			_color.getColor()
		);
	}

	void StringRender::drawFormatText(int _x, int _y, Color _color, const char* format, ...)
	{
		va_list args;
		int len;
		//char* buffer;

		va_start(args, format);
		len = _vscprintf(format, args) + 1;

#if _UNICODE
		char* buffer;
		buffer = (char*)malloc(len * sizeof(char));
#else
		//wchar_t* buffer;
		//buffer = (wchar_t*)malloc(len * sizeof(wchar_t));

		
#endif

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
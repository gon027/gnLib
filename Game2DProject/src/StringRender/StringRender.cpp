#include "../../include/StringRender/StringRender.h"
#include "../../include/Render/Render.h"
#include "../../include/Graphics/Graphics.h"
#include "../../include/GameCore/GameCore.h"
#include "../../include/Window/Window.h"

#include <stdio.h>
#include <stdarg.h>

namespace gnLib {

	void StringRender::drawText(const string& _str, int _x, int _y, Color _color)
	{
		// left, top, right, bottom
		RECT rc{ 
			_x, _y, WindowInfo::Width, WindowInfo::Height
		};

		GCStrDevice->DrawText(
			NULL,
			_str.c_str(),
			-1,
			&rc,
			NULL,
			_color.getColor()
		);
	}

	void StringRender::drawText(int _x, int _y, const char* _str, Color _color)
	{
		// left, top, right, bottom
		RECT rc{
			_x, _y, WindowInfo::Width, WindowInfo::Height
		};

		GCStrDevice->DrawText(
			NULL,
			_str,
			-1,
			&rc,
			NULL,
			_color.getColor()
		);
	}

	void StringRender::drawText(int _x, int _y, const string& _str, Color _color)
	{
		drawText(_x, _y, _str.c_str(), _color);
	}

	void StringRender::drawFormatText(int _x, int _y, Color _color, const char* format, ...)
	{
		va_list args;
		int len;
		char* buffer;

		va_start(args, format);
		len = _vscprintf(format, args) + 1;

		buffer = (char*)malloc(len * sizeof(char));
		if (buffer != nullptr) {
			vsprintf_s(buffer, len, format, args);
			drawText(_x, _y, buffer, _color);
			free(buffer);
		}
		va_end(args);
	}

}
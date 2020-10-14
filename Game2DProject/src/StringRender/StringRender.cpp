#include "../../include/StringRender/StringRender.h"
#include "../../include/Render/Render.h"
#include "../../include/Graphics/Graphics.h"
#include "../../include/GameCore/GameCore.h"
#include "../../include/Window/Window.h"

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
}
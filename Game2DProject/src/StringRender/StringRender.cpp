#include "../../include/StringRender/StringRender.h"
#include "../../include/Render/Render.h"
#include "../../include/Graphics/Graphics.h"
#include "../../include/Common/Macro.h"
#include "../../include/GameCore/GameCore.h"

namespace gnLib {
	StringRender::StringRender()
	{
	}

	StringRender::~StringRender()
	{
		RELEASE(font);
	}

	bool StringRender::create()
	{
		HRESULT ret;

		ret = D3DXCreateFont(
			GCGraphics,
			height,
			width,
			0,
			0,
			0,
			0,
			0,
			0,
			0,
			"‚l‚r ƒSƒVƒbƒN",
			&font
		);

		if (FAILED(ret)) {
			return false;
		}

		return true;
	}

	void StringRender::drawText(string _str, int _x, int _y, Color _color)
	{
		// left, top, right, bottom
		RECT rc{ _x, _y, 480, 600 };

		font->DrawText(
			NULL,
			_str.c_str(),
			-1,
			&rc,
			NULL,
			_color.getColor()
		);
	}
}
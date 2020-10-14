#include "../../include/Render/Render.h"
#include "../../include/Common/Macro.h"
#include "../../include/Window/Window.h"
#include "../../include/Graphics/Graphics.h"
#include "../../include/GameCore/GameCore.h"

namespace gnLib {

	RenderDevice::~RenderDevice()
	{
		RELEASE(d3dxLine);
		RELEASE(lpd3dxFont);
	}

	void RenderDevice::init(Graphics* _graphics)
	{
		D3DXCreateLine(_graphics->getDevice(), &d3dxLine);

		D3DXCreateFont(
			_graphics->getDevice(),
			20,
			10,
			0,
			0,
			0,
			0,
			0,
			0,
			0,
			"ÇlÇr ÉSÉVÉbÉN",
			&lpd3dxFont
		);
	}

	ID3DXLine* RenderDevice::getLineDevice() const
	{
		return d3dxLine;
	}

	LPD3DXFONT RenderDevice::getFontDevice() const
	{
		return lpd3dxFont;
	}
	
}

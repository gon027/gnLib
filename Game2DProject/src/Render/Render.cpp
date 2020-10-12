#include "../../include/Render/Render.h"
#include "../../include/Common/Macro.h"
#include "../../include/Graphics/Graphics.h"

namespace gnLib {

	RenderDevice::~RenderDevice()
	{
		RELEASE(d3dxLine);
		//RELEASE(lpd3dxFont);
	}

	void RenderDevice::init(Graphics* _graphics)
	{
		D3DXCreateLine(_graphics->getDevice(), &d3dxLine);;
	}

	ID3DXLine* RenderDevice::getLineDevice() const
	{
		return d3dxLine;
	}

	/*
	LPD3DXFONT RenderDevice::getFontDevice() const
	{
		return lpd3dxFont;
	}
	*/
}

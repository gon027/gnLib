#include "../../include/Render/Render.h"
#include "../../include/Common/Macro.h"
#include "../../include/Graphics/Graphics.h"

namespace gnLib {

	RenderDevice_::~RenderDevice_()
	{
		RELEASE(d3dxLine);
		//RELEASE(lpd3dxFont);
	}

	void RenderDevice_::init(Graphics* _graphics)
	{
		D3DXCreateLine(_graphics->getDevice(), &d3dxLine);;
	}

	ID3DXLine* RenderDevice_::getLineDevice() const
	{
		return d3dxLine;
	}

	/*
	LPD3DXFONT RenderDevice_::getFontDevice() const
	{
		return lpd3dxFont;
	}
	*/
}

#include "../../include/Render/Render.h"
#include "../../include/Common/Macro.h"
#include "../../include/Graphics/Graphics.h"

namespace gnLib {

	Render* Render::Instance = new Render;

	Render::Render()
	{
	}

	Render::~Render()
	{
		RELEASE(d3dxLine);
	}

	void Render::init(Graphics * _graphics)
	{
		graphics = _graphics;
		
		D3DXCreateLine(graphics->getDevice(), &d3dxLine);
	}

	Graphics * Render::getGraphics() const
	{
		return graphics;
	}

	ID3DXLine* Render::getLineDevice() const
	{
		return d3dxLine;
	}
}

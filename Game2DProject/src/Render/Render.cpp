#include "../../include/Render/Render.h"

Render* Render::Instance = new Render;

Render::Render()
{
}

void Render::setGraphics(Graphics * _graphics)
{
	graphics = _graphics;
}

Graphics * Render::getGraphics() const
{
	return graphics;
}

#include "../../include/Circle/Circle.h"
#include "../../include/Common/Macro.h"
#include "../../include/Graphics/Graphics.h"
#include "../../include/Render/Render.h"
#include "../../include/Color/Color.h"
#include "../../include/Vertex/Vertex2D.h"
#include "../../include/Common/Math.h"

#include <vector>
#include <cmath>

constexpr float split = 10.0f;

Circle::Circle()
{
	this->setActive(true);
}

void Circle::draw(float _x, float _y, float _radius)
{
	x = _x;
	y = _y;
	radius = _radius;

	std::vector<Vertex2D> circle(10);

	for (float r = 0; r < math::tau; r += math::tau / split) {
		float nx = radius * cosf(r);
		float ny = radius * sinf(r);


		// TODO: ‰~‚É‚È‚é‚æ‚¤‚Éƒ|ƒŠƒSƒ“‚ðì¬‚·‚é
		//circle.emplace_back(Vertex2D{nx, ny, 0.0f, 1.0f, 0xFFFF00FF, 0.0f, 0.0f});
		circle.emplace_back(Vertex2D{x, y, 0.0f, 1.0f, 0xFFFF00FF, 0.0f, 0.0f});
		if (r == 0.0f) {

		}
	}

	RenderDevice->SetFVF(FVF_CUSTOM2D);
	RenderDevice->DrawPrimitiveUP(
		D3DPT_TRIANGLESTRIP,
		10,
		circle.data(),
		sizeof(Vertex2D)
	);
}

#include "../../include/Circle/Circle.h"
#include "../../include/Common/Macro.h"
#include "../../include/Graphics/Graphics.h"
#include "../../include/Render/Render.h"
#include "../../include/Color/Color.h"
#include "../../include/Vertex/Vertex2D.h"
#include "../../include/Common/Math.h"
#include "../../include/Color/Color.h"
#include "../../GameCore.h"
#include <vector>
#include <cmath>

constexpr int NUM = 50 + 2;
constexpr float SPLIT = NUM - 2;
constexpr float theta = gnLib::tau / SPLIT;

namespace gnLib {
	Circle::Circle()
	{
		this->setActive(true);
	}

	void Circle::draw(float _x, float _y, float _radius)
	{
		x = _x;
		y = _y;
		radius = _radius;

		Color c(0, 255, 0);

		std::vector<Vertex2D> circle(NUM);
		circle[0] = Vertex2D{ _x, _y, 0.0f, 1.0f, c.getColor(), 0.0f, 0.0f };
		for (int r = 1; r < NUM; ++r) {
			float nx = _x + radius * cosf(theta * (r - 1));
			float ny = _y + radius * sinf(theta * (r - 1));

			circle[r] = Vertex2D{ nx, ny, 0.0f, 1.0f, c.getColor(), 0.0f, 0.0f };
		}
		circle[NUM - 1] = circle[1];

		GCoreIns->getGraphic()->getDevice()->SetFVF(FVF_CUSTOM2D);
		GCoreIns->getGraphic()->getDevice()->DrawPrimitiveUP(
			D3DPT_TRIANGLEFAN,
			NUM - 1,
			circle.data(),
			sizeof(Vertex2D)
		);
	}

}
#include "../../include/Circle/Circle.h"
#include "../../include/Common/Macro.h"
#include "../../include/Graphics/Graphics.h"
#include "../../include/Render/Render.h"
#include "../../include/Color/Color.h"
#include "../../include/Vertex/Vertex2D.h"
#include "../../include/Common/Math.h"
#include "../../include//GameCore/GameCore.h"
#include <vector>
#include <cmath>

constexpr int NUM = 50 + 2;
constexpr float SPLIT = NUM - 2;
constexpr float theta = gnLib::tau / SPLIT;

namespace gnLib {
	Circle::Circle()
		: radius(10)
		, color(255, 255, 255)
	{
		this->setActive(true);
	}

	Circle::Circle(float _x, float _y, float _r)
		: position(_x, _y)
		, radius(_r)
		, color(255, 255, 255)
	{
		this->setActive(true);
	}

	Circle::Circle(Vector2 _pos, float _r)
		: position(_pos)
		, radius(_r)
		, color(255, 255, 255)
	{
		this->setActive(true);
	}

	void Circle::setPosition(float _x, float _y)
	{
		position.setPosition(_x, _y);
	}

	void Circle::setPosition(const Vector2& _vector)
	{
		position.setPosition(_vector);
	}

	void Circle::setRadius(float _radius)
	{
		radius = _radius;
	}

	void Circle::setColor(const Color& _color)
	{
		color.setColor(_color);
	}

	void Circle::setColor(int _r, int _g, int _b)
	{
		color.setColor(_r, _g, _b);
	}

	void Circle::draw()
	{
		float x = position.x;
		float y = position.y;

		std::vector<Vertex2D> circle(NUM);
		circle[0] = Vertex2D{ x, y, 0.0f, 1.0f, color.getColor(), 0.0f, 0.0f };
		for (int r = 1; r < NUM; ++r) {
			float nx = x + radius * cosf(theta * (r - 1));
			float ny = y + radius * sinf(theta * (r - 1));

			circle[r] = Vertex2D{ nx, ny, 0.0f, 1.0f, color.getColor(), 0.0f, 0.0f };
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

	void Circle::draw(float _x, float _y, float _radius)
	{
		setPosition(_x, _y);
		setRadius(_radius);

		draw();

		/*
		std::vector<Vertex2D> circle(NUM);
		circle[0] = Vertex2D{ _x, _y, 0.0f, 1.0f, color.getColor(), 0.0f, 0.0f };
		for (int r = 1; r < NUM; ++r) {
			float nx = _x + radius * cosf(theta * (r - 1));
			float ny = _y + radius * sinf(theta * (r - 1));

			circle[r] = Vertex2D{ nx, ny, 0.0f, 1.0f, color.getColor(), 0.0f, 0.0f };
		}
		circle[NUM - 1] = circle[1];

		GCoreIns->getGraphic()->getDevice()->SetFVF(FVF_CUSTOM2D);
		GCoreIns->getGraphic()->getDevice()->DrawPrimitiveUP(
			D3DPT_TRIANGLEFAN,
			NUM - 1,
			circle.data(),
			sizeof(Vertex2D)
		);
		*/
	}

}
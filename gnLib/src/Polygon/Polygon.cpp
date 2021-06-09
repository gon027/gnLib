#include <Polygon/Polygon.h>
#include <GameCore/GameCore.h>
#include <Graphics/Graphics.h>
#include <Vertex/Vertex2D.h>
#include <Common/Macro.h>
#include <Render/Render.h>
#include <Common/Math.h>

namespace gnLib {

	Polygon::Polygon(std::initializer_list<Vertex2D> _vertex)
		: vertex(_vertex.begin(), _vertex.end())
		, position(Vector2::Zero)
		, color(Color::White)
	{
		for (int i{ 0 }; i < vertex.size(); ++i) {
			vertex[i].rhw = 1.0f;
			vertex[i].color = color.getColor();
		}
	}

	Polygon::Polygon(const std::vector<Vertex2D>& _vertex)
		: vertex(_vertex)
		, position(Vector2::Zero)
		, color(Color::White)
	{
		for (int i{ 0 }; i < vertex.size(); ++i) {
			vertex[i].rhw = 1.0f;
			vertex[i].color = color.getColor();
		}
	}

	void Polygon::setColor(Color _color)
	{
		color = _color;
		for (int i{ 0 }; i < vertex.size(); ++i) {
			vertex[i].color = color.getColor();
		}
	}

	void Polygon::translate(const Vector2& _delta)
	{
		for (int i{ 0 }; i < vertex.size(); ++i) {
			vertex[i].x += _delta.x;
			vertex[i].y += _delta.y;
		}
	}

	void Polygon::scale(const Vector2& _scale)
	{
		for (int i{ 0 }; i < vertex.size(); ++i) {
			vertex[i].x *= _scale.x;
			vertex[i].y *= _scale.y;
		}
	}

	void Polygon::rotate(float _angle)
	{
		auto begin = Vector2{ vertex[0].x, vertex[0].y };
		for (int i{ 0 }; i < vertex.size(); ++i) {
			auto v = rotation({ vertex[i].x, vertex[i].y }, begin, _angle);
			vertex[i].x = v.x;
			vertex[i].y = v.y;
		}
	}

	void Polygon::draw()
	{
		if (vertex.size() < 3) {
			return;
		}

		GCoreIns->getGraphic()->getDevice()->SetFVF(FVF_CUSTOM2D);
		GCoreIns->getGraphic()->getDevice()->DrawPrimitiveUP(
			D3DPT_TRIANGLESTRIP, 
			static_cast<UINT>(vertex.size() - 2), 
			vertex.data(), 
			sizeof(Vertex2D)
		);
	}

}

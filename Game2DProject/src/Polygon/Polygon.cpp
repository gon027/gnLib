#include "../../include/Polygon/Polygon.h"
#include "../../include/Graphics/Graphics.h"
#include "../../include/Vertex/Vertex2D.h"
#include "../../include/Common/Macro.h"
#include "../../include/Render/Render.h"
#include "../../include/GameCore/GameCore.h"

namespace gnLib {

	Polygon::Polygon(std::initializer_list<Vertex2D> _vertex)
		: vertex(_vertex.begin(), _vertex.end())
		, position(Vector2::Zero)
		, color(Color::White)
	{
		for (int i = 0; i < vertex.size(); ++i) {
			vertex[i].color = color.getColor();
		}
	}

	Polygon::Polygon(std::vector<Vertex2D> _vertex)
		: vertex(_vertex)
		, position(Vector2::Zero)
		, color(Color::White)
	{
		for (int i = 0; i < vertex.size(); ++i) {
			vertex[i].color = color.getColor();
		}
	}

	void Polygon::setPos(Vector2 _v)
	{
		position = _v;
		//for (int i = 0; i < vertex.size(); ++i) {
			//vertex[i].x = position.x;
			//vertex[i].y = position.y;
		//}
	}

	void Polygon::setColor(Color _color)
	{
		color = _color;
		for (int i = 0; i < vertex.size(); ++i) {
			vertex[i].color = color.getColor();
		}
	}

	void Polygon::draw()
	{
		GCoreIns->getGraphic()->getDevice()->SetFVF(FVF_CUSTOM2D);
		GCoreIns->getGraphic()->getDevice()->DrawPrimitiveUP(
			D3DPT_TRIANGLESTRIP, 
			static_cast<UINT>(vertex.size() - 2), 
			vertex.data(), 
			sizeof(Vertex2D)
		);
	}

	void Polygon::setVertex(std::vector<Vertex2D> _vertex)
	{
		vertex = _vertex;
	}

}

#pragma once

#include <initializer_list>
#include <vector>
#include "../Object/Object.h"
#include "include/Vertex/Vertex2D.h"
#include "include/Vector/Vector2.h"
#include "include/Color/Color.h"

namespace gnLib {

	class Polygon {
	public:
		Polygon(std::initializer_list<Vertex2D> _vertex);
		Polygon(std::vector<Vertex2D> _vertex);
		~Polygon() = default;

		void setPos(Vector2 _v);

		void setColor(Color _color);

		void draw();

		void setVertex(std::vector<Vertex2D> _vertex);

	private:
		std::vector<Vertex2D> vertex;

		Vector2 position;
		Color color;
	};

}

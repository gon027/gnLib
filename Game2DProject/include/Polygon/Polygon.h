#ifndef POLYGON_H
#define POLYGON_H

#include <initializer_list>
#include <vector>
#include "../Object/Object.h"
#include "../Vertex/Vertex2D.h"
#include "../Vector/Vector2.h"
#include "../Color/Color.h"

namespace gnLib {

	class Polygon : public Object{
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

#endif // !POLYGON_H
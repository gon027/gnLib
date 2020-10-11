#include "Polygon.h"

namespace gnLib {

	Polygon::Polygon(std::initializer_list<Vertex3D> _vertex)
		: vertex(_vertex.begin(), _vertex.end())
	{
	}

	Polygon::Polygon(std::vector<Vertex3D> _vertex)
		: vertex(_vertex)
	{
	}

	void Polygon::setVertex(std::vector<Vertex3D> _vertex)
	{
		vertex = _vertex;
	}

}

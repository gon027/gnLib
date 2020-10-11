#pragma once

#include <initializer_list>
#include <vector>
#include "../Object/Object.h"
#include "include/Vertex/Vertex3D.h"

namespace gnLib {

	class Vector3;

	class Polygon {
	public:
		Polygon(std::initializer_list<Vertex3D> _list);
		Polygon(std::vector<Vertex3D> _vertex);
		~Polygon() = default;

		void setPos();

		void setVertex(std::vector<Vertex3D> _vertex);

	private:
		std::vector<Vertex3D> vertex;
	};

}

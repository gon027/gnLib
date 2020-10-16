#ifndef POLYGONCOLLIDER_H
#define POLYGONCOLLIDER_H

#include <vector>
#include <initializer_list>
#include "ICollider.h"
#include "../Vector/Vector2.h"

namespace gnLib {

	class Vertex2D;

	class PolygonCollider : public ICollider {

		// std::vector<Vertex2D>のエイリアス宣言
		using PolygonList = std::vector<Vertex2D>;

	public:
		PolygonCollider();
		PolygonCollider(std::initializer_list<Vertex2D> _polygon);
		~PolygonCollider() = default;

	private:
		PolygonList polygonList;
	};

}

#endif // !POLYGONCOLLIDER_H

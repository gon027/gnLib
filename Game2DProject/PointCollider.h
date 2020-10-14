#ifndef POINTCOLLIDER_H
#define POINTCOLLIDER_H

#include "include/Vector/Vector2.h"
#include "include/Collider/ICollider.h"

namespace gnLib {

	class BoxCollider;
	class CircleCollider;
	class PolygonCollider;

	class PointCollider : public ICollider{
	public:
		PointCollider();
		PointCollider(const Vector2& _pos);
		~PointCollider();

		void update(const Vector2 _pos);

		bool boxHitTest(const PointCollider& _collider);
		bool boxHitTest(const BoxCollider& _collider);
		bool boxHitTest(const CircleCollider& _collider);
		bool boxHitTest(const PolygonCollider& _collider);
		
		ColliderType getType() override;

		Vector2& getPos();

	private:
		Vector2 position;
	};

}

#endif // !POINTCOLLIDER_H

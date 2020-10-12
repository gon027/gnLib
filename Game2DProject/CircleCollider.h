#ifndef CIRCLECOLLIDER_H
#define CIRCLECOLLIDER_H

#include "include/Collider/ICollider.h"
#include "include/Vector/Vector2.h"

namespace gnLib {

	class BoxCollider;
	class PolygonCollider;

	/// <summary>
	/// â~ÇÃè’ìÀîªíËÉNÉâÉX
	/// </summary>
	class CircleCollider : public ICollider {
	public:
		CircleCollider();
		CircleCollider(const Vector2& _vector, const Vector2& _radius);
		CircleCollider(float _x, float _y, float _rx, float _ry);
		~CircleCollider() = default;

		void update(const Vector2& _vector, const Vector2& _radius);

		bool circleHitTest(const CircleCollider& _circleCollider);
		bool circleHitTest(const BoxCollider& _collider);
		bool circleHitTest(const PolygonCollider& _collider);

		ColliderType getType() override;

		Vector2& getPosition();
		Vector2& getRadius();

	private:
		Vector2 position;
		Vector2 radius;
	};

}

#endif // !CIRCLECOLLIDER_H

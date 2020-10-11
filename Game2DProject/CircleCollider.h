#ifndef CIRCLECOLLIDER_H
#define CIRCLECOLLIDER_H

#include "include/Collider/ICollider.h"
#include "include/Vector/Vector2.h"


namespace gnLib {

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

		bool hitTest(const CircleCollider& _circleCollider);

		ColliderType getType() override;

		Vector2& getPosition();
		Vector2& getRadius();

	private:
		Vector2 position;
		Vector2 radius;
	};

}

#endif // !CIRCLECOLLIDER_H

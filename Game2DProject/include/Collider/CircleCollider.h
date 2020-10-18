#ifndef CIRCLECOLLIDER_H
#define CIRCLECOLLIDER_H

#include "ICollider.h"
#include "../Vector/Vector2.h"

namespace gnLib {

	/// <summary>
	/// â~ÇÃè’ìÀîªíËÉNÉâÉX
	/// </summary>
	class CircleCollider : public ICollider {
	public:
		CircleCollider();
		CircleCollider(const Vector2& _vector, float _radius);
		CircleCollider(float _x, float _y, float _r);
		~CircleCollider() = default;

		ColliderType getType() override;

		bool isHitTest(const CircleCollider& _circleCollider) override;
		bool isHitTest(const BoxCollider& _collider) override;

		void update(const Vector2& _vector, float _radius);

		const Vector2& getPos() const;
		const float getRadius();

	private:
		Vector2 position;
		float radius;
	};
}

#endif // !CIRCLECOLLIDER_H

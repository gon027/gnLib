#ifndef BOXCOLLIDER_H
#define BOXCOLLIDER_H

#include "ICollider.h"
#include "../Vector/Vector2.h"


namespace gnLib {

	class CircleCollider;
	class PolygonCollider;

	class BoxCollider : public ICollider {
	public:
		BoxCollider(Vector2& _pos, Vector2& _min, Vector2& _max);
		BoxCollider() = default;
		~BoxCollider() = default;

		bool boxHitTest(BoxCollider& _collider);
		bool boxHitTest(const CircleCollider& _collider);
		bool boxHitTest(const PolygonCollider& _collider);

		void update(const Vector2& _pos, const Vector2& _min, const Vector2& _max);

		Vector2 getPosition() const;
		Vector2 getMin() const;
		Vector2 getMax() const;
		Vector2 gerSize() const;

		virtual ColliderType getType() override;

	private:
		Vector2 center;
		Vector2 minPos;
		Vector2 maxPos;
		Vector2 size;
	};
}

#endif // !BOXCOLLIDER_H

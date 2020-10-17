#ifndef BOXCOLLIDER_H
#define BOXCOLLIDER_H

#include "ICollider.h"
#include "../Vector/Vector2.h"
#include "../../Bounds.h"

namespace gnLib {

	class BoxCollider : public ICollider {
	public:
		BoxCollider(Vector2& _pos, Vector2& _min, Vector2& _max);
		BoxCollider() = default;
		~BoxCollider() = default;

		virtual ColliderType getType() override;

		bool isHitTest(const BoxCollider& _collider) override;
		bool isHitTest(const CircleCollider& _collider) override;

		void update(const Vector2& _pos, const Bounds& _bounds);

		Vector2 getPos() const;
		Vector2 getMin() const;
		Vector2 getMax() const;
		Vector2 gerSize() const;

	private:
		Vector2 center;
		Vector2 size;
		Bounds bounds;
	};
}

#endif // !BOXCOLLIDER_H

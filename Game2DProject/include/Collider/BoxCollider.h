#ifndef BOXCOLLIDER_H
#define BOXCOLLIDER_H

#include "ICollider.h"
#include "../Vector/Vector2.h"
#include "../../Bounds.h"

namespace gnLib {

	class BoxCollider : public ICollider {
	public:
		BoxCollider() = default;
		~BoxCollider() = default;

		virtual ColliderType getType() override;

		bool isHitTest(const BoxCollider& _collider) override;
		bool isHitTest(const CircleCollider& _collider) override;

		void update(const Vector2& _v, float _width, float _height);

		Bounds getBounds() const;

	private:
		Bounds bounds;
	};
}

#endif // !BOXCOLLIDER_H

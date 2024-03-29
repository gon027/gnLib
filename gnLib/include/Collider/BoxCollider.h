#ifndef BOXCOLLIDER_H
#define BOXCOLLIDER_H

#include <Collider/ICollider.h>
#include <Vector/Vector2.h>
#include <Bounds/Bounds.h>

namespace gnLib {

	class BoxCollider : public ICollider {
	public:
		BoxCollider();
		~BoxCollider() = default;

		ColliderType getType() const override;

		void update(const Vector2& _v, float _width, float _height);

		const Bounds& getBounds() const;
	private:
		Vector2 position;
		Bounds bounds;
	};
}

#endif // !BOXCOLLIDER_H

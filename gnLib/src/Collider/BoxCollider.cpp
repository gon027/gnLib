#include <Collider/BoxCollider.h>
#include <Collider/Collision2D.h>
#include <Collider/CircleCollider.h>
#include <Common/Math.h>

namespace gnLib {

	BoxCollider::BoxCollider()
		: position()
		, bounds()
	{
	}

	void BoxCollider::update(const Vector2& _v, float _width, float _height)
	{
		auto w = _width / 2.0f;
		auto h = _height / 2.0f;

		bounds.center = _v;
		bounds.minPos.setPos(_v.x, _v.y);
		bounds.maxPos.setPos(_v.x + _width, _v.y + _height);
		bounds.size.setPos(_width, _height);
	}

	const Bounds& BoxCollider::getBounds() const
	{
		return bounds;
	}

	ColliderType BoxCollider::getType() const
	{
		return ColliderType::Box;
	}

}
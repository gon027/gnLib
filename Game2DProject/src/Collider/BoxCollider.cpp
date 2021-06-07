#include "../../include/Collider/BoxCollider.h"
#include "../../include/Collider/CircleCollider.h"
#include "../../include/Common/Math.h"
#include "../../include/Collider/Collision2D.h"

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

	bool BoxCollider::onCollsion(const ICollider& _collider)
	{
		return Collision2D::isCollision(*this, *this);
	}

	ColliderType BoxCollider::getType() const
	{
		return ColliderType::Box;
	}

}
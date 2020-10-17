#include "../../include/Collider/CircleCollider.h"

namespace gnLib {

	CircleCollider::CircleCollider()
		: position(Vector2::Zero)
		, radius(0)
	{
	}

	CircleCollider::CircleCollider(const Vector2& _vector, float _radius)
		: position(_vector)
		, radius(_radius)
	{
	}

	CircleCollider::CircleCollider(float _x, float _y, float _r)
		: position(Vector2{ _x, _y })
		, radius(_r)
	{

	}

	ColliderType CircleCollider::getType()
	{
		return ColliderType::CIRCLE;
	}

	void CircleCollider::update(const Vector2& _vector, float _radius)
	{
		position.setPos(_vector);
		radius = _radius;
	}

	bool CircleCollider::isHitTest(const CircleCollider& _circleCollider)
	{
		auto dist = _circleCollider.position - this->position;
		auto c = dist.magnitude();
		auto r = _circleCollider.radius + this->radius;

		if (c <= r * r) {
			return true;
		}

		return false;
	}

	bool CircleCollider::isHitTest(const BoxCollider& _collider)
	{
		return false;
	}

	

	Vector2& CircleCollider::getPos()
	{
		return position;
	}

	float CircleCollider::getRadius()
	{
		return radius;
	}


}
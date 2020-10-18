#include "../../include/Collider/CircleCollider.h"
#include "../../include/Collider/BoxCollider.h"
#include "../../include/Common/Math.h"

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
		auto& b = _collider.getBounds();
		auto& p = position;

		if (p.x > b.minPos.x && p.x < b.maxPos.x
			&& p.y > b.minPos.y - radius && p.y < b.maxPos.y + radius) {
			return true;
		}

		if (p.x > b.minPos.x - radius && p.x < b.maxPos.x + radius
			&& p.y > b.minPos.y && p.y < b.maxPos.y) {
			return true;
		}

		float r = radius * radius;

		float rx = b.minPos.x - p.x;
		float ry = b.minPos.y - p.y;
		float d = dist(rx, ry);
		if (d < r)return true;

		rx = b.maxPos.x - p.x;
		ry = b.minPos.y - p.y;
		d = dist(rx, ry);
		if (d < r)return true;

		rx = b.maxPos.x - p.x;
		ry = b.maxPos.y - p.y;
		d = dist(rx, ry);
		if (d < r)return true;

		rx = b.minPos.x - p.x;
		ry = b.maxPos.y - p.y;
		d = dist(rx, ry);
		if (d < r)return true;

		return false;
	}

	const Vector2& CircleCollider::getPos() const
	{
		return position;
	}

	const float CircleCollider::getRadius()
	{
		return radius;
	}

}
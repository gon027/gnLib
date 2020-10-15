#include "../../include/Collider/PointCollider.h"
#include "../../include/Collider/CircleCollider.h"
#include "../../include/Collider/BoxCollider.h"

namespace gnLib {

	PointCollider::PointCollider()
		: position(Vector2::Zero)
	{
	}

	PointCollider::PointCollider(const Vector2& _pos)
		: position(_pos)
	{
	}

	PointCollider::~PointCollider()
	{
	}

	void PointCollider::update(const Vector2 _pos)
	{
		position = _pos;
	}

	bool PointCollider::isHitTest(const PointCollider& _collider)
	{
		auto pos = _collider.position;

		if (position == pos) {
			return true;
		}

		return false;
	}

	bool PointCollider::isHitTest(const BoxCollider& _collider)
	{
		auto min = _collider.getMin();
		auto max = _collider.getMax();

		if (position.x >= min.x &&
			position.x <= max.x &&
			position.y >= min.y &&
			position.y <= max.y) {
			return true;
		}

		return false;
	}

	bool PointCollider::isHitTest(const CircleCollider& _collider)
	{
		//auto a = p - position;


		//if()

		return false;
	}

	bool PointCollider::isHitTest(const PolygonCollider& _collider)
	{
		return false;
	}

	ColliderType PointCollider::getType()
	{
		return ColliderType::POINT;
	}

	Vector2& PointCollider::getPos()
	{
		return position;
	}

}
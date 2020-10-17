#include "../../include/Collider/BoxCollider.h"
#include "../../include/Debug/Debug.h"

namespace gnLib {

	BoxCollider::BoxCollider(Vector2& _pos, Vector2& _min, Vector2& _max)
		: center(_pos)
	{
	}

	bool BoxCollider::isHitTest(const BoxCollider& _collider)
	{
		if (getMax().x >= _collider.getMin().x
			&& getMin().x <= _collider.getMax().x
			&& getMax().y >= _collider.getMin().y
			&& getMin().y <= _collider.getMax().y)
		{
			return true;
		}

		return false;
	}

	bool gnLib::BoxCollider::isHitTest(const CircleCollider& _collider)
	{
		return false;
	}

	void BoxCollider::update(const Vector2& _pos, const Bounds& _bounds)
	{
		center.setPos(_pos);
		bounds = _bounds;
		size.setPos(bounds.rightBottom - bounds.leftTop);

		Debug::drawLine(bounds.leftTop,    bounds.rightTop,    5.0f);
		Debug::drawLine(bounds.leftTop,    bounds.leftBottom,  5.0f);
		Debug::drawLine(bounds.rightTop,   bounds.rightBottom, 5.0f);
		Debug::drawLine(bounds.leftBottom, bounds.rightBottom, 5.0f);
		Debug::drawText(0, 0, size.toString().c_str());
	}

	Vector2 BoxCollider::getPos() const
	{
		return center;
	}

	Vector2 BoxCollider::getMin() const
	{
		return bounds.leftTop;
	}

	Vector2 BoxCollider::getMax() const
	{
		return bounds.rightBottom;
	}

	Vector2 BoxCollider::gerSize() const
	{
		return size;
	}

	ColliderType BoxCollider::getType()
	{
		return ColliderType::BOX;
	}

}
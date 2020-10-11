#include "../../include/Collider/BoxCollider.h"

BoxCollider::BoxCollider(Vector2& _pos, Vector2& _min, Vector2& _max)
	: center(_pos)
	, minPos(_min)
	, maxPos(_max)
	, size(maxPos - minPos)
{
}

bool BoxCollider::hitTest(BoxCollider & _collider)
{
	if (maxPos.x >= _collider.getMin().x
		&&minPos.x <= _collider.getMax().x
		&& maxPos.y >= _collider.getMin().y
		&& minPos.y <= _collider.getMax().y)
	{
		return true;
	}

	return false;
}

void BoxCollider::update(const Vector2& _pos, const Vector2& _min, const Vector2& _max)
{
	//center.setPos(_pos);
	minPos.setPos(_min);
	maxPos.setPos(_max);
	size.setPos(maxPos - minPos);
	center.setPos(minPos + size.half());
}

Vector2 BoxCollider::getPosition() const
{
	return center;
}

Vector2 BoxCollider::getMin() const
{
	return minPos;
}

Vector2 BoxCollider::getMax() const
{
	return maxPos;
}

Vector2 BoxCollider::gerSize() const
{
	return size;
}

ColliderType BoxCollider::getType()
{
	return ColliderType::RECT;
}

#include "../../include/Collider/BoxCollider.h"

BoxCollider::BoxCollider(Vector2& _pos, Vector2& _min, Vector2& _max)
	: center(_pos)
	, minPos(_min)
	, maxPos(_max)
	, size(maxPos - minPos)
{
}

bool BoxCollider::hitTest(BoxCollider & _other)
{
	if (maxPos.x >= _other.getMin().x
		&&minPos.x <= _other.getMax().x
		&& maxPos.y >= _other.getMin().y
		&& minPos.y <= _other.getMax().y)
	{
		return true;
	}

	return false;
}

void BoxCollider::update(float _x, float _y, float _xSize, float _ySize)
{
	size.x = _xSize;
	size.y = _ySize;

	center.x = _x + size.x / 2;
	center.y = _y + size.y / 2;

	minPos.x = _x;
	minPos.y = _y;

	maxPos.x = _x + size.x;
	maxPos.y = _y + size.y;	
}

void BoxCollider::update(const Vector2& _pos, const Vector2& _min, const Vector2& _max)
{
	center.setPos(_pos);
	minPos.setPos(_min);
	maxPos.setPos(_max);
	size = maxPos - minPos;
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

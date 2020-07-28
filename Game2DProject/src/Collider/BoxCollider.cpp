#include "../../include/Collider/BoxCollider.h"

BoxCollider::BoxCollider(float _x, float _y)
{
}

bool BoxCollider::hitTest(BoxCollider & _other)
{
	if (max.x >= _other.getMinSize().x
		&&min.x <= _other.getMaxSize().x
		&& max.y >= _other.getMinSize().y
		&& min.y <= _other.getMaxSize().y)
	{
		return true;
	}

	return false;
}

void BoxCollider::setCollider(float _x, float _y, float _xSize, float _ySize)
{
	size.x = _xSize;
	size.y = _ySize;

	center.x = _x + size.x / 2;
	center.y = _y + size.y / 2;

	min.x = _x;
	min.y = _y;

	max.x = _x + size.x;
	max.y = _y + size.y;	
}

D3DXVECTOR2 BoxCollider::getPosition() const
{
	return center;
}

D3DXVECTOR2 BoxCollider::getMinSize() const
{
	return min;
}

D3DXVECTOR2 BoxCollider::getMaxSize() const
{
	return max;
}

ColliderType BoxCollider::getType()
{
	return ColliderType::RECT;
}

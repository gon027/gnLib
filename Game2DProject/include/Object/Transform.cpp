#include "Transform.h"

namespace gnLib {

	void Transform::setPos(float _x, float _y)
	{
		pos.setPos(_x, _y);
	}

	void Transform::setPos(const Vector2& _v)
	{
		pos.setPos(_v);
	}

	void Transform::setScale(float _sx, float _sy)
	{
		scale.setPos(_sx, _sy);
	}

	void Transform::setScale(const Vector2& _v)
	{
		scale.setPos(_v);
	}

	void Transform::setRotate(float _angle)
	{
		angle = _angle;
	}

}

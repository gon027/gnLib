#include "Vector3.h"
#include "Vector2.h"


namespace gnLib {

	Vector3::Vector3()
		: x(0.0f)
		, y(0.0f)
		, z(0.0f)
	{ }

	Vector3::Vector3(const Vector2 & _vector)
		: x(_vector.x)
		, y(_vector.y)
		, z(0.0f)
	{ }

	Vector3::Vector3(const Vector3 & _vector)
		: x(_vector.x)
		, y(_vector.y)
		, z(_vector.z)
	{ }

	gnLib::Vector3::Vector3(float _x, float _y, float _z)
		: x(_x)
		, y(_y)
		, z(_z)
	{ }

	gnLib::Vector3::Vector3(float _xyz)
		: x(_xyz)
		, y(_xyz)
		, z(_xyz)
	{ }

	void Vector3::set(float _x, float _y, float _z)
	{
		x = _x;
		y = _y;
		z = _z;
	}

	void Vector3::set(const Vector3 & _vector)
	{
		set(_vector.x, _vector.y, _vector.z);
	}

	const Vector2 Vector3::toVector2()
	{
		return { x, y };
	}

}
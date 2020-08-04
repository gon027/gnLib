#include "Vector2.h"

namespace gnLib {
	Vector2::Vector2()
		: x(0)
		, y(0)
	{

	}

	Vector2::Vector2(const Vector2 & _vector)
		: x(_vector.x)
		, y(_vector.y)	
	{

	}

	Vector2::Vector2(float _x, float _y)
		: x(_x)
		, y(_y)
	{

	}

	Vector2::Vector2(float _xy)
		: x(_xy)
		, y(_xy)
	{

	}

	void Vector2::setPoision(float _x, float _y)
	{
		x = _x;
		y = _y;
	}



}

#ifndef MATH_H
#define MATH_H

#include "../Vector/Vector2.h"

namespace gnLib {

	constexpr float pi = 3.1415926535f;
	constexpr float tau = pi * 2.0f;

	// �x�N�g������]������
	inline Vector2 rotation(const Vector2& _origin, const Vector2& _center, float _rot) {

		// ���S���W��0�ɖ߂�
		auto diff = _origin - _center;

		return Vector2{
			diff.x * cosf(_rot) - diff.y * sinf(_rot) + _center.x,
			diff.x * sinf(_rot) + diff.y * cosf(_rot) + _center.y
		};
	}

}

#endif // !MATH_H

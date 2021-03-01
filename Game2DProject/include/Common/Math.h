#ifndef MATH_H
#define MATH_H

#include "../Vector/Vector2.h"

namespace gnLib {

	constexpr float pi = 3.1415926535f;
	constexpr float tau = pi * 2.0f;

	// �p�x�ɕϊ�
	inline float toDegrees(float _radians) {
		return _radians * 180.0f / pi;
	}

	// ���W�A���ɕϊ�
	inline float toRadians(float _degrees) {
		return _degrees * pi / 180.0f;
	}

	// �ŏ��l����ő�l�̊ԂɎ��߂�
	template<class T>
	inline T clamp(T _value, T _min, T _max) {
		return min(max(_value, _min), _max);
	}

	// �x�N�g����clamp�֐�
	inline Vector2 vecClamp(const Vector2& _vec, const Vector2& _min, const Vector2& _max) {
		return{
			min(_max.x, max(_vec.x, _min.x)),
			min(_max.y, max(_vec.y, _min.y))
		};
	}

	// ���������߂�
	constexpr float dist(float _x, float _y) {
		return _x * _x + _y * _y;
	}

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
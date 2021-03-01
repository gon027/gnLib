#ifndef MATH_H
#define MATH_H

#include "../Vector/Vector2.h"

namespace gnLib {

	constexpr float pi = 3.1415926535f;
	constexpr float tau = pi * 2.0f;

	// 角度に変換
	inline float toDegrees(float _radians) {
		return _radians * 180.0f / pi;
	}

	// ラジアンに変換
	inline float toRadians(float _degrees) {
		return _degrees * pi / 180.0f;
	}

	// 最小値から最大値の間に収める
	template<class T>
	inline T clamp(T _value, T _min, T _max) {
		return min(max(_value, _min), _max);
	}

	// ベクトルのclamp関数
	inline Vector2 vecClamp(const Vector2& _vec, const Vector2& _min, const Vector2& _max) {
		return{
			min(_max.x, max(_vec.x, _min.x)),
			min(_max.y, max(_vec.y, _min.y))
		};
	}

	// 距離を求める
	constexpr float dist(float _x, float _y) {
		return _x * _x + _y * _y;
	}

	// ベクトルを回転させる
	inline Vector2 rotation(const Vector2& _origin, const Vector2& _center, float _rot) {

		// 中心座標を0に戻す
		auto diff = _origin - _center;

		return Vector2{
			diff.x * cosf(_rot) - diff.y * sinf(_rot) + _center.x,
			diff.x * sinf(_rot) + diff.y * cosf(_rot) + _center.y
		};
	}

}

#endif // !MATH_H
#ifndef VECTOR3_H
#define VECTOR3_H

namespace gnLib {
	class Vector2;

	class Vector3 {
	public:
		float x;
		float y;
		float z;

		Vector3();
		Vector3(const Vector2& _vector);
		Vector3(const Vector3& _vector);
		Vector3(float _x, float _y, float z = 0.0f);
		Vector3(float _xyz);
		~Vector3() = default;

		void set(float _x, float _y, float _z);
		void set(const Vector3& _vector);

		const float magnitude() const;

		const Vector3 normalized() const;

		const float sqrMagnitude() const;

		// ì‡êœ
		const float dot(const Vector3& _v);

		// äOêœ
		const Vector3 cross(const Vector3& _v);

		// Vector2Ç…ïœä∑
		const Vector2 toVector2();

		const Vector3 operator+() const;

		const Vector3 operator-() const;

		const Vector3 operator+(const Vector3& _rvec) const;

		const Vector3 operator-(const Vector3& _rvec) const;

		const Vector3 operator*(const Vector3& _rvec) const;

		const Vector3 operator/(const Vector3& _rvec) const;

		const Vector3& operator+=(const Vector3& _rvec);

		const Vector3& operator-=(const Vector3& _rvec);

		const Vector3& operator*=(const Vector3& _rvec);

		const Vector3& operator/=(const Vector3& _rvec);

		const bool operator==(const Vector3& _rvec) const;

		const bool operator!=(const Vector3& _rvec) const;
	};
}

#endif // !VECTOR3_H

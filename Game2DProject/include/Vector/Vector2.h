#ifndef VECTOR2_H
#define VECTOR2_H

namespace gnLib {
	class Vector3;

	class Vector2 {
	public:
		float x;
		float y;

		Vector2();
		Vector2(const Vector2& _vector);
		Vector2(float _x, float _y);
		Vector2(float _xy);
		~Vector2() = default;

		void setPosition(float _x, float _y);
		void setPosition(const Vector2& _vector);

		const float magnitude() const;

		const Vector2 normalized() const;

		const float sqrMagnitude() const;

		// ì‡êœ
		const float dot(const Vector2 _rvec);

		Vector3 toVector3();

		// TODO: ââéZéqÇé¿ëïÇ∑ÇÈ
		const Vector2 operator+() const;

		const Vector2 operator-() const;

		const Vector2 operator+(const Vector2& _rvec) const;

		const Vector2 operator-(const Vector2& _rvec) const;

		const Vector2 operator*(const Vector2& _rvec) const;

		const Vector2 operator/(const Vector2& _rvec) const;

		const Vector2& operator+=(const Vector2& _rvec);

		const Vector2& operator-=(const Vector2& _rvec);

		const Vector2& operator*=(const Vector2& _rvec);

		const Vector2& operator/=(const Vector2& _rvec);

		const bool operator==(const Vector2& _rvec) const;

		const bool operator!=(const Vector2& _rvec) const;
	};

}


#endif // !VECTOR2_H

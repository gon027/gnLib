#ifndef VECTOR2_H
#define VECTOR2_H

namespace gnLib {
	class Vector3;

	// 2�����x�N�g���N���X
	class Vector2 {
	public:
		float x;
		float y;

		static Vector2 Up;
		static Vector2 Down;
		static Vector2 Left;
		static Vector2 Right;
		static Vector2 One;
		static Vector2 Zero;

		Vector2();
		Vector2(const Vector2& _vector);
		Vector2(float _x, float _y);
		Vector2(float _xy);
		~Vector2() = default;

		void setPos(float _x, float _y);
		void setPos(const Vector2& _vector);

		const float magnitude() const;

		const Vector2 normalized() const;

		const float sqrMagnitude() const;

		// ����
		const float dot(const Vector2& _rvec);

		// �O��
		const float cross(const Vector2& _rvec);

		// Vector3�ɕϊ�
		Vector3 toVector3();

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

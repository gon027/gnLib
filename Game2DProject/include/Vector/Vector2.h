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

		// TODO: ‰‰ŽZŽq‚ðŽÀ‘•‚·‚é
	};

}


#endif // !VECTOR2_H

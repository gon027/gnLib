#ifndef CIRCLE_H
#define CIRCLE_H

#include <Vector/Vector2.h>
#include <Color/Color.h>

namespace gnLib {

	/// <summary>
	/// �~��`�悷��N���X
	/// </summary>
	class Circle {
	public:
		Circle();
		Circle(float _x, float _y, float _r);
		Circle(const Vector2& _pos, float _r);
		~Circle() = default;

		// ���W��ݒ�
		Circle& setPos(float _x, float _y);
		Circle& setPos(const Vector2& _vector);

		// �~�̑傫����ݒ�
		Circle& setRadius(float _radius);

		// �F��ݒ�
		Circle& setColor(const Color& _color);
		Circle& setColor(int _r, int _g, int _b);

		// �`��
		void draw();

	private:
		Vector2 position;
		float radius;
		Color color;
	};
}

#endif // !CIRCLE_H

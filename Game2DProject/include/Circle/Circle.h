#ifndef CIRCLE_H
#define CIRCLE_H

#include "../../include/Object/Object.h"
#include "../../include/Vector/Vector2.h"
#include "../../include/Color/Color.h"
#include "../../include/Collider/CircleCollider.h"

namespace gnLib {

	/// <summary>
	/// �~��`�悷��N���X
	/// </summary>
	class Circle : public Object {
	public:
		Circle();
		Circle(float _x, float _y, float _r);
		Circle(Vector2 _pos, float _r);
		~Circle() = default;

		// ���W��ݒ�
		void setPos(float _x, float _y);
		void setPos(const Vector2& _vector);

		// �~�̑傫����ݒ�
		void setRadius(float _radius);

		// �F��ݒ�
		void setColor(const Color& _color);
		void setColor(int _r, int _g, int _b);

		// �`��
		void draw();

	private:
		Vector2 position;
		float radius;
		Color color;

	public:
		CircleCollider collider;
	};
}

#endif // !CIRCLE_H

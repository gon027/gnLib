#ifndef RECT_H
#define RECT_H

#include "../Object/Object.h"
#include "../Vector/Vector2.h"
#include "../Color/Color.h"
#include "../Collider/BoxCollider.h"
#include "../../Bounds.h"

namespace gnLib {

	class Rect : public Object{
	public:
		Rect();
		Rect(float _x, float _y, float _width, float _height);
		Rect(const Vector2& _v, float _width, float _height);
		~Rect() = default;

		// ���W��ݒ�
		void setPos(float _x, float _y);
		void setPos(const Vector2& _v);

		// �傫����ݒ�
		void setSize(float _width, float _height);
		void setSize(float _wh);

		// ��]������
		void setRotate(float _rot);

		// �F��ݒ�
		void setColor(const Color& _color);

		// �`��
		void draw();

		// ���W���擾
		Vector2 getPos();

	private:
		Vector2 position;
		float width;         // ����
		float height;        // ����
		float radian;        // ��]�p
		Color color;         // �F

	public:
		BoxCollider collider;
	};

}

#endif // !RECT_H

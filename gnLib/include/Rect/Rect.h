#ifndef RECT_H
#define RECT_H

#include <Vector/Vector2.h>
#include <Color/Color.h>
#include <Bounds/Bounds.h>

namespace gnLib {

	class Rect {
	public:
		Rect();
		Rect(float _x, float _y, float _width, float _height);
		Rect(const Vector2& _v, float _width, float _height);
		~Rect() = default;

		// ���W��ݒ�
		Rect& setPos(float _x, float _y);
		Rect& setPos(const Vector2& _v);

		// �傫����ݒ�
		Rect& setSize(float _width, float _height);
		Rect& setSize(float _wh);

		// ��]������
		Rect& setRotate(float _rot);

		// �F��ݒ�
		Rect& setColor(const Color& _color);

		// �`��
		void draw();

	private:
		Vector2 position;
		


		float width;         // ����
		float height;        // ����
		float radian;        // ��]�p
		Color color;         // �F
	};

}

#endif // !RECT_H

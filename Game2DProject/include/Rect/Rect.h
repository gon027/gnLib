#ifndef RECT_H
#define RECT_H

#pragma comment(lib, "d3dx9.lib")
#include <d3dx9.h>

#include "../Object/Object.h"
#include "../Vector/Vector3.h"
#include "../Vector/Vector2.h"
#include "../Color/Color.h"
#include "../Collider/BoxCollider.h"

namespace gnLib {

	class RectAngle : public Object{
	public:
		RectAngle();
		RectAngle(float _x, float _y, float _width, float _height);
		RectAngle(const Vector2& _v, float _width, float _height);
		RectAngle(const Vector3& _v, float _width, float _height);
		~RectAngle();

		// ���W��ݒ�
		void setPos(float _x, float _y, float _z);
		void setPos(const Vector2& _v);
		void setPos(const Vector3& _v);

		// �傫����ݒ�
		void setSize(float _width, float _height);
		void setSize(float _wh);

		// �F��ݒ�
		void setColor(const Color& _color);

		// �`��
		void draw();

		// ���W���擾
		Vector3 getMinPos();
		Vector3 getMaxPos();

	private:
		Vector3 position;
		Vector3 maxPos;
		float width;
		float height;
		Color color;

	public:
		BoxCollider collider;
	};

}

#endif // !RECT_H

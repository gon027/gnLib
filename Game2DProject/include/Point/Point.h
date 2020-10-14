#ifndef POINT_H
#define POINT_H

#include "../Object/Object.h"
#include "../Vector/Vector2.h"
#include "../Color/Color.h"
#include "../../PointCollider.h"

namespace gnLib {

	class Point : public Object{
	public:
		Point();
		Point(const Vector2& _pos);
		~Point() = default;

		// ���W��ݒ�
		void setPos(const Vector2& _pos);

		// �F��ݒ�
		void setColor(const Color& _color);

		// �`��
		void draw();

		// ���W�擾
		Vector2 getPos() const;

	private:
		Vector2 position;
		Color color;

	public:
		PointCollider collider;
	};

}

#endif // !POINT_H

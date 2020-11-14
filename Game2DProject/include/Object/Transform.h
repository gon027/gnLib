#ifndef TRANSFORM_H
#define TRANSFORM_H

#include "../Common/Lib.h"
#include "../Vector/Vector2.h"

namespace gnLib {

	class Transform {
	public:
		// ���W��ݒ肷��
		void setPos(float _x, float _y);
		void setPos(const Vector2& _v);

		// �摜�̑傫����ݒ肷��
		void setScale(float _sx, float _sy);
		void setScale(const Vector2& _v);

		// �摜�̊p�x��ݒ肷��
		void setRotate(float _angle);

	public:
		Vector2 pos;
		Vector2 scale;
		float angle;
	};

}

#endif // !TRANSFORM_H

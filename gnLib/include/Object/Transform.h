#ifndef TRANSFORM_H
#define TRANSFORM_H

#include "../Common/Lib.h"
#include "../Vector/Vector2.h"

namespace gnLib {

	class Transform {
	public:
		Transform();
		~Transform() = default;

		// 座標を設定する
		void setPos(float _x, float _y);
		void setPos(const Vector2& _v);

		// 画像の大きさを設定する
		void setScale(float _sx, float _sy);
		void setScale(const Vector2& _v);

		// 画像の角度を設定する
		void setRotate(float _angle);

	public:
		Vector2 pos;
		Vector2 scale;
		float angle;
	};

}

#endif // !TRANSFORM_H

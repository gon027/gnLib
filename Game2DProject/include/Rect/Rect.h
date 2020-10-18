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

		// 座標を設定
		void setPos(float _x, float _y);
		void setPos(const Vector2& _v);

		// 大きさを設定
		void setSize(float _width, float _height);
		void setSize(float _wh);

		// 回転させる
		void setRotate(float _rot);

		// 色を設定
		void setColor(const Color& _color);

		// 描画
		void draw();

		// 座標を取得
		Vector2 getPos();

	private:
		Vector2 position;
		float width;         // 横幅
		float height;        // 横幅
		float radian;        // 回転角
		Color color;         // 色

	public:
		BoxCollider collider;
	};

}

#endif // !RECT_H

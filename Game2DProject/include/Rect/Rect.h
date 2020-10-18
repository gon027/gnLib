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

		// À•W‚ğİ’è
		void setPos(float _x, float _y);
		void setPos(const Vector2& _v);

		// ‘å‚«‚³‚ğİ’è
		void setSize(float _width, float _height);
		void setSize(float _wh);

		// ‰ñ“]‚³‚¹‚é
		void setRotate(float _rot);

		// F‚ğİ’è
		void setColor(const Color& _color);

		// •`‰æ
		void draw();

		// À•W‚ğæ“¾
		Vector2 getPos();

	private:
		Vector2 position;
		float width;         // ‰¡•
		float height;        // ‰¡•
		float radian;        // ‰ñ“]Šp
		Color color;         // F

	public:
		BoxCollider collider;
	};

}

#endif // !RECT_H

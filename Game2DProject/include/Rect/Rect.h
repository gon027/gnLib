#ifndef RECT_H
#define RECT_H

#include "../Object/Object.h"
#include "../Vector/Vector3.h"
#include "../Vector/Vector2.h"
#include "../Color/Color.h"
#include "../Collider/BoxCollider.h"

namespace gnLib {

	class Rect : public Object{
	public:
		Rect();
		Rect(float _x, float _y, float _width, float _height);
		Rect(const Vector2& _v, float _width, float _height);
		Rect(const Vector3& _v, float _width, float _height);
		~Rect();

		// À•W‚ğİ’è
		void setPos(float _x, float _y, float _z);
		void setPos(const Vector2& _v);
		void setPos(const Vector3& _v);

		// ‘å‚«‚³‚ğİ’è
		void setSize(float _width, float _height);
		void setSize(float _wh);

		// F‚ğİ’è
		void setColor(const Color& _color);

		// •`‰æ
		void draw();

		// À•W‚ğæ“¾
		Vector3 getPos();
		Vector3 getMinPos();
		Vector3 getMaxPos();

	private:
		Vector3 position;
		Vector3 minPos;
		Vector3 maxPos;
		float width;
		float height;
		Color color;

	public:
		BoxCollider collider;
	};

}

#endif // !RECT_H

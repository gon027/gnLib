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

		// À•W‚ğİ’è
		void setPos(const Vector2& _pos);

		// F‚ğİ’è
		void setColor(const Color& _color);

		// •`‰æ
		void draw();

		// À•Wæ“¾
		Vector2 getPos() const;

	private:
		Vector2 position;
		Color color;

	public:
		PointCollider collider;
	};

}

#endif // !POINT_H

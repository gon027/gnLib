#ifndef CIRCLE_H
#define CIRCLE_H

#include "../../include/Object/Object.h"
#include "../../include/Vector/Vector2.h"
#include "../../include/Color/Color.h"
#include "../../include/Collider/CircleCollider.h"

namespace gnLib {

	/// <summary>
	/// ‰~‚ğ•`‰æ‚·‚éƒNƒ‰ƒX
	/// </summary>
	class Circle : public Object {
	public:
		Circle();
		Circle(float _x, float _y, float _r);
		Circle(Vector2 _pos, float _r);
		~Circle() = default;

		// À•W‚ğİ’è
		void setPos(float _x, float _y);
		void setPos(const Vector2& _vector);

		// ‰~‚Ì‘å‚«‚³‚ğİ’è
		void setRadius(float _radius);

		// F‚ğİ’è
		void setColor(const Color& _color);
		void setColor(int _r, int _g, int _b);

		// •`‰æ
		void draw();

	private:
		Vector2 position;
		float radius;
		Color color;

	public:
		CircleCollider collider;
	};
}

#endif // !CIRCLE_H

#ifndef RECT_H
#define RECT_H

#pragma comment(lib, "d3dx9.lib")
#include <d3dx9.h>

#include "../Object/Object.h"
#include "../Vector/Vector3.h"
#include "../Vector/Vector2.h"
#include "../Color/Color.h"

namespace gnLib {

	class RectAngle : public Object{
	public:
		RectAngle();
		RectAngle(float _x, float _y, float _width, float _height);
		RectAngle(const Vector2& _v, float _width, float _height);
		RectAngle(const Vector3& _v, float _width, float _height);
		~RectAngle();

		void setPos(float _x, float _y, float _z);
		void setPos(const Vector2& _v);
		void setPos(const Vector3& _v);

		void setSize(float _width, float _height);
		void setSize(float _wh);

		void setColor(const Color& _color);

		void draw();

	private:
		Vector3 position;
		float width;
		float height;
		Color color;
	};

}

#endif // !RECT_H

#ifndef IGRAPHICSRENDER_H
#define IGRAPHICSRENDER_H

namespace gnLib {

	class Graphics;
	class Color;

	namespace gnLibCore {

		class IGraphicsRender {
		public:
			virtual ~IGraphicsRender() = default;

			virtual void init(Graphics* _graphics) = 0;

			virtual void drawRect2D(float _x, float _y, float _width, float _height, float _r, const Color& _color) = 0;

			virtual void drawCircle2D(float _x, float _y, float _r, const Color& _color) = 0;

			virtual void drawLine2D(float _sx, float _sy, float _gx, float _gy, float _weight, float _r, const Color& _color) = 0;

			virtual void drawPoint2D(float _x, float _y, const Color& _color) = 0;
		};

	}

}

#endif // !IGRAPHICSRENDER_H
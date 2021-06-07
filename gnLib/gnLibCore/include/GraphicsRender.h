#ifndef GRAPHICSRENDER_H
#define GRAPHICSRENDER_H

#include "../interface/IGraphicsRender.h"

namespace gnLib {

	class Graphics;
	class Color;

	namespace gnLibCore {

		class GraphicsRender : public IGraphicsRender {
		public:
			GraphicsRender() = default;
			~GraphicsRender() = default;

			void init(Graphics* _graphics) override;

			void drawRect2D(float _x, float _y, float _width, float _height, float _r, const Color& _color) override;

			void drawCircle2D(float _x, float _y, float _r, const Color& _color) override;

			void drawLine2D(float _sx, float _sy, float _gx, float _gy, float _weight, float _, const Color& _color) override;

			void drawPoint2D(float _x, float _y, const Color& _color) override;

		private:
			Graphics* graphics;
		};

	}

}

#endif // !GRAPHICSRENDER_H
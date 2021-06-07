#include <GraphicsRender.h>
#include <Common/Macro.h>
#include <GameCore/GameCore.h>
#include <Graphics/Graphics.h>
#include <Vertex/Vertex2D.h>
#include <Vector/Vector2.h>
#include <Color/Color.h>
#include <Common/Math.h>
#include <Render/Render.h>
#include <vector>

namespace gnLib {

	namespace gnLibCore {

		namespace {
			constexpr int NUM = 50 + 2;                  // í∏ì_ÇÃêî
			constexpr float SPLIT = NUM - 2;             
			constexpr float theta = gnLib::tau / SPLIT;
		}

		void GraphicsRender::init(Graphics* _graphics)
		{
			graphics = _graphics;
		}

		void GraphicsRender::drawRect2D(float _x, float _y, float _width, float _height, float _r, const Color& _color)
		{
			float r = _r;
			auto leftTop = Vector2{ _x, _y };
			auto leftBottom = Vector2{ _x, _y + _height };
			auto rightTop = Vector2{ _x + _width,  _y };
			auto rightBottom = Vector2{ _x + _width, _y + _height };

			std::vector<Vertex2D> vertex = {
				{leftBottom.x,  leftBottom.y,  0.0f, 1.0f, _color.getColor(), 0.0f, 0.0f},
				{leftTop.x,     leftTop.y,     0.0f, 1.0f, _color.getColor(), 0.0f, 0.0f},
				{rightBottom.x, rightBottom.y, 0.0f, 1.0f, _color.getColor(), 0.0f, 0.0f},
				{rightTop.x,    rightTop.y,    0.0f, 1.0f, _color.getColor(), 0.0f, 0.0f},
			};

			GCGraphics->SetFVF(FVF_CUSTOM2D);
			GCGraphics->DrawPrimitiveUP(D3DPT_TRIANGLESTRIP, 2, vertex.data(), sizeof(Vertex2D));
		}

		void GraphicsRender::drawCircle2D(float _x, float _y, float _r, const Color& _color)
		{
			std::vector<Vertex2D> circle(NUM);
			circle[0] = Vertex2D{ _x + _r * cosf(0.0f),  _y + _r * sin(0.0f), 0.0f, 1.0f, _color.getColor(), 0.0f, 0.0f };
			for (int i{ 1 }; i < NUM; ++i) {
				float nx = _x + _r * cosf(theta * (i - 1));
				float ny = _y + _r * sinf(theta * (i - 1));

				circle[i] = Vertex2D{ nx, ny, 0.0f, 1.0f, _color.getColor(), 0.0f, 0.0f };
			}
			circle[NUM - 1] = circle[1];

			GCoreIns->getGraphic()->getDevice()->SetFVF(FVF_CUSTOM2D);
			GCoreIns->getGraphic()->getDevice()->DrawPrimitiveUP(
				D3DPT_TRIANGLEFAN,
				NUM - 1,
				circle.data(),
				sizeof(Vertex2D)
			);
		}

		void GraphicsRender::drawLine2D(float _sx, float _sy, float _gx, float _gy, float _weight, float _r, const Color& _color)
		{
			D3DXVECTOR2 vLise[] = {
				{_sx, _sy}, {_gx, _gy}
			};

			GCLineDevice->SetAntialias(true);
			GCLineDevice->SetWidth(_weight);
			GCLineDevice->Begin();
			{
				GCLineDevice->Draw(
					vLise, 2, _color.getColor()
				);
			}
			GCLineDevice->End();
		}

		void GraphicsRender::drawPoint2D(float _x, float _y, const Color& _color)
		{
			std::vector<Vertex2D> vertex = {
				{_x, _y, 0.0f, 1.0f, _color.getColor(), 0.0f, 0.0f}
			};

			GCGraphics->SetFVF(FVF_CUSTOM2D);
			GCGraphics->DrawPrimitiveUP(
				D3DPT_POINTLIST,
				1,
				vertex.data(),
				sizeof(Vertex2D)
			);
		}

	}

}
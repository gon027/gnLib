#ifndef RENDER_H
#define RENDER_H

#pragma comment(lib, "d3d9.lib")
#pragma comment(lib, "d3dx9.lib")
#pragma comment(lib, "d3dxof.lib")
#include <d3d9.h>
#include <d3dx9.h>

#define RenderIns    Render::Instance
#define RenderDevice Render::Instance->getGraphics()->getDevice()
#define LineDevice 

namespace gnLib {

	class Graphics;

	namespace {
		class LineRender {

		};
	}

	class Render {
	public:
		Render();
		~Render();

		static Render* Instance;

		void init(Graphics* _graphics);

		Graphics* getGraphics() const;
		ID3DXLine* getLineDevice() const;

	private:
		Graphics* graphics;
		ID3DXLine* d3dxLine;

		// コピーコンストラクタ禁止
		Render(const Render& _render) = delete;
		Render& operator= (const Render& _render) = delete;
	};
}

#endif // !RENDER_H

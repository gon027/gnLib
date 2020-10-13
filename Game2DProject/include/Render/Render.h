#ifndef RENDER_H
#define RENDER_H

#pragma comment(lib, "d3d9.lib")
#pragma comment(lib, "d3dx9.lib")
#pragma comment(lib, "d3dxof.lib")
#include <d3d9.h>
#include <d3dx9.h>

namespace gnLib {
	class Graphics;

	class RenderDevice {
	public:
		~RenderDevice();

		void init(Graphics* _graphics);

		ID3DXLine* getLineDevice() const;
		LPD3DXFONT getFontDevice() const;

	private:
		ID3DXLine* d3dxLine;     // ���C��
		LPD3DXFONT lpd3dxFont;   // ��ʂɕ������`��
	};
}

#endif // !RENDER_H

#ifndef RENDER_H
#define RENDER_H

#include "../Common/Lib.h"

namespace gnLib {
	class Graphics;

	class RenderDevice {
	public:
		~RenderDevice();

		void init(Graphics* _graphics);

		ID3DXLine* getLineDevice() const;
		LPD3DXFONT getFontDevice() const;

	private:
		ID3DXLine* d3dxLine;     // ƒ‰ƒCƒ“
		LPD3DXFONT lpd3dxFont;   // ‰æ–Ê‚É•¶Žš—ñ‚ð•`‰æ
	};
}

#endif // !RENDER_H

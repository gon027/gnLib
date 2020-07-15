#include "Main.h"

/*
#include <vector>
#include "Sprite.h"
#include "Rect.h"
#include "Color.h"
#include "Texture.h"
*/

/*
Sprite suraimu, s, backGround;
float t = 0;
RectAngle rect{};

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrefInstance, LPSTR lpCmdLine, int nCmdShow) {
	window::Window win{};
	win.createGraphics();

	Graphics graphics{};
	graphics.createGraphics(win);

	suraimu.loadTexture(graphics, "img/char.png");
	s.loadTexture(graphics, "img/char.png");
	backGround.loadTexture(graphics, "img/backscreen.jpg");

	std::vector<RectAngle> rects{};

	MSG msg = {};
	while (msg.message != WM_QUIT) {
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE)) {
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		else {
			// •`‰æˆ—
			graphics.begin();
			graphics.device->Clear(0, NULL, D3DCLEAR_TARGET, D3DCOLOR_XRGB(0xFF, 0xFF, 0xFF), 1.0, 0);

			t += 1.0f;

			backGround.draw(320, 240);

			/*for (float i = 0.0f; i <= (3.14 * 2); i += (3.14f / 12.0f)) {
				float x = 320.0f + sin(t * 0.01f) * 100.0f * cos(i + t);
				float y = 240.0f + cos(t * 0.1f) * 100.0f * sin(i + t);
				rects[i].draw(graphics, x, y, 25.0f, 25.0f, RGBA(255, 0, 255));
			}
			
			suraimu.scaleDraw(300, 300, 0.5f + sin(D3DXToRadian(t)) * 2, 0.5f);

			s.rotateDraw(50, 400, 40 + t);

			graphics.end();
		}
	}

	return 0;
}

*/
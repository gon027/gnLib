#include "App.h"

#include <vector>
#include "Console.h"
#include "Window.h"
#include "Texture.h"
#include "Sprite.h"
using namespace window;

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrefInstance, LPSTR lpCmdLine, int nCmdShow) {
	App app{ "WindowName" };

	Texture t, tt;
	t.loadTexture(app.getGraphics(), "img/char.png");
	tt.loadTexture(app.getGraphics(), "img/backscreen.jpg");

	Sprite sp3;
	sp3.loadTexture(app.getGraphics(), tt);

	std::vector<Sprite> sps(10);

	for (int i = 0; i < 10; ++i) {
		sps[i].loadTexture(app.getGraphics(), t);
	}

	while (app.update())
	{
		app.begin();

		sp3.draw(640 / 2, 480 / 2);

		for (int i = 0; i < 10; ++i) {
			sps[i].draw(50 + i * 45, 200);
		}

		app.end();
	}
}
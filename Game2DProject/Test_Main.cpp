#include "App.h"

#include <vector>
#include "Console.h"
#include "Texture.h"
#include "Sprite.h"
#include "MouseInput.h"
#include "Rect.h"
#include "KeyInput.h"

float time = 0;

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrefInstance, LPSTR lpCmdLine, int nCmdShow) {
	console::Console console;
	console.createConsole();

	App app{ "WindowName" };

	if (app.getWindow()->isClosed()) {
		console.print("aaaa\n");
	}

	Mouse m{ app.getWindow() };
	m.createDInput();
	m.create();

	Texture t, tt;
	t.loadTexture(app.getGraphics(), "img/char.png");
	tt.loadTexture(app.getGraphics(), "img/backscreen.jpg");

	if (t.isLoading()) {
		console.print("bbbbb");
	}

	Sprite sp1, sp3;
	sp1.loadTexture(app.getGraphics(), t);
	sp3.loadTexture(app.getGraphics(), tt);

	std::vector<Sprite> sps(10);

	RectAngle rect;

	for (int i = 0; i < 10; ++i) {
		sps[i].loadTexture(app.getGraphics(), t);
	}

	while (app.update())
	{
		app.begin();

		m.update();

		if (m.getLeftButton()) {
			time += 1.0f;
			console.print("aaaaaaafdfe\n");
		}
		
		sp3.draw(640 / 2, 480 / 2);

		for (int i = 0; i < 10; ++i) {
			sps[i].draw(50 + i * 45, 200);
		}

		sp1.rotateDraw(350.0f, 350.0f, time);

		rect.draw(app.getGraphics(), 250, 250, 100, 100, 0xFF00FFFF);

		app.end();
	}
}
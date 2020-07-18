#include "App.h"

/*
#include <vector>
#include "Console.h"
#include "Texture.h"
#include "Sprite.h"
#include "Rect.h"
#include "Input.h"

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

	KeyBorad key{ app.getWindow() };
	if (key.createDInput()) {
		console.print("aaaaaaaaaaa\n");
	}
	if (key.create()) {
		console.print("re");
	}


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

	while (app.doEvent())
	{
		app.begin();

		m.update();
		key.update();


		if (m.getMiddleButton()) {
			time += 1.0f;
			console.print("aaaaaaafdfe\n");
		}
		
		sp3.draw(640 / 2, 480 / 2);

		for (int i = 0; i < 10; ++i) {
			sps[i].draw(50.0f + i * 45.0f, 200.0f);
		}

		sp1.rotateDraw((float)350.0f, (float)350.0f, time);

		rect.draw(app.getGraphics(), 250.0f, 250.0f, 100.0f, 100.0f, 0xFF00FFFF);

		app.end();
	}
}*/
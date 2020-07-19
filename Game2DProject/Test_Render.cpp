#include "App.h"

#include <Windows.h>

#include <vector>

#include "GameLib.h"

/*
#include "StringRender.h"
#include "Texture.h"
#include "Sprite.h"
#include "Render.h"
#include "Color.h"
*/

/*
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrefInstance, LPSTR lpCmdLine, int nCmdShow) {
	App app{ "Test Render" };

	StringRender sr;
	sr.create();

	Texture bg("img/backscreen.jpg");
	Texture chara("img/char.png");

	Sprite sp(bg);

	constexpr int size{ 50 };
	std::vector<Sprite> sps(size);
	for (int i = 0; i < size; ++i) {
		sps[i].loadTexture(chara);
	}

	while (app.doEvent()) {
		app.begin();

		sp.draw(320.0f, 240.0f);

		sr.drawText("Test", 0, 0, Color(255, 0, 10));

		for (int i = 0; i < size; ++i) {
			sps[i].draw(50.0f * i, 240.0f);
		}

		app.end();
	}
}
*/
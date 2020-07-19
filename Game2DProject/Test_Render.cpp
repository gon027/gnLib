#include "App.h"

#include <Windows.h>
#include "Texture.h"
#include "Sprite.h"
#include "Render.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrefInstance, LPSTR lpCmdLine, int nCmdShow) {
	App app{ "Test Render" };

	Texture bg;
	bg.loadTexture("img/backscreen.jpg");

	Sprite sp;
	sp.loadTexture(RenderIns->getGraphics(), bg);
	

	while (app.doEvent()) {
		app.begin();

		sp.draw(320, 240);

		app.end();
	}
}
#include "GameLib.h"
#include "Rect.h"

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
	App app{ "Test Fps" };

	RectAngle ra;

	Texture bg("img/backscreen.jpg");

	Sprite sbg(bg);

	while (app.doEvent()) {
		app.begin();

		sbg.draw(320, 240);

		ra.draw(0, 0, 100, 100, 0xFFFF00FF);

		app.end();
	}
}
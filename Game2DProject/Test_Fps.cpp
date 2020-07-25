#include "GameLib.h"
#include "Rect.h"

#include "BoxCollider.h"

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
	console::Console cl;
	cl.createConsole();

	App app{ "Test Fps" };

	RectAngle ra, rb;

	Texture bg("img/backscreen.jpg");

	Sprite sbg(bg);

	float x1 = 0;
	float y1 = 0;

	float x2 = 0;
	float y2 = 0;

	while (app.doEvent()) {
		app.begin();

		ra.draw(x1, y1, 100, 100, 0xFFFF00FF);
		rb.draw(x2, y2, 100, 100, 0xFFFFFF00);

		if (ra.collider.hitTest(rb.collider)) {
			//sbg.draw(320, 240);
			cl.print("aaa\n");
		}

		x1++;
		y1 += 0.4f;

		x2 += 0.71f;
		y2 = 2;

		app.end();
	}
}
#include "GameLib.h"

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
	App app{ "Test", 400, 400 };

	Texture bg("img/400x400.png");
	Sprite spr(bg);
	RectAngle ra;
	Line l;
	Point p;

	float x = 300;

	while (app.doEvent()) {
		app.begin();

		spr.draw((float)app.getWidth() / 2, (float)app.getHeight() / 2);

		l.draw(0, 0, 100, 100);
		p.draw(200, 200);

		if (Input::getLeftButton()) {
			x++;
		}
		else {
			x--;
		}

		ra.draw(x, 200, 50, 50, 0xffff00ff);
		
		app.end();
	}
}
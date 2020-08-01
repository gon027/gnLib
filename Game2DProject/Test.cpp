#include "GameLib.h"

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
	App app{ "Test" };

	Texture t("img/char.png");
	Sprite s(t);
	Circle c;

	float x = 300;
	float sp = 1;

	while (app.doEvent()) {
		app.begin();

		c.draw(300, 300, 100);
		c.draw(100, 100, 50);

		s.draw(100, 50);
		s.draw(200, 300);
		s.draw(200, 100);

		x += sp;
		if (x >= app.getWidth()) {
			sp = -sp;
		}
		if (x <= 0) {
			sp = -sp;
		}
		
		app.end();
	}
}
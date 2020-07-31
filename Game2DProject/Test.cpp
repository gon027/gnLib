#include "GameLib.h"
#include "include/Line/Line.h"
#include "include/Point/Point.h"

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
	App app{ "Test" };

	RectAngle ra;
	Line l;
	Point p;

	float x = 300;

	while (app.doEvent()) {
		app.begin();

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
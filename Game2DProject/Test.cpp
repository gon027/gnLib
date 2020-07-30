#include "GameLib.h"
#include "Circle.h"

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
	App app{ "Test" };

	RectAngle ra;

	float x = 300;

	while (app.doEvent()) {
		app.begin();

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
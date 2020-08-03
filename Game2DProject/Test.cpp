#include "GameLib.h"

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
	App app{"Test"};

	Circle circle;

	while (app.doEvent()) {
		app.begin();

		if (Input::getLeftButton()) {
			circle.draw(100, 300, 100);
		}

		if (Input::getRightButton()) {
			circle.draw(300, 300, 100);
		}

		if (Input::getMiddleButton()) {
			circle.draw(200, 300, 100);
		}

		app.end();
	}
}
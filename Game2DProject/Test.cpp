#include "GameLib.h"

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
	App app{"Test", 400, 400};

	Circle circle;

	while (app.doEvent()) {
		app.begin();

		if (Input::getLeftButton()) {
			circle.draw(300, 300, 100);
		}

		app.end();
	}
}
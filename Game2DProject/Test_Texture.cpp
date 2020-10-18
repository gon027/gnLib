#include "GameLib.h"

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
	App app{ "Test_Game" };

	Rect rc;
	rc.setSize(100, 75);

	float time = 0.0f;

	while (app.doEvent()) {
		app.begin();

		time += 0.5f;

		rc.setColor(Color::Blue);
		rc.setPos(Input::getPos());
		rc.setRotate(time);
		rc.draw();

		app.end();
	}
}
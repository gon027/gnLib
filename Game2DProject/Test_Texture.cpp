#include "GameLib.h"

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
	App app{ "Test_Game" };

	Rect rc;
	rc.setSize(100, 75);
	//rc.setPos(Vector2{ 320.f, 240.f });
	//rc.setRotate(0);


	float time = 0.0f;

	while (app.doEvent()) {
		app.begin();

		time += 1.0f;


		//rc.setSize(100, 100);
		rc.setColor(Color::Blue);
		rc.setPos(Input::getPos());
		rc.setRotate(time);
		rc.draw();

		Debug::drawLine(rc.collider.getMin(), rc.collider.getMax(), 5.f);


		app.end();
	}
}
#include "GameLib.h"

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
	App app{ "Test_Game" };

	Rect rc;
	rc.setSize(100, 75);
	//rc.setPos(Vector2{ 320.f, 240.f });
	//rc.setRotate(0);

	StringRender sr;

	Circle r1, r2;

	float time = 0.0f;

	while (app.doEvent()) {
		app.begin();

		time += 0.5f;

		sr.drawText(100.f + 50.f * sinf(time * 0.1f), 20, "Hello World");
		sr.drawText(0, 40, "C++");

		//rc.setSize(100, 100);
		rc.setColor(Color::Blue);
		//rc.setPos(Input::getPos());
		rc.setRotate(time);
		rc.draw();

		Debug::drawLine(rc.collider.getMin(), rc.collider.getMax(), 5.f);

		r1.setRadius(50);
		r1.setPos(Input::getPos());
		r2.setRadius(100);
		r2.setPos(300, 300);
		r1.draw();
		r2.draw();

		if (r1.collider.isHitTest(r2.collider)) {
			r1.setColor(Color::Green);
		}
		else {
			r1.setColor(Color::Black);
		}

		app.end();
	}
}
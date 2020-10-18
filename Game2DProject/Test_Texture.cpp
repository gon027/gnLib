#include "GameLib.h"

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
	App app{ "Test_Game" };

	Rect rc, rc1;
	rc.setSize(100, 75);
	rc1.setSize(50, 150);

	Circle c;
	c.setRadius(75.0f);

	float time = 0.0f;

	while (app.doEvent()) {
		app.begin();

		time += 0.5f;

		//rc.setColor(Color::Blue);
		rc.setPos(Input::getPos());
		rc.draw();

		/*rc1.setColor(Color::Blue);
		rc1.setPos(400, 100);
		rc1.draw();
		*/

		c.setPos(100, 200);
		c.draw();

		if (rc.collider.isHitTest(c.collider)) {
			c.setColor(Color::Green);
		}
		else {
			c.setColor(Color::Red);

		}

		app.end();
	}
}
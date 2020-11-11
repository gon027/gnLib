/*#include "gnLib.h"

void gnMain() {
	App app;

	Time time;

	float frame = 0;
	Sprite s("img/char.png");

	float angle = 0.f;

	while (app.doEvent()) {
		app.begin();

		time.beginTime();

		frame++;

		//if (time.deltaTime() >= 17) {
			//Sleep(1);
			//time.beginTime();
		//}

		float delta = time.deltaTime() / 1000.f;
		Debug::drawFormatText(0, 0, Color::Black, "%lf", delta);

		angle += 90.0f * delta;
		s.setRotate(angle);
		s.setPos(300, 300);
		s.draw();

		time.endTime();

		app.end();
	}

}
*/
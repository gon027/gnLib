/*#include "gnLib.h"

void gnMain() {
	App app;

	float frame = 0;
	Sprite s("img/char.png");

	float angle = 0.f;

	while (app.doEvent()) {
		app.begin();


		frame++;

		//if (time.deltaTime() >= 17) {
			//Sleep(1);
			//time.beginTime();
		//}

		float delta = Time::deltaTime();

		angle += 90.0f * delta;
		s.setRotate(angle);
		s.setPos(300, 300);
		s.draw();

		Debug::drawFormatText(0, 0, Color::Black, "%d", Time::getTime());
		Debug::drawFormatText(0, 20, Color::Black, "%d", Time::getStartTime());
		Debug::drawFormatText(0, 40, Color::Black, "%d", Time::getEndTime());
		Debug::drawFormatText(0, 60, Color::Black, "%lf", Time::deltaTime());

		app.end();
	}

}
*/
/*#include "gnLib.h"

void gnMain() {
	App app;

	timeBeginPeriod(1);

	Time time;

	while (app.doEvent()) {
		app.begin();

		time.beginTime();

		if (time.deltaTime() >= 17) {
			Sleep(1);
			time.beginTime();
		}

		Debug::drawFormatText(0, 0, Color::Black, "%d", time.deltaTime());

		time.endTime();

		app.end();
	}

}
*/
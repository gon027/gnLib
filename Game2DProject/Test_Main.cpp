#include "gnLib.h"

void gnMain() {
	App app;

	Rect r;

	while (app.doEvent()) {
		app.begin();

		if (Input::getLeftButton()) {
			break;
		}

		app.end();
	}
}

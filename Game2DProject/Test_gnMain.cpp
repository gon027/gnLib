#include "gnLib.h"

void gnMain() {
	App app;

	while (app.doEvent()) {
		app.begin();

		app.end();
	}
}
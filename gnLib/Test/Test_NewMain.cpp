#include "../gnLib.h"

void gnMain() {
	App::init("Window", 640, 480);

	while (App::update()) {
		App::begin();

		App::end();
	}
}
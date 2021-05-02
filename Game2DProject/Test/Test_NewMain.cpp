#include "../gnLib.h"

void gnMain() {
	App::init("Window", 640, 480);

	while (App::update()) {
		App::begin();

		if (Input::getKey(Key::A)) {
			Debug::drawCircle(App::getWindowSize().half(), 100.0f);
		}

		App::end();
	}
}
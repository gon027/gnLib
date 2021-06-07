#include <gnLib.h>

void gnMain() {
	App::init("Window", 640, 480);

	while (App::update()) {
		App::begin();

		if (Input::getKeyDown(Key::A)) {
			App::setColor(Color{ 0, 255, 0 });
		}

		if (Input::getKeyDown(Key::S)) {
			App::setColor(Color{ 255, 0, 255 });
		}

		if (Input::getKeyDown(Key::D)) {
			App::setTitle("OSOIIII!!!!");
		}

		App::end();
	}
}
/*#include "gnLib.h"

void Test_Key() {

	if (Input::getKeyDown(Key::A)) {
		Debug::drawText(0, 0, "AAA");
	}

	if (Input::getKeyDown(Key::S)) {
		Debug::drawText(0, 20, "SSS");
	}

	if (Input::getKey(Key::D)) {
		Debug::drawText(0, 40, "DDD");
	}

	if (Input::getKey(Key::W)) {
		Debug::drawText(0, 60, "WWW");
	}

	if (Input::getKeyUp(Key::A)) {
		Debug::drawText(0, 80, "AAAAA");
	}

	if (Input::getKeyUp(Key::S)) {
		Debug::drawText(0, 100, "SSSSS");
	}

	if (Input::getKeyUp(Key::D)) {
		Debug::drawText(0, 120, "DDDDD");
	}

	if (Input::getKeyUp(Key::W)) {
		Debug::drawText(0, 140, "WWWWW");
	}
}

void gnMain() {
	App app;

	Point pt;

	while (app.doEvent()) {
		app.begin();

		
		for (int i = 0; i < 100; ++i) {
			pt.setColor(Color::Green);
			pt.setPos(Vector2{320.f + i, 240.f});
			pt.draw();
		}

		app.end();
	}
}
*/
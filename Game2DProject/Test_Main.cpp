#include "gnLib.h"

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

#include <vector>
using namespace std;

void gnMain() {
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	App app;

	Texture tex{ "img/char.png" };
	Sprite spr{ tex };
	auto aaa = Texture::spriteTexture(tex, 4, 4);

	int frame = 0;

	while (app.doEvent()) {
		app.begin();

		frame++;
		frame = frame % 16;

		spr.setPos({ 300.0f, 200.0f });
		spr.draw();
		spr.draw(aaa[frame]);

		app.end();
	}
}

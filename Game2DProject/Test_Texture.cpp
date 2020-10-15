#include "GameLib.h"

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
	App app{ "Test_Game" };

	Texture t{ "img/backscreen.jpg" }, c1{ "img/char.png" };
	Sprite s{ t }, sc{ c1 };

	while (app.doEvent()) {
		app.begin();

		s.setPos(app.getPos().half());
		s.draw();

		sc.setPos(Input::getPos());
		sc.draw();

		Debug::drawText(0, 0, t.toString().c_str());

		app.end();
	}
}
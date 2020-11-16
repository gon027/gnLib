#include "gnLib.h"

/*
void gnMain() {
	App app;

	TextureSPtr texture = Texture::createTexture("img/MapData.png");
	Sprite sp, a;
	sp.setTexture(texture);
	a.setTexture(texture);
	
	while (app.doEvent()) {
		app.begin();

		sp.setPos(600, 600);
		sp.draw();

		a.setPos(600, 600);
		a.draw();

		Debug::drawFormatText(0.f, 0.f, Color::Black, "%d", texture.use_count());

		app.end();
	}
}
*/
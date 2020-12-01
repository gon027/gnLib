/*#include "gnLib.h"

void gnMain() {
	App app;

	TextureSPtr texture = Texture::createTexture("img/char.png");
	Sprite sp, sp2, sp3;
	sp.setTexture(texture);
	sp2.setTexture(texture);
	sp3.setTexture(texture);
	
	while (app.doEvent()) {
		app.begin();

		//sp.draw(Vector2::Zero, Vector2{ 2.0f, 0.5f }, 0.0f);
		sp2.draw(Vector2{ 300.f, 300.f }, Vector2::One, 0.0f);
		sp3.draw(Vector2{ 300.f, 300.f }, Vector2::One, 0.0f, false);

		app.end();
	}
}*/
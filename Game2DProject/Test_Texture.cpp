#include "gnLib.h"

void gnMain() {
	App app;

	TextureSPtr texture = Texture::createTexture("img/char.png");
	Sprite sp, sp2, sp3;
	sp.setTexture(texture);
	sp2.setTexture(texture);
	sp3.setTexture(texture);
	
	while (app.doEvent()) {
		app.begin();

		sp.draw(Vector2::Zero, Vector2{ 2.0f, 0.5f }, 0.0f, true, true);
		sp2.draw(Vector2{ 100.f, 200.f }, Vector2::One, 0.0f, true);
		sp3.draw(Vector2{ 200.f, 300.f }, Vector2::One, 0.0f, true);

		app.end();
	}
}
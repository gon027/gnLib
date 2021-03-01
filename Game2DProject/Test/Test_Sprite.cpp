/*#include "../gnLib.h"

void gnMain() {
	App app;

	TextureSPtr tp = Texture::createTexture("Assets/img/char.png");
	AnimSprite as{8, 8, 30.0f};
	as.setTexture(tp);

	while (app.update()) {
		app.begin();

		as.draw({ 300, 300 }, { 1, 1 }, 0.0f);

		app.end();
	}
}*/
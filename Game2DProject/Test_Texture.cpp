#include "gnLib.h"

/*void gnMain() {
	App app;

	TextureSPtr texture = Texture::createTexture("img/char.png");
	//TextureRegion vt = Texture::spriteTexture(texture, 20, 20);

	// Texture[] ts = spliteTexture("", 32, 32, 5, 5);
	// sprite.draw(ts[0], one, one, 0.0f);

	Sprite sp{};
	sp.setTexture(texture);

	int a = 0;

	
	while (app.doEvent()) {
		app.begin();

		//sp.draw({100, 100}, { 1, 1 }, 0.0f, false);

		for (int i = 0; i < 100; ++i) {
			for (int j = 0; j < 100; ++j) {
				sp.draw(
					{ 50.f * i, 50.f * j },
					Vector2::One,
					0.0f
				);
			}
		}

		//Debug::drawFormatText(0, 20, Color::Black, "%d", texture->getWidth());
		//Debug::drawFormatText(0, 40, Color::Black, "%d", texture->getHeight());
		Sleep(1);

		app.end();
	}
}
*/
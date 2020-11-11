#include "gnLib.h"

void gnMain() {
	App app;

	Texture texture("img/MapData.png");
	auto a = Texture::spriteTexture(texture, 32, 32);
	Sprite sp{ texture };
	
	int frame = 0;

	while (app.doEvent()) {
		app.begin();

		sp.setPos(200, 100);
		sp.draw(a[0], false);

		Debug::drawFormatText(0, 0, Color::Red, "%d, %d", texture.getWidth(), texture.getWidth());
		Debug::drawFormatText
		(0, 20, Color::Red, "%lf, %lf", float(texture.getWidth()) / 32.f, float(texture.getHeight()) / 32.f);
		Debug::drawFormatText(0, 40, Color::Red, "%d, %d, %d, %d", a[0].left, a[0].top, a[0].right, a[0].bottom);
		Debug::drawFormatText(0, 60, Color::Red, "%d", a.size());

		app.end();
	}
}

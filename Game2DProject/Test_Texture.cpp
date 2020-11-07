#include "gnLib.h"

void gnMain() {
	App app;

	Texture texture("img/char.png");
	Sprite sprite{ texture };

	while (app.doEvent()) {
		app.begin();

		sprite.setPos(300, 300);
		sprite.draw(false);

		app.end();
	}
}
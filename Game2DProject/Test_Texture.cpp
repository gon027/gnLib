#include "gnLib.h"
/*
class DivSprite {
public:
	DivSprite();
	~DivSprite() = default;

	static DivSprite div(Texture _texture, int _allNum, int _xNum, int _yNum, int _xSize, int _ySize) {

	}

private:
	Sprite sprite;
};
*/

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
//#include "gnLib.h"

/*
class DivSprite {
public:
	DivSprite();
	~DivSprite() = default;

	static DivSprite div(Texture _texture, int _allNum, int _xNum, int _yNum, int _xSize, int _ySize) {

	}

	void setPos();
	void setPos();

	void setScale()
	void setScale();

	void setRotate(float _angle);

	void draw(int _index);

private:
	Sprite sprite;
};
*/
/*
void gnMain() {
	App app;

	Texture texture("img/char.png");
	Sprite sprite{ texture };

	Sprite sprite2{ "img/backscreen.jpg" };

	float frame = 0.0f;

	while (app.doEvent()) {
		app.begin();
		frame += 0.01f;

		//sprite.setRotate(frame);
		sprite.setScale({ cosf(frame) * 2.0f, 1 });
		sprite.setPos(300, 300);
		sprite.draw(true);

		sprite2.setScale({ 0.5f, cosf(frame) * 2.0f });
		sprite2.setPos(100, 100);
		sprite2.draw(false);

		app.end();
	}
}
*/
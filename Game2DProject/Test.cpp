#include "GameLib.h"

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
	App app{"Test"};

	Texture tex("img/backscreen.jpg");
	Sprite sp(tex);
	Circle circle;
	RectAngle ra;
	Line line;

	while (app.doEvent()) {
		app.begin();

		//sp.draw(app.getWidth() / 2, app.getHeight() / 2);
		
		circle.set(Vector2::Up);

		auto v = Input::getPosition();

		line.setColor(Color::Red);
		line.setWeight(10);
		line.setPos(Vector2::Zero, v);
		line.draw();
		
		if (Input::getLeftButton()) {
			circle.setColor(Color::Red);
			circle.draw(v.x, v.y, 100);
		}

		if (Input::getRightButton()) {
			ra.setPos(v);
			ra.setSize(100);
			ra.setColor(Color::White);
			ra.draw();
		}

		app.end();
	}
}
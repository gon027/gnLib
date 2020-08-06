#include "GameLib.h"

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
	App app{"Test"};

	Texture tex("img/backscreen.jpg");
	Sprite sp(tex);
	Circle circle;

	while (app.doEvent()) {
		app.begin();

		sp.draw(app.getWidth() / 2, app.getHeight() / 2);
		
		circle.set(Vector2::Up);
		circle.draw();

		auto v = Input::getPosition();
		
		if (Input::getLeftButton()) {
			circle.setColor(Color::Red);
			circle.draw(v.x, v.y, 100);
		}

		if (Input::getRightButton()) {
			circle.setColor(Color::Green);
			circle.setRadius(100);
			circle.set(Vector2(v.x, v.y));
			circle.draw();

		}

		app.end();
	}
}
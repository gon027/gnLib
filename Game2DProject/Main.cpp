#include "GameLib.h"

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
	
	App app{ "Main Window" };

	float x = app.getWidth() / 2.0f;
	float y = app.getHeight() / 2.0f;

	float speedX = 1.0f;
	float speedY = 2.5f;

	Texture texture{ "img/background.png" };
	Sprite sprite{ texture };

	Circle circle;
	circle.setColor(Color::Green);
	circle.setRadius(50);

	while (app.doEvent()) {
		app.begin();

		sprite.setPos(app.getWidth() / 2.0f, app.getHeight() / 2.0f);
		sprite.draw();

		circle.setPos(x, y);
		circle.draw();

		//Debug::drawLine(Vector2(0, 0), Vector2(100, 100));
		Debug::drawCircle(Input::getPosition(), 50);

		x += speedX;
		y += speedY;

		if (x + 50 >= app.getWidth() || x - 50 <= 0) {
			speedX = -speedX;
		}

		if (y + 50 >= app.getHeight() || y - 50 <= 0) {
			speedY = -speedY;
		}

		app.end();
	}
	
}
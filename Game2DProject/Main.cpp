#include "GameLib.h"

#include <string>
using namespace std;

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
	
	App app{ "Main Window" };

	float x = app.getWidth() / 2.0f;
	float y = app.getHeight() / 2.0f;

	float speedX = 5.0f;
	float speedY = 2.5f;

	Texture texture{ "img/background.png" };
	Sprite sprite{ texture };

	Circle circle, c2;
	circle.setColor(Color::Green);
	circle.setRadius(50);

	RectAngle r1{ Vector2{300, 200}, 75.0f, 100.0f}, r2{ Vector2{150, 150}, 50.f, 50.f };

	c2.setColor(Color::Red);
	c2.setRadius(20);

	while (app.doEvent()) {
		app.begin();

		sprite.setPos(app.getWidth() / 2.0f, app.getHeight() / 2.0f);
		sprite.draw();

		//x += speedX;

		//circle.setPos(x, y);
		circle.draw();

		c2.setPos(50, 50);
		c2.draw();

		r1.setPos(Input::getPosition());
		//r1.setPos(x, y, 0);
		r1.setColor(Color::Red);
		r1.draw();

		r2.setPos(r1.getPos());
		r2.draw();

		//Debug::drawLine(Vector2(0, 0), Vector2(100, 100));
		//Debug::drawCircle(Input::getPosition(), 20);

		
		//y += speedY;

		//if (r1.collider.getMax().x > app.getWidth()) {
			//speedX = -speedX;
		//}

		//if (y + 75 >= app.getHeight() || y <= 0) {
			//speedY = -speedY;
		//}
		

		//if (r1.collider.hitTest(r2.collider)) {
			//speedX += 3;
			//speedX = -speedX;
			//r1.setColor(Color::Green);
		//}

		app.end();
	}
	
}
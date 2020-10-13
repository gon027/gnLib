#include "GameLib.h"
#include <string>
using namespace std;

/*
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
	App app{"Test"};

	float t = 0;
	Texture tex("img/backscreen.jpg");
	Sprite sp(tex);
	Circle circle;
	RectAngle ra;
	Line line;

	while (app.doEvent()) {
		app.begin();

		auto v = Input::getPos();

		sp.setPos(app.getWidth() / 2, app.getHeight() / 2);
		//sp.setScale(0.5f, 0.5f);
		sp.draw();
		
		circle.setPos(Vector2::Up);

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
*/
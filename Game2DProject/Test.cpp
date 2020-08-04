#include "GameLib.h"

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
	App app{"Test"};

	Circle circle;
	
	//circle.setRadius(100);
	//circle.setColor(Color::Black);

	while (app.doEvent()) {
		app.begin();
		
		auto v = Input::getPosition();
		
		if (Input::getLeftButton()) {
			//circle.setPosition(v.x, v.y);
			circle.setColor(Color::Red);
			circle.draw(v.x, v.y, 100);
		}

		if (Input::getRightButton()) {
			//circle.draw(300, 300, 100);
			circle.setColor(Color::Green);
			circle.draw(v.x, v.y, 100);

		}

		if (Input::getMiddleButton()) {
			//circle.draw(200, 300, 100);
		}
		

		app.end();
	}
}
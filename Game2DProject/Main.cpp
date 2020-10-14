#include "GameLib.h"

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
	
	App app{};

	Texture texture{ "img/background.png" };
	Sprite sprite{ texture };

	//Line line{ Vector2{0, 0}, Vector2{app.getWidth(), app.getHeight()} };

	Point p, p2;
	RectAngle re{ Vector2{100.0f, 100.0f}, 50.0f, 50.0f };

	while (app.doEvent()) {
		app.begin();
		
		sprite.setPos(app.getWidth() / 2.0f, app.getHeight() / 2.0f);
		sprite.draw();

		//line.setWeight(10);
		//line.setColor(Color::Green);
		//line.draw();

		re.draw();

		p2.setColor(Color::Red);
		p2.setPos(Vector2{ 250, 250});
		p2.draw();

		p.setPos(Input::getPos());
		p.draw();

		if (p.collider.isHitTest(p2.collider)) {
			re.setColor(Color::Green);
		}
		else {
			re.setColor(Color::Red);
		}

		//Debug::drawRect(Input::getPos(), Color::Black);
		//Debug::drawLine(Input::getPos(), Vector2{ 0.f, 0.f });
		//Debug::drawRect(Vector2{ app.getWidth(), app.getHeight() });

		app.end();
	}
	
}
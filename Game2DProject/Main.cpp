#include "GameLib.h"

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
	
	App app{""};

	Texture texture{ "img/background.png" };
	Sprite sprite{ texture };

	Line line{ Vector2{0, 0}, Vector2{app.getWidth(), app.getHeight()} };

	while (app.doEvent()) {
		app.begin();
		
		sprite.setPos(app.getWidth() / 2.0f, app.getHeight() / 2.0f);
		sprite.draw();

		line.setWeight(10);
		line.setColor(Color::Green);
		line.draw();

		//Debug::drawRect(Input::getPos(), Color::Black);
		//Debug::drawLine(Input::getPos(), Vector2{ 0.f, 0.f });
		//Debug::drawRect(Vector2{ app.getWidth(), app.getHeight() });

		app.end();
	}
	
}
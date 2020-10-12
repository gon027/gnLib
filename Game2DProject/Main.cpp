#include "GameLib.h"
#include "Polygon.h"

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


	float a{ 100.0f };
	gnLib::Polygon po{
		{
			Vertex2D{0.0, 0.0f, 0.f, 1.0f},
			Vertex2D{a, 0.0f, 0.f, 1.0f},
			Vertex2D{0.0f, a, 0.f, 1.0f},
			Vertex2D{a, a, 0.f, 1.0f},
		}
	};

	RectAngle r1{ Vector2{300, 200}, 75.0f, 100.0f}, r2{ Vector2{150, 150}, 50.f, 50.f };

	c2.setColor(Color::Red);
	c2.setRadius(20);

	while (app.doEvent()) {
		app.begin();
		
		//sprite.setPos(app.getWidth() / 2.0f, app.getHeight() / 2.0f);
		//sprite.draw();

		//circle.setPos(x, y);
		//circle.draw();

		//c2.setPos(50, 50);
		//c2.draw();

		r1.setPos(Input::getPosition());
		r1.draw();

		r2.setPos(Vector2{ 250.f, 250.f });
		r2.draw();
		
		if (r1.collider.boxHitTest(r2.collider)) {
			r1.setColor(Color::Green);
		}
		else {
			r1.setColor(Color::Red);
		}

		app.end();
	}
	
}
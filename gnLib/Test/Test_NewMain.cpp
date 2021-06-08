#include <gnLib.h>

void gnMain() {
	App::init("Window", 640, 480);

	TextureSPtr t{ new Texture("Assets/img/char.png") };


	while (App::update()) {
		App::begin();

		if (Input::getKeyDown(Key::A)) {
			App::setColor(Color{ 0, 255, 0 });
		}

		if (Input::getKeyDown(Key::S)) {
			App::setColor(Color{ 255, 0, 255 });
		}

		if (Input::getKeyDown(Key::D)) {
			App::setTitle("OSOIIII!!!!");
		}

		/*
		Sprite s;
		s.setTexture(t);
		static float a = 0.0f;
		a += Time::deltaTime();
		s.draw({0, 0}, Vector2::One, 0, false, true);
		*/


		Line l;
		l.setColor(Color::Blue);
		l.setWeight(10.0f);
		l.setPos(Input::getPos(), { 300, 300 });
		//l.setPos({ 100, 100 }, { 300, 300 });
		l.draw();

		
		

		/*
		Rect r;
		r.setColor(Color::Red);
		r.setSize(200.0);
		r.setPos({ 300, 300 });
		r.draw();
		*/


		App::end();
	}
}
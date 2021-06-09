#include <gnLib.h>

void gnMain() {
	App::init("Window", 640, 480);

	//TextureSPtr t{ new Texture("Assets/img/char.png") };

	//App::setWindowPosition(600, 300);

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

		
		static float a = 0.0f;
		a += Time::deltaTime();
		/*
		Sprite s;
		s.setTexture(t);
		s.draw({ 0, 0 }, Vector2::One, a, false);
		s.draw({300, 0}, Vector2::One, a, false, true);
		*/

		/*
		Line l;
		for (int i = 0; i < 10; ++i) {
			l.setColor(Color::Red);
			l.setWeight(10.0f);
			l.setPos({ float(i * 50), 0.0f}, { float(i * 50), 500 });
			l.draw();
		}

		for (int j = 0; j < 10; ++j) {
			l.setColor(Color::Blue);
			l.setWeight(10.0f);
			l.setPos({ 0, float(j * 50) }, { 500, float(j * 50) });
			l.draw();
		}
		*/
		
		std::vector<Vertex2D> ab{ {100, 100}, { 300, 100 }, { 150, 200 }, { 350, 200 }, { 200, 400 }, { 400, 400 }};
		gnLib::Polygon p{ ab };
		p.setColor(Color::Blue);
		//p.translate({ a, 0.0f });
		p.scale({2.0f, 1.0f});
		//p.rotate(a);
		p.draw();

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
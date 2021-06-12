#include <gnLib.h>

void gnMain() {
	App::init("Window", 640, 480);

	while (App::update()) {
		App::begin();

		if (Input::getKeyDown(Key::A)) {
			App::setColor(Color{ 0, 255, 0 });
		}

		if (Input::getKeyDown(Key::S)) {
			App::setColor(Color{ 255, 0, 255 });
		}

		if (Input::getKeyDown(Key::D)) {
			App::setTitle("CaptionïœçX");
		}

		static float timer = 0.0f;
		timer += Time::deltaTime();
		
		/* ãå
		std::vector<Vertex2D> vertex{
			{ 100, 100 }, { 300, 100 }, { 150, 200 },
			{ 350, 200 }, { 200, 400 }, { 400, 400 }
		};
		gnLib::Polygon p{ vertex };
		p.setColor(Color::Blue)
			.scale({2.0f, 1.0f})
			.rotate(timer * 10.0)
			.draw();
		
		*/

		// êV
		std::vector<Vertex2D> vertex{
			{ 100, 100 }, { 300, 100 }, { 150, 200 },
			{ 350, 200 }, { 200, 400 }, { 400, 400 }
		};
		gnLib::Polygon p{ vertex };
		p.setColor(Color::Blue)
			.scale({2.0f, 1.0f})
			.rotate(timer * 5.0f)
			.draw();
		
		Rect r{};
		r.setPos(Input::getPos())
			.setSize(100, 100)
			.setRotate(timer * 20.0f)
			.setColor(Color::Blue)
			.draw();
			
		Circle c{};
		c.setPos({ 300, 300 })
			.setColor(Color::Red)
			.setRadius(100)
			.draw();

		auto size = App::getWindowSize();
		Line line{ {0, 0}, {size.x, size.y } };
		line.setWeight(5.0f)
			.setColor(Color::White)
			.draw();

		for (float i{ 0 }; i < 100; ++i) {
			Point p{ {i, 240} };
			p.setColor(Color::Green).draw();
		}

		App::end();
	}
}
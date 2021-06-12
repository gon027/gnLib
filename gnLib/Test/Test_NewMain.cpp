#include <gnLib.h>

#include <include/Timer.h>

void gnMain() {
	App::init("Window", 640, 480);

	Timer time{ 5.0f };

	std::vector<Color> colors{
		{Color{0, 255, 255}},
		{Color::Blue},
	};

	while (App::update()) {
		App::begin();

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
		p.scale({2.0f, 1.0f})
		p.rotate(timer * 10.0)
		p.draw();
		
		*/

		// êV
		std::vector<Vertex2D> vertex{
			{ 100, 100 }, { 300, 100 }, { 150, 200 },
			{ 350, 200 }, { 200, 400 }, { 400, 400 }
		};
		gnLib::Polygon p{ vertex };
		p.setColor(Color::Green)
			.rotate(timer)
			.draw();
		
		Rect r{};
		r.setPos(Input::getPos())
			.setSize(100, 100)
			.setRotate(timer * 20.0f)
			.setColor(Color{255, 0, 255})
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

		static int index = 0;
		time.countDown();
		if (time.isTimeUp(5.0f)) {
			time.reset();
			App::setColor(colors[((++index) % 2)]);
		}

		Debug::drawFormatText(0, 00, Color::Black, "Time = %.5lf", time.nowTime());

		App::end();
	}
}
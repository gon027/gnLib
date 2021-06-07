#include "../gnLib.h"

void gnMain() {
	App::init("Window", 640, 480);

	while (App::update()) {
		App::begin();

		Line l;
		l.setPos({ 0, 0 }, { 400, 400 });
		l.setColor(Color::Green);
		l.draw();

		Rect r;
		r.setPos({ 300, 300 });
		r.setColor(Color::Red);
		r.setSize(50, 50);
		r.draw();

		Circle c;
		c.setPos({ 200, 200 });
		c.setColor(Color::Blue);
		c.setRadius(150.0f);
		c.draw();

		Point p;
		p.setPos({ 400, 100 });
		p.setColor(Color::Blue);
		p.draw();
	

		App::end();
	}
}
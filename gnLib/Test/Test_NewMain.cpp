#include "../gnLib.h"

class Shape {
public:
	Shape(const Vector2& _pos)
		: pos(_pos), size() {}

	void draw() {
		r.setPos(pos);
		bos.update(pos, size.x, size.y);
		r.draw();
	}

	void setSize(const Vector2& _size) {
		size = _size;
	}

	ICollider& get() {
		return bos;
	}

	Rect r;
	BoxCollider bos;
	Vector2 pos;
	Vector2 size;
};

struct C{
	Circle c;
	CircleCollider cc;
};

void gnMain() {
	App::init("Window", 640, 480);

	while (App::update()) {
		App::begin();

		Shape s1(Input::getPos()), s2({ 300, 300 });

		s1.r.setPos(Input::getPos());
		s1.r.setColor(Color::Green);
		s1.r.setSize(30, 40);
		s1.bos.update(s1.pos, 30, 40);
		s1.r.draw();
		
		s2.r.setPos({300, 300});
		s2.r.setColor(Color::Red);
		s2.r.setSize(50, 100);
		s2.bos.update(s2.pos, 50, 100);
		s2.r.draw();

		/*if (Collision2D::isCollision(s1.get(), s2.get())) {
			Debug::drawText(0, 0, "aaaa");
		}*/

		/*
		C c;
		c.c.setPos({ 200, 400 });
		c.c.setRadius(120);
		c.c.setColor(Color::Blue);
		c.cc.update({ 200, 400 }, 120);
		c.c.draw();

		C v;
		v.c.setPos(Input::getPos());
		v.c.setRadius(30);
		v.c.setColor(Color::Blue);
		v.cc.update(Input::getPos(), 30);
		v.c.draw();


		if (Collision2D::isCollision(v.cc, c.cc)) {
			Debug::drawText(0, 20, "aafdafeaaa");
		}
		*/

		App::end();
	}
}
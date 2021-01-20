/*#include "gnLib.h"

class Test : public Object {
public:
	Test() : rect() {}
	Rect rect;
	void setPos(const Vector2& a) {
		transform.setPos(a);
	}

	void draw() {
		rect.setPos(transform.pos);
		rect.draw();
	}
};

void gnMain() {
	App a;
	
	Test test;
	
	while (a.doEvent()) {
		a.begin();

		test.rect.setSize(100.f);
		test.rect.setColor(Color::Black);
		test.transform.setPos(Input::getPos());
		test.draw();

		a.end();
	}
}
*/
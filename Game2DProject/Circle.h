#ifndef CIRCLE_H
#define CIRCLE_H

class Object {
public:
	virtual ~Object() {}

	void setActive(bool _active) {
		isActive = _active;
	}

	bool getActive() { return isActive; }

private:
	bool isActive;
};


class Circle : public Object{
public:
	Circle();
	~Circle() = default;

	void draw(float _x, float _y, float _radius);

private:
	float x;
	float y;
	float radius;
};

#endif // !CIRCLE_H

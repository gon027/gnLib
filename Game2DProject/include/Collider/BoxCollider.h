#ifndef BOXCOLLIDER_H
#define BOXCOLLIDER_H

#include "ICollider.h"
#include "../Vector/Vector2.h"
using namespace gnLib;

class BoxCollider : public ICollider{
public:
	BoxCollider(Vector2& _pos, Vector2& _min, Vector2& _max);
	BoxCollider() = default;
	~BoxCollider() = default;

	bool hitTest(BoxCollider& _other);

	void update(float _x, float _y, float _xSize, float _ySize);
	void update(const Vector2& _pos, const Vector2& _min, const Vector2& _max);

	Vector2 getPosition() const;
	Vector2 getMin() const;
	Vector2 getMax() const;
	Vector2 gerSize() const;

	virtual ColliderType getType() override;

private:
	Vector2 center;
	Vector2 minPos;
	Vector2 maxPos;
	Vector2 size;
};

#endif // !BOXCOLLIDER_H

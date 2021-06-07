#include <Collider/CircleCollider.h>
#include <Collider/BoxCollider.h>
#include <Common/Math.h>

namespace gnLib {

	CircleCollider::CircleCollider()
		: position(Vector2::Zero)
		, radius(0)
	{
	}

	CircleCollider::CircleCollider(const Vector2& _vector, float _radius)
		: position(_vector)
		, radius(_radius)
	{
	}

	CircleCollider::CircleCollider(float _x, float _y, float _r)
		: position(Vector2{ _x, _y })
		, radius(_r)
	{

	}

	ColliderType CircleCollider::getType() const
	{
		return ColliderType::Circle;
	}

	void CircleCollider::update(const Vector2& _vector, float _radius)
	{
		position.setPos(_vector);
		radius = _radius;
	}

	const Vector2& CircleCollider::getPos() const
	{
		return position;
	}

	const float CircleCollider::getRadius() const
	{
		return radius;
	}

}
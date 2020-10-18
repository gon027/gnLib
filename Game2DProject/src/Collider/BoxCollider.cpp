#include "../../include/Collider/BoxCollider.h"
#include "../../include/Debug/Debug.h"

namespace gnLib {

	bool BoxCollider::isHitTest(const BoxCollider& _collider)
	{
		const auto& cb = _collider.getBounds();

		if (bounds.maxPos.x >= cb.minPos.x
			&& bounds.minPos.x <= cb.maxPos.x
			&& bounds.maxPos.y >= cb.minPos.y
			&& bounds.minPos.y <= cb.maxPos.y)
		{
			return true;
		}

		return false;
	}

	bool gnLib::BoxCollider::isHitTest(const CircleCollider& _collider)
	{


		return false;
	}

	void BoxCollider::update(const Vector2& _v, float _width, float _height)
	{
		auto w = _width / 2.0f;
		auto h = _height / 2.0f;

		bounds.center = _v;
		bounds.minPos.setPos(_v.x - w, _v.y - h);
		bounds.maxPos.setPos(_v.x + w, _v.y + h);
		bounds.size.setPos(_width, _height);

		Debug::drawLine(bounds.minPos, Vector2{ bounds.maxPos.x, bounds.minPos.y }, 5.0f);
		Debug::drawLine(bounds.minPos, Vector2{ bounds.minPos.x, bounds.maxPos.y }, 5.0f);
		Debug::drawLine(Vector2{ bounds.maxPos.x, bounds.minPos.y }, bounds.maxPos, 5.0f);
		Debug::drawLine(Vector2{ bounds.minPos.x, bounds.maxPos.y }, bounds.maxPos, 5.0f);
		Debug::drawText(0, 0, bounds.size.toString().c_str());
	}

	Bounds BoxCollider::getBounds() const
	{
		return bounds;
	}

	ColliderType BoxCollider::getType()
	{
		return ColliderType::BOX;
	}

}
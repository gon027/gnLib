#include <Collider/Collision2D.h>
#include <Collider/BoxCollider.h>
#include <Collider/CircleCollider.h>
#include <Common/Math.h>

namespace gnLib {

	namespace Collision2D {

		bool isCollision(const BoxCollider& _left, const BoxCollider& _right)
		{
			auto& leftBounds = _left.getBounds();
			auto& rightBounds = _right.getBounds();

			return leftBounds.maxPos.x >= rightBounds.minPos.x
				&& leftBounds.minPos.x <= rightBounds.maxPos.x
				&& leftBounds.maxPos.y >= rightBounds.minPos.y
				&& leftBounds.minPos.y <= rightBounds.maxPos.y;
		}

		bool isCollision(const BoxCollider& _left, const CircleCollider& _right)
		{
			auto& box = _left.getBounds();
			auto& circle = _right.getPos();
			auto radius = _right.getRadius();

			if (circle.x > box.minPos.x && circle.x < box.maxPos.x
				&& circle.y > box.minPos.y - radius && circle.y < box.maxPos.y + radius) {
				return true;
			}

			if (circle.x > box.minPos.x - radius && circle.x < box.maxPos.x + radius
				&& circle.y > box.minPos.y && circle.y < box.maxPos.y) {
				return true;
			}

			float r = radius * radius;

			float rx = box.minPos.x - circle.x;
			float ry = box.minPos.y - circle.y;
			float d = dist(rx, ry);
			if (d < r)return true;

			rx = box.maxPos.x - circle.x;
			ry = box.minPos.y - circle.y;
			d = dist(rx, ry);
			if (d < r)return true;

			rx = box.maxPos.x - circle.x;
			ry = box.maxPos.y - circle.y;
			d = dist(rx, ry);
			if (d < r)return true;

			rx = box.minPos.x - circle.x;
			ry = box.maxPos.y - circle.y;
			d = dist(rx, ry);
			if (d < r)return true;

			return false;
		}

		bool isCollision(const CircleCollider& _left, const BoxCollider& _right)
		{
			return isCollision(_right, _left);
		}

		bool isCollision(const CircleCollider& _left, const CircleCollider& _right)
		{
			auto dist = _right.getPos() - _left.getPos();
			auto c = dist.magnitude();
			auto r = _right.getRadius() + _left.getRadius();

			return c <= r * r;
		}

	}
}
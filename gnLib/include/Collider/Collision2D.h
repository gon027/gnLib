#ifndef COLLISION2D_H
#define COLLISION2D_H

namespace gnLib {

	class ICollider;
	class BoxCollider;
	class CircleCollider;

	namespace Collision2D {

		/// <summary>
		/// BoxCollider vs BoxCollider
		/// </summary>
		/// <param name="_left"> BoxCollider </param>
		/// <param name="_right"> BoxCollider </param>
		/// <returns></returns>
		extern bool isCollision(const BoxCollider& _left, const BoxCollider& _right);

		/// <summary>
		/// BoxCollider vs CircleCollider
		/// </summary>
		/// <param name="_left"> BoxCollider </param>
		/// <param name="_right"> CircleCollider </param>
		/// <returns></returns>
		extern bool isCollision(const BoxCollider& _left, const CircleCollider& _right);

		/// <summary>
		/// CircleCollider vs BoxCollider
		/// </summary>
		/// <param name="_left"> CircleCollider </param>
		/// <param name="_right"> BoxCollider </param>
		/// <returns></returns>
		extern bool isCollision(const CircleCollider& _left, const BoxCollider& _right);

		/// <summary>
		/// CircleCollider vs CircleCollider
		/// </summary>
		/// <param name="_left"> CircleCollider </param>
		/// <param name="_right"> CircleCollider </param>
		/// <returns></returns>
		extern bool isCollision(const CircleCollider& _left, const CircleCollider& _right);

		//extern bool isCollision(const ICollider& _left, const ICollider& _right);
	}
}

#endif // !COLLISION2D_H
#ifndef TRANSFORM_H
#define TRANSFORM_H

#include "../Common/Lib.h"
#include "../Vector/Vector2.h"

namespace gnLib {

	class Transform {
	public:
		// À•W‚ğİ’è‚·‚é
		void setPos(float _x, float _y);
		void setPos(const Vector2& _v);

		// ‰æ‘œ‚Ì‘å‚«‚³‚ğİ’è‚·‚é
		void setScale(float _sx, float _sy);
		void setScale(const Vector2& _v);

		// ‰æ‘œ‚ÌŠp“x‚ğİ’è‚·‚é
		void setRotate(float _angle);

	public:
		Vector2 pos;
		Vector2 scale;
		float angle;
	};

}

#endif // !TRANSFORM_H

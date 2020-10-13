#ifndef POINT_H
#define POINT_H

#include "../Object/Object.h"

namespace gnLib {

	class Point : public Object{
	public:
		Point() = default;
		~Point() = default;

		void draw(float _x, float _y);
	};

}

#endif // !POINT_H

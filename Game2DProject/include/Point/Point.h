#ifndef POINT_H
#define POINT_H

namespace gnLib {
	class Point {
	public:
		Point() = default;
		~Point() = default;

		void draw(float _x, float _y);
	};
}

#endif // !POINT_H

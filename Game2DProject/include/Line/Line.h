#ifndef LINE_H
#define LINE_H

namespace gnLib {
	class Line {
	public:
		Line() = default;
		~Line() = default;

		void draw(float _x1, float _y1, float _x2, float _y2);
	};
}

#endif // !LINE_H

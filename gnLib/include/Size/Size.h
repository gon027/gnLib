#ifndef SIZE_H
#define SIZE_H

namespace gnLib {

	struct Size {
		Size(int _width = 0, int _height = 0)
			: width(_width)
			, height(_height)
		{ }

		int width;
		int height;
	};
}

#endif // !SIZE_H

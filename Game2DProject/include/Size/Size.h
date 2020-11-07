#ifndef SIZE_H
#define SIZE_H

namespace gnLib {
	struct Size {
	public:
		Size(int _width = 0, int _height = 0)
			: width(_width)
			, height(_height)
		{ }

		~Size() = default;

		void setSize(int _width = 0, int _height = 0) {
			width = _width;
			height = _height;
		}

		const int getWidth() const {
			return width;
		}

		const int getHeight() const {
			return height;
		}

	private:
		int width;
		int height;
	};
}

#endif // !SIZE_H

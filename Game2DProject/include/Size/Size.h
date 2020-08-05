#ifndef SIZE_H
#define SIZE_H

namespace gnLib {
	struct Size {
	public:
		explicit Size(float _width = 0, float _height = 0)
			: width(_width)
			, height(_height)
		{ }

		~Size() = default;

		void setSize(float _width = 0, float _height = 0) {
			width = _width;
			height = _height;
		}

		const float getWidth() const {
			return width;
		}

		const float getHeight() const {
			return height;
		}

	private:
		float width;
		float height;
	};
}

#endif // !SIZE_H

#ifndef COLOR_H
#define COLOR_H

#pragma comment(lib, "d3d9.lib")
#include <d3d9.h>

namespace gnLib {

	class Color {
	public:
		static Color White;
		static Color Black;
		static Color Red;
		static Color Green;
		static Color Blue;

		Color(const Color& _color);
		Color(int _r, int _g, int _b, int _alpha = 255);
		~Color() = default;

		void setColor(const Color& _color);
		void setColor(int _r, int _g, int _b);

		// D3DCOLORŒ^‚É•ÏŠ·
		D3DCOLOR getColor() const;

	private:
		int r, g, b, alpha;
	};

}

#endif // !COLOR_H

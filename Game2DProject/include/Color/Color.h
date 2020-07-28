#ifndef COLOR_H
#define COLOR_H

#pragma comment(lib, "d3d9.lib")
#include <d3d9.h>

class Color;

class Color {
public:
	Color(int _r, int _g, int _b, int _alpha = 255);
	~Color() = default;

	D3DCOLOR getColor() const;

private:
	int r, g, b, alpha;
};

#endif // !COLOR_H

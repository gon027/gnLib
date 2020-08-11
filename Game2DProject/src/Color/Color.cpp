#include "../../include/Color/Color.h"

namespace gnLib {
	Color Color::White = Color(255, 255, 255);
	Color Color::Black = Color(0, 0, 0);
	Color Color::Red = Color(255, 0, 0);
	Color Color::Green = Color(0, 255, 0);
	Color Color::Blue = Color(0, 0, 255);

	Color::Color(const Color & _color)
		: r(_color.r)
		, g(_color.g)
		, b(_color.b)
		, alpha(_color.alpha)
	{

	}

	Color::Color(int _r, int _g, int _b, int _alpha)
		: r(_r)
		, g(_g)
		, b(_b)
		, alpha(_alpha)
	{

	}

	void Color::setColor(const Color & _color)
	{
		r = _color.r;
		g = _color.g;
		b = _color.b;
	}

	void Color::setColor(int _r, int _g, int _b)
	{
		r = _r;
		g = _g;
		b = _b;
	}

	D3DCOLOR Color::getColor() const
	{
		return D3DCOLOR_ARGB(alpha, r, g, b);
	}
}

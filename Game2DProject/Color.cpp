#include "Color.h"

Color::Color(int _r, int _g, int _b, int _alpha)
	: r(_r)
	, g(_g)
	, b(_b)
	, alpha(_alpha)
{

}

D3DCOLOR Color::getColor() const
{
	return D3DCOLOR_ARGB(alpha, r, g, b);
}

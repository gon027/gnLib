#include "Color.h"

/*
unsigned int Color::RGBA(unsigned int _r, unsigned int _g, unsigned int _b, unsigned int _a)
{
	unsigned int argb = 0;
	argb |= 1 << 24;
	argb |= _r << 16;
	argb |= _g << 8;
	argb |= _b;
	return argb;
}
*/

DWORD RGBA(unsigned int _r, unsigned int _g, unsigned int _b, unsigned int _a)
{
	DWORD argb = 1 << 24;
	argb |= (_r % 256) << 16;
	argb |= (_g % 256) << 8;
	argb |= (_b % 256);
	return argb;
}

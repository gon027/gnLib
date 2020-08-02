#ifndef RECT_H
#define RECT_H

#pragma comment(lib, "d3dx9.lib")
#include <d3dx9.h>

//#include "../Collider/BoxCollider.h"

namespace gnLib {

	class Graphics;

	class RectAngle {
	public:
		RectAngle();
		~RectAngle();

		void draw(float _x, float _y, float _xsize, float _ysize, DWORD _color);

	private:
		D3DXVECTOR3 position;
	};

}

#endif // !RECT_H

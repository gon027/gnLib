#ifndef SPRITE_H
#define SPRITE_H

#pragma comment(lib, "d3d9.lib")
#pragma comment(lib, "d3dx9.lib")
#pragma comment(lib, "d3dxof.lib")
#include <d3d9.h>
#include <d3dx9.h>

#include "SmartPtr.h"
#include "Texture.h"

class Graphics;

class Sprite {
public:
	Sprite();
	~Sprite();

	D3DXVECTOR3 position;

	bool loadTexture(Graphics* _graphics, Texture& _texture);

	// •`‰æ
	void draw(float _x, float _y);

	// ‰ñ“]•`‰æ
	void rotateDraw(float _x, float _y, float _angle);

	// Šg‘åEk¬•`‰æ
	void scaleDraw(float _x, float _y, float _sx = 1.0f, float _sy = 1.0f);

	bool isSplite();

private:
	Texture tex;
	LPD3DXSPRITE sprite;
	D3DXVECTOR3 center;

	// ‰ñ“]EŠg‘åk¬‚ğl—¶‚µ‚½•`‰æ
	void drawEx(float _x, float _y, float _angle, float _sx, float _sy);
};

#endif // !SPRITE_H

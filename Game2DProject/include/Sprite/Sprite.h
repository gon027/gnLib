#ifndef SPRITE_H
#define SPRITE_H

#pragma comment(lib, "d3d9.lib")
#pragma comment(lib, "d3dx9.lib")
#pragma comment(lib, "d3dxof.lib")
#include <d3d9.h>
#include <d3dx9.h>

#include "../Common/SmartPtr.h"
#include "../Texture/Texture.h"

namespace gnLib {
	class Graphics;

	class Sprite {
	public:
		Sprite();
		Sprite(Texture& _texture);
		~Sprite();

		D3DXVECTOR3 position;

		bool loadTexture(Texture& _texture);

		// �`��
		void draw(float _x, float _y);

		// ��]�`��
		void rotateDraw(float _x, float _y, float _angle);

		// �g��E�k���`��
		void scaleDraw(float _x, float _y, float _sx = 1.0f, float _sy = 1.0f);

		bool isSplite();

	private:
		Texture tex;
		LPD3DXSPRITE sprite;
		D3DXVECTOR3 center;

		// ��]�E�g��k�����l�������`��
		void drawEx(float _x, float _y, float _angle, float _sx, float _sy);
	};
}

#endif // !SPRITE_H

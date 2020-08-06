#ifndef SPRITE_H
#define SPRITE_H

#pragma comment(lib, "d3d9.lib")
#pragma comment(lib, "d3dx9.lib")
#pragma comment(lib, "d3dxof.lib")
#include <d3d9.h>
#include <d3dx9.h>

#include "../Common/SmartPtr.h"
#include "../Texture/Texture.h"
#include "../Vector/Vector2.h"

namespace gnLib {
	class Graphics;

	class Sprite {
	public:
		Sprite();
		Sprite(Texture& _texture);
		~Sprite();

		/*
		void set(float _x, float _y);
		void set(const Vector2& _vector);

		void setScale(float _scale);

		void setRotation(float _x, float _y);
		void setRotation(const Vector2 _rot);

		void draw();
		*/

		// �`��
		void draw(float _x, float _y);

		// ��]�`��
		void rotateDraw(float _x, float _y, float _angle);

		// �g��E�k���`��
		void scaleDraw(float _x, float _y, float _sx = 1.0f, float _sy = 1.0f);

		bool isSplite();

	private:
		Texture texture;
		LPD3DXSPRITE sprite;
		D3DXVECTOR3 center;
		D3DXVECTOR3 position;

		// ��]�E�g��k�����l�������`��
		void drawEx(float _x, float _y, float _angle, float _sx, float _sy);

		// �e�N�X�`���ǂݍ���
		bool loadTexture(Texture& _texture);
	};
}

#endif // !SPRITE_H

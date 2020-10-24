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
#include "../Object/Object.h"

namespace gnLib {
	class Graphics;

	// �摜��`�悷��N���X
	class Sprite : public Object{
	public:
		Sprite(Texture& _texture);
		~Sprite();

		// ���W��ݒ肷��
		void setPos(float _x, float _y);
		void setPos(const Vector2& _v);

		// �摜�̑傫����ݒ肷��
		void setScale(float _sx, float _sy);
		void setScale(const Vector2& _v);

		// �摜�̊p�x��ݒ肷��
		void setRotate(float _angle);

		// �摜��`�悷��
		void draw();

		// �摜���ǂݍ��߂Ă��邩
		bool isLoading();

	private:
		LPD3DXSPRITE sprite;
		Texture texture;

		D3DXVECTOR3 center;
		Vector2 position;
		Vector2 scale;
		float angle;

		// �e�N�X�`���ǂݍ���
		bool loadTexture(Texture& _texture);
	};
}

#endif // !SPRITE_H

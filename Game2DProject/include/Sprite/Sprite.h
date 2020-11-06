#ifndef SPRITE_H
#define SPRITE_H

#include <vector>
#include "../Common/Lib.h"
#include "../Common/SmartPtr.h"
#include "../Texture/Texture.h"
#include "../Vector/Vector2.h"
#include "../Object/Object.h"

using std::vector;

namespace gnLib {

	struct TransformMatrix {
		D3DXMATRIX world;
		D3DXMATRIX position;
		D3DXMATRIX rotation;
		D3DXMATRIX scale;

		// �s�������������
		void initIdentity() {
			D3DXMatrixIdentity(&world);
			D3DXMatrixIdentity(&position);
			D3DXMatrixIdentity(&rotation);
			D3DXMatrixIdentity(&scale);
		}

		void calcWorldMatrix() {
			D3DXMatrixMultiply(&world, &world, &rotation);
			D3DXMatrixMultiply(&world, &world, &scale);
			D3DXMatrixMultiply(&world, &world, &position);
		}
	};

	// �摜��`�悷��N���X
	class Sprite : public Object{
	public:
		explicit Sprite(Texture& _texture);
		Sprite(const string& _filePath);
		~Sprite();

		// ���W��ݒ肷��
		void setPos(float _x, float _y);
		void setPos(const Vector2& _v);

		// �摜�̑傫����ݒ肷��
		void setScale(float _sx, float _sy);
		void setScale(const Vector2& _v);

		// �摜�̊p�x��ݒ肷��
		void setRotate(float _angle);

		// �e�N�X�`���ǂݍ���
		bool setTexture(Texture& _texture);

		// �摜��`�悷��
		void draw();

		// �T�C�Y���w�肵�ĉ摜��`�悷��
		void draw(RECT& _rect);

		// �摜�̃T�C�Y���擾
		const Size getSize();

		// �摜���ǂݍ��߂Ă��邩
		bool isLoading();

	private:
		LPD3DXSPRITE sprite;
		Texture texture;

		D3DXVECTOR3 center;    
		Vector2 position;      
		Vector2 scale;
		float angle;
	};

}

#endif // !SPRITE_H

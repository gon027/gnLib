#ifndef SPRITE_H
#define SPRITE_H

#include <vector>
#include "../Vector/Vector2.h"
#include "../Common/SmartPtr.h"
#include "../Texture/Texture.h"

using std::vector;

namespace gnLib {

	/*
	class Transform2D {
	public:
		// ���W��ݒ肷��
		void setPos(float _x, float _y);
		void setPos(const Vector2& _v);

		// �摜�̑傫����ݒ肷��
		void setScale(float _sx, float _sy);
		void setScale(const Vector2& _v);

		// �摜�̊p�x��ݒ肷��
		void setRotate(float _angle);

	private:
		Vector2 pos;
		Vector2 scale;
		float angle;

	private:
		D3DXMATRIX world;
	};
	*/

	// �摜��`�悷��N���X
	class Sprite {
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

		// �摜��`�悷��
		void draw(bool _isCenter = true);

		// �T�C�Y���w�肵�ĉ摜��`�悷��
		void draw(RECT& _rect, bool _isCenter = true);

		// �摜�̃T�C�Y���擾
		const Size& getSize();

	private:
		Texture texture;

		Vector2 position;      
		Vector2 scale;
		float angle;
	};

}

#endif // !SPRITE_H

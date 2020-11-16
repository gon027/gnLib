#ifndef SPRITE_H
#define SPRITE_H

#include <vector>
#include "../Vector/Vector2.h"
#include "../Common/SmartPtr.h"
#include "../Texture/Texture.h"

using std::vector;

namespace gnLib {
	// �摜��`�悷��N���X
	class Sprite {
	public:
		Sprite();
		~Sprite();

		// �e�N�X�`����ǂݍ���
		void setTexture(TextureSPtr& _texture);

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
		TextureSPtr texture;

		Vector2 position;      
		Vector2 scale;
		float angle;
	};

	// �e�N�X�`���𕪊��ł���N���X
	class DivSprite : public Sprite{
	public:
		DivSprite(Texture& _texture);
		DivSprite(const string& _filePath);
		~DivSprite() = default;

		void draw(int _index);

	private:
		vector<RECT> textureRect;
	};

}

#endif // !SPRITE_H

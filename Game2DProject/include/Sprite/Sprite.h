#ifndef SPRITE_H
#define SPRITE_H

#include <vector>
#include "../Vector/Vector2.h"
#include "../Common/SmartPtr.h"
#include "../Texture/Texture.h"

using std::vector;

namespace gnLib {

	class ISprite {
	public:
		ISprite() : texturePtr(nullptr){}

		virtual ~ISprite() = default;

		/// <summary>
		/// �e�N�X�`�����Z�b�g����
		/// </summary>
		/// <param name="_texturePtr"></param>
		virtual void setTexture(TextureSPtr& _texturePtr) = 0;

		/// <summary>
		/// �X�v���C�g��`��
		/// </summary>
		/// <param name="_pos"> ���W </param>
		/// <param name="_scale"> �X�P�[�� </param>
		/// <param name="angle"> �p�x </param>
		virtual void draw(const Vector2& _pos, const Vector2& _scale, float _angle, bool _isCenter = true, bool _isFlip = false) = 0;

	protected:
		TextureSPtr texturePtr;		// �e�N�X�`���̃|�C���^
	};

	// �X�v���C�g�N���X
	class Sprite : public ISprite {
	public:
		Sprite();
		~Sprite() = default;

		void setTexture(TextureSPtr& _texturePtr) override;

		void draw(const Vector2& _pos, const Vector2& _scale, float _angle, bool _isCenter = true, bool _isFlip = false) override;

		void draw(const TextureRect& _rect, const Vector2& _pos, const Vector2& _scale, float _angle, bool _isCenter = true, bool _isFlip = false);
	};

	// �A�j���[�V�����p�X�v���C�g�N���X
	class AnimSprite : public ISprite {
	public:
		// 
		AnimSprite(int _xNum, int _yNum, float _animfps = 60.0f);
		~AnimSprite() = default;

		void setTexture(TextureSPtr& _texturePtr) override;

		void draw(const Vector2& _pos, const Vector2& _scale, float _angle, bool _isCenter = true, bool _isFlip = false) override;

	private:
		int textureNum;
		vector<TextureRect> textureRect;
		Size textureSize;
		float frame;
		float animFps;
	};

	namespace umImpl {
		class gnSprite {
		public:
			gnSprite();
			~gnSprite() {};

			void setTexture(TextureTest* _texturePtr);

			void draw(const Vector2 _pos);

		private:
			TextureTest* texturePtr;		// �e�N�X�`���̃|�C���^
			Size size;
		};
	}
}

#endif // !SPRITE_H

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
		ISprite() : texturePtr(nullptr), size() {}

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

		/// <summary>
		/// �摜�̃T�C�Y���擾����
		/// </summary>
		/// <returns>  </returns>
		virtual const Size& getSize() = 0;

	protected:
		TextureSPtr texturePtr;		// �e�N�X�`���̃|�C���^
		Size size;
	};

	// �X�v���C�g�N���X
	class Sprite : public ISprite {
	public:
		Sprite();
		~Sprite() = default;

		void setTexture(TextureSPtr& _texturePtr) override;

		void draw(const Vector2& _pos, const Vector2& _scale, float _angle, bool _isCenter = true, bool _isFlip = false) override;

		const Size& getSize() override;
	};

	namespace unimpl {

		// �A�j���[�V�����p�X�v���C�g�N���X
		class AnimSprite : public ISprite {
			AnimSprite();
			~AnimSprite() = default;

			void setTexture(TextureSPtr& _texturePtr) override;

			void draw(const Vector2& _pos, const Vector2& _scale, float _angle, bool _isCenter = true, bool _isFlip = false) override;

			const Size& getSize() override;

		private:
			vector<TextureRect> textureRect;
		};
	}
}

#endif // !SPRITE_H

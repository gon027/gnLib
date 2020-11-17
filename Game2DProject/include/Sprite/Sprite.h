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
		/// テクスチャをセットする
		/// </summary>
		/// <param name="_texturePtr"></param>
		virtual void setTexture(TextureSPtr& _texturePtr) = 0;

		/// <summary>
		/// スプライトを描画
		/// </summary>
		/// <param name="_pos"> 座標 </param>
		/// <param name="_scale"> スケール </param>
		/// <param name="angle"> 角度 </param>
		virtual void draw(const Vector2& _pos, const Vector2& _scale, float _angle, bool _isCenter = true, bool _isFlip = false) = 0;

		/// <summary>
		/// 画像のサイズを取得する
		/// </summary>
		/// <returns>  </returns>
		virtual const Size& getSize() = 0;

	protected:
		TextureSPtr texturePtr;		// テクスチャのポインタ
		Size size;
	};

	// スプライトクラス
	class Sprite : public ISprite {
	public:
		Sprite();
		~Sprite() = default;

		void setTexture(TextureSPtr& _texturePtr) override;

		void draw(const Vector2& _pos, const Vector2& _scale, float _angle, bool _isCenter = true, bool _isFlip = false) override;

		const Size& getSize() override;
	};

	namespace unimpl {

		// アニメーション用スプライトクラス
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

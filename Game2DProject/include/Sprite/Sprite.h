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

	protected:
		TextureSPtr texturePtr;		// テクスチャのポインタ
	};

	// スプライトクラス
	class Sprite : public ISprite {
	public:
		Sprite();
		~Sprite() = default;

		void setTexture(TextureSPtr& _texturePtr) override;

		void draw(const Vector2& _pos, const Vector2& _scale, float _angle, bool _isCenter = true, bool _isFlip = false) override;

		void draw(const TextureRect& _rect, const Vector2& _pos, const Vector2& _scale, float _angle, bool _isCenter = true, bool _isFlip = false);
	};

	// アニメーション用スプライトクラス
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
			TextureTest* texturePtr;		// テクスチャのポインタ
			Size size;
		};
	}
}

#endif // !SPRITE_H

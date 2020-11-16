#ifndef SPRITE_H
#define SPRITE_H

#include <vector>
#include "../Vector/Vector2.h"
#include "../Common/SmartPtr.h"
#include "../Texture/Texture.h"

using std::vector;

namespace gnLib {
	// 画像を描画するクラス
	class Sprite {
	public:
		Sprite();
		~Sprite();

		// テクスチャを読み込む
		void setTexture(TextureSPtr& _texture);

		// 座標を設定する
		void setPos(float _x, float _y);
		void setPos(const Vector2& _v);

		// 画像の大きさを設定する
		void setScale(float _sx, float _sy);
		void setScale(const Vector2& _v);

		// 画像の角度を設定する
		void setRotate(float _angle);

		// 画像を描画する
		void draw(bool _isCenter = true);

		// サイズを指定して画像を描画する
		void draw(RECT& _rect, bool _isCenter = true);

		// 画像のサイズを取得
		const Size& getSize();

	private:
		TextureSPtr texture;

		Vector2 position;      
		Vector2 scale;
		float angle;
	};

	// テクスチャを分割できるクラス
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

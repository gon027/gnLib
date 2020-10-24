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

	// 画像を描画するクラス
	class Sprite : public Object{
	public:
		Sprite(Texture& _texture);
		~Sprite();

		// 座標を設定する
		void setPos(float _x, float _y);
		void setPos(const Vector2& _v);

		// 画像の大きさを設定する
		void setScale(float _sx, float _sy);
		void setScale(const Vector2& _v);

		// 画像の角度を設定する
		void setRotate(float _angle);

		// 画像を描画する
		void draw();

		// 画像が読み込めているか
		bool isLoading();

	private:
		LPD3DXSPRITE sprite;
		Texture texture;

		D3DXVECTOR3 center;
		Vector2 position;
		Vector2 scale;
		float angle;

		// テクスチャ読み込み
		bool loadTexture(Texture& _texture);
	};
}

#endif // !SPRITE_H

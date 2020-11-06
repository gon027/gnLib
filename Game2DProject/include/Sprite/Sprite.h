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

		// 行列を初期化する
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

	// 画像を描画するクラス
	class Sprite : public Object{
	public:
		explicit Sprite(Texture& _texture);
		Sprite(const string& _filePath);
		~Sprite();

		// 座標を設定する
		void setPos(float _x, float _y);
		void setPos(const Vector2& _v);

		// 画像の大きさを設定する
		void setScale(float _sx, float _sy);
		void setScale(const Vector2& _v);

		// 画像の角度を設定する
		void setRotate(float _angle);

		// テクスチャ読み込み
		bool setTexture(Texture& _texture);

		// 画像を描画する
		void draw();

		// サイズを指定して画像を描画する
		void draw(RECT& _rect);

		// 画像のサイズを取得
		const Size getSize();

		// 画像が読み込めているか
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

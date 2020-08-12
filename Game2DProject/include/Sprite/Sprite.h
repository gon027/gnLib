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
#include "../Vector/Vector3.h"
#include "../Object/Object.h"

namespace gnLib {
	class Graphics;

	class Sprite : public Object{
	public:
		Sprite(Texture& _texture);
		~Sprite();

		void setPos(float _x, float _y);
		void setPos(const Vector2& _v);
		void setPos(const Vector3& _v);

		void setScale(float _sx, float _sy);
		void setScale(const Vector2& _v);

		void setRotate(float _angle);

		void draw();

		bool isSplite();

	private:
		LPD3DXSPRITE sprite;
		Texture texture;

		D3DXVECTOR3 center;
		Vector3 position;
		Vector2 scale;
		float angle;

		// テクスチャ読み込み
		bool loadTexture(Texture& _texture);
	};
}

#endif // !SPRITE_H

#include "../../include/Sprite/Sprite.h"
#include "../../include/Common/Macro.h"
#include "../../include/Graphics/Graphics.h"
#include "../../include/Render/Render.h"
#include "../../include/GameCore/GameCore.h"

#include <winerror.h>

namespace gnLib {

	Sprite::Sprite(Texture & _texture)
		: sprite(nullptr)
		, center()
		, position(Vector2::Zero)
		, scale({ 1.0f, 1.0f })
		, angle(0)
	{
		loadTexture(_texture);
	}

	Sprite::~Sprite()
	{
		RELEASE(sprite);
	}

	void Sprite::setPos(float _x, float _y)
	{
		position.x = _x;
		position.y = _y;
	}

	void Sprite::setPos(const Vector2 & _v)
	{
		setPos(_v.x, _v.y);
	}

	void Sprite::setScale(float _sx, float _sy)
	{
		scale.x = _sx;
		scale.y = _sy;
	}

	void Sprite::setScale(const Vector2 & _v)
	{
		scale = _v;
	}

	void Sprite::setRotate(float _angle)
	{
		angle = _angle;
	}

	void Sprite::draw()
	{
		D3DXMATRIX matWorld, matRotation, matScale, matPosition;

		D3DXMatrixIdentity(&matWorld);
		D3DXMatrixIdentity(&matRotation);
		D3DXMatrixIdentity(&matScale);
		D3DXMatrixIdentity(&matPosition);

		D3DXMatrixScaling(&matScale, scale.x, scale.y, 0.0f);

		D3DXMatrixRotationZ(&matRotation, D3DXToRadian(angle));

		matPosition._41 = position.x;
		matPosition._42 = position.y;

		D3DXMatrixMultiply(&matWorld, &matWorld, &matRotation);
		D3DXMatrixMultiply(&matWorld, &matWorld, &matScale);
		D3DXMatrixMultiply(&matWorld, &matWorld, &matPosition);

		// 描画開始
		sprite->Begin(NULL);

		{
			sprite->SetTransform(&matWorld);

			sprite->Draw(texture.getTexture(), NULL, &center, NULL, 0xFFFFFFFF);
		}

		sprite->End();
	}

	bool Sprite::loadTexture(Texture & _texture)
	{
		HRESULT hr;

		// スプライトの作成
		hr = D3DXCreateSprite(
			GCoreIns->getGraphic()->getDevice(), 
			&sprite
		);

		if (FAILED(hr)) {
			return false;
		}

		texture = _texture;

		center = { texture.getWidth() / 2.0f, texture.getHeight() / 2.0f, 0.0f };

		return true;
	}

	bool Sprite::isLoading()
	{
		return sprite != nullptr;
	}
}
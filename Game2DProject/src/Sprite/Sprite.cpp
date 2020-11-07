#include "../../include/Sprite/Sprite.h"
#include "../../include/Common/Macro.h"
#include "../../include/Graphics/Graphics.h"
#include "../../include/Render/Render.h"
#include "../../include/GameCore/GameCore.h"

#include <winerror.h>

namespace gnLib {

	Sprite::Sprite(Texture & _texture)
		: sprite(nullptr)
		, texture(_texture)
		, position(Vector2::Zero)
		, scale({ 1.0f, 1.0f })
		, angle(0)
	{
		setTexture(_texture);
	}

	Sprite::Sprite(const string& _filePath)
	{
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

	void Sprite::draw(bool _isCenter)
	{
		auto rect = RECT{ 0, 0, (int)texture.getWidth(), (int)texture.getHeight() };
		draw(rect, _isCenter);
	}

	void Sprite::draw(RECT& _rect, bool _isCenter)
	{
		TransformMatrix tMatrix;
		tMatrix.initIdentity();

		D3DXMatrixScaling(&tMatrix.scale, scale.x, scale.y, 0.0f);
		D3DXMatrixRotationZ(&tMatrix.rotation, D3DXToRadian(angle));

		tMatrix.position._41 = position.x;
		tMatrix.position._42 = position.y;

		tMatrix.calcWorldMatrix();

		D3DXVECTOR3 center{0.0f, 0.0f, 0.0f};
		
		// �摜�����S���W�ɗ���悤�ɂ���
		if(_isCenter){
			center = { texture.getWidth() / 2.0f, texture.getHeight() / 2.0f, 0.0f };
		};

		// �`��J�n
		sprite->Begin(NULL);
		sprite->SetTransform(&tMatrix.world);
		sprite->Draw(texture.getTexture(), &_rect, &center, NULL, 0xFFFFFFFF);
		sprite->End();
	}

	const Size& Sprite::getSize()
	{
		return texture.getTextureSize();
	}

	bool Sprite::setTexture(Texture & _texture)
	{
		HRESULT hr;

		// �X�v���C�g�̍쐬
		hr = D3DXCreateSprite(
			GCoreIns->getGraphic()->getDevice(), 
			&sprite
		);

		if (FAILED(hr)) {
			return false;
		}

		return true;
	}

	bool Sprite::isLoading()
	{
		return sprite != nullptr;
	}
}
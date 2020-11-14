#include "../../include/Sprite/Sprite.h"
#include "../../include/Common/Macro.h"
#include "../../include/Common/Math.h"
#include "../../include/Graphics/Graphics.h"
#include "../../include/Render/Render.h"
#include "../../include/GameCore/GameCore.h"
#include "../../include/SpriteRender/SpriteRender.h"

#include <winerror.h>

namespace gnLib {

	Sprite::Sprite()
		: texture()
		, position(Vector2::Zero)
		, scale({ 1.0f, 1.0f })
		, angle(0)
	{
	}

	Sprite::Sprite(Texture & _texture)
		: texture(_texture)
		, position(Vector2::Zero)
		, scale({ 1.0f, 1.0f })
		, angle(0)
	{

	}

	Sprite::Sprite(const string& _filePath)
		: texture(_filePath)
		, position(Vector2::Zero)
		, scale({ 1.0f, 1.0f })
		, angle(0)
	{
	}

	Sprite::~Sprite()
	{

	}

	void Sprite::loadTexture(Texture& _texture)
	{
		texture = _texture;
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
		angle = _angle / 180.0f * pi;
	}

	void Sprite::draw(bool _isCenter)
	{
		auto rect = RECT{ 0, 0, (int)texture.getWidth(), (int)texture.getHeight() };
		draw(rect, _isCenter);
	}

	void Sprite::draw(RECT& _rect, bool _isCenter)
	{
		D3DXMATRIX mat;
		D3DXMatrixIdentity(&mat);

		D3DXVECTOR2 center{
			texture.getWidth() / 2.0f,
			texture.getHeight() / 2.0f 
		};

		D3DXVECTOR2 rotate{ scale.x, scale.y };

		D3DXVECTOR2 pos{ position.x, position.y };

		if (_isCenter) {
			pos.x -= center.x;
			pos.y -= center.y;
		}

		D3DXMatrixTransformation2D(
			&mat, 
			&center,  // スケーリングするときの座標の中心
			0.0f,
			&rotate,  
			&center, 
			angle,    // 回転角
			&pos      // 座標
		);

		GCSprite->getSprite()->SetTransform(&mat);
		GCSprite->getSprite()->Draw(texture.getTexture(), &_rect, NULL, NULL, 0xFFFFFFFF);

	}

	const Size& Sprite::getSize()
	{
		return texture.getTextureSize();
	}
}
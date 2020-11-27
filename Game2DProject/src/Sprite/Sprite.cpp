#include "../../include/Sprite/Sprite.h"
#include "../../include/Common/Macro.h"
#include "../../include/Graphics/Graphics.h"
#include "../../include/Render/Render.h"
#include "../../include/GameCore/GameCore.h"
#include "../../include/SpriteRender/SpriteRender.h"

#include <winerror.h>

namespace gnLib {

	Sprite::Sprite()
		: ISprite()
	{
	}

	void Sprite::setTexture(TextureSPtr& _texturePtr) 
	{
		this->texturePtr = _texturePtr;
		this->size = _texturePtr->getSize();
	}

	void Sprite::draw(const Vector2& _pos, const Vector2& _scale, float _angle, bool _isCenter, bool _isFlip) {
		if (texturePtr) {
			D3DXMATRIX mat;
			D3DXMatrixIdentity(&mat);

			D3DXVECTOR2 center{ texturePtr->getWidth() / 2.0f, texturePtr->getHeight() / 2.0f };  // 中心座標
			D3DXVECTOR2 scale{ _isFlip ? -_scale.x : _scale.x , _scale.y };  // スケール
			D3DXVECTOR2 pos{ _pos.x, _pos.y };         // 座標

			if (_isCenter) {
				pos.x -= center.x;
				pos.y -= center.y;
			}

			D3DXMatrixTransformation2D(
				&mat,
				&center,   // スケーリングするときの座標の中心
				0.0f,
				&scale,
				&center,
				_angle,    // 回転角
				&pos       // 座標
			);

			auto rect = RECT{ 0, 0, (int)texturePtr->getWidth(), (int)texturePtr->getHeight() };

			GCSprite->getSprite()->SetTransform(&mat);
			GCSprite->getSprite()->Draw(
				texturePtr->getTexture(),
				&rect,
				NULL,
				NULL,
				0xFFFFFFFF
			);
		}
	}

	const Size& Sprite::getSize() {
		return this->size;
	}
}


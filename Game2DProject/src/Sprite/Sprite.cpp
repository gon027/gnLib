#include "../../include/Sprite/Sprite.h"
#include "../../include/Common/Macro.h"
#include "../../include/Graphics/Graphics.h"
#include "../../include/Render/Render.h"
#include "../../include/GameCore/GameCore.h"
#include "../../include/SpriteRender/SpriteRender.h"
#include "../../include/Time/Time.h"

#include <winerror.h>

namespace gnLib {

	Sprite::Sprite()
		: ISprite()
	{
	}

	void Sprite::setTexture(TextureSPtr& _texturePtr) 
	{
		this->texturePtr = _texturePtr;
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

	void Sprite::draw(const TextureRect& _rect, const Vector2& _pos, const Vector2& _scale, float _angle, bool _isCenter, bool _isFlip)
	{
		if (texturePtr) {
			D3DXMATRIX mat;
			D3DXMatrixIdentity(&mat);

			auto rect = RECT{
				_rect.left,
				_rect.top,
				_rect.right,
				_rect.bottom
			};

			D3DXVECTOR2 center{ (rect.right - rect.left) / 2.0f, (rect.bottom - rect.top) / 2.0f };  // 中心座標
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

	AnimSprite::AnimSprite(int _xNum, int _yNum, float _animfps)
		: textureNum(_xNum * _yNum)
		, textureRect((long)textureNum)
		, textureSize({_xNum, _yNum})
		, frame(0.0f)
		, animFps(_animfps)
	{
	}

	void AnimSprite::setTexture(TextureSPtr& _texturePtr)
	{
		this->texturePtr = _texturePtr;

		auto tSize = texturePtr->getSize();                       // テクスチャの全体のサイズ
		int xSize = tSize.getWidth() / textureSize.getWidth();    // 分割するテクスチャの横の幅
		int ySize = tSize.getHeight() / textureSize.getHeight();  // 分割するテクスチャの縦の幅
			
		for (long y{ 0 }; y < textureSize.getHeight(); ++y) {
			for (long x{ 0 }; x < textureSize.getWidth(); ++x) {
				long index = y * static_cast<long>(textureSize.getWidth()) + x;
				textureRect[index] = {
					xSize * x,
					ySize * y,
					xSize * (x + 1),
					ySize * (y + 1)
				};
			}
		}
	}

	void AnimSprite::draw(const Vector2& _pos, const Vector2& _scale, float _angle, bool _isCenter, bool _isFlip)
	{
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

			frame += animFps * Time::deltaTime();
			int currentFrame = static_cast<int>(frame) % textureNum;

			auto rect = RECT{ 
				textureRect[currentFrame].left, 
				textureRect[currentFrame].top,
				textureRect[currentFrame].right,
				textureRect[currentFrame].bottom
			};

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
}

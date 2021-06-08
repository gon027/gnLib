#include <Sprite/Sprite.h>
#include <Common/Macro.h>
#include <GameCore/GameCore.h>
#include <Graphics/Graphics.h>
#include <Vertex/Vertex2D.h>
#include <Common/Math.h>
#include <Time/Time.h>

#include <SpriteRender/SpriteRender.h>

#include <vector>
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
		// 画像のポインタがnullptrだった場合
		if (!texturePtr) {
			return;
		}
		
		auto width = texturePtr->getWidth() * _scale.x;
		auto height = texturePtr->getHeight() * _scale.y;

		auto center = _pos + Vector2{ width / 2, height / 2 };

		auto leftTop     =  rotation(Vector2{ _pos.x, _pos.y }, center, _angle);
		auto leftBottom  =  rotation(Vector2{ _pos.x, _pos.y + height }, center, _angle);
		auto rightTop    =  rotation(Vector2{ _pos.x + width, _pos.y }, center, _angle);
		auto rightBottom =  rotation(Vector2{ _pos.x + width, _pos.y + height }, center, _angle);

		auto uv1 = Vector2{ 0.0f, 0.0f };
		auto uv2 = Vector2{ 1.0f, 1.0f };

		if (_isFlip) {
			std::swap(uv1, uv2);
			std::swap(uv1.y, uv2.y);
		}

		Color color{ Color::White };
		
		std::vector<Vertex2D> vertex = {
			{leftBottom.x,  leftBottom.y,  0.0f, 1.0f, color.getColor(), uv1.x, uv2.y},  // 左下
			{leftTop.x,     leftTop.y,     0.0f, 1.0f, color.getColor(), uv1.x, uv1.y},  // 左上
			{rightBottom.x, rightBottom.y, 0.0f, 1.0f, color.getColor(), uv2.x, uv2.y},  // 右下
			{rightTop.x,    rightTop.y,    0.0f, 1.0f, color.getColor(), uv2.x, uv1.y},  // 右上
		};

		GCGraphics->SetTexture(0, texturePtr->getTexture());
		GCGraphics->SetFVF(FVF_CUSTOM2D);
		GCGraphics->DrawPrimitiveUP(D3DPT_TRIANGLESTRIP, 2, vertex.data(), sizeof(Vertex2D));
		
		/*
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
		*/
	}

	void Sprite::draw(const TextureRect& _rect, const Vector2& _pos, const Vector2& _scale, float _angle, bool _isCenter, bool _isFlip)
	{
		if (!texturePtr) {
			return;
		}

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
		int xSize = tSize.width / textureSize.width;    // 分割するテクスチャの横の幅
		int ySize = tSize.height / textureSize.height;  // 分割するテクスチャの縦の幅
			
		for (long y{ 0 }; y < textureSize.height; ++y) {
			for (long x{ 0 }; x < textureSize.width; ++x) {
				long index = y * static_cast<long>(textureSize.width) + x;
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
		if (!texturePtr) {
			return;
		}

		D3DXMATRIX mat;
		D3DXMatrixIdentity(&mat);

		frame += animFps * Time::deltaTime();
		int currentFrame = static_cast<int>(frame) % textureNum;

		auto rect = RECT{
			textureRect[currentFrame].left,
			textureRect[currentFrame].top,
			textureRect[currentFrame].right,
			textureRect[currentFrame].bottom
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

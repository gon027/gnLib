#include "Sprite.h"

#include <winerror.h>
#include "Macro.h"
#include "Graphics.h"


Sprite::Sprite()
	: texture()
	, sprite()
	, center()
{

}

Sprite::~Sprite()
{
	RELEASE(texture);
	RELEASE(sprite);
}

bool Sprite::loadTexture(Graphics & _graphics, const char * _filePath)
{
	HRESULT hr;

	// スプライトの作成
	hr = D3DXCreateSprite(_graphics.device, &sprite);

	if (FAILED(hr)) {
		return false;
	}

	// テクスチャの読み込み
	hr = D3DXCreateTextureFromFile(_graphics.device, _filePath, &texture);

	if (FAILED(hr)) {
		return false;
	}

	// テクスチャからサーフェイスを取得
	IDirect3DSurface9* surface;
	hr = texture->GetSurfaceLevel(0, &surface);

	if (FAILED(hr)) {
		RELEASE(surface);
		return false;
	}

	// サーフェイス情報から画像サイズを取得
	D3DSURFACE_DESC surfaceInfo;
	hr = surface->GetDesc(&surfaceInfo);

	if (FAILED(hr)) {
		return false;
	}

	// 画像の縦幅と横幅を取得
	int width = surfaceInfo.Width;
	int height = surfaceInfo.Height;

	center = { width / 2.0f, height / 2.0f, 0.0f };

	RELEASE(surface);

	return true;
}

bool Sprite::loadTexture(Graphics & _graphics, Texture & _texture)
{
	HRESULT hr;

	// スプライトの作成
	hr = D3DXCreateSprite(_graphics.device, &sprite);

	if (FAILED(hr)) {
		return false;
	}

	tex = _texture;

	center = { tex.getWidth() / 2.0f, tex.getHeight() / 2.0f, 0.0f };

	return true;
}

void Sprite::draw(float _x, float _y)
{
	drawEx(_x, _y, 0, 1.0f, 1.0f);
}

void Sprite::rotateDraw(float _x, float _y, float _angle)
{
	drawEx(_x, _y, _angle, 1.0f, 1.0f);
}

void Sprite::scaleDraw(float _x, float _y, float _sx, float _sy)
{
	drawEx(_x, _y, 0.0f, _sx, _sy);
}

void Sprite::drawEx(float _x, float _y, float _angle, float _sx, float _sy)
{
	position.x = _x;
	position.y = _y;

	D3DXMATRIX matWorld, matRotation, matScale, matPosition;

	D3DXMatrixIdentity(&matWorld);
	D3DXMatrixIdentity(&matRotation);
	D3DXMatrixIdentity(&matScale);
	D3DXMatrixIdentity(&matPosition);

	D3DXMatrixScaling(&matScale, _sx, _sy, 0.0f);

	D3DXMatrixRotationZ(&matRotation, D3DXToRadian(_angle));

	matPosition._41 = _x;
	matPosition._42 = _y;

	D3DXMatrixMultiply(&matWorld, &matWorld, &matRotation);
	D3DXMatrixMultiply(&matWorld, &matWorld, &matScale);
	D3DXMatrixMultiply(&matWorld, &matWorld, &matPosition);

	// 描画開始
	sprite->Begin(NULL);

	{
		sprite->SetTransform(&matWorld);

		sprite->Draw(texture, NULL, &center, NULL, 0xFFFFFFFF);
	}

	sprite->End();
}

#include "Texture.h"

#include "Macro.h"
#include "Graphics.h"

Texture::Texture()
{

}

Texture::~Texture()
{
	//RELEASE(texture);
}

bool Texture::loadTexture(Graphics& _graphics, const char * _filePath)
{
	HRESULT hr;

	// テクスチャの読み込み
	hr = D3DXCreateTextureFromFile(_graphics.device, _filePath, &texture);

	if (FAILED(hr)) {
		return false;
	}

	if (imageInfo()) {
		return false;
	}

	return true;
}

bool Texture::imageInfo()
{
	// 画像の情報を取得

	HRESULT hr;

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
	width = surfaceInfo.Width;
	height = surfaceInfo.Height;

	RELEASE(surface);

	return true;
}

const LPDIRECT3DTEXTURE9 Texture::getTexture()
{
	return texture;
}

const int Texture::getWidth()
{
	return width;
}

const int Texture::getHeight()
{
	return height;
}

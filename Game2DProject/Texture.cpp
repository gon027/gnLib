#include "Texture.h"

#include "Macro.h"
#include "Graphics.h"
#include "Render.h"

Texture::Texture()
	: lpTexture(nullptr)
{

}

Texture::Texture(const string& _filePath)
	: lpTexture(nullptr)
{
	loadTexture(_filePath);
}

Texture::~Texture()
{
	RELEASE(lpTexture);
}

bool Texture::loadTexture(const string & _filePath)
{
	HRESULT hr;

	// テクスチャの読み込み
	hr = D3DXCreateTextureFromFile(RenderDevice, _filePath.c_str(), &lpTexture);

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
	hr = lpTexture->GetSurfaceLevel(0, &surface);
	

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

const int Texture::getWidth()
{
	return width;
}

const int Texture::getHeight()
{
	return height;
}

const bool Texture::isLoading()
{
	return lpTexture;
}

LPDIRECT3DTEXTURE9 Texture::getTexture() const
{
	return lpTexture;
}


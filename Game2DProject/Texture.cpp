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

	// �e�N�X�`���̓ǂݍ���
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
	// �摜�̏����擾

	HRESULT hr;

	// �e�N�X�`������T�[�t�F�C�X���擾
	IDirect3DSurface9* surface;
	hr = lpTexture->GetSurfaceLevel(0, &surface);
	

	if (FAILED(hr)) {
		RELEASE(surface);
		return false;
	}

	// �T�[�t�F�C�X��񂩂�摜�T�C�Y���擾
	D3DSURFACE_DESC surfaceInfo;
	hr = surface->GetDesc(&surfaceInfo);

	if (FAILED(hr)) {
		return false;
	}

	// �摜�̏c���Ɖ������擾
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


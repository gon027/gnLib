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

	// �e�N�X�`���̓ǂݍ���
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
	// �摜�̏����擾

	HRESULT hr;

	// �e�N�X�`������T�[�t�F�C�X���擾
	IDirect3DSurface9* surface;
	hr = texture->GetSurfaceLevel(0, &surface);

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

#include "../../include/Texture/Texture.h"
#include "../../include/Common/Macro.h"
#include "../../include/Graphics/Graphics.h"
#include "../../include/Render/Render.h"
#include "../../include/GameCore/GameCore.h"

namespace gnLib {
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
		hr = D3DXCreateTextureFromFile(
			GCoreIns->getGraphic()->getDevice(),
			_filePath.c_str(),
			&lpTexture
		);

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
		size.setSize(
			static_cast<float>(surfaceInfo.Width),
			static_cast<float>(surfaceInfo.Height)
		);

		RELEASE(surface);

		return true;
	}

	const float Texture::getWidth()
	{
		return size.getWidth();
	}

	const float Texture::getHeight()
	{
		return size.getHeight();
	}

	const bool Texture::isLoading()
	{
		return lpTexture;
	}

	LPDIRECT3DTEXTURE9 Texture::getTexture() const
	{
		return lpTexture;
	}

}
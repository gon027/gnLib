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

		// �摜�̏c�Ɖ��̕����擾
		D3DXIMAGE_INFO imgInfo;
		D3DXGetImageInfoFromFile(_filePath.c_str(), &imgInfo);

		hr = D3DXCreateTextureFromFileEx(
			GCGraphics,
			_filePath.c_str(),
			imgInfo.Width,      // �ǂݍ��މ摜�̕�
			imgInfo.Height,     // �ǂݍ��މ摜�̍���
			D3DX_DEFAULT,       // MipLevels
			0,                  // Usage
			D3DFMT_UNKNOWN,     // Format
			D3DPOOL_MANAGED,    // Pool
			D3DX_DEFAULT,       // �t�B���^�����O���@
			D3DX_DEFAULT,       // �~�j�}�b�v�ɑ΂��čs����t�B���^�����O�@
			0,                  // �J���[�L�[
			NULL,               // ���̉摜�̏����i�[����D3DXIMAGE_INFO�̃|�C���^
			NULL,               // 256�t�H�[�}�b�g�̏ꍇ�ɂ̂ݎg����
			&lpTexture          // ���������e�N�X�`���I�u�W�F�N�g�ւ̃|�C���^���Ԃ�
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
		size.setSize(surfaceInfo.Width, surfaceInfo.Height);

		RELEASE(surface);

		return true;
	}

	const int Texture::getWidth()
	{
		return size.getWidth();
	}

	const int Texture::getHeight()
	{
		return size.getHeight();
	}

	const Size& Texture::getSize()
	{
		return size;
	}

	bool Texture::isLoading()
	{
		return lpTexture;
	}

	LPDIRECT3DTEXTURE9 Texture::getTexture() const
	{
		return lpTexture;
	}

	TextureSPtr Texture::createTexture(const string& _filePath)
	{
		//TextureSPtr result = std::make_shared<Texture>(_filePath);
		return std::make_shared<Texture>(_filePath);
	}

	vector<RECT> Texture::spriteTexture(int _xSize, int _ySize, int _textureWidth, int _textureHeight)
	{
		int width{ _textureWidth / _xSize };
		int height{ _textureHeight / _ySize };

		int size{ width * height };
		vector<RECT> result(size);

		for (int i{}; i < height - 1; ++i) {
			for (int j{}; j < width - 1; ++j) {

				auto index = static_cast<long>(i) * static_cast<long>(width) + static_cast<long>(j);

				result[index] = RECT{ _xSize * j, _ySize * i, _xSize * (j + 1), _ySize * (i + 1) };
			}
		}

		return result;
	}

	vector<RECT> Texture::spriteTexture(Texture& _texture, int _xSize, int _ySize)
	{
		return spriteTexture(_xSize, _ySize, _texture.getWidth(), _texture.getHeight());
	}

}
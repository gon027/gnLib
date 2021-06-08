#include <Texture/Texture.h>
#include <Common/Macro.h>
#include <Graphics/Graphics.h>
#include <Render/Render.h>
#include <GameCore/GameCore.h>

namespace gnLib {

	namespace helper {

		// �e�N�X�`���̃T�C�Y���擾����
		Size getTextureSize(const string& _filePath) {
			Size size{};
			D3DXIMAGE_INFO imgInfo;
			D3DXGetImageInfoFromFile(_filePath.c_str(), &imgInfo);
			size.width = imgInfo.Width;
			size.height = imgInfo.Height;
			return size;
		}

		// �ǂݍ��܂ꂽ�e�N�X�`������e�N�X�`���̃T�C�Y���擾
		Size getTextureSize(LPDIRECT3DTEXTURE9 _lpTexture)
		{
			Size size{};

			if (!_lpTexture) {
				return size;
			}

			HRESULT hr;

			// �e�N�X�`������T�[�t�F�C�X���擾
			IDirect3DSurface9* surface;
			hr = _lpTexture->GetSurfaceLevel(0, &surface);

			if (FAILED(hr)) {
				RELEASE(surface);
				return size;
			}

			// �T�[�t�F�C�X��񂩂�摜�T�C�Y���擾
			D3DSURFACE_DESC surfaceInfo;
			hr = surface->GetDesc(&surfaceInfo);

			if (FAILED(hr)) {
				return size;
			}

			// �摜�̏c���Ɖ������擾
			size.width = surfaceInfo.Width;
			size.height = surfaceInfo.Height;

			RELEASE(surface);

			return size;
		}

		// �e�N�X�`���̃|�C���^���쐬����
		LPDIRECT3DTEXTURE9 createTexture(const string& _filePath) {
			LPDIRECT3DTEXTURE9 result{ nullptr };
			
			// �摜�̏c�Ɖ��̕����擾
			auto size = getTextureSize(_filePath);

			HRESULT hr;
			hr = D3DXCreateTextureFromFileEx(
				GCGraphics,
				_filePath.c_str(),
				size.width,                    // �ǂݍ��މ摜�̕�
				size.height,                    // �ǂݍ��މ摜�̍���
				D3DX_DEFAULT,                       
				0,                                  
				D3DFMT_UNKNOWN,                     
				D3DPOOL_MANAGED,                    
				D3DX_DEFAULT,                       
				D3DX_DEFAULT,                       
				D3DCOLOR_ARGB(255, 255, 255, 0),    // ���ߐF
				NULL,                               
				NULL,                               
				&result                             // ���������e�N�X�`���I�u�W�F�N�g�ւ̃|�C���^���Ԃ�
			);

			if (FAILED(hr)) {
				return result;
			}

			return result;
		}

		// �w�肵���T�C�Y�̃e�N�X�`���̃|�C���^���쐬����
		LPDIRECT3DTEXTURE9 createTexture(const string& _filePath, int _width, int _height) {
			LPDIRECT3DTEXTURE9 result{ nullptr };

			D3DXCreateTextureFromFileEx(
				GCGraphics,
				_filePath.c_str(),
				_width,                    // �ǂݍ��މ摜�̕�
				_height,                    // �ǂݍ��މ摜�̍���
				D3DX_DEFAULT,
				0,
				D3DFMT_UNKNOWN,
				D3DPOOL_MANAGED,
				D3DX_DEFAULT,
				D3DX_DEFAULT,
				D3DCOLOR_ARGB(255, 255, 255, 0),    // ���ߐF
				NULL,
				NULL,
				&result                             // ���������e�N�X�`���I�u�W�F�N�g�ւ̃|�C���^���Ԃ�
			);

			return result;
		}

		// ��̃e�N�X�`�����쐬
		LPDIRECT3DTEXTURE9 createEmptyTexture(int _width, int _height) {
			LPDIRECT3DTEXTURE9 result{ nullptr };

			D3DXCreateTexture(
				GCGraphics,
				_width,
				_height,
				0,                 // Levels
				0,                 // Usage
				D3DFMT_UNKNOWN,    // Format
				D3DPOOL_MANAGED,   // Pool
				&result
			);
			
			return result;
		}
	}


	Texture::Texture()
		: lpTexture(nullptr)
	{

	}

	Texture::Texture(const string& _filePath)
		: lpTexture(helper::createTexture(_filePath))
		, size(helper::getTextureSize(lpTexture))
	{
	}

	Texture::~Texture()
	{
		RELEASE(lpTexture);
	}

	const int Texture::getWidth()
	{
		return size.width;
	}

	const int Texture::getHeight()
	{
		return size.height;
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
		return std::make_shared<Texture>(_filePath);
	}

	TextureRegion Texture::spriteTexture(TextureSPtr& _texture, int _xNum, int _yNum)
	{
		return spriteTexture(_texture->getWidth(), _texture->getHeight(), _xNum, _yNum);
	}

	TextureRegion Texture::spriteTexture(int _textureWidth, int _textureHeight, int _xNum, int _yNum)
	{
		int xSize{ _textureWidth  / _xNum };
		int ySize{ _textureHeight / _yNum };

		int size{ _xNum * _yNum };
		vector<TextureRect> result(size);

		for (int i{}; i < _yNum; ++i) {
			for (int j{}; j < _xNum; ++j) {

				auto index = static_cast<long>(i) * static_cast<long>(_xNum) + static_cast<long>(j);

				result[index] = TextureRect{
					xSize * j,
					ySize * i,
					xSize * (j + 1),
					ySize * (i + 1)
				};
			}
		}

		return result;
	}
}
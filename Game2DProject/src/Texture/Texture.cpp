#include "../../include/Texture/Texture.h"
#include "../../include/Common/Macro.h"
#include "../../include/Graphics/Graphics.h"
#include "../../include/Render/Render.h"
#include "../../include/GameCore/GameCore.h"

namespace gnLib {

	namespace helper {

		// �e�N�X�`���̃T�C�Y���擾����
		Size getTextureSize(const string& _filePath) {
			Size size{};
			D3DXIMAGE_INFO imgInfo;
			D3DXGetImageInfoFromFile(_filePath.c_str(), &imgInfo);
			size.setSize(imgInfo.Width, imgInfo.Height);
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
			size.setSize(surfaceInfo.Width, surfaceInfo.Height);

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
				size.getWidth(),                    // �ǂݍ��މ摜�̕�
				size.getHeight(),                    // �ǂݍ��މ摜�̍���
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
		//loadTexture(_filePath);
	}

	Texture::~Texture()
	{
		RELEASE(lpTexture);
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

	namespace umImpl {

	}

	LPDIRECT3DTEXTURE9 cet()
	{
		return helper::createEmptyTexture(32, 32);
	}

	LPDIRECT3DTEXTURE9 ct(const string& _s)
	{
		return helper::createTexture(_s);
	}

	TextureTest::TextureTest(const string& _filePath)
		: lpTexture(helper::createTexture(_filePath))
		, size(helper::getTextureSize(lpTexture))
		, emp(helper::createEmptyTexture(32, 32))
		, esize(helper::getTextureSize(emp))
	{

	}

	TextureTest::~TextureTest()
	{
		RELEASE(lpTexture);
	}

	// ������
	void TextureTest::test()
	{
		// �e�N�X�`���Ƀt�H���g�r�b�g�}�b�v��������
		D3DLOCKED_RECT lockedRect, copyRect;
		// ���b�N
		lpTexture->LockRect(0, &copyRect, NULL, D3DLOCK_READONLY);


		// ���b�N
		emp->LockRect(0, &lockedRect, NULL, D3DLOCK_DISCARD);
		ZeroMemory(lockedRect.pBits, lockedRect.Pitch);

		for (int y = 0; y < 32; ++y) {
			for (int x = 0; x < 32; ++x) {
				//(BYTE*)((lockedRect.pBits) + 1) = 0;
				memcpy(
					(BYTE*)lockedRect.pBits + lockedRect.Pitch * y + 4 * x, 
					(BYTE*)copyRect.pBits + copyRect.Pitch * y + 4 * x,
					sizeof(DWORD)
				);
			}
		}
		

		emp->UnlockRect(0);

		lpTexture->UnlockRect(0);

	}

}
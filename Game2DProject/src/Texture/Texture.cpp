#include "../../include/Texture/Texture.h"
#include "../../include/Common/Macro.h"
#include "../../include/Graphics/Graphics.h"
#include "../../include/Render/Render.h"
#include "../../include/GameCore/GameCore.h"

namespace gnLib {

	namespace helper {

		// テクスチャのサイズを取得する
		Size getTextureSize(const string& _filePath) {
			Size size{};
			D3DXIMAGE_INFO imgInfo;
			D3DXGetImageInfoFromFile(_filePath.c_str(), &imgInfo);
			size.setSize(imgInfo.Width, imgInfo.Height);
			return size;
		}

		// 読み込まれたテクスチャからテクスチャのサイズを取得
		Size getTextureSize(LPDIRECT3DTEXTURE9 _lpTexture)
		{
			Size size{};

			if (!_lpTexture) {
				return size;
			}

			HRESULT hr;

			// テクスチャからサーフェイスを取得
			IDirect3DSurface9* surface;
			hr = _lpTexture->GetSurfaceLevel(0, &surface);

			if (FAILED(hr)) {
				RELEASE(surface);
				return size;
			}

			// サーフェイス情報から画像サイズを取得
			D3DSURFACE_DESC surfaceInfo;
			hr = surface->GetDesc(&surfaceInfo);

			if (FAILED(hr)) {
				return size;
			}

			// 画像の縦幅と横幅を取得
			size.setSize(surfaceInfo.Width, surfaceInfo.Height);

			RELEASE(surface);

			return size;
		}

		// テクスチャのポインタを作成する
		LPDIRECT3DTEXTURE9 createTexture(const string& _filePath) {
			LPDIRECT3DTEXTURE9 result{ nullptr };
			
			// 画像の縦と横の幅を取得
			auto size = getTextureSize(_filePath);

			HRESULT hr;
			hr = D3DXCreateTextureFromFileEx(
				GCGraphics,
				_filePath.c_str(),
				size.getWidth(),                    // 読み込む画像の幅
				size.getHeight(),                    // 読み込む画像の高さ
				D3DX_DEFAULT,                       
				0,                                  
				D3DFMT_UNKNOWN,                     
				D3DPOOL_MANAGED,                    
				D3DX_DEFAULT,                       
				D3DX_DEFAULT,                       
				D3DCOLOR_ARGB(255, 255, 255, 0),    // 透過色
				NULL,                               
				NULL,                               
				&result                             // 生成したテクスチャオブジェクトへのポインタが返る
			);

			if (FAILED(hr)) {
				return result;
			}

			return result;
		}

		// 指定したサイズのテクスチャのポインタを作成する
		LPDIRECT3DTEXTURE9 createTexture(const string& _filePath, int _width, int _height) {
			LPDIRECT3DTEXTURE9 result{ nullptr };

			D3DXCreateTextureFromFileEx(
				GCGraphics,
				_filePath.c_str(),
				_width,                    // 読み込む画像の幅
				_height,                    // 読み込む画像の高さ
				D3DX_DEFAULT,
				0,
				D3DFMT_UNKNOWN,
				D3DPOOL_MANAGED,
				D3DX_DEFAULT,
				D3DX_DEFAULT,
				D3DCOLOR_ARGB(255, 255, 255, 0),    // 透過色
				NULL,
				NULL,
				&result                             // 生成したテクスチャオブジェクトへのポインタが返る
			);

			return result;
		}

		// 空のテクスチャを作成
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

	// 初期化
	void TextureTest::test()
	{
		// テクスチャにフォントビットマップ書き込み
		D3DLOCKED_RECT lockedRect, copyRect;
		// ロック
		lpTexture->LockRect(0, &copyRect, NULL, D3DLOCK_READONLY);


		// ロック
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
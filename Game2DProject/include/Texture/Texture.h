#ifndef TEXTURE_H
#define TEXTURE_H

#include <string>
#include <vector>
#include "../Common/Lib.h"
#include "../Common/SmartPtr.h"
#include "../Size/Size.h"

using std::string;
using std::vector;

namespace gnLib {

	class Texture;

	// Textureのshared_ptr
	using TextureSPtr = SharedPtr<Texture>;

	// Textureのweak_ptr
	using TextureWPtr = WeakPtr<Texture>;

	struct TextureRect{
		int left;
		int top;
		int right;
		int bottom;
	};

	// 画像を読み込むクラス
	class Texture {
	public:
		static TextureSPtr createTexture(const string& _filePath);

		// 画像を分割する
		// TODO : もう少しいい処理を後で書く
		static vector<RECT> spriteTexture(int _xSize, int _ySize, int _textureWidth, int _textureHeight);

		static vector<RECT> spriteTexture(Texture& _texture, int _xSize, int _ySize);

	public:
		Texture();
		Texture(const string& _filePath);
		~Texture();

		// 画像読み込み
		bool loadTexture(const string& _filePath);

		// 画像の幅
		const int getWidth();

		// 画像の高さ
		const int getHeight();

		// 画像のサイズ取得
		const Size& getSize();

		// 画像が読み込めているか
		bool isLoading();

		LPDIRECT3DTEXTURE9 getTexture() const;

	private:
		// 画像の幅と逆さを取得
		bool imageInfo();

	private:
		LPDIRECT3DTEXTURE9 lpTexture;
		Size size;
	};
}

#endif // !TEXTURE_H

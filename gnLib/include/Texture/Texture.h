#ifndef TEXTURE_H
#define TEXTURE_H

#include <string>
#include <vector>
#include <Common/Lib.h>
#include <Common/SmartPtr.h>
#include <Size/Size.h>

using std::string;
using std::vector;

namespace gnLib {

	class Texture;

	struct TextureRect {
		int left;
		int top;
		int right;
		int bottom;
	};

	// Textureのshared_ptr
	using TextureSPtr = SharedPtr<Texture>;

	// Textureのweak_ptr
	using TextureWPtr = WeakPtr<Texture>;

	// Textureの領域
	using TextureRegion = std::vector<TextureRect>;

	// 画像を読み込むクラス
	class Texture {
	public:
		static TextureSPtr createTexture(const string& _filePath);

		// 画像を分割する
		static TextureRegion spriteTexture(TextureSPtr& _texture, int _xNum, int _yNum);

		static TextureRegion spriteTexture(int _textureWidth, int _textureHeight, int _xNum, int _yNum);

	public:
		Texture();
		Texture(const string& _filePath);
		~Texture();

		// 画像の幅
		const int getWidth();

		// 画像の高さ
		const int getHeight();

		// 画像のサイズ取得
		const Size& getSize();

		// 画像が読み込めているか
		bool isLoading();

		// テクスチャのポインタを取得
		LPDIRECT3DTEXTURE9 getTexture() const;

	private:
		LPDIRECT3DTEXTURE9 lpTexture;
		Size size;
	};
}

#endif // !TEXTURE_H

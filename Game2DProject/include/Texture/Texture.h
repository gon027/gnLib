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

	// 画像を読み込むクラス
	class Texture {
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
		const Size& getTextureSize();

		// 画像が読み込めているか
		bool isLoading();

		LPDIRECT3DTEXTURE9 getTexture() const;

		// 画像を分割する
		// TODO : もう少しいい処理を後で書く
		static vector<RECT> spriteTexture(int _xNum, int _yNum, int _xSize, int _ySize);

		static vector<RECT> spriteTexture(Texture& _texture, int _xNum, int _yNum);

	private:
		// 画像の幅と逆さを取得
		bool imageInfo();

	private:
		LPDIRECT3DTEXTURE9 lpTexture;
		Size size;
	};
}

#endif // !TEXTURE_H

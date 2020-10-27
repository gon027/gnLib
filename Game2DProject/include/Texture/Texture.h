#ifndef TEXTURE_H
#define TEXTURE_H

#include <string>
#include "../Common/Lib.h"
#include "../Common/SmartPtr.h"
#include "../Size/Size.h"

using string = std::string;

namespace gnLib {

	// 画像を読み込むクラス
	class Texture {
	public:
		Texture();
		Texture(const string& _filePath);
		~Texture();

		// 画像読み込み
		bool loadTexture(const string& _filePath);

		const float getWidth();
		const float getHeight();

		// 画像のサイズ取得
		Size getTextureSize();

		// 画像が読み込めているか
		const bool isLoading();

		LPDIRECT3DTEXTURE9 getTexture() const;

		string toString() {
			return "[x = " + std::to_string(getWidth()) +
				+", y = " + std::to_string(getHeight()) + "]";
		};

	private:
		LPDIRECT3DTEXTURE9 lpTexture;
		Size size;

		// 画像の幅と逆さを取得
		bool imageInfo();
	};

}

#endif // !TEXTURE_H

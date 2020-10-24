#ifndef TEXTURE_H
#define TEXTURE_H

#pragma comment(lib, "d3d9.lib")
#pragma comment(lib, "d3dx9.lib")
#pragma comment(lib, "d3dxof.lib")
#include <d3d9.h>
#include <d3dx9.h>

#include <string>
#include "../Common/SmartPtr.h"
#include "../Size/Size.h"

using string = std::string;

namespace gnLib {

	// �摜��ǂݍ��ރN���X
	class Texture {
	public:
		Texture();
		Texture(const string& _filePath);
		~Texture();

		// �摜�ǂݍ���
		bool loadTexture(const string& _filePath);

		const float getWidth();
		const float getHeight();

		// �摜�̃T�C�Y�擾
		Size getTextureSize();

		// �摜���ǂݍ��߂Ă��邩
		const bool isLoading();

		LPDIRECT3DTEXTURE9 getTexture() const;

		string toString() {
			return "[x = " + std::to_string(getWidth()) +
				+", y = " + std::to_string(getHeight()) + "]";
		};

	private:
		LPDIRECT3DTEXTURE9 lpTexture;
		Size size;

		// �摜�̕��Ƌt�����擾
		bool imageInfo();
	};

}

#endif // !TEXTURE_H

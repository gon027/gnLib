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

	// �摜��ǂݍ��ރN���X
	class Texture {
	public:
		Texture();
		Texture(const string& _filePath);
		~Texture();

		// �摜�ǂݍ���
		bool loadTexture(const string& _filePath);

		// �摜�̕�
		const int getWidth();

		// �摜�̍���
		const int getHeight();

		// �摜�̃T�C�Y�擾
		const Size& getTextureSize();

		// �摜���ǂݍ��߂Ă��邩
		bool isLoading();

		LPDIRECT3DTEXTURE9 getTexture() const;

		// �摜�𕪊�����
		// TODO : ��������������������ŏ���
		static vector<RECT> spriteTexture(int _xNum, int _yNum, int _xSize, int _ySize);

		static vector<RECT> spriteTexture(Texture& _texture, int _xNum, int _yNum);

	private:
		// �摜�̕��Ƌt�����擾
		bool imageInfo();

	private:
		LPDIRECT3DTEXTURE9 lpTexture;
		Size size;
	};
}

#endif // !TEXTURE_H

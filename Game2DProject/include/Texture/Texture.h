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

	// Texture��shared_ptr
	using TextureSPtr = SharedPtr<Texture>;

	// Texture��weak_ptr
	using TextureWPtr = WeakPtr<Texture>;

	struct TextureRect{
		int left;
		int top;
		int right;
		int bottom;
	};

	// �摜��ǂݍ��ރN���X
	class Texture {
	public:
		static TextureSPtr createTexture(const string& _filePath);

		// �摜�𕪊�����
		// TODO : ��������������������ŏ���
		static vector<RECT> spriteTexture(int _xSize, int _ySize, int _textureWidth, int _textureHeight);

		static vector<RECT> spriteTexture(Texture& _texture, int _xSize, int _ySize);

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
		const Size& getSize();

		// �摜���ǂݍ��߂Ă��邩
		bool isLoading();

		LPDIRECT3DTEXTURE9 getTexture() const;

	private:
		// �摜�̕��Ƌt�����擾
		bool imageInfo();

	private:
		LPDIRECT3DTEXTURE9 lpTexture;
		Size size;
	};
}

#endif // !TEXTURE_H

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

	// Texture��shared_ptr
	using TextureSPtr = SharedPtr<Texture>;

	// Texture��weak_ptr
	using TextureWPtr = WeakPtr<Texture>;

	// Texture�̗̈�
	using TextureRegion = std::vector<TextureRect>;

	// �摜��ǂݍ��ރN���X
	class Texture {
	public:
		static TextureSPtr createTexture(const string& _filePath);

		// �摜�𕪊�����
		static TextureRegion spriteTexture(TextureSPtr& _texture, int _xNum, int _yNum);

		static TextureRegion spriteTexture(int _textureWidth, int _textureHeight, int _xNum, int _yNum);

	public:
		Texture();
		Texture(const string& _filePath);
		~Texture();

		// �摜�̕�
		const int getWidth();

		// �摜�̍���
		const int getHeight();

		// �摜�̃T�C�Y�擾
		const Size& getSize();

		// �摜���ǂݍ��߂Ă��邩
		bool isLoading();

		// �e�N�X�`���̃|�C���^���擾
		LPDIRECT3DTEXTURE9 getTexture() const;

	private:
		LPDIRECT3DTEXTURE9 lpTexture;
		Size size;
	};
}

#endif // !TEXTURE_H

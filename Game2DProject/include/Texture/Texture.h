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
	class Graphics;

	class Texture {
	public:
		Texture();
		Texture(const string& _filePath);
		~Texture();

		// ‰æ‘œ“Ç‚İ‚İ
		bool loadTexture(const string& _filePath);

		const float getWidth();
		const float getHeight();

		// ‰æ‘œ‚ª“Ç‚İ‚ß‚Ä‚¢‚é‚©
		const bool isLoading();

		LPDIRECT3DTEXTURE9 getTexture() const;

	private:
		LPDIRECT3DTEXTURE9 lpTexture;
		Size size;

		// ‰æ‘œ‚Ì•‚Æ‹t‚³‚ğæ“¾
		bool imageInfo();
	};
}

#endif // !TEXTURE_H

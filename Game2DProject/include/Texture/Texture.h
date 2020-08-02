#ifndef TEXTURE_H
#define TEXTURE_H

#pragma comment(lib, "d3d9.lib")
#pragma comment(lib, "d3dx9.lib")
#pragma comment(lib, "d3dxof.lib")
#include <d3d9.h>
#include <d3dx9.h>

#include <string>
#include "../Common/SmartPtr.h"

using string = std::string;

namespace gnLib {
	class Graphics;

	class Texture {
	public:
		Texture();
		Texture(const string& _filePath);
		~Texture();

		bool loadTexture(const string& _filePath);

		bool imageInfo();

		const int getWidth();
		const int getHeight();

		// âÊëúÇ™ì«Ç›çûÇﬂÇƒÇ¢ÇÈÇ©
		const bool isLoading();

		LPDIRECT3DTEXTURE9 getTexture() const;

	private:

		LPDIRECT3DTEXTURE9 lpTexture;
		int width;
		int height;
	};
}

#endif // !TEXTURE_H

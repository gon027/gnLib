#ifndef TEXTURE_H
#define TEXTURE_H

#pragma comment(lib, "d3d9.lib")
#pragma comment(lib, "d3dx9.lib")
#pragma comment(lib, "d3dxof.lib")
#include <d3d9.h>
#include <d3dx9.h>

#include <string>
#include "SmartPtr.h"

class Graphics;
using string = std::string;

class Texture {
public:
	Texture();
	Texture(const string& _filePath);
	~Texture();

	bool loadTexture(const string& _filePath);

	bool imageInfo();

	const int getWidth();
	const int getHeight();

	// ‰æ‘œ‚ª“Ç‚İ‚ß‚Ä‚¢‚é‚©
	const bool isLoading();

	LPDIRECT3DTEXTURE9 getTexture() const;

private:
	
	LPDIRECT3DTEXTURE9 lpTexture;
	int width;
	int height;
};

#endif // !TEXTURE_H

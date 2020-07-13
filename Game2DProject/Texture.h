#ifndef TEXTURE_H
#define TEXTURE_H

#pragma comment(lib, "d3d9.lib")
#pragma comment(lib, "d3dx9.lib")
#pragma comment(lib, "d3dxof.lib")
#include <d3d9.h>
#include <d3dx9.h>

#include <map>
#include <string>
#include <memory>

class Graphics;

class Texture {
public:
	Texture();
	~Texture();

	bool loadTexture(Graphics& _graphics, const char* _filePath);

	bool imageInfo();

	const LPDIRECT3DTEXTURE9 getTexture();

	const int getWidth();

	const int getHeight();

private:
	LPDIRECT3DTEXTURE9 texture;
	int width;
	int height;
};

#endif // !TEXTURE_H

#ifndef GRAPHICS_H
#define GRAPHICS_H

#pragma comment(lib, "d3d9.lib")
#pragma comment(lib, "d3dx9.lib")
#pragma comment(lib, "d3dxof.lib")
#include <d3d9.h>
#include <d3dx9.h>

#include "Window.h"

class Graphics {
public:
	Graphics();
	~Graphics();

	// Graphic�̍쐬
	bool createGraphics(window::Window* _window) noexcept;

	void begin() noexcept;		//�`��J�n
	void end() noexcept;		//�`��I��

	IDirect3D9* getInterface() const;
	IDirect3DDevice9* getDevice() const;

private:
	IDirect3D9*		pD3D9;		    // Direct3D�f�o�C�X�����p�I�u�W�F�N�g
	IDirect3DDevice9*	device;	    // Direct3D�̃f�o�C�X
};

#endif // !GRAPHICS_H

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
	Graphics(window::Window* _window);
	~Graphics();

	// Graphicの作成
	bool create(window::Window& _win) noexcept;

	void begin() noexcept;		//描画開始
	void end() noexcept;		//描画終了

public:
	IDirect3D9*		pD3D9;		    // Direct3Dデバイス生成用オブジェクト
	IDirect3DDevice9*	device;	    // Direct3Dのデバイス

private:
	window::Window *win;
};

#endif // !GRAPHICS_H

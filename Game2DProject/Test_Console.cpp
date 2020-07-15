#include "Window.h"
#include "Graphics.h"
#include "Console.h"
#include "Sprite.h"

using namespace console;

void Main();

/*
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrefInstance, LPSTR lpCmdLine, int nCmdShow) {

	Main();
	
	return 0;
}
*/

/*
void Main() {
	Console con;
	con.createConsole();
	for (int i = 0; i < 20; ++i) {
		con.print("Hello World\n");
		con.print("123\n");
	}

	window::Window win{};
	win.createWindow();

	Graphics g;
	g.createGraphics(win);

	Sprite sp;
	sp.loadTexture(g, "img/backscreen.jpg");

	while (win.update()) {
		g.begin();
		g.device->Clear(0, NULL, D3DCLEAR_TARGET, D3DCOLOR_XRGB(0xFF, 0xFF, 0xFF), 1.0, 0);

		sp.draw(320, 240);

		g.end();
	}
}
*/
#include "App.h"
#include "Console.h"
#include "Window.h"
#include "Graphics.h"
using namespace window;

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrefInstance, LPSTR lpCmdLine, int nCmdShow) {
	console::Console c;
	c.createConsole();

	App app;
	app.initWindow(640, 480, "aaa");

	c.print("aaa");

	while (app.update())
	{
		app.begin();

		app.end();
	}
}
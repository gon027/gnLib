#include "App.h"
#include "Window.h"
using namespace window;

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrefInstance, LPSTR lpCmdLine, int nCmdShow) {
	App app;
	app.initWindow(640, 480, "aaa");

	while (app.update())
	{

	}
}
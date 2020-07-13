#include "App.h"

#include "Window.h"
#include "Graphics.h"
using namespace window;

App::App()
	: window()
	, graphics(new Graphics)
{

}

App::~App()
{

}

void App::initWindow(int _width, int _height, std::string _windowTitle)
{
	window.create();
//	window.get()->create();
	graphics.get()->create(window);
}

bool App::update()
{
	return window.update();
}

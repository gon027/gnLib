#include "App.h"

#include "Window.h"
#include "Graphics.h"

App::App()
	: window(new Window())
	, graphics(new Graphics())
{

}

App::~App()
{

}

void App::initWindow(int _width, int _height, std::string _windowTitle)
{
	window.get()->createGraphics();
	graphics.get()->createGraphics(window.get());
}

bool App::update()
{
	return window->update();
}

void App::begin()
{
	graphics.get()->begin();
}

void App::end()
{
	graphics.get()->end();
}

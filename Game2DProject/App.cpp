#include "App.h"

#include "Window.h"
#include "Graphics.h"

App::App(std::string _title, int _width, int _height)
	: window(new Window(_title, _width, _height))
	, graphics(new Graphics())
{
	window.get()->createWindow();
	graphics.get()->createGraphics(window.get());
}

App::~App()
{

}

void App::initWindow()
{
	window.get()->createWindow();
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

Window * App::getWindow() const
{
	return window.get();
}

Graphics * App::getGraphics() const
{
	return graphics.get();
}

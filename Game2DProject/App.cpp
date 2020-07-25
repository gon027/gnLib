#include "App.h"

#include "Window.h"
#include "Graphics.h"
#include <memory>

App::App(std::string _title, int _width, int _height)
	: window(new Window(_title, _width, _height))
	, graphics(new Graphics())
	, fpsManager()
{
	window.get()->createWindow();
	graphics.get()->createGraphics(window.get());
	RenderIns->setGraphics(graphics.get());
}

App::~App()
{

}

void App::initWindow()
{
	window.get()->createWindow();
	graphics.get()->createGraphics(window.get());
}

bool App::doEvent()
{
	MSG msg{};

	while (true) {
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE)) {

			if (msg.message == WM_QUIT) {
				return false;
			}

			::TranslateMessage(&msg);
			::DispatchMessage(&msg);
		}
		else {
			return true;
		}
	}
}

bool App::update()
{

	return false;
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

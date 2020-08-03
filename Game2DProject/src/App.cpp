#include "../include/App.h"
#include "../include/Window/Window.h"
#include "../include/Graphics/Graphics.h"
#include "../include/Render/Render.h"
#include "../include/Input/Input.h"
//#include "../GameCore.h"

namespace gnLib {
	App::App(std::string _title, int _width, int _height)
		: gCore()
		//: window(new Window(_title, _width, _height))
		//, graphics(new Graphics())
		//, windowWidth(_width)
		//, windowHeight(_height)
	{
		//window.get()->createWindow();
		//graphics.get()->createGraphics(window.get());
		//RenderIns->setGraphics(graphics.get());
		//Input::init(window.get());

		//GameCore::createWindow(_title, _width, _height);
		//GameCore::init();

		GCoreIns->initWindow(_title, _width, _height);
		GCoreIns->init();
	}

	App::~App()
	{

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
		Input::update();
		return false;
	}

	void App::begin()
	{
		GCoreIns->getGraphic()->begin();
		GCoreIns->update();
	}

	void App::end()
	{
		GCoreIns->getGraphic()->end();
	}

	int App::getWidth() const
	{
		return WindowInfo::Width;
	}

	int App::getHeight() const
	{
		return WindowInfo::Height;
	}

}
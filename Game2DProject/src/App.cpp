#include "../include/App.h"
#include "../include/Window/Window.h"
#include "../include/Graphics/Graphics.h"
#include "../include/Render/Render.h"
#include "../include/Input/Input.h"

namespace gnLib {
	App::App(std::string _title, int _width, int _height)
		: gCore()
	{
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
		//Input::update();
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
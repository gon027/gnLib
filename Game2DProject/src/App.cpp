#include "../include/App.h"
#include "../include/Window/Window.h"
#include "../include/Graphics/Graphics.h"
#include "../include/Render/Render.h"
#include "../include/Input/Input.h"

#include <assert.h>

namespace gnLib {
	App::App(std::string _title, int _width, int _height)
	{
		// title‚ª‹ó”’‚Ìê‡AƒGƒ‰[‚Æ‚·‚é
		assert(_title != "");

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

	float App::getWidth() const
	{
		return static_cast<float>(WindowInfo::Width);
	}

	float App::getHeight() const
	{
		return static_cast<float>(WindowInfo::Height);
	}

	Vector2 App::getPos() const
	{
		return Vector2{
			static_cast<float>(WindowInfo::Width),
			static_cast<float>(WindowInfo::Height)
		};
	}

}
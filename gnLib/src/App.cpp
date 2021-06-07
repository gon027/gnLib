#include "../include/App.h"
#include "../include/Window/Window.h"
#include "../include/Graphics/Graphics.h"
#include "../include/Render/Render.h"
#include "../include/Input/Input.h"
#include "../include/SpriteRender/SpriteRender.h"
#include "../include/Common/SmartPtr.h"
#include "../include/GameCore/GameCore.h"
#include "../include/Time/GameTime.h"

#include <assert.h>

namespace gnLib {
	bool App::init(std::string _title, int _width, int _height) {

		// title‚ª‹ó”’‚Ìê‡AƒGƒ‰[‚Æ‚·‚é
		assert(_title != "");

		GCoreIns->initWindow(_title, _width, _height);
		GCoreIns->init();

		return true;
	}

	bool App::update() {
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

	void App::begin() {
		GCoreIns->getGraphic()->begin();
		GCGameTime->beginTime();
		GCSprite->begin();
		GCoreIns->update();
	}

	void App::end() {
		GCSprite->end();
		GCGameTime->endTime();
		GCoreIns->getGraphic()->end();
	}

	void App::setTitle(const std::string& _title)
	{
		GCWindow->setTitle(_title);
	}

	void App::setWindowPosition(int _x, int _y)
	{
		GCWindow->setWindowPosition(_x, _y);
	}

	const Vector2 App::getWindowSize() {
		return {
			static_cast<float>(WindowInfo::Width),
			static_cast<float>(WindowInfo::Height)
		};
	}
}
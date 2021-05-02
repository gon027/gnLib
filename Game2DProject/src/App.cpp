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

		// titleが空白の場合、エラーとする
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

	const Vector2 getWindowSize() {
		return {
			static_cast<float>(WindowInfo::Width),
			static_cast<float>(WindowInfo::Height)
		};
	}

	/*
	App::App(std::string _title, int _width, int _height)
	{
		// titleが空白の場合、エラーとする
		assert(_title != "");

		GCoreIns->initWindow(_title, _width, _height);
		GCoreIns->init();
	}

	App::~App()
	{

	}

	bool App::update()
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

	void App::begin()
	{
		GCoreIns->getGraphic()->begin();
		GCGameTime->beginTime();
		GCSprite->begin();
		GCoreIns->update();
	}

	void App::end()
	{
		GCSprite->end();
		GCGameTime->endTime();
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
	*/
}
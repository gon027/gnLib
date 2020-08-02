#include "GameCore.h"
#include "include/Window/Window.h"
#include "include/Graphics/Graphics.h"
#include "include/Input/KeyInput.h"
#include "include/Input/MouseInput.h"

namespace gnLib {
	UniquePtr<Window> GameCore::window{ new Window("Test") };
	UniquePtr<Graphics> GameCore::graphics{ new Graphics() };
	UniquePtr<KeyInput> GameCore::keyBoard{ new KeyInput() };
	UniquePtr<MouseInput> GameCore::mouse{ new MouseInput() };

	void GameCore::init()
	{
		window.get()->createWindow();

		graphics.get()->createGraphics(window.get());

		keyBoard.get()->init(window.get());

		mouse.get()->init(window.get());
	}

	void GameCore::update()
	{
		keyBoard.get()->update();
		mouse.get()->update();
	}

	Window * gnLib::GameCore::getWindow()
	{
		return window.get();
	}

	Graphics * gnLib::GameCore::getGraphic()
	{
		return graphics.get();
	}

	KeyInput * gnLib::GameCore::getKeyBoard()
	{
		return keyBoard.get();
	}

	MouseInput * gnLib::GameCore::getMouse()
	{
		return mouse.get();
	}

}

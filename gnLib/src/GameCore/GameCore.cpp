#include "../../include/GameCore/GameCore.h"
#include "../../include/Window/Window.h"
#include "../../include/Graphics/Graphics.h"
#include "../../include/Input/KeyInput.h"
#include "../../include/Input/MouseInput.h"
#include "../../include/SpriteRender/SpriteRender.h"
#include "../../include/Render/Render.h"
#include "../../include/Time/GameTime.h"
#include "../../include/Audio/AudioListener.h"
#include <GraphicsRender/GraphicsRender.h>

namespace gnLib {

	GameCore* GameCore::Instance = nullptr;

	GameCore::GameCore()
		: window(new Window{})
		, graphics(new Graphics{})
		, keyBoard(new KeyInput{})
		, mouse(new MouseInput{})
		, spriteRender(new SpriteRender{})
		, renderDevice(new RenderDevice{})
		, gameTime(new GameTime{})
		, audioListener(new AudioListener{})
		, graphicsRender(new gnLibCore::GraphicsRender{})
	{

		if (Instance == nullptr) {
			Instance = this;
		}

	}

	GameCore::~GameCore()
	{
		Instance = nullptr;
	}

	GameCore * GameCore::get()
	{
		return Instance;
	}

	void GameCore::initWindow(const string& _title, int _width, int _height)
	{
		window.get()->initWindow(_title, _width, _height);
	}

	void GameCore::init()
	{
		window.get()->init();

		graphics.get()->init(window.get());

		keyBoard.get()->init(window.get());

		mouse.get()->init(window.get());

		spriteRender.get()->init();

		renderDevice.get()->init(graphics.get());

		audioListener.get()->init();

		graphicsRender.get()->init(graphics.get());
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

	SpriteRender* GameCore::getSprite()
	{
		return spriteRender.get();
	}

	RenderDevice* GameCore::getRenderDevice()
	{
		return renderDevice.get();
	}

	GameTime* GameCore::getGameTime()
	{
		return gameTime.get();
	}

	AudioListener* GameCore::getAudioListener()
	{
		return audioListener.get();
	}

	gnLibCore::IGraphicsRender* GameCore::getGraphicsRender()
	{
		return graphicsRender.get();
	}

}

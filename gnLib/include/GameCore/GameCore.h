#ifndef GAMECORE_H
#define GAMECORE_H

#include <string>
#include "../../include/Common/SmartPtr.h"

using std::string;

#define GCoreIns        GameCore::get()
#define GCWindow        GameCore::get()->getWindow()
#define GCGraphics      GameCore::get()->getGraphic()->getDevice()
#define GCInputMouse    GameCore::get()->getMouse()
#define GCInputKeyBoard GameCore::get()->getKeyBoard()
#define GCSprite        GameCore::get()->getSprite()
#define GCRenderDevice  GameCore::get()->getRenderDevice()
#define GCLineDevice    GameCore::get()->getRenderDevice()->getLineDevice()
#define GCStrDevice     GameCore::get()->getRenderDevice()->getFontDevice()
#define GCGameTime      GameCore::get()->getGameTime()
#define GCAudio         GameCore::get()->getAudioListener()
#define GCGraphicsRender GameCore::get()->getGraphicsRender()

namespace gnLib {

	class Window; 
	class Graphics;
	class KeyInput;
	class MouseInput;
	class SpriteRender;
	class RenderDevice;
	class Console;
	class GameTime;
	class AudioListener;

	namespace gnLibCore {
		class IGraphicsRender;
	}

	// �Q�[���Ɏg�����v�ȃN���X���܂Ƃ߂��N���X
	class GameCore {
	private:
		static GameCore* Instance;

	public:
		static GameCore* get();

	public:
		GameCore();
		~GameCore();
		
		void initWindow(const string& _title, int _width, int _height);
		void init();
		void update();

		Window*        getWindow();
		Graphics*      getGraphic();
		KeyInput*      getKeyBoard();
		MouseInput*    getMouse();
		SpriteRender*  getSprite();
		RenderDevice*  getRenderDevice();
		GameTime*      getGameTime();
		AudioListener* getAudioListener();
		gnLibCore::IGraphicsRender* getGraphicsRender();

	private:
		UniquePtr<Window>        window;        // �E�C���h�E
		UniquePtr<Graphics>      graphics;      // �O���t�B�N�X
		UniquePtr<KeyInput>      keyBoard;      // �L�[�{�[�h
		UniquePtr<SpriteRender>  spriteRender;  // �X�v���C�g�����_�[
		UniquePtr<MouseInput>    mouse;         // �}�E�X
		UniquePtr<RenderDevice>  renderDevice;	// �����_�[�f�o�C�X
		UniquePtr<GameTime>      gameTime;      // ����
		UniquePtr<AudioListener> audioListener; // �I�[�f�B�I���X�i�[
		UniquePtr<gnLibCore::IGraphicsRender> graphicsRender;
	};

}

#endif // !GAMECORE_H

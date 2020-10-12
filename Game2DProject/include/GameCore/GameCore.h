#ifndef GAMECORE_H
#define GAMECORE_H

#include <string>
#include "../../include/Common/SmartPtr.h"
#include "../../include/Render/Render.h"

using std::string;

#define GCoreIns       GameCore::get()
//#define GCoreRender    GameCore::get()->getRender()
//#define RDevice        GameCore::get()->getRender()->getGraphics()->getDevice();
//#define RLineDevice    GameCore::get()->getRender()->getLineDevice()

namespace gnLib {
	class Window; 
	class Graphics;
	class KeyInput;
	class MouseInput;
	//class Render;

	// �Q�[���Ɏg�����v�ȃN���X���܂Ƃ߂��N���X
	class GameCore {
	public:
		GameCore();
		~GameCore();
		
		static GameCore* get();

		void initWindow(const string& _title, int _width, int _height);
		void init();
		void update();

		Window* getWindow();
		Graphics* getGraphic();
		KeyInput* getKeyBoard();
		MouseInput* getMouse();

	private:
		static GameCore* Instance;

		UniquePtr<Window>     window;    // �E�C���h�E
		UniquePtr<Graphics>   graphics;  // �O���t�B�N�X
		UniquePtr<KeyInput>   keyBoard;  // �L�[�{�[�h
		UniquePtr<MouseInput> mouse;     // �}�E�X
		Render     render;    // �����_�[
	};

}

#endif // !GAMECORE_H

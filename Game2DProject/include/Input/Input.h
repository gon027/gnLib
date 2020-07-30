#ifndef INPUT_H
#define INPUT_H

// �L�[�{�[�h
#include "KeyInput.h"

// �}�E�X
#include "MouseInput.h"

namespace window {
	class Window;
}

using Window = window::Window;

class Input {
public:
	static void init(Window* _widnow);
	static void update();

	// �L�[�{�[�h
	static bool getKeyDown(Key key);	// �L�[���������Ƃ�
	static bool getKeyUp(Key key);		// �L�[���グ���Ƃ�
	static bool getKeyState(Key key);	// �L�[���������܂܂̂Ƃ�

	// �}�E�X
	static bool getLeftButton();		// �}�E�X�̍����������Ƃ�
	static bool getRightButton();		// �}�E�X�̉E���������Ƃ�
	static bool getMiddleButton();		// �}�E�X�̐^�񒆂��������Ƃ�
	static int getPosition();			// �}�E�X�̍��W���擾����

private:
	static KeyBorad keyBorad;
	static Mouse mouse;
};

#endif // !INPUT_H

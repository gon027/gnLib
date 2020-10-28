#ifndef INPUT_H
#define INPUT_H

// �L�[�{�[�h
#include "KeyInput.h"

// �}�E�X
#include "MouseInput.h"

namespace gnLib {

	class Vector2;

	// �}�E�X�̓��̓{�^��
	enum class MouseButton : int {
		LEFT   = 0,
		RIGHT  = 1,
		MIDDLE = 2
	};

	class Input {
	public:

		// �L�[�{�[�h
		static bool getKeyDown(Key _key);   // �L�[���������Ƃ�
		static bool getKeyUp(Key _key);     // �L�[���グ���Ƃ�
		static bool getKey(Key _key);       // �L�[���������܂܂̂Ƃ�

		// �}�E�X
		static bool getLeftButton();        // �}�E�X�̍����������Ƃ�
		static bool getRightButton();       // �}�E�X�̉E���������Ƃ�
		static bool getMiddleButton();      // �}�E�X�̒��S���������Ƃ�
		static Vector2 getPos();            // �}�E�X�̍��W���擾����
	};
}

#endif // !INPUT_H

#ifndef GAMETIME_H
#define GAMETIME_H

#pragma comment(lib, "winmm.lib")
#include <Windows.h>

namespace gnLib {

	class GameTime {
	public:
		GameTime();
		~GameTime();

		// �J�n���Ԃ��L�^
		void beginTime();

		// �I�����Ԃ��L�^
		void endTime();

		// ���Ԃ��擾����
		DWORD getTime();

		// �J�n���Ԃ��擾
		DWORD getStartTime();

		// �I�����Ԃ��擾 
		DWORD getEndTime();

		// �J�n���Ԃ���I�����Ԃ�����������
		DWORD deltaTime();

	private:
		DWORD currentTime;
		DWORD prevTime;
	};

}

#endif // !GAMETIME_H

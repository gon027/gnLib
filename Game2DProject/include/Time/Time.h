#ifndef TIME_H
#define TIME_H


#pragma comment(lib, "winmm.lib")
#include <Windows.h>

namespace gnLib {

	class Time {
	public:
		Time();
		~Time();

		// ���Ԃ��擾����
		DWORD getTime();

		// �J�n���Ԃ��L�^
		void beginTime();

		// �I�����Ԃ��L�^
		void endTime();

		// �J�n���Ԃ���I�����Ԃ�����������
		DWORD deltaTime();

	private:
		DWORD currentTime;
		DWORD prevTime;
	};

}

#endif // !TIME_H

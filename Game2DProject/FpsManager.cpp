#include "FpsManager.h"

#pragma comment(lib, "winmm.lib")
#include <mmsystem.h>

constexpr int TIMELIMIT = 1000;

namespace gnLib {

	FpsManager::FpsManager()
		: count(0)
	{
		// �擾���鎞�Ԃ̐��x���グ��
		timeBeginPeriod(1);

		// �N�����̎��Ԃ��擾
		oldTime = timeGetTime();
	}

	FpsManager::~FpsManager()
	{
		timeEndPeriod(1);
	}

	void FpsManager::update()
	{
		++count;

		// �Ō�̎��Ԃ��擾
		auto newTime = timeGetTime();
		
		// �����̎��Ԃ��Z�o
		auto diffTime = oldTime - newTime;

		if (diffTime >= TIMELIMIT) {		// 1�b�ȏ�o�߂��Ă���Ƃ�
			frameRate = ((double)count * 1000.0) / (double)diffTime;

			count = 0;

			// ���ݎ����̍X�V
			oldTime = newTime;
		}
	}

	double FpsManager::getFps() const
	{
		return oldTime;
	}

}
#ifndef FPSMANAGER_H
#define FPSMANAGER_H

#include <Windows.h>

namespace gnLib {

	// Fps�v���N���X
	class FpsManager {
	public:
		FpsManager();
		~FpsManager();

		void setFps(long _fps);
		void update();
		void wait();

		double getFps() const;

	private:
		long FPS = 60;		// 60FPS�œ��삳����
		DWORD oldTime;		// �ȑO�̎���
		int count = 0;
		double frameRate = 0;
	};

}


#endif // !FPSMANAGER_H

#ifndef FPSMANAGER_H
#define FPSMANAGER_H

#include <Windows.h>

namespace gnLib {

	// Fps計測クラス
	class FpsManager {
	public:
		FpsManager();
		~FpsManager();

		void setFps(long _fps);
		void update();
		void wait();

		double getFps() const;

	private:
		long FPS = 60;		// 60FPSで動作させる
		DWORD oldTime;		// 以前の時間
		int count = 0;
		double frameRate = 0;
	};

}


#endif // !FPSMANAGER_H

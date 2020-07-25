#include "FpsManager.h"

#pragma comment(lib, "winmm.lib")
#include <mmsystem.h>

constexpr int TIMELIMIT = 1000;

namespace gnLib {

	FpsManager::FpsManager()
		: count(0)
	{
		// 取得する時間の制度を上げる
		timeBeginPeriod(1);

		// 起動時の時間を取得
		oldTime = timeGetTime();
	}

	FpsManager::~FpsManager()
	{
		timeEndPeriod(1);
	}

	void FpsManager::update()
	{
		++count;

		// 最後の時間を取得
		auto newTime = timeGetTime();
		
		// 差分の時間を算出
		auto diffTime = oldTime - newTime;

		if (diffTime >= TIMELIMIT) {		// 1秒以上経過しているとき
			frameRate = ((double)count * 1000.0) / (double)diffTime;

			count = 0;

			// 現在時刻の更新
			oldTime = newTime;
		}
	}

	double FpsManager::getFps() const
	{
		return oldTime;
	}

}
#ifndef TIME_H
#define TIME_H


#pragma comment(lib, "winmm.lib")
#include <Windows.h>

namespace gnLib {

	class Time {
	public:
		Time();
		~Time();

		// 時間を取得する
		DWORD getTime();

		// 開始時間を記録
		void beginTime();

		// 終了時間を記録
		void endTime();

		// 開始時間から終了時間を引いた時間
		DWORD deltaTime();

	private:
		DWORD currentTime;
		DWORD prevTime;
	};

}

#endif // !TIME_H

#ifndef GAMETIME_H
#define GAMETIME_H

#pragma comment(lib, "winmm.lib")
#include <Windows.h>

namespace gnLib {

	class GameTime {
	public:
		GameTime();
		~GameTime();

		// 開始時間を記録
		void beginTime();

		// 終了時間を記録
		void endTime();

		// 時間を取得する
		DWORD getTime();

		// 開始時間を取得
		DWORD getStartTime();

		// 終了時間を取得 
		DWORD getEndTime();

		// 開始時間から終了時間を引いた時間
		DWORD deltaTime();

	private:
		DWORD currentTime;
		DWORD prevTime;
	};

}

#endif // !GAMETIME_H

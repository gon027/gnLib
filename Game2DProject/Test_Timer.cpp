/*#include "gnLib.h"

#include "include/Time/Time.h"

class FpsCounter {
public:
	FpsCounter() {

	}

	~FpsCounter() = default;

private:
	int a = 0;
};

#pragma comment(lib, "winmm.lib")

class T {
private:
	DWORD currentTime;
};

DWORD frameTime{ 17 };

DWORD current{ 0 };  // Œ»ÝŽžŠÔ
DWORD prev{ 0 };	// ‰ß‹ŽŽžŠÔ


void gnMain() {
	App app;

	timeBeginPeriod(1);

	prev = timeGetTime();

	while (app.doEvent()) {
		app.begin();

		current = timeGetTime();

		if (current - prev >= frameTime) {
			//Debug::drawFormatText(0, 20, Color::Black, "%d", 1123160);
			Sleep(1);
			current = timeGetTime();
		}

		Debug::drawFormatText(0, 0, Color::Black, "%d", current - prev);

		prev = current;

		app.end();
	}

	timeEndPeriod(1);
}
*/
#include "../../include/Time/Time.h"

namespace gnLib {

	Time::Time()
		: currentTime(0)
		, prevTime(0)
	{
		timeBeginPeriod(1);
		prevTime = timeGetTime();
	}

	Time::~Time() {
		timeEndPeriod(1);
	}

	DWORD Time::getTime() {
		return timeGetTime();
	}

	void Time::beginTime() {
		currentTime = timeGetTime();
	}

	void Time::endTime() {
		prevTime = currentTime;
	}

	DWORD Time::deltaTime() {
		return currentTime - prevTime;
	}
}
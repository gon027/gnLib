#include "../../include/Time/GameTime.h"

namespace gnLib {

	GameTime::GameTime()
		: currentTime(0)
		, prevTime(0)
	{
		timeBeginPeriod(1);
		prevTime = timeGetTime();
	}

	GameTime::~GameTime()
	{
		timeEndPeriod(1);
	}

	void GameTime::beginTime()
	{
		currentTime = timeGetTime();
	}

	void GameTime::endTime()
	{
		prevTime = currentTime;
	}

	DWORD GameTime::getTime()
	{
		return timeGetTime();;
	}

	DWORD GameTime::getStartTime()
	{
		return currentTime;
	}

	DWORD GameTime::getEndTime()
	{
		return prevTime;;
	}

	DWORD GameTime::deltaTime()
	{
		return currentTime - prevTime;
	}

}
#include <include/Timer.h>
#include <GameCore/GameCore.h>
#include <Time/Time.h>

namespace gnLib {

	Timer::Timer(float _time)
		: time(_time)
	{
	}

	void Timer::setTimer(float _time)
	{
		time = _time;
	}

	void Timer::countDown()
	{
		time += Time::deltaTime();
	}

	bool Timer::isTimeUp(float _maxTime)
	{
		return time > _maxTime;
	}

	void Timer::reset()
	{
		time = 0.0f;
	}

	float Timer::nowTime()
	{
		return time;
	}

}
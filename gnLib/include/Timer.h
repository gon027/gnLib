#ifndef TIMER_H
#define TIMER_H

namespace gnLib {

	class Timer {
	public:
		explicit Timer(float _time);
		~Timer() = default;

		void setTimer(float _time);

		void countDown();

		bool isTimeUp(float _maxTime);
		
		void reset();

		float nowTime();

	private:
		float time;
	};

}

#endif // !TIMER_H
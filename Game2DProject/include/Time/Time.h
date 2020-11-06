#ifndef TIME_H
#define TIME_H

namespace gnLib {

	class Time {
	public:
		~Time() = default;

		static float time();      // 起動してからの時間を取得
		static float deltaTime(); // 前フレームの時間を取得

	private:
		float th = 0;
	};

}

#endif // !TIME_H

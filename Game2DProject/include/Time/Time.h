#ifndef TIME_H
#define TIME_H

namespace gnLib {

	class Time {
	public:
		~Time() = default;

		static float time();      // �N�����Ă���̎��Ԃ��擾
		static float deltaTime(); // �O�t���[���̎��Ԃ��擾

	private:
		float th = 0;
	};

}

#endif // !TIME_H

#ifndef TIME_H
#define TIME_H

#include <Windows.h>

namespace gnLib {

	namespace Time {

		DWORD getTime();

		DWORD getStartTime();

		DWORD getEndTime();

		float deltaTime();

	};

}

#endif // !TIME_H

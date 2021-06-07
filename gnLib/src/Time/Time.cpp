#include "../../include/Time/Time.h"
#include "../../include/Time/GameTime.h"
#include "../../include/GameCore/GameCore.h"

namespace gnLib {

	DWORD Time::getTime() {
		return GCGameTime->getTime();
	}

	DWORD Time::getStartTime()
	{
		return GCGameTime->getStartTime();;
	}

	DWORD Time::getEndTime()
	{
		return GCGameTime->getEndTime();;
	}

	float Time::deltaTime() {
		float result = static_cast<float>(GCGameTime->deltaTime() / 1000.0f);
		if (result > 0.5f) result = 0.5f;
		return result;
	}
}
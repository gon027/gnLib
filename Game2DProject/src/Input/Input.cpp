#include "../../include/Input/Input.h"
#include "../../include/GameCore/GameCore.h"
#include "../../include/Vector/Vector2.h"

namespace gnLib {

	bool Input::getKeyDown(Key _key)
	{
		return GCInputKeyBoard->getKeyDown(_key);
	}

	bool Input::getKeyUp(Key _key)
	{
		return GCInputKeyBoard->getKeyUp(_key);
	}

	bool Input::getKey(Key _key)
	{
		return GCInputKeyBoard->getKey(_key);
	}

	bool Input::getLeftButton()
	{
		return GCInputMouse->getLeftButton();
	}

	bool Input::getRightButton()
	{
		return GCInputMouse->getRightButton();
	}

	bool Input::getMiddleButton()
	{
		return GCInputMouse->getMiddleButton();
	}

	Vector2 Input::getPos()
	{
		return GCInputMouse->getPos();
	}

}
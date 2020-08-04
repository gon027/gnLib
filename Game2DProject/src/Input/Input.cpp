#include "../../include/Input/Input.h"
#include "../../include/GameCore/GameCore.h"
#include "../../include/Vector/Vector2.h"

namespace gnLib {

	bool Input::getKeyDown(Key key)
	{
		return true; //keyBorad.keyDown(key);
	}

	bool Input::getKeyUp(Key key)
	{
		return true;// keyBorad.keyUp(key);;
	}

	bool Input::getKeyState(Key key)
	{
		return false;
	}

	bool Input::getLeftButton()
	{
		return GCoreIns->getMouse()->getLeftButton();
	}

	bool Input::getRightButton()
	{
		return GCoreIns->getMouse()->getRightButton();
	}

	bool Input::getMiddleButton()
	{
		return GCoreIns->getMouse()->getMiddleButton();
	}

	Vector2 Input::getPosition()
	{
		return GCoreIns->getMouse()->getPosition();;
	}

}
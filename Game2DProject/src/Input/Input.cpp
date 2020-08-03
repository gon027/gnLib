#include "../../include/Input/Input.h"
#include "../../GameCore.h"

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
		//return mouse.getLeftButton();
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

	int Input::getPosition()
	{
		return 0;
	}

}
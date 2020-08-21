#include "../../include/Input/Input.h"
#include "../../include/GameCore/GameCore.h"
#include "../../include/Vector/Vector2.h"

namespace gnLib {

	/*
	namespace {
		KeyBorad* keyBoard;
		MouseInput* mouseInput;
	}
	*/


	bool Input::getKeyDown(Key key)
	{
		return true; //keyBorad.getKeyDown(key);
	}

	bool Input::getKeyUp(Key key)
	{
		return true;// keyBorad.getKeyUp(key);;
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
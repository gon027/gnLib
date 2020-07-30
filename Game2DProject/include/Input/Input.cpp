#include "Input.h"

KeyBorad Input::keyBorad;
Mouse Input::mouse;

void Input::init(Window * _widnow)
{
	keyBorad.init(_widnow);
	mouse.init(_widnow);
}

void Input::update()
{
	keyBorad.update();
	mouse.update();
}

bool Input::getKeyDown(Key key)
{
	return keyBorad.keyDown(key);
}

bool Input::getKeyUp(Key key)
{
	return keyBorad.keyUp(key);;
}

bool Input::getKeyState(Key key)
{
	return false;
}

bool Input::getLeftButton()
{
	return mouse.getLeftButton();
}

bool Input::getRightButton()
{
	return mouse.getRightButton();
}

bool Input::getMiddleButton()
{
	return mouse.getMiddleButton();
}

int Input::getPosition()
{
	return 0;
}

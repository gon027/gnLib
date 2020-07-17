#include "KeyInput.h"

KeyInput::KeyInput(Window * _win)
	: window(_win)
	, beforeKey()
	, afterKey()
{

}

KeyInput::~KeyInput()
{
	RELEASE(directInput)
	RELEASE(keyBoard);
}

bool KeyInput::createDInput()
{
	return false;
}

bool KeyInput::create()
{
	return false;
}

void KeyInput::update()
{

}


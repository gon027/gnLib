#include "KeyInput.h"

KeyInput::KeyInput()
{

}

KeyInput::~KeyInput()
{
	RELEASE(directInput)
	RELEASE(keyBoard);
}


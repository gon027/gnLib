#include "KeyInput.h"

#include "Window.h"
#include "Macro.h"

KeyInput::KeyInput(Window * _win)
	: window(_win)
	, beforeKey()
	, afterKey()
{

}

KeyInput::~KeyInput()
{
	RELEASE(device)
	RELEASE(keyBoard);
}

bool KeyInput::createDInput()
{
	HRESULT ret;

	ret = DirectInput8Create(
		window->getHInstance(),
		DIRECTINPUT_VERSION,
		IID_IDirectInput8,
		(LPVOID*)&this->device,
		NULL
	);

	if (FAILED(ret)) {
		return false;
	}

	return true;
}

bool KeyInput::create()
{
	HRESULT ret;

	ret = device->CreateDevice(GUID_SysKeyboard, &keyBoard, NULL);
	if (FAILED(ret)) {
		return false;
	}

	ret = keyBoard->SetDataFormat(&c_dfDIKeyboard);
	if (FAILED(ret)) {
		relese();
		return false;
	}

	ret = keyBoard->SetCooperativeLevel(
		window->getHWnd(),
		DISCL_FOREGROUND | DISCL_NONEXCLUSIVE | DISCL_NOWINKEY
	);
	if (FAILED(ret)) {
		relese();
		return false;
	}

	return true;
}

void KeyInput::update()
{
	keyBoard->Acquire();

	ZeroMemory(beforeKey, sizeof(beforeKey));

	HRESULT ret = keyBoard->GetDeviceState(sizeof(beforeKey), beforeKey);

	if (FAILED(ret)) {
		keyBoard->Acquire();
		keyBoard->GetDeviceState(sizeof(beforeKey), beforeKey);
	}
}

bool KeyInput::keyDown(Key _keyCode)
{
	if (beforeKey[(BYTE)_keyCode] & 0x80) {
		return true;
	}

	return false;
}

void KeyInput::relese() noexcept
{
	RELEASE(keyBoard);
}


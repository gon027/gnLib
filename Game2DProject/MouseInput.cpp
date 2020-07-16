#include "MouseInput.h"
#include "Macro.h"

#define Failed(ret) if (FAILED(ret)) return false

MouseInput::MouseInput(window::Window* _win)
	: window(_win)
	, directInput(nullptr)
	, lpMouse(nullptr)
	, mouseState()
{

}

MouseInput::~MouseInput()
{
	release();
}

bool MouseInput::createDInput()
{
	HRESULT ret{};

	ret = DirectInput8Create(
		window->getHInstance(),
		DIRECTINPUT_VERSION,
		IID_IDirectInput8,
		(LPVOID*)&directInput,
		NULL
	);

	if (FAILED(ret)) {
		return false;
	}

	return true;
}

bool MouseInput::create()
{
	HRESULT ret{};

	ret = directInput->CreateDevice(GUID_SysMouse, &lpMouse, NULL);

	Failed(ret);

	ret = lpMouse->SetDataFormat(&c_dfDIMouse);

	Failed(ret);

	ret = lpMouse->SetCooperativeLevel(
		window->getHWnd(),
		DISCL_NONEXCLUSIVE | DISCL_FOREGROUND
	);

	Failed(ret);

	DIPROPDWORD diprop;
	diprop.diph.dwSize = sizeof(diprop);
	diprop.diph.dwHeaderSize = sizeof(diprop.diph);
	diprop.diph.dwHeaderSize = 0;
	diprop.diph.dwObj = DIPH_DEVICE;
	diprop.diph.dwHow = DIPROPAXISMODE_REL;

	ret = lpMouse->SetProperty(DIPROP_AXISMODE, &diprop.diph);
	
	Failed(ret);

	return true;
}

void MouseInput::release()
{
	RELEASE(directInput);
	RELEASE(lpMouse);
}

void MouseInput::update()
{
	HRESULT ret{};

	lpMouse->Acquire();

	ret = lpMouse->GetDeviceState(
		sizeof(DIMOUSESTATE),
		&mouseState
	);

	if (ret == DIERR_INPUTLOST) {
		lpMouse->Acquire();
		ret = lpMouse->GetDeviceState(
			sizeof(DIMOUSESTATE),
			&mouseState
		);
	}
}

bool MouseInput::getLeftButton()
{
	if (mouseState.rgbButtons[0] & 0x80) {
		return true;
	}

	return false;
}

bool MouseInput::getRightButton()
{
	if (mouseState.rgbButtons[1] & 0x80) {
		return true;
	}

	return false;
}

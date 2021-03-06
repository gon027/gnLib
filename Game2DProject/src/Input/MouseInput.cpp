#include "../../include/Input/MouseInput.h"
#include "../../include/Window/Window.h"
#include "../../include/Common/Macro.h"
#include "../../include/Vector/Vector2.h"

namespace gnLib {
	MouseInput::MouseInput(Window* _win)
		: window(_win)
		, device(nullptr)
		, lpMouse(nullptr)
		, mouseState()
	{

	}

	MouseInput::~MouseInput()
	{
		release();
	}

	void MouseInput::init(Window * _win)
	{
		window = _win;
		createDInput();
		create();
	}

	bool MouseInput::createDInput()
	{
		HRESULT ret{};

		ret = DirectInput8Create(
			window->getHInstance(),
			DIRECTINPUT_VERSION,
			IID_IDirectInput8,
			(LPVOID*)&device,
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

		ret = device->CreateDevice(GUID_SysMouse, &lpMouse, NULL);

		if (FAILED(ret)) {
			return false;
		}

		ret = lpMouse->SetDataFormat(&c_dfDIMouse);

		if (FAILED(ret)) {
			return false;
		}

		ret = lpMouse->SetCooperativeLevel(
			window->getHWnd(),
			DISCL_NONEXCLUSIVE | DISCL_FOREGROUND
		);

		if (FAILED(ret)) {
			return false;
		}

		DIPROPDWORD diprop;
		diprop.diph.dwSize = sizeof(diprop);
		diprop.diph.dwHeaderSize = sizeof(diprop.diph);
		diprop.diph.dwHeaderSize = 0;
		diprop.diph.dwObj = DIPH_DEVICE;
		diprop.diph.dwHow = DIPROPAXISMODE_REL;

		ret = lpMouse->SetProperty(DIPROP_AXISMODE, &diprop.diph);

		if (FAILED(ret)) {
			return false;
		}

		return true;
	}

	void MouseInput::release()
	{
		RELEASE(device);
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

	bool MouseInput::getMiddleButton()
	{
		if (mouseState.rgbButtons[2] & 0x80) {
			return true;
		}

		return false;
	}

	Vector2 MouseInput::getPos() const
	{
		POINT mousePoint{};

		// 座標を取得
		GetCursorPos(&mousePoint);

		// マウス座標をクライアント座標に変換
		ScreenToClient(window->getHWnd(), &mousePoint);

		return Vector2(
			(float)mousePoint.x, 
			(float)mousePoint.y
		);
	}
}
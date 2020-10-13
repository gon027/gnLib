#include "../../include/Input/KeyInput.h"
#include "../../include/Window/Window.h"
#include "../../include/Common/Macro.h"

namespace gnLib {
	KeyInput::KeyInput(Window * _win)
		: window(_win)
		, device(nullptr)
		, keyBoard(nullptr)
		, buffer()
		//, afterKey()
		, keyArray()
	{

	}

	KeyInput::~KeyInput()
	{
		RELEASE(device)
		RELEASE(keyBoard);
	}

	void KeyInput::init(Window * _win)
	{
		window = _win;
		createDInput();
		create();
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

		ZeroMemory(buffer, sizeof(buffer));

		HRESULT ret = keyBoard->GetDeviceState(sizeof(buffer), buffer);

		if (FAILED(ret)) {
			keyBoard->Acquire();
			keyBoard->GetDeviceState(sizeof(buffer), buffer);
		}
	}

	bool KeyInput::getKey(Key _keyCode)
	{
		return false;
	}

	bool KeyInput::getKeyDown(Key _keyCode)
	{
		keyArray[(BYTE)_keyCode] = 1;

		if (buffer[(BYTE)_keyCode] & 0x80) {
			return true;
		}

		return false;
	}

	bool KeyInput::getKeyUp(Key _keyCode)
	{
		keyArray[(BYTE)_keyCode] = 0;

		return false;
	}

	void KeyInput::relese() noexcept
	{
		RELEASE(keyBoard);
	}

}

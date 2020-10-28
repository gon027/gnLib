#include "../../include/Input/KeyInput.h"
#include "../../include/Window/Window.h"
#include "../../include/Common/Macro.h"

namespace gnLib {
	KeyInput::KeyInput(Window * _win)
		: window(_win)
		, device(nullptr)
		, keyBoard(nullptr)
		, bufferKey()
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

		ZeroMemory(bufferKey.buffer, sizeof(bufferKey.buffer));

		HRESULT ret = keyBoard->GetDeviceState(sizeof(bufferKey.buffer), bufferKey.buffer);

		if (FAILED(ret)) {
			keyBoard->Acquire();
			keyBoard->GetDeviceState(sizeof(bufferKey.buffer), bufferKey.buffer);
		}
	}

	bool KeyInput::getKey(Key _keyCode)
	{
		getKeyDown(_keyCode);

		bool result = false;

		if (bufferKey.buffer[(BYTE)_keyCode] & 0x80) {
			if (bufferKey.oldKey[(BYTE)_keyCode] & 0x80) {
				result = true;
			}
		}

		return result;
	}

	bool KeyInput::getKeyDown(Key _keyCode)
	{
		bool result = false;

		if (bufferKey.buffer[(BYTE)_keyCode] & 0x80) {
			if (!bufferKey.oldKey[(BYTE)_keyCode]) {
				result = true;
			}
		}

		bufferKey.oldKey[(BYTE)_keyCode] = bufferKey.buffer[(BYTE)_keyCode];

		return result;
	}

	bool KeyInput::getKeyUp(Key _keyCode)
	{
		if (!(bufferKey.buffer[(BYTE)_keyCode] & 0x80)) {
			return true;
		}

		return false;
	}

	void KeyInput::relese() noexcept
	{
		RELEASE(keyBoard);
	}

}

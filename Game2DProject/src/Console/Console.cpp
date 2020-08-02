#include "../../include/Console/Console.h"

#include <Windows.h>
#include <io.h>
#include <fcntl.h>

namespace gnLib {

	Console::Console()
	{

	}

	Console::~Console()
	{
		// 割り当てたコンソールを開放する
		FreeConsole();
	}

	void Console::createConsole()
	{
		BOOL ret;

		// コンソールを割り当てる
		ret = AllocConsole();

		if (!ret) {
			return;
		}

		if (!createOutputHandle()) {
			return;
		}

		ret = GetConsoleScreenBufferInfo(hStdOutput, &screenBuffer);

		if (!ret) {
			return;
		}
	}

	bool Console::createOutputHandle()
	{
		// 入出力のハンドルを取得する
		hStdOutput = GetStdHandle(STD_OUTPUT_HANDLE);

		if (!hStdOutput) {
			return false;
		}

		return true;
	}

	void Console::print(const TCHAR * _str)
	{
		lstrcpy(buf, _str);
		WriteConsole(hStdOutput, buf, lstrlen(buf), &dwWriteByte, NULL);
	}

	HANDLE* Console::getOutputHandle()
	{
		return &hStdOutput;
	}

}
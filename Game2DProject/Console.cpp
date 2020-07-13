#include "Console.h"

#include <Windows.h>
#include <io.h>
#include <fcntl.h>

console::Console::Console()
{
	
}

console::Console::~Console()
{
	// 割り当てたコンソールを開放する
	FreeConsole();
}

void console::Console::createConsole()
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

bool console::Console::createOutputHandle()
{
	// 入出力のハンドルを取得する
	hStdOutput = GetStdHandle(STD_OUTPUT_HANDLE);

	if (!hStdOutput) {
		return false;
	}

	return true;
}

void console::Console::print(const TCHAR * _str)
{
	lstrcpy(buf, _str);
	WriteConsole(hStdOutput, buf, lstrlen(buf), &dwWriteByte, NULL);
}

HANDLE* console::Console::getOutputHandle()
{
	return &hStdOutput;
}

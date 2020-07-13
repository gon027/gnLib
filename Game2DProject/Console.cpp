#include "Console.h"

#include <Windows.h>
#include <io.h>
#include <fcntl.h>

console::Console::Console()
{
	
}

console::Console::~Console()
{
	// ���蓖�Ă��R���\�[�����J������
	FreeConsole();
}

void console::Console::createConsole()
{
	BOOL ret;

	// �R���\�[�������蓖�Ă�
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
	// ���o�͂̃n���h�����擾����
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

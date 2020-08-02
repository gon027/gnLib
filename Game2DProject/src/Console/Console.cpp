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
		// ���蓖�Ă��R���\�[�����J������
		FreeConsole();
	}

	void Console::createConsole()
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

	bool Console::createOutputHandle()
	{
		// ���o�͂̃n���h�����擾����
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
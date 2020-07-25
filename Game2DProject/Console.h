#ifndef CONSOLE_H
#define CONSOLE_H

#include <Windows.h>
#include <string>


// CONSOLE_SCREEN_BUFFER_INFO�̃G�C���A�X�錾
using CSBInfo = CONSOLE_SCREEN_BUFFER_INFO;

namespace console {

	// �R���\�[���N���X
	class Console
	{
	public:
		Console();
		~Console();

		void createConsole();

		bool createInputHandle();

		bool createOutputHandle();

		// �R���\�[���ɕ�������o�͂�����
		void print(const TCHAR* _str);

		HANDLE* getOutputHandle();

	private:
		// ���o�̓n���h��
		HANDLE hStdOutput;
		HANDLE hStdInput;

		// ���������i�[����ϐ�
		DWORD dwWriteByte;
		DWORD dwReadByte;

		// �X�N���[���o�b�t�@
		CSBInfo screenBuffer;


		TCHAR buf[256];
	};
}

#endif // !CONSOLE_H

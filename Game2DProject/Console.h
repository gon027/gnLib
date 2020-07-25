#ifndef CONSOLE_H
#define CONSOLE_H

#include <Windows.h>
#include <string>


// CONSOLE_SCREEN_BUFFER_INFOのエイリアス宣言
using CSBInfo = CONSOLE_SCREEN_BUFFER_INFO;

namespace console {

	// コンソールクラス
	class Console
	{
	public:
		Console();
		~Console();

		void createConsole();

		bool createInputHandle();

		bool createOutputHandle();

		// コンソールに文字列を出力させる
		void print(const TCHAR* _str);

		HANDLE* getOutputHandle();

	private:
		// 入出力ハンドル
		HANDLE hStdOutput;
		HANDLE hStdInput;

		// 文字数を格納する変数
		DWORD dwWriteByte;
		DWORD dwReadByte;

		// スクリーンバッファ
		CSBInfo screenBuffer;


		TCHAR buf[256];
	};
}

#endif // !CONSOLE_H

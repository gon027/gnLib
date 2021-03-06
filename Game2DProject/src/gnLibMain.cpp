#include "../include/gnLibMain.h"
#include "../include/GameCore/GameCore.h"
#include "../include/Window/Window.h"

// メイン関数
// gnMainを起動させる
int _stdcall WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int lpCmdShow) {

	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	gnLib::GameCore gameCore;
	
	gnMain();

	return 0;
}
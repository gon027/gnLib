#include "../include/gnLibMain.h"
#include "../include/GameCore/GameCore.h"
#include "../include/Window/Window.h"

// ���C���֐�
// gnMain���N��������
int _stdcall WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int lpCmdShow) {

	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	gnLib::GameCore gameCore;
	
	gnMain();

	return 0;
}
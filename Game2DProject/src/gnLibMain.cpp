#include "../include/gnLibMain.h"
#include "../include/GameCore/GameCore.h"

#include <Windows.h>

// ���C���֐�
// gnMain���N��������
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	gnLib::GameCore gameCore;

	gnMain();

	return 0;
}
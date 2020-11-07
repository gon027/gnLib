#include "../include/gnLibMain.h"
#include "../include/GameCore/GameCore.h"

#include <Windows.h>

// メイン関数
// gnMainを起動させる
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	gnLib::GameCore gameCore;

	gnMain();

	return 0;
}
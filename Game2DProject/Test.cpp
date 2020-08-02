#include "GameLib.h"

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
	App app{};

	while (app.doEvent()) {
		app.begin();

		app.end();
	}
}
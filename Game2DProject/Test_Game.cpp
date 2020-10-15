#include "GameLib.h"
#include <vector>

/*
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
	App app{ "Test_Game" };

	std::vector<Rect> rect(5 * 5);

	while (app.doEvent()) {
		app.begin();

		for (int i = 0; i < 5; ++i) {
			for (int j = 0; j < 5; ++j) {
				int idx = j + i * 5;
				rect[idx].setColor(Color::Green);
				rect[idx].setSize(50, 50);
				rect[idx].setPos( 
					Vector2{ 50.f + 55.f * j, 50.f + 100.f * i }
				);
				rect[idx].draw();

			}
		}
		

		app.end();
	}
}
*/
#include "gnLib.h"

void gnMain() {
	App app;

	AudioSource audio;
	audio.load("test.wav");

	AudioSource bgm1;
	bgm1.load("bgm.wav");
	bgm1.play(PlayType::Loop);
	
	while (app.update()) {
		app.begin();

		if (Input::getRightButton()) {
			audio.play();
		}

		if (Input::getLeftButton()) {
			bgm1.stop();
		}

		app.end();
	}
}
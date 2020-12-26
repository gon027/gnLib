#include "gnLib.h"

void gnMain() {
	App app;

	AudioSource audio;
	audio.load("test.wav");
	audio.setVolume(-1000);

	AudioSource bgm1;
	bgm1.load("bgm.wav");
	bgm1.play(PlayType::Loop);
	
	while (app.update()) {
		app.begin();

		Debug::drawFormatText(0, 0, Color::Black, "%ld", audio.getVolume());

		if (Input::getRightButton()) {
			audio.setPosition(0);
			audio.play();
		}

		if (Input::getLeftButton()) {
			//bgm1.stop();
			bgm1.setVolume(-3000);
		}

		app.end();
	}
}
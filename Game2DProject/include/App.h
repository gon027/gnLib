#ifndef APP_H
#define APP_H

#include <string>
#include "../include/Common/SmartPtr.h"
#include "../include/GameCore/GameCore.h"
#include "../include/Vector/Vector2.h"

namespace gnLib {

	class Vector2;

	class App {
	public:
		App(std::string _title = "App", int _width = 640, int _height = 480);
		~App();

		bool doEvent();
		bool update();
		void begin();
		void end();

		// ウィンドウの幅と高さ
		float getWidth() const;
		float getHeight() const;
		Vector2 getPos() const;
	};

}

#endif // !APP_H

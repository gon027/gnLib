#ifndef APP_H
#define APP_H

#include <string>
#include "../include/Common/SmartPtr.h"

namespace gnLib {
	class Window;
	class Graphics;

	class App {
	public:
		App(std::string _title = "App", int _width = 640, int _height = 480);
		~App();

		void initWindow();

		bool doEvent();
		bool update();
		void begin();
		void end();

		// ウィンドウの幅と高さ
		int getWidth() const;
		int getHeight() const;

	private:
		UniquePtr<Window> window;
		UniquePtr<Graphics> graphics;

		int windowWidth = 640;
		int windowHeight = 480;
	};

}

#endif // !APP_H

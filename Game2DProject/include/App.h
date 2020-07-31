#ifndef APP_H
#define APP_H

#include <string>
#include "../include/Common/SmartPtr.h"

namespace window {
	class Window;
}

class Graphics;
using Window = window::Window;

class App {
public:
	App(std::string _title, int _width = 640, int _height = 480);
	~App();

	void initWindow();

	bool doEvent();
	bool update();
	void begin();
	void end();

	Window* getWindow() const;

	Graphics* getGraphics() const;

	// ウィンドウの幅と高さ
	int getWidth() const;
	int getHeight() const;

private:
	UniquePtr<Window> window;
	UniquePtr<Graphics> graphics;

	int windowWidth = 640;
	int windowHeight = 480;
};

#endif // !APP_H

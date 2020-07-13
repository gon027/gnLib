#ifndef APP_H
#define APP_H

#include <string>
#include <memory>

#include "Window.h"
using namespace window;

class Graphics;

class App {
public:
	App();
	~App();

	void initWindow(int _width, int _height, std::string _windowTitle);

	bool update();

private:
	Window window;
	std::unique_ptr<Graphics> graphics;
};

#endif // !APP_H

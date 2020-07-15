#ifndef APP_H
#define APP_H

#include <string>
#include <memory>
#include "SmartPtr.h"

namespace window {
	class Window;
}

class Graphics;
using Window = window::Window;

class App {
public:
	App();
	~App();

	void initWindow(int _width, int _height, std::string _windowTitle);

	bool update();
	void begin();
	void end();

private:
	UniquePtr<Window> window;
	UniquePtr<Graphics> graphics;
};

#endif // !APP_H

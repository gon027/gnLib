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
	App(std::string _title, int _width = 640, int _height = 480);
	~App();

	void initWindow();

	bool dumpMesagge();
	bool update();
	void update();
	void begin();
	void end();

	Window* getWindow() const;

	Graphics* getGraphics() const;

private:
	UniquePtr<Window> window;
	UniquePtr<Graphics> graphics;
};

#endif // !APP_H

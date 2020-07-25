#ifndef APP_H
#define APP_H

#include <string>
#include "SmartPtr.h"
#include "Render.h"
#include "FpsManager.h"

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

	double getFps() {
		return fpsManager.getFps();
	}

	Window* getWindow() const;

	Graphics* getGraphics() const;

private:
	UniquePtr<Window> window;
	UniquePtr<Graphics> graphics;
	gnLib::FpsManager fpsManager;
};

#endif // !APP_H

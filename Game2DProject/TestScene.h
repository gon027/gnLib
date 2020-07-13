#ifndef TESTSCENE
#define TESTSCENE

#include "BaseScene.h"
class Graphics;

class TestScene : public BaseScene {
public:
	TestScene(Graphics* _g);
	~TestScene();

	void start() override;
	void update() override;

private:

};

#endif // !TESTSCENE

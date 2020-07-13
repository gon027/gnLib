#ifndef BASESCENE
#define BASESCENE

// シーンのもととなる基底クラス
class BaseScene {
public:
	virtual void start() = 0;
	virtual void update() = 0;
	virtual ~BaseScene() = 0;
};

#endif // !BASESCENE

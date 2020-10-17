#ifndef ISCENE_H
#define ISCENE_H

class IScene {
public:
	virtual ~IScene() {}

	virtual void start()  = 0;
	virtual void update() = 0;
};

#endif // !ISCENE_H

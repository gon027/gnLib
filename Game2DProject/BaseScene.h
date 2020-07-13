#ifndef BASESCENE
#define BASESCENE

// �V�[���̂��ƂƂȂ���N���X
class BaseScene {
public:
	virtual void start() = 0;
	virtual void update() = 0;
	virtual ~BaseScene() = 0;
};

#endif // !BASESCENE

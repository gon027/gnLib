#ifndef BOXCOLLIDER_H
#define BOXCOLLIDER_H

#include "BaseCollider.h"

class BoxCollider : public BaseCollider{
public:
	BoxCollider(float _x, float _y);
	BoxCollider() = default;
	~BoxCollider() = default;

	bool hitTest(BoxCollider& _other);

	void setCollider(float _x, float _y, float _xSize, float _ySize);

	D3DXVECTOR2 getPosition() const;
	D3DXVECTOR2 getMinSize() const;
	D3DXVECTOR2 getMaxSize() const;

	virtual ColliderType getType() override;

private:
	D3DXVECTOR2 size;

	D3DXVECTOR2 center;
	D3DXVECTOR2 max;
	D3DXVECTOR2 min;
};

#endif // !BOXCOLLIDER_H

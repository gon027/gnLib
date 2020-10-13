#ifndef LINE_H
#define LINE_H

#pragma comment(lib, "d3dx9.lib")
#include <d3dx9.h>

#include "../Object/Object.h"
#include "../Vector/Vector3.h"
#include "../Vector/Vector2.h"
#include "../Color/Color.h"

namespace gnLib {

	class Line : public Object{
	public:
		Line();
		Line(const Vector2& _v1, const Vector2& _v2);
		Line(const Vector3& _v1, const Vector3& _v2);
		Line(float _sx, float _sy, float _gx, float _gy);
		~Line();

		// ���W��ݒ�
		void setPos(float _sx, float _sy, float _gx, float _gy);
		void setPos(const Vector2& _v1, const Vector2& _v2);
		void setPos(const Vector3& _v1, const Vector3& _v2);
		
		// ������ݒ�
		void setWeight(float _weight);

		// �F��ݒ�
		void setColor(Color _color);

		// �`��
		void draw();

	private:
		Vector3 pos1;
		Vector3 pos2;
		float weight;
		Color color;
	};
}

#endif // !LINE_H

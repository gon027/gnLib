#ifndef LINE_H
#define LINE_H

#include <Vector/Vector2.h>
#include <Color/Color.h>

namespace gnLib {

	class Line {
	public:
		Line();
		Line(const Vector2& _v1, const Vector2& _v2);
		Line(float _sx, float _sy, float _gx, float _gy);
		~Line() = default;

		// ���W��ݒ�
		Line& setPos(float _sx, float _sy, float _gx, float _gy);
		Line& setPos(const Vector2& _v1, const Vector2& _v2);
		
		// ������ݒ�
		Line& setWeight(float _weight);

		// �F��ݒ�
		Line& setColor(Color _color);

		// �`��
		void draw();

	private:
		Vector2 start;
		Vector2 end;
		float weight;
		Color color;
	};
}

#endif // !LINE_H

#ifndef LINE_H
#define LINE_H

#include "../Object/Object.h"
#include "../Vector/Vector2.h"
#include "../Color/Color.h"

namespace gnLib {

	class Line : public Object{
	public:
		Line();
		Line(const Vector2& _v1, const Vector2& _v2);
		Line(float _sx, float _sy, float _gx, float _gy);
		~Line() = default;

		// 座標を設定
		void setPos(float _sx, float _sy, float _gx, float _gy);
		void setPos(const Vector2& _v1, const Vector2& _v2);
		
		// 太さを設定
		void setWeight(float _weight);

		// 色を設定
		void setColor(Color _color);

		// 描画
		void draw();

	private:
		Vector2 start;
		Vector2 end;
		float weight;
		Color color;
	};
}

#endif // !LINE_H

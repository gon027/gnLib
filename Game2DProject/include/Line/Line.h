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

		// 座標を設定
		void setPos(float _sx, float _sy, float _gx, float _gy);
		void setPos(const Vector2& _v1, const Vector2& _v2);
		void setPos(const Vector3& _v1, const Vector3& _v2);
		
		// 太さを設定
		void setWeight(float _weight);

		// 色を設定
		void setColor(Color _color);

		// 描画
		void draw();

	private:
		Vector3 pos1;
		Vector3 pos2;
		float weight;
		Color color;
	};
}

#endif // !LINE_H

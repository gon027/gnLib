#ifndef LINE_H
#define LINE_H

#pragma comment(lib, "d3dx9.lib")
#include <d3dx9.h>

#include "../Object/Object.h"
#include "../Vector/Vector3.h"
#include "../Vector/Vector2.h"
#include "../Color/Color.h"

namespace gnLib {

	namespace inter {
		struct DxLine {
			ID3DXLine* d3dLine;


		};
	}

	class Line : public Object{
	public:
		Line();
		Line(const Vector2& _v1, const Vector2& _v2);
		Line(const Vector3& _v1, const Vector3& _v2);
		Line(float _sx, float _sy, float _gx, float _gy);
		~Line();

		// ç¿ïWÇê›íË
		void setPos(float _sx, float _sy, float _gx, float _gy);
		void setPos(const Vector2& _v1, const Vector2& _v2);
		void setPos(const Vector3& _v1, const Vector3& _v2);
		
		// ëæÇ≥Çê›íË
		void setWeight(float _weight);

		// êFÇê›íË
		void setColor(Color _color);

		// ï`âÊ
		void draw();

		// å„Ç…è¡Ç∑Ç©Ç‡ÇµÇÍÇ»Ç¢
		void draw(float _x1, float _y1, float _x2, float _y2);

	private:
		ID3DXLine* line;
		Vector3 pos1;
		Vector3 pos2;
		float weight;
		Color color;
	};
}

#endif // !LINE_H

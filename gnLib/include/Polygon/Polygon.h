#ifndef POLYGON_H
#define POLYGON_H

#include <initializer_list>
#include <vector>
#include <Vertex/Vertex2D.h>
#include <Vector/Vector2.h>
#include <Color/Color.h>

namespace gnLib {

	class Polygon {
	public:
		Polygon(std::initializer_list<Vertex2D> _vertex);
		Polygon(const std::vector<Vertex2D>& _vertex);
		~Polygon() = default;

		/// <summary>
		/// ポリゴンの色を設定
		/// </summary>
		/// <param name="_color"></param>
		void setColor(Color _color);

		/// <summary>
		/// ポリゴンを移動させる
		/// </summary>
		/// <param name="_delta"></param>
		void translate(const Vector2& _delta);

		/// <summary>
		/// ポリゴンのスケールを変更する
		/// </summary>
		/// <param name="_scale"></param>
		void scale(const Vector2& _scale = Vector2::One);

		/// <summary>
		/// 最初に追加した座標を中心に回転する
		/// </summary>
		/// <param name="_angle"> 回転角度 </param>
		void rotate(float _angle);

		/// <summary>
		/// 描画
		/// </summary>
		void draw();

	private:
		std::vector<Vertex2D> vertex;

		Vector2 position;
		Color color;
	};

}

#endif // !POLYGON_H
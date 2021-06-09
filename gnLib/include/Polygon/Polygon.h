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
		/// �|���S���̐F��ݒ�
		/// </summary>
		/// <param name="_color"></param>
		void setColor(Color _color);

		/// <summary>
		/// �|���S�����ړ�������
		/// </summary>
		/// <param name="_delta"></param>
		void translate(const Vector2& _delta);

		/// <summary>
		/// �|���S���̃X�P�[����ύX����
		/// </summary>
		/// <param name="_scale"></param>
		void scale(const Vector2& _scale = Vector2::One);

		/// <summary>
		/// �ŏ��ɒǉ��������W�𒆐S�ɉ�]����
		/// </summary>
		/// <param name="_angle"> ��]�p�x </param>
		void rotate(float _angle);

		/// <summary>
		/// �`��
		/// </summary>
		void draw();

	private:
		std::vector<Vertex2D> vertex;

		Vector2 position;
		Color color;
	};

}

#endif // !POLYGON_H
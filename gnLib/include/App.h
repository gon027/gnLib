#ifndef APP_H
#define APP_H

#include <string>
#include "../include/Vector/Vector2.h"

namespace gnLib {

	class Vector2;

	namespace App {

		/// <summary>
		/// �Q�[�����C�u�����̏�����
		/// </summary>
		/// <param name="_title"> �E�C���h�E�̃^�C�g�� </param>
		/// <param name="_width"> �E�C���h�E�̕� </param>
		/// <param name="_height"> �E�C���h�E�̍��� </param>
		/// <returns></returns>
		bool init(std::string _title = "App", int _width = 640, int _height = 480);

		/// <summary>
		/// �X�V�֐�
		/// </summary>
		/// <returns></returns>
		bool update();

		/// <summary>
		/// �X�V�J�n�֐�
		/// </summary>
		void begin();

		/// <summary>
		/// �X�V�I���֐�
		/// </summary>
		void end();

		/// <summary>
		/// �E�C���h�E�̃T�C�Y���擾����֐�
		/// </summary>
		/// <returns> �E�C���h�E�̃T�C�Y </returns>
		const Vector2 getWindowSize();
	}

}

#endif // !APP_H

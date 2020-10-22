#ifndef GNLIB_H
#define GNLIB_H

#include "include/App.h"

// �f�o�b�N
#include "include/Debug/Debug.h"

// ����
#include "include/Input/Input.h"

// �e�N�X�`��
#include "include/Texture/Texture.h"

// �X�v���C�g
#include "include/Sprite/Sprite.h"

// �F
#include "include/Color/Color.h"

// ���w
#include "include/Common/Math.h"

// �l�p�`
#include "include/Rect/Rect.h"

// �~
#include "include/Circle/Circle.h"

// ��
#include "include/Line/Line.h"

// �_
#include "include/Point/Point.h"

// �|���S��
#include "include/Polygon/Polygon.h"

// ������`��
#include "include/StringRender/StringRender.h"

// �m�C�Y
#include "include/Noise/Noise.h"

// �x�N�g��( 2D )
#include "include/Vector/Vector2.h"

// �x�N�g��( 3D )
#include "include/Vector/Vector3.h"

using namespace gnLib;

// ���C���֐�
// cpp�t�@�C���ł��̊֐�����������
void gnMain();

// WinMain�֐�
// gnMain���Ăяo��
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
	gnMain();
	return 0;
}

#endif // !GNLIB_H
#ifndef GNLIB_H
#define GNLIB_H

#include "include/App.h"

// デバック
#include "include/Debug/Debug.h"

// 入力
#include "include/Input/Input.h"

// テクスチャ
#include "include/Texture/Texture.h"

// スプライト
#include "include/Sprite/Sprite.h"

// 色
#include "include/Color/Color.h"

// 数学
#include "include/Common/Math.h"

// 四角形
#include "include/Rect/Rect.h"

// 円
#include "include/Circle/Circle.h"

// 線
#include "include/Line/Line.h"

// 点
#include "include/Point/Point.h"

// ポリゴン
#include "include/Polygon/Polygon.h"

// 文字列描画
#include "include/StringRender/StringRender.h"

// ノイズ
#include "include/Noise/Noise.h"

// ベクトル( 2D )
#include "include/Vector/Vector2.h"

// ベクトル( 3D )
#include "include/Vector/Vector3.h"

using namespace gnLib;

// メイン関数
// cppファイルでこの関数を実装する
void gnMain();

// WinMain関数
// gnMainを呼び出す
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrefInstance, LPSTR lpCmdLine, int cmdShow) {
	gnMain();
	return 0;
}

#endif // !GNLIB_H

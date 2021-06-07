#ifndef APP_H
#define APP_H

#include <Vector/Vector2.h>
#include <string>

namespace gnLib {

	class Color;
	class Vector2;

	namespace App {

		/// <summary>
		/// ゲームライブラリの初期化
		/// </summary>
		/// <param name="_title"> ウインドウのタイトル </param>
		/// <param name="_width"> ウインドウの幅 </param>
		/// <param name="_height"> ウインドウの高さ </param>
		/// <returns></returns>
		bool init(std::string _title = "App", int _width = 640, int _height = 480);

		/// <summary>
		/// 更新関数
		/// </summary>
		/// <returns></returns>
		bool update();

		/// <summary>
		/// 更新開始関数
		/// </summary>
		void begin();

		/// <summary>
		/// 更新終了関数
		/// </summary>
		void end();

		/// <summary>
		/// ウインドウのタイトルを変更
		/// </summary>
		/// <param name="_title"></param>
		void setTitle(const std::string& _title);

		/// <summary>
		/// ウインドウの位置を設定
		/// </summary>
		/// <param name="_x"> x座標 </param>
		/// <param name="_y"> y座標 </param>
		void setWindowPosition(int _x, int _y);

		/// <summary>
		/// 背景色の設定
		/// </summary>
		/// <param name="_color"></param>
		void setColor(const Color& _color);

		/// <summary>
		/// ウインドウのサイズを取得する関数
		/// </summary>
		/// <returns> ウインドウのサイズ </returns>
		const Vector2 getWindowSize();
	}

}

#endif // !APP_H

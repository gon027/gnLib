#ifndef APP_H
#define APP_H

#include <string>
#include "../include/Vector/Vector2.h"

namespace gnLib {

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
		/// ウインドウのサイズを取得する関数
		/// </summary>
		/// <returns> ウインドウのサイズ </returns>
		const Vector2 getWindowSize();
	}

}

#endif // !APP_H

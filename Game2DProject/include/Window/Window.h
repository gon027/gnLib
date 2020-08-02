#ifndef WINDOW_H
#define WINDOW_H

#include <Windows.h>
#include <string>

using std::string;

namespace gnLib {

	namespace WindowInfo {
		static int Width = 640;
		static int Height = 480;
		static string WindowName = "App";
	}

	class Window {
	public:
		Window(string _title, int _width = 640, int _height = 480);
		~Window();

		bool createWindow();	//ウインドウの設定

		void setTitle(const string& _title);

		const int getWidth() const;

		const int getHeight() const;

		// ウインドウが閉じられているか
		bool isClosed() const;

		const HINSTANCE getHInstance() const;

		const HWND getHWnd() const;

	private:
		WNDCLASSEX winc;		//ウインドウの情報を格納する構造体
		HINSTANCE hInstance;
		HWND hwnd;				//ウインドウハンドル
		string title;
		int width;
		int height;
	};
}

#endif // !WINDOW_H
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

	struct WindowSize {
		int width;
		int height;
	};

	struct WindowPosition {
		int x;
		int y;
	};

	// スクリーンの大きさ
	struct ScreenSize {
		int width;
		int height;
	};

	class Window {
	public:
		Window(string _title = "App", int _width = 640, int _height = 480);
		~Window();

		void initWindow(const string& _title, int _width, int _height);

		//ウインドウの設定
		bool init();	

		// ウインドウのタイトルを設定
		void setTitle(const string& _title);

		// ウインドウの位置を設定
		void setWindowPosition(int _x, int _y);

		const int getWidth() const;

		const int getHeight() const;

		// ウインドウが閉じられているか
		bool isClosed() const;

		const HINSTANCE getHInstance() const;

		const HWND getHWnd() const;

	private:
		ScreenSize getScreenSize() const;

	private:
		WNDCLASSEX winc;		// ウインドウの情報を格納する構造体
		HINSTANCE hInstance;    // HInstance
		HWND hwnd;				// ウインドウハンドル

		ScreenSize screenSize;
		WindowSize windowSize;
		WindowPosition windowPosition;
		string title;
		int width;
		int height;
	};
}

#endif // !WINDOW_H
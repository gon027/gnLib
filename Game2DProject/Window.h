#ifndef WINDOW_H
#define WINDOW_H

#include <Windows.h>
#include <tchar.h>
#include <string>

using string = std::string;

namespace window {
	static LRESULT CALLBACK WindowProc(HWND hwnd, UINT msg, WPARAM wp, LPARAM lp);

	class Window {
	public:
		Window(string _title, int _width = 640, int _height = 480);
		~Window();

		static LRESULT CALLBACK WindowProc(HWND hwnd, UINT msg, WPARAM wp, LPARAM lp);

		bool createWindow();	//ウインドウの設定

		void setTitle(const string& _title);

		bool update();

		const int getWidth() const;

		const int getHeight() const;

		// ウインドウが閉じられているか
		bool isClosed() const;

		const HINSTANCE getHInstance();

		const HWND getHWnd();

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
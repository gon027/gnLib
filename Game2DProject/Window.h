#ifndef WINDOW_H
#define WINDOW_H

#include <Windows.h>
#include <tchar.h>

namespace window {
	static LRESULT CALLBACK WindowProc(HWND hwnd, UINT msg, WPARAM wp, LPARAM lp);

	class Window {
	public:
		Window();
		Window(HINSTANCE _hInstance, LONG _width, LONG _height);
		Window(LONG _width, LONG _height);
		~Window();

		static LRESULT CALLBACK WindowProc(HWND hwnd, UINT msg, WPARAM wp, LPARAM lp);

		bool create() noexcept;	//ウインドウの設定

		void setTitle(LPSTR _title);

		bool update();

		const int getWidth() const;

		const int getHeight() const;


	public:
		WNDCLASSEX winc;    //ウインドウの情報を格納する構造体
		HINSTANCE hInstance;
		HWND hwnd;          //ウインドウハンドル
		LPSTR title;
		int width;
		int height;
	};
}

#endif // !WINDOW_H
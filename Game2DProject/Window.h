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

		bool create() noexcept;	//�E�C���h�E�̐ݒ�

		void setTitle(LPSTR _title);

		bool update();

		const int getWidth() const;

		const int getHeight() const;


	public:
		WNDCLASSEX winc;    //�E�C���h�E�̏����i�[����\����
		HINSTANCE hInstance;
		HWND hwnd;          //�E�C���h�E�n���h��
		LPSTR title;
		int width;
		int height;
	};
}

#endif // !WINDOW_H
#ifndef WINDOW_H
#define WINDOW_H

#include <Windows.h>
#include <string>

using string = std::string;

namespace window {

	class Window {
	public:
		Window(string _title, int _width = 640, int _height = 480);
		~Window();

		bool createWindow();	//�E�C���h�E�̐ݒ�

		void setTitle(const string& _title);

		const int getWidth() const;

		const int getHeight() const;

		// �E�C���h�E�������Ă��邩
		bool isClosed() const;

		const HINSTANCE getHInstance() const;

		const HWND getHWnd() const;

	private:
		WNDCLASSEX winc;		//�E�C���h�E�̏����i�[����\����
		HINSTANCE hInstance;
		HWND hwnd;				//�E�C���h�E�n���h��
		string title;
		int width;
		int height;
	};
}

#endif // !WINDOW_H
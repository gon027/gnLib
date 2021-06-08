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

	// �X�N���[���̑傫��
	struct ScreenSize {
		int width;
		int height;
	};

	class Window {
	public:
		Window(string _title = "App", int _width = 640, int _height = 480);
		~Window();

		void initWindow(const string& _title, int _width, int _height);

		//�E�C���h�E�̐ݒ�
		bool init();	

		// �E�C���h�E�̃^�C�g����ݒ�
		void setTitle(const string& _title);

		// �E�C���h�E�̈ʒu��ݒ�
		void setWindowPosition(int _x, int _y);

		const int getWidth() const;

		const int getHeight() const;

		// �E�C���h�E�������Ă��邩
		bool isClosed() const;

		const HINSTANCE getHInstance() const;

		const HWND getHWnd() const;

	private:
		ScreenSize getScreenSize() const;

	private:
		WNDCLASSEX winc;		// �E�C���h�E�̏����i�[����\����
		HINSTANCE hInstance;    // HInstance
		HWND hwnd;				// �E�C���h�E�n���h��

		ScreenSize screenSize;
		WindowSize windowSize;
		WindowPosition windowPosition;
		string title;
		int width;
		int height;
	};
}

#endif // !WINDOW_H
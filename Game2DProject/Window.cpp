#include "Window.h"

namespace window {
	Window::Window()
		: winc()
		, hInstance(nullptr)
		, title((LPSTR)("Window"))
		, width(640)
		, height(480)
	{

	}

	Window::Window(HINSTANCE _hInstance, LONG _width = 640, LONG _height = 480)
		: hInstance(nullptr)
		, width(_width)
		, height(_height)
	{

	}

	Window::Window(LONG _width = 640, LONG _height = 480) 
		: hInstance(nullptr)
		, width(_width)
		, height(_height)
	{

	}

	Window::~Window() {
		//ウインドウクラス登録解除
		UnregisterClass(winc.lpszClassName, hInstance);
	}

	LRESULT Window::WindowProc(HWND hwnd, UINT msg, WPARAM wp, LPARAM lp)
	{
		switch (msg) {
		case WM_DESTROY:
			PostQuitMessage(0);
			return 0;
		}

		return DefWindowProc(hwnd, msg, wp, lp);
	}


	bool Window::create() noexcept {
		winc.cbSize = sizeof(WNDCLASSEX);
		winc.style = CS_HREDRAW | CS_VREDRAW;
		winc.lpfnWndProc = WindowProc;
		winc.cbClsExtra = 0;
		winc.cbWndExtra = 0;
		winc.hInstance = hInstance;
		winc.hIcon = ((HICON)LoadImage(NULL, IDI_APPLICATION, IMAGE_ICON, 0, 0, LR_DEFAULTSIZE | LR_SHARED));
		winc.hCursor = (HCURSOR)LoadImage(NULL, IDC_ARROW, IMAGE_CURSOR, 0, 0, LR_DEFAULTSIZE | LR_SHARED);
		winc.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
		winc.lpszMenuName = NULL;
		winc.lpszClassName = title;
		winc.hIconSm = NULL;

		//ウインドウクラスを登録
		if (!RegisterClassEx(&winc)) return false;

		RECT rect{ 0, 0, width, height };
		AdjustWindowRect(&rect, WS_OVERLAPPEDWINDOW, false);

		hwnd = CreateWindow(
			title,
			title,
			WS_OVERLAPPEDWINDOW,
			CW_USEDEFAULT,
			CW_USEDEFAULT,
			rect.right - rect.left,
			rect.bottom - rect.top,
			nullptr,
			nullptr,
			hInstance,
			nullptr
		);

		if (!ShowWindow(hwnd, SW_SHOW)) {
			return false;
		}

		return true;
	}

	void Window::setTitle(LPSTR _title)
	{
		title = _title;
	}

	bool Window::update()
	{
		MSG msg{};

		while (true) {
			if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE)) {

				if (msg.message == WM_QUIT) {
					return false;
				}

				::TranslateMessage(&msg);
				::DispatchMessage(&msg);
			}
			else {
				return true;
			}
		}
	}

	const int Window::getWidth() const
	{
		return width;
	}

	const int Window::getHeight() const
	{
		return height;
	}
}
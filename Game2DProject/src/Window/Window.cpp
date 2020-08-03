#include "../../include/Window/Window.h"
#include "../../include/Window/WinProc.h"

namespace gnLib {
	Window::Window()
		: winc()
		, hInstance(GetModuleHandle(NULL))
		, hwnd(nullptr)
	{

	}

	Window::Window(string _title, int _width, int _height)
		: winc()
		, hInstance(GetModuleHandle(NULL))
		, hwnd(nullptr)
		, title(_title)
		, width(_width)
		, height(_height)
	{

	}

	Window::~Window() {
		//ウインドウクラス登録解除
		UnregisterClass(winc.lpszClassName, hInstance);
	}

	void Window::initWindow(const string & _title, int _width, int _height)
	{
		title = _title;
		width = _width;
		height = _height;

		//createWindow();
	}

	bool Window::init() {
		winc.cbSize = sizeof(WNDCLASSEX);
		winc.style = CS_HREDRAW | CS_VREDRAW;
		winc.lpfnWndProc = gnLib::WindowProc;
		winc.cbClsExtra = 0;
		winc.cbWndExtra = 0;
		winc.hInstance = hInstance;
		winc.hIcon = ((HICON)LoadImage(NULL, IDI_APPLICATION, IMAGE_ICON, 0, 0, LR_DEFAULTSIZE | LR_SHARED));
		winc.hCursor = (HCURSOR)LoadImage(NULL, IDC_ARROW, IMAGE_CURSOR, 0, 0, LR_DEFAULTSIZE | LR_SHARED);
		winc.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
		winc.lpszMenuName = NULL;
		winc.lpszClassName = title.c_str();
		winc.hIconSm = NULL;

		//ウインドウクラスを登録
		if (!RegisterClassEx(&winc)) return false;

		RECT rect{ 0, 0, (LONG)width, (LONG)height };
		AdjustWindowRect(&rect, WS_OVERLAPPEDWINDOW, false);

		hwnd = CreateWindow(
			title.c_str(),
			title.c_str(),
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

	void Window::setTitle(const string& _title)
	{
		title = _title;
	}

	const int Window::getWidth() const
	{
		return width;
	}

	const int Window::getHeight() const
	{
		return height;
	}

	bool Window::isClosed() const
	{
		return IsWindow(hwnd);
	}

	const HINSTANCE Window::getHInstance() const
	{
		return hInstance;
	}

	const HWND Window::getHWnd() const 
	{
		return hwnd;
	}
}
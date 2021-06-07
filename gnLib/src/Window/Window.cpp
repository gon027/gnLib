#include <Window/Window.h>
#include <Window/WinProc.h>
#include <App.h>

namespace gnLib {

	Window::Window(string _title, int _width, int _height)
		: winc()
		, hInstance(GetModuleHandle(NULL))
		, hwnd(nullptr)
		, screenSize({})
		, windowSize({})
		, windowPosition({})
		, title(_title)
		, width(_width)
		, height(_height)
	{
		WindowInfo::WindowName = _title;
		WindowInfo::Width = _width;
		WindowInfo::Height = _height;
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

		WindowInfo::WindowName = _title;
		WindowInfo::Width  = _width;
		WindowInfo::Height = _height;
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

		{
			RECT rect{ 0, 0, (LONG)width, (LONG)height };
			AdjustWindowRect(&rect, WS_OVERLAPPEDWINDOW, false);

			windowSize.width = rect.right - rect.left;
			windowSize.height = rect.bottom - rect.top;
		}

		hwnd = CreateWindow(
			title.c_str(),
			title.c_str(),
			WS_OVERLAPPEDWINDOW,
			CW_USEDEFAULT,
			CW_USEDEFAULT,
			windowSize.width,
			windowSize.height,
			nullptr,
			nullptr,
			hInstance,
			nullptr
		);

		screenSize = getScreenSize();

		// ウインドウを中心に設定
		{
			windowPosition.x = (screenSize.width - windowSize.width) / 2;
			windowPosition.y = (screenSize.height - windowSize.height) / 2;

			setWindowPosition(windowPosition.x, windowPosition.y);
		}

		if (!ShowWindow(hwnd, SW_SHOW)) {
			return false;
		}

		return true;
	}

	void Window::setTitle(const string& _title)
	{
		title = _title;
		SetWindowTextA(hwnd, _title.c_str());
	}

	void Window::setWindowPosition(int _x, int _y)
	{
		windowPosition.x = _x;
		windowPosition.y = _y;
		SetWindowPos(hwnd, 0, windowPosition.x, windowPosition.y, 0, 0, SWP_NOSIZE);
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

	ScreenSize Window::getScreenSize() const
	{
		RECT rc;
		SystemParametersInfo(SPI_GETWORKAREA, 0, &rc, 0);
		return {
			rc.right - rc.left,
			rc.bottom - rc.top
		};
	}
}
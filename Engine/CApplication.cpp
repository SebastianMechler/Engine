#include "CApplication.h"

bool Engine::CApplication::Initialize(const SWindowDesc& a_windowDescription)
{
	WNDCLASS wndClass;
	ZeroMemory(&wndClass, sizeof(WNDCLASS));

	wndClass.hCursor = LoadCursor(NULL, IDC_ARROW); // load cursor 
	wndClass.hIcon = LoadIcon(NULL, IDI_INFORMATION); // load icon 
	wndClass.hbrBackground = static_cast<HBRUSH>(GetStockObject(GRAY_BRUSH)); // background color 
	wndClass.lpfnWndProc = CApplication::WndProc; // message handler 
	wndClass.lpszClassName = "MyWindowClass"; // window class name 
	wndClass.lpszMenuName = NULL; // no menu 
	wndClass.style = CS_DBLCLKS | CS_OWNDC | CS_HREDRAW | CS_VREDRAW; // window behaviour 

	if (FAILED(RegisterClass(&wndClass)))
	{
		return false;
	}

	CWindow window;
	if (!window.Initialize(a_windowDescription))
	{
		return false;
	}

	return true;
}

void Engine::CApplication::Run() const
{
	bool keepGoing = true;
	
	while (keepGoing)
	{
		keepGoing = INPUT.PollMessages();
	}
}

LRESULT Engine::CApplication::WndProc(HWND a_hwnd, unsigned int a_Message, WPARAM a_wParam, LPARAM a_lParam)
{

	switch (a_Message)
	{
	case WM_DESTROY:
	case WM_QUIT:
	case WM_CLOSE:
		PostQuitMessage(0); // shutdown the window 
	}
	
	// call default message handling 
	return (DefWindowProc(a_hwnd, a_Message, a_wParam, a_lParam));
}

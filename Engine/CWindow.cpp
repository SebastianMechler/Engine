#include "CWindow.h"

bool Engine::CWindow::Initialize(const SWindowDesc& a_windowDescription)
{
	int windowStyle = WS_OVERLAPPEDWINDOW;//WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU | WS_THICKFRAME | WS_MINIMIZEBOX | WS_MAXIMIZEBOX;

	int screenX = GetSystemMetrics(SM_CXSCREEN);
	int screenY = GetSystemMetrics(SM_CYSCREEN);

	RECT windowRect = { 0, 0, 0, 0 };

	if (a_windowDescription.isFullScreen)
	{
		windowRect.left = 0;
		windowRect.right = 0;
		windowRect.right = screenX;
		windowRect.bottom = screenY;
	}
	else
	{
		windowRect.right = a_windowDescription.width;
		windowRect.bottom = a_windowDescription.height;

		AdjustWindowRect(&windowRect, windowStyle, false);

		windowRect.right = a_windowDescription.width - windowRect.left;
		windowRect.bottom = a_windowDescription.height - windowRect.top;

		
		switch (a_windowDescription.windowAlignment)
		{
		case EWindowAlignment::TopLeft:
			windowRect.left = 0;
			windowRect.top = 0;
			break;

		case EWindowAlignment::TopRight:
			windowRect.left = screenX - windowRect.right;
			windowRect.top = 0;
			break;

		case EWindowAlignment::BottomLeft:
			windowRect.left = 0;
			windowRect.top = screenY - windowRect.bottom;
			break;

		case EWindowAlignment::BottomRight:
			windowRect.left = screenX - windowRect.right;
			windowRect.top = screenY - windowRect.bottom;
			break;

		case EWindowAlignment::Top:
			windowRect.left = screenX / 2 - windowRect.right / 2;
			windowRect.top = 0;
			break;

		case EWindowAlignment::Bottom:
			windowRect.left = screenX / 2 - windowRect.right / 2;
			windowRect.top = screenY - windowRect.bottom;
			break;

		case EWindowAlignment::Left:
			windowRect.left = 0;
			windowRect.top = screenY / 2 - windowRect.bottom / 2;
			break;

		case EWindowAlignment::Right:
			windowRect.left = screenX - windowRect.right;
			windowRect.top = screenY / 2 - windowRect.bottom / 2;
			break;

		case EWindowAlignment::Center:
			windowRect.left = screenX / 2 - windowRect.right / 2;
			windowRect.top = screenY / 2 - windowRect.bottom / 2;
			break;

		default:
			break;
		}
	}

	mHwnd = CreateWindow("MyWindowClass", a_windowDescription.name, windowStyle, windowRect.left, windowRect.top, windowRect.right, windowRect.bottom, nullptr, nullptr, GetModuleHandle(NULL), nullptr);
	if (mHwnd != NULL)
	{
		SetFocus(mHwnd);
		SetForegroundWindow(mHwnd);
		ShowWindow(mHwnd, SW_SHOW);

		return true;
	}
	

	return false;
}

HWND Engine::CWindow::GetHandle() const
{
	return this->mHwnd;
}

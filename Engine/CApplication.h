#pragma once
#include <Windows.h>

#include "CInputManager.h"
#include "CWindow.h"

namespace Engine
{
	class CApplication
	{
	public:
		bool Initialize(const SWindowDesc& a_windowDescription);
		void Run() const;
		static LRESULT CALLBACK WndProc(HWND a_hwnd, unsigned int a_Message, WPARAM a_wParam, LPARAM a_lParam);
	};
}
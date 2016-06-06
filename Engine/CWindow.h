#pragma once

#include <Windows.h>

#include "SWindowDesc.h"

namespace Engine
{
	class CWindow
	{
	public:
		bool Initialize(const SWindowDesc& a_windowDescription);
		HWND GetHandle() const;

	private:
		HWND mHwnd;
	};
}
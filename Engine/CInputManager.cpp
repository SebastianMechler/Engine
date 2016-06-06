#include "CInputManager.h"
#include <stdio.h>

Engine::CInputManager::CInputManager()
{
}

bool Engine::CInputManager::PollMessages()
{
	MSG msg = { 0 };
	
	//get all messages and store pressed in map
	while (PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE) > 0)
	{
		switch (msg.message)
		{
		case WM_DESTROY:
		case WM_QUIT:
		case WM_CLOSE:
			return false;

		case WM_KEYDOWN:
			this->mKeyMap[static_cast<EKeyCode>(msg.wParam)] = true;
			printf("%s: %d %s", "KEY PRESSED...", static_cast<int>(msg.wParam), "\n");

			// exit
			if (msg.wParam == static_cast<int>(EKeyCode::K_ESCAPE))
			{
				return false;
			}
			break;


		case WM_KEYUP:
			this->mKeyMap[static_cast<EKeyCode>(msg.wParam)] = false;
			break;
		}

		TranslateMessage(&msg); // translate message 
		DispatchMessage(&msg); // process message 
	}

	return true;
}

bool Engine::CInputManager::GetKey(EKeyCode a_KeyCode) const
{
	return this->mKeyMap.at(a_KeyCode);
}

Engine::CInputManager& Engine::CInputManager::GetInstance()
{
	static CInputManager inputManager;
	return inputManager;
}
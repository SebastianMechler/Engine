#pragma once

#include <Windows.h>
#include "EKeyCode.h"
#include <unordered_map>

namespace Engine
{
	class CInputManager
	{
	public:
		bool PollMessages();
		bool GetKey(EKeyCode a_KeyCode) const;

		static CInputManager& GetInstance();

	private:
		CInputManager();
		CInputManager(const CInputManager &other);
		CInputManager operator=(const CInputManager &other);

		std::unordered_map<EKeyCode, bool> mKeyMap;
	};
}

#define INPUT Engine::CInputManager::GetInstance()

#pragma once

#include "EWindowAlignment.h"

namespace Engine
{
	struct SWindowDesc
	{
		LONG width;
		LONG height;
		const char* name;
		bool isFullScreen;
		EWindowAlignment windowAlignment;
	};
}

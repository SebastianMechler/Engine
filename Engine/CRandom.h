#pragma once
#include <stdlib.h> // required for function: srand + rand
#include <time.h> // required for function: timeGetTime

namespace Engine
{
	namespace Tools
	{
		class CRandom
		{
		public:
			int GetRandomNumber(const int min, const int max);
			static CRandom& GetInstance();

		private:
			CRandom();
			CRandom(const CRandom &other);
			CRandom operator=(const CRandom &other);
		};
	}
}


#define RANDOM Engine::Tools::CRandom::GetInstance().GetRandomNumber

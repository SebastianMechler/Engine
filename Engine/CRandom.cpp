#include "CRandom.h"

// Constructor
Engine::Tools::CRandom::CRandom()
{
	// static variable, which will persist in all Random classes
	static bool isSeeded = false;

	if (isSeeded == false)
	{
		// Initialize the seed only once per application
		srand((unsigned int)time(nullptr));
		isSeeded = true;
	}
}

int Engine::Tools::CRandom::GetRandomNumber(const int min, const int max)
{
	// returns a random number between min and max
	return(rand() % (max - min + 1) + min);
}

Engine::Tools::CRandom& Engine::Tools::CRandom::GetInstance()
{
	static CRandom Rnd;
	return (Rnd);
}
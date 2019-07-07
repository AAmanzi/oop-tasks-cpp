#pragma once
#include <string>
#include <list>
#include "Enums.h"

class IVideoGame
{
public:
	virtual std::string GetType() = 0;
	virtual std::string GetName() = 0;
	virtual std::list<enums::Platform> GetPlatforms() = 0;
	virtual ~IVideoGame();
};

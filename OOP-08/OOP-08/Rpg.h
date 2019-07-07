#pragma once
#include "VideoGame.h"

class Rpg : virtual public VideoGame
{
public:
	Rpg
	(
		std::string name,
		std::list<enums::Platform> platforms
	);
	Rpg();
	virtual ~Rpg();
};


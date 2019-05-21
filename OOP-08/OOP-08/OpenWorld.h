#pragma once
#include "VideoGame.h"

class OpenWorld : virtual public VideoGame
{
public:
	OpenWorld
	(
		std::string name,
		std::list<enums::Platform> platforms
	);
	OpenWorld();

	virtual ~OpenWorld();
};


#pragma once
#include "VideoGame.h"

class Action : virtual public VideoGame
{
public:
	Action
	(
		std::string name, 
		std::list<enums::Platform> platforms
	);
	Action();

	virtual ~Action();
};


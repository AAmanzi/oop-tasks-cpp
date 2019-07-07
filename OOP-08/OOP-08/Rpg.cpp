#include "Rpg.h"


Rpg::Rpg
(
	std::string name, 
	std::list<enums::Platform> platforms
)
	: VideoGame
	(
		name,
		"Action",
		platforms
	)
{}

Rpg::Rpg()
{
	Type = "Rpg";
}


Rpg::~Rpg()
{
	Platforms.clear();
}

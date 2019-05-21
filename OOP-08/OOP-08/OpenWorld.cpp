#include "OpenWorld.h"


OpenWorld::OpenWorld
(
	std::string name, 
	std::list<enums::Platform> platforms
)
	: VideoGame
(
	name,
	"Open World",
	platforms
)
{}

OpenWorld::OpenWorld()
{
	Type = "Open World";
}


OpenWorld::~OpenWorld()
{
	Platforms.clear();
}

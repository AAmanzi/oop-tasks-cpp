#include "VideoGame.h"


VideoGame::VideoGame
(
	std::string name, 
	std::string type, 
	std::list<enums::Platform> platforms
)
{
	Name = name;
	Type = type;
	Platforms = platforms;
}

std::string VideoGame::GetType()
{
	return Type;
}

std::string VideoGame::GetName()
{
	return Name;
}

std::list<enums::Platform> VideoGame::GetPlatforms()
{
	return Platforms;
}

VideoGame::~VideoGame()
{
	Platforms.clear();
}

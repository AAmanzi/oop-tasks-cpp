#include "Action.h"


Action::Action
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

Action::Action()
{
	Type = "Action";
}

Action::~Action()
{
	Platforms.clear();
}

#include "GodOfWar.h"



GodOfWar::GodOfWar()
{
	Name = "God of War";
	Platforms = *new std::list<enums::Platform>
		{
			enums::PS4
		};
}


GodOfWar::~GodOfWar()
{
	Platforms.clear();
}

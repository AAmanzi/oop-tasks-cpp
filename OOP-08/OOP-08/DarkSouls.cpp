#include "DarkSouls.h"



DarkSouls::DarkSouls()
{
	Name = "Dark Souls";
	Platforms = *new std::list<enums::Platform>
		{
			enums::PC,
			enums::PS4,
			enums::XBOX
		};
}


DarkSouls::~DarkSouls()
{
	Platforms.clear();
}

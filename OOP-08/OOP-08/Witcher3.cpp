#include "Witcher3.h"



Witcher3::Witcher3()
{
	Name = "Witcher 3";
	Type = "Rpg, Open World";
	Platforms = *new std::list<enums::Platform>
		{
			enums::PC,
			enums::PS4,
			enums::XBOX
		};
}


Witcher3::~Witcher3()
{
	Platforms.clear();
}

#include "Fallout4.h"



Fallout4::Fallout4()
{
	Name = "Fallout 4";
	Platforms = *new std::list<enums::Platform>
		{
			enums::PC,
			enums::PS4,
			enums::XBOX
		};
}


Fallout4::~Fallout4()
{
	Platforms.clear();
}

#include "LastOfUs2.h"



LastOfUs2::LastOfUs2()
{
	Name = "The Last of Us 2";
	Platforms = *new std::list<enums::Platform>
		{
			enums::PS4
		};
}


LastOfUs2::~LastOfUs2()
{
	Platforms.clear();
}

#include <iostream>
#include "Fallout4.h"
#include "DarkSouls.h"
#include "GodOfWar.h"
#include "LastOfUs2.h"
#include "Witcher3.h"
#include "PlatformCounter.h"
#include <pplwin.h>

int main()
{
	auto darkSouls = new DarkSouls();
	auto fallout = new Fallout4();
	auto godOfWar = new GodOfWar();
	auto lastOfUs = new LastOfUs2();
	auto witcher = new Witcher3();

	auto platformCounter = new PlatformCounter();

	auto videoGames = new std::list<VideoGame*>
		{
			darkSouls,
			fallout,
			godOfWar,
			lastOfUs,
			witcher
		};

	for
	(auto& videoGame : *videoGames)
	{
		platformCounter->AddPlatforms(*videoGame);
	}

	std::cout 
		<< enums::EnumParser::ParsePlatform(platformCounter->GetMostOccurringPlatform())
		<< std::endl;

	system("pause");
}

#include "PlatformCounter.h"


PlatformCounter::PlatformCounter(int pc, int ps4, int xbox)
{
	Pc = pc;
	Ps4 = ps4;
	Xbox = xbox;
}

PlatformCounter::PlatformCounter(VideoGame videoGame)
	: Pc(0), Ps4(0), Xbox(0)
{
	auto platforms = videoGame.GetPlatforms();

	for
	(auto& platform : platforms)
	{
		if (platform == enums::PC)
			Pc = 1;
		if (platform == enums::PS4)
			Ps4 = 1;
		if (platform == enums::XBOX)
			Xbox = 1;
	}
}

PlatformCounter::PlatformCounter()
{
	Pc = 0;
	Ps4 = 0;
	Xbox = 0;
}

void PlatformCounter::AddPlatforms(VideoGame videoGame)
{
	auto platforms = videoGame.GetPlatforms();

	for
	(auto& platform : platforms)
	{
		if (platform == enums::PC)
			Pc++;
		if (platform == enums::PS4)
			Ps4++;
		if (platform == enums::XBOX)
			Xbox++;
	}
}

enums::Platform PlatformCounter::GetMostOccurringPlatform()
{
	if(Ps4 > Pc && Ps4 > Xbox)
		return enums::PS4;
	if(Xbox > Pc && Xbox > Ps4)
		return enums::XBOX;
	return enums::PC;
}

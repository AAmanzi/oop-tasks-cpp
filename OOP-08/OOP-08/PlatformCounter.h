#pragma once
#include "VideoGame.h"

class PlatformCounter
{
protected:
	int Pc;
	int Ps4;
	int Xbox;
public:
	PlatformCounter(int pc, int ps4, int xbox);
	PlatformCounter(VideoGame videoGame);
	PlatformCounter();

	void AddPlatforms(VideoGame videoGame);
	enums::Platform GetMostOccurringPlatform();
};


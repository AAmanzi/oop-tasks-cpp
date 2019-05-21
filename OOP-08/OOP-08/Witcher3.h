#pragma once
#include "Rpg.h"
#include "OpenWorld.h"

class Witcher3 : public Rpg, public OpenWorld
{
public:
	Witcher3();
	virtual ~Witcher3();
};


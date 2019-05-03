#include "Tiger.h"

zoo::Tiger::Tiger
	(
		std::string name, 
		int yearOfBirth, 
		int cageNumber, 
		int mealsPerDay
	)
	: Mammal
	(
		"P. tigris", 
		name, 
		yearOfBirth, 
		10, 
		cageNumber, 
		mealsPerDay, 
		3, 
		37
	)
{}

zoo::Tiger::Tiger(const Tiger& copy)
	: Mammal(copy)
{;}

zoo::Tiger::~Tiger()
{
	MassByYear.clear();
}

void zoo::Tiger::InputTo(std::istream& inputStream)
{}

void zoo::Tiger::SetDefaults()
{
	Mammal::SetDefaults();
	Species = "P. tigris";
	LifespanInYears = 10;
	GestationPeriodInMonths = 3;
	AvgTemperatureInCelsius = 37;
}

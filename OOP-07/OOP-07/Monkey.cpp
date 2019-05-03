#include "Monkey.h"

zoo::Monkey::Monkey
	(
		std::string name, 
		int yearOfBirth, 
		int cageNumber, 
		int mealsPerDay
	)
	: Mammal
	(
		"M. sphinx", 
		name, 
		yearOfBirth, 
		20, 
		cageNumber, 
		mealsPerDay, 
		6, 
		37
	)
{}

zoo::Monkey::Monkey(const Monkey& copy)
	: Mammal(copy)
{;}

zoo::Monkey::~Monkey()
{
	MassByYear.clear();
}

void zoo::Monkey::InputTo(std::istream& inputStream)
{}

void zoo::Monkey::SetDefaults()
{
	Mammal::SetDefaults();
	Species = "M. sphinx";
	LifespanInYears = 20;
	GestationPeriodInMonths = 6;
	AvgTemperatureInCelsius = 37;
}

#include "Elephant.h"

zoo::Elephant::Elephant
	(
		std::string name, 
		int yearOfBirth, 
		int cageNumber, 
		int mealsPerDay
	)
	: Mammal
	(
		"L. africana", 
		name, 
		yearOfBirth, 
		65, 
		cageNumber, 
		mealsPerDay, 
		24, 
		36
	)
{}

zoo::Elephant::Elephant(const Elephant& copy)
	: Mammal(copy)
{;}

zoo::Elephant::~Elephant()
{
	MassByYear.clear();
}

void zoo::Elephant::InputTo(std::istream& inputStream)
{}

void zoo::Elephant::SetDefaults()
{
	Mammal::SetDefaults();
	Species = "L. africana";
	LifespanInYears = 65;
	GestationPeriodInMonths = 24;
	AvgTemperatureInCelsius = 36;
}

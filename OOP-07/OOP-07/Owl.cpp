#include "Owl.h"

zoo::Owl::Owl
	(
		std::string name, 
		int yearOfBirth, 
		int cageNumber, 
		int mealsPerDay,
		int mealPortionInKg
	)
	: Bird
	(
		"S. bubo", 
		name, 
		yearOfBirth, 
		4, 
		cageNumber,
		mealsPerDay,
		mealPortionInKg,
		1, 
		38
	)
{}

zoo::Owl::Owl(const Owl& copy)
	: Bird(copy)
{;}

zoo::Owl::~Owl()
{
	MassByYear.clear();
}

void zoo::Owl::InputTo(std::istream& inputStream)
{}

void zoo::Owl::SetDefaults()
{
	Bird::SetDefaults();
	Species = "S. bubo";
	LifespanInYears = 4;
	IncubationPeriodInMonths = 1;
	AvgTemperatureInCelsius = 38;
}
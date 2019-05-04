#include "Crocodile.h"

zoo::Crocodile::Crocodile
	(
		std::string name, 
		int yearOfBirth, 
		int cageNumber, 
		int mealsPerDay,
		int mealPortionInKg
	)
	: Reptile
	(
		"C. porosus", 
		name, 
		yearOfBirth, 
		70, 
		cageNumber, 
		mealsPerDay,
		mealPortionInKg,
		3, 
		30
	)
{}

zoo::Crocodile::Crocodile(const Crocodile& copy)
	: Reptile(copy)
{;}

zoo::Crocodile::~Crocodile()
{
	MassByYear.clear();
}

void zoo::Crocodile::InputTo(std::istream& inputStream)
{
}

void zoo::Crocodile::SetDefaults()
{
	Reptile::SetDefaults();
	Species = "C. porosus";
	LifespanInYears = 70;
	IncubationPeriodInMonths = 3;
	EnvironmentTemperatureInCelsius = 30;
}

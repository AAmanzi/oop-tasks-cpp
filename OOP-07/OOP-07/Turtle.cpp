#include "Turtle.h"

zoo::Turtle::Turtle
	(
		std::string name, 
		int yearOfBirth, 
		int cageNumber, 
		int mealsPerDay,
		int mealPortionInKg
	)
	: Reptile
	(
		"C. caretta", 
		name, 
		yearOfBirth, 
		57, 
		cageNumber, 
		mealsPerDay,
		mealPortionInKg,
		3, 
		30
	)
{}

zoo::Turtle::Turtle(const Turtle& copy)
	: Reptile(copy)
{;}

zoo::Turtle::~Turtle()
{
	MassByYear.clear();
}

void zoo::Turtle::InputTo(std::istream& inputStream)
{}

void zoo::Turtle::SetDefaults()
{
	Reptile::SetDefaults();
	Species = "C. caretta";
	LifespanInYears = 57;
	IncubationPeriodInMonths = 3;
	EnvironmentTemperatureInCelsius = 30;
}

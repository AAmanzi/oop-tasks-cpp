#include "GriffonVulture.h"

zoo::GriffonVulture::GriffonVulture
	(
		std::string name, 
		int yearOfBirth, 
		int cageNumber, 
		int mealsPerDay,
		int mealPortionInKg
	)
	: Bird
	(
		"G. fulvus", 
		name, 
		yearOfBirth, 
		41, 
		cageNumber, 
		mealsPerDay,
		mealPortionInKg,
		1, 
		38
	)
{}

zoo::GriffonVulture::GriffonVulture(const GriffonVulture& copy)
	: Bird(copy)
{;}

zoo::GriffonVulture::~GriffonVulture()
{
	MassByYear.clear();
}

void zoo::GriffonVulture::InputTo(std::istream& inputStream)
{}

void zoo::GriffonVulture::SetDefaults()
{
	Bird::SetDefaults();
	Species = "G. fulvus";
	LifespanInYears = 41;
	IncubationPeriodInMonths = 1;
	AvgTemperatureInCelsius = 38;
}
#include "Bird.h"

zoo::Bird::Bird
	(
		std::string species,
		std::string name, 
		int yearOfBirth, 
		int lifespanInYears, 
		int cageNumber, 
		int mealsPerDay,
		int mealPortionInKg,
		int incubationPeriodInMonths, 
		int avgTemperatureInCelsius
	)
	: ZooAnimal
	(
		species, 
		name, 
		yearOfBirth, 
		lifespanInYears, 
		cageNumber, 
		mealsPerDay,
		mealPortionInKg,
		"Oviparous", 
		"Warm-blooded"
	)
{
	IncubationPeriodInMonths = incubationPeriodInMonths;
	AvgTemperatureInCelsius = avgTemperatureInCelsius;
}

zoo::Bird::Bird(const Bird& copy)
	: ZooAnimal(copy)
{
	IncubationPeriodInMonths = copy.IncubationPeriodInMonths;
	AvgTemperatureInCelsius = copy.AvgTemperatureInCelsius;
}

zoo::Bird::~Bird()
{
	MassByYear.clear();
}

void zoo::Bird::OutputTo(std::ostream& outputStream) const
{
	ZooAnimal::OutputTo(outputStream);
	outputStream << "Incubation period (months): ";
	outputStream << IncubationPeriodInMonths << std::endl;
	outputStream << "Average temperature (Celsius): ";
	outputStream << AvgTemperatureInCelsius << std::endl;
}

void zoo::Bird::InputTo(std::istream& inputStream)
{
	std::cout << "Species: ";
	inputStream >> Species;
	std::cout << "Lifespan (years): ";
	inputStream >> LifespanInYears;
	std::cout << "Incubation period (months): ";
	inputStream >> IncubationPeriodInMonths;
	std::cout << "Average temperature (Celsius): ";
	inputStream >> AvgTemperatureInCelsius;
}

void zoo::Bird::SetDefaults()
{
	FertilizationType = "Oviparous";
	ThermoregulationType = "Warm-blooded";
}

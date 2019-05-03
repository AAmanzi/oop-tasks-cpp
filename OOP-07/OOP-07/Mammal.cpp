#include "Mammal.h"

zoo::Mammal::Mammal
	(
		std::string species,
		std::string name, 
		int yearOfBirth, 
		int lifespanInYears, 
		int cageNumber, 
		int mealsPerDay,
		int gestationPeriodInMonths, 
		int avgTemperatureInCelsius
	) 
	: ZooAnimal(
		species, 
		name, 
		yearOfBirth, 
		lifespanInYears, 
		cageNumber, 
		mealsPerDay, 
		"Viviparous", 
		"Warm-blooded"
	)
{
	GestationPeriodInMonths = gestationPeriodInMonths;
	AvgTemperatureInCelsius = avgTemperatureInCelsius;
}

zoo::Mammal::Mammal(const Mammal& copy)
	: ZooAnimal(copy)
{
	GestationPeriodInMonths = copy.GestationPeriodInMonths;
	AvgTemperatureInCelsius = copy.AvgTemperatureInCelsius;
}

zoo::Mammal::~Mammal()
{
	MassByYear.clear();
}

void zoo::Mammal::OutputTo(std::ostream& outputStream) const
{
	ZooAnimal::OutputTo(outputStream);
	outputStream << "Gestation period (months): ";
	outputStream << GestationPeriodInMonths << std::endl;
	outputStream << "Average temperature (Celsius): ";
	outputStream << AvgTemperatureInCelsius << std::endl;
}

void zoo::Mammal::InputTo(std::istream& inputStream)
{
	std::cout << "Species: ";
	inputStream >> Species;
	std::cout << "Lifespan (years): ";
	inputStream >> LifespanInYears;
	std::cout << "Gestation period (months): ";
	inputStream >> GestationPeriodInMonths;
	std::cout << "Average temperature (Celsius): ";
	inputStream >> AvgTemperatureInCelsius;
}

void zoo::Mammal::SetDefaults()
{
	FertilizationType = "Viviparous";
	ThermoregulationType = "Warm-blooded";
}

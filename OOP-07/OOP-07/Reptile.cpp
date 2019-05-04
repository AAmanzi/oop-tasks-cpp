#include "Reptile.h"

zoo::Reptile::Reptile
	(
		std::string species,
		std::string name, 
		int yearOfBirth, 
		int lifespanInYears, 
		int cageNumber,	
		int mealsPerDay,
		int mealPortionInKg,
		int incubationPeriodInMonths, 
		int environmentTemperatureInCelsius
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
		"Cold-blooded"
	)
{
	IncubationPeriodInMonths = incubationPeriodInMonths;
	EnvironmentTemperatureInCelsius = environmentTemperatureInCelsius;
}

zoo::Reptile::Reptile(const Reptile& copy)
	: ZooAnimal(copy)
{
	IncubationPeriodInMonths = copy.IncubationPeriodInMonths;
	EnvironmentTemperatureInCelsius = copy.EnvironmentTemperatureInCelsius;
}

zoo::Reptile::~Reptile()
{
	MassByYear.clear();
}

void zoo::Reptile::OutputTo(std::ostream& outputStream) const
{
	ZooAnimal::OutputTo(outputStream);
	outputStream << "Incubation period (months): ";
	outputStream << IncubationPeriodInMonths << std::endl;
	outputStream << "Environment temperature (Celsius): ";
	outputStream << EnvironmentTemperatureInCelsius << std::endl;
}

void zoo::Reptile::InputTo(std::istream& inputStream)
{
	std::cout << "Species: ";
	inputStream >> Species;
	std::cout << "Lifespan (years): ";
	inputStream >> LifespanInYears;
	std::cout << "Incubation period (months): ";
	inputStream >> IncubationPeriodInMonths;
	std::cout << "Environment temperature (Celsius): ";
	inputStream >> EnvironmentTemperatureInCelsius;
}

void zoo::Reptile::SetDefaults()
{
	FertilizationType = "Oviparous";
	ThermoregulationType = "Cold-blooded";
}

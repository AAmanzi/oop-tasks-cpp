#define _CRT_SECURE_NO_WARNINGS

#include "ZooAnimal.h"
#include <ctime>

zoo::ZooAnimal::ZooAnimal
	(
		std::string species,
		std::string name, 
		int yearOfBirth, 
		int lifespanInYears, 
		int cageNumber, 
		int mealsPerDay,
		std::string fertilizationType,
		std::string thermoregulationType
	)
{
	Species = species,
	Name = name;
	YearOfBirth = yearOfBirth;
	LifespanInYears = lifespanInYears;
	CageNumber = cageNumber;
	MealsPerDay = mealsPerDay;
	MassByYear = * new std::map<int, int>[lifespanInYears * 2];
	FertilizationType = fertilizationType;
	ThermoregulationType = thermoregulationType;
}

zoo::ZooAnimal::ZooAnimal()
= default;

zoo::ZooAnimal::~ZooAnimal()
{
	MassByYear.clear();
}

zoo::ZooAnimal::ZooAnimal(const ZooAnimal &copy) :
	Species(copy.Species),
	Name(copy.Name),
	YearOfBirth(copy.YearOfBirth),
	LifespanInYears(copy.LifespanInYears),
	CageNumber(copy.CageNumber),
	MealsPerDay(copy.MealsPerDay),
	MassByYear(copy.MassByYear),
	FertilizationType(copy.FertilizationType),
	ThermoregulationType(copy.ThermoregulationType){};

int zoo::ZooAnimal::MealsIncrease()
{
	MealsPerDay++;
	return MealsPerDay;
}

int zoo::ZooAnimal::MealsDecrease()
{
	MealsPerDay--;
	return MealsPerDay;
}

bool zoo::ZooAnimal::TryAddMassInfo(int currentMass)
{
	const auto now = Clock::now();
    auto nowC = Clock::to_time_t(now);
	const auto currentTime = localtime(&nowC);
	auto currentYear = currentTime->tm_year + 1900;

	if(MassByYear.find(currentYear) == MassByYear.end())
	{
		MassByYear.insert(std::pair<int, int>(currentYear, currentMass));
		return true;
	}
	std::cout << "Mass info for that year already exists!";
	return false;
}

bool zoo::ZooAnimal::TryAddMassInfo(int mass, int yearToAdd)
{
	if(MassByYear.find(yearToAdd) == MassByYear.end())
	{
		MassByYear.insert(std::pair<int, int>(yearToAdd, mass));
		return true;
	}
	std::cout << "Mass info for that year already exists!";
	return false;
}

int zoo::ZooAnimal::MassChangeDrastic()
{
	const auto now = Clock::now();
    auto nowC = Clock::to_time_t(now);
	const auto currentTime = localtime(&nowC);
	const auto currentYear = currentTime->tm_year + 1900;

	if(MassByYear.find(currentYear) == MassByYear.end())
	{
		std::cout << "This year's mass wasn't recorded yet!" << std::endl;
		return 404;
	}
	if(MassByYear.find(currentYear-1) == MassByYear.end())
	{
		std::cout << "Last year's mass hasn't been recorded!" << std::endl;
		return 403;
	}

	const auto currentMass = MassByYear.find(currentYear)->second;
	const auto previousMass = MassByYear.find(currentYear-1)->second;
	const auto maxDeviation = previousMass * 0.1;

	if(previousMass + maxDeviation < currentMass)
	{
		return 1;
	}

	if(previousMass - maxDeviation > currentMass)
	{
		return -1;
	}

	return 0;
}

int zoo::ZooAnimal::GetMass()
{
	const auto now = Clock::now();
    auto nowC = Clock::to_time_t(now);
	const auto currentTime = localtime(&nowC);
	const auto currentYear = currentTime->tm_year + 1900;
	return MassByYear.find(currentYear)->second;
}

auto zoo::ZooAnimal::GetName() const -> std::string
{
	return Name;
}

void zoo::ZooAnimal::OutputTo(std::ostream& outputStream) const
{
	outputStream << "Name: " << Name << std::endl;
	outputStream << "Species: " << Species << std::endl;
	outputStream << "Year of birth: " << YearOfBirth << std::endl;
	outputStream << "Life expectancy: " << LifespanInYears << " years" << std::endl;
	outputStream << "Cage number: " << CageNumber << std::endl;
	outputStream << "Meals per day: " << MealsPerDay << std::endl;
	outputStream << "Type of fertilization: " << FertilizationType << std::endl;
	outputStream << "Type of thermoregulation: " << ThermoregulationType << std::endl;
}

void zoo::ZooAnimal::InputTo(std::istream& inputStream)
{
	std::cout << "Species: ";
	inputStream >> Species;
	std::cout << "Lifespan (years): ";
	inputStream >> LifespanInYears;
	std::cout << "Type of fertilization: ";
	inputStream >> FertilizationType;
	std::cout << "Type of thermoregulation: ";
	inputStream >> ThermoregulationType;
}

void zoo::ZooAnimal::SetDefaults()
{
}

std::istream& zoo::operator>>(std::istream& inputStream, ZooAnimal& toInput)
{
	toInput.InputTo(inputStream);

	std::cout << "Name: ";
	inputStream >> toInput.Name;
	std::cout << "Year of birth: ";
	inputStream >> toInput.YearOfBirth;
	std::cout << "Cage number: ";
	inputStream >> toInput.CageNumber;
	std::cout << "Meals per day: ";
	inputStream >> toInput.MealsPerDay;

	toInput.SetDefaults();

	return inputStream;
}

std::ostream& zoo::operator<<(std::ostream& outputStream, const ZooAnimal& toOutput)
{
	toOutput.OutputTo(outputStream);

	return outputStream;
}

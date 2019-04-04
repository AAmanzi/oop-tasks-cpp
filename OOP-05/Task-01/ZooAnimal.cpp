#define _CRT_SECURE_NO_WARNINGS

#include "ZooAnimal.h"

ZooAnimal::ZooAnimal(string species, string name, int yearOfBirth,
	int lifeExpectancyInYears, int cageNumber, int mealsPerDay)
{
	Species = species,
	Name = name;
	YearOfBirth = yearOfBirth;
	LifeExpectancyInYears = lifeExpectancyInYears;
	CageNumber = cageNumber;
	MealsPerDay = mealsPerDay;
	MassByYear = * new map<int, int>[lifeExpectancyInYears * 2];
}

ZooAnimal::~ZooAnimal()
{
	MassByYear.clear();
}

ZooAnimal::ZooAnimal(const ZooAnimal &copy) :
	Species(copy.Species),
	Name(copy.Name),
	YearOfBirth(copy.YearOfBirth),
	LifeExpectancyInYears(copy.LifeExpectancyInYears),
	CageNumber(copy.CageNumber),
	MealsPerDay(copy.MealsPerDay),
	MassByYear(copy.MassByYear){};

int ZooAnimal::MealsIncrease()
{
	MealsPerDay++;
	return MealsPerDay;
}

int ZooAnimal::MealsDecrease()
{
	MealsPerDay--;
	return MealsPerDay;
}

bool ZooAnimal::TryAddMassInfo(int currentMass)
{
	const auto now = Clock::now();
    auto nowC = Clock::to_time_t(now);
	const auto currentTime = localtime(&nowC);
	auto currentYear = currentTime->tm_year + 1900;

	if(MassByYear.find(currentYear) == MassByYear.end())
	{
		MassByYear.insert(pair<int, int>(currentYear, currentMass));
		return true;
	}
	cout << "Mass info for that year already exists!";
	return false;
}

bool ZooAnimal::TryAddMassInfo(int mass, int yearToAdd)
{
	if(MassByYear.find(yearToAdd) == MassByYear.end())
	{
		MassByYear.insert(pair<int, int>(yearToAdd, mass));
		return true;
	}
	cout << "Mass info for that year already exists!";
	return false;
}

int ZooAnimal::MassChangeDrastic()
{
	const auto now = Clock::now();
    auto nowC = Clock::to_time_t(now);
	const auto currentTime = localtime(&nowC);
	const auto currentYear = currentTime->tm_year + 1900;

	if(MassByYear.find(currentYear) == MassByYear.end())
	{
		cout << "This year's mass wasn't recorded yet!" << endl;
		return 404;
	}
	if(MassByYear.find(currentYear-1) == MassByYear.end())
	{
		cout << "Last year's mass hasn't been recorded!" << endl;
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

void ZooAnimal::Print() const
{
	const auto now = Clock::now();
    auto nowC = Clock::to_time_t(now);
	const auto currentTime = localtime(&nowC);
	const auto currentYear = currentTime->tm_year + 1900;

	cout << Name << endl;
	cout << "Species: " << Species << endl;
	cout << "Year of birth: " << YearOfBirth << endl;
	cout << "Life expectancy: " << LifeExpectancyInYears << "years " << endl;
	cout << "Cage number: " << CageNumber << endl;
	cout << "Meals per day: " << MealsPerDay << endl;
	cout << "Mass: " << MassByYear.find(currentYear)->second << endl;
	cout << endl;
}

string ZooAnimal::GetName() const
{
	return Name;
}

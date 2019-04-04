#pragma once
#include <string>
#include <chrono>
#include <ctime>
#include <iostream>
#include <map>

using namespace std;
typedef std::chrono::system_clock Clock;

class ZooAnimal
{
	string Species, Name;
	int YearOfBirth, LifeExpectancyInYears;
	int CageNumber, MealsPerDay;
	map<int, int> MassByYear;
public:
	ZooAnimal(string species, string name, int yearOfBirth, int lifeExpectancyInYears, int cageNumber,
	          int mealsPerDay);
	~ZooAnimal();
	ZooAnimal(const ZooAnimal& copy);
	int MealsIncrease();
	int MealsDecrease();
	bool TryAddMassInfo(int currentMass);
	bool TryAddMassInfo(int mass, int yearToAdd);
	int MassChangeDrastic();
	void Print() const;
	string GetName() const;
};

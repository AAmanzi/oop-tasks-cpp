#pragma once
#include <string>
#include <chrono>
#include <iostream>
#include <map>

typedef std::chrono::system_clock Clock;

namespace zoo
{
	class ZooAnimal
	{
	protected:
		virtual void OutputTo(std::ostream& outputStream) const;
		virtual void InputTo(std::istream& inputStream);
		virtual void SetDefaults();
	public:
		std::string Species;
		std::string Name;
		int YearOfBirth;
		int LifespanInYears;
		int CageNumber;
		int MealsPerDay;
		int MealPortionInKg;
		std::map<int, int> MassByYear;
		std::string FertilizationType;
		std::string ThermoregulationType;

		ZooAnimal
		(
			std::string species,
			std::string name, 
			int yearOfBirth, 
			int lifespanInYears, 
			int cageNumber, 
		    int mealsPerDay,
			int mealPortionInKg,
			std::string fertilizationType, 
			std::string thermoregulationType
		);

		ZooAnimal();
		ZooAnimal(const ZooAnimal& copy);
		virtual ~ZooAnimal();

		friend std::istream & operator>>(std::istream& inputStream, ZooAnimal& toInput);
		friend std::ostream & operator<<(std::ostream& outputStream, const ZooAnimal& toOutput);

		int MealsIncrease();
		int MealsDecrease();
		bool TryAddMassInfo(int currentMass);
		bool TryAddMassInfo(int mass, int yearToAdd);
		int MassChangeDrastic();
		int GetMass();

		std::string GetName() const;
	};
}

#pragma once
#include "../../OOP-05/Task-01/ZooAnimal.h"

namespace zoo
{
	class Mammal : public ZooAnimal
	{
	protected:
		void OutputTo(std::ostream& outputStream) const override;
		void InputTo(std::istream& inputStream) override;
		void SetDefaults() override;
	public:
		int GestationPeriodInMonths{};
		int AvgTemperatureInCelsius{};

		Mammal
		(
			std::string species,
			std::string name, 
			int yearOfBirth, 
			int lifespanInYears, 
			int cageNumber, 
			int mealsPerDay, 
			int gestationPeriodInMonths, 
			int avgTemperatureInCelsius
		);
		Mammal() = default;
		Mammal(const Mammal& copy);
		~Mammal();

	};
}

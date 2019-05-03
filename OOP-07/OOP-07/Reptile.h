#pragma once
#include "../../OOP-05/Task-01/ZooAnimal.h"

namespace zoo
{
	class Reptile : public ZooAnimal
	{
	protected:
		void OutputTo(std::ostream& outputStream) const override;
		void InputTo(std::istream& inputStream) override;
		void SetDefaults() override;
	public:
		int IncubationPeriodInMonths{};
		int EnvironmentTemperatureInCelsius{};

		Reptile
		(
			std::string species,
			std::string name, 
			int yearOfBirth, 
			int lifespanInYears, 
			int cageNumber, 
			int mealsPerDay, 
			int incubationPeriodInMonths, 
			int environmentTemperatureInCelsius
		);

		Reptile() = default;
		Reptile(const Reptile& copy);
		~Reptile();
	};
}

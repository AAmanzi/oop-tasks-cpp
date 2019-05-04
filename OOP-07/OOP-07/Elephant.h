#pragma once
#include "Mammal.h"

namespace zoo
{
	class Elephant : public Mammal
	{
	protected:
		void InputTo(std::istream& inputStream) override;
		void SetDefaults() override;
	public:
		Elephant
		(
			std::string name, 
			int yearOfBirth, 
			int cageNumber, 
			int mealsPerDay,
			int mealPortionInKg
		);
		Elephant() = default;
		Elephant(const Elephant& copy);
		~Elephant();
	};
}

#pragma once
#include "Reptile.h"

namespace zoo
{
	class Crocodile : public Reptile
	{
	protected:
		void InputTo(std::istream& inputStream) override;
		void SetDefaults() override;
	public:
		Crocodile
		(
			std::string name, 
			int yearOfBirth, 
			int cageNumber, 
			int mealsPerDay,
			int mealPortionInKg
		);
		Crocodile() = default;
		Crocodile(const Crocodile& copy);
		~Crocodile();
	};
}

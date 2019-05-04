#pragma once
#include "Reptile.h"

namespace zoo
{
	class Turtle : public Reptile
	{
	protected:
		void InputTo(std::istream& inputStream) override;
		void SetDefaults() override;
	public:
		Turtle
		(
			std::string name, 
			int yearOfBirth, 
			int cageNumber, 
			int mealsPerDay,
			int mealPortionInKg
		);
		Turtle() = default;
		Turtle(const Turtle& copy);
		~Turtle();
	};
}

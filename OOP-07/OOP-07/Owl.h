#pragma once
#include "Bird.h"

namespace zoo
{
	class Owl : public Bird
	{
	protected:
		void InputTo(std::istream& inputStream) override;
		void SetDefaults() override;
	public:
		Owl
		(
			std::string name, 
			int yearOfBirth, 
			int cageNumber, 
			int mealsPerDay,
			int mealPortionInKg
		);
		Owl() = default;
		Owl(const Owl& copy);
		~Owl();
	};
}

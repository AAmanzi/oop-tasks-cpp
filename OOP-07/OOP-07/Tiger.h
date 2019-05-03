#pragma once
#include "Mammal.h"

namespace zoo
{
	class Tiger : public Mammal
	{
	protected:
		void InputTo(std::istream& inputStream) override;
		void SetDefaults() override;
	public:
		Tiger
		(
			std::string name, 
			int yearOfBirth, 
			int cageNumber, 
			int mealsPerDay
		);

		Tiger() = default;
		Tiger(const Tiger& copy);
		~Tiger();
	};
}
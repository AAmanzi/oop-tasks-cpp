#pragma once
#include "Mammal.h"

namespace zoo
{
	class Monkey : public Mammal
	{
	protected:
		void InputTo(std::istream& inputStream) override;
		void SetDefaults() override;
	public:
		Monkey
		(
			std::string name, 
			int yearOfBirth, 
			int cageNumber, 
			int mealsPerDay
		);
		Monkey() = default;
		Monkey(const Monkey& copy);
		~Monkey();
	};
}

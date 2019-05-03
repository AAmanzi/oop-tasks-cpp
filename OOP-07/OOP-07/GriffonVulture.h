#pragma once
#include "Bird.h"

namespace zoo
{
	class GriffonVulture : public Bird
	{
	protected:
		void InputTo(std::istream& inputStream) override;
		void SetDefaults() override;
	public:
		GriffonVulture
		(
			std::string name, 
			int yearOfBirth, 
			int cageNumber, 
			int mealsPerDay
		);
		GriffonVulture() = default;
		GriffonVulture(const GriffonVulture& copy);
		~GriffonVulture();
	};
}

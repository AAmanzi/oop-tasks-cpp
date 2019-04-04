#include <iostream>
#include <iomanip>
#include <vector>
#include "ZooAnimal.h"

using namespace std;

int main()
{
	vector<ZooAnimal> allAnimals;

	auto tmpAnimal = new ZooAnimal("Lion", "Kenny", 1998, 30, 1, 5);
	tmpAnimal->TryAddMassInfo(150, 2018);
	tmpAnimal->TryAddMassInfo(175, 2019);
	allAnimals.push_back(*tmpAnimal);

	tmpAnimal = new ZooAnimal("Elephant", "Johnny", 2010, 25, 2, 3);
	tmpAnimal->TryAddMassInfo(900, 2018);
	tmpAnimal->TryAddMassInfo(850, 2019);
	allAnimals.push_back(*tmpAnimal);

	tmpAnimal = new ZooAnimal("Pelican", "Boris", 2004, 35, 3, 2);
	tmpAnimal->TryAddMassInfo(25, 2018);
	tmpAnimal->TryAddMassInfo(10, 2019);
	allAnimals.push_back(*tmpAnimal);

	for (auto i = allAnimals.begin(); i != allAnimals.end(); ++i)
	{
		const auto massChange = i->MassChangeDrastic();
		if(massChange == 1)
		{
			cout << i->GetName() << " is overfed!" << endl;
			i->MealsDecrease();
		}
		else if(massChange == -1)
		{
			cout << i->GetName() << " is underfed!" << endl;
			i->MealsIncrease();
		}
	}

	cout << endl << endl;

	for (auto animal : allAnimals)
	{
		animal.Print();
	}

	allAnimals.clear();

	system("pause");
}
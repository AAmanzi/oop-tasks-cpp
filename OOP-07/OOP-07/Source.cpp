#include <iostream>
#include "../../OOP-05/Task-01/ZooAnimal.h"
#include "Crocodile.h"
#include "Elephant.h"
#include "Tiger.h"
#include <vector>

using namespace zoo;
using namespace std;

int main()
{
	auto someCrocodile = new Crocodile(
		"Stipe",
		2000,
		101,
		3,
		30
	);
	auto someElephant = new Elephant(
		"Boris",
		1995,
		102,
		4,
		50
	);
	auto someTiger = new Tiger(
		"Tiggr",
		2013,
		103,
		2,
		60
	);

	auto zooAnimals = new vector<ZooAnimal>;
	zooAnimals->push_back(*someCrocodile);
	zooAnimals->push_back(*someElephant);
	zooAnimals->push_back(*someTiger);

	auto totalFoodAmountPerDay = 0;

	for (auto zooAnimal = zooAnimals->begin(); zooAnimal != zooAnimals->end(); ++zooAnimal)
	{
		totalFoodAmountPerDay += zooAnimal->FoodPerDayInKg();
		cout << *zooAnimal << endl << endl;
	}

	cout << totalFoodAmountPerDay << endl;

	system("pause");
}
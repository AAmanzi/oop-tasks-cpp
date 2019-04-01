#include <iostream>
#include <iomanip>
#include <ctime>
#include "Gun.h"
#include "Target.h"
#include <list>
#include <ctime>
#include <stdlib.h>

using namespace std;

int main()
{
	srand(time(NULL));
	const auto gunLocation = new Point();
	auto newGun = new Gun(*gunLocation, 12);

	int amountOfTargets;

	cout << "Enter the amount of targets you want to create:" << endl;
	cin >> amountOfTargets;

	list<Target> targets;

	for (auto i = 0; i < amountOfTargets; ++i)
	{
		const auto bottomLeftCorner = new Point(-50, 50);
		const auto newTarget = new Target(*bottomLeftCorner, 10, 10);

		targets.push_back(*newTarget);
	}

	for (auto target : targets)
	{
		if(target.IsOnYAxis(newGun->GetLocation().GetY()))
		{
			cout << "hit";
			newGun->Shoot();
			target.Hit();
			if(newGun->IsEmpty())
				newGun->Reload();
		}
	}

	system("pause");
}
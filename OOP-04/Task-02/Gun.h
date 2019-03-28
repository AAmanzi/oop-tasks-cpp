#pragma once
#include "../Task-01/Point.h"

class Gun
{
	Point Location;
	int MagazineSize, AvailableBullets;
public:
	Gun();
	Gun(const Point& location, int magazineSize, int availableBullets);
	bool IsEmpty() const;
	void Shoot();
	void Reload();
};


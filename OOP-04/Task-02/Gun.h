#pragma once
#include "../Task-01/Point.h"

class Gun
{
	Point Location;
	int MagazineSize, AvailableBullets;
public:
	Gun();
	Gun(const Point& location, int magazineSize, int availableBullets);
	Gun(const Point& location, int magazineSize);
	int GetMagazineSize();
	int GetAvailableBullets();
	Point GetLocation();
	bool IsEmpty() const;
	void Shoot();
	void Reload();
};